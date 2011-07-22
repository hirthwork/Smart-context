#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <memory>

#include "context.hpp"

class TObject
{
    TContext::TContextImpl Context;

public:
    inline TObject(const TContext::TContextImpl& context)
        : Context(context)
    {
    }
};

#endif

