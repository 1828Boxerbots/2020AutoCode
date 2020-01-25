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
    m_leftMotor.SetInverted(true);
    m_rightMotor.SetInverted(false);
    m_gyro.Calibrate();
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
    //Checking if time is invalid
    if(time < 0.0)
    {
        Stop();
        return;
    }

    //Start Moving
    Forward();

    //Use FRC timer to get current time
    frc::Timer timer;
    double startTime = timer.Get();
    double currentTime = timer.Get();

    //Keep looping until end time is reached
    while(currentTime - startTime < time)
    {
        currentTime = timer.Get();
    }

    //Stop moving
    Stop();
}
//function used to make the robot turn in a relative angle
void DriveTrain::TurnInDegrees(double relativeAngle)
{
    m_gyro.Reset();
    m_gyro.GetAngle();
    //displays to smartdashboard to check angle
    frc::SmartDashboard::PutNumber("Current Angle", m_gyro.GetAngle());
    //statements meant for determining if angle is negative or positive
    if(relativeAngle > 0)
    {
     while(relativeAngle < m_gyro.GetAngle())   
     {
         TurnRight();
     }
    }
    if(relativeAngle < 0)
    {
        while(relativeAngle > m_gyro.GetAngle())
        {
            TurnLeft();
        }
    }
    Stop();
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
