#ifndef SRC_DATE_H
#define SRC_DATE_H

#include <vector>
#include <utility>

class Date {
    public:
        Date() = default;
        ~Date() = default;
        static std::pair<float, float> calculateNumbers(std::vector<float> &hours);
        static float calculateExtraHours(float &hour);
};

#endif  