#include <fstream>

#include "BibFile.h"

struct vbc::BibFile::BibFileD
{
    FileName fileName;
    std::ifstream file;
};

vbc::BibFile::BibFile(const FileName& filename)
    : d(std::make_unique<BibFileD>())
{
    d->file.open(filename);
    d->fileName = filename;
}

vbc::BibFile::~BibFile() = default;

std::string vbc::BibFile::getFileName() const
{
    return d->fileName;
}

vbc::BibFile::iterator vbc::BibFile::begin()
{
    return iterator(d->file);
}

vbc::BibFile::iterator vbc::BibFile::end()
{
    return iterator();
}
