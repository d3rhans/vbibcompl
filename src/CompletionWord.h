/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef COMPLETIONWORD_H_
#define COMPLETIONWORD_H_

#include <memory>
#include <ostream>
#include <string>

namespace vbc
{
    class CompletionWord
    {
        private:
            struct CompletionWordD;
            std::unique_ptr<CompletionWordD> d;

        public:

            CompletionWord(const std::string& word,
                           const std::string& menu,
                           const std::string& infoPattern);

            CompletionWord() = delete;
            CompletionWord(const CompletionWord& other) = delete;
            CompletionWord(CompletionWord&& other);

            ~CompletionWord();

            CompletionWord& operator=(const CompletionWord& rhs) = delete;
            CompletionWord& operator=(CompletionWord&& rhs);

            bool operator<(const CompletionWord& rhs) const;

            void addToInfo(const std::string& key, const std::string& value);
            void write(std::ostream& stream) const;

    };

    std::ostream& operator<<(std::ostream& stream, const CompletionWord& complWord);
}

#endif /* define COMPLETIONWORD_H_ */
