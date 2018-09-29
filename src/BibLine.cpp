#include <regex>

#include "BibLine.h"

const std::regex entryRegex("^\\s*@([a-zA-Z]+)\\{(.+),\\s*$");
const std::regex tokeRegex("^\\s*([a-zA-Z]+)\\s*=\\s*[\"\\{]*(.*)[\\}\",]*");

struct vbc::BibLine::BibLineD
{
    LineType line;
    mutable std::cmatch match;
};

vbc::BibLine::BibLine()
    : d(std::make_unique<BibLineD>())
{

}

vbc::BibLine::~BibLine() = default;

void vbc::BibLine::setLine(LineType&& line)
{
    d->line = line;
}

vbc::BibLine::LineType vbc::BibLine::getLine() const
{
    return d->line;
}

bool vbc::BibLine::isEmpty() const
{
    return d->line.find_first_not_of(" \t\n\v\f\r") == std::string::npos;
}

bool vbc::BibLine::isEntry() const
{
    if(d->line.find_first_of("@") != std::string::npos) {
        return std::regex_match(d->line.c_str(), d->match, entryRegex);
    }

    return false;
}

bool vbc::BibLine::isToken() const
{
    return std::regex_match(d->line.c_str(), d->match, tokeRegex);
}

const std::cmatch& vbc::BibLine::getLastMatch() const
{
    return d->match;
}

std::istream& vbc::operator>>(std::istream& is, BibLine& bl)
{
    BibLine::LineType line;

    std::getline(is, line);
    bl.setLine(std::move(line));

    return is;
}

std::ostream& vbc::operator<<(std::ostream& os, const BibLine& bl)
{
    os << bl.getLine();
    return os;
}
