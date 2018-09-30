#ifndef OUTPUTSTD_H_
#define OUTPUTSTD_H_

#include "Output.h"

namespace vbc
{
    class OutputSTD : public Output
    {
        protected:
            void _execute(const CompletionData& data) override;

        public:
            OutputSTD() = default;

            OutputSTD(const OutputSTD& other) = delete;
            OutputSTD(OutputSTD&& other)      = delete;

            virtual ~OutputSTD();

            OutputSTD& operator=(const OutputSTD& rhs) = delete;
            OutputSTD& operator=(OutputSTD&& rhs)      = delete;
    };
}

#endif /* define OUTPUTSTD_H_ */
