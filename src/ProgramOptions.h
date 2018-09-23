#ifndef PROGRAMOPTIONS_H_
#define PROGRAMOPTIONS_H_

#include <memory>

namespace vbc
{
    class ProgramOptions
    {
        private:
            struct ProgramOptionsD;
            std::unique_ptr<ProgramOptionsD> d;

        public:
            ProgramOptions(int argc, char** argv);
            ~ProgramOptions();

            ProgramOptions(const ProgramOptions& rhs) = delete;
            ProgramOptions(ProgramOptions&& rhs) = delete;

            ProgramOptions& operator=(const ProgramOptions& rhs) = delete;
            ProgramOptions& operator=(ProgramOptions&& rhs) = delete;

            void printUsage() const;

            bool error() const;
            bool helpRequested() const;

            bool inpuFileSet() const;
            bool inputDirSet() const;
            bool outputFileSet() const;

            std::string getInputFile() const;
            std::string getInputDir() const;
            std::string getOutputfile() const;
            std::string getInfoPattern() const;


    };
}

#endif /* define PROGRAMOPTIONS_H_ */
