/* File: /home/roy/workspace/via_bgd/Release/_sds/p0/.cf_work/portinfo.h */
#ifndef _SDS_PORTINFO_p_0__H
#define _SDS_PORTINFO_p_0__H

#include "cf_request.h"
#include "accel_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

struct p_0_hwblk_bgd_accel {
  cf_port_send_t cmd_bgd_accel;
  cf_port_send_t valData;
  cf_port_send_t valWeight;
  cf_port_receive_t valGradient;
};

struct p_0_hwblk_s2mm_data_copy {
  cf_port_send_t cmd_s2mm_data_copy;
  cf_port_send_t fifo;
  cf_port_send_t len;
  cf_port_send_t buf_offset;
};

struct p_0_hwblk_via_dma_in0 {
  cf_port_send_t cmd_via_dma_in0;
  cf_port_send_t in0_offset;
  cf_port_send_t len;
  cf_port_receive_t data;
};

struct p_0_hwblk_via_dma_in1 {
  cf_port_send_t cmd_via_dma_in1;
  cf_port_send_t in1_offset;
  cf_port_send_t len;
  cf_port_receive_t weight;
};

extern struct p_0_hwblk_bgd_accel p_0_hwinst_bgd_accel_1;
extern struct p_0_hwblk_s2mm_data_copy p_0_hwinst_s2mm_data_copy_1;
extern struct p_0_hwblk_via_dma_in0 p_0_hwinst_via_dma_in0_1;
extern struct p_0_hwblk_via_dma_in1 p_0_hwinst_via_dma_in1_1;
void p_0_cf_framework_open(void);
void p_0_cf_framework_close(void);

#ifdef __cplusplus
};
#endif

#endif
