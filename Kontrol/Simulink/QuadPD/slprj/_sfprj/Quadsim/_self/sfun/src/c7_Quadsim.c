/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c7_Quadsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[12] = { "arm_l", "craft_m", "b", "d",
  "g", "U", "MM", "MA", "nargin", "nargout", "in", "Uout" };

/* Function Declarations */
static void initialize_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance);
static void enable_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void disable_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_st);
static void finalize_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void sf_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void c7_chartstep_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance, const
  mxArray *c7_Uout, const char_T *c7_identifier, real_T c7_y[5]);
static void c7_b_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[5]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_d_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4]);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_e_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[22]);
static void c7_eml_scalar_eg(SFc7_QuadsimInstanceStruct *chartInstance);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_f_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_g_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_Quadsim, const char_T *c7_identifier);
static uint8_T c7_h_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_Quadsim = 0U;
}

static void initialize_params_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_Quadsim(SFc7_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[5];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T (*c7_Uout)[5];
  c7_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 5; c7_i0++) {
    c7_u[c7_i0] = (*c7_Uout)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_Quadsim;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[5];
  int32_T c7_i1;
  real_T (*c7_Uout)[5];
  c7_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "Uout",
                      c7_dv0);
  for (c7_i1 = 0; c7_i1 < 5; c7_i1++) {
    (*c7_Uout)[c7_i1] = c7_dv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_Quadsim = c7_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 1)), "is_active_c7_Quadsim");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Quadsim(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
  int32_T c7_i2;
  int32_T c7_i3;
  real_T (*c7_Uout)[5];
  real_T (*c7_in)[4];
  c7_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 4; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((*c7_in)[c7_i2], 0U);
  }

  for (c7_i3 = 0; c7_i3 < 5; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*c7_Uout)[c7_i3], 1U);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_Quadsim(chartInstance);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_chartstep_c7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
  int32_T c7_i4;
  real_T c7_in[4];
  uint32_T c7_debug_family_var_map[12];
  real_T c7_arm_l;
  real_T c7_craft_m;
  real_T c7_b;
  real_T c7_d;
  real_T c7_g;
  real_T c7_U[4];
  real_T c7_MM[16];
  real_T c7_MA[4];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_Uout[5];
  int32_T c7_i5;
  int32_T c7_i6;
  static real_T c7_a[16] = { 22123.893805309737, 22123.893805309737,
    22123.893805309737, 22123.893805309737, 0.0, -192381.68526356295, 0.0,
    192381.68526356295, 192381.68526356295, 0.0, -192381.68526356295, 0.0,
    -333333.33333333331, 333333.33333333331, -333333.33333333331,
    333333.33333333331 };

  int32_T c7_i7;
  real_T c7_b_b[4];
  int32_T c7_i8;
  int32_T c7_i9;
  int32_T c7_i10;
  real_T c7_C[4];
  int32_T c7_i11;
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  real_T c7_c_b;
  real_T c7_y;
  real_T c7_d_b;
  real_T c7_b_y;
  real_T c7_e_b;
  real_T c7_c_y;
  real_T c7_f_b;
  real_T c7_d_y;
  real_T c7_x;
  real_T c7_e_y;
  int32_T c7_i18;
  real_T (*c7_b_Uout)[5];
  real_T (*c7_b_in)[4];
  c7_b_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i4 = 0; c7_i4 < 4; c7_i4++) {
    c7_in[c7_i4] = (*c7_b_in)[c7_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c7_arm_l, 0U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_craft_m, 1U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_b, 2U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_d, 3U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_g, 4U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c7_U, 5U, c7_e_sf_marshallOut,
    c7_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c7_MM, 6U, c7_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c7_MA, 7U, c7_b_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 8U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 9U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c7_in, 10U, c7_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c7_Uout, 11U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  c7_arm_l = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_craft_m = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_b = 1.1299999999999999E-5;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_d = 7.5E-7;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i5 = 0; c7_i5 < 4; c7_i5++) {
    c7_U[c7_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_U[0] = c7_in[0];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_U[1] = c7_in[1];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  c7_U[2] = c7_in[2];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  c7_U[3] = c7_in[3];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  for (c7_i6 = 0; c7_i6 < 16; c7_i6++) {
    c7_MM[c7_i6] = c7_a[c7_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
  for (c7_i7 = 0; c7_i7 < 4; c7_i7++) {
    c7_b_b[c7_i7] = c7_U[c7_i7];
  }

  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  for (c7_i8 = 0; c7_i8 < 4; c7_i8++) {
    c7_MA[c7_i8] = 0.0;
  }

  for (c7_i9 = 0; c7_i9 < 4; c7_i9++) {
    c7_MA[c7_i9] = 0.0;
  }

  for (c7_i10 = 0; c7_i10 < 4; c7_i10++) {
    c7_C[c7_i10] = c7_MA[c7_i10];
  }

  for (c7_i11 = 0; c7_i11 < 4; c7_i11++) {
    c7_MA[c7_i11] = c7_C[c7_i11];
  }

  for (c7_i12 = 0; c7_i12 < 4; c7_i12++) {
    c7_C[c7_i12] = c7_MA[c7_i12];
  }

  for (c7_i13 = 0; c7_i13 < 4; c7_i13++) {
    c7_MA[c7_i13] = c7_C[c7_i13];
  }

  for (c7_i14 = 0; c7_i14 < 4; c7_i14++) {
    c7_MA[c7_i14] = 0.0;
    c7_i15 = 0;
    for (c7_i16 = 0; c7_i16 < 4; c7_i16++) {
      c7_MA[c7_i14] += c7_a[c7_i15 + c7_i14] * c7_b_b[c7_i16];
      c7_i15 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
  for (c7_i17 = 0; c7_i17 < 5; c7_i17++) {
    c7_Uout[c7_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
  c7_c_b = ((c7_MA[0] + c7_MA[1]) + c7_MA[2]) + c7_MA[3];
  c7_y = 1.1299999999999999E-5 * c7_c_b;
  c7_Uout[0] = c7_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
  c7_d_b = -c7_MA[1] + c7_MA[3];
  c7_b_y = 1.1299999999999999E-5 * c7_d_b;
  c7_Uout[1] = c7_b_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 26);
  c7_e_b = c7_MA[0] - c7_MA[2];
  c7_c_y = 1.1299999999999999E-5 * c7_e_b;
  c7_Uout[2] = c7_c_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  c7_f_b = ((-c7_MA[0] + c7_MA[1]) - c7_MA[2]) + c7_MA[3];
  c7_d_y = 7.5E-7 * c7_f_b;
  c7_Uout[3] = c7_d_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 28);
  c7_x = (((-c7_MA[0] + c7_MA[1]) - c7_MA[2]) + c7_MA[3]) * c7_d;
  c7_e_y = c7_x;
  c7_Uout[4] = c7_e_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -28);
  sf_debug_symbol_scope_pop();
  for (c7_i18 = 0; c7_i18 < 5; c7_i18++) {
    (*c7_b_Uout)[c7_i18] = c7_Uout[c7_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_Quadsim(SFc7_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i19;
  real_T c7_b_inData[5];
  int32_T c7_i20;
  real_T c7_u[5];
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i19 = 0; c7_i19 < 5; c7_i19++) {
    c7_b_inData[c7_i19] = (*(real_T (*)[5])c7_inData)[c7_i19];
  }

  for (c7_i20 = 0; c7_i20 < 5; c7_i20++) {
    c7_u[c7_i20] = c7_b_inData[c7_i20];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance, const
  mxArray *c7_Uout, const char_T *c7_identifier, real_T c7_y[5])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Uout), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_Uout);
}

static void c7_b_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[5])
{
  real_T c7_dv1[5];
  int32_T c7_i21;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c7_i21 = 0; c7_i21 < 5; c7_i21++) {
    c7_y[c7_i21] = c7_dv1[c7_i21];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Uout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[5];
  int32_T c7_i22;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_Uout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Uout), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_Uout);
  for (c7_i22 = 0; c7_i22 < 5; c7_i22++) {
    (*(real_T (*)[5])c7_outData)[c7_i22] = c7_y[c7_i22];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i23;
  real_T c7_b_inData[4];
  int32_T c7_i24;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i23 = 0; c7_i23 < 4; c7_i23++) {
    c7_b_inData[c7_i23] = (*(real_T (*)[4])c7_inData)[c7_i23];
  }

  for (c7_i24 = 0; c7_i24 < 4; c7_i24++) {
    c7_u[c7_i24] = c7_b_inData[c7_i24];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static void c7_d_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4])
{
  real_T c7_dv2[4];
  int32_T c7_i25;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c7_i25 = 0; c7_i25 < 4; c7_i25++) {
    c7_y[c7_i25] = c7_dv2[c7_i25];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_MA;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[4];
  int32_T c7_i26;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_MA = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_MA), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_MA);
  for (c7_i26 = 0; c7_i26 < 4; c7_i26++) {
    (*(real_T (*)[4])c7_outData)[c7_i26] = c7_y[c7_i26];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  real_T c7_b_inData[16];
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  real_T c7_u[16];
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i27 = 0;
  for (c7_i28 = 0; c7_i28 < 4; c7_i28++) {
    for (c7_i29 = 0; c7_i29 < 4; c7_i29++) {
      c7_b_inData[c7_i29 + c7_i27] = (*(real_T (*)[16])c7_inData)[c7_i29 +
        c7_i27];
    }

    c7_i27 += 4;
  }

  c7_i30 = 0;
  for (c7_i31 = 0; c7_i31 < 4; c7_i31++) {
    for (c7_i32 = 0; c7_i32 < 4; c7_i32++) {
      c7_u[c7_i32 + c7_i30] = c7_b_inData[c7_i32 + c7_i30];
    }

    c7_i30 += 4;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i33;
  real_T c7_b_inData[4];
  int32_T c7_i34;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i33 = 0; c7_i33 < 4; c7_i33++) {
    c7_b_inData[c7_i33] = (*(real_T (*)[4])c7_inData)[c7_i33];
  }

  for (c7_i34 = 0; c7_i34 < 4; c7_i34++) {
    c7_u[c7_i34] = c7_b_inData[c7_i34];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_e_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[4])
{
  real_T c7_dv3[4];
  int32_T c7_i35;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv3, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c7_i35 = 0; c7_i35 < 4; c7_i35++) {
    c7_y[c7_i35] = c7_dv3[c7_i35];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_U;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[4];
  int32_T c7_i36;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_U = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_U), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_U);
  for (c7_i36 = 0; c7_i36 < 4; c7_i36++) {
    (*(real_T (*)[4])c7_outData)[c7_i36] = c7_y[c7_i36];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[22];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i37;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22), FALSE);
  for (c7_i37 = 0; c7_i37 < 22; c7_i37++) {
    c7_r0 = &c7_info[c7_i37];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i37);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i37);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[22])
{
  c7_info[0].context = "";
  c7_info[0].name = "mpower";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[0].fileTimeLo = 1286815242U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[1].name = "power";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[1].fileTimeLo = 1336518496U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[2].name = "eml_scalar_eg";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[2].fileTimeLo = 1286815196U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[3].name = "eml_scalexp_alloc";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[3].fileTimeLo = 1330604834U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[4].name = "floor";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[4].fileTimeLo = 1286815142U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[5].name = "eml_scalar_floor";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c7_info[5].fileTimeLo = 1286815126U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context = "";
  c7_info[6].name = "mtimes";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[6].fileTimeLo = 1289516092U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context = "";
  c7_info[7].name = "mrdivide";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[7].fileTimeLo = 1342807344U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 1319726366U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[8].name = "rdivide";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[8].fileTimeLo = 1286815244U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[9].name = "eml_div";
  c7_info[9].dominantType = "double";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[9].fileTimeLo = 1313344210U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[10].name = "eml_index_class";
  c7_info[10].dominantType = "";
  c7_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[10].fileTimeLo = 1323166978U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[11].name = "eml_scalar_eg";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[11].fileTimeLo = 1286815196U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[12].name = "eml_xgemm";
  c7_info[12].dominantType = "char";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[12].fileTimeLo = 1299073172U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[13].name = "eml_blas_inline";
  c7_info[13].dominantType = "";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[13].fileTimeLo = 1299073168U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
  c7_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c7_info[14].name = "mtimes";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[14].fileTimeLo = 1289516092U;
  c7_info[14].fileTimeHi = 0U;
  c7_info[14].mFileTimeLo = 0U;
  c7_info[14].mFileTimeHi = 0U;
  c7_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[15].name = "eml_index_class";
  c7_info[15].dominantType = "";
  c7_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[15].fileTimeLo = 1323166978U;
  c7_info[15].fileTimeHi = 0U;
  c7_info[15].mFileTimeLo = 0U;
  c7_info[15].mFileTimeHi = 0U;
  c7_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[16].name = "eml_scalar_eg";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[16].fileTimeLo = 1286815196U;
  c7_info[16].fileTimeHi = 0U;
  c7_info[16].mFileTimeLo = 0U;
  c7_info[16].mFileTimeHi = 0U;
  c7_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[17].name = "eml_refblas_xgemm";
  c7_info[17].dominantType = "char";
  c7_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c7_info[17].fileTimeLo = 1299073174U;
  c7_info[17].fileTimeHi = 0U;
  c7_info[17].mFileTimeLo = 0U;
  c7_info[17].mFileTimeHi = 0U;
  c7_info[18].context = "";
  c7_info[18].name = "sum";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[18].fileTimeLo = 1314733012U;
  c7_info[18].fileTimeHi = 0U;
  c7_info[18].mFileTimeLo = 0U;
  c7_info[18].mFileTimeHi = 0U;
  c7_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[19].name = "isequal";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[19].fileTimeLo = 1286815158U;
  c7_info[19].fileTimeHi = 0U;
  c7_info[19].mFileTimeLo = 0U;
  c7_info[19].mFileTimeHi = 0U;
  c7_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c7_info[20].name = "eml_isequal_core";
  c7_info[20].dominantType = "double";
  c7_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c7_info[20].fileTimeLo = 1286815186U;
  c7_info[20].fileTimeHi = 0U;
  c7_info[20].mFileTimeLo = 0U;
  c7_info[20].mFileTimeHi = 0U;
  c7_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c7_info[21].name = "eml_const_nonsingleton_dim";
  c7_info[21].dominantType = "double";
  c7_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[21].fileTimeLo = 1286815096U;
  c7_info[21].fileTimeHi = 0U;
  c7_info[21].mFileTimeLo = 0U;
  c7_info[21].mFileTimeHi = 0U;
}

static void c7_eml_scalar_eg(SFc7_QuadsimInstanceStruct *chartInstance)
{
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_f_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i38;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i38, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i38;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_g_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_Quadsim, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Quadsim), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Quadsim);
  return c7_y;
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_QuadsimInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1732089917U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2018865273U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3425269830U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(467005236U);
}

mxArray *sf_c7_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QwOrCZ2RTDQsxQo4hht7v");
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

static const mxArray *sf_get_sim_state_info_c7_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Uout\",},{M[8],M[0],T\"is_active_c7_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc7_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          7,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,712);
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
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          real_T (*c7_in)[4];
          real_T (*c7_Uout)[5];
          c7_Uout = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_in = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_in);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_Uout);
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
  return "1fcJFXrTHhZI4BAUTGsDWC";
}

static void sf_opaque_initialize_c7_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_Quadsim(void *chartInstanceVar)
{
  enable_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_Quadsim(void *chartInstanceVar)
{
  disable_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_Quadsim(void *chartInstanceVar)
{
  sf_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_Quadsim((SFc7_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c7_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_Quadsim((SFc7_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_Quadsim(S);
}

static void sf_opaque_set_sim_state_c7_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_Quadsim(S, st);
}

static void sf_opaque_terminate_c7_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Quadsim((SFc7_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Quadsim((SFc7_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1312732308U));
  ssSetChecksum1(S,(945631337U));
  ssSetChecksum2(S,(3427223315U));
  ssSetChecksum3(S,(112394976U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Quadsim(SimStruct *S)
{
  SFc7_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc7_QuadsimInstanceStruct *)malloc(sizeof
    (SFc7_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_Quadsim;
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

void c7_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
