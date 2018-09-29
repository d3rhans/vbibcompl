#ifndef OUTPUTSTD_H_
#define OUTPUTSTD_H_

#include "Output.h"

namespace vbc
{
    class OutputSTD : public Output
    {
        public:
            OutputSTD() = default;
            virtual ~OutputSTD();

        protected:
            void _execute(const CompletionData& data) override;

    };
}

#endif /* define OUTPUTSTD_H_ */
