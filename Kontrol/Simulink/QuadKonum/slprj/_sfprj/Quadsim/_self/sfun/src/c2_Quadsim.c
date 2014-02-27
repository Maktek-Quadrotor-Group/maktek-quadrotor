/* Include files */

#include "blascompat32.h"
#include "Quadsim_sfun.h"
#include "c2_Quadsim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadsim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[40] = { "arm_l", "craft_m", "Ixx",
  "Iyy", "Izz", "b", "d", "g", "X_dot", "Y_dot", "Z_dot", "Roll_dot",
  "Pitch_dot", "Yaw_dot", "X", "Y", "Z", "Roll", "Pitch", "Yaw", "F", "R", "B",
  "L", "TF", "TR", "TB", "TL", "D", "X_ddot", "Y_ddot", "z_craft_component",
  "Z_ddot", "Roll_ddot", "Pitch_ddot", "Yaw_ddot", "nargin", "nargout", "Xin",
  "Xout" };

/* Function Declarations */
static void initialize_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void initialize_params_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance);
static void enable_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void disable_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance);
static void set_sim_state_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void sf_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void c2_chartstep_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void initSimStructsc2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance, const
  mxArray *c2_Xout, const char_T *c2_identifier, real_T c2_y[12]);
static void c2_b_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14]);
static void c2_eml_scalar_eg(SFc2_QuadsimInstanceStruct *chartInstance);
static real_T c2_mpower(SFc2_QuadsimInstanceStruct *chartInstance, real_T c2_a);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Quadsim, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_QuadsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Quadsim = 0U;
}

static void initialize_params_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance)
{
}

static void enable_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Quadsim(SFc2_QuadsimInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[12];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_Xout)[12];
  c2_Xout = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
    c2_u[c2_i0] = (*c2_Xout)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 12),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Quadsim;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[12];
  int32_T c2_i1;
  real_T (*c2_Xout)[12];
  c2_Xout = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "Xout",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 12; c2_i1++) {
    (*c2_Xout)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_Quadsim = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_Quadsim");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Quadsim(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
}

static void sf_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T (*c2_Xin)[16];
  real_T (*c2_Xout)[12];
  c2_Xin = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c2_Xout = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 12; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_Xout)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 16; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_Xin)[c2_i3], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Quadsim(chartInstance);
  sf_debug_check_for_state_inconsistency(_QuadsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  real_T c2_Xin[16];
  uint32_T c2_debug_family_var_map[40];
  real_T c2_arm_l;
  real_T c2_craft_m;
  real_T c2_Ixx;
  real_T c2_Iyy;
  real_T c2_Izz;
  real_T c2_b;
  real_T c2_d;
  real_T c2_g;
  real_T c2_X_dot;
  real_T c2_Y_dot;
  real_T c2_Z_dot;
  real_T c2_Roll_dot;
  real_T c2_Pitch_dot;
  real_T c2_Yaw_dot;
  real_T c2_X;
  real_T c2_Y;
  real_T c2_Z;
  real_T c2_Roll;
  real_T c2_Pitch;
  real_T c2_Yaw;
  real_T c2_F;
  real_T c2_R;
  real_T c2_B;
  real_T c2_L;
  real_T c2_TF;
  real_T c2_TR;
  real_T c2_TB;
  real_T c2_TL;
  real_T c2_D;
  real_T c2_X_ddot;
  real_T c2_Y_ddot;
  real_T c2_z_craft_component;
  real_T c2_Z_ddot;
  real_T c2_Roll_ddot;
  real_T c2_Pitch_ddot;
  real_T c2_Yaw_ddot;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_Xout[12];
  real_T c2_b_b;
  real_T c2_c_b;
  real_T c2_d_b;
  real_T c2_e_b;
  real_T c2_f_b;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_g_b;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_a;
  real_T c2_h_b;
  real_T c2_b_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_a;
  real_T c2_i_b;
  real_T c2_c_y;
  real_T c2_j_b;
  real_T c2_d_y;
  real_T c2_d_a;
  real_T c2_k_b;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_e_a;
  real_T c2_l_b;
  real_T c2_e_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_f_a;
  real_T c2_m_b;
  real_T c2_f_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_g_a;
  real_T c2_n_b;
  real_T c2_g_y;
  real_T c2_o_b;
  real_T c2_h_y;
  real_T c2_h_a;
  real_T c2_p_b;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_q_b;
  real_T c2_i_y;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_i_a;
  real_T c2_r_b;
  real_T c2_j_y;
  real_T c2_j_a;
  real_T c2_s_b;
  real_T c2_t_b;
  real_T c2_u_b;
  real_T c2_A;
  real_T c2_y_x;
  real_T c2_ab_x;
  int32_T c2_i5;
  real_T (*c2_b_Xout)[12];
  real_T (*c2_b_Xin)[16];
  c2_b_Xin = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_Xout = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 16; c2_i4++) {
    c2_Xin[c2_i4] = (*c2_b_Xin)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 40U, 40U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_arm_l, 0U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_craft_m, 1U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Ixx, 2U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Iyy, 3U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Izz, 4U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_b, 5U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_d, 6U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_g, 7U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_X_dot, 8U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Y_dot, 9U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Z_dot, 10U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Roll_dot, 11U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Pitch_dot, 12U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Yaw_dot, 13U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_X, 14U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Y, 15U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Z, 16U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Roll, 17U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Pitch, 18U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Yaw, 19U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_F, 20U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_R, 21U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_B, 22U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L, 23U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_TF, 24U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_TR, 25U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_TB, 26U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_TL, 27U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_D, 28U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_X_ddot, 29U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Y_ddot, 30U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_z_craft_component, 31U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Z_ddot, 32U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Roll_ddot, 33U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Pitch_ddot, 34U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Yaw_ddot, 35U,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 36U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 37U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_Xin, 38U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_Xout, 39U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_arm_l = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_craft_m = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_Ixx = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_Iyy = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_Izz = 0.013000000000000001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_b = 3.1299999999999995E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_d = 7.5E-7;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_X_dot = c2_Xin[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_Y_dot = c2_Xin[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_Z_dot = c2_Xin[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_Roll_dot = c2_Xin[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_Pitch_dot = c2_Xin[4];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_Yaw_dot = c2_Xin[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_X = c2_Xin[6];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_Y = c2_Xin[7];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_Z = c2_Xin[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_Roll = c2_Xin[9];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_Pitch = c2_Xin[10];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_Yaw = c2_Xin[11];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_F = c2_Xin[12];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_R = c2_Xin[13];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_B = c2_Xin[14];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_L = c2_Xin[15];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_b_b = c2_mpower(chartInstance, c2_F);
  c2_TF = 3.1299999999999995E-5 * c2_b_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_c_b = c2_mpower(chartInstance, c2_R);
  c2_TR = 3.1299999999999995E-5 * c2_c_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  c2_d_b = c2_mpower(chartInstance, c2_B);
  c2_TB = 3.1299999999999995E-5 * c2_d_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_e_b = c2_mpower(chartInstance, c2_L);
  c2_TL = 3.1299999999999995E-5 * c2_e_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_f_b = ((-c2_F + c2_R) - c2_B) + c2_L;
  c2_D = 7.5E-7 * c2_f_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_x = c2_Roll;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_Pitch;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_a = c2_b_x;
  c2_g_b = c2_d_x;
  c2_y = c2_a * c2_g_b;
  c2_e_x = c2_Yaw;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarCos(c2_f_x);
  c2_b_a = c2_y;
  c2_h_b = c2_f_x;
  c2_b_y = c2_b_a * c2_h_b;
  c2_g_x = c2_Roll;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_i_x = c2_Yaw;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSin(c2_j_x);
  c2_c_a = c2_h_x;
  c2_i_b = c2_j_x;
  c2_c_y = c2_c_a * c2_i_b;
  c2_j_b = c2_b_y + c2_c_y;
  c2_d_y = 1.0526315789473684 * c2_j_b;
  c2_d_a = c2_d_y;
  c2_k_b = ((c2_TF + c2_TR) + c2_TB) + c2_TL;
  c2_X_ddot = c2_d_a * c2_k_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_k_x = c2_Roll;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_m_x = c2_Pitch;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarSin(c2_n_x);
  c2_e_a = c2_l_x;
  c2_l_b = c2_n_x;
  c2_e_y = c2_e_a * c2_l_b;
  c2_o_x = c2_Yaw;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarSin(c2_p_x);
  c2_f_a = c2_e_y;
  c2_m_b = c2_p_x;
  c2_f_y = c2_f_a * c2_m_b;
  c2_q_x = c2_Roll;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_s_x = c2_Yaw;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_g_a = c2_r_x;
  c2_n_b = c2_t_x;
  c2_g_y = c2_g_a * c2_n_b;
  c2_o_b = c2_f_y + c2_g_y;
  c2_h_y = 1.0526315789473684 * c2_o_b;
  c2_h_a = c2_h_y;
  c2_p_b = ((c2_TF + c2_TR) + c2_TB) + c2_TL;
  c2_Y_ddot = c2_h_a * c2_p_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_u_x = c2_Roll;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarCos(c2_v_x);
  c2_q_b = c2_v_x;
  c2_i_y = 1.0526315789473684 * c2_q_b;
  c2_w_x = c2_Pitch;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarCos(c2_x_x);
  c2_i_a = c2_i_y;
  c2_r_b = c2_x_x;
  c2_j_y = c2_i_a * c2_r_b;
  c2_j_a = c2_j_y;
  c2_s_b = ((c2_TF + c2_TR) + c2_TB) + c2_TL;
  c2_z_craft_component = c2_j_a * c2_s_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
  c2_Z_ddot = c2_z_craft_component - c2_g;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  c2_t_b = -c2_TR + c2_TL;
  c2_Roll_ddot = 30.666666666666668 * c2_t_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  c2_u_b = c2_TF - c2_TB;
  c2_Pitch_ddot = 30.666666666666668 * c2_u_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
  c2_A = c2_D;
  c2_y_x = c2_A;
  c2_ab_x = c2_y_x;
  c2_Yaw_ddot = c2_ab_x / 0.013000000000000001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
  c2_Xout[0] = c2_X_ddot;
  c2_Xout[1] = c2_Y_ddot;
  c2_Xout[2] = c2_Z_ddot;
  c2_Xout[3] = c2_Roll_ddot;
  c2_Xout[4] = c2_Pitch_ddot;
  c2_Xout[5] = c2_Yaw_ddot;
  c2_Xout[6] = c2_X_dot;
  c2_Xout[7] = c2_Y_dot;
  c2_Xout[8] = c2_Z_dot;
  c2_Xout[9] = c2_Roll_dot;
  c2_Xout[10] = c2_Pitch_dot;
  c2_Xout[11] = c2_Yaw_dot;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -65);
  sf_debug_symbol_scope_pop();
  for (c2_i5 = 0; c2_i5 < 12; c2_i5++) {
    (*c2_b_Xout)[c2_i5] = c2_Xout[c2_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Quadsim(SFc2_QuadsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i6;
  real_T c2_b_inData[12];
  int32_T c2_i7;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i6 = 0; c2_i6 < 12; c2_i6++) {
    c2_b_inData[c2_i6] = (*(real_T (*)[12])c2_inData)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 12; c2_i7++) {
    c2_u[c2_i7] = c2_b_inData[c2_i7];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 12), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance, const
  mxArray *c2_Xout, const char_T *c2_identifier, real_T c2_y[12])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Xout), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Xout);
}

static void c2_b_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12])
{
  real_T c2_dv1[12];
  int32_T c2_i8;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 12);
  for (c2_i8 = 0; c2_i8 < 12; c2_i8++) {
    c2_y[c2_i8] = c2_dv1[c2_i8];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Xout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[12];
  int32_T c2_i9;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_Xout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Xout), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Xout);
  for (c2_i9 = 0; c2_i9 < 12; c2_i9++) {
    (*(real_T (*)[12])c2_outData)[c2_i9] = c2_y[c2_i9];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  real_T c2_b_inData[16];
  int32_T c2_i11;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i10 = 0; c2_i10 < 16; c2_i10++) {
    c2_b_inData[c2_i10] = (*(real_T (*)[16])c2_inData)[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    c2_u[c2_i11] = c2_b_inData[c2_i11];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 16), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
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
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Quadsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[14];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i12;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c2_i12 = 0; c2_i12 < 14; c2_i12++) {
    c2_r0 = &c2_info[c2_i12];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i12);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14])
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
  c2_info[10].context = "";
  c2_info[10].name = "cos";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[10].fileTimeLo = 1286815106U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[11].name = "eml_scalar_cos";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[11].fileTimeLo = 1286815122U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "sin";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[12].fileTimeLo = 1286815150U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[13].name = "eml_scalar_sin";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[13].fileTimeLo = 1286815136U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_QuadsimInstanceStruct *chartInstance)
{
}

static real_T c2_mpower(SFc2_QuadsimInstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i13, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i13;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Quadsim, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Quadsim), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Quadsim);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_QuadsimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_QuadsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Quadsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4118834690U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3293625441U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3925692659U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4294461591U);
}

mxArray *sf_c2_Quadsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vyQJe5G6FueBtQwHzFUh1F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(16);
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
      pr[1] = (double)(12);
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

static const mxArray *sf_get_sim_state_info_c2_Quadsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Xout\",},{M[8],M[0],T\"is_active_c2_Quadsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Quadsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_QuadsimInstanceStruct *chartInstance;
    chartInstance = (SFc2_QuadsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QuadsimMachineNumber_,
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
          init_script_number_translation(_QuadsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_QuadsimMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QuadsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Xout");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Xin");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1743);
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
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c2_Xout)[12];
          real_T (*c2_Xin)[16];
          c2_Xin = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          c2_Xout = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Xout);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_Xin);
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
  return "9o7dvh4brCYsAmWk5kqURF";
}

static void sf_opaque_initialize_c2_Quadsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_QuadsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
  initialize_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Quadsim(void *chartInstanceVar)
{
  enable_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Quadsim(void *chartInstanceVar)
{
  disable_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Quadsim(void *chartInstanceVar)
{
  sf_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Quadsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Quadsim((SFc2_QuadsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Quadsim();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Quadsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Quadsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Quadsim((SFc2_QuadsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Quadsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Quadsim(S);
}

static void sf_opaque_set_sim_state_c2_Quadsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Quadsim(S, st);
}

static void sf_opaque_terminate_c2_Quadsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_QuadsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Quadsim_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Quadsim((SFc2_QuadsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Quadsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Quadsim((SFc2_QuadsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadsim_optimization_info();
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
  ssSetChecksum0(S,(187015974U));
  ssSetChecksum1(S,(574456174U));
  ssSetChecksum2(S,(1755528127U));
  ssSetChecksum3(S,(3318370812U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Quadsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Quadsim(SimStruct *S)
{
  SFc2_QuadsimInstanceStruct *chartInstance;
  chartInstance = (SFc2_QuadsimInstanceStruct *)malloc(sizeof
    (SFc2_QuadsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_QuadsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Quadsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Quadsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_Quadsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Quadsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Quadsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Quadsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Quadsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_Quadsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Quadsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Quadsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Quadsim;
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

void c2_Quadsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Quadsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Quadsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Quadsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Quadsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
