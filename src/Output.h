#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <memory>

#include "CompletionData.h"
#include "ProgramOptions.h"

namespace vbc
{
    class Output
    {
        protected:
            Output() = default;

            virtual void _execute(const CompletionData& data) = 0;

        public:
            using Pointer = std::unique_ptr<Output>;

            static Pointer getOutput(const ProgramOptions& options);

            Output(const Output& rhs) = delete;
            Output(Output&& rhs)      = delete;

            virtual ~Output();

            Output& operator=(const Output& rhs) = delete;
            Output& operator=(Output&& rhs)      = delete;

            void execute(const CompletionData& data);

    };

}

#endif /* define OUTPUT_H_ */
