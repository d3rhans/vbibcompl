/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef OUTPUTSTD_H_
#define OUTPUTSTD_H_

#include "Output.h"

namespace vbc
{
    /**
     * @brief Output to STDOUT
     */
    class OutputSTD : public Output
    {
        protected:
            /**
             * @brief Output implementation to STDOUT
             *
             * @param data output data
             */
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
