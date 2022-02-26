#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>

class CParent1{
private:
  int m_nParent1;
public:
   virtual void f0(){ printf("f0()\n"); }
   virtual void g0(){ printf("g0()\n"); }
   virtual void h0(){ printf("h0()\n"); }
};

class CParent2{
private:
   int m_nParent2;

public:
   virtual void f1(){ printf("f1()\n"); }
   virtual void g1(){ printf("g1()\n"); }
   virtual void h1(){ printf("h1()\n"); }
};

class CChildren : public CParent1, public CParent2{
private:
   int m_nChildren;

public:
   virtual void f0(){ printf("children f0()\n"); }
   virtual void g1(){ printf("children g1()\n"); }
   virtual void f2(){ printf("children f2()\n"); }

   virtual void h0(){ printf("children h0()\n"); }
   virtual void h1(){ printf("children h1()\n"); }
   virtual void h2(){ printf("children h2()\n"); }
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

   pvirtualfunc func5 = (pvirtualfunc)(*(*p + 4));
   func5(&pChildrenA);
  
   pvirtualfunc func6 = (pvirtualfunc)(*(*p + 5));
   func6(&pChildrenA);

   pvirtualfunc func7 = (pvirtualfunc)(*(*p + 6));
   func7(&pChildrenA);

   printf("===============================\n");
   char *q = (char *)&pChildrenA;
   q = q + 8 + 4 +4;
   p = (uintptr_t **)q;

   pvirtualfunc func8 = (pvirtualfunc)**p;
   func8(&pChildrenA);

   return 0x0;
}
