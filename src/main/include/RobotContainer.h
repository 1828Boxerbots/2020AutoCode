/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include "commands/DriveTrainCMD.h"
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/DriveTrain.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  DriveTrain m_driveTrain;
  DriveTrainCMD m_driveTrainCMD;
  frc2::SequentialCommandGroup m_driveAutonomous = frc2::SequentialCommandGroup
  {
    frc2::InstantCommand([this] {m_driveTrain.Init();}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(3);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.TurnInDegrees(45);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(3);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.TurnInDegrees(45);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(2);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.TurnInDegrees(45);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(3);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.TurnInDegrees(45);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(3);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.TurnInDegrees(90);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.ForwardInSec(5);}, {&m_driveTrain}),
    frc2::InstantCommand([this] { m_driveTrain.Stop();}, {&m_driveTrain})
    };
  void ConfigureButtonBindings();
};
