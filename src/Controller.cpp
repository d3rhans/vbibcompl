/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#include "filesystem.h"

#include "BibFile.h"
#include "CompletionData.h"
#include "Output.h"

#include "Controller.h"


struct vbc::Controller::ControllerD
{
    ProgramOptions options;
    FileNameContainer bibFiles;
};

vbc::Controller::Controller(ProgramOptions&& options)
    : d(std::make_unique<ControllerD>())
{
    d->options = std::move(options);
}

vbc::Controller::~Controller() = default;

void vbc::Controller::execute()
{
    if(d->options.error() || d->options.helpRequested()) {
        d->options.printUsage();
    } else {
        getBibFileNames(d->options, d->bibFiles);

        CompletionData complData(d->options);

        for(BibFile bibFile: d->bibFiles)
        {
            for(auto& line: bibFile)
            {
                if(line.isEmpty()) {
                    continue;
                }

                if(line.isEntry()) {
                    complData.createWord(line, bibFile.getFileName());
                    continue;
                }

                if(line.isToken()) {
                    complData.addToCurrent(line);
                }
            }
        }

        if(!complData.empty()) {
            Output::Pointer output = Output::getOutput(d->options);
            output->execute(complData);
        }
    }
}
