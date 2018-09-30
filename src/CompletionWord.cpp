/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

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

struct vbc::CompletionWord::CompletionWordD
{
    std::string word;
    std::string menu;
    std::string info;
};

vbc::CompletionWord::CompletionWord(const std::string& word,
                                    const std::string& menu,
                                    const std::string& infoPattern)
    : d(std::make_unique<CompletionWordD>())
{
    d->word = word;
    d->menu = menu;
    d->info = infoPattern;

    addToInfo("bibkey", d->word);
    addToInfo("file", d->menu);
}

vbc::CompletionWord::CompletionWord(CompletionWord&& other)
    : d(std::make_unique<CompletionWordD>())
{
    d = std::move(other.d);
}

vbc::CompletionWord::~CompletionWord() = default;

vbc::CompletionWord& vbc::CompletionWord::operator=(CompletionWord&& rhs)
{
    d = std::move(rhs.d);
    return *this;
}

bool vbc::CompletionWord::operator<(const CompletionWord& rhs) const
{
    return d->word < rhs.d->word;
}

void vbc::CompletionWord::addToInfo(const std::string& key, const std::string& value)
{
    std::string key_{key};

    std::transform(key_.begin(), key_.end(), key_.begin(), ::tolower);

    const auto token = TOKEN.find(key_);

    if(token != TOKEN.end()) {
        d->info = std::regex_replace(d->info, token->second, value);
    }
}

void vbc::CompletionWord::write(std::ostream& stream) const
{
    stream << "{ 'word': '"  << d->word
           << "', 'menu': '" << d->menu
           << "', 'info': '" << d->info
           << "'}";
}

std::ostream& vbc::operator<<(std::ostream& stream, const CompletionWord& complWord)
{
    complWord.write(stream);
    return stream;
}
