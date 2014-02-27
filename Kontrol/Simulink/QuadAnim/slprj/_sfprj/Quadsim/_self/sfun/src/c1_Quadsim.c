/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c1_Quadsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[31] = { "roll_set", "pitch_set",
  "yaw_set", "roll_dot", "pitch_dot", "yaw_dot", "roll", "pitch", "yaw",
  "roll_p", "roll_i", "roll_d", "pitch_p", "pitch_i", "pitch_d", "yaw_p",
  "yaw_i", "yaw_d", "roll_error", "yaw_error", "roll_d_error", "pitch_d_error",
  "yaw_d_error", "roll_return", "pitch_return", "yaw_return", "nargin",
  "nargout", "Cin", "Cout", "pitch_error" };

/* Function Declarations */
static void initialize_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance);
static void enable_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void disable_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void sf_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void c1_chartstep_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_pitch_error, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_Cout, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_d_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Quadsim, const char_T *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Quadsim = 0U;
}

static void initialize_params_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Quadsim(SFc1_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_pitch_error;
  real_T (*c1_Cout)[3];
  c1_pitch_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Cout = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_Cout)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = *c1_pitch_error;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_Quadsim;
  c1_c_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i1;
  real_T *c1_pitch_error;
  real_T (*c1_Cout)[3];
  c1_pitch_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Cout = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "Cout", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    (*c1_Cout)[c1_i1] = c1_dv0[c1_i1];
  }

  *c1_pitch_error = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "pitch_error");
  chartInstance->c1_is_active_c1_Quadsim = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "is_active_c1_Quadsim");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Quadsim(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  real_T *c1_pitch_error;
  real_T (*c1_Cout)[3];
  real_T (*c1_Cin)[15];
  c1_pitch_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Cout = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_Cin = (real_T (*)[15])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 15; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_Cin)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_Cout)[c1_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_pitch_error, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Quadsim(chartInstance);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
  int32_T c1_i4;
  real_T c1_Cin[15];
  uint32_T c1_debug_family_var_map[31];
  real_T c1_roll_set;
  real_T c1_pitch_set;
  real_T c1_yaw_set;
  real_T c1_roll_dot;
  real_T c1_pitch_dot;
  real_T c1_yaw_dot;
  real_T c1_roll;
  real_T c1_pitch;
  real_T c1_yaw;
  real_T c1_roll_p;
  real_T c1_roll_i;
  real_T c1_roll_d;
  real_T c1_pitch_p;
  real_T c1_pitch_i;
  real_T c1_pitch_d;
  real_T c1_yaw_p;
  real_T c1_yaw_i;
  real_T c1_yaw_d;
  real_T c1_roll_error;
  real_T c1_yaw_error;
  real_T c1_roll_d_error;
  real_T c1_pitch_d_error;
  real_T c1_yaw_d_error;
  real_T c1_roll_return;
  real_T c1_pitch_return;
  real_T c1_yaw_return;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_Cout[3];
  real_T c1_pitch_error;
  real_T c1_b;
  real_T c1_y;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_f_b;
  real_T c1_f_y;
  int32_T c1_i5;
  int32_T c1_i6;
  real_T *c1_b_pitch_error;
  real_T (*c1_b_Cout)[3];
  real_T (*c1_b_Cin)[15];
  c1_b_pitch_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Cout = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Cin = (real_T (*)[15])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 15; c1_i4++) {
    c1_Cin[c1_i4] = (*c1_b_Cin)[c1_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 31U, 31U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_set, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_set, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_set, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_dot, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_dot, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_dot, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_roll_p, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_i, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_roll_d, 11U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_pitch_p, 12U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_i, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_pitch_d, 14U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_yaw_p, 15U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_i, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_yaw_d, 17U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_error, 18U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_error, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_d_error, 20U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_d_error, 21U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_d_error, 22U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_roll_return, 23U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_return, 24U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yaw_return, 25U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 26U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 27U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_Cin, 28U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_Cout, 29U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pitch_error, 30U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_roll_set = c1_Cin[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_pitch_set = c1_Cin[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_yaw_set = c1_Cin[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_roll_dot = c1_Cin[6];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_pitch_dot = c1_Cin[7];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_yaw_dot = c1_Cin[8];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_roll = c1_Cin[12];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_pitch = c1_Cin[13];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_yaw = c1_Cin[14];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_roll_p = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_roll_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_roll_d = 0.175;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_pitch_p = 0.7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_pitch_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_pitch_d = 0.175;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_yaw_p = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_yaw_i = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_yaw_d = 0.175;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_roll_error = c1_roll_set - c1_roll;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_pitch_error = c1_pitch_set - c1_pitch;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_yaw_error = c1_yaw_set - c1_yaw;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_roll_d_error = c1_roll_dot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  c1_pitch_d_error = c1_pitch_dot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_yaw_d_error = c1_yaw_dot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_b = c1_roll_error;
  c1_y = 0.5 * c1_b;
  c1_b_b = c1_roll_d_error;
  c1_b_y = 0.175 * c1_b_b;
  c1_roll_return = c1_y - c1_b_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  c1_c_b = c1_pitch_error;
  c1_c_y = 0.7 * c1_c_b;
  c1_d_b = c1_pitch_d_error;
  c1_d_y = 0.175 * c1_d_b;
  c1_pitch_return = c1_c_y - c1_d_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  c1_e_b = c1_yaw_error;
  c1_e_y = 0.5 * c1_e_b;
  c1_f_b = c1_yaw_d_error;
  c1_f_y = 0.175 * c1_f_b;
  c1_yaw_return = c1_e_y - c1_f_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_Cout[c1_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
  c1_Cout[0] = c1_roll_return;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  c1_Cout[1] = c1_pitch_return;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  c1_Cout[2] = c1_yaw_return;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -55);
  sf_debug_symbol_scope_pop();
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    (*c1_b_Cout)[c1_i6] = c1_Cout[c1_i6];
  }

  *c1_b_pitch_error = c1_pitch_error;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Quadsim(SFc1_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_pitch_error, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_pitch_error),
    &c1_thisId);
  sf_mex_destroy(&c1_pitch_error);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_pitch_error;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_pitch_error = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_pitch_error),
    &c1_thisId);
  sf_mex_destroy(&c1_pitch_error);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i7;
  real_T c1_b_inData[3];
  int32_T c1_i8;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_b_inData[c1_i7] = (*(real_T (*)[3])c1_inData)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_u[c1_i8] = c1_b_inData[c1_i8];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_Cout, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Cout), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Cout);
}

static void c1_d_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv1[3];
  int32_T c1_i9;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_y[c1_i9] = c1_dv1[c1_i9];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Cout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i10;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_Cout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Cout), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Cout);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    (*(real_T (*)[3])c1_outData)[c1_i10] = c1_y[c1_i10];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i11;
  real_T c1_b_inData[15];
  int32_T c1_i12;
  real_T c1_u[15];
  const mxArray *c1_y = NULL;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i11 = 0; c1_i11 < 15; c1_i11++) {
    c1_b_inData[c1_i11] = (*(real_T (*)[15])c1_inData)[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 15; c1_i12++) {
    c1_u[c1_i12] = c1_b_inData[c1_i12];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 15), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[1];
  c1_ResolvedFunctionInfo (*c1_b_info)[1];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i13;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[1])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289516092U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c1_i13 = 0; c1_i13 < 1; c1_i13++) {
    c1_r0 = &c1_info[c1_i13];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i13);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i13);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i14;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i14, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i14;
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
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Quadsim, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Quadsim), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Quadsim);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_QuadsimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1778271072U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2018721704U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3164733172U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2724660017U);
}

mxArray *sf_c1_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Kpq7dSH6NENuAxd0Y3TUiE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(15);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Cout\",},{M[1],M[7],T\"pitch_error\",},{M[8],M[0],T\"is_active_c1_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc1_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
          1,
          1,
          1,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Cin");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Cout");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pitch_error");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1205);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_pitch_error;
          real_T (*c1_Cin)[15];
          real_T (*c1_Cout)[3];
          c1_pitch_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Cout = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Cin = (real_T (*)[15])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_Cin);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_Cout);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_pitch_error);
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
  return "zUcdx8zrseZsHdosXKBZiF";
}

static void sf_opaque_initialize_c1_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Quadsim(void *chartInstanceVar)
{
  enable_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Quadsim(void *chartInstanceVar)
{
  disable_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Quadsim(void *chartInstanceVar)
{
  sf_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Quadsim((SFc1_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Quadsim((SFc1_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Quadsim(S);
}

static void sf_opaque_set_sim_state_c1_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Quadsim(S, st);
}

static void sf_opaque_terminate_c1_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Quadsim((SFc1_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Quadsim((SFc1_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4106376529U));
  ssSetChecksum1(S,(3379817207U));
  ssSetChecksum2(S,(215719143U));
  ssSetChecksum3(S,(2601473049U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Quadsim(SimStruct *S)
{
  SFc1_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc1_QuadsimInstanceStruct *)malloc(sizeof
    (SFc1_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Quadsim;
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

void c1_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
