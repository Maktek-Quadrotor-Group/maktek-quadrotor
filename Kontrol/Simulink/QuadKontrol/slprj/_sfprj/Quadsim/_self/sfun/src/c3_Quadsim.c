/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c3_Quadsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[14] = { "altitude_set", "z_dot", "z",
  "altitude_p", "altitude_i", "altitude_d", "altitude_error", "altitude_d_error",
  "altitude_return", "altitude_last_out", "nargin", "nargout", "alt_in",
  "alt_out" };

/* Function Declarations */
static void initialize_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance);
static void enable_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void disable_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void sf_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_alt_out, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Quadsim, const char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_Quadsim = 0U;
}

static void initialize_params_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_Quadsim(SFc3_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_alt_out;
  c3_alt_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_alt_out;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_Quadsim;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_alt_out;
  c3_alt_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_alt_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "alt_out");
  chartInstance->c3_is_active_c3_Quadsim = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_Quadsim");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Quadsim(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  real_T c3_alt_in[13];
  uint32_T c3_debug_family_var_map[14];
  real_T c3_altitude_set;
  real_T c3_z_dot;
  real_T c3_z;
  real_T c3_altitude_p;
  real_T c3_altitude_i;
  real_T c3_altitude_d;
  real_T c3_altitude_error;
  real_T c3_altitude_d_error;
  real_T c3_altitude_return;
  real_T c3_altitude_last_out;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_alt_out;
  real_T c3_b;
  real_T c3_y;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T *c3_b_alt_out;
  real_T (*c3_b_alt_in)[13];
  c3_b_alt_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_alt_in = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i0 = 0; c3_i0 < 13; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_alt_in)[c3_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_alt_out, 1U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 13; c3_i1++) {
    c3_alt_in[c3_i1] = (*c3_b_alt_in)[c3_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_set, 0U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_z_dot, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_z, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_altitude_p, 3U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_i, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_altitude_d, 5U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_error, 6U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_d_error, 7U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_return, 8U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_altitude_last_out, 9U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_alt_in, 12U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_alt_out, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_altitude_set = c3_alt_in[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_z_dot = c3_alt_in[3];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_z = c3_alt_in[9];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_altitude_p = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_altitude_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_altitude_d = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_altitude_error = c3_altitude_set - c3_z;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_altitude_d_error = c3_z_dot;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_b = c3_altitude_error;
  c3_y = 3.0 * c3_b;
  c3_b_b = c3_altitude_d_error;
  c3_b_y = 0.2 * c3_b_b;
  c3_altitude_return = c3_y - c3_b_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_altitude_last_out = c3_z;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_alt_out = c3_altitude_return;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -32);
  sf_debug_symbol_scope_pop();
  *c3_b_alt_out = c3_alt_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_Quadsim(SFc3_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_alt_out, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_alt_out), &c3_thisId);
  sf_mex_destroy(&c3_alt_out);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_alt_out;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)chartInstanceVoid;
  c3_alt_out = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_alt_out), &c3_thisId);
  sf_mex_destroy(&c3_alt_out);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i2;
  real_T c3_b_inData[13];
  int32_T c3_i3;
  real_T c3_u[13];
  const mxArray *c3_y = NULL;
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i2 = 0; c3_i2 < 13; c3_i2++) {
    c3_b_inData[c3_i2] = (*(real_T (*)[13])c3_inData)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 13; c3_i3++) {
    c3_u[c3_i3] = c3_b_inData[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 13), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[1];
  c3_ResolvedFunctionInfo (*c3_b_info)[1];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i4;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[1])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 1289516092U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c3_i4 = 0; c3_i4 < 1; c3_i4++) {
    c3_r0 = &c3_info[c3_i4];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i4);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i4);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i5, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Quadsim, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Quadsim), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Quadsim);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_QuadsimInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1263220506U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1200266457U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3064905722U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1226113190U);
}

mxArray *sf_c3_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gjDlIWyNZ4uIfdrepNVpUB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"alt_out\",},{M[8],M[0],T\"is_active_c3_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc3_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"alt_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"alt_out");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,727);
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
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_alt_out;
          real_T (*c3_alt_in)[13];
          c3_alt_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_alt_in = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_alt_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_alt_out);
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
  return "QyszokO1S9uw7BHK2hNkc";
}

static void sf_opaque_initialize_c3_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Quadsim(void *chartInstanceVar)
{
  enable_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Quadsim(void *chartInstanceVar)
{
  disable_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Quadsim(void *chartInstanceVar)
{
  sf_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Quadsim((SFc3_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c3_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Quadsim((SFc3_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Quadsim(S);
}

static void sf_opaque_set_sim_state_c3_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_Quadsim(S, st);
}

static void sf_opaque_terminate_c3_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Quadsim((SFc3_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Quadsim((SFc3_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1028637508U));
  ssSetChecksum1(S,(4046633382U));
  ssSetChecksum2(S,(1010587472U));
  ssSetChecksum3(S,(1331758976U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Quadsim(SimStruct *S)
{
  SFc3_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc3_QuadsimInstanceStruct *)malloc(sizeof
    (SFc3_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Quadsim;
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

void c3_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
