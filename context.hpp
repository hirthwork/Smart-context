#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include <memory>

class TObject;
class TContext
{
    class TImpl;
    std::shared_ptr<TImpl> Impl;

public:
    typedef decltype(Impl) TContextImpl;
    TContext();
    std::unique_ptr<TObject> CreateObject();
};

#endif

