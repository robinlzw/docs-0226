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

class CGrandChildren: public CChildren{
private:
    int m_nGrandChildren;

public:
   virtual void f0(){ printf("grand children f0()\n"); }
   virtual void h1(){ printf("grand children h1()\n"); }
   virtual void f2(){ printf("grand children f2()\n"); }
   virtual void f3(){ printf("grand children f3()\n"); }
};

int main(int argc,char *argv[])
{
   CGrandChildren pGrandChildrenA;
   uintptr_t **p = (uintptr_t **)&pGrandChildrenA;
 
   typedef void (*pvirtualfunc)(CGrandChildren *);

   printf("sizeof(CGrandChildren): %d\n", sizeof(CGrandChildren));

   pvirtualfunc func1 = (pvirtualfunc)**p;
   func1(&pGrandChildrenA);
   
   pvirtualfunc func2 = (pvirtualfunc)(*(*p + 1));
   func2(&pGrandChildrenA);
   
   pvirtualfunc func3 = (pvirtualfunc)(*(*p + 2));
   func3(&pGrandChildrenA);

   pvirtualfunc func4 = (pvirtualfunc)(*(*p + 3));
   func4(&pGrandChildrenA);

   pvirtualfunc func5 = (pvirtualfunc)(*(*p + 4));
   func5(&pGrandChildrenA);

   pvirtualfunc func6 = (pvirtualfunc)(*(*p + 5));
   func6(&pGrandChildrenA);

   pvirtualfunc func7 = (pvirtualfunc)(*(*p + 6));
   func7(&pGrandChildrenA);

   pvirtualfunc func8 = (pvirtualfunc)(*(*p + 7));
   func8(&pGrandChildrenA);

   printf("=============================\n");

   char *q = (char *)&pGrandChildrenA;
   q = q + 8 + 4 + 4;

   p = (uintptr_t **)q;

   pvirtualfunc func9 = (pvirtualfunc)**p;
   func9(&pGrandChildrenA);

   return 0x0;
}
