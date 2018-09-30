/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef BIBLINE_H_
#define BIBLINE_H_

#include <memory>
#include <istream>
#include <regex>
#include <string>

namespace vbc
{
    /**
     * @brief A line form a BibTex file
     */
    class BibLine
    {
        private:
            struct BibLineD;
            std::unique_ptr<BibLineD> d;

        public:
            using LineType = std::string;

            /**
             * @brief Default constructor
             */
            BibLine();
            BibLine(const BibLine&) = delete;
            BibLine(BibLine&&)      = delete;

            BibLine& operator=(const BibLine&) = delete;
            BibLine& operator=(BibLine&&)      = delete;

            ~BibLine();

            /**
             * @brief Set content of line (does not modify underlying file)
             *
             * @param line The string to place in the object
             */
            void setLine(LineType&& line);

            /**
             * @brief Get string content of line
             *
             * @return The content
             */
            LineType getLine() const;

            /**
             * @brief Check if the line contains nothing but whitespaces
             *
             * @return true if no non-whitespace character was found, false otherwise
             */
            bool isEmpty() const;

            /**
             * @brief Check if line is the start of a BibText Entry
             *
             * @return true, if line is start of entry, false otherwise
             */
            bool isEntry() const;

            /**
             * @brief Check if line is a key=value token
             *
             * @return true, if it is a token, false otherwise
             */
            bool isToken() const;

            /**
             * @brief Provide access to the match object of last isEntry or isToken call
             *
             * @return The regex match object (Might be empty!)
             */
            const std::cmatch& getLastMatch() const;
    };

    /**
     * @brief Read line from input stream (usually a ifstream)
     *
     * @param is The input stream
     * @param bl The line object to read into
     *
     * @return the passed input stream
     */
    std::istream& operator>>(std::istream& is, BibLine& bl);
}

#endif /* define BIBLINE_H_ */
