#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "functions.h"
#include "types.h"
#include "ComplData.h"


int main(int argc, char** argv)
{
    vbc::FileNameContainer bibFiles;

    vbc::BibEntry bibEntry;
    vbc::BibData bibData;

    vbc::ComplWord cw;
    vbc::ComplData cd;

    std::cmatch currentMatch;

    vbc::getBibFiles(".", bibFiles);

    for(const auto& filename: bibFiles) {
        std::ifstream bibFile(filename);

        for(std::string line; std::getline(bibFile, line); /**/) {
            if(vbc::isNewEntry(line, currentMatch)) {
                if(!bibEntry.empty()) {
                    bibData.push_back(bibEntry);
                    bibEntry.clear();
                }
                bibEntry.emplace(std::make_pair("bibtype", currentMatch[1]));
                bibEntry.emplace(std::make_pair("bibkey", currentMatch[2]));
                bibEntry.emplace(std::make_pair("file", filename));
            }

            if(vbc::isToken(line, currentMatch)) {
                bibEntry.emplace(std::make_pair(currentMatch[1], currentMatch[2]));
            }
        }
        if(!bibEntry.empty()) {
            bibData.push_back(bibEntry);
            bibEntry.clear();
        }
    }

    for(const auto& entry: bibData) {
        vbc::bibEntryToCompWord(entry, cw);
        cd.words.push_back(cw);
    }

    std::cout << cd << std::endl;

    return 0;
}
