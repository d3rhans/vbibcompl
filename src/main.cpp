#include <iostream>

#include "functions.h"
#include "types.h"
#include "ComplData.h"
#include "Output.h"
#include "ProgramOptions.h"

int main(int argc, char** argv)
{
    vbc::FileNameContainer bibFiles;
    vbc::ComplData complData;
    vbc::Output::Pointer output;

    vbc::ProgramOptions options(argc, argv);

    if(options.error() || options.helpRequested()) {
       options.printUsage();
    } else {
        vbc::setFiles(options, bibFiles);
        vbc::processBibFiles(bibFiles, complData);

        output = vbc::Output::getOutput(options);
        output->execute(complData);
    }

    return 0;
}
