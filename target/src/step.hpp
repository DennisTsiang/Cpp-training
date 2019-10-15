#include "Time.h"
#include <iostream>
#include <cstdio>
#include "washing_machine_type.hpp"

#ifndef STEP_H
#define STEP_H

namespace WMS
{

    class Step 
    {
        private:
        enum Type type;
        Time::Duration duration; // in milliseconds
        const char* typeStrings[4] { "invalid", "empty", "fill", "heat" };

        protected:
        void display();

        public:
        Step();
        Step(enum Type type, Time::Duration duration);
        ~Step();
        void run();
    };
}

#endif