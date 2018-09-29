#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <string>
#include <vector>

#include "ProgramOptions.h"


namespace vbc
{
    using DirName = std::string;
    using FileName = std::string;
    using FileNameContainer = std::vector<FileName>;

    void getBibFilesFromDir(const DirName& dir, FileNameContainer& files);
    void getBibFileNames(const ProgramOptions& options, FileNameContainer& files);
}

#endif /* define FILESYSTEM_H_ */
