#include <iostream>

#include "functions.h"
#include "types.h"
#include "ComplData.h"
#include "ProgramOptions.h"


int main(int argc, char** argv)
{
    vbc::FileNameContainer bibFiles;
    vbc::ComplData complData;

    vbc::ProgramOptions options(argc, argv);

    if(options.error() || options.helpRequested()) {
       options.printUsage();
    } else {
        vbc::getBibFiles(".", bibFiles);
        vbc::processBibFiles(bibFiles, complData);

        std::cout << complData << std::endl;
    }

    return 0;
}
