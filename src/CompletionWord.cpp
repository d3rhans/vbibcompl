#include <iostream>
#include <algorithm>
#include <map>
#include <regex>

#include "CompletionWord.h"

const std::map<std::string, std::regex> TOKEN{{"bibkey",  std::regex{"%k"}},
                                              {"file",    std::regex{"%f"}},
                                              {"bibtype", std::regex{"%p"}},
                                              {"author",  std::regex{"%a"}},
                                              {"title",   std::regex{"%t"}},
                                              {"year",    std::regex{"%y"}}};

vbc::CompletionWord::CompletionWord(const std::string& word,
                                    const std::string& menu,
                                    const std::string& infoPattern)
    : word(word), menu(menu), info(infoPattern)
{
    addToInfo("bibkey", word);
    addToInfo("file", menu);
}

void vbc::CompletionWord::addToInfo(const std::string& key, const std::string& value)
{
    std::string key_{key};

    std::transform(key_.begin(), key_.end(), key_.begin(), ::tolower);

    const auto token = TOKEN.find(key_);

    if(token != TOKEN.end()) {
        info = std::regex_replace(info, token->second, value);
    }
}

void vbc::CompletionWord::write(std::ostream& stream) const
{
    stream << "{ 'word': '"  << word
           << "', 'menu': '" << menu
           << "', 'info': '" << info
           << "'}";
}

std::ostream& vbc::operator<<(std::ostream& stream, const CompletionWord& complWord)
{
    complWord.write(stream);
    return stream;
}

bool vbc::operator<(const CompletionWord& lhs, const CompletionWord& rhs)
{
    return lhs.word < rhs.word;
}
