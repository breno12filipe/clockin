#include <iostream>
#include <sstream>
#include <string>
#include "fileMgmt.h"

void FileMgmt::readCsvFileLoadContentMemory() {
    std::fstream file(this->inputFilePath, std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, this->line)) {
            this->row.clear();
            std::stringstream str(this->line);
            while (std::getline(str, this->word, ',')) {
                this->row.push_back(this->word);
                this->content.push_back(this->row);
            }
        }
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
    }
}

// TODO: Check the printed output of this method!
void FileMgmt::showLoadedMemoryContent() {
    std::stringstream headerResult;
    std::stringstream contentResult;
    for (int i = 0; i < this->content.size(); i++) {
        for (int j = 0; j < this->content[i].size(); j++) {
            std::cout << this->content[i][j] << " ";
        }
        std::cout << "\n";
    }
}