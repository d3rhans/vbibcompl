#include <filesystem>

#include "ProgramOptions.h"
#include "filesystem.h"

namespace fs = std::filesystem;

void vbc::getBibFilesFromDir(const DirName& dir, FileNameContainer& files)
{
    const fs::path BIB_EXTENSION{".bib"};

    for(const auto& entry: fs::recursive_directory_iterator(dir)) {
        if(entry.is_regular_file()) {
            auto file = entry.path();

            if(file.extension() == BIB_EXTENSION) {
                files.push_back(file.string());
            }
        }
    }
}

void vbc::getBibFileNames(const ProgramOptions& options, FileNameContainer& files)
{
    const std::string DEFAULT_DIR{"."};

    if(options.inpuFileSet()) {
        files.push_back(options.getInputFile());
    } else if(options.inputDirSet()) {
        getBibFilesFromDir(options.getInputDir(), files);
    } else {
        getBibFilesFromDir(DEFAULT_DIR, files);
    }
}
