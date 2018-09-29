#ifndef OUTPUTFILE_H_
#define OUTPUTFILE_H_

#include <memory>

#include "Output.h"

namespace vbc
{
    class OutputFile : public Output
    {
        public:
            OutputFile(const std::string& filename);
            virtual ~OutputFile();

        protected:
            void _execute(const CompletionData& data) override;

        private:
            struct OutputFileD;
            std::unique_ptr<OutputFileD> d;

    };
}

#endif /* define OUTPUTFILE_H_ */
