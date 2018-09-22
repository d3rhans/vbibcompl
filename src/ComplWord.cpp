#include "ComplWord.h"

void vbc::ComplWord::write(std::ostream& stream) const
{
    stream << "{ 'word': '" << word
        << "', 'menu': '" << menu
        << "', 'info': '" << info
        << "'}";
}

std::ostream& vbc::operator<<(std::ostream& stream, const ComplWord& complWord)
{
    complWord.write(stream);
    return stream;
}
