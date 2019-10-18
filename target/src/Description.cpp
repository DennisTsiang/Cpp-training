#include "Description.h"
#include <iostream>
#include <cstring>
#include <utility>

namespace WMS
{

    Description::Description() : Description::Description(nullptr)
    {
    }

    Description::Description(const char* desc)
    {
        std::cout << "Description Constructor called" << std::endl;
        if (desc)
        {
            char* new_buffer { new char[strlen(desc)+1] };
            strncpy(new_buffer, desc, strlen(desc));
            this->desc = new_buffer;
        }        
        
    }

    const char* Description::c_str() const
    {
        return this->desc == nullptr ? "" : this->desc;
    }

    Description::Description(const Description& other_desc)
        : Description { other_desc.desc }
    {
        std::cout << "Description Copy constructor called" << std::endl;
    }

    Description& Description::operator=(Description rhs)
    {
        std::cout << "Description Assignment operator called" << std::endl;
        std::swap(this->desc, rhs.desc);
        return *this;
    }

    Description::Description(Description&& rhs) noexcept
        : Description { }
    {
        std::cout << "Description move constructor called" << std::endl;
        swap(*this, rhs);
    }

    void swap(Description& lhs, Description& rhs)
    {
        using std::swap;
        swap(lhs.desc, rhs.desc);
    }

    Description::~Description()
    {
        std::cout << "Description Destructor called" << std::endl;
        delete[] this->desc;
    }
}