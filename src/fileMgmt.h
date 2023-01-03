#ifndef SRC_FILE_MGMT_H
#define SRC_FILE_MGMT_H
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class FileMgmt{
    public:
        std::string inputFilePath;
        std::string outputFilePath;
        FileMgmt(std::string inputPath, std::string outputPath){
            inputFilePath = inputPath;
            outputFilePath = outputPath;
        };
        ~FileMgmt();
        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;
        std::string line, word;
        void readCsvFileLoadContentMemory();
        void showLoadedMemoryContent();
};

#endif