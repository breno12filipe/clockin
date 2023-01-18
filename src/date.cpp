#include <iostream>
#include <vector>
#include "date.h"

float Date::calculateNumbers(std::vector<float> &hours){
    float firstSub, secondSub;
    firstSub  = hours[0] - hours[1];
    secondSub = hours[2] - hours[3];
    return secondSub + firstSub;
}