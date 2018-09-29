#include <iostream>

#include "Controller.h"
#include "ProgramOptions.h"

int main(int argc, char** argv)
{
    vbc::ProgramOptions options(argc, argv);
    vbc::Controller controller(std::move(options));

    controller.execute();

    return 0;
}
