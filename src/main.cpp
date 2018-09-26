#include <iostream>

#include "ProgramOptions.h"

int main(int argc, char** argv)
{
    vbc::ProgramOptions options(argc, argv);

    if(options.error() || options.helpRequested()) {
        options.printUsage();
    } else {


    }

    return 0;
}
