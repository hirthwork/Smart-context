#include <iostream>
#include <memory>

#include "context.hpp"
#include "object.hpp"

struct TContext::TImpl : std::enable_shared_from_this<TContext::TImpl>
{
    inline TImpl()
    {
        std::cout << "TImpl::TImpl" << std::endl;
    }

    inline ~TImpl()
    {
        std::cout << "TImpl::~TImpl" << std::endl;
    }
};

TContext::TContext()
    : Impl(new TImpl)
{
}

std::unique_ptr<TObject> TContext::CreateObject()
{
    return std::unique_ptr<TObject>(new TObject(Impl->shared_from_this()));
}

