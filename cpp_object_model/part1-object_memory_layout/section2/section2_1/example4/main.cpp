#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>

class CParent{
private:
  int m_nAge;
public:
   virtual void f0(){ printf("f0()\n"); }
   virtual void g0(){ printf("g0()\n"); }
   virtual void h0(){ printf("h0()\n"); }
};

int main(int argc,char *argv[])
{
   CParent pParentA;
   uintptr_t **p = (uintptr_t **)&pParentA;
 
   typedef void (*pvirtualfunc)(CParent *);

   printf("sizeof(CParent): %d\n", sizeof(CParent));

   pvirtualfunc func1 = (pvirtualfunc)**p;
   func1(&pParentA);

   pvirtualfunc func2 = (pvirtualfunc)(*(*p + 1));
   func2(&pParentA);

   pvirtualfunc func3 = (pvirtualfunc)(*(*p + 2));
   func3(&pParentA);
  
   return 0x0;
}
