#ifndef TYPES_H_
#define TYPES_H_

#include <map>
#include <string>
#include <vector>

namespace vbc
{
    using BibEntry = std::map<std::string, std::string>;
    using FileNameContainer = std::vector<std::string>;
}

#endif /* define TYPES_H_ */
