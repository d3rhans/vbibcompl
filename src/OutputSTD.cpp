#include <iostream>

#include "OutputSTD.h"

void vbc::OutputSTD::_execute(const CompletionData& data)
{
    std::cout << data << std::endl;
}

vbc::OutputSTD::~OutputSTD() = default;
