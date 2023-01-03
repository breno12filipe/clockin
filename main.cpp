#include <iostream>
#include <string>
#include "utils/colormod.h"
#include "fileMgmt.h"

int main() {
    color::modifier magenta(color::FG_MAGENTA);
    color::modifier def(color::FG_DEFAULT);

    std::string inputPath, outputPath;
    std::cout << magenta << "    (CLOCKIN 0.1)    " << std::endl;
    std::cout << "Digite o local de origem do arquivo:" << std::endl;
    std::cin  >> inputPath;
    std::cout << "Digite o local de destino do arquivo:" << std::endl;
    std::cin  >> outputPath;

    FileMgmt* FileManager = new FileMgmt(inputPath, outputPath);
    return 0;
}
