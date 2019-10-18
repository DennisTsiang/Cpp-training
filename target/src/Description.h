#ifndef DESCRIPTION_H
#define DESCRIPTION_H

namespace WMS
{
    class Description
    {
        public:
        Description();
        Description(const char* desc);
        Description(const Description& other_desc);
        Description(Description&& rhs) noexcept;

        const char* c_str() const; // const at end means we don't modify the object
        
        Description& operator=(Description rhs);
        ~Description();
        friend void swap(Description& lhs, Description& rhs);
        private:
        char* desc;
    };
}

#endif