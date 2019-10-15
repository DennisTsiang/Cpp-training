#include "Time.h"
#include <iostream>
#include <cstdio>
#include "step.hpp"

using Time::operator"" _ms;

namespace WMS
{

    Step::Step(): Step(Type::invalid, 1000_ms) 
    {
    }

    Step::Step(enum Type type, Time::Duration duration): type{type}, duration{duration}
    {
        std::cout << "Step constructor called" << std::endl;
    }

    Step::~Step()
    {
        std::cout << "Step deconstructor called" << std::endl;
    }

    void Step::display()
    {
        printf("Step %s running for %f milliseconds\n", 
            this->typeStrings[this->type], 
            this->duration.as_ticks() / 1000.0);
    }

    void Step::run()
    {
        this->display();
        Time::sleep(this->duration);
    }

    Type Step::get_type()
    {
        return this->type;
    }
}
