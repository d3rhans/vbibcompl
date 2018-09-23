#ifndef LINECHECKER_H_
#define LINECHECKER_H_

#include <regex>

namespace vbc
{
    class LineChecker
    {
        public:
            bool isNewEntry(const std::string& line, std::cmatch& match) const;
            bool isToken(const std::string& line, std::cmatch& match) const;
    };
}

#endif /* define LINECHECKER_H_ */
