#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <memory>

#include "types.h"
#include "ComplWord.h"

namespace vbc
{
    class Converter
    {
        public:
            Converter();
            Converter(const std::string& infoPattern);
            ~Converter();

            Converter& operator=(const Converter& rhs);

            void bibEntryToComplWord(BibEntry& BibEntry, ComplWord& complWord) const;

        private:
            struct ConverterD;
            std::unique_ptr<ConverterD> d;
    };
}

#endif /* define CONVERTER_H_ */
