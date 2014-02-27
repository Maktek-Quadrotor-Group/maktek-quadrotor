/* Include files */

#include "blascompat32.h"
#include "quadPD_sfun.h"
#include "c1_quadPD.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quadPD_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[41] = { "dFi", "dTeta", "dPsi", "Fi",
  "Teta", "Psi", "U1", "U2", "U3", "U4", "Omega", "Ixx", "Iyy", "Izz", "Jr", "l",
  "g", "m", "a1", "a2", "a3", "a4", "a5", "b1", "b2", "b3", "ux", "uy", "d2Fi",
  "d2Teta", "d2Psi", "d2Z", "d2X", "d2Y", "nargin", "nargout", "dAlfa", "Alfa",
  "U", "d2Alfa", "d2Konum" };

/* Function Declarations */
static void initialize_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void initialize_params_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void enable_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void disable_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_quadPD(SFc1_quadPDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_quadPD(SFc1_quadPDInstanceStruct
  *chartInstance);
static void set_sim_state_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void sf_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void c1_chartstep_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void initSimStructsc1_quadPD(SFc1_quadPDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance, const
  mxArray *c1_d2Konum, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[14]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_quadPD, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_quadPDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_quadPD = 0U;
}

static void initialize_params_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
}

static void enable_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_quadPD(SFc1_quadPDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_quadPD(SFc1_quadPDInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T (*c1_d2Konum)[3];
  real_T (*c1_d2Alfa)[3];
  c1_d2Konum = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_d2Alfa = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_d2Alfa)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_d2Konum)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_quadPD;
  c1_c_u = c1_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i2;
  real_T c1_dv1[3];
  int32_T c1_i3;
  real_T (*c1_d2Alfa)[3];
  real_T (*c1_d2Konum)[3];
  c1_d2Konum = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_d2Alfa = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "d2Alfa", c1_dv0);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    (*c1_d2Alfa)[c1_i2] = c1_dv0[c1_i2];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "d2Konum", c1_dv1);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    (*c1_d2Konum)[c1_i3] = c1_dv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_quadPD = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "is_active_c1_quadPD");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_quadPD(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
}

static void sf_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T (*c1_d2Konum)[3];
  real_T (*c1_U)[5];
  real_T (*c1_d2Alfa)[3];
  real_T (*c1_Alfa)[3];
  real_T (*c1_dAlfa)[3];
  c1_d2Konum = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_U = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 2);
  c1_d2Alfa = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_Alfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_dAlfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_dAlfa)[c1_i4], 0U);
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_Alfa)[c1_i5], 1U);
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_d2Alfa)[c1_i6], 2U);
  }

  for (c1_i7 = 0; c1_i7 < 5; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((*c1_U)[c1_i7], 3U);
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*c1_d2Konum)[c1_i8], 4U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_quadPD(chartInstance);
  sf_debug_check_for_state_inconsistency(_quadPDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
  int32_T c1_i9;
  real_T c1_dAlfa[3];
  int32_T c1_i10;
  real_T c1_Alfa[3];
  int32_T c1_i11;
  real_T c1_U[5];
  uint32_T c1_debug_family_var_map[41];
  real_T c1_dFi;
  real_T c1_dTeta;
  real_T c1_dPsi;
  real_T c1_Fi;
  real_T c1_Teta;
  real_T c1_Psi;
  real_T c1_U1;
  real_T c1_U2;
  real_T c1_U3;
  real_T c1_U4;
  real_T c1_Omega;
  real_T c1_Ixx;
  real_T c1_Iyy;
  real_T c1_Izz;
  real_T c1_Jr;
  real_T c1_l;
  real_T c1_g;
  real_T c1_m;
  real_T c1_a1;
  real_T c1_a2;
  real_T c1_a3;
  real_T c1_a4;
  real_T c1_a5;
  real_T c1_b1;
  real_T c1_b2;
  real_T c1_b3;
  real_T c1_ux;
  real_T c1_uy;
  real_T c1_d2Fi;
  real_T c1_d2Teta;
  real_T c1_d2Psi;
  real_T c1_d2Z;
  real_T c1_d2X;
  real_T c1_d2Y;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 2.0;
  real_T c1_d2Alfa[3];
  real_T c1_d2Konum[3];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_h_a;
  real_T c1_h_y;
  real_T c1_i_a;
  real_T c1_i_y;
  real_T c1_j_a;
  real_T c1_h_b;
  real_T c1_j_y;
  real_T c1_i_b;
  real_T c1_k_y;
  real_T c1_k_a;
  real_T c1_j_b;
  real_T c1_l_y;
  real_T c1_l_a;
  real_T c1_m_y;
  real_T c1_m_a;
  real_T c1_n_y;
  real_T c1_n_a;
  real_T c1_k_b;
  real_T c1_o_y;
  real_T c1_l_b;
  real_T c1_p_y;
  real_T c1_o_a;
  real_T c1_m_b;
  real_T c1_q_y;
  real_T c1_p_a;
  real_T c1_r_y;
  real_T c1_n_b;
  real_T c1_s_y;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_q_a;
  real_T c1_o_b;
  real_T c1_t_y;
  real_T c1_r_a;
  real_T c1_u_y;
  real_T c1_s_a;
  real_T c1_p_b;
  real_T c1_v_y;
  real_T c1_t_a;
  real_T c1_w_y;
  real_T c1_u_a;
  real_T c1_q_b;
  real_T c1_v_a;
  real_T c1_x_y;
  real_T c1_w_a;
  real_T c1_r_b;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T (*c1_b_d2Alfa)[3];
  real_T (*c1_b_d2Konum)[3];
  real_T (*c1_b_U)[5];
  real_T (*c1_b_Alfa)[3];
  real_T (*c1_b_dAlfa)[3];
  c1_b_d2Konum = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_U = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_d2Alfa = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Alfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_dAlfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_dAlfa[c1_i9] = (*c1_b_dAlfa)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_Alfa[c1_i10] = (*c1_b_Alfa)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 5; c1_i11++) {
    c1_U[c1_i11] = (*c1_b_U)[c1_i11];
  }

  sf_debug_symbol_scope_push_eml(0U, 41U, 41U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_dFi, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_dTeta, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_dPsi, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Fi, 3U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Teta, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Psi, 5U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_U1, 6U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_U2, 7U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_U3, 8U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_U4, 9U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Omega, 10U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_Ixx, 11U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Iyy, 12U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Izz, 13U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Jr, 14U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_l, 15U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_g, 16U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_m, 17U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a1, 18U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a2, 19U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a3, 20U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a4, 21U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a5, 22U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_b1, 23U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_b2, 24U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_b3, 25U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_ux, 26U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_uy, 27U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2Fi, 28U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2Teta, 29U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2Psi, 30U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2Z, 31U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2X, 32U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d2Y, 33U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 34U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 35U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_dAlfa, 36U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Alfa, 37U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_U, 38U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_d2Alfa, 39U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_d2Konum, 40U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_dFi = c1_dAlfa[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_dTeta = c1_dAlfa[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_dPsi = c1_dAlfa[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_Fi = c1_Alfa[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_Teta = c1_Alfa[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_Psi = c1_Alfa[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_U1 = c1_U[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_U2 = c1_U[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_U3 = c1_U[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_U4 = c1_U[3];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_Omega = c1_U[4];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_Ixx = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_Iyy = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_Izz = 0.013000000000000001;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  c1_Jr = 6.5E-5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_l = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_m = 0.65;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_a1 = -0.7333333333333335;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_a2 = 0.0086666666666666663;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_a3 = 0.7333333333333335;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_a4 = 0.0086666666666666663;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_a5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_b1 = 30.666666666666668;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_b2 = 30.666666666666668;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
  c1_b3 = 17.69230769230769;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_x = c1_Fi;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_Teta;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_a = c1_b_x;
  c1_b = c1_d_x;
  c1_y = c1_a * c1_b;
  c1_e_x = c1_Psi;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_b_a = c1_y;
  c1_b_b = c1_f_x;
  c1_b_y = c1_b_a * c1_b_b;
  c1_g_x = c1_Fi;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_i_x = c1_Psi;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarSin(c1_j_x);
  c1_c_a = c1_h_x;
  c1_c_b = c1_j_x;
  c1_c_y = c1_c_a * c1_c_b;
  c1_ux = c1_b_y + c1_c_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_k_x = c1_Fi;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarCos(c1_l_x);
  c1_m_x = c1_Teta;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarSin(c1_n_x);
  c1_d_a = c1_l_x;
  c1_d_b = c1_n_x;
  c1_d_y = c1_d_a * c1_d_b;
  c1_o_x = c1_Psi;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarSin(c1_p_x);
  c1_e_a = c1_d_y;
  c1_e_b = c1_p_x;
  c1_e_y = c1_e_a * c1_e_b;
  c1_q_x = c1_Fi;
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarSin(c1_r_x);
  c1_s_x = c1_Psi;
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarCos(c1_t_x);
  c1_f_a = c1_r_x;
  c1_f_b = c1_t_x;
  c1_f_y = c1_f_a * c1_f_b;
  c1_uy = c1_e_y - c1_f_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_g_a = c1_dTeta;
  c1_g_b = c1_dPsi;
  c1_g_y = c1_g_a * c1_g_b;
  c1_h_a = c1_g_y;
  c1_h_y = c1_h_a * -0.7333333333333335;
  c1_i_a = c1_dTeta;
  c1_i_y = c1_i_a * 0.0086666666666666663;
  c1_j_a = c1_i_y;
  c1_h_b = c1_Omega;
  c1_j_y = c1_j_a * c1_h_b;
  c1_i_b = c1_U2;
  c1_k_y = 30.666666666666668 * c1_i_b;
  c1_d2Fi = (c1_h_y + c1_j_y) + c1_k_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  c1_k_a = c1_dFi;
  c1_j_b = c1_dPsi;
  c1_l_y = c1_k_a * c1_j_b;
  c1_l_a = c1_l_y;
  c1_m_y = c1_l_a * 0.7333333333333335;
  c1_m_a = c1_dFi;
  c1_n_y = c1_m_a * 0.0086666666666666663;
  c1_n_a = c1_n_y;
  c1_k_b = c1_Omega;
  c1_o_y = c1_n_a * c1_k_b;
  c1_l_b = c1_U3;
  c1_p_y = 30.666666666666668 * c1_l_b;
  c1_d2Teta = (c1_m_y - c1_o_y) + c1_p_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_o_a = c1_dTeta;
  c1_m_b = c1_dFi;
  c1_q_y = c1_o_a * c1_m_b;
  c1_p_a = c1_q_y;
  c1_r_y = c1_p_a * 0.0;
  c1_n_b = c1_U4;
  c1_s_y = 17.69230769230769 * c1_n_b;
  c1_d2Psi = c1_r_y + c1_s_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
  c1_u_x = c1_Fi;
  c1_v_x = c1_u_x;
  c1_v_x = muDoubleScalarCos(c1_v_x);
  c1_w_x = c1_Teta;
  c1_x_x = c1_w_x;
  c1_x_x = muDoubleScalarCos(c1_x_x);
  c1_q_a = c1_v_x;
  c1_o_b = c1_x_x;
  c1_t_y = c1_q_a * c1_o_b;
  c1_r_a = c1_t_y;
  c1_u_y = c1_r_a * 1.5384615384615383;
  c1_s_a = c1_u_y;
  c1_p_b = c1_U1;
  c1_v_y = c1_s_a * c1_p_b;
  c1_d2Z = c1_g - c1_v_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  c1_t_a = c1_ux;
  c1_w_y = c1_t_a * 1.5384615384615383;
  c1_u_a = c1_w_y;
  c1_q_b = c1_U1;
  c1_d2X = c1_u_a * c1_q_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  c1_v_a = -c1_uy;
  c1_x_y = c1_v_a * 1.5384615384615383;
  c1_w_a = c1_x_y;
  c1_r_b = c1_U1;
  c1_d2Y = c1_w_a * c1_r_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
  c1_d2Alfa[0] = c1_d2Fi;
  c1_d2Alfa[1] = c1_d2Teta;
  c1_d2Alfa[2] = c1_d2Psi;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_d2Konum[0] = c1_d2X;
  c1_d2Konum[1] = c1_d2Y;
  c1_d2Konum[2] = c1_d2Z;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -45);
  sf_debug_symbol_scope_pop();
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    (*c1_b_d2Alfa)[c1_i12] = c1_d2Alfa[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    (*c1_b_d2Konum)[c1_i13] = c1_d2Konum[c1_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_quadPD(SFc1_quadPDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  real_T c1_b_inData[3];
  int32_T c1_i15;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_b_inData[c1_i14] = (*(real_T (*)[3])c1_inData)[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_u[c1_i15] = c1_b_inData[c1_i15];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance, const
  mxArray *c1_d2Konum, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d2Konum), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d2Konum);
}

static void c1_b_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i16;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_y[c1_i16] = c1_dv2[c1_i16];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d2Konum;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i17;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_d2Konum = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d2Konum), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d2Konum);
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    (*(real_T (*)[3])c1_outData)[c1_i17] = c1_y[c1_i17];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i18;
  real_T c1_b_inData[5];
  int32_T c1_i19;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i18 = 0; c1_i18 < 5; c1_i18++) {
    c1_b_inData[c1_i18] = (*(real_T (*)[5])c1_inData)[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 5; c1_i19++) {
    c1_u[c1_i19] = c1_b_inData[c1_i19];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_quadPD_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[14];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i20;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c1_i20 = 0; c1_i20 < 14; c1_i20++) {
    c1_r0 = &c1_info[c1_i20];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i20);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i20);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[14])
{
  c1_info[0].context = "";
  c1_info[0].name = "mpower";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[0].fileTimeLo = 1286815242U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1336518496U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286815196U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1330604834U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[4].fileTimeLo = 1286815142U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[5].name = "eml_scalar_floor";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[5].fileTimeLo = 1286815126U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "mtimes";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].fileTimeLo = 1289516092U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "";
  c1_info[7].name = "mrdivide";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[7].fileTimeLo = 1342807344U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 1319726366U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[8].name = "rdivide";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[8].fileTimeLo = 1286815244U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[9].name = "eml_div";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[9].fileTimeLo = 1313344210U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "";
  c1_info[10].name = "cos";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[10].fileTimeLo = 1286815106U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[11].name = "eml_scalar_cos";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[11].fileTimeLo = 1286815122U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "sin";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[12].fileTimeLo = 1286815150U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[13].name = "eml_scalar_sin";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[13].fileTimeLo = 1286815136U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i21;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i21, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i21;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_quadPD, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_quadPD), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_quadPD);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_quadPDInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_quadPDInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_quadPD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2376662902U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2476772887U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2499057365U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3085346529U);
}

mxArray *sf_c1_quadPD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IMq0rdF9isSrRsJjOSDwDB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[1] = (double)(5);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_quadPD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"d2Alfa\",},{M[1],M[8],T\"d2Konum\",},{M[8],M[0],T\"is_active_c1_quadPD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_quadPD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_quadPDInstanceStruct *chartInstance;
    chartInstance = (SFc1_quadPDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_quadPDMachineNumber_,
          1,
          1,
          1,
          5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dAlfa");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Alfa");
          _SFD_SET_DATA_PROPS(2,2,0,1,"d2Alfa");
          _SFD_SET_DATA_PROPS(3,1,1,0,"U");
          _SFD_SET_DATA_PROPS(4,2,0,1,"d2Konum");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1117);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T (*c1_dAlfa)[3];
          real_T (*c1_Alfa)[3];
          real_T (*c1_d2Alfa)[3];
          real_T (*c1_U)[5];
          real_T (*c1_d2Konum)[3];
          c1_d2Konum = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_U = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 2);
          c1_d2Alfa = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Alfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c1_dAlfa = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_dAlfa);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_Alfa);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_d2Alfa);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_U);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_d2Konum);
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
  return "UsDqs6U2xgUtamKtIEZGxF";
}

static void sf_opaque_initialize_c1_quadPD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_quadPDInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
  initialize_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_quadPD(void *chartInstanceVar)
{
  enable_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_quadPD(void *chartInstanceVar)
{
  disable_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_quadPD(void *chartInstanceVar)
{
  sf_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_quadPD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_quadPD((SFc1_quadPDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_quadPD();/* state var info */
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

extern void sf_internal_set_sim_state_c1_quadPD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_quadPD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_quadPD((SFc1_quadPDInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_quadPD(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_quadPD(S);
}

static void sf_opaque_set_sim_state_c1_quadPD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_quadPD(S, st);
}

static void sf_opaque_terminate_c1_quadPD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_quadPDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_quadPD_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_quadPD((SFc1_quadPDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_quadPD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_quadPD((SFc1_quadPDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quadPD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1373669556U));
  ssSetChecksum1(S,(1891441741U));
  ssSetChecksum2(S,(4185196072U));
  ssSetChecksum3(S,(3147454908U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_quadPD(SimStruct *S)
{
  SFc1_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc1_quadPDInstanceStruct *)malloc(sizeof
    (SFc1_quadPDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_quadPDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_quadPD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_quadPD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_quadPD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_quadPD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_quadPD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_quadPD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_quadPD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_quadPD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_quadPD;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_quadPD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_quadPD;
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

void c1_quadPD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_quadPD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_quadPD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_quadPD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_quadPD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
