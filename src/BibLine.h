#ifndef BIBLINE_H_
#define BIBLINE_H_

#include <memory>
#include <istream>
#include <regex>
#include <string>

namespace vbc
{
    class BibLine
    {
        private:
            struct BibLineD;
            std::unique_ptr<BibLineD> d;

        public:
            using LineType = std::string;

            BibLine();
            BibLine(const BibLine&) = delete;
            BibLine(BibLine&&) = delete;

            BibLine& operator=(const BibLine&) = delete;
            BibLine& operator=(BibLine&&) = delete;

            ~BibLine();

            void setLine(LineType&& line);
            LineType getLine() const;

            bool isEmpty() const;
            bool isEntry() const;
            bool isToken() const;

            const std::cmatch& getLastMatch() const;
    };

    std::istream& operator>>(std::istream& is, BibLine& bl);
    std::ostream& operator<<(std::ostream& os, const BibLine& bl);
}

#endif /* define BIBLINE_H_ */
