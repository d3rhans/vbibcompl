/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef COMPLETIONDATA_H_
#define COMPLETIONDATA_H_

#include <ostream>
#include <memory>
#include <vector>

#include "BibLine.h"
#include "CompletionWord.h"
#include "ProgramOptions.h"

namespace vbc
{
    /**
     * @brief Holds the omnicompletion data for vim
     */
    class CompletionData
    {
        private:
            struct CompletionDataD;
            std::unique_ptr<CompletionDataD> d;

        public:
            using Container = std::vector<CompletionWord>;

            /**
             * @brief The constructor
             *
             * @param options Command line options passed to the program
             */
            CompletionData(const ProgramOptions& options);

            CompletionData()                      = delete;
            CompletionData(const CompletionData&) = delete;
            CompletionData(CompletionData&&)      = delete;

            CompletionData& operator=(const CompletionData&) = delete;
            CompletionData& operator=(CompletionData&&)      = delete;

            ~CompletionData();

            /**
             * @brief Create a new completion word / corresponds to a BibTex entry
             *
             * @param line    The line from the file currently processed
             * @param bibFile Name of the currently processed file
             */
            void createWord(const BibLine& line, const FileName& bibFile);

            /**
             * @brief Add data to current completion word
             *
             * @param line The line from the file currently processed
             */
            void addToCurrent(const BibLine& line);

            /**
             * @brief Check if completion data is empty
             *
             * @return true if so, false otherwise
             */
            bool empty() const;

            /**
             * @brief Sort completion data by "word" alphabetically
             */
            void sort();

            /**
             * @brief Write completion data to output stream
             *
             * @param os The stream to write to
             */
            void write(std::ostream& os) const;
    };

    /**
     * @brief Operator overload for output streams
     *
     * @param os The output stream to write to
     * @param cd The completion data to write to os
     *
     * @return The output stream that was passed to the operator
     */
    std::ostream& operator<<(std::ostream& os, const CompletionData& cd);
}

#endif /* define COMPLETIONDATA_H_ */
