#include "context.h"

int main()
{
    TObject object = TContext().CreateObject();
    {
        TContext context;
        object = context.CreateObject();
    }
    std::cout << "very last line" << std::endl;
}
