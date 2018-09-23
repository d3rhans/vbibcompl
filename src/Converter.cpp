#include <regex>

#include "Converter.h"

const std::map<std::string, std::regex> TOKEN{{"bibkey",    std::regex{"%k"}},
                                                {"file",    std::regex{"%f"}},
                                                {"bibtype", std::regex{"%p"}},
                                                {"author",  std::regex{"%a"}},
                                                {"title",   std::regex{"%t"}},
                                                {"year",    std::regex{"%y"}}};

struct vbc::Converter::ConverterD
{
    std::string infoPattern;
};

vbc::Converter::Converter()
    :d(std::make_unique<ConverterD>())
{

}

vbc::Converter::Converter(const std::string& infoPattern)
    : d(std::make_unique<ConverterD>())
{
    d->infoPattern = infoPattern;
}

vbc::Converter& vbc::Converter::operator=(const Converter& rhs)
{
    d->infoPattern = rhs.d->infoPattern;
    return *this;
}

vbc::Converter::~Converter() = default;

void vbc::Converter::bibEntryToComplWord(BibEntry& bibEntry, ComplWord& word) const
{

    word.word = bibEntry.find("bibkey")->second;
    word.menu = bibEntry.find("file")->second;

    word.info = d->infoPattern;

    for(const auto& token: TOKEN) {
        auto bibToken = bibEntry.find(token.first);

        if(bibToken != bibEntry.end()) {
            word.info = std::regex_replace(word.info, token.second, bibToken->second);
        }
    }
}
