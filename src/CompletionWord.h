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
    /**
     * @brief An omnicompletion word in vim
     */
    class CompletionWord
    {
        private:
            struct CompletionWordD;
            std::unique_ptr<CompletionWordD> d;

        public:

            /**
             * @brief The constructor
             *
             * @param word        The completion word (bibkey)
             * @param menu        Menu entry (filename)
             * @param infoPattern Pattern to use for the preview window
             */
            CompletionWord(const std::string& word,
                           const std::string& menu,
                           const std::string& infoPattern);

            CompletionWord() = delete;
            CompletionWord(const CompletionWord& other) = delete;

            /**
             * @brief The move constructor (needed for sorting)
             *
             * @param other Completion word to move from
             */
            CompletionWord(CompletionWord&& other);

            ~CompletionWord();

            CompletionWord& operator=(const CompletionWord& rhs) = delete;

            /**
             * @brief Move assignment operator (needed for sorting)
             *
             * @param rhs The CompletionWord to move from
             *
             * @return reference to this
             */
            CompletionWord& operator=(CompletionWord&& rhs);

            /**
             * @brief Comparison operator <
             *
             * @param rhs The CompletionWord to compare with
             *
             * @return true if this is lexicographically smaller than rhs
             */
            bool operator<(const CompletionWord& rhs) const;

            /**
             * @brief Add token (key = value) to info text
             *
             * @param key   The token key
             * @param value The token value
             */
            void addToInfo(const std::string& key, const std::string& value);

            /**
             * @brief Write to output stream
             *
             * @param stream The stream to write to
             */
            void write(std::ostream& stream) const;

    };

    /**
     * @brief Operatot overload <<
     *
     * @param stream    The stream to write to
     * @param complWord The CompletionWord to write to stream
     *
     * @return  The output stream passed to the operator
     */
    std::ostream& operator<<(std::ostream& stream, const CompletionWord& complWord);
}

#endif /* define COMPLETIONWORD_H_ */
