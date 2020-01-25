/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Util.h"

double Util::Limit(double value, double lower, double upper)
{
    if(lower > upper)
    {
        return value;
    }

    if(value < lower)
    {
        value = lower;
    }
    else if(value > upper)
    {
        value = upper;
    }

    return value;
}
