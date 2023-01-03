#include <iostream>
#include "date.h"

float Date::calculateNumbers(float firstIn, float firstOut, float lastIn, float lastOut){
    float firstSub, secondSub;
    firstSub  = firstIn - firstOut;
    secondSub = lastOut - lastIn; 
    return lastIn - lastOut + firstIn - firstOut;
}