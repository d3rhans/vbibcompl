#include "Output.h"
#include "OutputFile.h"
#include "OutputSTD.h"

vbc::Output::Pointer vbc::Output::getOutput(const ProgramOptions& options)
{
    if(options.outputFileSet()) {
        return std::make_unique<OutputFile>(options.getOutputfile());
    }

    return std::make_unique<OutputSTD>();
}

vbc::Output::~Output() = default;

void vbc::Output::execute(const CompletionData& data)
{
    _execute(data);
}
