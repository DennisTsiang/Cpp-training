#include "wash_programme.h"
#include <algorithm>

namespace WMS {

    void Wash_programme::add(const Step &step)
    {
        this->steps.push_back(step);
    }

    void Wash_programme::run()
    {
        std::for_each(this->steps.begin(), this->steps.end(),
            [](Step &step) -> void { step.run(); });
    }

    void Wash_programme::remove(Type step_type)
    {
        std::remove_if(this->steps.begin(), this->steps.end(),
            [step_type](Step &step) -> bool { return step.get_type() == step_type; });
    }
}