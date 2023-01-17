#ifndef SRC_FILE_MGMT_H
#define SRC_FILE_MGMT_H
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// TODO: Check the access modifiers and return of the methods
class FileMgmt{
    public:
        FileMgmt(std::string, std::string);
        ~FileMgmt();
        std::string inputPath, outputPath, line, word;
        //std::vector<std::vector<std::string>> content;
        std::vector<std::string> content;
        std::vector<std::string> row;
        void readCsvFileLoadContentMemory();
        void showLoadedMemoryContent();
        void generateOutputCsvFile();
        void parseCsvFileValues();
};

#endif