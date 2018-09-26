#ifndef BIBFILE_H_
#define BIBFILE_H_

#include <memory>

#include "types.h"

namespace vbc
{
    class BibFile
    {
        private:
            struct BibFileD;
            std::unique_ptr<BibFileD> d;

        public:
            BibFile(const FileName& filename);

            ~BibFile();

    };
}

#endif /* define BIBFILE_H_ */
