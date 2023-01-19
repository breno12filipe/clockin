#include <iostream>
#include <vector>
#include "date.h"

std::pair<float, float> Date::calculateNumbers(std::vector<float> &hours) {
    float firstSub, secondSub, workedHoursResult;
    std::pair<float, float> resultPair;

    firstSub  = hours[1] - hours[0];
    secondSub = hours[3] - hours[2];
    workedHoursResult  = secondSub + firstSub;
    
    resultPair.first  = workedHoursResult;
    resultPair.second = calculateExtraHours(workedHoursResult); 
    return resultPair;
}

float Date::calculateExtraHours(float &hour) {
    return hour - 8;
}