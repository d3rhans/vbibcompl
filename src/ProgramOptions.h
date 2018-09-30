/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef PROGRAMOPTIONS_H_
#define PROGRAMOPTIONS_H_

#include <memory>

#include "filesystem.h"

namespace vbc
{
    class ProgramOptions
    {
        private:
            struct ProgramOptionsD;
            std::unique_ptr<ProgramOptionsD> d;

        public:
            ProgramOptions();
            ProgramOptions(int argc, char** argv);
            ~ProgramOptions();

            ProgramOptions(const ProgramOptions& rhs) = delete;
            ProgramOptions(ProgramOptions&& rhs) = delete;

            ProgramOptions& operator=(const ProgramOptions& rhs) = delete;
            ProgramOptions& operator=(ProgramOptions&& rhs);

            void printUsage() const;

            bool error() const;
            bool helpRequested() const;

            bool inpuFileSet()   const;
            bool inputDirSet()   const;
            bool outputFileSet() const;

            FileName getInputFile()   const;
            FileName getInputDir()    const;
            FileName getOutputfile()  const;
            FileName getInfoPattern() const;


    };
}

#endif /* define PROGRAMOPTIONS_H_ */
