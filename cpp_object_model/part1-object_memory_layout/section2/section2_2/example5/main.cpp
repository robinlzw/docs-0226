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

class CChildren : public CParent{
private:
   int m_nChildren;

public:
   virtual void f0(){ printf("children f0()\n"); }
   virtual void g1(){ printf("g1()\n"); }
   virtual void h0(){ printf("children h0()\n"); }
};

int main(int argc,char *argv[])
{
   CChildren pChildrenA;
   uintptr_t **p = (uintptr_t **)&pChildrenA;
 
   typedef void (*pvirtualfunc)(CChildren *);

   printf("sizeof(CChildren): %d\n", sizeof(CChildren));

   pvirtualfunc func1 = (pvirtualfunc)**p;
   func1(&pChildrenA);

   pvirtualfunc func2 = (pvirtualfunc)(*(*p + 1));
   func2(&pChildrenA);

   pvirtualfunc func3 = (pvirtualfunc)(*(*p + 2));
   func3(&pChildrenA);

   pvirtualfunc func4 = (pvirtualfunc)(*(*p + 3));
   func4(&pChildrenA);
  
   return 0x0;
}
