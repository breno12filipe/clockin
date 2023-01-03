#include <iostream>

#include "fileMgmt.h"

int FileMgmt::readCsvFileLoadContentMemory() {
    std::fstream file(this -> inputFilePath, std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, this -> line)) {
            this -> row.clear();
            std::stringstream str(this -> line);
            while (std::getline(str, this -> word, ',')) {
                row.push_back(this -> word);
                content.push_back(this -> row);
            }
        }
    } else {
        std::cout << "Não foi possível abrir o arquivo" << std::endl;

        for (int i = 0; i < content.size(); i++) {
            for (int j = 0; j < content[i].size(); j++) {
                std::cout << content[i][j] << " ";
            }
            std::cout << "\n";
        }
        return 0;
    }
}