#include <stdio.h>
#include <stdlib.h>


class CVariable{
private:
   int m_a;
   int m_b;
   int m_c;
};

int main(int argc,char *argv[])
{
   CVariable pVarA;
   int a = 0;
   int b = a;
   printf("b = %d\n", b);
   printf("&pVarA: %p\n", &pVarA);
   printf("sizeof(CVariable): %d\n", sizeof(CVariable));

   return 0x0;
}
