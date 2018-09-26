#include <filesystem>

#include "BibFiles.h"

namespace fs = std::filesystem;

struct vbc::BibFiles::BibFilesD
{
    FileNameContainer files;

    void getBibFiles(std::string dirName)
    {
        const fs::path BIB_EXTENSION{".bib"};

        for(auto& entry: fs::recursive_directory_iterator(dirName)) {
            if(entry.is_regular_file()) {
                auto file = entry.path();

                if(file.extension() == BIB_EXTENSION) {
                    files.push_back(std::move(file.string()));
                }
            }
        }
    }
};

vbc::BibFiles::BibFiles(const ProgramOptions& options)
    : d(std::make_unique<BibFilesD>())
{
    const std::string DEFAULT_DIR{"."};

    if(options.inpuFileSet()) {
        d->files.push_back(options.getInputFile());
    } else if(options.inputDirSet()) {
        d->getBibFiles(options.getInputDir());
    } else {
        d->getBibFiles(DEFAULT_DIR);
    }

}

vbc::BibFiles::~BibFiles() = default;


vbc::BibFiles::iterator vbc::BibFiles::begin()
{
    return d->files.begin();
}

vbc::BibFiles::const_iterator vbc::BibFiles::begin() const
{
    return d->files.begin();
}

vbc::BibFiles::const_iterator vbc::BibFiles::cbegin() const
{
    return d->files.begin();
}

vbc::BibFiles::iterator vbc::BibFiles::end()
{
    return d->files.end();
}

vbc::BibFiles::const_iterator vbc::BibFiles::end() const
{
    return d->files.end();
}

vbc::BibFiles::const_iterator vbc::BibFiles::cend() const
{
    return d->files.end();
}
