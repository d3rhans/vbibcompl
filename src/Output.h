#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <memory>

#include "ComplData.h"
#include "ProgramOptions.h"

namespace vbc
{
    class Output
    {
        public:
            using Pointer = std::unique_ptr<Output>;

            static Pointer getOutput(const ProgramOptions& options);

            Output() = default;
            Output(const Output& rhs) = delete;
            Output(Output&& rhs) = delete;

            virtual ~Output();

            Output& operator=(const Output& rhs) = delete;
            Output& operator=(Output&& rhs) = delete;

            void execute(const ComplData& data);

        protected:
            virtual void _execute(const ComplData& data) = 0;
    };

}

#endif /* define OUTPUT_H_ */
