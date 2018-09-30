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
            virtual ~OutputFile();



    };
}

#endif /* define OUTPUTFILE_H_ */
