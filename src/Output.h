/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <memory>

#include "CompletionData.h"
#include "ProgramOptions.h"

namespace vbc
{
    /**
     * @brief Abstract base class for output modes
     */
    class Output
    {
        protected:
            Output() = default;

            /**
             * @brief Virtual function for the output execution
             *
             * @param data output data
             */
            virtual void _execute(const CompletionData& data) = 0;

        public:
            using Pointer = std::unique_ptr<Output>;

            /**
             * @brief Factory method, constructs Output subclass based on options
             *
             * @param options the command line parameters passed to the program
             *
             * @return Pointer to the concrete Output object
             */
            static Pointer getOutput(const ProgramOptions& options);

            Output(const Output& rhs) = delete;
            Output(Output&& rhs)      = delete;

            virtual ~Output();

            Output& operator=(const Output& rhs) = delete;
            Output& operator=(Output&& rhs)      = delete;

            /**
             * @brief Public interface to the output execution
             *
             * @param data output data
             */
            void execute(const CompletionData& data);

    };

}

#endif /* define OUTPUT_H_ */
