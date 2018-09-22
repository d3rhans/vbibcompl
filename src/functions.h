#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <regex>

#include "types.h"
#include "ComplWord.h"
#include "ComplData.h"

namespace vbc
{
    void bibEntryToCompWord(const BibEntry& bibEntry, ComplWord& word);
    void getBibFiles(const std::string& dir, FileNameContainer& bibfiles);

    bool isNewEntry(const std::string& line, std::cmatch& match);
    bool isToken(const std::string& line, std::cmatch& match);
}

#endif /* define FUNCTIONS_H_ */
