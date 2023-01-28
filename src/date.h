#ifndef SRC_DATE_H
#define SRC_DATE_H

#include <utility>
#include <vector>

class Date {
public:
  Date();
  ~Date();
  static std::pair<float, float> calculateNumbers(std::vector<float> &hours);
  static float calculateExtraHours(float &hour);
};

#endif