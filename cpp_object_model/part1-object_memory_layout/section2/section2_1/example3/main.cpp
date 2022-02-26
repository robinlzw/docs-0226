#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>

class CVFunction{
public:
   virtual void f(){ printf("f()\n"); }
   virtual void g(){ printf("g()\n"); }
   virtual void h(){ printf("h()\n"); }
};

int main(int argc,char *argv[])
{
   CVFunction pVFunc;
   uintptr_t **p = (uintptr_t **)&pVFunc;

   typedef void (*pvirtualfunc)(CVFunction *);

   printf("sizeof(CVFuncation): %d\n", sizeof(CVFunction));

   pvirtualfunc func1 = (pvirtualfunc)**p;
   func1(&pVFunc);

   pvirtualfunc func2 = (pvirtualfunc)(*(*p + 1));
   func2(&pVFunc);

   pvirtualfunc func3 = (pvirtualfunc)(*(*p + 2));
   func3(&pVFunc);
  
   return 0x0;
}
