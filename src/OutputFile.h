/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef OUTPUTFILE_H_
#define OUTPUTFILE_H_

#include <memory>

#include "Output.h"

namespace vbc
{
    class OutputFile : public Output
    {
        private:
            struct OutputFileD;
            std::unique_ptr<OutputFileD> d;

        protected:
            void _execute(const CompletionData& data) override;

        public:
            OutputFile(const std::string& filename);

            OutputFile()                        = delete;
            OutputFile(const OutputFile& other) = delete;
            OutputFile(OutputFile&& other)      = delete;

            virtual ~OutputFile();

            OutputFile& operator=(const OutputFile& rhs) = delete;
            OutputFile& operator=(OutputFile&& rhs)      = delete;
    };
}

#endif /* define OUTPUTFILE_H_ */
