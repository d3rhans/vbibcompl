#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>


#include "types.h"
#include "ComplData.h"

namespace fs = std::filesystem;

namespace vbc
{
    void bibEntryToCompWord(const BibEntry& bibEntry, ComplWord& word)
    {
        const std::map<std::string, std::string> TOKEN{{"bibkey", "%k"},
                                                       {"file", "%f"},
                                                       {"bibtype", "%p"},
                                                       {"author", "%a"},
                                                       {"title", "%t"},
                                                       {"year", "%y"}};

        const std::string INFO_PATTERN{"%a: %t - %p (%y)"};

        word.word = bibEntry.find("bibkey")->second;
        word.menu = bibEntry.find("file")->second;

        word.info = INFO_PATTERN;

        for(const auto& token: TOKEN) {
            auto bibToken = bibEntry.find(token.first);

            if(bibToken != bibEntry.end()) {
                word.info = std::regex_replace(word.info,
                                               std::regex(token.second),
                                               bibToken->second);
            }
        }
    }

    void getBibFiles(const std::string& dir, FileNameContainer& bibfiles)
    {
        const fs::path BIB_EXTENSION{".bib"};

        for(auto& entry: fs::recursive_directory_iterator(dir)) {
            if(entry.is_regular_file()) {
                auto file = entry.path();

                if(file.extension() == BIB_EXTENSION) {
                    bibfiles.push_back(std::move(file.string()));
                }
            }
        }
    }

    bool isNewEntry(const std::string& line, std::cmatch& match)
    {
        const std::regex entryRegex("^\\s*@([a-zA-Z]+)\\{(.+),\\s*$");

        return std::regex_match(line.c_str(), match, entryRegex);
    }

    bool isToken(const std::string& line, std::cmatch& match)
    {
        const std::regex tokeRegex("^\\s*([a-zA-Z]+)\\s*=\\s*[\"\\{]+(.*)[\\}\",]+");

        return std::regex_match(line.c_str(), match, tokeRegex);
    }

}



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
