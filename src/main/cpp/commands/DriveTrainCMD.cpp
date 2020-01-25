/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveTrainCMD.h"
#include "../include/Robot.h"


DriveTrainCMD::DriveTrainCMD() 
{
  //Work on addRequirements() and hooking up controller to code

  // Use addRequirements() here to declare subsystem dependencies.
}

DriveTrainCMD::DriveTrainCMD(DriveTrain* subsystem)
{
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void DriveTrainCMD::Initialize()
{
 //Robot::m_drivetrain.Init();
}

// Called repeatedly when this Command is scheduled to run
void DriveTrainCMD::Execute() {}

// Called once the command ends or is interrupted.
void DriveTrainCMD::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveTrainCMD::IsFinished() { return false; }
