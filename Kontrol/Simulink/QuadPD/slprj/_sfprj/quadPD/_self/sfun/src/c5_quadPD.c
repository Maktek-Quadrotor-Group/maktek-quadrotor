/* Include files */

#include "blascompat32.h"
#include "quadPD_sfun.h"
#include "c5_quadPD.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "quadPD_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[26] = { "Fi", "Teta", "Psi", "X", "Y",
  "Z", "dX", "dY", "XHedef", "YHedef", "PsiHedef", "ZHedef", "kpx", "kdx", "kpy",
  "kdy", "eX", "eY", "X_kont", "Y_kont", "nargin", "nargout", "Durum", "dDurum",
  "Hedef", "Cikis" };

/* Function Declarations */
static void initialize_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void initialize_params_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void enable_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void disable_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_quadPD(SFc5_quadPDInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_quadPD(SFc5_quadPDInstanceStruct
  *chartInstance);
static void set_sim_state_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void sf_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void initSimStructsc5_quadPD(SFc5_quadPDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance, const
  mxArray *c5_Cikis, const char_T *c5_identifier, real_T c5_y[4]);
static void c5_b_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_quadPD, const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_quadPDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_quadPD = 0U;
}

static void initialize_params_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
}

static void enable_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_quadPD(SFc5_quadPDInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_quadPD(SFc5_quadPDInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[4];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_Cikis)[4];
  c5_Cikis = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 4; c5_i0++) {
    c5_u[c5_i0] = (*c5_Cikis)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_quadPD;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[4];
  int32_T c5_i1;
  real_T (*c5_Cikis)[4];
  c5_Cikis = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "Cikis", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 4; c5_i1++) {
    (*c5_Cikis)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_quadPD = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_quadPD");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_quadPD(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
}

static void sf_c5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  real_T c5_Durum[6];
  int32_T c5_i7;
  real_T c5_dDurum[6];
  int32_T c5_i8;
  real_T c5_Hedef[4];
  uint32_T c5_debug_family_var_map[26];
  real_T c5_Fi;
  real_T c5_Teta;
  real_T c5_Psi;
  real_T c5_X;
  real_T c5_Y;
  real_T c5_Z;
  real_T c5_dX;
  real_T c5_dY;
  real_T c5_XHedef;
  real_T c5_YHedef;
  real_T c5_PsiHedef;
  real_T c5_ZHedef;
  real_T c5_kpx;
  real_T c5_kdx;
  real_T c5_kpy;
  real_T c5_kdy;
  real_T c5_eX;
  real_T c5_eY;
  real_T c5_X_kont;
  real_T c5_Y_kont;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_Cikis[4];
  real_T c5_b;
  real_T c5_y;
  real_T c5_b_b;
  real_T c5_b_y;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_d_b;
  real_T c5_d_y;
  int32_T c5_i9;
  real_T (*c5_b_Cikis)[4];
  real_T (*c5_b_Hedef)[4];
  real_T (*c5_b_dDurum)[6];
  real_T (*c5_b_Durum)[6];
  c5_b_Hedef = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_Cikis = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_dDurum = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_Durum = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 6; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_Durum)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 6; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_dDurum)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 4; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_Cikis)[c5_i4], 2U);
  }

  for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_Hedef)[c5_i5], 3U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i6 = 0; c5_i6 < 6; c5_i6++) {
    c5_Durum[c5_i6] = (*c5_b_Durum)[c5_i6];
  }

  for (c5_i7 = 0; c5_i7 < 6; c5_i7++) {
    c5_dDurum[c5_i7] = (*c5_b_dDurum)[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 4; c5_i8++) {
    c5_Hedef[c5_i8] = (*c5_b_Hedef)[c5_i8];
  }

  sf_debug_symbol_scope_push_eml(0U, 26U, 26U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_Fi, 0U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Teta, 1U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Psi, 2U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X, 3U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y, 4U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Z, 5U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_dX, 6U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_dY, 7U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_XHedef, 8U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_YHedef, 9U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_PsiHedef, 10U,
    c5_d_sf_marshallOut, c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ZHedef, 11U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_kpx, 12U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_kdx, 13U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_kpy, 14U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_kdy, 15U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_eX, 16U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_eY, 17U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_kont, 18U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y_kont, 19U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 20U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 21U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c5_Durum, 22U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_dDurum, 23U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_Hedef, 24U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_Cikis, 25U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_Fi = c5_Durum[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_Teta = c5_Durum[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_Psi = c5_Durum[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_X = c5_Durum[3];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_Y = c5_Durum[4];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_Z = c5_Durum[5];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_dX = c5_dDurum[3];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_dY = c5_dDurum[4];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_XHedef = c5_Hedef[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_YHedef = c5_Hedef[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_PsiHedef = c5_Hedef[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_ZHedef = c5_Hedef[3];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_kpx = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_kdx = 0.15;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_kpy = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_kdy = 0.17;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_eX = c5_XHedef - c5_X;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_eY = c5_YHedef - c5_Y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_b = c5_eX;
  c5_y = 0.1 * c5_b;
  c5_b_b = c5_dX;
  c5_b_y = 0.15 * c5_b_b;
  c5_X_kont = c5_y - c5_b_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_c_b = c5_eY;
  c5_c_y = 0.1 * c5_c_b;
  c5_d_b = c5_dY;
  c5_d_y = 0.17 * c5_d_b;
  c5_Y_kont = c5_c_y - c5_d_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
  c5_Cikis[0] = c5_Y_kont;
  c5_Cikis[1] = c5_X_kont;
  c5_Cikis[2] = c5_PsiHedef;
  c5_Cikis[3] = c5_ZHedef;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -28);
  sf_debug_symbol_scope_pop();
  for (c5_i9 = 0; c5_i9 < 4; c5_i9++) {
    (*c5_b_Cikis)[c5_i9] = c5_Cikis[c5_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_quadPDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_quadPD(SFc5_quadPDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i10;
  real_T c5_b_inData[4];
  int32_T c5_i11;
  real_T c5_u[4];
  const mxArray *c5_y = NULL;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i10 = 0; c5_i10 < 4; c5_i10++) {
    c5_b_inData[c5_i10] = (*(real_T (*)[4])c5_inData)[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 4; c5_i11++) {
    c5_u[c5_i11] = c5_b_inData[c5_i11];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance, const
  mxArray *c5_Cikis, const char_T *c5_identifier, real_T c5_y[4])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Cikis), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Cikis);
}

static void c5_b_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4])
{
  real_T c5_dv1[4];
  int32_T c5_i12;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c5_i12 = 0; c5_i12 < 4; c5_i12++) {
    c5_y[c5_i12] = c5_dv1[c5_i12];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_Cikis;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[4];
  int32_T c5_i13;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_Cikis = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Cikis), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Cikis);
  for (c5_i13 = 0; c5_i13 < 4; c5_i13++) {
    (*(real_T (*)[4])c5_outData)[c5_i13] = c5_y[c5_i13];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i14;
  real_T c5_b_inData[4];
  int32_T c5_i15;
  real_T c5_u[4];
  const mxArray *c5_y = NULL;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i14 = 0; c5_i14 < 4; c5_i14++) {
    c5_b_inData[c5_i14] = (*(real_T (*)[4])c5_inData)[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 4; c5_i15++) {
    c5_u[c5_i15] = c5_b_inData[c5_i15];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i16;
  real_T c5_b_inData[6];
  int32_T c5_i17;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i16 = 0; c5_i16 < 6; c5_i16++) {
    c5_b_inData[c5_i16] = (*(real_T (*)[6])c5_inData)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 6; c5_i17++) {
    c5_u[c5_i17] = c5_b_inData[c5_i17];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_quadPD_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[1];
  c5_ResolvedFunctionInfo (*c5_b_info)[1];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i18;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[1])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "mtimes";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[0].fileTimeLo = 1289516092U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 0U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c5_i18 = 0; c5_i18 < 1; c5_i18++) {
    c5_r0 = &c5_info[c5_i18];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i18);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i18);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i19;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i19, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i19;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_quadPD, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_quadPD), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_quadPD);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_quadPDInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_quadPDInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_quadPD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1542821128U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1123488035U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2408895304U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2393516049U);
}

mxArray *sf_c5_quadPD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NS6uPjrF1bXzXeWblzr23D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c5_quadPD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Cikis\",},{M[8],M[0],T\"is_active_c5_quadPD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_quadPD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_quadPDInstanceStruct *chartInstance;
    chartInstance = (SFc5_quadPDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_quadPDMachineNumber_,
          5,
          1,
          1,
          4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Durum");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dDurum");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Cikis");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Hedef");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,443);
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
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c5_Durum)[6];
          real_T (*c5_dDurum)[6];
          real_T (*c5_Cikis)[4];
          real_T (*c5_Hedef)[4];
          c5_Hedef = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
          c5_Cikis = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_dDurum = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c5_Durum = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_Durum);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_dDurum);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_Cikis);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_Hedef);
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
  return "epoZoda4OuWM0qVCXi0fsF";
}

static void sf_opaque_initialize_c5_quadPD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_quadPDInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
  initialize_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_quadPD(void *chartInstanceVar)
{
  enable_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_quadPD(void *chartInstanceVar)
{
  disable_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_quadPD(void *chartInstanceVar)
{
  sf_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_quadPD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_quadPD((SFc5_quadPDInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_quadPD();/* state var info */
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

extern void sf_internal_set_sim_state_c5_quadPD(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_quadPD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_quadPD((SFc5_quadPDInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_quadPD(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_quadPD(S);
}

static void sf_opaque_set_sim_state_c5_quadPD(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_quadPD(S, st);
}

static void sf_opaque_terminate_c5_quadPD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_quadPDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_quadPD_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_quadPD((SFc5_quadPDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_quadPD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_quadPD((SFc5_quadPDInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_quadPD_optimization_info();
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
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3878371984U));
  ssSetChecksum1(S,(106204770U));
  ssSetChecksum2(S,(2321398774U));
  ssSetChecksum3(S,(2351847206U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_quadPD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_quadPD(SimStruct *S)
{
  SFc5_quadPDInstanceStruct *chartInstance;
  chartInstance = (SFc5_quadPDInstanceStruct *)malloc(sizeof
    (SFc5_quadPDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_quadPDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_quadPD;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_quadPD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_quadPD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_quadPD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_quadPD;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_quadPD;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_quadPD;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_quadPD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_quadPD;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_quadPD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_quadPD;
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

void c5_quadPD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_quadPD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_quadPD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_quadPD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_quadPD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
