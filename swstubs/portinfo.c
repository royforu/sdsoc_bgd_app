/* File: /home/roy/workspace/via_bgd/Release/_sds/p0/.cf_work/portinfo.c */
#include "cf_lib.h"
#include "cf_request.h"
#include "accel_info.h"
#include "sds_lib.h"
#include "sds_trace.h"
#include "portinfo.h"
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit
#include "xlnk_core_cf.h"
#include "axi_lite_dm.h"
#include "sysport_info.h"
#include "zero_copy_dm.h"

sysport_info_t _sds_sysportp_0_ps7_S_AXI_ACP = {
  .name = "ps7_S_AXI_ACP",
  .id = 1,
  .address_space = 0,
  .cmd_type = sysport_commands_type_no_action,
};

accel_info_t _sds_p_0_bgd_accel_1 = {
  .device_id = 0,
  .phys_base_addr = 0x44a00000,
  .addr_range = 0x10000,
  .func_name = "bgd_accel_1",
  .ip_type = "axis_acc_adapter",
};

accel_info_t _sds_p_0_s2mm_data_copy_1 = {
  .device_id = 1,
  .phys_base_addr = 0x44a10000,
  .addr_range = 0x10000,
  .func_name = "s2mm_data_copy_1",
  .ip_type = "axis_acc_adapter",
};

accel_info_t _sds_p_0_via_dma_in0_1 = {
  .device_id = 2,
  .phys_base_addr = 0x44a20000,
  .addr_range = 0x10000,
  .func_name = "via_dma_in0_1",
  .ip_type = "axis_acc_adapter",
};

accel_info_t _sds_p_0_via_dma_in1_1 = {
  .device_id = 3,
  .phys_base_addr = 0x44a30000,
  .addr_range = 0x10000,
  .func_name = "via_dma_in1_1",
  .ip_type = "axis_acc_adapter",
};

int p_0_hwinst_bgd_accel_1_cmd_bgd_accel_sg_list[] = {0x8};

axi_lite_info_t p_0_hwinst_bgd_accel_1_cmd_bgd_accel_info = {
  .phys_base_addr = 0x44a00000,
  .data_reg_offset = p_0_hwinst_bgd_accel_1_cmd_bgd_accel_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds_p_0_bgd_accel_1,
};

int p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_sg_list[] = {0x8};

axi_lite_info_t p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_info = {
  .phys_base_addr = 0x44a10000,
  .data_reg_offset = p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds_p_0_s2mm_data_copy_1,
};

int p_0_hwinst_s2mm_data_copy_1_len_sg_list[] = {0xc};

axi_lite_info_t p_0_hwinst_s2mm_data_copy_1_len_info = {
  .phys_base_addr = 0x44a10000,
  .data_reg_offset = p_0_hwinst_s2mm_data_copy_1_len_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds_p_0_s2mm_data_copy_1,
};

zero_copy_info_t p_0_hwinst_s2mm_data_copy_1_buf_offset_info = {
  .phys_base_addr = 0x44a10000,
  .data_reg_offset = 0x10,
  .status_reg_offset = 0x410,
  .config = XLNK_ZERO_COPY_KEYHOLE |
    XLNK_ZERO_COPY_STAT_REG_WRITE(XLNK_ZERO_COPY_STAT_REG_QUEUING),
  .data_sysport = &_sds_sysportp_0_ps7_S_AXI_ACP,
  .dir = XLNK_BI_DIRECTIONAL,
  .cache = 0,
  .acc_info = &_sds_p_0_s2mm_data_copy_1,
};

int p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_sg_list[] = {0x8};

axi_lite_info_t p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_info = {
  .phys_base_addr = 0x44a20000,
  .data_reg_offset = p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds_p_0_via_dma_in0_1,
};

zero_copy_info_t p_0_hwinst_via_dma_in0_1_in0_offset_info = {
  .phys_base_addr = 0x44a20000,
  .data_reg_offset = 0xc,
  .status_reg_offset = 0x40c,
  .config = XLNK_ZERO_COPY_KEYHOLE |
    XLNK_ZERO_COPY_STAT_REG_WRITE(XLNK_ZERO_COPY_STAT_REG_QUEUING),
  .data_sysport = &_sds_sysportp_0_ps7_S_AXI_ACP,
  .dir = XLNK_BI_DIRECTIONAL,
  .cache = 0,
  .acc_info = &_sds_p_0_via_dma_in0_1,
};

int p_0_hwinst_via_dma_in0_1_len_sg_list[] = {0x10};

axi_lite_info_t p_0_hwinst_via_dma_in0_1_len_info = {
  .phys_base_addr = 0x44a20000,
  .data_reg_offset = p_0_hwinst_via_dma_in0_1_len_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds_p_0_via_dma_in0_1,
};

int p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_sg_list[] = {0x8};

axi_lite_info_t p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_info = {
  .phys_base_addr = 0x44a30000,
  .data_reg_offset = p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds_p_0_via_dma_in1_1,
};

zero_copy_info_t p_0_hwinst_via_dma_in1_1_in1_offset_info = {
  .phys_base_addr = 0x44a30000,
  .data_reg_offset = 0xc,
  .status_reg_offset = 0x40c,
  .config = XLNK_ZERO_COPY_KEYHOLE |
    XLNK_ZERO_COPY_STAT_REG_WRITE(XLNK_ZERO_COPY_STAT_REG_QUEUING),
  .data_sysport = &_sds_sysportp_0_ps7_S_AXI_ACP,
  .dir = XLNK_BI_DIRECTIONAL,
  .cache = 0,
  .acc_info = &_sds_p_0_via_dma_in1_1,
};

int p_0_hwinst_via_dma_in1_1_len_sg_list[] = {0x10};

axi_lite_info_t p_0_hwinst_via_dma_in1_1_len_info = {
  .phys_base_addr = 0x44a30000,
  .data_reg_offset = p_0_hwinst_via_dma_in1_1_len_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds_p_0_via_dma_in1_1,
};

struct p_0_hwblk_bgd_accel p_0_hwinst_bgd_accel_1 = {
  .cmd_bgd_accel = { .base = { .channel_info = &p_0_hwinst_bgd_accel_1_cmd_bgd_accel_info}, 
    .send_i = &axi_lite_send },
};

struct p_0_hwblk_s2mm_data_copy p_0_hwinst_s2mm_data_copy_1 = {
  .cmd_s2mm_data_copy = { .base = { .channel_info = &p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_info}, 
    .send_i = &axi_lite_send },
  .len = { .base = { .channel_info = &p_0_hwinst_s2mm_data_copy_1_len_info}, 
    .send_i = &axi_lite_send },
  .buf_offset = { .base = { .channel_info = &p_0_hwinst_s2mm_data_copy_1_buf_offset_info}, 
    .send_ref_i = &zero_copy_send_ref_i },
};

struct p_0_hwblk_via_dma_in0 p_0_hwinst_via_dma_in0_1 = {
  .cmd_via_dma_in0 = { .base = { .channel_info = &p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_info}, 
    .send_i = &axi_lite_send },
  .in0_offset = { .base = { .channel_info = &p_0_hwinst_via_dma_in0_1_in0_offset_info}, 
    .send_ref_i = &zero_copy_send_ref_i },
  .len = { .base = { .channel_info = &p_0_hwinst_via_dma_in0_1_len_info}, 
    .send_i = &axi_lite_send },
};

struct p_0_hwblk_via_dma_in1 p_0_hwinst_via_dma_in1_1 = {
  .cmd_via_dma_in1 = { .base = { .channel_info = &p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_info}, 
    .send_i = &axi_lite_send },
  .in1_offset = { .base = { .channel_info = &p_0_hwinst_via_dma_in1_1_in1_offset_info}, 
    .send_ref_i = &zero_copy_send_ref_i },
  .len = { .base = { .channel_info = &p_0_hwinst_via_dma_in1_1_len_info}, 
    .send_i = &axi_lite_send },
};

extern void pfm_hook_init(void);
extern void pfm_hook_shutdown(void);
void p_0_init_pl(void)
{
  sysport_open(&_sds_sysportp_0_ps7_S_AXI_ACP);
  axi_lite_open(&p_0_hwinst_bgd_accel_1_cmd_bgd_accel_info);
  axi_lite_open(&p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_info);
  axi_lite_open(&p_0_hwinst_s2mm_data_copy_1_len_info);
  zero_copy_open(&p_0_hwinst_s2mm_data_copy_1_buf_offset_info);
  axi_lite_open(&p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_info);
  zero_copy_open(&p_0_hwinst_via_dma_in0_1_in0_offset_info);
  axi_lite_open(&p_0_hwinst_via_dma_in0_1_len_info);
  axi_lite_open(&p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_info);
  zero_copy_open(&p_0_hwinst_via_dma_in1_1_in1_offset_info);
  axi_lite_open(&p_0_hwinst_via_dma_in1_1_len_info);
  _sds_p_0_bgd_accel_1.arg_dm_id[0] = p_0_hwinst_bgd_accel_1_cmd_bgd_accel_info.dm_id;
  _sds_p_0_bgd_accel_1.arg_dm_id_count = 1;
  accel_open(&_sds_p_0_bgd_accel_1);
  _sds_p_0_s2mm_data_copy_1.arg_dm_id[0] = p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_info.dm_id;
  _sds_p_0_s2mm_data_copy_1.arg_dm_id[1] = p_0_hwinst_s2mm_data_copy_1_len_info.dm_id;
  _sds_p_0_s2mm_data_copy_1.arg_dm_id[2] = p_0_hwinst_s2mm_data_copy_1_buf_offset_info.dm_id;
  _sds_p_0_s2mm_data_copy_1.arg_dm_id_count = 3;
  accel_open(&_sds_p_0_s2mm_data_copy_1);
  _sds_p_0_via_dma_in0_1.arg_dm_id[0] = p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_info.dm_id;
  _sds_p_0_via_dma_in0_1.arg_dm_id[1] = p_0_hwinst_via_dma_in0_1_in0_offset_info.dm_id;
  _sds_p_0_via_dma_in0_1.arg_dm_id[2] = p_0_hwinst_via_dma_in0_1_len_info.dm_id;
  _sds_p_0_via_dma_in0_1.arg_dm_id_count = 3;
  accel_open(&_sds_p_0_via_dma_in0_1);
  _sds_p_0_via_dma_in1_1.arg_dm_id[0] = p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_info.dm_id;
  _sds_p_0_via_dma_in1_1.arg_dm_id[1] = p_0_hwinst_via_dma_in1_1_in1_offset_info.dm_id;
  _sds_p_0_via_dma_in1_1.arg_dm_id[2] = p_0_hwinst_via_dma_in1_1_len_info.dm_id;
  _sds_p_0_via_dma_in1_1.arg_dm_id_count = 3;
  accel_open(&_sds_p_0_via_dma_in1_1);
}

void p_0_shutdown_pl()
{
  accel_close(&_sds_p_0_bgd_accel_1);
  accel_close(&_sds_p_0_s2mm_data_copy_1);
  accel_close(&_sds_p_0_via_dma_in0_1);
  accel_close(&_sds_p_0_via_dma_in1_1);
  axi_lite_close(&p_0_hwinst_bgd_accel_1_cmd_bgd_accel_info);
  axi_lite_close(&p_0_hwinst_s2mm_data_copy_1_cmd_s2mm_data_copy_info);
  axi_lite_close(&p_0_hwinst_s2mm_data_copy_1_len_info);
  zero_copy_close(&p_0_hwinst_s2mm_data_copy_1_buf_offset_info);
  axi_lite_close(&p_0_hwinst_via_dma_in0_1_cmd_via_dma_in0_info);
  zero_copy_close(&p_0_hwinst_via_dma_in0_1_in0_offset_info);
  axi_lite_close(&p_0_hwinst_via_dma_in0_1_len_info);
  axi_lite_close(&p_0_hwinst_via_dma_in1_1_cmd_via_dma_in1_info);
  zero_copy_close(&p_0_hwinst_via_dma_in1_1_in1_offset_info);
  axi_lite_close(&p_0_hwinst_via_dma_in1_1_len_info);
  sysport_close(&_sds_sysportp_0_ps7_S_AXI_ACP);
}


void p_0_cf_framework_open(void) __attribute__((constructor));
void p_0_cf_framework_close(void) __attribute__((destructor));
void p_0_cf_framework_open(void)
{
  if (xlnkOpen()) {
    cf_context_init();
    xlnkCounterMap(666666687);
    pfm_hook_init();
    sds_trace_setup(0x0);
  }
  p_0_init_pl();
}

#ifdef PERF_EST
void add_sw_estimates();
#endif

void p_0_cf_framework_close(void)
{
  p_0_shutdown_pl();
  if(xlnkDecrementRef()) {
    sds_trace_cleanup();
    pfm_hook_shutdown();
    xlnkClose(1, NULL);
  }
#ifdef PERF_EST
  add_sw_estimates();
  apf_perf_estimation_exit();
#endif
}
