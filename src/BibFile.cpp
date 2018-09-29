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

vbc::BibFile::iterator vbc::BibFile::begin()
{
    return iterator(d->file);
}

vbc::BibFile::iterator vbc::BibFile::end()
{
    return iterator();
}
