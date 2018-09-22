#ifndef COMPLWORD_H_
#define COMPLWORD_H_

#include <ostream>
#include <string>

namespace vbc
{
    struct ComplWord
    {
        std::string word;
        std::string menu;
        std::string info;

        void write(std::ostream& stream) const;
    };

    std::ostream& operator<<(std::ostream& stream, const ComplWord& complWord);
}

#endif /* define COMPLWORD_H_ */
