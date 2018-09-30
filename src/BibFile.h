/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef BIBFILE_H_
#define BIBFILE_H_

#include <iterator>
#include <memory>

#include "filesystem.h"
#include "BibLine.h"

namespace vbc
{
    class BibFile
    {
        private:
            struct BibFileD;
            std::unique_ptr<BibFileD> d;

        public:
            using iterator = std::istream_iterator<BibLine>;

            BibFile(const FileName& filename);

            BibFile() = delete;
            BibFile(const BibFile& other) = delete;
            BibFile(BibFile&& other) = delete;

            ~BibFile();

            std::string getFileName() const;

            BibFile& operator=(const BibLine& rhs) = delete;
            BibFile& operator=(BibFile&& rhs) = delete;

            iterator begin();
            iterator end();
    };
}

#endif /* define BIBFILE_H_ */
