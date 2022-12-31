#include <iostream>
#include <map>
#include <vector>
#include "utils/colormod.h"
#include "date.h"

void allocateInputValue(std::vector<float> *week, float &input) {
    week->push_back(input);
}

int main() {
    int i, j, k, weekNo, monthDay, optionsNo;
    float firstIn, firstOut, lastIn, lastOut, inputVal;

    std::map<char,int> weekValues;
    color::modifier magenta(color::FG_MAGENTA);
    color::modifier def(color::FG_DEFAULT);

    std::cout << magenta << "    (CLOCKIN 0.1)    " << std::endl;

    std::cout << def << "    Digite a quantidade de semanas" << std::endl;
    std::cin >> weekNo;
    std::cout << "    Digite o mes" << std::endl;
    std::cin >> monthDay;

    for (int i = 0; i < weekNo; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "    Digite a primeira hora de entrada" << std::endl;
            std::cin  >> firstIn;
            std::cout << "    Digite a primeira hora de saida" << std::endl;
            std::cin  >> firstOut;
            std::cout << "    Digite a ultima hora de entrada" << std::endl;
            std::cin  >> lastIn;
            std::cout << "    Digite a ultima hora de saida" << std::endl;    
            std::cin  >> lastOut;
            Date::calculateNumbers(firstIn, firstOut, lastIn, lastOut);
        }
    }
    return 0;
}
