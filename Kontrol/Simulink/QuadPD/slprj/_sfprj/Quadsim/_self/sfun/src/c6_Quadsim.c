/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c6_Quadsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[13] = { "arm_l", "craft_m", "b", "d",
  "g", "U", "MM", "MA", "Omd", "nargin", "nargout", "in", "out" };

/* Function Declarations */
static void initialize_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance);
static void enable_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void disable_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void sf_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void c6_chartstep_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance, const
  mxArray *c6_out, const char_T *c6_identifier, real_T c6_y[4]);
static void c6_b_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_d_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[23]);
static void c6_eml_scalar_eg(SFc6_QuadsimInstanceStruct *chartInstance);
static void c6_eml_error(SFc6_QuadsimInstanceStruct *chartInstance);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Quadsim, const char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_Quadsim = 0U;
}

static void initialize_params_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_Quadsim(SFc6_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[4];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_out)[4];
  c6_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_u[c6_i0] = (*c6_out)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Quadsim;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[4];
  int32_T c6_i1;
  real_T (*c6_out)[4];
  c6_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "out",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    (*c6_out)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_Quadsim = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)), "is_active_c6_Quadsim");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Quadsim(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  real_T (*c6_out)[4];
  real_T (*c6_in)[4];
  c6_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_in)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 4; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_out)[c6_i3], 1U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_Quadsim(chartInstance);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
  int32_T c6_i4;
  real_T c6_in[4];
  uint32_T c6_debug_family_var_map[13];
  real_T c6_arm_l;
  real_T c6_craft_m;
  real_T c6_b;
  real_T c6_d;
  real_T c6_g;
  real_T c6_U[4];
  real_T c6_MM[16];
  real_T c6_MA[4];
  real_T c6_Omd[4];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_out[4];
  int32_T c6_i5;
  int32_T c6_i6;
  static real_T c6_a[16] = { 22123.893805309737, 22123.893805309737,
    22123.893805309737, 22123.893805309737, 0.0, -192381.68526356295, 0.0,
    192381.68526356295, 192381.68526356295, 0.0, -192381.68526356295, 0.0,
    -333333.33333333331, 333333.33333333331, -333333.33333333331,
    333333.33333333331 };

  int32_T c6_i7;
  real_T c6_b_b[4];
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  real_T c6_C[4];
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_k;
  real_T c6_b_k;
  real_T c6_x;
  real_T c6_y;
  int32_T c6_i18;
  int32_T c6_c_k;
  real_T c6_d_k;
  int32_T c6_e_k;
  real_T c6_b_x;
  real_T c6_c_x;
  int32_T c6_i19;
  int32_T c6_i20;
  real_T (*c6_b_out)[4];
  real_T (*c6_b_in)[4];
  c6_b_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    c6_in[c6_i4] = (*c6_b_in)[c6_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_arm_l, 0U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_craft_m, 1U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_b, 2U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_d, 3U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_g, 4U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_U, 5U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_MM, 6U, c6_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_MA, 7U, c6_b_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_Omd, 8U, c6_b_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 9U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 10U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_in, 11U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_out, 12U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_arm_l = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_craft_m = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_b = 1.1299999999999999E-5;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_d = 7.5E-7;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i5 = 0; c6_i5 < 4; c6_i5++) {
    c6_U[c6_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_U[0] = 9.3195;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_U[1] = c6_in[1];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_U[2] = c6_in[2];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_U[3] = c6_in[3];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  for (c6_i6 = 0; c6_i6 < 16; c6_i6++) {
    c6_MM[c6_i6] = c6_a[c6_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 20);
  for (c6_i7 = 0; c6_i7 < 4; c6_i7++) {
    c6_b_b[c6_i7] = c6_U[c6_i7];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
    c6_MA[c6_i8] = 0.0;
  }

  for (c6_i9 = 0; c6_i9 < 4; c6_i9++) {
    c6_MA[c6_i9] = 0.0;
  }

  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_C[c6_i10] = c6_MA[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 4; c6_i11++) {
    c6_MA[c6_i11] = c6_C[c6_i11];
  }

  for (c6_i12 = 0; c6_i12 < 4; c6_i12++) {
    c6_C[c6_i12] = c6_MA[c6_i12];
  }

  for (c6_i13 = 0; c6_i13 < 4; c6_i13++) {
    c6_MA[c6_i13] = c6_C[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 4; c6_i14++) {
    c6_MA[c6_i14] = 0.0;
    c6_i15 = 0;
    for (c6_i16 = 0; c6_i16 < 4; c6_i16++) {
      c6_MA[c6_i14] += c6_a[c6_i15 + c6_i14] * c6_b_b[c6_i16];
      c6_i15 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  for (c6_i17 = 0; c6_i17 < 4; c6_i17++) {
    c6_b_b[c6_i17] = c6_MA[c6_i17];
  }

  for (c6_k = 0; c6_k < 4; c6_k++) {
    c6_b_k = 1.0 + (real_T)c6_k;
    c6_x = c6_b_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 4, 1, 0) - 1];
    c6_y = muDoubleScalarAbs(c6_x);
    c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
      1, 4, 1, 0) - 1] = c6_y;
  }

  for (c6_i18 = 0; c6_i18 < 4; c6_i18++) {
    c6_Omd[c6_i18] = c6_C[c6_i18];
  }

  for (c6_c_k = 0; c6_c_k < 4; c6_c_k++) {
    c6_d_k = 1.0 + (real_T)c6_c_k;
    if (c6_Omd[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c6_d_k), 1, 4, 1, 0) - 1] < 0.0) {
      c6_eml_error(chartInstance);
    }
  }

  for (c6_e_k = 0; c6_e_k < 4; c6_e_k++) {
    c6_d_k = 1.0 + (real_T)c6_e_k;
    c6_b_x = c6_Omd[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c6_d_k), 1, 4, 1, 0) - 1];
    c6_c_x = c6_b_x;
    c6_c_x = muDoubleScalarSqrt(c6_c_x);
    c6_Omd[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_d_k), 1, 4, 1, 0) - 1] = c6_c_x;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
    c6_out[c6_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  c6_out[0] = c6_Omd[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
  c6_out[1] = c6_Omd[1];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  c6_out[2] = c6_Omd[2];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
  c6_out[3] = c6_Omd[3];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -28);
  sf_debug_symbol_scope_pop();
  for (c6_i20 = 0; c6_i20 < 4; c6_i20++) {
    (*c6_b_out)[c6_i20] = c6_out[c6_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_Quadsim(SFc6_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i21;
  real_T c6_b_inData[4];
  int32_T c6_i22;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i21 = 0; c6_i21 < 4; c6_i21++) {
    c6_b_inData[c6_i21] = (*(real_T (*)[4])c6_inData)[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 4; c6_i22++) {
    c6_u[c6_i22] = c6_b_inData[c6_i22];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance, const
  mxArray *c6_out, const char_T *c6_identifier, real_T c6_y[4])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_out), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_out);
}

static void c6_b_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4])
{
  real_T c6_dv1[4];
  int32_T c6_i23;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c6_i23 = 0; c6_i23 < 4; c6_i23++) {
    c6_y[c6_i23] = c6_dv1[c6_i23];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_out;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i24;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_out = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_out), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_out);
  for (c6_i24 = 0; c6_i24 < 4; c6_i24++) {
    (*(real_T (*)[4])c6_outData)[c6_i24] = c6_y[c6_i24];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i25;
  real_T c6_b_inData[4];
  int32_T c6_i26;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i25 = 0; c6_i25 < 4; c6_i25++) {
    c6_b_inData[c6_i25] = (*(real_T (*)[4])c6_inData)[c6_i25];
  }

  for (c6_i26 = 0; c6_i26 < 4; c6_i26++) {
    c6_u[c6_i26] = c6_b_inData[c6_i26];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_d_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4])
{
  real_T c6_dv2[4];
  int32_T c6_i27;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c6_i27 = 0; c6_i27 < 4; c6_i27++) {
    c6_y[c6_i27] = c6_dv2[c6_i27];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Omd;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i28;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_Omd = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Omd), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Omd);
  for (c6_i28 = 0; c6_i28 < 4; c6_i28++) {
    (*(real_T (*)[4])c6_outData)[c6_i28] = c6_y[c6_i28];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_b_inData[16];
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  real_T c6_u[16];
  const mxArray *c6_y = NULL;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i29 = 0;
  for (c6_i30 = 0; c6_i30 < 4; c6_i30++) {
    for (c6_i31 = 0; c6_i31 < 4; c6_i31++) {
      c6_b_inData[c6_i31 + c6_i29] = (*(real_T (*)[16])c6_inData)[c6_i31 +
        c6_i29];
    }

    c6_i29 += 4;
  }

  c6_i32 = 0;
  for (c6_i33 = 0; c6_i33 < 4; c6_i33++) {
    for (c6_i34 = 0; c6_i34 < 4; c6_i34++) {
      c6_u[c6_i34 + c6_i32] = c6_b_inData[c6_i34 + c6_i32];
    }

    c6_i32 += 4;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

const mxArray *sf_c6_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[23];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i35;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c6_i35 = 0; c6_i35 < 23; c6_i35++) {
    c6_r0 = &c6_info[c6_i35];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i35);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i35);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[23])
{
  c6_info[0].context = "";
  c6_info[0].name = "mpower";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[0].fileTimeLo = 1286815242U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[1].name = "power";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[1].fileTimeLo = 1336518496U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[2].name = "eml_scalar_eg";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[2].fileTimeLo = 1286815196U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[3].name = "eml_scalexp_alloc";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[3].fileTimeLo = 1330604834U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[4].name = "floor";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[4].fileTimeLo = 1286815142U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[5].name = "eml_scalar_floor";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[5].fileTimeLo = 1286815126U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context = "";
  c6_info[6].name = "mtimes";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[6].fileTimeLo = 1289516092U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context = "";
  c6_info[7].name = "mrdivide";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[7].fileTimeLo = 1342807344U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 1319726366U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[8].name = "rdivide";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[8].fileTimeLo = 1286815244U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[9].name = "eml_div";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[9].fileTimeLo = 1313344210U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[10].name = "eml_index_class";
  c6_info[10].dominantType = "";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[10].fileTimeLo = 1323166978U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[11].name = "eml_scalar_eg";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[11].fileTimeLo = 1286815196U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[12].name = "eml_xgemm";
  c6_info[12].dominantType = "char";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[12].fileTimeLo = 1299073172U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[13].name = "eml_blas_inline";
  c6_info[13].dominantType = "";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[13].fileTimeLo = 1299073168U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[14].name = "mtimes";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[14].fileTimeLo = 1289516092U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[15].name = "eml_index_class";
  c6_info[15].dominantType = "";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[15].fileTimeLo = 1323166978U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[16].name = "eml_scalar_eg";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[16].fileTimeLo = 1286815196U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[17].name = "eml_refblas_xgemm";
  c6_info[17].dominantType = "char";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[17].fileTimeLo = 1299073174U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context = "";
  c6_info[18].name = "abs";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[18].fileTimeLo = 1286815094U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[19].name = "eml_scalar_abs";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[19].fileTimeLo = 1286815112U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context = "";
  c6_info[20].name = "sqrt";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[20].fileTimeLo = 1286815152U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[21].name = "eml_error";
  c6_info[21].dominantType = "char";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[21].fileTimeLo = 1305314400U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[22].name = "eml_scalar_sqrt";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c6_info[22].fileTimeLo = 1286815138U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_QuadsimInstanceStruct *chartInstance)
{
}

static void c6_eml_error(SFc6_QuadsimInstanceStruct *chartInstance)
{
  int32_T c6_i36;
  static char_T c6_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  for (c6_i36 = 0; c6_i36 < 30; c6_i36++) {
    c6_u[c6_i36] = c6_varargin_1[c6_i36];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i37;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i37, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i37;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Quadsim, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Quadsim), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Quadsim);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_QuadsimInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3832458382U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3521894081U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3843688816U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4248812389U);
}

mxArray *sf_c6_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8kfQGs2wsaLP1C7hWfFWBD");
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
      pr[1] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c6_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c6_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc6_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          6,
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
          init_script_number_translation(_QuadsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_QuadsimMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QuadsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"out");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,611);
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
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          real_T (*c6_in)[4];
          real_T (*c6_out)[4];
          c6_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_in);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_out);
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
  return "UcbywWibZQ21EyDZpUJl3C";
}

static void sf_opaque_initialize_c6_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_Quadsim(void *chartInstanceVar)
{
  enable_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Quadsim(void *chartInstanceVar)
{
  disable_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Quadsim(void *chartInstanceVar)
{
  sf_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Quadsim((SFc6_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c6_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Quadsim((SFc6_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_Quadsim(S);
}

static void sf_opaque_set_sim_state_c6_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_Quadsim(S, st);
}

static void sf_opaque_terminate_c6_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Quadsim((SFc6_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Quadsim((SFc6_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2185646500U));
  ssSetChecksum1(S,(3227936860U));
  ssSetChecksum2(S,(4069766520U));
  ssSetChecksum3(S,(2450719327U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Quadsim(SimStruct *S)
{
  SFc6_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc6_QuadsimInstanceStruct *)malloc(sizeof
    (SFc6_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_Quadsim;
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

void c6_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
