#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>


class A{
public:
    static void static_func()
    {
         printf("call static func\n");
    }

    void nonstatic_func()
    {
         printf("call nonstatic func\n");
    }

    virtual void virtual_func()
    {
        printf("call virtual func\n");
    }
};


int main(int argc,char *argv[])
{

    A a;

    void (*pfunc_1)() = A::static_func;
    (*pfunc_1)();


    //Note: here must use &A::nonstatic_func
    void (A::*pfunc_2)() = &A::nonstatic_func;
    (a.*pfunc_2)();


    // virtual member function
    uintptr_t **p = (uintptr_t **)&a;
    typedef void (*pvirtual_func)(A *);
    pvirtual_func pvfunc = (pvirtual_func)**p;
    pvfunc(&a);

    // another method to call virtual function
    void (A::*pfunc_3)() = &A::virtual_func;
    (a.*pfunc_3)();

    return 0x0;
}
