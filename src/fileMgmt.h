#ifndef SRC_FILE_MGMT_H
#define SRC_FILE_MGMT_H
#define FMT_HEADER_ONLY
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <list>
#include "date.h"

// TODO: Check the access modifiers and return of the methods
class FileMgmt{
    public:
        FileMgmt(std::string, std::string);
        ~FileMgmt() = default;
        std::string inputPath, outputPath, line, word;
        std::vector<std::string> content;
        std::vector<std::string> row;
        std::vector<std::pair<float, float>> outputResult;
        void readCsvFileLoadContentMemory();
        void showLoadedMemoryContent();
        void generateOutputCsvFile();
        void parseCsvFileValues();
        void writeOutputValuesIntoFile();
};

#endif