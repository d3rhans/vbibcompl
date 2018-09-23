#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <regex>

#include "types.h"
#include "ComplWord.h"
#include "ComplData.h"
#include "ProgramOptions.h"

namespace vbc
{
    void setFiles(const ProgramOptions& options, FileNameContainer& bibFiles);
    void getBibFiles(const std::string& dir, FileNameContainer& bibfiles);

    void processBibFiles(const FileNameContainer& bibfiles, ComplData& complData);

    void storeBibEntry(BibEntry& bibEntry, ComplData& complData);
}

#endif /* define FUNCTIONS_H_ */
