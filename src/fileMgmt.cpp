#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <cstdlib>
#include "fileMgmt.h"

FileMgmt::FileMgmt(std::string inputPath, std::string outputPath) {
    this->inputPath = inputPath;
    this->outputPath = outputPath;
};

void FileMgmt::readCsvFileLoadContentMemory() {
    std::fstream file(this->inputPath, std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, this->line)) {
            this->row.clear();
            std::stringstream str(this->line);
            while (std::getline(str, this->word, ',')) {
                // this->row.push_back(this->word);
                this->content.push_back(this->word);
            }
        }
    }
    else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
    }
}

void FileMgmt::showLoadedMemoryContent() {
    for (int i = 0; i < this->content.size(); i++) {
        for (int j = 0; j < this->content[i].size(); j++) {
            std::cout << this->content[i][j];
        }
        std::cout << "\n";
    }
}

void FileMgmt::parseCsvFileValues() {
    std::vector<float> parsedVals;
    std::pair<float, float> result;
    for (int i = 0; i < this->content.size(); i++) {
        if (std::regex_match(this->content[i], std::regex("[+-]?([0-9]*[.])?[0-9]+"))) {
            if (!std::regex_match(this->content[i], std::regex("^\\d+$"))) {
                parsedVals.emplace_back(atof(this->content[i].c_str()));
                if (parsedVals.size() == 4) {
                    result = Date::calculateNumbers(parsedVals);
                    outputResult.first  = result.first;
                    outputResult.second = result.second;
                    parsedVals.clear();
                }
                continue;
            }
        }
    }
}

void FileMgmt::writeOutputValuesIntoFile() {
    std::cout << "Chegou no writeOutputValuesIntoFile" << std::endl;
    //std::ofstream outputFile(this->outputPath);
    //outputFile << "abcywok";
    //outputFile.close();
}