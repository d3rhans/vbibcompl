#ifndef BIBLINE_H_
#define BIBLINE_H_

#include <memory>
#include <istream>
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
    };

    std::istream& operator>>(std::istream& is, BibLine& bl);
}

#endif /* define BIBLINE_H_ */
