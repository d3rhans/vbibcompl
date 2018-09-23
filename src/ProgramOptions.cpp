#include <iostream>
#include <unistd.h>
#include <string>

#include "ProgramOptions.h"

extern char* optarg;
extern int optind, opterr, optopt;

struct vbc::ProgramOptions::ProgramOptionsD
{
    bool inputFile  = false;
    bool inputDir   = false;
    bool outputFile = false;
    bool help       = false;
    bool error      = false;

    std::string inputFileName;
    std::string inputDirName;
    std::string outputFileName;

    void validate()
    {
        bool inputFileAndDir   = inputFile && inputDir;
        bool inputFileMissing  = inputFile && inputFileName.empty();
        bool inputDirMissing   = inputDir && inputDirName.empty();
        bool outputFileMissing = outputFile && outputFileName.empty();

        error = inputFileAndDir || inputFileMissing || inputDirMissing || outputFileMissing;
    }
};

vbc::ProgramOptions::ProgramOptions(int argc, char** argv)
    : d(std::make_unique<ProgramOptionsD>())
{
    const std::string OPTIONS{"i:d:o:h"};

    int opt;

    while((opt = getopt(argc, argv, OPTIONS.c_str())) != EOF) {
        switch(opt){
            case 'i':
                d->inputFile = true;
                d->inputFileName = optarg;
                break;
            case 'd':
                d->inputDir = true;
                d->inputDirName = optarg;
                break;
            case 'o':
                d->outputFile = true;
                d->outputFileName = optarg;
                break;
            case 'h':
                d->help = true;
                break;
            default:
                d->error = true;
                return;
        }
    }

    d->validate();
}

vbc::ProgramOptions::~ProgramOptions() = default;

void vbc::ProgramOptions::printUsage() const
{
    std::cout << std::endl;
    std::cout << "vbibcompl: Create vim omnicompletion data from bibtex" << std::endl;
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "  vbibcompl [-h][-i inputFile | -d inputDir][-o outputFile]" << std::endl;
    std::cout << "      -h            : Print this message" << std::endl;
    std::cout << "      -i inputFile  : Process only given input file" << std::endl;
    std::cout << "      -d inputDir   : Process all *.bib files in input directory" << std::endl;
    std::cout << "      -o outputFile : Write results to output file (STDOUT otherwise)" << std::endl;
    std::cout << std::endl;
    std::cout << "Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>, License: GNU GPLv3" << std::endl;
}

bool vbc::ProgramOptions::error() const
{
    return d->error;
}

bool vbc::ProgramOptions::helpRequested() const
{
    return d->help;
}

bool vbc::ProgramOptions::inpuFileSet() const
{
    return d->inputFile;
}

bool vbc::ProgramOptions::inputDirSet() const
{
    return d->inputDir;
}

bool vbc::ProgramOptions::outputFileSet() const
{
    return d->outputFile;
}


std::string vbc::ProgramOptions::getInputFile() const
{
    return d->inputFileName;
}

std::string vbc::ProgramOptions::getInputDir() const
{
    return d->inputDirName;
}

std::string vbc::ProgramOptions::getOutputfile() const
{
    return d->outputFileName;
}
