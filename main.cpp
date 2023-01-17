#include <iostream>
#include <string>
#include <vector>
#include "utils/colormod.h"
#include "src/fileMgmt.h"

int main() {
    color::modifier magenta(color::FG_MAGENTA);
    color::modifier def(color::FG_DEFAULT);
    color::modifier blue(color::FG_BLUE);
    color::modifier green(color::FG_GREEN);
    

    std::string inputPath, outputPath;
    std::cout << blue << "\n\n       ###############" << std::endl;
    std::cout << green << "        (CLOCKIN 1.0)" << std::endl;
    std::cout << blue << "       ###############" << std::endl;
    std::cout << def     << "Digite o local de origem do arquivo:" << std::endl;
    std::cin  >> inputPath;
    std::cout << "Digite o local de destino do arquivo:" << std::endl;
    std::cin  >> outputPath;

    FileMgmt* FileManager = new FileMgmt(inputPath, outputPath);
    FileManager->readCsvFileLoadContentMemory();
    FileManager->parseCsvFileValues();
    
    return 0;
}
