/*
 * flightControlSystem_data.c
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

/* Block parameters (default storage) */
P_flightControlSystem_T flightControlSystem_P = {
  /* Variable: Sensors
   * Referenced by:
   *   '<S241>/SaturationSonar'
   *   '<S295>/Constant'
   */
  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,
    0.05
  },

  /* Mask Parameter: Thresholdforeachpixel_const
   * Referenced by: '<S504>/Constant'
   */
  100.0,

  /* Mask Parameter: Thresholdfortotalwhitepixels_const
   * Referenced by: '<S505>/Constant'
   */
  10U,

  /* Expression: 2
   * Referenced by: '<S2>/Constant'
   */
  2.0,

  /* Computed Parameter: RateTransition_InitialCondition
   * Referenced by: '<Root>/Rate Transition'
   */
  false,

  /* Start of '<Root>/Control System' */
  {
    /* Mask Parameter: outlierBelowFloor_const
     * Referenced by: '<S243>/Constant'
     */
    0.0,

    /* Mask Parameter: outlierJump_const
     * Referenced by: '<S298>/Constant'
     */
    0.1,

    /* Mask Parameter: currentEstimateVeryOffFromPressure_const
     * Referenced by: '<S296>/Constant'
     */
    0.8,

    /* Mask Parameter: currentStateVeryOffsonarflt_const
     * Referenced by: '<S297>/Constant'
     */
    0.4,

    /* Mask Parameter: Checkerrorcondition_const
     * Referenced by: '<S219>/Constant'
     */
    -1.0,

    /* Mask Parameter: u0continuousOFerrors_const
     * Referenced by: '<S218>/Constant'
     */
    50.0,

    /* Mask Parameter: Angularvelocitycontrolloop_D
     * Referenced by: '<S94>/Derivative Gain'
     */
    { 0.00012F, 9.72E-5F },

    /* Mask Parameter: Angularvelocitycontrolloop_I
     * Referenced by: '<S97>/Integral Gain'
     */
    { 0.006F, 0.00486F },

    /* Mask Parameter: Velocitycontroller_I
     * Referenced by: '<S198>/Integral Gain'
     */
    0.1F,

    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
     * Referenced by: '<S433>/UD'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForFilter
     * Referenced by: '<S95>/Filter'
     */
    0.0F,

    /* Mask Parameter: Velocitycontroller_InitialConditionForIntegrator
     * Referenced by: '<S201>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForIntegrator
     * Referenced by: '<S100>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Positioncontroller_LowerSaturationLimit
     * Referenced by: '<S158>/Saturation'
     */
    -0.5F,

    /* Mask Parameter: Velocitycontroller_LowerSaturationLimit
     * Referenced by:
     *   '<S208>/Saturation'
     *   '<S194>/DeadZone'
     */
    -0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_LowerSaturationLimit
     * Referenced by:
     *   '<S107>/Saturation'
     *   '<S93>/DeadZone'
     */
    -0.02F,

    /* Mask Parameter: Angularvelocitycontrolloop_N
     * Referenced by: '<S103>/Filter Coefficient'
     */
    { 70.0F, 70.0F },

    /* Mask Parameter: Positioncontroller_P
     * Referenced by: '<S156>/Proportional Gain'
     */
    0.7F,

    /* Mask Parameter: Velocitycontroller_P
     * Referenced by: '<S206>/Proportional Gain'
     */
    0.2F,

    /* Mask Parameter: Anglecontrolloop_P
     * Referenced by: '<S55>/Proportional Gain'
     */
    4.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_P
     * Referenced by: '<S105>/Proportional Gain'
     */
    { 0.003F, 0.00243F },

    /* Mask Parameter: Positioncontroller_UpperSaturationLimit
     * Referenced by: '<S158>/Saturation'
     */
    0.5F,

    /* Mask Parameter: Velocitycontroller_UpperSaturationLimit
     * Referenced by:
     *   '<S208>/Saturation'
     *   '<S194>/DeadZone'
     */
    0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_UpperSaturationLimit
     * Referenced by:
     *   '<S107>/Saturation'
     *   '<S93>/DeadZone'
     */
    0.02F,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S300>/Constant'
     */
    6.867F,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S301>/Constant'
     */
    12.753F,

    /* Mask Parameter: maxp_const
     * Referenced by: '<S436>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxq_const
     * Referenced by: '<S438>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxw1_const
     * Referenced by: '<S440>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxw2_const
     * Referenced by: '<S441>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxdw1_const
     * Referenced by: '<S434>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxdw2_const
     * Referenced by: '<S435>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxp2_const
     * Referenced by: '<S437>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxq2_const
     * Referenced by: '<S439>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxw3_const
     * Referenced by: '<S442>/Constant'
     */
    5.0F,

    /* Mask Parameter: maxw4_const
     * Referenced by: '<S443>/Constant'
     */
    5.0F,

    /* Mask Parameter: minHeightforOF_const
     * Referenced by: '<S444>/Constant'
     */
    -0.4F,

    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S428>/Constant'
     */
    -0.4F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
     * Referenced by: '<S430>/Constant'
     */
    0.0F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
     * Referenced by: '<S431>/Constant'
     */
    0.0F,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S222>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S224>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S223>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S225>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant_const_j
     * Referenced by: '<S220>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant1_const_e
     * Referenced by: '<S221>/Constant'
     */
    10.0F,

    /* Mask Parameter: WrapToZero_Threshold
     * Referenced by: '<S233>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_k
     * Referenced by: '<S501>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_e
     * Referenced by: '<S420>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: CompareToConstant_const_l
     * Referenced by: '<S416>/Constant'
     */
    1U,

    /* Mask Parameter: CompareToConstant_const_h
     * Referenced by: '<S498>/Constant'
     */
    800U,

    /* Mask Parameter: WrapToZero_Threshold_c
     * Referenced by: '<S16>/FixPt Switch'
     */
    65535U,

    /* Mask Parameter: CompareToConstant_const_c
     * Referenced by: '<S13>/Constant'
     */
    100U,

    /* Expression: 0
     * Referenced by: '<S4>/ '
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S5>/xValue'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S5>/zValue'
     */
    -1.0,

    /* Expression: 1
     * Referenced by: '<S5>/LatchValue'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S292>/L*(y[k]-yhat[k|k-1])'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S294>/deltax'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S414>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S236>/Delay2'
     */
    0.0,

    /* Expression: pInitialization.X0
     * Referenced by: '<S240>/X0'
     */
    { -0.046, 0.0 },

    /* Expression: -inf
     * Referenced by: '<S241>/SaturationSonar'
     */
    0.0,

    /* Expression: Estimator.alt.filterSonarNum
     * Referenced by: '<S241>/sonarFilter_IIR'
     */
    { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
      3.7568380197512489E-6 },

    /* Expression: Estimator.alt.filterSonarDen
     * Referenced by: '<S241>/sonarFilter_IIR'
     */
    { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

    /* Expression: 0
     * Referenced by: '<S241>/sonarFilter_IIR'
     */
    0.0,

    /* Expression: pInitialization.M
     * Referenced by: '<S244>/KalmanGainM'
     */
    { 0.026241420641872265, 0.0697767360714946 },

    /* Expression: pInitialization.C
     * Referenced by: '<S240>/C'
     */
    { 1.0, 0.0 },

    /* Expression: pInitialization.M
     * Referenced by: '<S307>/KalmanGainM'
     */
    { 0.0011869299883620552, -3.2868164179443354E-5 },

    /* Expression: pInitialization.M
     * Referenced by: '<S361>/KalmanGainM'
     */
    { 0.0011869299883620552, -3.2868164179443354E-5 },

    /* Expression: pInitialization.M
     * Referenced by: '<S445>/KalmanGainM'
     */
    { 0.066408162001371535, 0.0, -0.021605460397771489, 0.0, 0.0,
      0.066408162001371535, 0.0, -0.021605460397771493 },

    /* Expression: pInitialization.L
     * Referenced by: '<S445>/KalmanGainL'
     */
    { 0.066516189303360354, 5.23402355848703E-19, -0.021605460397771867,
      -4.8628553107267881E-19, 4.3622439914025292E-18, 0.066516189303360354,
      -4.5659075919712689E-17, -0.021605460397771864 },

    /* Expression: [0 0 -g]
     * Referenced by: '<S423>/gravity'
     */
    { 0.0, 0.0, -9.81 },

    /* Expression: 1
     * Referenced by: '<S423>/gainaccinput1'
     */
    1.0,

    /* Expression: 0.0
     * Referenced by: '<S5>/Delay1'
     */
    0.0,

    /* Expression: 0.0
     * Referenced by: '<S5>/Delay'
     */
    0.0,

    /* Expression: pInitialization.A
     * Referenced by: '<S240>/A'
     */
    { 1.0, 0.0, 0.005, 1.0 },

    /* Expression: [0 0 g]
     * Referenced by: '<S236>/gravity'
     */
    { 0.0, 0.0, 9.81 },

    /* Expression: pInitialization.L
     * Referenced by: '<S361>/KalmanGainL'
     */
    { 0.0011870943291829544, -3.2868164179443428E-5 },

    /* Expression: pInitialization.L
     * Referenced by: '<S307>/KalmanGainL'
     */
    { 0.0011870943291829544, -3.2868164179443428E-5 },

    /* Expression: pInitialization.B
     * Referenced by: '<S240>/B'
     */
    { 0.0, 0.005 },

    /* Expression: pInitialization.D
     * Referenced by: '<S240>/D'
     */
    0.0,

    /* Expression: pInitialization.L
     * Referenced by: '<S244>/KalmanGainL'
     */
    { 0.026590304322229696, 0.069776736071494483 },

    /* Expression: 200*3
     * Referenced by: '<S4>/Wait  3 Seconds'
     */
    600.0,

    /* Expression: 0.0
     * Referenced by: '<S4>/Delay One Step'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S4>/0.5 meters'
     */
    0.5,

    /* Expression: pInitialization.Z
     * Referenced by: '<S445>/CovarianceZ'
     */
    { 1.3281632400274306, 0.0, -0.43210920795542973, 0.0, 0.0,
      1.3281632400274306, 0.0, -0.43210920795542984, -0.43210920795542979, 0.0,
      6.14734986237778, 0.0, 0.0, -0.43210920795542984, 0.0, 6.14734986237778 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S244>/CovarianceZ'
     */
    { 0.0026241420641872266, 0.0069776736071494585, 0.0069776736071494594,
      0.037607692935053338 },

    /* Expression: pInitialization.P0
     * Referenced by: '<S240>/P0'
     */
    { 0.002694858992582106, 0.0071657120718247548, 0.0071657120718247548,
      0.038107692935053374 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S307>/CovarianceZ'
     */
    { 1097.3834951572255, -30.388465402591859, -30.388465402591855,
      7.2223686232128914 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S361>/CovarianceZ'
     */
    { 1097.3834951572255, -30.388465402591859, -30.388465402591855,
      7.2223686232128914 },

    /* Expression: pInitialization.G
     * Referenced by: '<S240>/G'
     */
    { 0.0, 1.0 },

    /* Expression: pInitialization.H
     * Referenced by: '<S240>/H'
     */
    0.0,

    /* Expression: pInitialization.N
     * Referenced by: '<S240>/N'
     */
    0.0,

    /* Expression: pInitialization.Q
     * Referenced by: '<S240>/Q'
     */
    0.0005,

    /* Expression: pInitialization.R
     * Referenced by: '<S240>/R'
     */
    0.1,

    /* Expression: Controller.takeoffGain
     * Referenced by: '<S7>/takeoff_gain1'
     */
    0.2F,

    /* Computed Parameter: P_z1_Gain
     * Referenced by: '<S7>/P_z1'
     */
    0.8F,

    /* Computed Parameter: D_z1_Gain
     * Referenced by: '<S7>/D_z1'
     */
    0.5F,

    /* Computed Parameter: Pitchcorrection_Value
     * Referenced by: '<S9>/Pitch correction'
     */
    0.002F,

    /* Computed Parameter: zerocorrection_Value
     * Referenced by: '<S9>/zero correction'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain
     * Referenced by: '<S10>/Gain'
     */
    { -1.0F, 1.0F },

    /* Computed Parameter: _Value_i
     * Referenced by: '<S4>/    '
     */
    0.0F,

    /* Computed Parameter: X_Y0
     * Referenced by: '<S235>/X'
     */
    0.0F,

    /* Computed Parameter: Y_Y0
     * Referenced by: '<S235>/Y'
     */
    0.0F,

    /* Computed Parameter: Landinglookaheaddistance_Value
     * Referenced by: '<S234>/Landing look-ahead distance'
     */
    0.2F,

    /* Computed Parameter: Gain_Gain_k
     * Referenced by: '<S414>/Gain'
     */
    0.00228F,

    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S418>/Out1'
     */
    0.0F,

    /* Computed Parameter: Lykyhatkk1_Y0_c
     * Referenced by: '<S495>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F,

    /* Computed Parameter: deltax_Y0_k
     * Referenced by: '<S497>/deltax'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_p
     * Referenced by: '<S427>/Gain'
     */
    -1.0F,

    /* Computed Parameter: opticalFlowErrorCorrect_Gain
     * Referenced by: '<S427>/opticalFlowErrorCorrect'
     */
    1.15F,

    /* Expression: Controller.Q2Ts
     * Referenced by: '<S9>/TorqueTotalThrustToThrustPerMotor'
     */
    { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
      -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F,
      5.66592F, 5.66592F, -5.66592F },

    /* Computed Parameter: A_Value_a
     * Referenced by: '<S426>/A'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.005F, 0.0F, 1.0F, 0.0F,
      0.0F, -0.005F, 0.0F, 1.0F },

    /* Computed Parameter: SimplyIntegrateVelocity_gainval
     * Referenced by: '<S422>/SimplyIntegrateVelocity'
     */
    0.005F,

    /* Computed Parameter: SimplyIntegrateVelocity_IC
     * Referenced by: '<S422>/SimplyIntegrateVelocity'
     */
    0.0F,

    /* Computed Parameter: invertzaxisGain_Gain
     * Referenced by: '<S236>/invertzaxisGain'
     */
    -1.0F,

    /* Computed Parameter: prsToAltGain_Gain
     * Referenced by: '<S236>/prsToAltGain'
     */
    0.0832137167F,

    /* Computed Parameter: pressureFilter_IIR_NumCoef
     * Referenced by: '<S241>/pressureFilter_IIR'
     */
    { 3.75683794E-6F, 1.12705138E-5F, 1.12705138E-5F, 3.75683794E-6F },

    /* Computed Parameter: pressureFilter_IIR_DenCoef
     * Referenced by: '<S241>/pressureFilter_IIR'
     */
    { 1.0F, -2.93717074F, 2.87629962F, -0.939098954F },

    /* Computed Parameter: pressureFilter_IIR_InitialStates
     * Referenced by: '<S241>/pressureFilter_IIR'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S304>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC
     * Referenced by: '<S304>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: X0_Value_i
     * Referenced by: '<S306>/X0'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
     * Referenced by: '<S238>/Assuming that the  preflight calibration was done at level orientation'
     */
    { 0.0F, 0.0F, 9.81F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: inverseIMU_gain_Gain
     * Referenced by: '<S238>/inverseIMU_gain'
     */
    { 0.994075298F, 0.996184587F, 1.00549F, 1.00139189F, 0.993601203F, 1.00003F
    },

    /* Computed Parameter: FIR_IMUaccel_InitialStates
     * Referenced by: '<S238>/FIR_IMUaccel'
     */
    0.0F,

    /* Computed Parameter: FIR_IMUaccel_Coefficients
     * Referenced by: '<S238>/FIR_IMUaccel'
     */
    { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
      0.0264077242F },

    /* Computed Parameter: Gain2_Gain
     * Referenced by: '<S302>/Gain2'
     */
    0.101936802F,

    /* Computed Parameter: Constant_Value_h
     * Referenced by: '<S305>/Constant'
     */
    2.0F,

    /* Computed Parameter: C_Value_h
     * Referenced by: '<S306>/C'
     */
    { 1.0F, 0.0F },

    /* Computed Parameter: X0_Value_iy
     * Referenced by: '<S360>/X0'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: C_Value_i
     * Referenced by: '<S360>/C'
     */
    { 1.0F, 0.0F },

    /* Computed Parameter: LPFFcutoff40Hz1_NumCoef
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz1'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz1_DenCoef
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz1'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz1_InitialStates
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz1'
     */
    0.0F,

    /* Computed Parameter: LPFFcutoff40Hz_NumCoef
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz_DenCoef
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz_InitialStates
     * Referenced by: '<S238>/LPF Fcutoff = 40Hz'
     */
    0.0F,

    /* Computed Parameter: IIR_IMUgyro_r_NumCoef
     * Referenced by: '<S238>/IIR_IMUgyro_r'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIR_IMUgyro_r_DenCoef
     * Referenced by: '<S238>/IIR_IMUgyro_r'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIR_IMUgyro_r_InitialStates
     * Referenced by: '<S238>/IIR_IMUgyro_r'
     */
    0.0F,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S304>/Constant'
     */
    0.0F,

    /* Computed Parameter: X0_Value_c
     * Referenced by: '<S426>/X0'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: C_Value_i2
     * Referenced by: '<S426>/C'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Gain1_Gain
     * Referenced by: '<S424>/Gain1'
     */
    -1.0F,

    /* Computed Parameter: IIRgyroz_NumCoef
     * Referenced by: '<S425>/IIRgyroz'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIRgyroz_DenCoef
     * Referenced by: '<S425>/IIRgyroz'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIRgyroz_InitialStates
     * Referenced by: '<S425>/IIRgyroz'
     */
    0.0F,

    /* Computed Parameter: TSamp_WtEt
     * Referenced by: '<S433>/TSamp'
     */
    200.0F,

    /* Computed Parameter: Delay_InitialCondition_k
     * Referenced by: '<S421>/Delay'
     */
    0.0F,

    /* Computed Parameter: Delay1_InitialCondition_p
     * Referenced by: '<S6>/Delay1'
     */
    0.0F,

    /* Computed Parameter: B_Value_f
     * Referenced by: '<S426>/B'
     */
    { 0.005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005F, 0.0F, 0.0F },

    /* Computed Parameter: D_Value_h
     * Referenced by: '<S426>/D'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S201>/Integrator'
     */
    0.005F,

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 8.95774746F, -6.95774698F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    0.0F,

    /* Computed Parameter: Integrator_gainval_i
     * Referenced by: '<S100>/Integrator'
     */
    0.005F,

    /* Computed Parameter: Filter_gainval
     * Referenced by: '<S95>/Filter'
     */
    0.005F,

    /* Computed Parameter: w1_Value
     * Referenced by: '<S7>/w1'
     */
    -0.66708F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_h
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    2.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    -2.0F,

    /* Computed Parameter: SaturationThrust1_UpperSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    1.20204329F,

    /* Computed Parameter: SaturationThrust1_LowerSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    -1.20204329F,

    /* Computed Parameter: Saturation_UpperSat
     * Referenced by: '<S11>/Saturation'
     */
    0.52359879F,

    /* Computed Parameter: Saturation_LowerSat
     * Referenced by: '<S11>/Saturation'
     */
    -0.52359879F,

    /* Computed Parameter: P_yaw_Gain
     * Referenced by: '<S11>/P_yaw'
     */
    0.004F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_d
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_b
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: D_yaw_Gain
     * Referenced by: '<S11>/D_yaw'
     */
    0.0012F,

    /* Computed Parameter: ThrustToMotorCommand_Gain
     * Referenced by: '<S12>/ThrustToMotorCommand'
     */
    -1530.72681F,

    /* Expression: Vehicle.Motor.maxLimit
     * Referenced by: '<S12>/Saturation5'
     */
    500.0F,

    /* Expression: Vehicle.Motor.minLimit
     * Referenced by: '<S12>/Saturation5'
     */
    10.0F,

    /* Computed Parameter: MotorDirections_Gain
     * Referenced by: '<S12>/MotorDirections'
     */
    { 1.0F, -1.0F, 1.0F, -1.0F },

    /* Computed Parameter: A_Value_k
     * Referenced by: '<S306>/A'
     */
    { 1.0F, 0.0F, -0.005F, 1.0F },

    /* Computed Parameter: A_Value_ah
     * Referenced by: '<S360>/A'
     */
    { 1.0F, 0.0F, -0.005F, 1.0F },

    /* Computed Parameter: B_Value_g
     * Referenced by: '<S360>/B'
     */
    { 0.005F, 0.0F },

    /* Computed Parameter: D_Value_k
     * Referenced by: '<S360>/D'
     */
    0.0F,

    /* Computed Parameter: B_Value_o
     * Referenced by: '<S306>/B'
     */
    { 0.005F, 0.0F },

    /* Computed Parameter: D_Value_kg
     * Referenced by: '<S306>/D'
     */
    0.0F,

    /* Computed Parameter: Constant5_Value
     * Referenced by: '<S91>/Constant5'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S91>/Constant1'
     */
    0.0F,

    /* Computed Parameter: Constant5_Value_p
     * Referenced by: '<S192>/Constant5'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value_c
     * Referenced by: '<S192>/Constant1'
     */
    0.0F,

    /* Computed Parameter: I_yaw_Gain
     * Referenced by: '<S11>/I_yaw'
     */
    0.002F,

    /* Computed Parameter: I_pr_Gain
     * Referenced by: '<S7>/I_pr'
     */
    0.24F,

    /* Computed Parameter: Gain_Gain_o
     * Referenced by: '<S4>/Gain'
     */
    1.0F,

    /* Computed Parameter: Gain1_Gain_p
     * Referenced by: '<S4>/Gain1'
     */
    1.0F,

    /* Computed Parameter: P0_Value_e
     * Referenced by: '<S426>/P0'
     */
    { 1.42263806F, 0.0F, -0.462845951F, 0.0F, 0.0F, 1.42263806F, 0.0F,
      -0.462845951F, -0.462845951F, 0.0F, 6.15735F, 0.0F, 0.0F, -0.462845951F,
      0.0F, 6.15735F },

    /* Computed Parameter: G_Value_i
     * Referenced by: '<S426>/G'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_m
     * Referenced by: '<S426>/Q'
     */
    { 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.01F },

    /* Computed Parameter: H_Value_i
     * Referenced by: '<S426>/H'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: N_Value_i
     * Referenced by: '<S426>/N'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: P0_Value_h
     * Referenced by: '<S306>/P0'
     */
    { 1098.6875F, -30.4245777F, -30.4245777F, 7.22336864F },

    /* Computed Parameter: G_Value_m
     * Referenced by: '<S306>/G'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_j
     * Referenced by: '<S306>/Q'
     */
    { 1.0F, 0.0F, 0.0F, 0.001F },

    /* Computed Parameter: P0_Value_l
     * Referenced by: '<S360>/P0'
     */
    { 1098.6875F, -30.4245777F, -30.4245777F, 7.22336864F },

    /* Computed Parameter: G_Value_g
     * Referenced by: '<S360>/G'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_p
     * Referenced by: '<S360>/Q'
     */
    { 1.0F, 0.0F, 0.0F, 0.001F },

    /* Computed Parameter: R_Value_h
     * Referenced by: '<S426>/R'
     */
    { 20.0F, 0.0F, 0.0F, 20.0F },

    /* Computed Parameter: H_Value_a
     * Referenced by: '<S306>/H'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: N_Value_f
     * Referenced by: '<S306>/N'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: H_Value_o
     * Referenced by: '<S360>/H'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: N_Value_b
     * Referenced by: '<S360>/N'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: R_Value_a
     * Referenced by: '<S306>/R'
     */
    924556.188F,

    /* Computed Parameter: R_Value_l
     * Referenced by: '<S360>/R'
     */
    924556.188F,

    /* Computed Parameter: Movetorightfactor_Gain
     * Referenced by: '<S5>/Move to right factor'
     */
    3518437209U,

    /* Computed Parameter: Output_InitialCondition
     * Referenced by: '<S417>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_f
     * Referenced by: '<S499>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_h
     * Referenced by: '<S226>/Output'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value
     * Referenced by: '<S232>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_a
     * Referenced by: '<S233>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_p
     * Referenced by: '<S500>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_e
     * Referenced by: '<S501>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_m
     * Referenced by: '<S419>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_jy
     * Referenced by: '<S420>/Constant'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_fi
     * Referenced by: '<S14>/Output'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_g
     * Referenced by: '<S15>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S16>/Constant'
     */
    0U,

    /* Computed Parameter: controlModePosVsOrient_Value
     * Referenced by: '<S1>/controlModePosVsOrient'
     */
    true,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S493>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S290>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S355>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S409>/isSqrtUsed'
     */
    false,

    /* Computed Parameter: Constant_Value_km
     * Referenced by: '<S91>/Constant'
     */
    1,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S91>/Constant2'
     */
    -1,

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S91>/Constant3'
     */
    1,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S91>/Constant4'
     */
    -1,

    /* Computed Parameter: Constant_Value_p
     * Referenced by: '<S192>/Constant'
     */
    1,

    /* Computed Parameter: Constant2_Value_f
     * Referenced by: '<S192>/Constant2'
     */
    -1,

    /* Computed Parameter: Constant3_Value_d
     * Referenced by: '<S192>/Constant3'
     */
    1,

    /* Computed Parameter: Constant4_Value_p
     * Referenced by: '<S192>/Constant4'
     */
    -1,

    /* Computed Parameter: Disabletemperaturecompensation_CurrentSetting
     * Referenced by: '<S414>/Disable temperature compensation'
     */
    1U,

    /* Computed Parameter: ManualSwitch_CurrentSetting
     * Referenced by: '<S9>/Manual Switch'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S4>/Merge'
     */
    0U,

    /* Start of '<S387>/Enabled Subsystem' */
    {
      /* Computed Parameter: deltax_Y0
       * Referenced by: '<S413>/deltax'
       */
      0.0F
    }
    ,

    /* End of '<S387>/Enabled Subsystem' */

    /* Start of '<S380>/MeasurementUpdate' */
    {
      /* Computed Parameter: Lykyhatkk1_Y0
       * Referenced by: '<S411>/L*(y[k]-yhat[k|k-1])'
       */
      0.0F
    }
    ,

    /* End of '<S380>/MeasurementUpdate' */

    /* Start of '<S333>/Enabled Subsystem' */
    {
      /* Computed Parameter: deltax_Y0
       * Referenced by: '<S359>/deltax'
       */
      0.0F
    }
    ,

    /* End of '<S333>/Enabled Subsystem' */

    /* Start of '<S326>/MeasurementUpdate' */
    {
      /* Computed Parameter: Lykyhatkk1_Y0
       * Referenced by: '<S357>/L*(y[k]-yhat[k|k-1])'
       */
      0.0F
    }
    ,

    /* End of '<S326>/MeasurementUpdate' */

    /* Start of '<S4>/Normal condition' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S229>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Normal condition' */

    /* Start of '<S4>/Ultrasound improper' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S230>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Ultrasound improper' */

    /* Start of '<S4>/No optical flow ' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S228>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/No optical flow ' */

    /* Start of '<S4>/estimator//Optical flow error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S231>/Constant'
       */
      99U
    }
    ,

    /* End of '<S4>/estimator//Optical flow error' */

    /* Start of '<S4>/Geofencing error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S227>/Constant'
       */
      1U
    }
    /* End of '<S4>/Geofencing error' */
  }
  /* End of '<Root>/Control System' */
};
