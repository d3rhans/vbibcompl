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

        void write(std::ostream& stream) const
        {
            stream << "{ 'word': '" << word
                   << "', 'menu': '" << menu
                   << "', 'info': '" << info
                   << "'}";
        }
    };

    std::ostream& operator<<(std::ostream& stream, const ComplWord& complWord)
    {
        complWord.write(stream);
        return stream;
    }
}

#endif /* define COMPLWORD_H_ */
