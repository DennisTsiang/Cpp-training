#ifndef STEP_H
#define STEP_H

#include "Time.h"
#include <iostream>
#include <cstdio>

namespace WMS
{

    enum Type { invalid, empty, fill, heat, wash };

    class Step 
    {
        private:
        Type type;
        Time::Duration duration; // in milliseconds
        const char* typeStrings[5] { "invalid", "empty", "fill", "heat", "wash" };

        protected:
        void display();

        public:
        Step();
        Step(enum Type type, Time::Duration duration);
        ~Step();
        void run();
        Type get_type();
    };
}

#endif