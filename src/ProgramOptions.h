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
    /**
     * @brief Parser and container for command line options
     */
    class ProgramOptions
    {
        private:
            struct ProgramOptionsD;
            std::unique_ptr<ProgramOptionsD> d;

        public:
            /**
             * @brief Default constructor
             */
            ProgramOptions();

            /**
             * @brief The constructor
             *
             * @param argc numer of command line arguments
             * @param argv the command line arguments
             */
            ProgramOptions(int argc, char** argv);
            ~ProgramOptions();

            ProgramOptions( const ProgramOptions& rhs) = delete;
            ProgramOptions(ProgramOptions&& rhs) = delete;

            ProgramOptions& operator=( const ProgramOptions& rhs) = delete;

            /**
             * @brief Move assignment operator
             *
             * @param rhs the object to move from
             *
             * @return this after move
             */
            ProgramOptions& operator=(ProgramOptions&& rhs);

            /**
             * @brief Print program usage to STDOUT
             */
            void printUsage() const;

            /**
             * @brief Check if command line options had an error
             *
             * @return true if an error occurred, false otherwise
             */
            bool error() const;

            /**
             * @brief Check if user requested help (via -h option)
             *
             * @return true of help was requested, false otherwise
             */
            bool helpRequested() const;

            /**
             * @brief Has an input file been provided
             *
             * @return true if provided, false otherwise
             */
            bool inpuFileSet() const;

            /**
             * @brief Has an input directory been provided
             *
             * @return true if provided, false otherwise
             */
            bool inputDirSet() const;

            /**
             * @brief Has an output file been provided
             *
             * @return true if provided, false otherwise
             */
            bool outputFileSet() const;

            /**
             * @brief Get the provided input file
             *
             * @return The file name
             */
            FileName getInputFile() const;

            /**
             * @brief Get the provided input directory
             *
             * @return The directory name
             */
            FileName getInputDir() const;

            /**
             * @brief Get the provided output file
             *
             * @return The filename
             */
            FileName getOutputfile() const;

            /**
             * @brief Get the Info pattern
             *
             * @return the pattern provided via command line or default
             */
            FileName getInfoPattern() const;


    };
}

#endif /* define PROGRAMOPTIONS_H_ */
