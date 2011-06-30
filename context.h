#ifndef __CLASS_H__
#define __CLASS_H__

#include <memory>
#include <iostream>

#include "object.h"

// TODO: shorter name
template <class T>
class TObjectInContext
{
    std::shared_ptr<typename T::TImpl> Context;
public:
    TObjectInContext(const T& context)
        : Context(context.GetImpl())
    {
    }

    // Only for debugging purposes, default is a fine too
    TObjectInContext(const TObjectInContext& object)
        : Context(object.Context)
    {
    }

    ~TObjectInContext()
    {
    }
};

class TContext
{
public:
    TContext();
    ~TContext();
    TObject CreateObject();

    class TImpl;
    inline const std::shared_ptr<TImpl>& GetImpl() const
    {
        return Impl;
    }

private:
    std::shared_ptr<TImpl> Impl;
};

#endif

