/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef COMPLDATA_H_
#define COMPLDATA_H_

#include <memory>
#include <ostream>
#include <vector>

#include "types.h"
#include "ComplWord.h"
#include "Converter.h"

namespace vbc
{
    class ComplData
    {
        public:
            ComplData(const Converter& converter);
            ComplData() = delete;
            ComplData(const ComplData&) = delete;
            ComplData(ComplData&&) = delete;

            ComplData& operator=(const ComplData&) = delete;
            ComplData& operator=(ComplData&&) = delete;

            ~ComplData();

            void addBibEntry(BibEntry& BibEntry);
            void write(std::ostream& stream) const;


        private:
            struct ComplDataD;
            std::unique_ptr<ComplDataD> d;
    };

    std::ostream& operator<<(std::ostream& stream, const ComplData& data);
}

#endif /* define COMPLDATA_H_ */
