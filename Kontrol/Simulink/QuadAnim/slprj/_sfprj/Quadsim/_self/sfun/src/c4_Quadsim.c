/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c4_Quadsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[20] = { "dey", "dex", "y_p", "y_i",
  "y_d", "x_p", "x_i", "x_d", "nargin", "nargout", "y_hedef", "y", "ydot",
  "x_hedef", "x", "xdot", "kontrol_roll", "kontrol_pitch", "ex", "ey" };

/* Function Declarations */
static void initialize_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance);
static void enable_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void disable_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void sf_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_ey, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Quadsim, const char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Quadsim = 0U;
}

static void initialize_params_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Quadsim(SFc4_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_ex;
  real_T *c4_ey;
  real_T *c4_kontrol_pitch;
  real_T *c4_kontrol_roll;
  c4_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_kontrol_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_kontrol_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  c4_hoistedGlobal = *c4_ex;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_ey;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_kontrol_pitch;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_kontrol_roll;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_active_c4_Quadsim;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_ex;
  real_T *c4_ey;
  real_T *c4_kontrol_pitch;
  real_T *c4_kontrol_roll;
  c4_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_kontrol_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_kontrol_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_ex = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "ex");
  *c4_ey = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "ey");
  *c4_kontrol_pitch = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "kontrol_pitch");
  *c4_kontrol_roll = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "kontrol_roll");
  chartInstance->c4_is_active_c4_Quadsim = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "is_active_c4_Quadsim");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Quadsim(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_y_hedef;
  real_T c4_y;
  real_T c4_ydot;
  real_T c4_x_hedef;
  real_T c4_x;
  real_T c4_xdot;
  uint32_T c4_debug_family_var_map[20];
  real_T c4_dey;
  real_T c4_dex;
  real_T c4_y_p;
  real_T c4_y_i;
  real_T c4_y_d;
  real_T c4_x_p;
  real_T c4_x_i;
  real_T c4_x_d;
  real_T c4_nargin = 6.0;
  real_T c4_nargout = 4.0;
  real_T c4_kontrol_roll;
  real_T c4_kontrol_pitch;
  real_T c4_ex;
  real_T c4_ey;
  real_T c4_b;
  real_T c4_b_y;
  real_T c4_b_b;
  real_T c4_c_y;
  real_T c4_c_b;
  real_T c4_d_y;
  real_T c4_d_b;
  real_T c4_e_y;
  real_T *c4_b_y_hedef;
  real_T *c4_f_y;
  real_T *c4_b_kontrol_roll;
  real_T *c4_b_ydot;
  real_T *c4_b_x_hedef;
  real_T *c4_b_x;
  real_T *c4_b_xdot;
  real_T *c4_b_kontrol_pitch;
  real_T *c4_b_ex;
  real_T *c4_b_ey;
  c4_b_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_kontrol_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_xdot = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_x_hedef = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_ydot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_kontrol_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_f_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_y_hedef = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_y_hedef, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_f_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_kontrol_roll, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ydot, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_x_hedef, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_x, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_b_xdot, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_b_kontrol_pitch, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ex, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ey, 9U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_y_hedef;
  c4_b_hoistedGlobal = *c4_f_y;
  c4_c_hoistedGlobal = *c4_b_ydot;
  c4_d_hoistedGlobal = *c4_b_x_hedef;
  c4_e_hoistedGlobal = *c4_b_x;
  c4_f_hoistedGlobal = *c4_b_xdot;
  c4_y_hedef = c4_hoistedGlobal;
  c4_y = c4_b_hoistedGlobal;
  c4_ydot = c4_c_hoistedGlobal;
  c4_x_hedef = c4_d_hoistedGlobal;
  c4_x = c4_e_hoistedGlobal;
  c4_xdot = c4_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_dey, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_dex, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_y_p, 2U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_y_i, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_y_d, 4U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_x_p, 5U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_x_i, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_x_d, 7U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_y_hedef, 10U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_y, 11U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_ydot, 12U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_x_hedef, 13U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_x, 14U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_xdot, 15U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_kontrol_roll, 16U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_kontrol_pitch, 17U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ex, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ey, 19U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_ey = c4_y_hedef - c4_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_ex = c4_x_hedef - c4_x;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_dey = c4_ydot;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_dex = c4_xdot;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_y_p = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_y_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_y_d = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_x_p = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_x_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_x_d = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_b = c4_ey;
  c4_b_y = 0.2 * c4_b;
  c4_b_b = c4_dey;
  c4_c_y = 0.1 * c4_b_b;
  c4_kontrol_roll = c4_b_y - c4_c_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_c_b = c4_ex;
  c4_d_y = 0.1 * c4_c_b;
  c4_d_b = c4_dex;
  c4_e_y = 0.1 * c4_d_b;
  c4_kontrol_pitch = c4_d_y - c4_e_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  *c4_b_kontrol_roll = c4_kontrol_roll;
  *c4_b_kontrol_pitch = c4_kontrol_pitch;
  *c4_b_ex = c4_ex;
  *c4_b_ey = c4_ey;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_Quadsim(SFc4_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QuadsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_ey, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ey), &c4_thisId);
  sf_mex_destroy(&c4_ey);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ey;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QuadsimInstanceStruct *)chartInstanceVoid;
  c4_ey = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ey), &c4_thisId);
  sf_mex_destroy(&c4_ey);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[1];
  c4_ResolvedFunctionInfo (*c4_b_info)[1];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[1])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mtimes";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[0].fileTimeLo = 1289516092U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c4_i0 = 0; c4_i0 < 1; c4_i0++) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QuadsimInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QuadsimInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Quadsim, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Quadsim), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Quadsim);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_QuadsimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(14208064U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3264957759U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2118541878U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1857790795U);
}

mxArray *sf_c4_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y13Ws3ALp5PfBrFx9vErGD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c4_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[12],T\"ex\",},{M[1],M[13],T\"ey\",},{M[1],M[11],T\"kontrol_pitch\",},{M[1],M[6],T\"kontrol_roll\",},{M[8],M[0],T\"is_active_c4_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc4_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          4,
          1,
          1,
          10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"y_hedef");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"kontrol_roll");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ydot");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x_hedef");
          _SFD_SET_DATA_PROPS(5,1,1,0,"x");
          _SFD_SET_DATA_PROPS(6,1,1,0,"xdot");
          _SFD_SET_DATA_PROPS(7,2,0,1,"kontrol_pitch");
          _SFD_SET_DATA_PROPS(8,2,0,1,"ex");
          _SFD_SET_DATA_PROPS(9,2,0,1,"ey");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,300);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_y_hedef;
          real_T *c4_y;
          real_T *c4_kontrol_roll;
          real_T *c4_ydot;
          real_T *c4_x_hedef;
          real_T *c4_x;
          real_T *c4_xdot;
          real_T *c4_kontrol_pitch;
          real_T *c4_ex;
          real_T *c4_ey;
          c4_ey = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_ex = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_kontrol_pitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_xdot = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c4_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_x_hedef = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_ydot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_kontrol_roll = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_y_hedef = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_y_hedef);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_kontrol_roll);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_ydot);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_x_hedef);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_x);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_xdot);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_kontrol_pitch);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_ex);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_ey);
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
  return "CUs8mPnHI1dV0odOiDsGvH";
}

static void sf_opaque_initialize_c4_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Quadsim(void *chartInstanceVar)
{
  enable_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Quadsim(void *chartInstanceVar)
{
  disable_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Quadsim(void *chartInstanceVar)
{
  sf_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Quadsim((SFc4_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Quadsim((SFc4_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_Quadsim(S);
}

static void sf_opaque_set_sim_state_c4_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_Quadsim(S, st);
}

static void sf_opaque_terminate_c4_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Quadsim((SFc4_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Quadsim((SFc4_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1514165753U));
  ssSetChecksum1(S,(233166670U));
  ssSetChecksum2(S,(2112907702U));
  ssSetChecksum3(S,(482717526U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Quadsim(SimStruct *S)
{
  SFc4_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc4_QuadsimInstanceStruct *)malloc(sizeof
    (SFc4_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Quadsim;
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

void c4_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
