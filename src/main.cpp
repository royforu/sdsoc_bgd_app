/*
(c) Copyright 2013 - 2016 Xilinx, Inc. All rights reserved. 

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER 
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law: (1) THESE
MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX HEREBY
DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising
under or in connection with these materials, including for any direct, or any
indirect, special, incidental, or consequential loss or damage (including loss
of data, profits, goodwill, or any type of loss or damage suffered as a result
of any action brought by a third party) even if such damage or loss was
reasonably foreseeable or Xilinx had been advised of the possibility of the
same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES. 
*/

#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include "sds_lib.h"

#include "dmain.h"
#include "lrbgd.h"

#define numClasses 10
#define numFeatures  784
#define chunkSize  4000




class perf_counter
{
public:
     uint64_t tot, cnt, calls;
     perf_counter() : tot(0), cnt(0), calls(0) {};
     inline void reset() { tot = cnt = calls = 0; }
     inline void start() { cnt = sds_clock_counter(); calls++; };
     inline void stop() { tot += (sds_clock_counter() - cnt); };
     inline uint64_t avg_cpu_cycles() { return ((tot+(calls>>1)) / calls); };
};

static void init_arrays_in(float *in0,  float *in1, int in0len, int in1len)
{

    for (int i = 0; i < in0len; i++) {
             in0[i] = (float(i) + 1.0) / float(int(chunkSize*(numClasses+numFeatures+1)));
     }

     for (int i = 0; i < in1len; i++) {
             in1[i] = (float(i) + 1.0) / float(int(numClasses*(numFeatures+1)));
     }
     

     
}


static void init_arrays_out(float *out, int outlen)
{

     for (int i = 0; i < outlen; i++) {
             out[i] = 0;
     }

}

void via_dma_in0_sw(float *in0, int len, float *data)
{
    for(int i=0;i<len;i++)
    	data[i] = in0[i];
}

void via_dma_in1_sw(float *in1, int len, float *weight)
{
    for(int i=0;i<len;i++)
    	weight[i] = in1[i];
}

void s2mm_data_copy_sw(float *fifo, int len, float *buf)
{

     for(int i=0; i<len; i++) {

          buf[i] = fifo[i];
     }

}

void bgd_accel_sw(float *valData, float *valWeight, float *valGradient, int regScalar)
{

	uint32_t datapos = 0;
    float32_t fltData[NUM_KERNEL][NUM_TOTAL_FEATURE];

    float32_t fltLabel[NUM_CLASSES];

    float32_t fltWeight[NUM_CLASSES][NUM_TOTAL_FEATURE];


    float32_t fltGradient[NUM_CLASSES][NUM_TOTAL_FEATURE];

    uint32_t u32Chunks = regScalar;



    for(uint32_t loop = 0, i = 0, j = 0; loop < (NUM_CLASSES * (NUM_FEATURES + 1)); loop++, j++)
    {

        if(j == (NUM_FEATURES + 1))
        {
            i++;
            j = 0;
        }
        float32_t fltWTmp;

        fltWTmp.float32 = valWeight[loop];
        fltWeight[i][j] = fltWTmp;
        fltWTmp.uint32 = 0;
        fltGradient[i][j] = fltWTmp;


    }


    for(uint32_t ch = 0; ch < NUM_CHUNKS; ch += NUM_PARALLELERS)
    {

        for(uint32_t loop = 0, i = 0, j = 0; loop < (NUM_PARALLELERS * (NUM_CLASSES + NUM_FEATURES + 1)); loop++, j++,datapos++)
        {

			float32_t fltDTmp;

			if(j == (NUM_CLASSES + NUM_FEATURES + 1))
			{
				i++;
				j = 0;
			}
			fltDTmp.float32 = valData[datapos];
			if (j>=NUM_CLASSES)
			{
				for(uint32_t k = 0; k < NUM_KERNEL; k++)
					fltData[k][j - NUM_CLASSES] = fltDTmp;
			}
			else
			{
				fltLabel[j] = fltDTmp;
			}
        }


		for(uint32_t cla = 0; cla < NUM_CLASSES; cla+=NUM_KERNEL)
		{
			bgd_func0(fltLabel[cla], &fltWeight[cla][0], &fltData[0][0], &fltGradient[cla][0]);
			bgd_func1(fltLabel[cla+1], &fltWeight[cla+1][0], &fltData[1][0], &fltGradient[cla+1][0]);
			#if (NUM_KERNEL==5)
			bgd_func2(fltLabel[cla+2], &fltWeight[cla+2][0], &fltData[2][0], &fltGradient[cla+2][0]);
			bgd_func3(fltLabel[cla+3], &fltWeight[cla+3][0], &fltData[3][0], &fltGradient[cla+3][0]);
			bgd_func4(fltLabel[cla+4], &fltWeight[cla+4][0], &fltData[4][0], &fltGradient[cla+4][0]);
			#endif
		}
    }


    for(uint32_t loop = 0, i = 0, j = 0; loop < (NUM_CLASSES * (NUM_FEATURES + 1)); loop++, j++)
    {

        if(j == (NUM_FEATURES + 1))
        {
            i++;
            j = 0;
        }

        float32_t fltGTmp;
        fltGTmp = fltGradient[i][j];
        valGradient[loop]= fltGTmp.float32;

    }

}




int main(int argc, char* argv[]){

    float *inbuf0, *inbuf1;

    float  *swdata, *swweight, *swgradient,  *swoutbuf;

    float  hwdata[1], hwweight[1], hwgradient[1],  *hwoutbuf;
    clock_t start, end;
    double cpu_time_used;

    int inbuffer0len = int(chunkSize*(numClasses+numFeatures+1));
    int inbuffer1len = int(numClasses*(numFeatures+1));
    int outbufferlen =  int(numClasses*(numFeatures+1));

    std::cout << "inbuffer0len: "
               << inbuffer0len << std::endl;

    
    std::cout << "inbuffer1len1: "
               << inbuffer1len << std::endl;


     std::cout << "outbufferlen: "
               << outbufferlen << std::endl;

     inbuf0 = (float *)sds_alloc(inbuffer0len* sizeof(float));
     inbuf1 = (float *)sds_alloc(inbuffer1len * sizeof(float));

    // swdata = (float *)sds_alloc(inbuffer0len* sizeof(float));
   //  swweight = (float *)sds_alloc(inbuffer1len * sizeof(float));


     swgradient = (float *)sds_alloc(outbufferlen * sizeof(float));

    // swoutbuf = (float *)sds_alloc(outbufferlen * sizeof(float));
   

    init_arrays_in(inbuf0, inbuf1, inbuffer0len, inbuffer1len);
   // init_arrays_out(swoutbuf, outbufferlen);


  perf_counter hw_ctr, sw_ctr;

   // sw_ctr.start();
    
   // via_dma_in0_sw(inbuf0,inbuffer0len,swdata);
  	//  via_dma_in1_sw(inbuf1,inbuffer1len,swweight);
  	  bgd_accel_sw(inbuf0, inbuf1, swgradient, 0);
  	// s2mm_data_copy_sw(swgradient,outbufferlen , swoutbuf);

 //   sw_ctr.stop();
     
 //  uint64_t sw_cycles = sw_ctr.avg_cpu_cycles();
 //  std::cout << "Average number of CPU cycles in software: "
 //              << sw_cycles << std::endl;

   std::cout << "data: " << inbuf0[0] << std::endl;

   /*
   for(int i=0; i<inbuffer0len ;i++)
   {
      	if(i%10==0)
      	    std::cout << std::endl;
      	std::cout << inbuf0[i] << " ";
   }
   */
   std::cout << "weight: "  << inbuf1[0] << std::endl;
   /*
   for(int i=0; i<inbuffer1len ;i++)
   {
      	if(i%10==0)
      	    std::cout << std::endl;
      	std::cout << inbuf1[i] << " ";
   }
   */

   std::cout << "swout: " << std::endl;
    for(int i=0; i<4 ;i++)
    {
    	if(i%10==0)
    	    std::cout << std::endl;
    	std::cout << swgradient[i] << " ";
    }
    for(int i=outbufferlen-4; i<outbufferlen ;i++)
    {

	   std::cout << swgradient[i] << " ";
    }

    sds_free(swgradient);
    std::cout << "swdone: " << std::endl;




    //hwdata = (float *)sds_alloc(inbuffer0len* sizeof(float));
    //std::cout << "hwdata assign done: " << std::endl;
   // hwweight = (float *)sds_alloc(inbuffer1len * sizeof(float));
   // std::cout << "hwweight assign done: " << std::endl;

   // hwgradient = (float *)sds_alloc(outbufferlen * sizeof(float));
    //std::cout << "hwgradient assign done: " << std::endl;
    hwoutbuf = (float *)sds_alloc(outbufferlen * sizeof(float));
    std::cout << "hwoutbuf assign done: " << std::endl;

    //start = clock();
    hw_ctr.start();
    via_dma_in0(inbuf0,inbuffer0len,hwdata);
    via_dma_in1(inbuf1,inbuffer1len,hwweight);
    bgd_accel(hwdata, hwweight, hwgradient);
    s2mm_data_copy(hwgradient,outbufferlen , hwoutbuf);

     hw_ctr.stop();
   //  end = clock();

     uint64_t hw_cycles = hw_ctr.avg_cpu_cycles();
    // std::cout << "Average number of CPU cycles in hardware: "
      //             << hw_cycles << std::endl;

     std::cout << "hw elapsed time: " << hw_cycles/pow(10,8) << std::endl;

  //   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   std::cout << "hwclock elapsed time: " << cpu_time_used << std::endl;

     std::cout << "hwout: " << std::endl;
     for(int i=0; i<4 ;i++)
	 {
		if(i%10==0)
			std::cout << std::endl;
		std::cout << hwoutbuf[i] << " ";
	 }
	 for(int i=outbufferlen-4; i<outbufferlen ;i++)
	 {

	   std::cout << hwoutbuf[i] << " ";
	 }



     sds_free(inbuf0);
     sds_free(inbuf1);



     //sds_free(hwdata);
    // sds_free(hwweight);
   //  sds_free(hwgradient);
     sds_free(hwoutbuf);

    
     return (0);
}
