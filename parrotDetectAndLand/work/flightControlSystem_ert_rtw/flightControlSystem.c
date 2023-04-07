/*
 * flightControlSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 4.98
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Wed Nov 23 15:36:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "rtwtypes.h"
#include "flightControlSystem_types.h"
#include "flightControlSystem_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<Root>/Control System' */
uint8_T flag_outport;                  /* '<Root>/Control System' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_flightControlSystem_T flightControlSystem_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
static RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(flightControlSystem_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (flightControlSystem_M->Timing.TaskCounters.TID[1])++;
  if ((flightControlSystem_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    flightControlSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/Geofencing error'
 *    '<S4>/estimator//Optical flow error'
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion generated from: '<S227>/Out1' incorporates:
   *  Constant: '<S227>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for atomic system:
 *    '<S355>/SqrtUsedFcn'
 *    '<S409>/SqrtUsedFcn'
 */
void flightControlSystem_SqrtUsedFcn(const real32_T rtu_u[4], boolean_T
  rtu_isSqrtUsed)
{
  int32_T i;
  real32_T rtb_P_o[4];
  real32_T rtb_P_k_tmp;
  if (rtu_isSqrtUsed) {
    for (i = 0; i < 2; i++) {
      rtb_P_k_tmp = rtu_u[i + 2];
      rtb_P_o[i] = rtb_P_k_tmp * rtu_u[2] + rtu_u[i] * rtu_u[0];
      rtb_P_o[i + 2] = rtb_P_k_tmp * rtu_u[3] + rtu_u[i] * rtu_u[1];
    }
  } else {
    for (i = 0; i < 2; i++) {
      rtb_P_o[i] = rtu_u[i];
      rtb_P_o[i + 2] = rtu_u[i + 2];
    }
  }
}

/*
 * System initialize for enable system:
 *    '<S326>/MeasurementUpdate'
 *    '<S380>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Init
  (B_MeasurementUpdate_flightControlSystem_T *localB,
   P_MeasurementUpdate_flightControlSystem_T *localP)
{
  /* SystemInitialize for Product: '<S357>/Product3' incorporates:
   *  Outport: '<S357>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;
  localB->Product3[1] = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S326>/MeasurementUpdate'
 *    '<S380>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Disable
  (B_MeasurementUpdate_flightControlSystem_T *localB,
   DW_MeasurementUpdate_flightControlSystem_T *localDW,
   P_MeasurementUpdate_flightControlSystem_T *localP)
{
  /* Disable for Product: '<S357>/Product3' incorporates:
   *  Outport: '<S357>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;
  localB->Product3[1] = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S326>/MeasurementUpdate'
 *    '<S380>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[2], real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T
  rtu_xhatkk1[2], real32_T rtu_Dk, real32_T rtu_uk,
  B_MeasurementUpdate_flightControlSystem_T *localB,
  DW_MeasurementUpdate_flightControlSystem_T *localDW,
  P_MeasurementUpdate_flightControlSystem_T *localP)
{
  real32_T rtb_Sum;

  /* Outputs for Enabled SubSystem: '<S326>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S357>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Sum: '<S357>/Sum' incorporates:
     *  Product: '<S357>/C[k]*xhat[k|k-1]'
     *  Product: '<S357>/D[k]*u[k]'
     *  Sum: '<S357>/Add1'
     */
    rtb_Sum = rtu_yk - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1[1])
                        + rtu_Dk * rtu_uk);

    /* Product: '<S357>/Product3' */
    localB->Product3[0] = rtu_Lk[0] * rtb_Sum;
    localB->Product3[1] = rtu_Lk[1] * rtb_Sum;
  } else if (localDW->MeasurementUpdate_MODE) {
    flightControlSystem_MeasurementUpdate_Disable(localB, localDW, localP);
  }

  /* End of Outputs for SubSystem: '<S326>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S333>/Enabled Subsystem'
 *    '<S387>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Init
  (B_EnabledSubsystem_flightControlSystem_T *localB,
   P_EnabledSubsystem_flightControlSystem_T *localP)
{
  /* SystemInitialize for Product: '<S359>/Product2' incorporates:
   *  Outport: '<S359>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;
  localB->Product2[1] = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S333>/Enabled Subsystem'
 *    '<S387>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Disable
  (B_EnabledSubsystem_flightControlSystem_T *localB,
   DW_EnabledSubsystem_flightControlSystem_T *localDW,
   P_EnabledSubsystem_flightControlSystem_T *localP)
{
  /* Disable for Product: '<S359>/Product2' incorporates:
   *  Outport: '<S359>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;
  localB->Product2[1] = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S333>/Enabled Subsystem'
 *    '<S387>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[2], const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_flightControlSystem_T *localB,
  DW_EnabledSubsystem_flightControlSystem_T *localDW,
  P_EnabledSubsystem_flightControlSystem_T *localP)
{
  real32_T rtb_Add1;

  /* Outputs for Enabled SubSystem: '<S333>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S359>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S359>/Add1' incorporates:
     *  Product: '<S359>/Product'
     */
    rtb_Add1 = rtu_yk - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1[1]);

    /* Product: '<S359>/Product2' */
    localB->Product2[0] = rtu_Mk[0] * rtb_Add1;
    localB->Product2[1] = rtu_Mk[1] * rtb_Add1;
  } else if (localDW->EnabledSubsystem_MODE) {
    flightControlSystem_EnabledSubsystem_Disable(localB, localDW, localP);
  }

  /* End of Outputs for SubSystem: '<S333>/Enabled Subsystem' */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* System initialize for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Init(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  P_ControlSystem_flightControlSystem_T *localP,
  ZCE_ControlSystem_flightControlSystem_T *localZCE)
{
  int32_T i;

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Control System/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estimatedStates",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_DSTATE[1] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S236>/Delay2' */
  localDW->Delay2_DSTATE = localP->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S240>/MemoryX' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteIntegrator: '<S304>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S306>/MemoryX' */
  localDW->icLoad_p = true;

  /* InitializeConditions for DiscreteFir: '<S238>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = localP->FIR_IMUaccel_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFir: '<S238>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S360>/MemoryX' */
  localDW->icLoad_k = true;

  /* InitializeConditions for DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localP->LPFFcutoff40Hz1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localP->LPFFcutoff40Hz_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S238>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = localP->IIR_IMUgyro_r_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S238>/IIR_IMUgyro_r' */

  /* InitializeConditions for Sum: '<S419>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S417>/Output'
   */
  localDW->Output_DSTATE = localP->Output_InitialCondition;

  /* InitializeConditions for Delay: '<S426>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for Sum: '<S500>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S499>/Output'
   */
  localDW->Output_DSTATE_n = localP->Output_InitialCondition_f;

  /* InitializeConditions for DiscreteFilter: '<S425>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = localP->IIRgyroz_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S425>/IIRgyroz' */

  /* InitializeConditions for Switch: '<S5>/Switch' incorporates:
   *  Delay: '<S5>/Delay1'
   */
  localDW->Delay1_DSTATE = localP->Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S433>/UD' incorporates:
   *  Sum: '<S433>/Diff'
   */
  localDW->UD_DSTATE[0] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S421>/Delay' */
  localDW->Delay_DSTATE_a[0] = localP->Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[0] = localP->Delay1_InitialCondition_p;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[0] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_d[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;

  /* InitializeConditions for UnitDelay: '<S433>/UD' incorporates:
   *  Sum: '<S433>/Diff'
   */
  localDW->UD_DSTATE[1] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S421>/Delay' */
  localDW->Delay_DSTATE_a[1] = localP->Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[1] = localP->Delay1_InitialCondition_p;

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Integrator' */
  localDW->Integrator_DSTATE[1] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_d[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;

  /* InitializeConditions for Sum: '<S15>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a = localP->Output_InitialCondition_fi;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_c = localP->DiscreteTimeIntegrator_IC_h;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d = localP->DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for Sum: '<S232>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S226>/Output'
   */
  localDW->Output_DSTATE_g = localP->Output_InitialCondition_h;

  /* InitializeConditions for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = localP->DelayOneStep_InitialCondition;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Triggered SubSystem: '<S234>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S235>/X' incorporates:
   *  Outport: '<S235>/X'
   */
  localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0 = localP->X_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S235>/Y' incorporates:
   *  Outport: '<S235>/Y'
   */
  localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0 = localP->Y_Y0;
  localZCE->TriggeredSubsystem_Trig_ZCE_g = ZERO_ZCSIG;

  /* End of SystemInitialize for SubSystem: '<S234>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S262>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S292>/Product3' incorporates:
   *  Outport: '<S292>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S262>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S268>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S294>/Product2' incorporates:
   *  Outport: '<S294>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S268>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S262>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S292>/Product3' incorporates:
   *  Outport: '<S292>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[1] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S262>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S268>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S294>/Product2' incorporates:
   *  Outport: '<S294>/deltax'
   */
  localB->Product2[1] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S268>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S326>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of SystemInitialize for SubSystem: '<S326>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S333>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_d,
    &localP->EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S333>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S380>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_j,
    &localP->MeasurementUpdate_j);

  /* End of SystemInitialize for SubSystem: '<S380>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S387>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_n,
    &localP->EnabledSubsystem_n);

  /* End of SystemInitialize for SubSystem: '<S387>/Enabled Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S414>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S418>/In1' incorporates:
   *  Outport: '<S418>/Out1'
   */
  localB->In1 = localP->Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S414>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S464>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S495>/Product3' incorporates:
   *  Outport: '<S495>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[0] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S464>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S471>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S497>/Product2' incorporates:
   *  Outport: '<S497>/deltax'
   */
  localB->Product2_k[0] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S471>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S464>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S495>/Product3' incorporates:
   *  Outport: '<S495>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[1] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S464>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S471>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S497>/Product2' incorporates:
   *  Outport: '<S497>/deltax'
   */
  localB->Product2_k[1] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S471>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S464>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S495>/Product3' incorporates:
   *  Outport: '<S495>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[2] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S464>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S471>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S497>/Product2' incorporates:
   *  Outport: '<S497>/deltax'
   */
  localB->Product2_k[2] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S471>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S464>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S495>/Product3' incorporates:
   *  Outport: '<S495>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[3] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S464>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S471>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S497>/Product2' incorporates:
   *  Outport: '<S497>/deltax'
   */
  localB->Product2_k[3] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S471>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, boolean_T rtu_VisionbasedData,
  B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  P_ControlSystem_flightControlSystem_T *localP,
  ZCE_ControlSystem_flightControlSystem_T *localZCE)
{
  real32_T rtb_MathFunction_tmp;
  real32_T rtb_MathFunction_tmp_0;
  real32_T rtb_MathFunction_tmp_1;
  real32_T rtb_MathFunction_tmp_2;
  real32_T rtb_MathFunction_tmp_3;
  real32_T rtb_MathFunction_tmp_tmp;
  int8_T rtb_Add_g_0;
  int8_T rtb_DeadZone_0;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_fc;
  boolean_T rtb_Compare_p;
  boolean_T rtb_DataTypeConversionEnable_e;
  boolean_T rtb_DataTypeConversionEnable_g;

  /* DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  if (localP->controlModePosVsOrient_Value &&
      (localDW->SimplyIntegrateVelocity_PrevResetState <= 0)) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] =
      localP->SimplyIntegrateVelocity_IC;
    localDW->SimplyIntegrateVelocity_DSTATE[1] =
      localP->SimplyIntegrateVelocity_IC;
  }

  /* RelationalOperator: '<S243>/Compare' incorporates:
   *  Constant: '<S243>/Constant'
   *  Delay: '<S236>/Delay2'
   */
  localB->Compare = (localDW->Delay2_DSTATE > localP->outlierBelowFloor_const);

  /* Delay: '<S240>/MemoryX' incorporates:
   *  Constant: '<S240>/X0'
   *  DataTypeConversion: '<S240>/DataTypeConversionReset'
   *  Reshape: '<S240>/ReshapeX0'
   */
  localDW->icLoad = (localB->Compare || localDW->icLoad);
  if (localDW->icLoad) {
    localDW->MemoryX_DSTATE[0] = localP->X0_Value[0];
    localDW->MemoryX_DSTATE[1] = localP->X0_Value[1];
  }

  /* Gain: '<S236>/invertzaxisGain' */
  localB->invertzaxisGain = (real_T)localP->invertzaxisGain_Gain *
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* Saturate: '<S241>/SaturationSonar' */
  if (localB->invertzaxisGain > -flightControlSystem_P.Sensors.altSensorMin) {
    localB->sonarFilter_IIR_tmp = -flightControlSystem_P.Sensors.altSensorMin;
  } else if (localB->invertzaxisGain < localP->SaturationSonar_LowerSat) {
    localB->sonarFilter_IIR_tmp = localP->SaturationSonar_LowerSat;
  } else {
    localB->sonarFilter_IIR_tmp = localB->invertzaxisGain;
  }

  /* End of Saturate: '<S241>/SaturationSonar' */

  /* Sum: '<S241>/Add' incorporates:
   *  Delay: '<S236>/Delay2'
   */
  localB->u_h = localDW->Delay2_DSTATE - localB->sonarFilter_IIR_tmp;

  /* DataTypeConversion: '<S238>/Data Type Conversion' */
  for (localB->i = 0; localB->i < 8; localB->i++) {
    localB->DataTypeConversion_g[localB->i] = rtu_Sensors->
      SensorCalibration[localB->i];
  }

  /* End of DataTypeConversion: '<S238>/Data Type Conversion' */

  /* Sum: '<S238>/Sum2' */
  localB->DiscreteTimeIntegrator_k5 =
    rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
    localB->DataTypeConversion_g[6];

  /* DiscreteFilter: '<S241>/pressureFilter_IIR' incorporates:
   *  Gain: '<S236>/prsToAltGain'
   */
  localB->DiscreteTimeIntegrator_k5 = (((localP->prsToAltGain_Gain *
    localB->DiscreteTimeIntegrator_k5 - localDW->pressureFilter_IIR_states[0] *
    localP->pressureFilter_IIR_DenCoef[1]) - localDW->pressureFilter_IIR_states
    [1] * localP->pressureFilter_IIR_DenCoef[2]) -
    localDW->pressureFilter_IIR_states[2] * localP->pressureFilter_IIR_DenCoef[3])
    / localP->pressureFilter_IIR_DenCoef[0];
  localB->numAccum_d = ((localP->pressureFilter_IIR_NumCoef[0] *
    localB->DiscreteTimeIntegrator_k5 + localDW->pressureFilter_IIR_states[0] *
    localP->pressureFilter_IIR_NumCoef[1]) + localDW->pressureFilter_IIR_states
                        [1] * localP->pressureFilter_IIR_NumCoef[2]) +
    localDW->pressureFilter_IIR_states[2] * localP->pressureFilter_IIR_NumCoef[3];

  /* RelationalOperator: '<S296>/Compare' incorporates:
   *  Abs: '<S241>/Absestdiff1'
   *  Constant: '<S296>/Constant'
   *  Delay: '<S236>/Delay2'
   *  DiscreteFilter: '<S241>/pressureFilter_IIR'
   *  Sum: '<S241>/Add1'
   */
  rtb_Compare_p = (fabs(localB->numAccum_d - localDW->Delay2_DSTATE) >=
                   localP->currentEstimateVeryOffFromPressure_const);

  /* DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localB->sonarFilter_IIR_tmp = (((localB->invertzaxisGain -
    localDW->sonarFilter_IIR_states[0] * localP->sonarFilter_IIR_DenCoef[1]) -
    localDW->sonarFilter_IIR_states[1] * localP->sonarFilter_IIR_DenCoef[2]) -
    localDW->sonarFilter_IIR_states[2] * localP->sonarFilter_IIR_DenCoef[3]) /
    localP->sonarFilter_IIR_DenCoef[0];

  /* Sum: '<S241>/Add2' incorporates:
   *  Delay: '<S236>/Delay2'
   *  DiscreteFilter: '<S241>/sonarFilter_IIR'
   */
  localDW->Delay2_DSTATE = (((localP->sonarFilter_IIR_NumCoef[0] *
    localB->sonarFilter_IIR_tmp + localDW->sonarFilter_IIR_states[0] *
    localP->sonarFilter_IIR_NumCoef[1]) + localDW->sonarFilter_IIR_states[1] *
    localP->sonarFilter_IIR_NumCoef[2]) + localDW->sonarFilter_IIR_states[2] *
    localP->sonarFilter_IIR_NumCoef[3]) - localDW->Delay2_DSTATE;

  /* Abs: '<S241>/Absestdiff2' incorporates:
   *  Delay: '<S236>/Delay2'
   */
  localDW->Delay2_DSTATE = fabs(localDW->Delay2_DSTATE);

  /* Logic: '<S241>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S241>/Absestdiff'
   *  Constant: '<S295>/Constant'
   *  Constant: '<S297>/Constant'
   *  Constant: '<S298>/Constant'
   *  Delay: '<S236>/Delay2'
   *  Logic: '<S241>/NOT'
   *  Logic: '<S241>/findingoutliers'
   *  Logic: '<S241>/newupdateneeded'
   *  RelationalOperator: '<S295>/Compare'
   *  RelationalOperator: '<S297>/Compare'
   *  RelationalOperator: '<S298>/Compare'
   */
  localB->nicemeasurementornewupdateneeded = ((fabs(localB->u_h) <=
    localP->outlierJump_const) && (localB->invertzaxisGain <
    -flightControlSystem_P.Sensors.altSensorMin) && ((!rtb_Compare_p) ||
    (!(localDW->Delay2_DSTATE >= localP->currentStateVeryOffsonarflt_const))));

  /* Outputs for Enabled SubSystem: '<S268>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S294>/Enable'
   */
  /* DataTypeConversion: '<S240>/DataTypeConversionEnable' */
  if (localB->nicemeasurementornewupdateneeded) {
    localDW->EnabledSubsystem_MODE_i = true;

    /* Sum: '<S294>/Add1' incorporates:
     *  Constant: '<S240>/C'
     *  Delay: '<S240>/MemoryX'
     *  Product: '<S294>/Product'
     *  Reshape: '<S240>/Reshapey'
     */
    localB->u_h = localB->invertzaxisGain - (localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]);

    /* Product: '<S294>/Product2' incorporates:
     *  Constant: '<S244>/KalmanGainM'
     *  DataTypeConversion: '<S285>/Conversion'
     */
    localB->Product2[0] = localP->KalmanGainM_Value[0] * localB->u_h;
    localB->Product2[1] = localP->KalmanGainM_Value[1] * localB->u_h;
  } else if (localDW->EnabledSubsystem_MODE_i) {
    /* Disable for Product: '<S294>/Product2' incorporates:
     *  Outport: '<S294>/deltax'
     */
    localB->Product2[0] = localP->deltax_Y0;
    localB->Product2[1] = localP->deltax_Y0;
    localDW->EnabledSubsystem_MODE_i = false;
  }

  /* End of Outputs for SubSystem: '<S268>/Enabled Subsystem' */

  /* Sum: '<S268>/Add' incorporates:
   *  Delay: '<S240>/MemoryX'
   */
  localB->rtb_Add_a_idx_0 = localB->Product2[0] + localDW->MemoryX_DSTATE[0];
  localB->rtb_Add_a_idx_1 = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* Delay: '<S306>/MemoryX' incorporates:
   *  Constant: '<S306>/X0'
   *  Reshape: '<S306>/ReshapeX0'
   */
  if (localDW->icLoad_p) {
    localDW->MemoryX_DSTATE_g[0] = localP->X0_Value_i[0];
    localDW->MemoryX_DSTATE_g[1] = localP->X0_Value_i[1];
  }

  /* Delay: '<S306>/MemoryX' */
  localB->rtb_MemoryX_e_f[0] = localDW->MemoryX_DSTATE_g[0];
  localB->rtb_MemoryX_e_f[1] = localDW->MemoryX_DSTATE_g[1];

  /* Bias: '<S238>/Assuming that the  preflight calibration was done at level orientation' */
  for (localB->i = 0; localB->i < 6; localB->i++) {
    localB->Sum1_p[localB->i] = localB->DataTypeConversion_g[localB->i] +
      localP->
      Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[localB->i];
  }

  /* End of Bias: '<S238>/Assuming that the  preflight calibration was done at level orientation' */

  /* Sum: '<S238>/Sum1' */
  localB->Sum1_p_c[0] = rtu_Sensors->HALSensors.HAL_acc_SI.x - localB->Sum1_p[0];
  localB->Sum1_p_c[1] = rtu_Sensors->HALSensors.HAL_acc_SI.y - localB->Sum1_p[1];
  localB->Sum1_p_c[2] = rtu_Sensors->HALSensors.HAL_acc_SI.z - localB->Sum1_p[2];
  localB->Sum1_p_c[3] = rtu_Sensors->HALSensors.HAL_gyro_SI.x - localB->Sum1_p[3];
  localB->Sum1_p_c[4] = rtu_Sensors->HALSensors.HAL_gyro_SI.y - localB->Sum1_p[4];
  localB->Sum1_p_c[5] = rtu_Sensors->HALSensors.HAL_gyro_SI.z - localB->Sum1_p[5];
  for (localB->j = 0; localB->j < 6; localB->j++) {
    /* Gain: '<S238>/inverseIMU_gain' */
    localB->Sum1_p_c[localB->j] *= localP->inverseIMU_gain_Gain[localB->j];
  }

  /* DiscreteFir: '<S238>/FIR_IMUaccel' */
  localB->Abs = localB->Sum1_p_c[0] * localP->FIR_IMUaccel_Coefficients[0];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = localB->Abs;

  /* Math: '<S305>/Math Function' incorporates:
   *  Constant: '<S305>/Constant'
   *  DiscreteFir: '<S238>/FIR_IMUaccel'
   */
  localB->rtb_Subtract_p_idx_2 = (real32_T)floor(localP->Constant_Value_h);
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       localB->rtb_Subtract_p_idx_2)) {
    localB->rtb_Subtract_p_idx_0 = -rt_powf_snf(-localB->Abs,
      localP->Constant_Value_h);
  } else {
    localB->rtb_Subtract_p_idx_0 = rt_powf_snf(localB->Abs,
      localP->Constant_Value_h);
  }

  /* DiscreteFir: '<S238>/FIR_IMUaccel' */
  localB->Abs = localP->FIR_IMUaccel_Coefficients[0] * localB->Sum1_p_c[1];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = localB->Abs;

  /* Math: '<S305>/Math Function' incorporates:
   *  Constant: '<S305>/Constant'
   *  DiscreteFir: '<S238>/FIR_IMUaccel'
   */
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       localB->rtb_Subtract_p_idx_2)) {
    localB->rtb_Subtract_p_idx_1 = -rt_powf_snf(-localB->Abs,
      localP->Constant_Value_h);
  } else {
    localB->rtb_Subtract_p_idx_1 = rt_powf_snf(localB->Abs,
      localP->Constant_Value_h);
  }

  /* DiscreteFir: '<S238>/FIR_IMUaccel' */
  localB->Abs = localP->FIR_IMUaccel_Coefficients[0] * localB->Sum1_p_c[2];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = localB->Abs;

  /* Gain: '<S302>/Gain2' */
  localB->Add_i = localP->Gain2_Gain * localB->FIR_IMUaccel[0];

  /* Trigonometry: '<S302>/Trigonometric Function1' */
  if (localB->Add_i > 1.0F) {
    localB->Add_i = 1.0F;
  } else if (localB->Add_i < -1.0F) {
    localB->Add_i = -1.0F;
  }

  /* Trigonometry: '<S302>/Trigonometric Function1' */
  localB->TrigonometricFunction1 = (real32_T)asin(localB->Add_i);

  /* Reshape: '<S306>/Reshapey' */
  localB->rtb_Reshapey_f_j = localB->TrigonometricFunction1;

  /* Math: '<S305>/Math Function' incorporates:
   *  Constant: '<S305>/Constant'
   *  DiscreteFir: '<S238>/FIR_IMUaccel'
   */
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       localB->rtb_Subtract_p_idx_2)) {
    localB->Add_i = -rt_powf_snf(-localB->Abs, localP->Constant_Value_h);
  } else {
    localB->Add_i = rt_powf_snf(localB->Abs, localP->Constant_Value_h);
  }

  /* Sqrt: '<S305>/Sqrt' incorporates:
   *  Sum: '<S305>/Sum of Elements'
   */
  localB->Add_i = (real32_T)sqrt((localB->rtb_Subtract_p_idx_0 +
    localB->rtb_Subtract_p_idx_1) + localB->Add_i);

  /* Logic: '<S237>/Logical Operator' incorporates:
   *  Constant: '<S300>/Constant'
   *  Constant: '<S301>/Constant'
   *  RelationalOperator: '<S300>/Compare'
   *  RelationalOperator: '<S301>/Compare'
   */
  localB->LogicalOperator = (int16_T)((localB->Add_i >
    localP->CompareToConstant_const) && (localB->Add_i <
    localP->CompareToConstant1_const));

  /* DataTypeConversion: '<S306>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_g = (localB->LogicalOperator != 0);

  /* DataTypeConversion: '<S350>/Conversion' incorporates:
   *  Constant: '<S307>/KalmanGainM'
   */
  localB->rtb_Conversion_g_c[0] = (real32_T)localP->KalmanGainM_Value_l[0];
  localB->rtb_Conversion_g_c[1] = (real32_T)localP->KalmanGainM_Value_l[1];

  /* Outputs for Enabled SubSystem: '<S333>/Enabled Subsystem' */
  /* Constant: '<S306>/C' */
  flightControlSystem_EnabledSubsystem(rtb_DataTypeConversionEnable_g,
    localB->rtb_Conversion_g_c, localP->C_Value_h, localB->rtb_Reshapey_f_j,
    localB->rtb_MemoryX_e_f, &localB->EnabledSubsystem_d,
    &localDW->EnabledSubsystem_d, &localP->EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S333>/Enabled Subsystem' */

  /* Delay: '<S360>/MemoryX' incorporates:
   *  Constant: '<S360>/X0'
   *  Reshape: '<S360>/ReshapeX0'
   */
  if (localDW->icLoad_k) {
    localDW->MemoryX_DSTATE_m[0] = localP->X0_Value_iy[0];
    localDW->MemoryX_DSTATE_m[1] = localP->X0_Value_iy[1];
  }

  /* Trigonometry: '<S303>/Trigonometric Function' incorporates:
   *  DiscreteFir: '<S238>/FIR_IMUaccel'
   *  Product: '<S303>/Divide'
   */
  localB->TrigonometricFunction = (real32_T)atan(localB->FIR_IMUaccel[1] /
    localB->Abs);

  /* Reshape: '<S360>/Reshapey' */
  localB->rtb_Reshapey_g_d = localB->TrigonometricFunction;

  /* DataTypeConversion: '<S360>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_e = (localB->LogicalOperator != 0);

  /* Delay: '<S360>/MemoryX' */
  localB->rtb_MemoryX_g_g[0] = localDW->MemoryX_DSTATE_m[0];

  /* DataTypeConversion: '<S404>/Conversion' incorporates:
   *  Constant: '<S361>/KalmanGainM'
   */
  localB->rtb_Conversion_i_g[0] = (real32_T)localP->KalmanGainM_Value_a[0];

  /* Delay: '<S360>/MemoryX' */
  localB->rtb_MemoryX_g_g[1] = localDW->MemoryX_DSTATE_m[1];

  /* DataTypeConversion: '<S404>/Conversion' incorporates:
   *  Constant: '<S361>/KalmanGainM'
   */
  localB->rtb_Conversion_i_g[1] = (real32_T)localP->KalmanGainM_Value_a[1];

  /* Outputs for Enabled SubSystem: '<S387>/Enabled Subsystem' */
  /* Constant: '<S360>/C' */
  flightControlSystem_EnabledSubsystem(rtb_DataTypeConversionEnable_e,
    localB->rtb_Conversion_i_g, localP->C_Value_i, localB->rtb_Reshapey_g_d,
    localB->rtb_MemoryX_g_g, &localB->EnabledSubsystem_n,
    &localDW->EnabledSubsystem_n, &localP->EnabledSubsystem_n);

  /* End of Outputs for SubSystem: '<S387>/Enabled Subsystem' */

  /* DataTypeConversion: '<S237>/Data Type Conversion3' incorporates:
   *  Sum: '<S333>/Add'
   *  Sum: '<S387>/Add'
   */
  localB->rtb_DataTypeConversion3_idx_1 = localB->EnabledSubsystem_d.Product2[0]
    + localB->rtb_MemoryX_e_f[0];
  localB->rtb_DataTypeConversion3_idx_2 = localB->EnabledSubsystem_n.Product2[0]
    + localB->rtb_MemoryX_g_g[0];

  /* DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz1' */
  localB->Add_i = (localB->Sum1_p_c[3] - localP->LPFFcutoff40Hz1_DenCoef[1] *
                   localDW->LPFFcutoff40Hz1_states) /
    localP->LPFFcutoff40Hz1_DenCoef[0];

  /* DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz1' */
  localB->p = localP->LPFFcutoff40Hz1_NumCoef[0] * localB->Add_i +
    localP->LPFFcutoff40Hz1_NumCoef[1] * localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz' */
  localB->LPFFcutoff40Hz_tmp = (localB->Sum1_p_c[4] -
    localP->LPFFcutoff40Hz_DenCoef[1] * localDW->LPFFcutoff40Hz_states) /
    localP->LPFFcutoff40Hz_DenCoef[0];

  /* DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz' */
  localB->q = localP->LPFFcutoff40Hz_NumCoef[0] * localB->LPFFcutoff40Hz_tmp +
    localP->LPFFcutoff40Hz_NumCoef[1] * localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S238>/IIR_IMUgyro_r' */
  localB->denAccum = localB->Sum1_p_c[5];
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->denAccum -= localP->IIR_IMUgyro_r_DenCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  localB->IIR_IMUgyro_r_tmp = localB->denAccum / localP->IIR_IMUgyro_r_DenCoef[0];
  localB->numAccum = localP->IIR_IMUgyro_r_NumCoef[0] *
    localB->IIR_IMUgyro_r_tmp;
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->numAccum += localP->IIR_IMUgyro_r_NumCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S416>/Constant'
   *  UnitDelay: '<S417>/Output'
   */
  rtb_Compare_p = (localDW->Output_DSTATE == localP->CompareToConstant_const_l);

  /* Outputs for Triggered SubSystem: '<S414>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S418>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == POS_ZCSIG) != (int32_T)
       rtb_Compare_p) && (localZCE->TriggeredSubsystem_Trig_ZCE !=
                          UNINITIALIZED_ZCSIG)) {
    /* SignalConversion generated from: '<S418>/In1' */
    localB->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare_p;

  /* End of Outputs for SubSystem: '<S414>/Triggered Subsystem' */

  /* ManualSwitch: '<S414>/Disable temperature compensation' incorporates:
   *  Constant: '<S414>/Constant'
   *  Gain: '<S414>/Gain'
   */
  if (localP->Disabletemperaturecompensation_CurrentSetting == 1) {
    /* Sum: '<S414>/Subtract' */
    localB->Subtract = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature -
      localB->In1;
    localB->u_h = localP->Gain_Gain_k * localB->Subtract;
  } else {
    localB->u_h = localP->Constant_Value;
  }

  /* End of ManualSwitch: '<S414>/Disable temperature compensation' */

  /* Sum: '<S414>/Subtract1' incorporates:
   *  DataTypeConversion: '<S414>/Data Type Conversion1'
   *  DiscreteFilter: '<S238>/IIR_IMUgyro_r'
   */
  localB->Subtract = localB->numAccum - (real32_T)localB->u_h;

  /* Sum: '<S237>/Subtract' incorporates:
   *  Constant: '<S304>/Constant'
   *  Sum: '<S333>/Add'
   *  Sum: '<S387>/Add'
   */
  localB->rtb_Subtract_p_idx_0 = localB->p -
    (localB->EnabledSubsystem_n.Product2[1] + localB->rtb_MemoryX_g_g[1]);
  localB->rtb_Subtract_p_idx_1 = localB->q -
    (localB->EnabledSubsystem_d.Product2[1] + localB->rtb_MemoryX_e_f[1]);
  localB->rtb_Subtract_p_idx_2 = localB->Subtract - localP->Constant_Value_j;

  /* Delay: '<S426>/MemoryX' incorporates:
   *  Constant: '<S426>/X0'
   *  Reshape: '<S426>/ReshapeX0'
   */
  if (localDW->icLoad_o) {
    localDW->MemoryX_DSTATE_l[0] = localP->X0_Value_c[0];
    localDW->MemoryX_DSTATE_l[1] = localP->X0_Value_c[1];
    localDW->MemoryX_DSTATE_l[2] = localP->X0_Value_c[2];
    localDW->MemoryX_DSTATE_l[3] = localP->X0_Value_c[3];
  }

  /* Switch: '<S427>/Switch' incorporates:
   *  Constant: '<S498>/Constant'
   *  Gain: '<S427>/opticalFlowErrorCorrect'
   *  RelationalOperator: '<S498>/Compare'
   *  UnitDelay: '<S499>/Output'
   */
  if (localDW->Output_DSTATE_n < localP->CompareToConstant_const_h) {
    localB->u_l[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    localB->u_l[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1];
    localB->u_l[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    /* Gain: '<S427>/Gain' incorporates:
     *  DataTypeConversion: '<S236>/Data Type Conversion'
     *  Reshape: '<S240>/Reshapexhat'
     */
    localB->Gain_m = localP->Gain_Gain_p * (real32_T)localB->rtb_Add_a_idx_0;

    /* Product: '<S427>/ ' */
    localB->u_l[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      localB->Gain_m;
    localB->u_l[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      localB->Gain_m;
    localB->u_l[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2] *
      localB->Gain_m;
    localB->u_l[0] *= localP->opticalFlowErrorCorrect_Gain;
    localB->u_l[1] *= localP->opticalFlowErrorCorrect_Gain;
    localB->u_l[2] *= localP->opticalFlowErrorCorrect_Gain;
  }

  /* End of Switch: '<S427>/Switch' */

  /* Abs: '<S424>/Abs' incorporates:
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  Reshape: '<S240>/Reshapexhat'
   */
  localB->Gain_m = (real32_T)fabs((real32_T)localB->rtb_Add_a_idx_0);

  /* DataTypeConversion: '<S424>/Data Type Conversion' incorporates:
   *  Gain: '<S424>/Gain1'
   *  Product: '<S424>/prod'
   */
  localB->Integrator_l[0] = localB->Gain_m * localB->rtb_Subtract_p_idx_1 *
    localP->Gain1_Gain;
  localB->Integrator_l[1] = localB->Gain_m * localB->rtb_Subtract_p_idx_0;

  /* SignalConversion generated from: '<S425>/IIRgyroz' */
  localB->Add_g[0] = localB->p;
  localB->Add_g[1] = localB->q;
  for (localB->i = 0; localB->i < 2; localB->i++) {
    /* Sum: '<S421>/angular velocity compensation' */
    localB->Gain_m = localB->u_l[localB->i];

    /* Sum: '<S421>/angular velocity compensation' */
    localB->angularvelocitycompensation[localB->i] = localB->Gain_m +
      localB->Integrator_l[localB->i];

    /* DiscreteFilter: '<S425>/IIRgyroz' */
    localB->memOffset = localB->i * 5;
    localB->denAccum = localB->Add_g[localB->i];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      localB->denAccum -= localDW->IIRgyroz_states[localB->memOffset + localB->j]
        * localP->IIRgyroz_DenCoef[localB->denIdx];
      localB->denIdx++;
    }

    localB->denAccum /= localP->IIRgyroz_DenCoef[0];
    localB->numAccum = localP->IIRgyroz_NumCoef[0] * localB->denAccum;
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      localB->numAccum += localDW->IIRgyroz_states[localB->memOffset + localB->j]
        * localP->IIRgyroz_NumCoef[localB->denIdx];
      localB->denIdx++;
    }

    /* SampleTimeMath: '<S433>/TSamp' incorporates:
     *  DiscreteFilter: '<S425>/IIRgyroz'
     *
     * About '<S433>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->rtb_TSamp_d = localB->numAccum * localP->TSamp_WtEt;

    /* Sum: '<S433>/Diff' incorporates:
     *  UnitDelay: '<S433>/UD'
     */
    localDW->UD_DSTATE[localB->i] = localB->rtb_TSamp_d - localDW->
      UD_DSTATE[localB->i];

    /* DiscreteFilter: '<S425>/IIRgyroz' */
    localB->IIRgyroz_tmp[localB->i] = localB->denAccum;

    /* SampleTimeMath: '<S433>/TSamp'
     *
     * About '<S433>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp[localB->i] = localB->rtb_TSamp_d;

    /* DiscreteFilter: '<S425>/IIRgyroz' incorporates:
     *  Delay: '<S421>/Delay'
     *  Sum: '<S425>/Add'
     */
    localB->Integrator_l[localB->i] = localB->Gain_m - localDW->
      Delay_DSTATE_a[localB->i];
  }

  /* Abs: '<S425>/Abs' incorporates:
   *  Abs: '<S425>/Abs4'
   */
  localB->Gain_m = (real32_T)fabs(localB->p);

  /* Abs: '<S425>/Abs1' incorporates:
   *  Abs: '<S425>/Abs5'
   */
  localB->denAccum = (real32_T)fabs(localB->q);

  /* Logic: '<S425>/Logical Operator3' incorporates:
   *  Abs: '<S425>/Abs'
   *  Abs: '<S425>/Abs1'
   *  Abs: '<S425>/Abs2'
   *  Abs: '<S425>/Abs3'
   *  Abs: '<S425>/Abs6'
   *  Abs: '<S425>/Abs7'
   *  Abs: '<S425>/Abs8'
   *  Abs: '<S425>/Abs9'
   *  Constant: '<S434>/Constant'
   *  Constant: '<S435>/Constant'
   *  Constant: '<S436>/Constant'
   *  Constant: '<S437>/Constant'
   *  Constant: '<S438>/Constant'
   *  Constant: '<S439>/Constant'
   *  Constant: '<S440>/Constant'
   *  Constant: '<S441>/Constant'
   *  Constant: '<S442>/Constant'
   *  Constant: '<S443>/Constant'
   *  Constant: '<S444>/Constant'
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  Logic: '<S425>/Logical Operator'
   *  Logic: '<S425>/Logical Operator1'
   *  Logic: '<S425>/Logical Operator2'
   *  RelationalOperator: '<S434>/Compare'
   *  RelationalOperator: '<S435>/Compare'
   *  RelationalOperator: '<S436>/Compare'
   *  RelationalOperator: '<S437>/Compare'
   *  RelationalOperator: '<S438>/Compare'
   *  RelationalOperator: '<S439>/Compare'
   *  RelationalOperator: '<S440>/Compare'
   *  RelationalOperator: '<S441>/Compare'
   *  RelationalOperator: '<S442>/Compare'
   *  RelationalOperator: '<S443>/Compare'
   *  RelationalOperator: '<S444>/Compare'
   *  Reshape: '<S240>/Reshapexhat'
   */
  localB->LogicalOperator3 = (((((real32_T)fabs
    (localB->rtb_DataTypeConversion3_idx_1) <= localP->maxp_const) && ((real32_T)
    fabs(localB->rtb_DataTypeConversion3_idx_2) <= localP->maxq_const) &&
    (localB->Gain_m <= localP->maxw1_const) && (localB->denAccum <=
    localP->maxw2_const) && ((real32_T)fabs(localDW->UD_DSTATE[0]) <=
    localP->maxdw1_const) && ((real32_T)fabs(localDW->UD_DSTATE[1]) <=
    localP->maxdw2_const)) || ((localB->Gain_m <= localP->maxp2_const) &&
    (localB->denAccum <= localP->maxq2_const))) && ((real32_T)fabs
    (localB->Integrator_l[0]) <= localP->maxw3_const) && ((real32_T)fabs
    (localB->Integrator_l[1]) <= localP->maxw4_const) && ((real32_T)
    localB->rtb_Add_a_idx_0 <= localP->minHeightforOF_const));

  /* Outputs for Enabled SubSystem: '<S471>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S497>/Enable'
   */
  /* DataTypeConversion: '<S426>/DataTypeConversionEnable' */
  if (localB->LogicalOperator3) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S497>/Add1' incorporates:
     *  Constant: '<S426>/C'
     *  Delay: '<S426>/MemoryX'
     *  Product: '<S497>/Product'
     *  Reshape: '<S426>/Reshapey'
     */
    for (localB->j = 0; localB->j < 2; localB->j++) {
      localB->Add_g[localB->j] = localB->angularvelocitycompensation[localB->j]
        - (((localP->C_Value_i2[localB->j + 2] * localDW->MemoryX_DSTATE_l[1] +
             localP->C_Value_i2[localB->j] * localDW->MemoryX_DSTATE_l[0]) +
            localP->C_Value_i2[localB->j + 4] * localDW->MemoryX_DSTATE_l[2]) +
           localP->C_Value_i2[localB->j + 6] * localDW->MemoryX_DSTATE_l[3]);
    }

    /* End of Sum: '<S497>/Add1' */
    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S497>/Product2' incorporates:
       *  Constant: '<S445>/KalmanGainM'
       *  DataTypeConversion: '<S488>/Conversion'
       */
      localB->Product2_k[localB->j] = 0.0F;
      localB->Product2_k[localB->j] += (real32_T)localP->
        KalmanGainM_Value_i[localB->j] * localB->Add_g[0];
      localB->Product2_k[localB->j] += (real32_T)localP->
        KalmanGainM_Value_i[localB->j + 4] * localB->Add_g[1];
    }
  } else if (localDW->EnabledSubsystem_MODE) {
    /* Disable for Product: '<S497>/Product2' incorporates:
     *  Outport: '<S497>/deltax'
     */
    localB->Product2_k[0] = localP->deltax_Y0_k;
    localB->Product2_k[1] = localP->deltax_Y0_k;
    localB->Product2_k[2] = localP->deltax_Y0_k;
    localB->Product2_k[3] = localP->deltax_Y0_k;
    localDW->EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S471>/Enabled Subsystem' */

  /* Sum: '<S471>/Add' incorporates:
   *  Delay: '<S426>/MemoryX'
   */
  localB->Add_o[0] = localB->Product2_k[0] + localDW->MemoryX_DSTATE_l[0];
  localB->Add_o[1] = localB->Product2_k[1] + localDW->MemoryX_DSTATE_l[1];
  localB->Add_o[2] = localB->Product2_k[2] + localDW->MemoryX_DSTATE_l[2];
  localB->Add_o[3] = localB->Product2_k[3] + localDW->MemoryX_DSTATE_l[3];

  /* Trigonometry: '<S242>/sincos' incorporates:
   *  DiscreteIntegrator: '<S304>/Discrete-Time Integrator'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   *  Trigonometry: '<S429>/sincos'
   *  Trigonometry: '<S502>/sincos'
   */
  localB->rtb_Akxhatkk1_o_idx_0 = (real32_T)sin
    (localDW->DiscreteTimeIntegrator_DSTATE);
  localB->rtb_DataTypeConversion1_i_idx_0_tmp = (real32_T)cos
    (localDW->DiscreteTimeIntegrator_DSTATE);
  localB->denAccum = (real32_T)sin(localB->rtb_DataTypeConversion3_idx_1);
  localB->rtb_TSamp_d = (real32_T)cos(localB->rtb_DataTypeConversion3_idx_1);
  localB->rtb_sincos_o2_idx_2_tmp = (real32_T)sin
    (localB->rtb_DataTypeConversion3_idx_2);
  localB->numAccum = (real32_T)cos(localB->rtb_DataTypeConversion3_idx_2);

  /* Fcn: '<S242>/Fcn11' incorporates:
   *  Fcn: '<S429>/Fcn11'
   *  Fcn: '<S502>/Fcn11'
   *  Trigonometry: '<S242>/sincos'
   */
  localB->rtb_MathFunction_tmp = localB->rtb_DataTypeConversion1_i_idx_0_tmp *
    localB->rtb_TSamp_d;
  localB->MathFunction[0] = localB->rtb_MathFunction_tmp;

  /* Fcn: '<S242>/Fcn21' incorporates:
   *  Fcn: '<S429>/Fcn21'
   *  Fcn: '<S502>/Fcn21'
   *  Trigonometry: '<S242>/sincos'
   */
  localB->rtb_Gain_m_tmp = localB->denAccum * localB->rtb_sincos_o2_idx_2_tmp;
  rtb_MathFunction_tmp = localB->rtb_Akxhatkk1_o_idx_0 * localB->numAccum;
  localB->MathFunction[1] = localB->rtb_Gain_m_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp - rtb_MathFunction_tmp;

  /* Fcn: '<S242>/Fcn31' incorporates:
   *  Fcn: '<S429>/Fcn31'
   *  Fcn: '<S502>/Fcn31'
   *  Trigonometry: '<S242>/sincos'
   */
  rtb_MathFunction_tmp_tmp = localB->denAccum * localB->numAccum;
  rtb_MathFunction_tmp_0 = localB->rtb_Akxhatkk1_o_idx_0 *
    localB->rtb_sincos_o2_idx_2_tmp;
  localB->MathFunction[2] = rtb_MathFunction_tmp_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp + rtb_MathFunction_tmp_0;

  /* Fcn: '<S242>/Fcn12' incorporates:
   *  Fcn: '<S429>/Fcn12'
   *  Fcn: '<S502>/Fcn12'
   *  Trigonometry: '<S242>/sincos'
   */
  rtb_MathFunction_tmp_1 = localB->rtb_Akxhatkk1_o_idx_0 * localB->rtb_TSamp_d;
  localB->MathFunction[3] = rtb_MathFunction_tmp_1;

  /* Fcn: '<S242>/Fcn22' incorporates:
   *  Fcn: '<S242>/Fcn21'
   *  Fcn: '<S429>/Fcn22'
   *  Fcn: '<S502>/Fcn22'
   *  Trigonometry: '<S242>/sincos'
   */
  rtb_MathFunction_tmp_2 = localB->rtb_DataTypeConversion1_i_idx_0_tmp *
    localB->numAccum;
  localB->MathFunction[4] = localB->rtb_Gain_m_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 + rtb_MathFunction_tmp_2;

  /* Fcn: '<S242>/Fcn32' incorporates:
   *  Fcn: '<S242>/Fcn31'
   *  Fcn: '<S429>/Fcn32'
   *  Fcn: '<S502>/Fcn32'
   *  Trigonometry: '<S242>/sincos'
   */
  rtb_MathFunction_tmp_3 = localB->rtb_DataTypeConversion1_i_idx_0_tmp *
    localB->rtb_sincos_o2_idx_2_tmp;
  localB->MathFunction[5] = rtb_MathFunction_tmp_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 - rtb_MathFunction_tmp_3;

  /* Fcn: '<S242>/Fcn13' incorporates:
   *  Trigonometry: '<S242>/sincos'
   */
  localB->MathFunction[6] = -localB->denAccum;

  /* Fcn: '<S242>/Fcn23' incorporates:
   *  Fcn: '<S429>/Fcn23'
   *  Fcn: '<S502>/Fcn23'
   *  Trigonometry: '<S242>/sincos'
   */
  localB->rtb_sincos_o2_idx_2_tmp *= localB->rtb_TSamp_d;
  localB->MathFunction[7] = localB->rtb_sincos_o2_idx_2_tmp;

  /* Fcn: '<S242>/Fcn33' incorporates:
   *  Fcn: '<S429>/Fcn33'
   *  Fcn: '<S502>/Fcn33'
   *  Trigonometry: '<S242>/sincos'
   */
  localB->rtb_TSamp_d *= localB->numAccum;
  localB->MathFunction[8] = localB->rtb_TSamp_d;

  /* DataTypeConversion: '<S236>/Data Type Conversion1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->u_h = localDW->Delay1_DSTATE_p[0];
  localB->unnamed_idx_1_tmp = localDW->Delay1_DSTATE_p[1];

  /* Product: '<S236>/Product1' incorporates:
   *  DataTypeConversion: '<S236>/Data Type Conversion1'
   *  Math: '<S236>/Math Function'
   *  Reshape: '<S240>/Reshapexhat'
   *  SignalConversion generated from: '<S236>/Product1'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MultiportSwitch_tmp = (localB->MathFunction[localB->j + 3] *
      localB->unnamed_idx_1_tmp + localB->MathFunction[localB->j] * localB->u_h)
      + localB->MathFunction[localB->j + 6] * localB->rtb_Add_a_idx_1;
    localB->MultiportSwitch[localB->j] = localB->rtb_MultiportSwitch_tmp;
    localB->rtb_MathFunction_c[localB->j] = localB->rtb_MultiportSwitch_tmp;
  }

  /* End of Product: '<S236>/Product1' */

  /* DataTypeConversion: '<S236>/Data Type Conversion2' */
  localB->Gain_m = (real32_T)localB->rtb_MathFunction_c[2];

  /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  DataTypeConversion: '<S236>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S304>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity'
   *  Reshape: '<S240>/Reshapexhat'
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localDW->SimplyIntegrateVelocity_DSTATE[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[2] = (real32_T)
    localB->rtb_Add_a_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] =
    localDW->DiscreteTimeIntegrator_DSTATE;
  localB->TmpSignalConversionAtToWorkspaceInport1[4] =
    localB->rtb_DataTypeConversion3_idx_1;
  localB->TmpSignalConversionAtToWorkspaceInport1[5] =
    localB->rtb_DataTypeConversion3_idx_2;
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Add_o[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Add_o[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] = (real32_T)
    localB->MultiportSwitch[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[9] =
    localB->rtb_Subtract_p_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[10] =
    localB->rtb_Subtract_p_idx_1;
  localB->TmpSignalConversionAtToWorkspaceInport1[11] =
    localB->rtb_Subtract_p_idx_2;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspaceInport1[0]);
  }

  /* Math: '<S236>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MathFunction_m[3 * localB->j] = localB->MathFunction[localB->j];
    localB->rtb_MathFunction_m[3 * localB->j + 1] = localB->MathFunction
      [localB->j + 3];
    localB->rtb_MathFunction_m[3 * localB->j + 2] = localB->MathFunction
      [localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->MathFunction[localB->j] = localB->rtb_MathFunction_m[localB->j];
  }

  /* End of Math: '<S236>/Math Function' */

  /* Fcn: '<S429>/Fcn11' */
  localB->Reshape9to3x3columnmajor[0] = localB->rtb_MathFunction_tmp;

  /* Fcn: '<S429>/Fcn21' */
  localB->Reshape9to3x3columnmajor[1] = localB->rtb_Gain_m_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp - rtb_MathFunction_tmp;

  /* Fcn: '<S429>/Fcn31' */
  localB->Reshape9to3x3columnmajor[2] = rtb_MathFunction_tmp_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp + rtb_MathFunction_tmp_0;

  /* Fcn: '<S429>/Fcn12' */
  localB->Reshape9to3x3columnmajor[3] = rtb_MathFunction_tmp_1;

  /* Fcn: '<S429>/Fcn22' */
  localB->Reshape9to3x3columnmajor[4] = localB->rtb_Gain_m_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 + rtb_MathFunction_tmp_2;

  /* Fcn: '<S429>/Fcn32' */
  localB->Reshape9to3x3columnmajor[5] = rtb_MathFunction_tmp_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 - rtb_MathFunction_tmp_3;

  /* Fcn: '<S429>/Fcn13' */
  localB->Reshape9to3x3columnmajor[6] = -localB->denAccum;

  /* Fcn: '<S429>/Fcn23' */
  localB->Reshape9to3x3columnmajor[7] = localB->rtb_sincos_o2_idx_2_tmp;

  /* Fcn: '<S429>/Fcn33' */
  localB->Reshape9to3x3columnmajor[8] = localB->rtb_TSamp_d;

  /* Fcn: '<S502>/Fcn11' */
  localB->MathFunction_a[0] = localB->rtb_MathFunction_tmp;

  /* Fcn: '<S502>/Fcn21' */
  localB->MathFunction_a[1] = localB->rtb_Gain_m_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp - rtb_MathFunction_tmp;

  /* Fcn: '<S502>/Fcn31' */
  localB->MathFunction_a[2] = rtb_MathFunction_tmp_tmp *
    localB->rtb_DataTypeConversion1_i_idx_0_tmp + rtb_MathFunction_tmp_0;

  /* Fcn: '<S502>/Fcn12' */
  localB->MathFunction_a[3] = rtb_MathFunction_tmp_1;

  /* Fcn: '<S502>/Fcn22' */
  localB->MathFunction_a[4] = localB->rtb_Gain_m_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 + rtb_MathFunction_tmp_2;

  /* Fcn: '<S502>/Fcn32' */
  localB->MathFunction_a[5] = rtb_MathFunction_tmp_tmp *
    localB->rtb_Akxhatkk1_o_idx_0 - rtb_MathFunction_tmp_3;

  /* Fcn: '<S502>/Fcn13' */
  localB->MathFunction_a[6] = -localB->denAccum;

  /* Fcn: '<S502>/Fcn23' */
  localB->MathFunction_a[7] = localB->rtb_sincos_o2_idx_2_tmp;

  /* Fcn: '<S502>/Fcn33' */
  localB->MathFunction_a[8] = localB->rtb_TSamp_d;

  /* Math: '<S422>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MathFunction_m[3 * localB->j] = localB->MathFunction_a[localB->j];
    localB->rtb_MathFunction_m[3 * localB->j + 1] = localB->
      MathFunction_a[localB->j + 3];
    localB->rtb_MathFunction_m[3 * localB->j + 2] = localB->
      MathFunction_a[localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->MathFunction_a[localB->j] = localB->rtb_MathFunction_m[localB->j];
  }

  /* End of Math: '<S422>/Math Function' */

  /* RelationalOperator: '<S428>/Compare' incorporates:
   *  Constant: '<S428>/Constant'
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  Reshape: '<S240>/Reshapexhat'
   */
  rtb_Compare_p = ((real32_T)localB->rtb_Add_a_idx_0 <=
                   localP->DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S423>/Logical Operator' incorporates:
   *  Constant: '<S430>/Constant'
   *  Constant: '<S431>/Constant'
   *  RelationalOperator: '<S430>/Compare'
   *  RelationalOperator: '<S431>/Compare'
   */
  rtb_Compare_fc = ((localB->u_l[0] !=
                     localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con)
                    || (localB->u_l[1] !=
                        localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));

  /* Sum: '<S423>/Add' incorporates:
   *  Constant: '<S423>/gravity'
   *  Product: '<S423>/Product1'
   *  Reshape: '<S432>/Reshape (9) to [3x3] column-major'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_FIR_IMUaccel_k[localB->j] = localB->FIR_IMUaccel[localB->j] -
      ((localB->Reshape9to3x3columnmajor[localB->j + 3] * localP->gravity_Value
        [1] + localB->Reshape9to3x3columnmajor[localB->j] *
        localP->gravity_Value[0]) + localB->Reshape9to3x3columnmajor[localB->j +
       6] * localP->gravity_Value[2]);
  }

  /* End of Sum: '<S423>/Add' */

  /* Product: '<S423>/Product' incorporates:
   *  Gain: '<S423>/gainaccinput1'
   */
  localB->Product[0] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_FIR_IMUaccel_k[0]) * (real32_T)rtb_Compare_fc * (real32_T)
    rtb_Compare_p;
  localB->Product[1] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_FIR_IMUaccel_k[1]) * (real32_T)rtb_Compare_fc * (real32_T)
    rtb_Compare_p;

  /* Outputs for Enabled SubSystem: '<S464>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S495>/Enable'
   */
  /* DataTypeConversion: '<S426>/DataTypeConversionEnable' */
  if (localB->LogicalOperator3) {
    localDW->MeasurementUpdate_MODE = true;
    for (localB->j = 0; localB->j < 2; localB->j++) {
      /* Sum: '<S495>/Sum' incorporates:
       *  Constant: '<S426>/C'
       *  Constant: '<S426>/D'
       *  Delay: '<S426>/MemoryX'
       *  Product: '<S495>/C[k]*xhat[k|k-1]'
       *  Product: '<S495>/D[k]*u[k]'
       *  Reshape: '<S426>/Reshapeu'
       *  Reshape: '<S426>/Reshapey'
       *  Sum: '<S495>/Add1'
       */
      localB->Add_g[localB->j] = localB->angularvelocitycompensation[localB->j]
        - ((((localP->C_Value_i2[localB->j + 2] * localDW->MemoryX_DSTATE_l[1] +
              localP->C_Value_i2[localB->j] * localDW->MemoryX_DSTATE_l[0]) +
             localP->C_Value_i2[localB->j + 4] * localDW->MemoryX_DSTATE_l[2]) +
            localP->C_Value_i2[localB->j + 6] * localDW->MemoryX_DSTATE_l[3]) +
           (localP->D_Value_h[localB->j + 2] * localB->Product[1] +
            localP->D_Value_h[localB->j] * localB->Product[0]));
    }

    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S495>/Product3' incorporates:
       *  Constant: '<S445>/KalmanGainL'
       *  DataTypeConversion: '<S487>/Conversion'
       */
      localB->Product3_a[localB->j] = 0.0F;
      localB->Product3_a[localB->j] += (real32_T)localP->
        KalmanGainL_Value[localB->j] * localB->Add_g[0];
      localB->Product3_a[localB->j] += (real32_T)localP->
        KalmanGainL_Value[localB->j + 4] * localB->Add_g[1];
    }
  } else if (localDW->MeasurementUpdate_MODE) {
    /* Disable for Product: '<S495>/Product3' incorporates:
     *  Outport: '<S495>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3_a[0] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[1] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[2] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[3] = localP->Lykyhatkk1_Y0_c;
    localDW->MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S464>/MeasurementUpdate' */

  /* BusAssignment: '<S1>/Control Mode Update' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   */
  localB->u_l[0] = rtu_ReferenceValueServerCmds->orient_ref[0];
  localB->u_l[1] = rtu_ReferenceValueServerCmds->orient_ref[1];
  localB->u_l[2] = rtu_ReferenceValueServerCmds->orient_ref[2];

  /* Switch: '<S5>/Switch' */
  if (rtu_VisionbasedData) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/LatchValue'
     */
    localDW->Delay1_DSTATE = localP->LatchValue_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Logic: '<S5>/NOT' */
  rtb_Compare_p = !(localDW->Delay1_DSTATE != 0.0);

  /* Outputs for Triggered SubSystem: '<S234>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S235>/Trigger'
   */
  localB->zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
    &localZCE->TriggeredSubsystem_Trig_ZCE_g,
    (localDW->Delay1_DSTATE));
  if (localB->zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S235>/X' incorporates:
     *  DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity'
     */
    localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0 =
      localDW->SimplyIntegrateVelocity_DSTATE[0];

    /* SignalConversion generated from: '<S235>/Y' incorporates:
     *  DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity'
     */
    localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0 =
      localDW->SimplyIntegrateVelocity_DSTATE[1];
  }

  /* End of Outputs for SubSystem: '<S234>/Triggered Subsystem' */

  /* Sum: '<S5>/Add' incorporates:
   *  Delay: '<S5>/Delay'
   *  Gain: '<S5>/Move to right factor'
   */
  localDW->Delay_DSTATE += (real_T)(rtb_Compare_p ?
    localP->Movetorightfactor_Gain : 0U) * 2.8421709430404007E-14;

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Constant: '<S234>/Landing look-ahead distance'
   *  Constant: '<S5>/xValue'
   *  Constant: '<S5>/zValue'
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  Delay: '<S5>/Delay'
   *  Reshape: '<S240>/Reshapexhat'
   *  Sum: '<S234>/Add'
   */
  if (!rtb_Compare_p) {
    localB->MultiportSwitch[0] =
      localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0;
    localB->MultiportSwitch[1] =
      localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0;
    localB->MultiportSwitch[2] = (real32_T)localB->rtb_Add_a_idx_0 +
      localP->Landinglookaheaddistance_Value;
  } else {
    localB->MultiportSwitch[0] = localP->xValue_Value;
    localB->MultiportSwitch[1] = localDW->Delay_DSTATE;
    localB->MultiportSwitch[2] = localP->zValue_Value;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity'
   */
  localB->rtb_MathFunction_tmp = (real32_T)localB->MultiportSwitch[0] -
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->rtb_Gain_m_tmp = (real32_T)localB->MultiportSwitch[1] -
    localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* Saturate: '<S158>/Saturation' incorporates:
   *  Gain: '<S156>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localB->rtb_sincos_o2_idx_2_tmp = (localB->rtb_DataTypeConversion1_i_idx_0_tmp
    * localB->rtb_MathFunction_tmp + localB->rtb_Akxhatkk1_o_idx_0 *
    localB->rtb_Gain_m_tmp) * localP->Positioncontroller_P;
  if (localB->rtb_sincos_o2_idx_2_tmp >
      localP->Positioncontroller_UpperSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Positioncontroller_UpperSaturationLimit;
  } else if (localB->rtb_sincos_o2_idx_2_tmp <
             localP->Positioncontroller_LowerSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S156>/Proportional Gain'
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->denAccum = localB->rtb_sincos_o2_idx_2_tmp - localB->Add_o[0];

  /* Sum: '<S210>/Sum' incorporates:
   *  DiscreteIntegrator: '<S201>/Integrator'
   *  Gain: '<S206>/Proportional Gain'
   */
  localB->rtb_TSamp_d = localP->Velocitycontroller_P * localB->denAccum +
    localDW->Integrator_DSTATE[0];

  /* Saturate: '<S208>/Saturation' */
  if (localB->rtb_TSamp_d > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->rtb_TSamp_d <
             localP->Velocitycontroller_LowerSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    localB->rtb_sincos_o2_idx_2_tmp = localB->rtb_TSamp_d;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localB->rtb_sincos_o2_idx_2_tmp = (localB->rtb_sincos_o2_idx_2_tmp -
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[1]) /
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localB->numAccum =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localB->rtb_sincos_o2_idx_2_tmp +
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1];

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S156>/Proportional Gain'
   */
  localB->Add_g[0] = localB->denAccum;

  /* Sum: '<S210>/Sum' */
  localB->DeadZone[0] = localB->rtb_TSamp_d;

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[0] =
    localB->rtb_sincos_o2_idx_2_tmp;

  /* Saturate: '<S158>/Saturation' incorporates:
   *  Gain: '<S156>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localB->rtb_sincos_o2_idx_2_tmp = (-localB->rtb_Akxhatkk1_o_idx_0 *
    localB->rtb_MathFunction_tmp + localB->rtb_DataTypeConversion1_i_idx_0_tmp *
    localB->rtb_Gain_m_tmp) * localP->Positioncontroller_P;
  if (localB->rtb_sincos_o2_idx_2_tmp >
      localP->Positioncontroller_UpperSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Positioncontroller_UpperSaturationLimit;
  } else if (localB->rtb_sincos_o2_idx_2_tmp <
             localP->Positioncontroller_LowerSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S156>/Proportional Gain'
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->denAccum = localB->rtb_sincos_o2_idx_2_tmp - localB->Add_o[1];

  /* Sum: '<S210>/Sum' incorporates:
   *  DiscreteIntegrator: '<S201>/Integrator'
   *  Gain: '<S206>/Proportional Gain'
   */
  localB->rtb_TSamp_d = localP->Velocitycontroller_P * localB->denAccum +
    localDW->Integrator_DSTATE[1];

  /* Saturate: '<S208>/Saturation' */
  if (localB->rtb_TSamp_d > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->rtb_TSamp_d <
             localP->Velocitycontroller_LowerSaturationLimit) {
    localB->rtb_sincos_o2_idx_2_tmp =
      localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    localB->rtb_sincos_o2_idx_2_tmp = localB->rtb_TSamp_d;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localB->rtb_sincos_o2_idx_2_tmp = (localB->rtb_sincos_o2_idx_2_tmp -
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[1] *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1])
    / localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[1] =
    localB->rtb_sincos_o2_idx_2_tmp;

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  Constant: '<S1>/controlModePosVsOrient'
   *  DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   *  Gain: '<S10>/Gain'
   */
  if (localP->controlModePosVsOrient_Value) {
    localB->Integrator_l[0] = localP->Gain_Gain[0] * localB->numAccum;
    localB->Integrator_l[1] =
      (localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0]
       * localB->rtb_sincos_o2_idx_2_tmp +
       localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1]
       * localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
       [1]) * localP->Gain_Gain[1];
  } else {
    localB->Integrator_l[0] = localB->u_l[1];
    localB->Integrator_l[1] = localB->u_l[2];
  }

  /* End of Switch: '<S3>/Switch_refAtt' */

  /* Gain: '<S55>/Proportional Gain' incorporates:
   *  Sum: '<S8>/Sum19'
   */
  localB->rtb_DataTypeConversion3_idx_1 = (localB->Integrator_l[0] -
    localB->rtb_DataTypeConversion3_idx_1) * localP->Anglecontrolloop_P;
  localB->rtb_DataTypeConversion3_idx_2 = (localB->Integrator_l[1] -
    localB->rtb_DataTypeConversion3_idx_2) * localP->Anglecontrolloop_P;

  /* Sum: '<S8>/Sum1' */
  localB->Integrator_l[0] = localB->rtb_DataTypeConversion3_idx_1 -
    localB->rtb_Subtract_p_idx_1;
  localB->Integrator_l[1] = localB->rtb_DataTypeConversion3_idx_2 -
    localB->rtb_Subtract_p_idx_0;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localB->rtb_Subtract_p_idx_0 = (localP->Angularvelocitycontrolloop_D[0] *
    localB->Integrator_l[0] - localDW->Filter_DSTATE[0]) *
    localP->Angularvelocitycontrolloop_N[0];

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  localB->rtb_DataTypeConversion3_idx_2 = (localP->Angularvelocitycontrolloop_P
    [0] * localB->Integrator_l[0] + localDW->Integrator_DSTATE_d[0]) +
    localB->rtb_Subtract_p_idx_0;

  /* Saturate: '<S107>/Saturation' */
  if (localB->rtb_DataTypeConversion3_idx_2 >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    localB->rtb_Akxhatkk1_o_idx_0 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->rtb_DataTypeConversion3_idx_2 <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->rtb_Akxhatkk1_o_idx_0 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    localB->rtb_Akxhatkk1_o_idx_0 = localB->rtb_DataTypeConversion3_idx_2;
  }

  /* Gain: '<S103>/Filter Coefficient' */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] =
    localB->rtb_Subtract_p_idx_0;

  /* Sum: '<S109>/Sum' */
  localB->DeadZone_k[0] = localB->rtb_DataTypeConversion3_idx_2;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localB->rtb_Subtract_p_idx_0 = (localP->Angularvelocitycontrolloop_D[1] *
    localB->Integrator_l[1] - localDW->Filter_DSTATE[1]) *
    localP->Angularvelocitycontrolloop_N[1];

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  localB->rtb_DataTypeConversion3_idx_2 = (localP->Angularvelocitycontrolloop_P
    [1] * localB->Integrator_l[1] + localDW->Integrator_DSTATE_d[1]) +
    localB->rtb_Subtract_p_idx_0;

  /* Saturate: '<S107>/Saturation' */
  if (localB->rtb_DataTypeConversion3_idx_2 >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    localB->rtb_DataTypeConversion3_idx_1 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->rtb_DataTypeConversion3_idx_2 <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->rtb_DataTypeConversion3_idx_1 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    localB->rtb_DataTypeConversion3_idx_1 =
      localB->rtb_DataTypeConversion3_idx_2;
  }

  /* Gain: '<S103>/Filter Coefficient' */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] =
    localB->rtb_Subtract_p_idx_0;

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_f = (localDW->Output_DSTATE_a < localP->CompareToConstant_const_c);

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((!rtb_Compare_f) && (localDW->DiscreteTimeIntegrator_PrevResetState == 1))
  {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_IC_h;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE_c >=
      localP->DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_UpperSat;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_c <=
             localP->DiscreteTimeIntegrator_LowerSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_LowerSat;
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Reshape: '<S240>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_0 = (real32_T)localB->MultiportSwitch[2] -
    (real32_T)localB->rtb_Add_a_idx_0;

  /* Sum: '<S11>/Sum1' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  DiscreteIntegrator: '<S304>/Discrete-Time Integrator'
   */
  localB->rtb_Subtract_p_idx_1 = localB->u_l[0] -
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S11>/Saturation' */
  if (localB->rtb_Subtract_p_idx_1 > localP->Saturation_UpperSat) {
    localB->rtb_Subtract_p_idx_1 = localP->Saturation_UpperSat;
  } else if (localB->rtb_Subtract_p_idx_1 < localP->Saturation_LowerSat) {
    localB->rtb_Subtract_p_idx_1 = localP->Saturation_LowerSat;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Switch: '<S7>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S7>/w1'
   *  DataTypeConversion: '<S236>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Gain: '<S7>/takeoff_gain1'
   *  Sum: '<S7>/Sum1'
   */
  if (rtb_Compare_f) {
    localB->rtb_DataTypeConversion1_i_idx_0_tmp = localP->takeoff_gain1_Gain *
      localP->w1_Value;
  } else {
    localB->rtb_DataTypeConversion1_i_idx_0_tmp = (localP->P_z1_Gain *
      localB->rtb_Subtract_p_idx_0 + localDW->DiscreteTimeIntegrator_DSTATE_c) -
      localP->D_z1_Gain * (real32_T)localB->rtb_MathFunction_c[2];
  }

  /* End of Switch: '<S7>/TakeoffOrControl_Switch1' */

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/w1'
   */
  localB->rtb_sincos_o2_idx_2_tmp = localP->w1_Value +
    localB->rtb_DataTypeConversion1_i_idx_0_tmp;

  /* Saturate: '<S7>/SaturationThrust1' */
  if (localB->rtb_sincos_o2_idx_2_tmp > localP->SaturationThrust1_UpperSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->SaturationThrust1_UpperSat;
  } else if (localB->rtb_sincos_o2_idx_2_tmp <
             localP->SaturationThrust1_LowerSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->SaturationThrust1_LowerSat;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_yaw'
   *  Gain: '<S11>/P_yaw'
   *  Sum: '<S11>/Sum2'
   */
  localB->rtb_DataTypeConversion1_i_idx_0_tmp = (localP->P_yaw_Gain *
    localB->rtb_Subtract_p_idx_1 + localDW->DiscreteTimeIntegrator_DSTATE_d) -
    localP->D_yaw_Gain * localB->rtb_Subtract_p_idx_2;

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Pitch correction'
   *  Constant: '<S9>/zero correction'
   *  ManualSwitch: '<S9>/Manual Switch'
   */
  if (localP->ManualSwitch_CurrentSetting == 1) {
    localB->rtb_Subtract_p_idx_2 = localP->Pitchcorrection_Value;
  } else {
    localB->rtb_Subtract_p_idx_2 = localP->zerocorrection_Value;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  Sum: '<S9>/Add'
   */
  localB->rtb_Subtract_p_idx_2 += localB->rtb_Akxhatkk1_o_idx_0;

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/TorqueTotalThrustToThrustPerMotor'
   *  Saturate: '<S7>/SaturationThrust1'
   *  SignalConversion generated from: '<S9>/Product'
   */
  for (localB->j = 0; localB->j < 4; localB->j++) {
    localB->fv[localB->j] = ((localP->
      TorqueTotalThrustToThrustPerMotor_Value[localB->j + 4] *
      localB->rtb_DataTypeConversion1_i_idx_0_tmp +
      localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j] *
      localB->rtb_sincos_o2_idx_2_tmp) +
      localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 8] *
      localB->rtb_Subtract_p_idx_2) +
      localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 12] *
      localB->rtb_DataTypeConversion3_idx_1;
  }

  /* End of Product: '<S9>/Product' */

  /* Saturate: '<S12>/Saturation5' incorporates:
   *  Gain: '<S12>/MotorDirections'
   *  Gain: '<S12>/ThrustToMotorCommand'
   */
  localB->rtb_sincos_o2_idx_2_tmp = localP->ThrustToMotorCommand_Gain *
    localB->fv[0];
  if (localB->rtb_sincos_o2_idx_2_tmp > localP->Saturation5_UpperSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_UpperSat;
  } else if (localB->rtb_sincos_o2_idx_2_tmp < localP->Saturation5_LowerSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_LowerSat;
  }

  /* Gain: '<S12>/MotorDirections' */
  localB->MotorDirections[0] = localP->MotorDirections_Gain[0] *
    localB->rtb_sincos_o2_idx_2_tmp;

  /* Saturate: '<S12>/Saturation5' incorporates:
   *  Gain: '<S12>/MotorDirections'
   *  Gain: '<S12>/ThrustToMotorCommand'
   */
  localB->rtb_sincos_o2_idx_2_tmp = localP->ThrustToMotorCommand_Gain *
    localB->fv[1];
  if (localB->rtb_sincos_o2_idx_2_tmp > localP->Saturation5_UpperSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_UpperSat;
  } else if (localB->rtb_sincos_o2_idx_2_tmp < localP->Saturation5_LowerSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_LowerSat;
  }

  /* Gain: '<S12>/MotorDirections' */
  localB->MotorDirections[1] = localP->MotorDirections_Gain[1] *
    localB->rtb_sincos_o2_idx_2_tmp;

  /* Saturate: '<S12>/Saturation5' incorporates:
   *  Gain: '<S12>/MotorDirections'
   *  Gain: '<S12>/ThrustToMotorCommand'
   */
  localB->rtb_sincos_o2_idx_2_tmp = localP->ThrustToMotorCommand_Gain *
    localB->fv[2];
  if (localB->rtb_sincos_o2_idx_2_tmp > localP->Saturation5_UpperSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_UpperSat;
  } else if (localB->rtb_sincos_o2_idx_2_tmp < localP->Saturation5_LowerSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_LowerSat;
  }

  /* Gain: '<S12>/MotorDirections' */
  localB->MotorDirections[2] = localP->MotorDirections_Gain[2] *
    localB->rtb_sincos_o2_idx_2_tmp;

  /* Saturate: '<S12>/Saturation5' incorporates:
   *  Gain: '<S12>/MotorDirections'
   *  Gain: '<S12>/ThrustToMotorCommand'
   */
  localB->rtb_sincos_o2_idx_2_tmp = localP->ThrustToMotorCommand_Gain *
    localB->fv[3];
  if (localB->rtb_sincos_o2_idx_2_tmp > localP->Saturation5_UpperSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_UpperSat;
  } else if (localB->rtb_sincos_o2_idx_2_tmp < localP->Saturation5_LowerSat) {
    localB->rtb_sincos_o2_idx_2_tmp = localP->Saturation5_LowerSat;
  }

  /* Gain: '<S12>/MotorDirections' */
  localB->MotorDirections[3] = localP->MotorDirections_Gain[3] *
    localB->rtb_sincos_o2_idx_2_tmp;
  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Sum: '<S236>/Sum' incorporates:
     *  Constant: '<S236>/gravity'
     *  DiscreteFir: '<S238>/FIR_IMUaccel'
     *  Math: '<S236>/Math Function'
     *  Product: '<S236>/Product'
     */
    localB->Sum[localB->j] = ((localB->MathFunction[localB->j + 3] *
      localB->FIR_IMUaccel[1] + localB->MathFunction[localB->j] *
      localB->FIR_IMUaccel[0]) + localB->MathFunction[localB->j + 6] *
      localB->Abs) + localP->gravity_Value_j[localB->j];
  }

  /* Reshape: '<S360>/Reshapeu' */
  localB->rtb_Reshapeu_n_g = localB->p;

  /* DataTypeConversion: '<S376>/Conversion' */
  localB->rtb_Conversion_mo_m[0] = localB->rtb_MemoryX_g_g[0];

  /* DataTypeConversion: '<S403>/Conversion' incorporates:
   *  Constant: '<S361>/KalmanGainL'
   */
  localB->rtb_Conversion_b_n[0] = (real32_T)localP->KalmanGainL_Value_p[0];

  /* DataTypeConversion: '<S376>/Conversion' */
  localB->rtb_Conversion_mo_m[1] = localB->rtb_MemoryX_g_g[1];

  /* DataTypeConversion: '<S403>/Conversion' incorporates:
   *  Constant: '<S361>/KalmanGainL'
   */
  localB->rtb_Conversion_b_n[1] = (real32_T)localP->KalmanGainL_Value_p[1];

  /* Outputs for Enabled SubSystem: '<S380>/MeasurementUpdate' */
  /* Constant: '<S360>/C' incorporates:
   *  Constant: '<S360>/D'
   */
  flightControlSystem_MeasurementUpdate(rtb_DataTypeConversionEnable_e,
    localB->rtb_Conversion_b_n, localB->rtb_Reshapey_g_d, localP->C_Value_i,
    localB->rtb_Conversion_mo_m, localP->D_Value_k, localB->rtb_Reshapeu_n_g,
    &localB->MeasurementUpdate_j, &localDW->MeasurementUpdate_j,
    &localP->MeasurementUpdate_j);

  /* End of Outputs for SubSystem: '<S380>/MeasurementUpdate' */

  /* Reshape: '<S306>/Reshapeu' */
  localB->rtb_Reshapeu_k_l = localB->q;

  /* DataTypeConversion: '<S322>/Conversion' */
  localB->rtb_Conversion_fz_p[0] = localB->rtb_MemoryX_e_f[0];

  /* DataTypeConversion: '<S349>/Conversion' incorporates:
   *  Constant: '<S307>/KalmanGainL'
   */
  localB->rtb_Conversion_p_l[0] = (real32_T)localP->KalmanGainL_Value_l[0];

  /* DataTypeConversion: '<S322>/Conversion' */
  localB->rtb_Conversion_fz_p[1] = localB->rtb_MemoryX_e_f[1];

  /* DataTypeConversion: '<S349>/Conversion' incorporates:
   *  Constant: '<S307>/KalmanGainL'
   */
  localB->rtb_Conversion_p_l[1] = (real32_T)localP->KalmanGainL_Value_l[1];

  /* Outputs for Enabled SubSystem: '<S326>/MeasurementUpdate' */
  /* Constant: '<S306>/C' incorporates:
   *  Constant: '<S306>/D'
   */
  flightControlSystem_MeasurementUpdate(rtb_DataTypeConversionEnable_g,
    localB->rtb_Conversion_p_l, localB->rtb_Reshapey_f_j, localP->C_Value_h,
    localB->rtb_Conversion_fz_p, localP->D_Value_kg, localB->rtb_Reshapeu_k_l,
    &localB->MeasurementUpdate_n, &localDW->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of Outputs for SubSystem: '<S326>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S262>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S292>/Enable'
   */
  /* DataTypeConversion: '<S240>/DataTypeConversionEnable' */
  if (localB->nicemeasurementornewupdateneeded) {
    localDW->MeasurementUpdate_MODE_h = true;

    /* Product: '<S292>/D[k]*u[k]' incorporates:
     *  Constant: '<S240>/D'
     *  Delay: '<S236>/Delay2'
     *  Reshape: '<S240>/Reshapeu'
     */
    localDW->Delay2_DSTATE = localP->D_Value * localB->Sum[2];

    /* Sum: '<S292>/Sum' incorporates:
     *  Constant: '<S240>/C'
     *  Delay: '<S236>/Delay2'
     *  Delay: '<S240>/MemoryX'
     *  Product: '<S292>/C[k]*xhat[k|k-1]'
     *  Reshape: '<S240>/Reshapey'
     *  Sum: '<S292>/Add1'
     */
    localB->u_h = localB->invertzaxisGain - ((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localDW->Delay2_DSTATE);

    /* Product: '<S292>/Product3' incorporates:
     *  Constant: '<S244>/KalmanGainL'
     *  DataTypeConversion: '<S284>/Conversion'
     */
    localB->Product3[0] = localP->KalmanGainL_Value_b[0] * localB->u_h;
    localB->Product3[1] = localP->KalmanGainL_Value_b[1] * localB->u_h;
  } else if (localDW->MeasurementUpdate_MODE_h) {
    /* Disable for Product: '<S292>/Product3' incorporates:
     *  Outport: '<S292>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3[0] = localP->Lykyhatkk1_Y0;
    localB->Product3[1] = localP->Lykyhatkk1_Y0;
    localDW->MeasurementUpdate_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S262>/MeasurementUpdate' */

  /* DeadZone: '<S93>/DeadZone' */
  if (localB->DeadZone_k[0] >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    localB->DeadZone_k[0] -=
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->DeadZone_k[0] >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->DeadZone_k[0] = 0.0F;
  } else {
    localB->DeadZone_k[0] -=
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* Gain: '<S97>/Integral Gain' */
  localB->Integrator_l[0] *= localP->Angularvelocitycontrolloop_I[0];

  /* DeadZone: '<S194>/DeadZone' */
  if (localB->DeadZone[0] > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->DeadZone[0] -= localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->DeadZone[0] >=
             localP->Velocitycontroller_LowerSaturationLimit) {
    localB->DeadZone[0] = 0.0F;
  } else {
    localB->DeadZone[0] -= localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S198>/Integral Gain' */
  localB->Add_g[0] *= localP->Velocitycontroller_I;

  /* DeadZone: '<S93>/DeadZone' */
  if (localB->rtb_DataTypeConversion3_idx_2 >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    localB->DeadZone_k[1] = localB->rtb_DataTypeConversion3_idx_2 -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->rtb_DataTypeConversion3_idx_2 >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->DeadZone_k[1] = 0.0F;
  } else {
    localB->DeadZone_k[1] = localB->rtb_DataTypeConversion3_idx_2 -
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* Gain: '<S97>/Integral Gain' */
  localB->Integrator_l[1] *= localP->Angularvelocitycontrolloop_I[1];

  /* DeadZone: '<S194>/DeadZone' */
  if (localB->rtb_TSamp_d > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->DeadZone[1] = localB->rtb_TSamp_d -
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->rtb_TSamp_d >=
             localP->Velocitycontroller_LowerSaturationLimit) {
    localB->DeadZone[1] = 0.0F;
  } else {
    localB->DeadZone[1] = localB->rtb_TSamp_d -
      localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S198>/Integral Gain' */
  localB->Add_g[1] = localP->Velocitycontroller_I * localB->denAccum;

  /* Sum: '<S15>/FixPt Sum1' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a = (uint16_T)((uint32_T)localDW->Output_DSTATE_a +
    localP->FixPtConstant_Value_g);

  /* Switch: '<S16>/FixPt Switch' */
  if (localDW->Output_DSTATE_a > localP->WrapToZero_Threshold_c) {
    /* Sum: '<S15>/FixPt Sum1' incorporates:
     *  Constant: '<S16>/Constant'
     */
    localDW->Output_DSTATE_a = localP->Constant_Value_k;
  }

  /* End of Switch: '<S16>/FixPt Switch' */

  /* Gain: '<S4>/Gain' */
  localB->Abs = localP->Gain_Gain_o *
    rtu_Sensors->VisionSensors.opticalFlow_data[0];

  /* Sum: '<S4>/Subtract' incorporates:
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_2 = localB->Abs - localB->Add_o[0];

  /* Abs: '<S4>/Abs4' */
  localB->Abs = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]);

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Abs: '<S4>/Abs2'
   *  Constant: '<S222>/Constant'
   *  Constant: '<S224>/Constant'
   *  RelationalOperator: '<S222>/Compare'
   *  RelationalOperator: '<S224>/Compare'
   */
  rtb_Compare_fc = ((localB->Abs > localP->CompareToConstant4_const) &&
                    ((real32_T)fabs(localB->rtb_Subtract_p_idx_2) >
                     localP->CompareToConstant2_const));

  /* Gain: '<S4>/Gain1' */
  localB->Abs = localP->Gain1_Gain_p *
    rtu_Sensors->VisionSensors.opticalFlow_data[1];

  /* Sum: '<S4>/Subtract1' incorporates:
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_2 = localB->Abs - localB->Add_o[1];

  /* Abs: '<S4>/Abs5' */
  localB->Abs = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]);

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  Constant: '<S4>/Wait  3 Seconds'
   *  UnitDelay: '<S226>/Output'
   */
  rtb_Compare_p = (localDW->Output_DSTATE_g > localP->Wait3Seconds_Value);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   */
  if (rtb_Compare_p) {
    localB->u_h = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->u_h = localP->_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Delay: '<S4>/Delay One Step' incorporates:
   *  Delay: '<S236>/Delay2'
   */
  localDW->Delay2_DSTATE = localDW->DelayOneStep_DSTATE;

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S219>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S236>/Delay2'
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S219>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->u_h ==
    localP->Checkerrorcondition_const) * localDW->Delay2_DSTATE + (real_T)
    (localB->u_h == localP->Checkerrorcondition_const);

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs  '
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs3'
   *  Constant: '<S218>/Constant'
   *  Constant: '<S220>/Constant'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S223>/Constant'
   *  Constant: '<S225>/Constant'
   *  Constant: '<S4>/0.5 meters'
   *  Delay: '<S4>/Delay One Step'
   *  DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S218>/Compare'
   *  RelationalOperator: '<S220>/Compare'
   *  RelationalOperator: '<S221>/Compare'
   *  RelationalOperator: '<S223>/Compare'
   *  RelationalOperator: '<S225>/Compare'
   *  RelationalOperator: '<S4>/GreaterThan  '
   *  Switch: '<S4>/         '
   */
  if (((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[0]) >
       localP->CompareToConstant_const_j) || ((real32_T)fabs
       (localDW->SimplyIntegrateVelocity_DSTATE[1]) >
       localP->CompareToConstant1_const_e)) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S227>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if (rtb_Compare_fc || (((real32_T)fabs(localB->rtb_Subtract_p_idx_2) >
               localP->CompareToConstant3_const) && (localB->Abs >
               localP->CompareToConstant5_const))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->DelayOneStep_DSTATE > localP->u0continuousOFerrors_const)
  {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge, &localP->Noopticalflow);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_Compare_p) {
      /* Switch: '<S4>/         ' incorporates:
       *  DataTypeConversion: '<S236>/Data Type Conversion'
       *  DiscreteFilter: '<S241>/pressureFilter_IIR'
       *  Reshape: '<S240>/Reshapexhat'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      localB->numAccum_d = (real32_T)localB->rtb_Add_a_idx_0 -
        localB->numAccum_d;
    } else {
      /* Switch: '<S4>/         ' incorporates:
       *  Constant: '<S4>/    '
       */
      localB->numAccum_d = localP->_Value_i;
    }

    if ((real32_T)fabs(localB->numAccum_d) > localP->u5meters_Value) {
      /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
       *  ActionPort: '<S230>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge,
        &localP->Ultrasoundimproper);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S229>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge,
        &localP->Normalcondition);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* Sum: '<S232>/FixPt Sum1' incorporates:
   *  Constant: '<S232>/FixPt Constant'
   *  UnitDelay: '<S226>/Output'
   */
  localDW->Output_DSTATE_g += localP->FixPtConstant_Value;

  /* Sum: '<S500>/FixPt Sum1' incorporates:
   *  Constant: '<S500>/FixPt Constant'
   *  UnitDelay: '<S499>/Output'
   */
  localDW->Output_DSTATE_n += localP->FixPtConstant_Value_p;

  /* Switch: '<S501>/FixPt Switch' */
  if (localDW->Output_DSTATE_n > localP->WrapToZero_Threshold_k) {
    /* Sum: '<S500>/FixPt Sum1' incorporates:
     *  Constant: '<S501>/Constant'
     */
    localDW->Output_DSTATE_n = localP->Constant_Value_e;
  }

  /* End of Switch: '<S501>/FixPt Switch' */

  /* Sum: '<S419>/FixPt Sum1' incorporates:
   *  Constant: '<S419>/FixPt Constant'
   *  UnitDelay: '<S417>/Output'
   */
  localDW->Output_DSTATE += localP->FixPtConstant_Value_m;

  /* Switch: '<S420>/FixPt Switch' */
  if (localDW->Output_DSTATE > localP->WrapToZero_Threshold_e) {
    /* Sum: '<S419>/FixPt Sum1' incorporates:
     *  Constant: '<S420>/Constant'
     */
    localDW->Output_DSTATE = localP->Constant_Value_jy;
  }

  /* End of Switch: '<S420>/FixPt Switch' */

  /* DataTypeConversion: '<S352>/Conversion' incorporates:
   *  Constant: '<S307>/CovarianceZ'
   */
  localB->rtb_Conversion_a_b[0] = (real32_T)localP->CovarianceZ_Value_bp[0];
  localB->rtb_Conversion_a_b[1] = (real32_T)localP->CovarianceZ_Value_bp[1];
  localB->rtb_Conversion_a_b[2] = (real32_T)localP->CovarianceZ_Value_bp[2];
  localB->rtb_Conversion_a_b[3] = (real32_T)localP->CovarianceZ_Value_bp[3];

  /* MATLAB Function: '<S355>/SqrtUsedFcn' incorporates:
   *  Constant: '<S355>/isSqrtUsed'
   */
  flightControlSystem_SqrtUsedFcn(localB->rtb_Conversion_a_b,
    localP->isSqrtUsed_Value_f);

  /* DataTypeConversion: '<S406>/Conversion' incorporates:
   *  Constant: '<S361>/CovarianceZ'
   */
  localB->rtb_Conversion_ii_p[0] = (real32_T)localP->CovarianceZ_Value_m[0];
  localB->rtb_Conversion_ii_p[1] = (real32_T)localP->CovarianceZ_Value_m[1];
  localB->rtb_Conversion_ii_p[2] = (real32_T)localP->CovarianceZ_Value_m[2];
  localB->rtb_Conversion_ii_p[3] = (real32_T)localP->CovarianceZ_Value_m[3];

  /* MATLAB Function: '<S409>/SqrtUsedFcn' incorporates:
   *  Constant: '<S409>/isSqrtUsed'
   */
  flightControlSystem_SqrtUsedFcn(localB->rtb_Conversion_ii_p,
    localP->isSqrtUsed_Value_j);

  /* SignalConversion generated from: '<S422>/Product' incorporates:
   *  Reshape: '<S426>/Reshapexhat'
   */
  localB->numAccum_d = localB->Add_o[0];
  localB->Abs = localB->Add_o[1];

  /* Product: '<S422>/Product' incorporates:
   *  Math: '<S422>/Math Function'
   *  SignalConversion generated from: '<S422>/Product'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->FIR_IMUaccel[localB->j] = (localB->MathFunction_a[localB->j + 3] *
      localB->Abs + localB->MathFunction_a[localB->j] * localB->numAccum_d) +
      localB->MathFunction_a[localB->j + 6] * localB->Gain_m;
  }

  /* End of Product: '<S422>/Product' */

  /* Update for DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = (int8_T)
    localP->controlModePosVsOrient_Value;

  /* Update for Delay: '<S236>/Delay2' incorporates:
   *  Reshape: '<S240>/Reshapexhat'
   */
  localDW->Delay2_DSTATE = localB->rtb_Add_a_idx_0;

  /* Update for Delay: '<S240>/MemoryX' */
  localDW->icLoad = false;

  /* Update for DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] +=
    localP->SimplyIntegrateVelocity_gainval * localB->FIR_IMUaccel[0];

  /* Product: '<S262>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S240>/A'
   *  Delay: '<S240>/MemoryX'
   */
  localB->rtb_Add_a_idx_0 = localP->A_Value[0] * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1] * localP->A_Value[2];

  /* Update for DiscreteIntegrator: '<S422>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] +=
    localP->SimplyIntegrateVelocity_gainval * localB->FIR_IMUaccel[1];

  /* Product: '<S262>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S240>/A'
   *  Delay: '<S240>/MemoryX'
   */
  localB->rtb_Add_a_idx_1 = localDW->MemoryX_DSTATE[0] * localP->A_Value[1] +
    localDW->MemoryX_DSTATE[1] * localP->A_Value[3];

  /* Update for Delay: '<S240>/MemoryX' incorporates:
   *  Constant: '<S240>/B'
   *  Product: '<S262>/B[k]*u[k]'
   *  Product: '<S292>/Product3'
   *  Reshape: '<S240>/Reshapeu'
   *  Sum: '<S262>/Add'
   */
  localDW->MemoryX_DSTATE[0] = (localP->B_Value[0] * localB->Sum[2] +
    localB->rtb_Add_a_idx_0) + localB->Product3[0];

  /* Update for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localDW->sonarFilter_IIR_states[1];

  /* Update for Delay: '<S240>/MemoryX' incorporates:
   *  Constant: '<S240>/B'
   *  Product: '<S262>/B[k]*u[k]'
   *  Product: '<S292>/Product3'
   *  Reshape: '<S240>/Reshapeu'
   *  Sum: '<S262>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (localP->B_Value[1] * localB->Sum[2] +
    localB->rtb_Add_a_idx_1) + localB->Product3[1];

  /* Update for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localDW->sonarFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S241>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = localB->DiscreteTimeIntegrator_k5;

  /* Update for DiscreteFilter: '<S241>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localB->sonarFilter_IIR_tmp;

  /* Update for DiscreteIntegrator: '<S304>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE +=
    localP->DiscreteTimeIntegrator_gainval * localB->Subtract;

  /* Update for Delay: '<S306>/MemoryX' incorporates:
   *  Constant: '<S306>/A'
   *  Constant: '<S306>/B'
   *  Product: '<S326>/A[k]*xhat[k|k-1]'
   *  Product: '<S326>/B[k]*u[k]'
   *  Product: '<S357>/Product3'
   *  Sum: '<S326>/Add'
   */
  localDW->icLoad_p = false;
  localDW->MemoryX_DSTATE_g[0] = ((localP->A_Value_k[0] *
    localB->rtb_Conversion_fz_p[0] + localB->rtb_Conversion_fz_p[1] *
    localP->A_Value_k[2]) + localP->B_Value_o[0] * localB->rtb_Reshapeu_k_l) +
    localB->MeasurementUpdate_n.Product3[0];
  localDW->MemoryX_DSTATE_g[1] = ((localB->rtb_Conversion_fz_p[0] *
    localP->A_Value_k[1] + localB->rtb_Conversion_fz_p[1] * localP->A_Value_k[3])
    + localP->B_Value_o[1] * localB->rtb_Reshapeu_k_l) +
    localB->MeasurementUpdate_n.Product3[1];

  /* Update for DiscreteFir: '<S238>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] = localB->
    Sum1_p_c[0];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localB->Sum1_p_c[1];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localB->Sum1_p_c[2];

  /* End of Update for DiscreteFir: '<S238>/FIR_IMUaccel' */

  /* Update for Delay: '<S360>/MemoryX' incorporates:
   *  Constant: '<S360>/A'
   *  Constant: '<S360>/B'
   *  Product: '<S380>/A[k]*xhat[k|k-1]'
   *  Product: '<S380>/B[k]*u[k]'
   *  Product: '<S411>/Product3'
   *  Sum: '<S380>/Add'
   */
  localDW->icLoad_k = false;
  localDW->MemoryX_DSTATE_m[0] = ((localP->A_Value_ah[0] *
    localB->rtb_Conversion_mo_m[0] + localB->rtb_Conversion_mo_m[1] *
    localP->A_Value_ah[2]) + localP->B_Value_g[0] * localB->rtb_Reshapeu_n_g) +
    localB->MeasurementUpdate_j.Product3[0];
  localDW->MemoryX_DSTATE_m[1] = ((localB->rtb_Conversion_mo_m[0] *
    localP->A_Value_ah[1] + localB->rtb_Conversion_mo_m[1] * localP->A_Value_ah
    [3]) + localP->B_Value_g[1] * localB->rtb_Reshapeu_n_g) +
    localB->MeasurementUpdate_j.Product3[1];

  /* Update for DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localB->Add_i;

  /* Update for DiscreteTransferFcn: '<S238>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localB->LPFFcutoff40Hz_tmp;

  /* Update for DiscreteFilter: '<S238>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->IIR_IMUgyro_r_tmp;

  /* Update for Delay: '<S426>/MemoryX' */
  localDW->icLoad_o = false;
  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Product: '<S464>/B[k]*u[k]' incorporates:
     *  Constant: '<S426>/B'
     *  Reshape: '<S426>/Reshapeu'
     */
    localB->fv[localB->j] = localP->B_Value_f[localB->j + 4] * localB->Product[1]
      + localP->B_Value_f[localB->j] * localB->Product[0];

    /* Product: '<S464>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S426>/A'
     *  Delay: '<S426>/MemoryX'
     */
    localB->fv1[localB->j] = ((localP->A_Value_a[localB->j + 4] *
      localDW->MemoryX_DSTATE_l[1] + localP->A_Value_a[localB->j] *
      localDW->MemoryX_DSTATE_l[0]) + localP->A_Value_a[localB->j + 8] *
      localDW->MemoryX_DSTATE_l[2]) + localP->A_Value_a[localB->j + 12] *
      localDW->MemoryX_DSTATE_l[3];
  }

  /* Update for Delay: '<S426>/MemoryX' incorporates:
   *  Sum: '<S464>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localB->fv[0] + localB->fv1[0]) +
    localB->Product3_a[0];
  localDW->MemoryX_DSTATE_l[1] = (localB->fv[1] + localB->fv1[1]) +
    localB->Product3_a[1];
  localDW->MemoryX_DSTATE_l[2] = (localB->fv[2] + localB->fv1[2]) +
    localB->Product3_a[2];
  localDW->MemoryX_DSTATE_l[3] = (localB->fv[3] + localB->fv1[3]) +
    localB->Product3_a[3];
  for (localB->j = 0; localB->j < 2; localB->j++) {
    /* RelationalOperator: '<S91>/fix for DT propagation issue1' incorporates:
     *  DiscreteIntegrator: '<S100>/Integrator'
     */
    localB->rtb_DataTypeConversion3_idx_1 = localB->Integrator_l[localB->j];

    /* RelationalOperator: '<S91>/Relational Operator' incorporates:
     *  DiscreteIntegrator: '<S100>/Integrator'
     */
    localB->rtb_DataTypeConversion3_idx_2 = localB->DeadZone_k[localB->j];

    /* RelationalOperator: '<S192>/fix for DT propagation issue1' incorporates:
     *  DiscreteIntegrator: '<S201>/Integrator'
     */
    localB->denAccum = localB->Add_g[localB->j];

    /* RelationalOperator: '<S192>/Relational Operator' incorporates:
     *  DiscreteIntegrator: '<S201>/Integrator'
     */
    localB->rtb_TSamp_d = localB->DeadZone[localB->j];

    /* Reshape: '<S426>/Reshapexhat' */
    localB->DiscreteTimeIntegrator_k5 = localB->Add_o[localB->j];

    /* Update for DiscreteFilter: '<S425>/IIRgyroz' */
    localB->memOffset = localB->j * 5;
    localDW->IIRgyroz_states[localB->memOffset + 4] = localDW->
      IIRgyroz_states[localB->memOffset + 3];
    localDW->IIRgyroz_states[localB->memOffset + 3] = localDW->
      IIRgyroz_states[localB->memOffset + 2];
    localDW->IIRgyroz_states[localB->memOffset + 2] = localDW->
      IIRgyroz_states[localB->memOffset + 1];
    localDW->IIRgyroz_states[localB->memOffset + 1] = localDW->
      IIRgyroz_states[localB->memOffset];
    localDW->IIRgyroz_states[localB->memOffset] = localB->IIRgyroz_tmp[localB->j];

    /* Update for UnitDelay: '<S433>/UD' incorporates:
     *  Sum: '<S433>/Diff'
     */
    localDW->UD_DSTATE[localB->j] = localB->TSamp[localB->j];

    /* Update for Delay: '<S421>/Delay' */
    localDW->Delay_DSTATE_a[localB->j] = localB->DiscreteTimeIntegrator_k5;

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE_p[localB->j] = localB->DiscreteTimeIntegrator_k5;

    /* Switch: '<S192>/Switch1' incorporates:
     *  Constant: '<S192>/Constant'
     *  Constant: '<S192>/Constant2'
     *  Constant: '<S192>/Constant5'
     *  RelationalOperator: '<S192>/fix for DT propagation issue'
     */
    if (localB->rtb_TSamp_d > localP->Constant5_Value_p) {
      rtb_DeadZone_0 = localP->Constant_Value_p;
    } else {
      rtb_DeadZone_0 = localP->Constant2_Value_f;
    }

    /* End of Switch: '<S192>/Switch1' */

    /* Switch: '<S192>/Switch2' incorporates:
     *  Constant: '<S192>/Constant3'
     *  Constant: '<S192>/Constant4'
     *  Constant: '<S192>/Constant5'
     *  RelationalOperator: '<S192>/fix for DT propagation issue1'
     */
    if (localB->denAccum > localP->Constant5_Value_p) {
      rtb_Add_g_0 = localP->Constant3_Value_d;
    } else {
      rtb_Add_g_0 = localP->Constant4_Value_p;
    }

    /* End of Switch: '<S192>/Switch2' */

    /* Switch: '<S192>/Switch' incorporates:
     *  Constant: '<S192>/Constant1'
     *  Constant: '<S192>/Constant5'
     *  Logic: '<S192>/AND3'
     *  RelationalOperator: '<S192>/Equal1'
     *  RelationalOperator: '<S192>/Relational Operator'
     */
    if ((localP->Constant5_Value_p != localB->rtb_TSamp_d) && (rtb_DeadZone_0 ==
         rtb_Add_g_0)) {
      localB->denAccum = localP->Constant1_Value_c;
    }

    /* End of Switch: '<S192>/Switch' */

    /* Update for DiscreteIntegrator: '<S201>/Integrator' */
    localDW->Integrator_DSTATE[localB->j] += localP->Integrator_gainval *
      localB->denAccum;

    /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
    localDW->
      LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[localB->j]
      = localB->
      LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[localB->j];

    /* Switch: '<S91>/Switch1' incorporates:
     *  Constant: '<S91>/Constant'
     *  Constant: '<S91>/Constant2'
     *  Constant: '<S91>/Constant5'
     *  RelationalOperator: '<S91>/fix for DT propagation issue'
     */
    if (localB->rtb_DataTypeConversion3_idx_2 > localP->Constant5_Value) {
      rtb_DeadZone_0 = localP->Constant_Value_km;
    } else {
      rtb_DeadZone_0 = localP->Constant2_Value;
    }

    /* End of Switch: '<S91>/Switch1' */

    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S91>/Constant3'
     *  Constant: '<S91>/Constant4'
     *  Constant: '<S91>/Constant5'
     *  RelationalOperator: '<S91>/fix for DT propagation issue1'
     */
    if (localB->rtb_DataTypeConversion3_idx_1 > localP->Constant5_Value) {
      rtb_Add_g_0 = localP->Constant3_Value;
    } else {
      rtb_Add_g_0 = localP->Constant4_Value;
    }

    /* End of Switch: '<S91>/Switch2' */

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/Constant1'
     *  Constant: '<S91>/Constant5'
     *  Logic: '<S91>/AND3'
     *  RelationalOperator: '<S91>/Equal1'
     *  RelationalOperator: '<S91>/Relational Operator'
     */
    if ((localP->Constant5_Value != localB->rtb_DataTypeConversion3_idx_2) &&
        (rtb_DeadZone_0 == rtb_Add_g_0)) {
      localB->rtb_DataTypeConversion3_idx_1 = localP->Constant1_Value;
    }

    /* End of Switch: '<S91>/Switch' */

    /* Update for DiscreteIntegrator: '<S100>/Integrator' */
    localDW->Integrator_DSTATE_d[localB->j] += localP->Integrator_gainval_i *
      localB->rtb_DataTypeConversion3_idx_1;

    /* Update for DiscreteIntegrator: '<S95>/Filter' */
    localDW->Filter_DSTATE[localB->j] += localP->Filter_gainval *
      localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr
      [localB->j];
  }

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_c += localP->I_pr_Gain *
    localB->rtb_Subtract_p_idx_0 * localP->DiscreteTimeIntegrator_gainval_n;
  if (localDW->DiscreteTimeIntegrator_DSTATE_c >=
      localP->DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_UpperSat;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_c <=
             localP->DiscreteTimeIntegrator_LowerSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_LowerSat;
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)rtb_Compare_f;

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_yaw'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_d += localP->I_yaw_Gain *
    localB->rtb_Subtract_p_idx_1 * localP->DiscreteTimeIntegrator_gainval_d;

  /* Switch: '<S233>/FixPt Switch' */
  if (localDW->Output_DSTATE_g > localP->WrapToZero_Threshold) {
    /* Sum: '<S232>/FixPt Sum1' incorporates:
     *  Constant: '<S233>/Constant'
     *  UnitDelay: '<S226>/Output'
     */
    localDW->Output_DSTATE_g = localP->Constant_Value_a;
  }

  /* End of Switch: '<S233>/FixPt Switch' */
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  boolean_T rtb_RateTransition;

  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  rtb_RateTransition = flightControlSystem_DW.RateTransition_Buffer0;

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_ControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, rtb_RateTransition, &flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem, &flightControlSystem_P.ControlSystem,
    &flightControlSystem_PrevZCX.ControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[0] = flightControlSystem_B.ControlSystem.MotorDirections[0];
  motors_outport[1] = flightControlSystem_B.ControlSystem.MotorDirections[1];
  motors_outport[2] = flightControlSystem_B.ControlSystem.MotorDirections[2];
  motors_outport[3] = flightControlSystem_B.ControlSystem.MotorDirections[3];

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* SignalConversion generated from: '<Root>/Control System' */
  flag_outport = flightControlSystem_B.ControlSystem.Merge;

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightControlSystem_M->Timing.taskTime0 =
    ((time_T)(++flightControlSystem_M->Timing.clockTick0)) *
    flightControlSystem_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  int32_T i;
  uint32_T tmp;
  boolean_T rtb_Compare_aa;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  MW_Build_RGB(&imRGB[0], &flightControlSystem_B.imageBuff_1[0],
               &flightControlSystem_B.imageBuff_2[0],
               &flightControlSystem_B.imageBuff_3[0]);

  /* Sum: '<S2>/Sum of white pixels' */
  tmp = 0U;
  for (i = 0; i < 19200; i++) {
    /* Sum: '<S2>/Sum of white pixels' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S504>/Constant'
     *  MATLABSystem: '<S2>/PARROT Image Conversion'
     *  Product: '<S2>/Divide1'
     *  Product: '<S2>/Divide2'
     *  RelationalOperator: '<S504>/Compare'
     *  Sum: '<S2>/Add'
     */
    tmp += (((real_T)flightControlSystem_B.imageBuff_1[i] - (real_T)
             flightControlSystem_B.imageBuff_3[i] /
             flightControlSystem_P.Constant_Value) - (real_T)
            flightControlSystem_B.imageBuff_2[i] /
            flightControlSystem_P.Constant_Value >
            flightControlSystem_P.Thresholdforeachpixel_const);
  }

  /* RelationalOperator: '<S505>/Compare' incorporates:
   *  Constant: '<S505>/Constant'
   *  Sum: '<S2>/Sum of white pixels'
   */
  rtb_Compare_aa = ((uint16_T)tmp >
                    flightControlSystem_P.Thresholdfortotalwhitepixels_const);

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */

  /* RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 = rtb_Compare_aa;
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  flightControlSystem_P.ControlSystem.SaturationSonar_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, 100.0);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &flightControlSystem_B), 0,
                sizeof(B_flightControlSystem_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void)memset(&flightControlSystem_Y, 0, sizeof(ExtY_flightControlSystem_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));
  flightControlSystem_PrevZCX.ControlSystem.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 =
    flightControlSystem_P.RateTransition_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Init(flightControlSystem_M,
    &flightControlSystem_B.ControlSystem, &flightControlSystem_DW.ControlSystem,
    &flightControlSystem_P.ControlSystem,
    &flightControlSystem_PrevZCX.ControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Control System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
