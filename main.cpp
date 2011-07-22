#include <iostream>
#include "context.hpp"
#include "object.hpp"

int main()
{
    TObject object = *TContext().CreateObject();
    {
        TContext context;
        std::cout << "another context created" << std::endl;
        object = *context.CreateObject();
        std::cout << "leaving scope" << std::endl;
    }
    std::cout << "very last line" << std::endl;
}
