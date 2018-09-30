/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#include "Controller.h"
#include "ProgramOptions.h"

int main(int argc, char** argv)
{
    vbc::ProgramOptions options(argc, argv);
    vbc::Controller controller(std::move(options));

    controller.execute();

    return 0;
}
