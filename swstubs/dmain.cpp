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

#include "cf_stub.h"
void p_0_via_dma_in0_1_noasync(float * in0, int len, float * data);
void p_0_via_dma_in0_1_noasync(float * in0, int len, float * data)
{
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t p_0_hwinst_via_dma_in0_1_cmd;
  cf_send_i(&(p_0_hwinst_via_dma_in0_1.cmd_via_dma_in0), start_seq, 1 * sizeof(int), &p_0_hwinst_via_dma_in0_1_cmd);
  cf_wait(p_0_hwinst_via_dma_in0_1_cmd);

  cf_send_ref_i(&(p_0_hwinst_via_dma_in0_1.in0_offset), &in0, (len) * 4, &p_0_request_2);
  cf_send_i(&(p_0_hwinst_via_dma_in0_1.len), &len, 4, &p_0_request_3);


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

#include "cf_stub.h"
void p_0_via_dma_in1_1_noasync(float * in1, int len, float * weight);
void p_0_via_dma_in1_1_noasync(float * in1, int len, float * weight)
{
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t p_0_hwinst_via_dma_in1_1_cmd;
  cf_send_i(&(p_0_hwinst_via_dma_in1_1.cmd_via_dma_in1), start_seq, 1 * sizeof(int), &p_0_hwinst_via_dma_in1_1_cmd);
  cf_wait(p_0_hwinst_via_dma_in1_1_cmd);

  cf_send_ref_i(&(p_0_hwinst_via_dma_in1_1.in1_offset), &in1, (len) * 4, &p_0_request_4);
  cf_send_i(&(p_0_hwinst_via_dma_in1_1.len), &len, 4, &p_0_request_5);


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

#include "cf_stub.h"
void p_0_s2mm_data_copy_1_noasync(float * fifo, int len, float * buf);
void p_0_s2mm_data_copy_1_noasync(float * fifo, int len, float * buf)
{
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t p_0_hwinst_s2mm_data_copy_1_cmd;
  cf_send_i(&(p_0_hwinst_s2mm_data_copy_1.cmd_s2mm_data_copy), start_seq, 1 * sizeof(int), &p_0_hwinst_s2mm_data_copy_1_cmd);
  cf_wait(p_0_hwinst_s2mm_data_copy_1_cmd);

  cf_send_i(&(p_0_hwinst_s2mm_data_copy_1.len), &len, 4, &p_0_request_0);
  cf_send_ref_i(&(p_0_hwinst_s2mm_data_copy_1.buf_offset), &buf, (len) * 4, &p_0_request_1);


  cf_wait(p_0_request_0);
  cf_wait(p_0_request_1);
  cf_wait(p_0_request_2);
  cf_wait(p_0_request_3);
  cf_wait(p_0_request_4);
  cf_wait(p_0_request_5);
}


