#ifndef COMPLETIONWORD_H_
#define COMPLETIONWORD_H_

#include <ostream>
#include <string>

namespace vbc
{
    struct CompletionWord
    {
        std::string word;
        std::string menu;
        std::string info;

        CompletionWord(const std::string& word,
                       const std::string& menu,
                       const std::string& infoPattern);

        void addToInfo(const std::string& key, const std::string& value);

        void write(std::ostream& stream) const;
    };

    std::ostream& operator<<(std::ostream& stream, const CompletionWord& complWord);

    bool operator<(const CompletionWord& lhs, const CompletionWord& rhs);
}

#endif /* define COMPLETIONWORD_H_ */
