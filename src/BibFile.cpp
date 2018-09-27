#include <fstream>

#include "BibEntry.h"
#include "BibFile.h"

struct vbc::BibFile::BibFileD
{
    std::ifstream file;
};

vbc::BibFile::BibFile(const FileName& filename)
    : d(std::make_unique<BibFileD>())
{
    d->file.open(filename);
}

vbc::BibFile::~BibFile() = default;
