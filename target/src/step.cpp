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

    Step::Step(enum Type type, Time::Duration duration)
        : Step(type, duration, "No description provided")
    {
    }

    Step::Step(enum Type type, Time::Duration duration, const char* description) 
        : type{type}, duration{duration}, description{ description }
    {
        std::cout << "Step constructor called" << std::endl;
    }

    Step::Step(const Step& other) 
        : type{other.type}, duration{other.duration}, description{other.description}
    {
        std::cout << "Step copy constructor called" << std::endl;
    }

    Step::Step(Step&& other) noexcept
       : type{other.type}, duration{other.duration}, description{std::move(other.description)}

    {
        std::cout << "Step move constructor called" << std::endl;
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
        std::cout << this->description.c_str() << std::endl;
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
