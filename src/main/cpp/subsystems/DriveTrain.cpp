/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "../include/Util.h"

DriveTrain::DriveTrain() {}

void DriveTrain::Init()
{
    m_leftMotor.SetInverted(false);
    m_rightMotor.SetInverted(true);
    m_gyro.Calibrate();
    m_gyro.Reset();
}

//Motors Move
void DriveTrain::TankDrive(double leftY, double rightY)
{
    m_leftMotor.Set(Util::Limit(leftY));
    m_rightMotor.Set(Util::Limit(rightY));
}
//Motors Stop
void DriveTrain::Stop()
{
    m_leftMotor.Set(NOPOWER);
    m_rightMotor.Set(NOPOWER);
}

//The Robot will move in Arcade drive
void DriveTrain::ArcadeDrive(double joyY, double joyX)
{
    double left = -joyX + joyY;
    double right = -joyX + joyY;
    TankDrive(left, right);
}

void DriveTrain::Forward(double speed)
{
    m_leftMotor.Set(Util::Limit(speed));
    m_rightMotor.Set(Util::Limit(speed));
}

void DriveTrain::TurnRight(double speed)
{
    m_leftMotor.Set(Util::Limit(speed));
    m_rightMotor.Set(Util::Limit(-speed));
}
void DriveTrain::TurnLeft(double speed)
{
    m_leftMotor.Set(Util::Limit(-speed));
    m_rightMotor.Set(Util::Limit(speed));
}


void DriveTrain::ForwardInSec(double time)
{
    frc::SmartDashboard::PutNumber("Time", time);
    //Checking if time is invalid
    if(time < 0.0)
    {
        Stop();
        return;
    }

    //Start Moving
    Forward();
    frc::SmartDashboard::PutNumber("Start Time", -1);
    Util::DelayInSeconds(time);
    //Stop moving
    Stop();
     frc::SmartDashboard::PutNumber("End Time", -610);
}
//function used to make the robot turn in a relative angle
void DriveTrain::TurnInDegrees(double relativeAngle)
{
    //displays to smartdashboard to check angle
    double startAngle = m_gyro.GetAngle();
    frc::SmartDashboard::PutNumber("Start Angle", startAngle);
    frc::SmartDashboard::PutNumber("Relative Angle", relativeAngle);
    //statements meant for determining if angle is negative or positive
    if(relativeAngle > 0)
    {
        frc::SmartDashboard::PutString("Turning", "Right");
        TurnRight();
        frc::SmartDashboard::PutNumber("Current Angle Right", m_gyro.GetAngle());
        while(relativeAngle > m_gyro.GetAngle() - startAngle)   
        {
            frc::SmartDashboard::PutNumber("Current Angle Right", m_gyro.GetAngle());
        }
    }
    else
    {
        frc::SmartDashboard::PutString("Turning", "Left");
       TurnLeft();
        frc::SmartDashboard::PutNumber("Current Angle Right", m_gyro.GetAngle());
        while(relativeAngle < m_gyro.GetAngle() - startAngle)
        {
            frc::SmartDashboard::PutNumber("Current Angle Left", m_gyro.GetAngle());
        }
    }
    frc::SmartDashboard::PutNumber("End Angle", 555);
    Stop();
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
