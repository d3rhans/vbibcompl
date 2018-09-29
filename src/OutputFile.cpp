#include <fstream>

#include "OutputFile.h"

struct vbc::OutputFile::OutputFileD
{
    std::string filename;
};

vbc::OutputFile::OutputFile(const std::string& filename)
    : d(std::make_unique<OutputFileD>())
{
    d->filename = filename;
}

vbc::OutputFile::~OutputFile() = default;

void vbc::OutputFile::_execute(const CompletionData& data)
{
    std::ofstream outputFile(d->filename);
    outputFile << data << std::endl;
}
