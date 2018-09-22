#ifndef COMPLDATA_H_
#define COMPLDATA_H_

#include <ostream>
#include <vector>

#include "ComplWord.h"

namespace vbc
{
    struct ComplData
    {
        std::vector<ComplWord> words;

        void write(std::ostream& stream) const;
    };

    std::ostream& operator<<(std::ostream& stream, const ComplData& data);
}

#endif /* define COMPLDATA_H_ */
