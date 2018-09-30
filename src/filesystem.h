/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <string>
#include <vector>



namespace vbc
{
    class ProgramOptions;

    using DirName = std::string;
    using FileName = std::string;
    using FileNameContainer = std::vector<FileName>;

    /**
     * @brief Find all BibTex files in given directory and subdirectories
     *
     * @param dir   name of the directory to search
     * @param files container holding the file names
     */
    void getBibFilesFromDir(const DirName& dir, FileNameContainer& files);

    /**
     * @brief Get BibTex file names based on command line parameters
     *
     * @param options the command line parameters
     * @param files   container holding the BibTex file names
     */
    void getBibFileNames(const ProgramOptions& options, FileNameContainer& files);
}

#endif /* define FILESYSTEM_H_ */
