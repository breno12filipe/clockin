#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <cstdlib>
#include <list>
#include <math.h>
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
    for (int i = 0; i < this->content.size(); i++) {
        if (std::regex_match(this->content[i], std::regex("[+-]?([0-9]*[.])?[0-9]+"))) {
            if (!std::regex_match(this->content[i], std::regex("^\\d+$"))) {
                parsedVals.emplace_back(atof(this->content[i].c_str()));
                if (parsedVals.size() == 4) {
                    outputResult.emplace_back(Date::calculateNumbers(parsedVals));
                    parsedVals.clear();
                }
                continue;
            }
        }
    }
}

void FileMgmt::writeOutputValuesIntoFile() {
    // escreve isso no arquivo em uma unica linha
    std::list<std::string> header = {"primeira_entrada", "primeira_saida", "ultima_entrada", "ultima_saida", "dia_mes", "horas_trabalhadas", "horas_extras"};
    int counter = 0;

    for (int i = 0; i < this->content.size(); i++) {
        if (std::regex_match(this->content[i], std::regex("[+-]?([0-9]*[.])?[0-9]+")) && 
            !std::regex_match(this->content[i], std::regex("^\\d+$"))) {
            // escreve isso no arquivo
            std::cout << this->content[i] << ", ";
            counter++;
            if (counter == 4) {
                std::cout << "\n";
                counter = 0;
            }

        }
    }
    // escreve isso no arquivo, depois das linhas
    for (int k = 0; k < this->outputResult.size(); k++) {
        std::cout << this->outputResult[k].first << ", ";
        std::cout << this->outputResult[k].second << std::endl;
    }



    
}
