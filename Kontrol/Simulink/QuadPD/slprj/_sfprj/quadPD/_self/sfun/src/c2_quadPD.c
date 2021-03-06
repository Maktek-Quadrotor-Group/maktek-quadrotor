/* Include files */

#include "blascompat32.h"
#include "quadPD_sfun.h"
#include "c2_quadPD.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quadPD_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[26] = { "U1", "U2", "U3", "U4", "Ix",
  "Iy", "Iz", "Jr", "b", "d", "l", "m", "g", "U", "M", "OM_2h", "OM_2", "U1_2",
  "U2_2", "U3_2", "U4_2", "Omega", "nargin", "nargout", "Uin", "Uout" };

/* Function Declarations */
static void initialize_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void initialize_params_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void enable_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void disable_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_quadPD(SFc2_quadPDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_quadPD(SFc2_quadPDInstanceStruct
  *chartInstance);
static void set_sim_state_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void sf_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void c2_chartstep_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void initSimStructsc2_quadPD(SFc2_quadPDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance, const
  mxArray *c2_Uout, const char_T *c2_identifier, real_T c2_y[5]);
static void c2_b_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[5]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_e_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static void c2_eml_scalar_eg(SFc2_quadPDInstanceStruct *chartInstance);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_quadPD, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_quadPDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_quadPD = 0U;
}

static void initialize_params_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
}

static void enable_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_quadPD(SFc2_quadPDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_quadPD(SFc2_quadPDInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[5];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_Uout)[5];
  c2_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 5; c2_i0++) {
    c2_u[c2_i0] = (*c2_Uout)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_quadPD;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[5];
  int32_T c2_i1;
  real_T (*c2_Uout)[5];
  c2_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "Uout",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 5; c2_i1++) {
    (*c2_Uout)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_quadPD = c2_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_quadPD");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_quadPD(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
}

static void sf_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T (*c2_Uout)[5];
  real_T (*c2_Uin)[4];
  c2_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_Uin = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_Uin)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 5; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_Uout)[c2_i3], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_quadPD(chartInstance);
  sf_debug_check_for_state_inconsistency(_quadPDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  real_T c2_Uin[4];
  uint32_T c2_debug_family_var_map[26];
  real_T c2_U1;
  real_T c2_U2;
  real_T c2_U3;
  real_T c2_U4;
  real_T c2_Ix;
  real_T c2_Iy;
  real_T c2_Iz;
  real_T c2_Jr;
  real_T c2_b;
  real_T c2_d;
  real_T c2_l;
  real_T c2_m;
  real_T c2_g;
  real_T c2_U[4];
  real_T c2_M[16];
  real_T c2_OM_2h[4];
  real_T c2_OM_2[4];
  real_T c2_U1_2;
  real_T c2_U2_2;
  real_T c2_U3_2;
  real_T c2_U4_2;
  real_T c2_Omega;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_Uout[5];
  int32_T c2_i5;
  static real_T c2_a[16] = { 7987.2204472843459, 7987.2204472843459,
    7987.2204472843459, 7987.2204472843459, 0.0, -69454.090845950836, 0.0,
    69454.090845950836, 69454.090845950836, 0.0, -69454.090845950836, 0.0,
    -333333.33333333331, 333333.33333333331, -333333.33333333331,
    333333.33333333331 };

  int32_T c2_i6;
  real_T c2_b_b[4];
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  real_T c2_C[4];
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  real_T c2_c_b;
  real_T c2_d_b;
  real_T c2_e_b;
  real_T c2_f_b;
  real_T c2_g_b;
  int32_T c2_i17;
  real_T (*c2_b_Uout)[5];
  real_T (*c2_b_Uin)[4];
  c2_b_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Uin = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    c2_Uin[c2_i4] = (*c2_b_Uin)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 26U, 26U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_U1, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U2, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U3, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U4, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Ix, 4U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Iy, 5U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Iz, 6U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Jr, 7U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_b, 8U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_d, 9U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_l, 10U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_m, 11U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_g, 12U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_U, 13U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_M, 14U, c2_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_OM_2h, 15U, c2_b_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_OM_2, 16U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U1_2, 17U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U2_2, 18U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U3_2, 19U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_U4_2, 20U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Omega, 21U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 22U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 23U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_Uin, 24U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_Uout, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_U1 = c2_Uin[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_U2 = c2_Uin[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_U3 = c2_Uin[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_U4 = c2_Uin[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_Ix = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_Iy = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_Iz = 0.013000000000000001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_Jr = 6.5E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_b = 3.1299999999999995E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_d = 7.5E-7;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_l = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_m = 0.65;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_U[0] = c2_U1;
  c2_U[1] = c2_U2;
  c2_U[2] = c2_U3;
  c2_U[3] = c2_U4;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  for (c2_i5 = 0; c2_i5 < 16; c2_i5++) {
    c2_M[c2_i5] = c2_a[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_b_b[c2_i6] = c2_U[c2_i6];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_OM_2h[c2_i7] = 0.0;
  }

  for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
    c2_OM_2h[c2_i8] = 0.0;
  }

  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_C[c2_i9] = c2_OM_2h[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_OM_2h[c2_i10] = c2_C[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_C[c2_i11] = c2_OM_2h[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_OM_2h[c2_i12] = c2_C[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_OM_2h[c2_i13] = 0.0;
    c2_i14 = 0;
    for (c2_i15 = 0; c2_i15 < 4; c2_i15++) {
      c2_OM_2h[c2_i13] += c2_a[c2_i14 + c2_i13] * c2_b_b[c2_i15];
      c2_i14 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    c2_OM_2[c2_i16] = c2_OM_2h[c2_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_c_b = ((c2_OM_2[0] + c2_OM_2[1]) + c2_OM_2[2]) + c2_OM_2[3];
  c2_U1_2 = 3.1299999999999995E-5 * c2_c_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_d_b = -c2_OM_2[1] + c2_OM_2[3];
  c2_U2_2 = 3.1299999999999995E-5 * c2_d_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_e_b = c2_OM_2[0] - c2_OM_2[2];
  c2_U3_2 = 3.1299999999999995E-5 * c2_e_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_f_b = ((-c2_OM_2[0] + c2_OM_2[1]) - c2_OM_2[2]) + c2_OM_2[3];
  c2_U4_2 = 7.5E-7 * c2_f_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_g_b = ((-c2_OM_2[0] + c2_OM_2[1]) - c2_OM_2[2]) + c2_OM_2[3];
  c2_Omega = 7.5E-7 * c2_g_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_Uout[0] = c2_U1_2;
  c2_Uout[1] = c2_U2_2;
  c2_Uout[2] = c2_U3_2;
  c2_Uout[3] = c2_U4_2;
  c2_Uout[4] = c2_Omega;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -35);
  sf_debug_symbol_scope_pop();
  for (c2_i17 = 0; c2_i17 < 5; c2_i17++) {
    (*c2_b_Uout)[c2_i17] = c2_Uout[c2_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_quadPD(SFc2_quadPDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i18;
  real_T c2_b_inData[5];
  int32_T c2_i19;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i18 = 0; c2_i18 < 5; c2_i18++) {
    c2_b_inData[c2_i18] = (*(real_T (*)[5])c2_inData)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 5; c2_i19++) {
    c2_u[c2_i19] = c2_b_inData[c2_i19];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance, const
  mxArray *c2_Uout, const char_T *c2_identifier, real_T c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Uout), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Uout);
}

static void c2_b_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[5])
{
  real_T c2_dv1[5];
  int32_T c2_i20;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c2_i20 = 0; c2_i20 < 5; c2_i20++) {
    c2_y[c2_i20] = c2_dv1[c2_i20];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Uout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i21;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_Uout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Uout), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Uout);
  for (c2_i21 = 0; c2_i21 < 5; c2_i21++) {
    (*(real_T (*)[5])c2_outData)[c2_i21] = c2_y[c2_i21];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i22;
  real_T c2_b_inData[4];
  int32_T c2_i23;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i22 = 0; c2_i22 < 4; c2_i22++) {
    c2_b_inData[c2_i22] = (*(real_T (*)[4])c2_inData)[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 4; c2_i23++) {
    c2_u[c2_i23] = c2_b_inData[c2_i23];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i24;
  real_T c2_b_inData[4];
  int32_T c2_i25;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    c2_b_inData[c2_i24] = (*(real_T (*)[4])c2_inData)[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
    c2_u[c2_i25] = c2_b_inData[c2_i25];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv2[4];
  int32_T c2_i26;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
    c2_y[c2_i26] = c2_dv2[c2_i26];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_OM_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i27;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_OM_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_OM_2), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_OM_2);
  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    (*(real_T (*)[4])c2_outData)[c2_i27] = c2_y[c2_i27];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_e_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv3[4];
  int32_T c2_i28;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i28 = 0; c2_i28 < 4; c2_i28++) {
    c2_y[c2_i28] = c2_dv3[c2_i28];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_OM_2h;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i29;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_OM_2h = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_OM_2h), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_OM_2h);
  for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
    (*(real_T (*)[4])c2_outData)[c2_i29] = c2_y[c2_i29];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T c2_b_inData[16];
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
    for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
      c2_b_inData[c2_i32 + c2_i30] = (*(real_T (*)[16])c2_inData)[c2_i32 +
        c2_i30];
    }

    c2_i30 += 4;
  }

  c2_i33 = 0;
  for (c2_i34 = 0; c2_i34 < 4; c2_i34++) {
    for (c2_i35 = 0; c2_i35 < 4; c2_i35++) {
      c2_u[c2_i35 + c2_i33] = c2_b_inData[c2_i35 + c2_i33];
    }

    c2_i33 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_quadPD_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i36;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c2_i36 = 0; c2_i36 < 18; c2_i36++) {
    c2_r0 = &c2_info[c2_i36];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i36);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i36);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "mpower";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].fileTimeLo = 1286815242U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 1336518496U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 1286815196U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 1330604834U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[4].name = "floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[4].fileTimeLo = 1286815142U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].name = "eml_scalar_floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[5].fileTimeLo = 1286815126U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileTimeLo = 1289516092U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "mrdivide";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[7].fileTimeLo = 1342807344U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 1319726366U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[8].name = "rdivide";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].fileTimeLo = 1286815244U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "eml_div";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[9].fileTimeLo = 1313344210U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "eml_index_class";
  c2_info[10].dominantType = "";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[10].fileTimeLo = 1323166978U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "eml_scalar_eg";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[11].fileTimeLo = 1286815196U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].name = "eml_xgemm";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[12].fileTimeLo = 1299073172U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[13].name = "eml_blas_inline";
  c2_info[13].dominantType = "";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[13].fileTimeLo = 1299073168U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[14].name = "mtimes";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].fileTimeLo = 1289516092U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[15].name = "eml_index_class";
  c2_info[15].dominantType = "";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[15].fileTimeLo = 1323166978U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileTimeLo = 1286815196U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[17].name = "eml_refblas_xgemm";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[17].fileTimeLo = 1299073174U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_quadPDInstanceStruct *chartInstance)
{
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i37;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i37, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i37;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_quadPD, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_quadPD), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_quadPD);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_quadPDInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_quadPDInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_quadPD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2329745586U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(348000375U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2230493608U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(900401540U);
}

mxArray *sf_c2_quadPD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jWo57ZHUopjlbC7wqAM1RE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_quadPD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[11],T\"Uout\",},{M[8],M[0],T\"is_active_c2_quadPD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_quadPD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_quadPDInstanceStruct *chartInstance;
    chartInstance = (SFc2_quadPDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_quadPDMachineNumber_,
          2,
          1,
          1,
          2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Uin");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Uout");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,761);
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
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_Uin)[4];
          real_T (*c2_Uout)[5];
          c2_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Uin = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Uin);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_Uout);
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
  return "nIcdyGfO33y9PyzE5Hr84B";
}

static void sf_opaque_initialize_c2_quadPD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_quadPDInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
  initialize_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_quadPD(void *chartInstanceVar)
{
  enable_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_quadPD(void *chartInstanceVar)
{
  disable_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_quadPD(void *chartInstanceVar)
{
  sf_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_quadPD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_quadPD((SFc2_quadPDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_quadPD();/* state var info */
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

extern void sf_internal_set_sim_state_c2_quadPD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_quadPD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_quadPD((SFc2_quadPDInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_quadPD(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_quadPD(S);
}

static void sf_opaque_set_sim_state_c2_quadPD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_quadPD(S, st);
}

static void sf_opaque_terminate_c2_quadPD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_quadPDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_quadPD_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_quadPD((SFc2_quadPDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_quadPD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_quadPD((SFc2_quadPDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quadPD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3982110355U));
  ssSetChecksum1(S,(787689932U));
  ssSetChecksum2(S,(1113638002U));
  ssSetChecksum3(S,(797800189U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_quadPD(SimStruct *S)
{
  SFc2_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc2_quadPDInstanceStruct *)malloc(sizeof
    (SFc2_quadPDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_quadPDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_quadPD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_quadPD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_quadPD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_quadPD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_quadPD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_quadPD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_quadPD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_quadPD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_quadPD;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_quadPD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_quadPD;
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

void c2_quadPD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_quadPD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_quadPD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_quadPD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_quadPD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
