/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include "Constants.h"
#include <frc/ADXRS450_Gyro.h>
#include <frc/SmartDashboard/SmartDashboard.h>

class DriveTrain : public frc2::SubsystemBase {
 public:

  DriveTrain();
  
  //Functions
  //Moves robot using Tank Drive
  //leftY - Power level of left motor
  //rightY - Power level of right motor
  void TankDrive(double leftY, double rightY);

  //Moves robot using Arcade Drive
  //joyY - Value of the Y on the joystick
  //joyX - Value of the X on the joystick
  void ArcadeDrive(double joyY, double joyX);

  //Stops all motors
  void Stop();

  //Turns the robot to the given angle relative to 0
  //relativeAngle - The angle relative to 0 the robot wants to move to
  //speed - How fast the robot is turning
  void TurnInDegrees(double relativeAngle);

  //Moves the robot forward based on the speed
  //speed - How fast the robot is moving
  void Forward(double speed = 1.0);

  //Moves the robot forward for a certain amount of time
  //time - How long the robot is moving
  void ForwardInSec(double time);

  //Used in TurnInDegrees() only to turn right
  void TurnRight(double speed = 1.0);

  //used in TurnInDegrees() only to turn left
  void TurnLeft(double speed = 1.0);

  //When the program starts this function runs
  //Inverts the motors on the robot
  void Init();

  //Variables
  private:
  const double NOPOWER = 0.0;

  //The percentage of how much power is being used

  /*
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  //Objects
  frc::Spark m_leftMotor{PWM_LEFTMOTOR};
  frc::Spark m_rightMotor{PWM_RIGHTMOTOR};
  //Hooks up gyro to correct port
  frc::ADXRS450_Gyro m_gyro{frc::SPI::Port::kOnboardCS0};
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
