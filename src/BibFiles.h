#ifndef BIBFILES_H_
#define BIBFILES_H_

#include <memory>

#include "ProgramOptions.h"

namespace vbc
{
    class BibFiles
    {
        private:
            struct BibFilesD;
            std::unique_ptr<BibFilesD> d;

        public:
            using iterator       = FileNameContainer::iterator;
            using const_iterator = FileNameContainer::const_iterator;

            BibFiles(const ProgramOptions& options);

            BibFiles()                      = delete;
            BibFiles(const BibFiles& other) = delete;
            BibFiles(BibFiles&& other)      = delete;

            ~BibFiles();

            BibFiles& operator=(const BibFiles& rhs) = delete;
            BibFiles& operator=(BibFiles&& rhs)      = delete;

            iterator begin();
            const_iterator begin() const;
            const_iterator cbegin() const;

            iterator end();
            const_iterator end() const;
            const_iterator cend() const;

    };
}

#endif /* define BIBFILES_H_ */
