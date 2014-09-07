//
//  eNUm.cpp
//  AIE Basic Framework
//
//  Created by MAXXIE on 9/6/14.
//  Copyright (c) 2014 AIE. All rights reserved.
//

#include "iostream"
using namespace std;

enum DaysOfWeek

{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

DaysOfWeek today;



void main ()
{
    today = DaysOfWeek::FRIDAY;
    
    system("pause");
}
