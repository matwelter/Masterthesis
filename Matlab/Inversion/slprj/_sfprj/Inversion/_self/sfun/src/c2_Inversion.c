/* Include files */

#include "blascompat32.h"
#include "Inversion_sfun.h"
#include "c2_Inversion.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Inversion_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[9] = { "T", "phi", "theta", "psi",
  "Mt", "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance);
static void initialize_params_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance);
static void enable_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance);
static void disable_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance);
static void set_sim_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance);
static void sf_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance);
static void c2_chartstep_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance);
static void initSimStructsc2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_eml_scalar_eg(SFc2_InversionInstanceStruct *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Inversion, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_InversionInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Inversion = 0U;
}

static void initialize_params_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance)
{
}

static void enable_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[3];
  c2_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Inversion;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i1;
  real_T (*c2_y)[3];
  c2_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_Inversion = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_Inversion");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Inversion(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance)
{
}

static void sf_c2_Inversion(SFc2_InversionInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T (*c2_y)[3];
  real_T (*c2_u)[4];
  c2_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_u)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_y)[c2_i3], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Inversion(chartInstance);
  sf_debug_check_for_state_inconsistency(_InversionMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance)
{
  int32_T c2_i4;
  real_T c2_u[4];
  uint32_T c2_debug_family_var_map[9];
  real_T c2_T;
  real_T c2_phi;
  real_T c2_theta;
  real_T c2_psi;
  real_T c2_Mt[9];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y[3];
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_d_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_e_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_f_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_g_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_h_y;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_i_y;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_j_y;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_k_y;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_k_a;
  real_T c2_k_b;
  real_T c2_l_y;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_l_a;
  real_T c2_l_b;
  real_T c2_m_y;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_n_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_o_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_p_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_q_y;
  int32_T c2_i5;
  real_T c2_q_a[9];
  real_T c2_q_b[3];
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_C[3];
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T (*c2_r_y)[3];
  real_T (*c2_b_u)[4];
  c2_r_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    c2_u[c2_i4] = (*c2_b_u)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_T, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_psi, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Mt, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 5U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 6U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_u, 7U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_T = c2_u[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_phi = c2_u[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_theta = c2_u[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_psi = c2_u[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_x = c2_theta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_psi;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_a = c2_b_x;
  c2_b = c2_d_x;
  c2_b_y = c2_a * c2_b;
  c2_e_x = c2_phi;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_b_a = c2_f_x;
  c2_b_b = c2_h_x;
  c2_c_y = c2_b_a * c2_b_b;
  c2_i_x = c2_psi;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_c_a = c2_c_y;
  c2_c_b = c2_j_x;
  c2_d_y = c2_c_a * c2_c_b;
  c2_k_x = c2_phi;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_m_x = c2_psi;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarSin(c2_n_x);
  c2_d_a = c2_l_x;
  c2_d_b = c2_n_x;
  c2_e_y = c2_d_a * c2_d_b;
  c2_o_x = c2_phi;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_q_x = c2_theta;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_e_a = c2_p_x;
  c2_e_b = c2_r_x;
  c2_f_y = c2_e_a * c2_e_b;
  c2_s_x = c2_psi;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_f_a = c2_f_y;
  c2_f_b = c2_t_x;
  c2_g_y = c2_f_a * c2_f_b;
  c2_u_x = c2_phi;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_w_x = c2_psi;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarSin(c2_x_x);
  c2_g_a = c2_v_x;
  c2_g_b = c2_x_x;
  c2_h_y = c2_g_a * c2_g_b;
  c2_y_x = c2_theta;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarCos(c2_ab_x);
  c2_bb_x = c2_psi;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_h_a = c2_ab_x;
  c2_h_b = c2_cb_x;
  c2_i_y = c2_h_a * c2_h_b;
  c2_db_x = c2_phi;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_fb_x = c2_theta;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarSin(c2_gb_x);
  c2_i_a = c2_eb_x;
  c2_i_b = c2_gb_x;
  c2_j_y = c2_i_a * c2_i_b;
  c2_hb_x = c2_psi;
  c2_ib_x = c2_hb_x;
  c2_ib_x = muDoubleScalarSin(c2_ib_x);
  c2_j_a = c2_j_y;
  c2_j_b = c2_ib_x;
  c2_k_y = c2_j_a * c2_j_b;
  c2_jb_x = c2_phi;
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarCos(c2_kb_x);
  c2_lb_x = c2_psi;
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarCos(c2_mb_x);
  c2_k_a = c2_kb_x;
  c2_k_b = c2_mb_x;
  c2_l_y = c2_k_a * c2_k_b;
  c2_nb_x = c2_phi;
  c2_ob_x = c2_nb_x;
  c2_ob_x = muDoubleScalarCos(c2_ob_x);
  c2_pb_x = c2_theta;
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_l_a = c2_ob_x;
  c2_l_b = c2_qb_x;
  c2_m_y = c2_l_a * c2_l_b;
  c2_rb_x = c2_psi;
  c2_sb_x = c2_rb_x;
  c2_sb_x = muDoubleScalarSin(c2_sb_x);
  c2_m_a = c2_m_y;
  c2_m_b = c2_sb_x;
  c2_n_y = c2_m_a * c2_m_b;
  c2_tb_x = c2_phi;
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarSin(c2_ub_x);
  c2_vb_x = c2_psi;
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarCos(c2_wb_x);
  c2_n_a = c2_ub_x;
  c2_n_b = c2_wb_x;
  c2_o_y = c2_n_a * c2_n_b;
  c2_xb_x = c2_theta;
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarSin(c2_yb_x);
  c2_ac_x = c2_phi;
  c2_bc_x = c2_ac_x;
  c2_bc_x = muDoubleScalarSin(c2_bc_x);
  c2_cc_x = c2_theta;
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarCos(c2_dc_x);
  c2_o_a = c2_bc_x;
  c2_o_b = c2_dc_x;
  c2_p_y = c2_o_a * c2_o_b;
  c2_ec_x = c2_phi;
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarCos(c2_fc_x);
  c2_gc_x = c2_theta;
  c2_hc_x = c2_gc_x;
  c2_hc_x = muDoubleScalarCos(c2_hc_x);
  c2_p_a = c2_fc_x;
  c2_p_b = c2_hc_x;
  c2_q_y = c2_p_a * c2_p_b;
  c2_Mt[0] = c2_b_y;
  c2_Mt[3] = c2_d_y - c2_e_y;
  c2_Mt[6] = c2_g_y + c2_h_y;
  c2_Mt[1] = c2_i_y;
  c2_Mt[4] = c2_k_y + c2_l_y;
  c2_Mt[7] = c2_n_y - c2_o_y;
  c2_Mt[2] = -c2_yb_x;
  c2_Mt[5] = c2_p_y;
  c2_Mt[8] = c2_q_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i5 = 0; c2_i5 < 9; c2_i5++) {
    c2_q_a[c2_i5] = c2_Mt[c2_i5];
  }

  c2_q_b[0] = 0.0;
  c2_q_b[1] = 0.0;
  c2_q_b[2] = c2_T;
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_y[c2_i6] = 0.0;
  }

  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_y[c2_i7] = 0.0;
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_C[c2_i8] = c2_y[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_y[c2_i9] = c2_C[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_C[c2_i10] = c2_y[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_y[c2_i11] = c2_C[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_y[c2_i12] = 0.0;
    c2_i13 = 0;
    for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
      c2_y[c2_i12] += c2_q_a[c2_i13 + c2_i12] * c2_q_b[c2_i14];
      c2_i13 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    (*c2_r_y)[c2_i15] = c2_y[c2_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Inversion(SFc2_InversionInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i16;
  real_T c2_b_inData[3];
  int32_T c2_i17;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_b_inData[c2_i16] = (*(real_T (*)[3])c2_inData)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    c2_u[c2_i17] = c2_b_inData[c2_i17];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i18;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    c2_y[c2_i18] = c2_dv1[c2_i18];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[3];
  int32_T c2_i19;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    (*(real_T (*)[3])c2_outData)[c2_i19] = c2_b_y[c2_i19];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i20;
  real_T c2_b_inData[4];
  int32_T c2_i21;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i20 = 0; c2_i20 < 4; c2_i20++) {
    c2_b_inData[c2_i20] = (*(real_T (*)[4])c2_inData)[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 4; c2_i21++) {
    c2_u[c2_i21] = c2_b_inData[c2_i21];
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
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
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
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
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
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  real_T c2_b_inData[9];
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
      c2_b_inData[c2_i24 + c2_i22] = (*(real_T (*)[9])c2_inData)[c2_i24 + c2_i22];
    }

    c2_i22 += 3;
  }

  c2_i25 = 0;
  for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
    for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
      c2_u[c2_i27 + c2_i25] = c2_b_inData[c2_i27 + c2_i25];
    }

    c2_i25 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv2[9];
  int32_T c2_i28;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i28 = 0; c2_i28 < 9; c2_i28++) {
    c2_y[c2_i28] = c2_dv2[c2_i28];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Mt;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_Mt = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Mt), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Mt);
  c2_i29 = 0;
  for (c2_i30 = 0; c2_i30 < 3; c2_i30++) {
    for (c2_i31 = 0; c2_i31 < 3; c2_i31++) {
      (*(real_T (*)[9])c2_outData)[c2_i31 + c2_i29] = c2_y[c2_i31 + c2_i29];
    }

    c2_i29 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Inversion_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[12];
  c2_ResolvedFunctionInfo (*c2_b_info)[12];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i32;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[12])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "cos";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[0].fileTimeLo = 1286818706U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[1].name = "eml_scalar_cos";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c2_b_info)[1].fileTimeLo = 1286818722U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context = "";
  (*c2_b_info)[2].name = "mtimes";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[2].fileTimeLo = 1289519692U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "sin";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[3].fileTimeLo = 1286818750U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[4].name = "eml_scalar_sin";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c2_b_info)[4].fileTimeLo = 1286818736U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[5].name = "eml_index_class";
  (*c2_b_info)[5].dominantType = "";
  (*c2_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c2_b_info)[5].fileTimeLo = 1286818778U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[6].name = "eml_scalar_eg";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c2_b_info)[6].fileTimeLo = 1286818796U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[7].name = "eml_xgemm";
  (*c2_b_info)[7].dominantType = "int32";
  (*c2_b_info)[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c2_b_info)[7].fileTimeLo = 1299076772U;
  (*c2_b_info)[7].fileTimeHi = 0U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  (*c2_b_info)[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c2_b_info)[8].name = "eml_blas_inline";
  (*c2_b_info)[8].dominantType = "";
  (*c2_b_info)[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c2_b_info)[8].fileTimeLo = 1299076768U;
  (*c2_b_info)[8].fileTimeHi = 0U;
  (*c2_b_info)[8].mFileTimeLo = 0U;
  (*c2_b_info)[8].mFileTimeHi = 0U;
  (*c2_b_info)[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c2_b_info)[9].name = "mtimes";
  (*c2_b_info)[9].dominantType = "double";
  (*c2_b_info)[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[9].fileTimeLo = 1289519692U;
  (*c2_b_info)[9].fileTimeHi = 0U;
  (*c2_b_info)[9].mFileTimeLo = 0U;
  (*c2_b_info)[9].mFileTimeHi = 0U;
  (*c2_b_info)[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c2_b_info)[10].name = "eml_scalar_eg";
  (*c2_b_info)[10].dominantType = "double";
  (*c2_b_info)[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c2_b_info)[10].fileTimeLo = 1286818796U;
  (*c2_b_info)[10].fileTimeHi = 0U;
  (*c2_b_info)[10].mFileTimeLo = 0U;
  (*c2_b_info)[10].mFileTimeHi = 0U;
  (*c2_b_info)[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c2_b_info)[11].name = "eml_refblas_xgemm";
  (*c2_b_info)[11].dominantType = "int32";
  (*c2_b_info)[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c2_b_info)[11].fileTimeLo = 1299076774U;
  (*c2_b_info)[11].fileTimeHi = 0U;
  (*c2_b_info)[11].mFileTimeLo = 0U;
  (*c2_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c2_i32 = 0; c2_i32 < 12; c2_i32++) {
    c2_r0 = &c2_info[c2_i32];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i32);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i32);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_eml_scalar_eg(SFc2_InversionInstanceStruct *chartInstance)
{
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i33;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i33, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i33;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Inversion, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Inversion), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Inversion);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_InversionInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_InversionInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Inversion_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2377109151U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1392427268U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(901560262U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1930191215U);
}

mxArray *sf_c2_Inversion_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t7GEzpUUmqMhpW89ncbhPF");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Inversion(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_Inversion\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Inversion_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_InversionInstanceStruct *chartInstance;
    chartInstance = (SFc2_InversionInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_InversionMachineNumber_,
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
          init_script_number_translation(_InversionMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_InversionMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_InversionMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,437);
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
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_u)[4];
          real_T (*c2_y)[3];
          c2_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_InversionMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "2M58aZYjpuWXqaia8NkufE";
}

static void sf_opaque_initialize_c2_Inversion(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_InversionInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_Inversion((SFc2_InversionInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Inversion(void *chartInstanceVar)
{
  enable_c2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Inversion(void *chartInstanceVar)
{
  disable_c2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Inversion(void *chartInstanceVar)
{
  sf_c2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Inversion(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Inversion((SFc2_InversionInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Inversion();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Inversion(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Inversion();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Inversion((SFc2_InversionInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Inversion(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Inversion(S);
}

static void sf_opaque_set_sim_state_c2_Inversion(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Inversion(S, st);
}

static void sf_opaque_terminate_c2_Inversion(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_InversionInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Inversion_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Inversion((SFc2_InversionInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Inversion(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Inversion((SFc2_InversionInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Inversion(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Inversion_optimization_info();
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
  ssSetChecksum0(S,(3901356304U));
  ssSetChecksum1(S,(3771401690U));
  ssSetChecksum2(S,(2603976906U));
  ssSetChecksum3(S,(2155832048U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Inversion(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Inversion(SimStruct *S)
{
  SFc2_InversionInstanceStruct *chartInstance;
  chartInstance = (SFc2_InversionInstanceStruct *)malloc(sizeof
    (SFc2_InversionInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_InversionInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Inversion;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Inversion;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_Inversion;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Inversion;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Inversion;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Inversion;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Inversion;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_Inversion;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Inversion;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Inversion;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Inversion;
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

void c2_Inversion_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Inversion(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Inversion(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Inversion(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Inversion_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
