#include <iostream>
#include "context.h"
#include "object.h"

class TObject::TImpl: TObjectInContext<TContext>
{
public:
    TImpl(const TContext& context)
        : TObjectInContext<TContext>(context)
    {
    }

    TImpl(const TImpl& impl)
        : TObjectInContext<TContext>(impl)
    {
    }

    ~TImpl()
    {
    }
};

TObject::TObject(const TContext& context)
    : Impl(new TImpl(context))
{
    std::cout << "TObject::TObject" << std::endl;
}

TObject::TObject(const TObject& object)
    : Impl(new TImpl(*object.Impl))
{
    std::cout << "TObject::TObject(copy)" << std::endl;
}

TObject& TObject::operator =(const TObject& object)
{
    Impl.reset(new TImpl(*object.Impl));
    std::cout << "TObject::TObject(assign)" << std::endl;
}

TObject::~TObject()
{
    std::cout << "TObject::~TObject" << std::endl;
}

