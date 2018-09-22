#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "functions.h"
#include "types.h"
#include "ComplData.h"


int main(int argc, char** argv)
{
    vbc::FileNameContainer bibFiles;
    vbc::ComplData complData;

    vbc::getBibFiles(".", bibFiles);
    vbc::processBibFiles(bibFiles, complData);

    std::cout << complData << std::endl;

    return 0;
}
