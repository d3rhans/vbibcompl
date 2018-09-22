#ifndef COMPLDATA_H_
#define COMPLDATA_H_

#include <algorithm>
#include <iterator>
#include <ostream>
#include <vector>

#include "ComplWord.h"

namespace vbc
{
    struct ComplData
    {
        std::vector<ComplWord> words;

        void write(std::ostream& stream) const
        {
            stream << "{'words': [";

            std::copy(words.begin(), words.end(),
                      std::ostream_iterator<ComplWord>(stream, ", "));

            stream << "]}";
        }
    };

    std::ostream& operator<<(std::ostream& stream, const ComplData& data)
    {
        data.write(stream);
        return stream;
    }
}

#endif /* define COMPLDATA_H_ */
