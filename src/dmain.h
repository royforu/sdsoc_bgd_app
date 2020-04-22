#ifdef _SDSVHLS_
#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<32,1,1,1> value_t;
typedef hls::stream<value_t> stream_t;
typedef ap_uint<32> reg32_t;
void bgd_accel(value_t& valData, value_t& valWeight, value_t& valGradient, reg32_t regScalar);
#else
void bgd_accel(float *valData, float *valWeight, float *valGradient);
#pragma SDS data zero_copy(in0[0:len])
#pragma SDS data sys_port (in0:HP)
void via_dma_in0(float *in0, int len, float *data);

#pragma SDS data zero_copy(in1[0:len])
#pragma SDS data sys_port (in1:HP)
void via_dma_in1(float *in1, int len, float *weight);

#pragma SDS data zero_copy(buf[0:len])
#pragma SDS data sys_port (fifo:HP)
void s2mm_data_copy(float *fifo, int len, float *buf);
#endif


