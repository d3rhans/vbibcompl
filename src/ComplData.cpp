#include <algorithm>
#include <iterator>

#include "ComplData.h"

void vbc::ComplData::write(std::ostream& stream) const
{
    stream << "{'words': [";

    std::copy(words.begin(), words.end(),
            std::ostream_iterator<ComplWord>(stream, ", "));

    stream << "]}";
}

std::ostream& vbc::operator<<(std::ostream& stream, const ComplData& data)
{
    data.write(stream);
    return stream;
}
