#ifndef WASH_PROGRAMME_H
#define WASH_PROGRAMME_H

#include <vector>
#include "step.hpp"

namespace WMS 
{
    class Wash_programme
    {
        private:
        std::vector<Step> steps {};

        public:
        Wash_programme(std::initializer_list<Step> steps) : steps {steps} {};
        void add(Step step);
        void run();
        void remove(Type step_type);
    };
}

#endif