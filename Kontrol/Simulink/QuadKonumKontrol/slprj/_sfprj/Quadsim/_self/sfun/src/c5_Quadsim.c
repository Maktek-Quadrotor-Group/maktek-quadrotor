/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c5_Quadsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[9] = { "nargin", "nargout", "roll",
  "pitch", "yaw", "x", "y", "z", "theta" };

/* Function Declarations */
static void initialize_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance);
static void enable_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void disable_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void sf_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void c5_chartstep_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_theta, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_eml_error(SFc5_QuadsimInstanceStruct *chartInstance);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Quadsim, const char_T *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_Quadsim = 0U;
}

static void initialize_params_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_Quadsim(SFc5_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  uint8_T c5_e_hoistedGlobal;
  uint8_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T *c5_theta;
  real_T *c5_x;
  real_T *c5_g_y;
  real_T *c5_z;
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(5), FALSE);
  c5_hoistedGlobal = *c5_theta;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_x;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_g_y;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_z;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = chartInstance->c5_is_active_c5_Quadsim;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_theta;
  real_T *c5_x;
  real_T *c5_y;
  real_T *c5_z;
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_theta = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    0)), "theta");
  *c5_x = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "x");
  *c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
    "y");
  *c5_z = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 3)),
    "z");
  chartInstance->c5_is_active_c5_Quadsim = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 4)), "is_active_c5_Quadsim");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Quadsim(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
  real_T *c5_roll;
  real_T *c5_pitch;
  real_T *c5_x;
  real_T *c5_yaw;
  real_T *c5_y;
  real_T *c5_z;
  real_T *c5_theta;
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_roll, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_pitch, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_x, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_yaw, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_theta, 6U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Quadsim(chartInstance);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_roll;
  real_T c5_pitch;
  real_T c5_yaw;
  uint32_T c5_debug_family_var_map[9];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 4.0;
  real_T c5_x;
  real_T c5_y;
  real_T c5_z;
  real_T c5_theta;
  real_T c5_A;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_b_y;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_b_A;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_c_y;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_a;
  real_T c5_b;
  real_T c5_d_y;
  real_T c5_c_A;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_e_y;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_b_a;
  real_T c5_b_b;
  real_T c5_f_y;
  real_T c5_d_A;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_g_y;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_e_A;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_h_y;
  real_T c5_t_x;
  real_T c5_u_x;
  real_T c5_c_a;
  real_T c5_c_b;
  real_T c5_i_y;
  real_T c5_f_A;
  real_T c5_v_x;
  real_T c5_w_x;
  real_T c5_j_y;
  real_T c5_x_x;
  real_T c5_y_x;
  real_T c5_d_a;
  real_T c5_d_b;
  real_T c5_k_y;
  real_T c5_ab_x;
  real_T c5_bb_x;
  real_T c5_e_b;
  real_T c5_g_A;
  real_T c5_cb_x;
  real_T c5_db_x;
  real_T c5_l_y;
  real_T c5_eb_x;
  real_T c5_fb_x;
  real_T c5_h_A;
  real_T c5_gb_x;
  real_T c5_hb_x;
  real_T c5_m_y;
  real_T c5_ib_x;
  real_T c5_jb_x;
  real_T c5_e_a;
  real_T c5_f_b;
  real_T c5_n_y;
  real_T c5_i_A;
  real_T c5_kb_x;
  real_T c5_lb_x;
  real_T c5_o_y;
  real_T c5_mb_x;
  real_T c5_nb_x;
  real_T c5_f_a;
  real_T c5_g_b;
  real_T c5_p_y;
  real_T c5_j_A;
  real_T c5_ob_x;
  real_T c5_pb_x;
  real_T c5_q_y;
  real_T c5_qb_x;
  real_T c5_rb_x;
  real_T c5_k_A;
  real_T c5_sb_x;
  real_T c5_tb_x;
  real_T c5_r_y;
  real_T c5_ub_x;
  real_T c5_vb_x;
  real_T c5_g_a;
  real_T c5_h_b;
  real_T c5_s_y;
  real_T c5_l_A;
  real_T c5_wb_x;
  real_T c5_xb_x;
  real_T c5_t_y;
  real_T c5_yb_x;
  real_T c5_ac_x;
  real_T c5_h_a;
  real_T c5_i_b;
  real_T c5_u_y;
  real_T c5_m_A;
  real_T c5_bc_x;
  real_T c5_cc_x;
  real_T c5_v_y;
  real_T c5_dc_x;
  real_T c5_ec_x;
  real_T c5_n_A;
  real_T c5_fc_x;
  real_T c5_gc_x;
  real_T c5_w_y;
  real_T c5_hc_x;
  real_T c5_ic_x;
  real_T c5_i_a;
  real_T c5_j_b;
  real_T c5_x_y;
  real_T c5_o_A;
  real_T c5_jc_x;
  real_T c5_kc_x;
  real_T c5_y_y;
  real_T c5_lc_x;
  real_T c5_mc_x;
  real_T c5_j_a;
  real_T c5_k_b;
  real_T c5_ab_y;
  real_T c5_p_A;
  real_T c5_nc_x;
  real_T c5_oc_x;
  real_T c5_bb_y;
  real_T c5_pc_x;
  real_T c5_qc_x;
  real_T c5_q_A;
  real_T c5_rc_x;
  real_T c5_sc_x;
  real_T c5_cb_y;
  real_T c5_tc_x;
  real_T c5_uc_x;
  real_T c5_k_a;
  real_T c5_l_b;
  real_T c5_db_y;
  real_T c5_r_A;
  real_T c5_vc_x;
  real_T c5_wc_x;
  real_T c5_eb_y;
  real_T c5_xc_x;
  real_T c5_yc_x;
  real_T c5_l_a;
  real_T c5_m_b;
  real_T c5_fb_y;
  real_T c5_s_A;
  real_T c5_ad_x;
  real_T c5_bd_x;
  real_T c5_gb_y;
  real_T c5_cd_x;
  real_T c5_dd_x;
  real_T c5_t_A;
  real_T c5_ed_x;
  real_T c5_fd_x;
  real_T c5_hb_y;
  real_T c5_gd_x;
  real_T c5_hd_x;
  real_T c5_m_a;
  real_T c5_n_b;
  real_T c5_ib_y;
  real_T c5_u_A;
  real_T c5_id_x;
  real_T c5_jd_x;
  real_T c5_jb_y;
  real_T c5_kd_x;
  real_T c5_ld_x;
  real_T c5_n_a;
  real_T c5_o_b;
  real_T c5_kb_y;
  real_T c5_v_A;
  real_T c5_md_x;
  real_T c5_nd_x;
  real_T c5_lb_y;
  real_T c5_od_x;
  real_T c5_pd_x;
  real_T c5_w_A;
  real_T c5_qd_x;
  real_T c5_rd_x;
  real_T c5_mb_y;
  real_T c5_sd_x;
  real_T c5_td_x;
  real_T c5_o_a;
  real_T c5_p_b;
  real_T c5_nb_y;
  real_T c5_x_A;
  real_T c5_ud_x;
  real_T c5_vd_x;
  real_T c5_ob_y;
  real_T c5_wd_x;
  real_T c5_xd_x;
  real_T c5_p_a;
  real_T c5_q_b;
  real_T c5_pb_y;
  real_T *c5_b_theta;
  real_T *c5_b_z;
  real_T *c5_qb_y;
  real_T *c5_yd_x;
  real_T *c5_b_yaw;
  real_T *c5_b_pitch;
  real_T *c5_b_roll;
  boolean_T guard1 = FALSE;
  c5_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_b_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_qb_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_yd_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_roll;
  c5_b_hoistedGlobal = *c5_b_pitch;
  c5_c_hoistedGlobal = *c5_b_yaw;
  c5_roll = c5_hoistedGlobal;
  c5_pitch = c5_b_hoistedGlobal;
  c5_yaw = c5_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_roll, 2U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_pitch, 3U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_yaw, 4U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_x, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_y, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_z, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_theta, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_pitch = -c5_pitch;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_A = c5_yaw;
  c5_b_x = c5_A;
  c5_c_x = c5_b_x;
  c5_b_y = c5_c_x / 2.0;
  c5_d_x = c5_b_y;
  c5_e_x = c5_d_x;
  c5_e_x = muDoubleScalarCos(c5_e_x);
  c5_b_A = c5_pitch;
  c5_f_x = c5_b_A;
  c5_g_x = c5_f_x;
  c5_c_y = c5_g_x / 2.0;
  c5_h_x = c5_c_y;
  c5_i_x = c5_h_x;
  c5_i_x = muDoubleScalarCos(c5_i_x);
  c5_a = c5_e_x;
  c5_b = c5_i_x;
  c5_d_y = c5_a * c5_b;
  c5_c_A = c5_roll;
  c5_j_x = c5_c_A;
  c5_k_x = c5_j_x;
  c5_e_y = c5_k_x / 2.0;
  c5_l_x = c5_e_y;
  c5_m_x = c5_l_x;
  c5_m_x = muDoubleScalarCos(c5_m_x);
  c5_b_a = c5_d_y;
  c5_b_b = c5_m_x;
  c5_f_y = c5_b_a * c5_b_b;
  c5_d_A = c5_yaw;
  c5_n_x = c5_d_A;
  c5_o_x = c5_n_x;
  c5_g_y = c5_o_x / 2.0;
  c5_p_x = c5_g_y;
  c5_q_x = c5_p_x;
  c5_q_x = muDoubleScalarSin(c5_q_x);
  c5_e_A = c5_pitch;
  c5_r_x = c5_e_A;
  c5_s_x = c5_r_x;
  c5_h_y = c5_s_x / 2.0;
  c5_t_x = c5_h_y;
  c5_u_x = c5_t_x;
  c5_u_x = muDoubleScalarSin(c5_u_x);
  c5_c_a = c5_q_x;
  c5_c_b = c5_u_x;
  c5_i_y = c5_c_a * c5_c_b;
  c5_f_A = c5_roll;
  c5_v_x = c5_f_A;
  c5_w_x = c5_v_x;
  c5_j_y = c5_w_x / 2.0;
  c5_x_x = c5_j_y;
  c5_y_x = c5_x_x;
  c5_y_x = muDoubleScalarSin(c5_y_x);
  c5_d_a = c5_i_y;
  c5_d_b = c5_y_x;
  c5_k_y = c5_d_a * c5_d_b;
  c5_ab_x = c5_f_y - c5_k_y;
  c5_bb_x = c5_ab_x;
  guard1 = FALSE;
  if (c5_bb_x < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < c5_bb_x) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c5_eml_error(chartInstance);
  }

  c5_bb_x = muDoubleScalarAcos(c5_bb_x);
  c5_e_b = c5_bb_x;
  c5_theta = 2.0 * c5_e_b;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_g_A = c5_yaw;
  c5_cb_x = c5_g_A;
  c5_db_x = c5_cb_x;
  c5_l_y = c5_db_x / 2.0;
  c5_eb_x = c5_l_y;
  c5_fb_x = c5_eb_x;
  c5_fb_x = muDoubleScalarSin(c5_fb_x);
  c5_h_A = c5_pitch;
  c5_gb_x = c5_h_A;
  c5_hb_x = c5_gb_x;
  c5_m_y = c5_hb_x / 2.0;
  c5_ib_x = c5_m_y;
  c5_jb_x = c5_ib_x;
  c5_jb_x = muDoubleScalarSin(c5_jb_x);
  c5_e_a = c5_fb_x;
  c5_f_b = c5_jb_x;
  c5_n_y = c5_e_a * c5_f_b;
  c5_i_A = c5_roll;
  c5_kb_x = c5_i_A;
  c5_lb_x = c5_kb_x;
  c5_o_y = c5_lb_x / 2.0;
  c5_mb_x = c5_o_y;
  c5_nb_x = c5_mb_x;
  c5_nb_x = muDoubleScalarCos(c5_nb_x);
  c5_f_a = c5_n_y;
  c5_g_b = c5_nb_x;
  c5_p_y = c5_f_a * c5_g_b;
  c5_j_A = c5_yaw;
  c5_ob_x = c5_j_A;
  c5_pb_x = c5_ob_x;
  c5_q_y = c5_pb_x / 2.0;
  c5_qb_x = c5_q_y;
  c5_rb_x = c5_qb_x;
  c5_rb_x = muDoubleScalarCos(c5_rb_x);
  c5_k_A = c5_pitch;
  c5_sb_x = c5_k_A;
  c5_tb_x = c5_sb_x;
  c5_r_y = c5_tb_x / 2.0;
  c5_ub_x = c5_r_y;
  c5_vb_x = c5_ub_x;
  c5_vb_x = muDoubleScalarCos(c5_vb_x);
  c5_g_a = c5_rb_x;
  c5_h_b = c5_vb_x;
  c5_s_y = c5_g_a * c5_h_b;
  c5_l_A = c5_roll;
  c5_wb_x = c5_l_A;
  c5_xb_x = c5_wb_x;
  c5_t_y = c5_xb_x / 2.0;
  c5_yb_x = c5_t_y;
  c5_ac_x = c5_yb_x;
  c5_ac_x = muDoubleScalarSin(c5_ac_x);
  c5_h_a = c5_s_y;
  c5_i_b = c5_ac_x;
  c5_u_y = c5_h_a * c5_i_b;
  c5_x = c5_p_y + c5_u_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_m_A = c5_yaw;
  c5_bc_x = c5_m_A;
  c5_cc_x = c5_bc_x;
  c5_v_y = c5_cc_x / 2.0;
  c5_dc_x = c5_v_y;
  c5_ec_x = c5_dc_x;
  c5_ec_x = muDoubleScalarSin(c5_ec_x);
  c5_n_A = c5_pitch;
  c5_fc_x = c5_n_A;
  c5_gc_x = c5_fc_x;
  c5_w_y = c5_gc_x / 2.0;
  c5_hc_x = c5_w_y;
  c5_ic_x = c5_hc_x;
  c5_ic_x = muDoubleScalarCos(c5_ic_x);
  c5_i_a = c5_ec_x;
  c5_j_b = c5_ic_x;
  c5_x_y = c5_i_a * c5_j_b;
  c5_o_A = c5_roll;
  c5_jc_x = c5_o_A;
  c5_kc_x = c5_jc_x;
  c5_y_y = c5_kc_x / 2.0;
  c5_lc_x = c5_y_y;
  c5_mc_x = c5_lc_x;
  c5_mc_x = muDoubleScalarCos(c5_mc_x);
  c5_j_a = c5_x_y;
  c5_k_b = c5_mc_x;
  c5_ab_y = c5_j_a * c5_k_b;
  c5_p_A = c5_yaw;
  c5_nc_x = c5_p_A;
  c5_oc_x = c5_nc_x;
  c5_bb_y = c5_oc_x / 2.0;
  c5_pc_x = c5_bb_y;
  c5_qc_x = c5_pc_x;
  c5_qc_x = muDoubleScalarCos(c5_qc_x);
  c5_q_A = c5_pitch;
  c5_rc_x = c5_q_A;
  c5_sc_x = c5_rc_x;
  c5_cb_y = c5_sc_x / 2.0;
  c5_tc_x = c5_cb_y;
  c5_uc_x = c5_tc_x;
  c5_uc_x = muDoubleScalarSin(c5_uc_x);
  c5_k_a = c5_qc_x;
  c5_l_b = c5_uc_x;
  c5_db_y = c5_k_a * c5_l_b;
  c5_r_A = c5_roll;
  c5_vc_x = c5_r_A;
  c5_wc_x = c5_vc_x;
  c5_eb_y = c5_wc_x / 2.0;
  c5_xc_x = c5_eb_y;
  c5_yc_x = c5_xc_x;
  c5_yc_x = muDoubleScalarSin(c5_yc_x);
  c5_l_a = c5_db_y;
  c5_m_b = c5_yc_x;
  c5_fb_y = c5_l_a * c5_m_b;
  c5_y = c5_ab_y + c5_fb_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_s_A = c5_yaw;
  c5_ad_x = c5_s_A;
  c5_bd_x = c5_ad_x;
  c5_gb_y = c5_bd_x / 2.0;
  c5_cd_x = c5_gb_y;
  c5_dd_x = c5_cd_x;
  c5_dd_x = muDoubleScalarCos(c5_dd_x);
  c5_t_A = c5_pitch;
  c5_ed_x = c5_t_A;
  c5_fd_x = c5_ed_x;
  c5_hb_y = c5_fd_x / 2.0;
  c5_gd_x = c5_hb_y;
  c5_hd_x = c5_gd_x;
  c5_hd_x = muDoubleScalarSin(c5_hd_x);
  c5_m_a = c5_dd_x;
  c5_n_b = c5_hd_x;
  c5_ib_y = c5_m_a * c5_n_b;
  c5_u_A = c5_roll;
  c5_id_x = c5_u_A;
  c5_jd_x = c5_id_x;
  c5_jb_y = c5_jd_x / 2.0;
  c5_kd_x = c5_jb_y;
  c5_ld_x = c5_kd_x;
  c5_ld_x = muDoubleScalarCos(c5_ld_x);
  c5_n_a = c5_ib_y;
  c5_o_b = c5_ld_x;
  c5_kb_y = c5_n_a * c5_o_b;
  c5_v_A = c5_yaw;
  c5_md_x = c5_v_A;
  c5_nd_x = c5_md_x;
  c5_lb_y = c5_nd_x / 2.0;
  c5_od_x = c5_lb_y;
  c5_pd_x = c5_od_x;
  c5_pd_x = muDoubleScalarSin(c5_pd_x);
  c5_w_A = c5_pitch;
  c5_qd_x = c5_w_A;
  c5_rd_x = c5_qd_x;
  c5_mb_y = c5_rd_x / 2.0;
  c5_sd_x = c5_mb_y;
  c5_td_x = c5_sd_x;
  c5_td_x = muDoubleScalarCos(c5_td_x);
  c5_o_a = c5_pd_x;
  c5_p_b = c5_td_x;
  c5_nb_y = c5_o_a * c5_p_b;
  c5_x_A = c5_roll;
  c5_ud_x = c5_x_A;
  c5_vd_x = c5_ud_x;
  c5_ob_y = c5_vd_x / 2.0;
  c5_wd_x = c5_ob_y;
  c5_xd_x = c5_wd_x;
  c5_xd_x = muDoubleScalarSin(c5_xd_x);
  c5_p_a = c5_nb_y;
  c5_q_b = c5_xd_x;
  c5_pb_y = c5_p_a * c5_q_b;
  c5_z = c5_kb_y + c5_pb_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -8);
  sf_debug_symbol_scope_pop();
  *c5_yd_x = c5_x;
  *c5_qb_y = c5_y;
  *c5_b_z = c5_z;
  *c5_b_theta = c5_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Quadsim(SFc5_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QuadsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_theta, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_theta), &c5_thisId);
  sf_mex_destroy(&c5_theta);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_theta;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QuadsimInstanceStruct *)chartInstanceVoid;
  c5_theta = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_theta), &c5_thisId);
  sf_mex_destroy(&c5_theta);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[11];
  c5_ResolvedFunctionInfo (*c5_b_info)[11];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i0;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[11])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "mrdivide";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[0].fileTimeLo = 1342807344U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 1319726366U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[1].name = "rdivide";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[1].fileTimeLo = 1286815244U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[2].name = "eml_div";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c5_b_info)[2].fileTimeLo = 1313344210U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  (*c5_b_info)[3].context = "";
  (*c5_b_info)[3].name = "cos";
  (*c5_b_info)[3].dominantType = "double";
  (*c5_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[3].fileTimeLo = 1286815106U;
  (*c5_b_info)[3].fileTimeHi = 0U;
  (*c5_b_info)[3].mFileTimeLo = 0U;
  (*c5_b_info)[3].mFileTimeHi = 0U;
  (*c5_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[4].name = "eml_scalar_cos";
  (*c5_b_info)[4].dominantType = "double";
  (*c5_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c5_b_info)[4].fileTimeLo = 1286815122U;
  (*c5_b_info)[4].fileTimeHi = 0U;
  (*c5_b_info)[4].mFileTimeLo = 0U;
  (*c5_b_info)[4].mFileTimeHi = 0U;
  (*c5_b_info)[5].context = "";
  (*c5_b_info)[5].name = "mtimes";
  (*c5_b_info)[5].dominantType = "double";
  (*c5_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[5].fileTimeLo = 1289516092U;
  (*c5_b_info)[5].fileTimeHi = 0U;
  (*c5_b_info)[5].mFileTimeLo = 0U;
  (*c5_b_info)[5].mFileTimeHi = 0U;
  (*c5_b_info)[6].context = "";
  (*c5_b_info)[6].name = "sin";
  (*c5_b_info)[6].dominantType = "double";
  (*c5_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[6].fileTimeLo = 1286815150U;
  (*c5_b_info)[6].fileTimeHi = 0U;
  (*c5_b_info)[6].mFileTimeLo = 0U;
  (*c5_b_info)[6].mFileTimeHi = 0U;
  (*c5_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[7].name = "eml_scalar_sin";
  (*c5_b_info)[7].dominantType = "double";
  (*c5_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c5_b_info)[7].fileTimeLo = 1286815136U;
  (*c5_b_info)[7].fileTimeHi = 0U;
  (*c5_b_info)[7].mFileTimeLo = 0U;
  (*c5_b_info)[7].mFileTimeHi = 0U;
  (*c5_b_info)[8].context = "";
  (*c5_b_info)[8].name = "acos";
  (*c5_b_info)[8].dominantType = "double";
  (*c5_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c5_b_info)[8].fileTimeLo = 1286815094U;
  (*c5_b_info)[8].fileTimeHi = 0U;
  (*c5_b_info)[8].mFileTimeLo = 0U;
  (*c5_b_info)[8].mFileTimeHi = 0U;
  (*c5_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c5_b_info)[9].name = "eml_error";
  (*c5_b_info)[9].dominantType = "char";
  (*c5_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c5_b_info)[9].fileTimeLo = 1305314400U;
  (*c5_b_info)[9].fileTimeHi = 0U;
  (*c5_b_info)[9].mFileTimeLo = 0U;
  (*c5_b_info)[9].mFileTimeHi = 0U;
  (*c5_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c5_b_info)[10].name = "eml_scalar_acos";
  (*c5_b_info)[10].dominantType = "double";
  (*c5_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  (*c5_b_info)[10].fileTimeLo = 1286815112U;
  (*c5_b_info)[10].fileTimeHi = 0U;
  (*c5_b_info)[10].mFileTimeLo = 0U;
  (*c5_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c5_i0 = 0; c5_i0 < 11; c5_i0++) {
    c5_r0 = &c5_info[c5_i0];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i0);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_eml_error(SFc5_QuadsimInstanceStruct *chartInstance)
{
  int32_T c5_i1;
  static char_T c5_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'a', 'c', 'o', 's', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  for (c5_i1 = 0; c5_i1 < 30; c5_i1++) {
    c5_u[c5_i1] = c5_varargin_1[c5_i1];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c5_y));
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QuadsimInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i2;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i2, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i2;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QuadsimInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Quadsim, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Quadsim), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Quadsim);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_QuadsimInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(141790817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1935014339U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3832627190U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2776272519U);
}

mxArray *sf_c5_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YS9XocuN8LPX8L1d5YQbfC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[10],T\"theta\",},{M[1],M[8],T\"x\",},{M[1],M[5],T\"y\",},{M[1],M[9],T\"z\",},{M[8],M[0],T\"is_active_c5_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc5_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          5,
          1,
          1,
          7,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QuadsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_QuadsimMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QuadsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(2,2,0,1,"x");
          _SFD_SET_DATA_PROPS(3,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(4,2,0,1,"y");
          _SFD_SET_DATA_PROPS(5,2,0,1,"z");
          _SFD_SET_DATA_PROPS(6,2,0,1,"theta");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,402);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_roll;
          real_T *c5_pitch;
          real_T *c5_x;
          real_T *c5_yaw;
          real_T *c5_y;
          real_T *c5_z;
          real_T *c5_theta;
          c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c5_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_roll);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_pitch);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_x);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_yaw);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QuadsimMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "vLTA2eC5fVHgR425DciQCB";
}

static void sf_opaque_initialize_c5_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Quadsim(void *chartInstanceVar)
{
  enable_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Quadsim(void *chartInstanceVar)
{
  disable_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Quadsim(void *chartInstanceVar)
{
  sf_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Quadsim((SFc5_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Quadsim((SFc5_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_Quadsim(S);
}

static void sf_opaque_set_sim_state_c5_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_Quadsim(S, st);
}

static void sf_opaque_terminate_c5_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Quadsim((SFc5_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Quadsim((SFc5_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2359459675U));
  ssSetChecksum1(S,(1904460565U));
  ssSetChecksum2(S,(469450931U));
  ssSetChecksum3(S,(1088414852U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Quadsim(SimStruct *S)
{
  SFc5_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc5_QuadsimInstanceStruct *)malloc(sizeof
    (SFc5_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Quadsim;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
