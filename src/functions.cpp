#include <filesystem>
#include <fstream>

#include "functions.h"
#include "Converter.h"
#include "LineChecker.h"

namespace fs = std::filesystem;

void vbc::setFiles(const ProgramOptions& options, FileNameContainer& bibFiles)
{
    const std::string DEFAULT_DIR{"."};

    if(options.inpuFileSet()) {
        bibFiles.push_back(options.getInputFile());
    } else if(options.inputDirSet()) {
        getBibFiles(options.getInputDir(), bibFiles);
    } else {
        getBibFiles(DEFAULT_DIR, bibFiles);
    }
}

void vbc::getBibFiles(const std::string& dir, FileNameContainer& bibfiles)
{
    const fs::path BIB_EXTENSION{".bib"};

    for(auto& entry: fs::recursive_directory_iterator(dir)) {
        if(entry.is_regular_file()) {
            auto file = entry.path();

            if(file.extension() == BIB_EXTENSION) {
                bibfiles.push_back(std::move(file.string()));
            }
        }
    }
}


void vbc::processBibFiles(const FileNameContainer& bibfiles, ComplData& complData)
{
    BibEntry bibEntry;
    std::cmatch currentMatch;

    LineChecker lineChecker;

    for(const auto& filename: bibfiles) {
        std::ifstream bibFile(filename);

        for(std::string line; std::getline(bibFile, line); /**/) {
            if(lineChecker.isNewEntry(line, currentMatch)) {
                complData.addBibEntry(bibEntry);

                bibEntry.emplace(std::make_pair("bibtype", currentMatch[1]));
                bibEntry.emplace(std::make_pair("bibkey", currentMatch[2]));
                bibEntry.emplace(std::make_pair("file", filename));
            }

            if(lineChecker.isToken(line, currentMatch)) {
                bibEntry.emplace(std::make_pair(currentMatch[1], currentMatch[2]));
            }
        }
        complData.addBibEntry(bibEntry);
    }
}
