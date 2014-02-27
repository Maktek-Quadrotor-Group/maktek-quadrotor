/* Include files */

#include "blascompat32.h"
#include "quadPD_sfun.h"
#include "c6_quadPD.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quadPD_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[9] = { "nargin", "nargout", "Fi",
  "Teta", "Psi", "x", "y", "z", "theta" };

/* Function Declarations */
static void initialize_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void initialize_params_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void enable_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void disable_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_quadPD(SFc6_quadPDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_quadPD(SFc6_quadPDInstanceStruct
  *chartInstance);
static void set_sim_state_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void sf_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void c6_chartstep_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void initSimStructsc6_quadPD(SFc6_quadPDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_theta, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_eml_error(SFc6_quadPDInstanceStruct *chartInstance);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_c_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_d_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_quadPD, const char_T *c6_identifier);
static uint8_T c6_e_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_quadPDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_quadPD = 0U;
}

static void initialize_params_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
}

static void enable_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_quadPD(SFc6_quadPDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_quadPD(SFc6_quadPDInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_c_hoistedGlobal;
  real_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_d_hoistedGlobal;
  real_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  real_T *c6_theta;
  real_T *c6_x;
  real_T *c6_g_y;
  real_T *c6_z;
  c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(5), FALSE);
  c6_hoistedGlobal = *c6_theta;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_x;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = *c6_g_y;
  c6_c_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = *c6_z;
  c6_d_u = c6_d_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = chartInstance->c6_is_active_c6_quadPD;
  c6_e_u = c6_e_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_theta;
  real_T *c6_x;
  real_T *c6_y;
  real_T *c6_z;
  c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_theta = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    0)), "theta");
  *c6_x = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "x");
  *c6_y = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
    "y");
  *c6_z = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
    "z");
  chartInstance->c6_is_active_c6_quadPD = c6_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 4)), "is_active_c6_quadPD");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_quadPD(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
}

static void sf_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
  real_T *c6_Fi;
  real_T *c6_Teta;
  real_T *c6_x;
  real_T *c6_Psi;
  real_T *c6_y;
  real_T *c6_z;
  real_T *c6_theta;
  c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_Teta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_Fi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_Fi, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_Teta, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_x, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_Psi, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c6_theta, 6U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_quadPD(chartInstance);
  sf_debug_check_for_state_inconsistency(_quadPDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_Fi;
  real_T c6_Teta;
  real_T c6_Psi;
  uint32_T c6_debug_family_var_map[9];
  real_T c6_nargin = 3.0;
  real_T c6_nargout = 4.0;
  real_T c6_x;
  real_T c6_y;
  real_T c6_z;
  real_T c6_theta;
  real_T c6_A;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_b_y;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_b_A;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_c_y;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_a;
  real_T c6_b;
  real_T c6_d_y;
  real_T c6_c_A;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_e_y;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_f_y;
  real_T c6_d_A;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_g_y;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_e_A;
  real_T c6_r_x;
  real_T c6_s_x;
  real_T c6_h_y;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_c_a;
  real_T c6_c_b;
  real_T c6_i_y;
  real_T c6_f_A;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_j_y;
  real_T c6_x_x;
  real_T c6_y_x;
  real_T c6_d_a;
  real_T c6_d_b;
  real_T c6_k_y;
  real_T c6_ab_x;
  real_T c6_bb_x;
  real_T c6_e_b;
  real_T c6_g_A;
  real_T c6_cb_x;
  real_T c6_db_x;
  real_T c6_l_y;
  real_T c6_eb_x;
  real_T c6_fb_x;
  real_T c6_h_A;
  real_T c6_gb_x;
  real_T c6_hb_x;
  real_T c6_m_y;
  real_T c6_ib_x;
  real_T c6_jb_x;
  real_T c6_e_a;
  real_T c6_f_b;
  real_T c6_n_y;
  real_T c6_i_A;
  real_T c6_kb_x;
  real_T c6_lb_x;
  real_T c6_o_y;
  real_T c6_mb_x;
  real_T c6_nb_x;
  real_T c6_f_a;
  real_T c6_g_b;
  real_T c6_p_y;
  real_T c6_j_A;
  real_T c6_ob_x;
  real_T c6_pb_x;
  real_T c6_q_y;
  real_T c6_qb_x;
  real_T c6_rb_x;
  real_T c6_k_A;
  real_T c6_sb_x;
  real_T c6_tb_x;
  real_T c6_r_y;
  real_T c6_ub_x;
  real_T c6_vb_x;
  real_T c6_g_a;
  real_T c6_h_b;
  real_T c6_s_y;
  real_T c6_l_A;
  real_T c6_wb_x;
  real_T c6_xb_x;
  real_T c6_t_y;
  real_T c6_yb_x;
  real_T c6_ac_x;
  real_T c6_h_a;
  real_T c6_i_b;
  real_T c6_u_y;
  real_T c6_m_A;
  real_T c6_bc_x;
  real_T c6_cc_x;
  real_T c6_v_y;
  real_T c6_dc_x;
  real_T c6_ec_x;
  real_T c6_n_A;
  real_T c6_fc_x;
  real_T c6_gc_x;
  real_T c6_w_y;
  real_T c6_hc_x;
  real_T c6_ic_x;
  real_T c6_i_a;
  real_T c6_j_b;
  real_T c6_x_y;
  real_T c6_o_A;
  real_T c6_jc_x;
  real_T c6_kc_x;
  real_T c6_y_y;
  real_T c6_lc_x;
  real_T c6_mc_x;
  real_T c6_j_a;
  real_T c6_k_b;
  real_T c6_ab_y;
  real_T c6_p_A;
  real_T c6_nc_x;
  real_T c6_oc_x;
  real_T c6_bb_y;
  real_T c6_pc_x;
  real_T c6_qc_x;
  real_T c6_q_A;
  real_T c6_rc_x;
  real_T c6_sc_x;
  real_T c6_cb_y;
  real_T c6_tc_x;
  real_T c6_uc_x;
  real_T c6_k_a;
  real_T c6_l_b;
  real_T c6_db_y;
  real_T c6_r_A;
  real_T c6_vc_x;
  real_T c6_wc_x;
  real_T c6_eb_y;
  real_T c6_xc_x;
  real_T c6_yc_x;
  real_T c6_l_a;
  real_T c6_m_b;
  real_T c6_fb_y;
  real_T c6_s_A;
  real_T c6_ad_x;
  real_T c6_bd_x;
  real_T c6_gb_y;
  real_T c6_cd_x;
  real_T c6_dd_x;
  real_T c6_t_A;
  real_T c6_ed_x;
  real_T c6_fd_x;
  real_T c6_hb_y;
  real_T c6_gd_x;
  real_T c6_hd_x;
  real_T c6_m_a;
  real_T c6_n_b;
  real_T c6_ib_y;
  real_T c6_u_A;
  real_T c6_id_x;
  real_T c6_jd_x;
  real_T c6_jb_y;
  real_T c6_kd_x;
  real_T c6_ld_x;
  real_T c6_n_a;
  real_T c6_o_b;
  real_T c6_kb_y;
  real_T c6_v_A;
  real_T c6_md_x;
  real_T c6_nd_x;
  real_T c6_lb_y;
  real_T c6_od_x;
  real_T c6_pd_x;
  real_T c6_w_A;
  real_T c6_qd_x;
  real_T c6_rd_x;
  real_T c6_mb_y;
  real_T c6_sd_x;
  real_T c6_td_x;
  real_T c6_o_a;
  real_T c6_p_b;
  real_T c6_nb_y;
  real_T c6_x_A;
  real_T c6_ud_x;
  real_T c6_vd_x;
  real_T c6_ob_y;
  real_T c6_wd_x;
  real_T c6_xd_x;
  real_T c6_p_a;
  real_T c6_q_b;
  real_T c6_pb_y;
  real_T *c6_b_theta;
  real_T *c6_b_z;
  real_T *c6_qb_y;
  real_T *c6_yd_x;
  real_T *c6_b_Psi;
  real_T *c6_b_Teta;
  real_T *c6_b_Fi;
  boolean_T guard1 = FALSE;
  c6_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_b_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_qb_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_yd_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_Teta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_Fi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_Fi;
  c6_b_hoistedGlobal = *c6_b_Teta;
  c6_c_hoistedGlobal = *c6_b_Psi;
  c6_Fi = c6_hoistedGlobal;
  c6_Teta = c6_b_hoistedGlobal;
  c6_Psi = c6_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_Fi, 2U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Teta, 3U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Psi, 4U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_x, 5U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_y, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_z, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_theta, 8U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_Teta = -c6_Teta;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_A = c6_Psi;
  c6_b_x = c6_A;
  c6_c_x = c6_b_x;
  c6_b_y = c6_c_x / 2.0;
  c6_d_x = c6_b_y;
  c6_e_x = c6_d_x;
  c6_e_x = muDoubleScalarCos(c6_e_x);
  c6_b_A = c6_Teta;
  c6_f_x = c6_b_A;
  c6_g_x = c6_f_x;
  c6_c_y = c6_g_x / 2.0;
  c6_h_x = c6_c_y;
  c6_i_x = c6_h_x;
  c6_i_x = muDoubleScalarCos(c6_i_x);
  c6_a = c6_e_x;
  c6_b = c6_i_x;
  c6_d_y = c6_a * c6_b;
  c6_c_A = c6_Fi;
  c6_j_x = c6_c_A;
  c6_k_x = c6_j_x;
  c6_e_y = c6_k_x / 2.0;
  c6_l_x = c6_e_y;
  c6_m_x = c6_l_x;
  c6_m_x = muDoubleScalarCos(c6_m_x);
  c6_b_a = c6_d_y;
  c6_b_b = c6_m_x;
  c6_f_y = c6_b_a * c6_b_b;
  c6_d_A = c6_Psi;
  c6_n_x = c6_d_A;
  c6_o_x = c6_n_x;
  c6_g_y = c6_o_x / 2.0;
  c6_p_x = c6_g_y;
  c6_q_x = c6_p_x;
  c6_q_x = muDoubleScalarSin(c6_q_x);
  c6_e_A = c6_Teta;
  c6_r_x = c6_e_A;
  c6_s_x = c6_r_x;
  c6_h_y = c6_s_x / 2.0;
  c6_t_x = c6_h_y;
  c6_u_x = c6_t_x;
  c6_u_x = muDoubleScalarSin(c6_u_x);
  c6_c_a = c6_q_x;
  c6_c_b = c6_u_x;
  c6_i_y = c6_c_a * c6_c_b;
  c6_f_A = c6_Fi;
  c6_v_x = c6_f_A;
  c6_w_x = c6_v_x;
  c6_j_y = c6_w_x / 2.0;
  c6_x_x = c6_j_y;
  c6_y_x = c6_x_x;
  c6_y_x = muDoubleScalarSin(c6_y_x);
  c6_d_a = c6_i_y;
  c6_d_b = c6_y_x;
  c6_k_y = c6_d_a * c6_d_b;
  c6_ab_x = c6_f_y - c6_k_y;
  c6_bb_x = c6_ab_x;
  guard1 = FALSE;
  if (c6_bb_x < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < c6_bb_x) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c6_eml_error(chartInstance);
  }

  c6_bb_x = muDoubleScalarAcos(c6_bb_x);
  c6_e_b = c6_bb_x;
  c6_theta = 2.0 * c6_e_b;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_g_A = c6_Psi;
  c6_cb_x = c6_g_A;
  c6_db_x = c6_cb_x;
  c6_l_y = c6_db_x / 2.0;
  c6_eb_x = c6_l_y;
  c6_fb_x = c6_eb_x;
  c6_fb_x = muDoubleScalarSin(c6_fb_x);
  c6_h_A = c6_Teta;
  c6_gb_x = c6_h_A;
  c6_hb_x = c6_gb_x;
  c6_m_y = c6_hb_x / 2.0;
  c6_ib_x = c6_m_y;
  c6_jb_x = c6_ib_x;
  c6_jb_x = muDoubleScalarSin(c6_jb_x);
  c6_e_a = c6_fb_x;
  c6_f_b = c6_jb_x;
  c6_n_y = c6_e_a * c6_f_b;
  c6_i_A = c6_Fi;
  c6_kb_x = c6_i_A;
  c6_lb_x = c6_kb_x;
  c6_o_y = c6_lb_x / 2.0;
  c6_mb_x = c6_o_y;
  c6_nb_x = c6_mb_x;
  c6_nb_x = muDoubleScalarCos(c6_nb_x);
  c6_f_a = c6_n_y;
  c6_g_b = c6_nb_x;
  c6_p_y = c6_f_a * c6_g_b;
  c6_j_A = c6_Psi;
  c6_ob_x = c6_j_A;
  c6_pb_x = c6_ob_x;
  c6_q_y = c6_pb_x / 2.0;
  c6_qb_x = c6_q_y;
  c6_rb_x = c6_qb_x;
  c6_rb_x = muDoubleScalarCos(c6_rb_x);
  c6_k_A = c6_Teta;
  c6_sb_x = c6_k_A;
  c6_tb_x = c6_sb_x;
  c6_r_y = c6_tb_x / 2.0;
  c6_ub_x = c6_r_y;
  c6_vb_x = c6_ub_x;
  c6_vb_x = muDoubleScalarCos(c6_vb_x);
  c6_g_a = c6_rb_x;
  c6_h_b = c6_vb_x;
  c6_s_y = c6_g_a * c6_h_b;
  c6_l_A = c6_Fi;
  c6_wb_x = c6_l_A;
  c6_xb_x = c6_wb_x;
  c6_t_y = c6_xb_x / 2.0;
  c6_yb_x = c6_t_y;
  c6_ac_x = c6_yb_x;
  c6_ac_x = muDoubleScalarSin(c6_ac_x);
  c6_h_a = c6_s_y;
  c6_i_b = c6_ac_x;
  c6_u_y = c6_h_a * c6_i_b;
  c6_x = c6_p_y + c6_u_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_m_A = c6_Psi;
  c6_bc_x = c6_m_A;
  c6_cc_x = c6_bc_x;
  c6_v_y = c6_cc_x / 2.0;
  c6_dc_x = c6_v_y;
  c6_ec_x = c6_dc_x;
  c6_ec_x = muDoubleScalarSin(c6_ec_x);
  c6_n_A = c6_Teta;
  c6_fc_x = c6_n_A;
  c6_gc_x = c6_fc_x;
  c6_w_y = c6_gc_x / 2.0;
  c6_hc_x = c6_w_y;
  c6_ic_x = c6_hc_x;
  c6_ic_x = muDoubleScalarCos(c6_ic_x);
  c6_i_a = c6_ec_x;
  c6_j_b = c6_ic_x;
  c6_x_y = c6_i_a * c6_j_b;
  c6_o_A = c6_Fi;
  c6_jc_x = c6_o_A;
  c6_kc_x = c6_jc_x;
  c6_y_y = c6_kc_x / 2.0;
  c6_lc_x = c6_y_y;
  c6_mc_x = c6_lc_x;
  c6_mc_x = muDoubleScalarCos(c6_mc_x);
  c6_j_a = c6_x_y;
  c6_k_b = c6_mc_x;
  c6_ab_y = c6_j_a * c6_k_b;
  c6_p_A = c6_Psi;
  c6_nc_x = c6_p_A;
  c6_oc_x = c6_nc_x;
  c6_bb_y = c6_oc_x / 2.0;
  c6_pc_x = c6_bb_y;
  c6_qc_x = c6_pc_x;
  c6_qc_x = muDoubleScalarCos(c6_qc_x);
  c6_q_A = c6_Teta;
  c6_rc_x = c6_q_A;
  c6_sc_x = c6_rc_x;
  c6_cb_y = c6_sc_x / 2.0;
  c6_tc_x = c6_cb_y;
  c6_uc_x = c6_tc_x;
  c6_uc_x = muDoubleScalarSin(c6_uc_x);
  c6_k_a = c6_qc_x;
  c6_l_b = c6_uc_x;
  c6_db_y = c6_k_a * c6_l_b;
  c6_r_A = c6_Fi;
  c6_vc_x = c6_r_A;
  c6_wc_x = c6_vc_x;
  c6_eb_y = c6_wc_x / 2.0;
  c6_xc_x = c6_eb_y;
  c6_yc_x = c6_xc_x;
  c6_yc_x = muDoubleScalarSin(c6_yc_x);
  c6_l_a = c6_db_y;
  c6_m_b = c6_yc_x;
  c6_fb_y = c6_l_a * c6_m_b;
  c6_y = c6_ab_y + c6_fb_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_s_A = c6_Psi;
  c6_ad_x = c6_s_A;
  c6_bd_x = c6_ad_x;
  c6_gb_y = c6_bd_x / 2.0;
  c6_cd_x = c6_gb_y;
  c6_dd_x = c6_cd_x;
  c6_dd_x = muDoubleScalarCos(c6_dd_x);
  c6_t_A = c6_Teta;
  c6_ed_x = c6_t_A;
  c6_fd_x = c6_ed_x;
  c6_hb_y = c6_fd_x / 2.0;
  c6_gd_x = c6_hb_y;
  c6_hd_x = c6_gd_x;
  c6_hd_x = muDoubleScalarSin(c6_hd_x);
  c6_m_a = c6_dd_x;
  c6_n_b = c6_hd_x;
  c6_ib_y = c6_m_a * c6_n_b;
  c6_u_A = c6_Fi;
  c6_id_x = c6_u_A;
  c6_jd_x = c6_id_x;
  c6_jb_y = c6_jd_x / 2.0;
  c6_kd_x = c6_jb_y;
  c6_ld_x = c6_kd_x;
  c6_ld_x = muDoubleScalarCos(c6_ld_x);
  c6_n_a = c6_ib_y;
  c6_o_b = c6_ld_x;
  c6_kb_y = c6_n_a * c6_o_b;
  c6_v_A = c6_Psi;
  c6_md_x = c6_v_A;
  c6_nd_x = c6_md_x;
  c6_lb_y = c6_nd_x / 2.0;
  c6_od_x = c6_lb_y;
  c6_pd_x = c6_od_x;
  c6_pd_x = muDoubleScalarSin(c6_pd_x);
  c6_w_A = c6_Teta;
  c6_qd_x = c6_w_A;
  c6_rd_x = c6_qd_x;
  c6_mb_y = c6_rd_x / 2.0;
  c6_sd_x = c6_mb_y;
  c6_td_x = c6_sd_x;
  c6_td_x = muDoubleScalarCos(c6_td_x);
  c6_o_a = c6_pd_x;
  c6_p_b = c6_td_x;
  c6_nb_y = c6_o_a * c6_p_b;
  c6_x_A = c6_Fi;
  c6_ud_x = c6_x_A;
  c6_vd_x = c6_ud_x;
  c6_ob_y = c6_vd_x / 2.0;
  c6_wd_x = c6_ob_y;
  c6_xd_x = c6_wd_x;
  c6_xd_x = muDoubleScalarSin(c6_xd_x);
  c6_p_a = c6_nb_y;
  c6_q_b = c6_xd_x;
  c6_pb_y = c6_p_a * c6_q_b;
  c6_z = c6_kb_y + c6_pb_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -8);
  sf_debug_symbol_scope_pop();
  *c6_yd_x = c6_x;
  *c6_qb_y = c6_y;
  *c6_b_z = c6_z;
  *c6_b_theta = c6_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_quadPD(SFc6_quadPDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc6_quadPDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_theta, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta), &c6_thisId);
  sf_mex_destroy(&c6_theta);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_theta;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc6_quadPDInstanceStruct *)chartInstanceVoid;
  c6_theta = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_theta), &c6_thisId);
  sf_mex_destroy(&c6_theta);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_quadPD_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[11];
  c6_ResolvedFunctionInfo (*c6_b_info)[11];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i0;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[11])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mrdivide";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[0].fileTimeLo = 1342807344U;
  (*c6_b_info)[0].fileTimeHi = 0U;
  (*c6_b_info)[0].mFileTimeLo = 1319726366U;
  (*c6_b_info)[0].mFileTimeHi = 0U;
  (*c6_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c6_b_info)[1].name = "rdivide";
  (*c6_b_info)[1].dominantType = "double";
  (*c6_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[1].fileTimeLo = 1286815244U;
  (*c6_b_info)[1].fileTimeHi = 0U;
  (*c6_b_info)[1].mFileTimeLo = 0U;
  (*c6_b_info)[1].mFileTimeHi = 0U;
  (*c6_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c6_b_info)[2].name = "eml_div";
  (*c6_b_info)[2].dominantType = "double";
  (*c6_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c6_b_info)[2].fileTimeLo = 1313344210U;
  (*c6_b_info)[2].fileTimeHi = 0U;
  (*c6_b_info)[2].mFileTimeLo = 0U;
  (*c6_b_info)[2].mFileTimeHi = 0U;
  (*c6_b_info)[3].context = "";
  (*c6_b_info)[3].name = "cos";
  (*c6_b_info)[3].dominantType = "double";
  (*c6_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c6_b_info)[3].fileTimeLo = 1286815106U;
  (*c6_b_info)[3].fileTimeHi = 0U;
  (*c6_b_info)[3].mFileTimeLo = 0U;
  (*c6_b_info)[3].mFileTimeHi = 0U;
  (*c6_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c6_b_info)[4].name = "eml_scalar_cos";
  (*c6_b_info)[4].dominantType = "double";
  (*c6_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c6_b_info)[4].fileTimeLo = 1286815122U;
  (*c6_b_info)[4].fileTimeHi = 0U;
  (*c6_b_info)[4].mFileTimeLo = 0U;
  (*c6_b_info)[4].mFileTimeHi = 0U;
  (*c6_b_info)[5].context = "";
  (*c6_b_info)[5].name = "mtimes";
  (*c6_b_info)[5].dominantType = "double";
  (*c6_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c6_b_info)[5].fileTimeLo = 1289516092U;
  (*c6_b_info)[5].fileTimeHi = 0U;
  (*c6_b_info)[5].mFileTimeLo = 0U;
  (*c6_b_info)[5].mFileTimeHi = 0U;
  (*c6_b_info)[6].context = "";
  (*c6_b_info)[6].name = "sin";
  (*c6_b_info)[6].dominantType = "double";
  (*c6_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c6_b_info)[6].fileTimeLo = 1286815150U;
  (*c6_b_info)[6].fileTimeHi = 0U;
  (*c6_b_info)[6].mFileTimeLo = 0U;
  (*c6_b_info)[6].mFileTimeHi = 0U;
  (*c6_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c6_b_info)[7].name = "eml_scalar_sin";
  (*c6_b_info)[7].dominantType = "double";
  (*c6_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c6_b_info)[7].fileTimeLo = 1286815136U;
  (*c6_b_info)[7].fileTimeHi = 0U;
  (*c6_b_info)[7].mFileTimeLo = 0U;
  (*c6_b_info)[7].mFileTimeHi = 0U;
  (*c6_b_info)[8].context = "";
  (*c6_b_info)[8].name = "acos";
  (*c6_b_info)[8].dominantType = "double";
  (*c6_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[8].fileTimeLo = 1286815094U;
  (*c6_b_info)[8].fileTimeHi = 0U;
  (*c6_b_info)[8].mFileTimeLo = 0U;
  (*c6_b_info)[8].mFileTimeHi = 0U;
  (*c6_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[9].name = "eml_error";
  (*c6_b_info)[9].dominantType = "char";
  (*c6_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c6_b_info)[9].fileTimeLo = 1305314400U;
  (*c6_b_info)[9].fileTimeHi = 0U;
  (*c6_b_info)[9].mFileTimeLo = 0U;
  (*c6_b_info)[9].mFileTimeHi = 0U;
  (*c6_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  (*c6_b_info)[10].name = "eml_scalar_acos";
  (*c6_b_info)[10].dominantType = "double";
  (*c6_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  (*c6_b_info)[10].fileTimeLo = 1286815112U;
  (*c6_b_info)[10].fileTimeHi = 0U;
  (*c6_b_info)[10].mFileTimeLo = 0U;
  (*c6_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c6_i0 = 0; c6_i0 < 11; c6_i0++) {
    c6_r0 = &c6_info[c6_i0];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i0);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_eml_error(SFc6_quadPDInstanceStruct *chartInstance)
{
  int32_T c6_i1;
  static char_T c6_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'a', 'c', 'o', 's', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  for (c6_i1 = 0; c6_i1 < 30; c6_i1++) {
    c6_u[c6_i1] = c6_varargin_1[c6_i1];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc6_quadPDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_c_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i2;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i2, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i2;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc6_quadPDInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_d_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_quadPD, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_quadPD), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_quadPD);
  return c6_y;
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_quadPDInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_quadPDInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_quadPD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1103765472U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3727094824U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4283172431U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2333501688U);
}

mxArray *sf_c6_quadPD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("E6egBDwxv2QiMofOnIoLRC");
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

static const mxArray *sf_get_sim_state_info_c6_quadPD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[10],T\"theta\",},{M[1],M[8],T\"x\",},{M[1],M[5],T\"y\",},{M[1],M[9],T\"z\",},{M[8],M[0],T\"is_active_c6_quadPD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_quadPD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_quadPDInstanceStruct *chartInstance;
    chartInstance = (SFc6_quadPDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_quadPDMachineNumber_,
          6,
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
          init_script_number_translation(_quadPDMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_quadPDMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_quadPDMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Fi");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Teta");
          _SFD_SET_DATA_PROPS(2,2,0,1,"x");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Psi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,373);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_Fi;
          real_T *c6_Teta;
          real_T *c6_x;
          real_T *c6_Psi;
          real_T *c6_y;
          real_T *c6_z;
          real_T *c6_theta;
          c6_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c6_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_Teta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_Fi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_Fi);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_Teta);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_x);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_Psi);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_quadPDMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "LzOSdZzcQHf8B1Txmm08MD";
}

static void sf_opaque_initialize_c6_quadPD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_quadPDInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
  initialize_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_quadPD(void *chartInstanceVar)
{
  enable_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_quadPD(void *chartInstanceVar)
{
  disable_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_quadPD(void *chartInstanceVar)
{
  sf_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_quadPD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_quadPD((SFc6_quadPDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_quadPD();/* state var info */
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

extern void sf_internal_set_sim_state_c6_quadPD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_quadPD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_quadPD((SFc6_quadPDInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_quadPD(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_quadPD(S);
}

static void sf_opaque_set_sim_state_c6_quadPD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_quadPD(S, st);
}

static void sf_opaque_terminate_c6_quadPD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_quadPDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_quadPD_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_quadPD((SFc6_quadPDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_quadPD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_quadPD((SFc6_quadPDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quadPD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1691633245U));
  ssSetChecksum1(S,(4080382493U));
  ssSetChecksum2(S,(2748126710U));
  ssSetChecksum3(S,(187387501U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_quadPD(SimStruct *S)
{
  SFc6_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc6_quadPDInstanceStruct *)malloc(sizeof
    (SFc6_quadPDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_quadPDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_quadPD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_quadPD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_quadPD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_quadPD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_quadPD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_quadPD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_quadPD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_quadPD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_quadPD;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_quadPD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_quadPD;
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

void c6_quadPD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_quadPD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_quadPD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_quadPD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_quadPD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
