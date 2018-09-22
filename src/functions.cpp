#include <filesystem>
#include <fstream>

#include "functions.h"

namespace fs = std::filesystem;

void vbc::bibEntryToCompWord(const BibEntry& bibEntry, ComplWord& word)
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

void vbc::getBibFiles(const std::string& dir, FileNameContainer& bibfiles)
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

bool vbc::isNewEntry(const std::string& line, std::cmatch& match)
{
    const std::regex entryRegex("^\\s*@([a-zA-Z]+)\\{(.+),\\s*$");

    return std::regex_match(line.c_str(), match, entryRegex);
}

bool vbc::isToken(const std::string& line, std::cmatch& match)
{
    const std::regex tokeRegex("^\\s*([a-zA-Z]+)\\s*=\\s*[\"\\{]+(.*)[\\}\",]+");

    return std::regex_match(line.c_str(), match, tokeRegex);
}

void vbc::processBibFiles(const FileNameContainer& bibfiles, ComplData& complData)
{
    vbc::BibEntry bibEntry;
    std::cmatch currentMatch;

    for(const auto& filename: bibfiles) {
        std::ifstream bibFile(filename);

        for(std::string line; std::getline(bibFile, line); /**/) {
            if(vbc::isNewEntry(line, currentMatch)) {
                storeBibEntry(bibEntry, complData);

                bibEntry.emplace(std::make_pair("bibtype", currentMatch[1]));
                bibEntry.emplace(std::make_pair("bibkey", currentMatch[2]));
                bibEntry.emplace(std::make_pair("file", filename));
            }

            if(vbc::isToken(line, currentMatch)) {
                bibEntry.emplace(std::make_pair(currentMatch[1], currentMatch[2]));
            }
        }
        storeBibEntry(bibEntry, complData);
    }
}

void vbc::storeBibEntry(BibEntry& bibEntry, ComplData& complData)
{
    static ComplWord cw;

    if(!bibEntry.empty()) {
        vbc::bibEntryToCompWord(bibEntry, cw);
        complData.words.push_back(cw);
        bibEntry.clear();
    }
}
