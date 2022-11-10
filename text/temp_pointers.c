#include <stdio.h>
#include <stdlib.h>

void alterTheValue(int x);
void alterTheValueByRef(int * ptr_b);

int main()
{
    int x = 23;

    alterTheValue(x);
    alterTheValueByRef(&x);

    int * ptr_x = &x;
    int y = *ptr_x;

    printf("%i\n", y);



    return 0;
}

void alterTheValue(int a) {

   a++;
   printf("%i\n", a);

}

void alterTheValueByRef(int * ptr_b) {

   *ptr_b = *ptr_b + 1;
   printf("%i\n", *ptr_b);

   printf("%x\n", ptr_b);
   printf("%x\n", ++ptr_b);

}


#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>

void alterTheValue(int x);
void alterTheValueByRef(int * ptr_b);

int main()
{
    int x = 23;

    alterTheValue(x);
    alterTheValueByRef(&x);

    int * ptr_x = &x;
    int y = *ptr_x;

    printf("%i\n", y);
    printf("%s\n", typeid(y).name());


    return 0;
}

void alterTheValue(int a) {

   a++;
   printf("%i\n", a);

}

void alterTheValueByRef(int * ptr_b) {

   *ptr_b = *ptr_b + 1;
   printf("%i\n", *ptr_b);

   printf("%x\n", ptr_b);
   printf("%s\n", typeid(ptr_b).name());
   printf("%x\n", ++ptr_b);
  
}
