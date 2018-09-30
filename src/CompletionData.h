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
    class CompletionData
    {
        private:
            struct CompletionDataD;
            std::unique_ptr<CompletionDataD> d;

        public:
            using Container = std::vector<CompletionWord>;

            CompletionData(const ProgramOptions& options);

            CompletionData()                      = delete;
            CompletionData(const CompletionData&) = delete;
            CompletionData(CompletionData&&)      = delete;

            CompletionData& operator=(const CompletionData&) = delete;
            CompletionData& operator=(CompletionData&&)      = delete;

            ~CompletionData();

            void createWord(const BibLine& line, const FileName& bibFile);
            void addToCurrent(const BibLine& line);

            bool empty() const;
            void sort();

            void write(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const CompletionData& cd);
}

#endif /* define COMPLETIONDATA_H_ */
