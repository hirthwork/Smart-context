#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <memory>

class TContext;
class TObject
{
    class TImpl;
    std::unique_ptr<TImpl> Impl;

public:
    TObject(const TContext& context);

    // Only for debugging purposes, default is a fine too
    TObject(const TObject& object);

    TObject& operator =(const TObject& object);

    ~TObject();
};

#endif

