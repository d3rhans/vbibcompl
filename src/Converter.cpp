#include <regex>

#include "Converter.h"

const std::map<std::string, std::regex> TOKEN{{"bibkey",    std::regex{"%k"}},
                                                {"file",    std::regex{"%f"}},
                                                {"bibtype", std::regex{"%p"}},
                                                {"author",  std::regex{"%a"}},
                                                {"title",   std::regex{"%t"}},
                                                {"year",    std::regex{"%y"}}};

const std::string INFO_PATTERN{"%a: %t - %p (%y)"};

void vbc::Converter::bibEntryToComplWord(BibEntry& bibEntry, ComplWord& word) const
{

    word.word = bibEntry.find("bibkey")->second;
    word.menu = bibEntry.find("file")->second;

    word.info = INFO_PATTERN;

    for(const auto& token: TOKEN) {
        auto bibToken = bibEntry.find(token.first);

        if(bibToken != bibEntry.end()) {
            word.info = std::regex_replace(word.info, token.second, bibToken->second);
        }
    }
}
