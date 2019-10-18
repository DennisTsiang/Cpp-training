#ifndef STEP_H
#define STEP_H

#include "Time.h"
#include <iostream>
#include <cstdio>
#include "Description.h"

namespace WMS
{

    enum Type { invalid, empty, fill, heat, wash };

    class Step 
    {
        private:
        Type type;
        Time::Duration duration; // in milliseconds
        const char* typeStrings[5] { "invalid", "empty", "fill", "heat", "wash" };
        Description description;

        protected:
        void display();

        public:
        Step();
        Step(Step&& other) noexcept;
        Step(const Step& other);
        Step(enum Type type, Time::Duration duration);
        Step(enum Type type, Time::Duration duration, const char* description);
        Step& operator= (const Step& rhs) = default;
        Step& operator= (Step&& rhs) = default;
        ~Step();
        void run();
        Type get_type();
    };
}

#endif