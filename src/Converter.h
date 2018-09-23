#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "types.h"
#include "ComplWord.h"

namespace vbc
{
    class Converter
    {
        public:
            void bibEntryToComplWord(BibEntry& BibEntry, ComplWord& complWord) const;
    };
}

#endif /* define CONVERTER_H_ */
