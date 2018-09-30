/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "ProgramOptions.h"

namespace vbc
{
    /**
     * @brief The main application controller
     */
    class Controller
    {
        private:
            struct ControllerD;
            std::unique_ptr<ControllerD> d;

        public:
            /**
             * @brief The constructor
             *
             * @param options command line options passed to the program
             */
            Controller(ProgramOptions&& options);

            Controller()                  = delete;
            Controller(const Controller&) = delete;
            Controller(Controller&&)      = delete;

            Controller& operator=(const Controller&) = delete;
            Controller& operator=(Controller&&)      = delete;

            ~Controller();

            /**
             * @brief Execute main program
             */
            void execute();
    };
}

#endif /* define CONTROLLER_H_ */
