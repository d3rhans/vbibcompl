#include "filesystem.h"

#include "BibFile.h"
#include "Controller.h"

struct vbc::Controller::ControllerD
{
    ProgramOptions options;
    FileNameContainer bibFileNames;
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
        getBibFileNames(d->options, d->bibFileNames);

        for(BibFile bibFile: d->bibFileNames)
        {

        }
    }
}
