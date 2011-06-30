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
        : Context(context.Impl)
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

private:
    class TImpl;
    std::shared_ptr<TImpl> Impl;
    friend class TObjectInContext<TContext>;
};

#endif

