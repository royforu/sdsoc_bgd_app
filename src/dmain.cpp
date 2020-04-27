#include <string.h>
#include "dmain.h"

#ifdef _SDSVHLS_
void via_dma_in(volatile int32_t* pn32MIGPtrDI, reg32_t& regXferLeng, value_t& valStreamOut)
{
#pragma HLS INTERFACE m_axi depth=4096 port=pn32MIGPtrDI offset=slave
#pragma HLS INTERFACE s_axilite port=regXferLeng
#pragma HLS INTERFACE axis port=valStreamOut
#pragma HLS INTERFACE s_axilite port=return

    uint32_t u32NumXfer4B;
    value_t valStream;

    u32NumXfer4B = (regXferLeng + (sizeof(int32_t) - 1)) / sizeof(int32_t);
    valStream.data = 0;
    valStream.keep = 0xF;
    valStream.strb = 0;
    valStream.user = 0;
    valStream.last = 0;
    valStream.id = 0;
    valStream.dest = 0;

_XFER_LOOP_:
    for(uint32_t loop = 0; loop < u32NumXfer4B; loop++)
    {
        #pragma HLS PIPELINE
        if(loop == (u32NumXfer4B - 1))
        {
            valStream.last = 1;
        }
        valStream.data = pn32MIGPtrDI[loop];
        valStreamOut = valStream;
    }
}
#else
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
#endif

void s2mm_data_copy(float *fifo, int len, float *buf)
{
#pragma HLS interface axis port=fifo
     for(int i=0; i<len; i++) {
#pragma HLS pipeline
          buf[i] = *fifo;
     }

}
