#include <iostream>

#include "context.h"

class TContext::TImpl
{
public:
    TImpl()
    {
        std::cout << "TImpl::TImpl" << std::endl;
    }

    ~TImpl()
    {
        std::cout << "TImpl::~TImpl" << std::endl;
    }
};

TContext::TContext()
    : Impl(new TImpl)
{
}

TContext::~TContext()
{
}

TObject TContext::CreateObject()
{
    return TObject(*this);
}

