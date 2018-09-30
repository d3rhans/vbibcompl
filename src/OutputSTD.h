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
            virtual ~OutputSTD();
    };
}

#endif /* define OUTPUTSTD_H_ */
