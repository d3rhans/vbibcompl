#include "LineChecker.h"

const std::regex entryRegex("^\\s*@([a-zA-Z]+)\\{(.+),\\s*$");
const std::regex tokeRegex("^\\s*([a-zA-Z]+)\\s*=\\s*[\"\\{]+(.*)[\\}\",]+");

bool vbc::LineChecker::isNewEntry(const std::string& line, std::cmatch& match) const
{
    return std::regex_match(line.c_str(), match, entryRegex);
}

bool vbc::LineChecker::isToken(const std::string& line, std::cmatch& match) const
{
    return std::regex_match(line.c_str(), match, tokeRegex);
}
