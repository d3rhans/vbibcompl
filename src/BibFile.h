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
    /**
     * @brief Abstraction and access for a BibTex File
     */
    class BibFile
    {
        private:
            struct BibFileD;
            std::unique_ptr<BibFileD> d;

        public:
            using iterator = std::istream_iterator<BibLine>;

            /**
             * @brief The constructor
             *
             * @param filename Name of the BibTex file
             */
            BibFile(const FileName& filename);

            BibFile()                     = delete;
            BibFile(const BibFile& other) = delete;
            BibFile(BibFile&& other)      = delete;

            ~BibFile();

            /**
             * @brief Get associated file name
             *
             * @return The filename
             */
            FileName getFileName() const;

            BibFile& operator=(const BibLine& rhs) = delete;
            BibFile& operator=(BibFile&& rhs)      = delete;

            /**
             * @brief Iterator to first line
             *
             * @return the iterator
             */
            iterator begin();

            /**
             * @brief Iterator to EOF
             *
             * @return the iterator
             */
            iterator end();
    };
}

#endif /* define BIBFILE_H_ */
