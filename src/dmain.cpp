#include <string.h>
#include "dmain.h"


void via_dma_in0(float *in0, int len, float *data)
{
#pragma HLS INTERFACE axis port=data


   for(int i=0;i<len;i++)
    {
#pragma HLS PIPELINE
    	data[i] = in0[i];
    }
}

void via_dma_in1(float *in1, int len, float *weight)
{
#pragma HLS INTERFACE axis port=weight


   for(int i=0;i<len;i++)
    {
#pragma HLS PIPELINE
    	weight[i] = in1[i];
    }
}

void s2mm_data_copy(float *fifo, int len, float *buf)
{
#pragma HLS interface axis port=fifo
     for(int i=0; i<len; i++) {
#pragma HLS pipeline
          buf[i] = *fifo;
     }

}
