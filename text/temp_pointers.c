#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[15] = "Hello, world";

    printf("%s\n",x);

// myCTalkthrough
//
//    char 	dec		bin
//    m			109		01101101
//    y			121		01111001
//    C			 67		01000011
//    T			 84		01010100
//    a			 97		01100001
//    l			108		01101100
//    k			107		01101011
//    t			116		01110100
//    h			104		01101000
//    r			114		01110010
//    o			111		01101111
//    u			117		01110101
//    g			103		01100111
//    h			104		01101000
//
// 		1 byte	 1 byte		an int = 4 byte = 32 bit 				 an int = 4 byte = 32 bit					an int = 4 byte = 32 bit
//    01101000 01100111 01110101011011110111001001101000 01110100011010110110110001100001 01010100010000110111100101101101
//			104			103				1970238056												1953197153											1413708141

		    unsigned int * ptr_int = &x;
		    char * ptr_char = &x;

		    unsigned int left = 1413708141;
		    unsigned int middle = 1953197153;
		    unsigned int right = 1970238056;
		    char restToTheRight = 103;

		    *ptr_int = left;
		    ptr_int++;
		    *ptr_int = middle;
		    ptr_int++;
		    *ptr_int = right;

		    ptr_char = ptr_char + 12;
		    *ptr_char = restToTheRight;
		    restToTheRight++;
		    ptr_char++;
		    *ptr_char = restToTheRight;
		    x[14] = '\0';

    printf("%s\n",x);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[] = "Hello, world";

    printf("%s\n",x);
    printf("%c\n",x[0]);

    for (int i = 0; i < 12; i++) {
			    printf("%c\n",x[i]);
    }
    printf("%c\n",x[12]);

    char * ptr_x = &x;

    printf("%x\n",ptr_x);
		printf("%c\n",*ptr_x);
		ptr_x++;
		printf("%c\n",*ptr_x);
		ptr_x = ptr_x + 10;
		printf("%c\n",*ptr_x);
		ptr_x++;
		printf("%c\n",*ptr_x);
		ptr_x++;
		printf("%c\n",*ptr_x);
		ptr_x--;
		printf("%c\n",*ptr_x);


    return 0;
}

//////////////////////////////////////////////////////////////////////////////

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
    printf("Size: %d\n", sizeof(y));




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
   printf("Size: %d\n", sizeof(ptr_b));
   printf("%x\n", ++ptr_b);

}

//////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main()
{
	int i = 0;
	int* i_ptr;
	unsigned char r = 97, g = 98, b = 99;
	unsigned char* r_ptr;
	unsigned char* g_ptr;
	unsigned char* b_ptr;
	unsigned char* current_ptr;

	i_ptr = &i;
	i = 123456;
	// 65 ('A')	66 ('B')	67 ('C')	126 ('~')
	// 01000001	01000010	01000011	01111110
	// decimal
	// 1094861694
	i = 1094861694;

	r_ptr = &r;
	g_ptr = &g;
	b_ptr = &b;

	printf("%d is of size %d bytes\n",i, sizeof(i));
	printf("The pointer points to %0x where %d is stored of size %d bytes\n",i_ptr, *i_ptr, sizeof(i_ptr));

	printf("\n");

	printf("%i is of size %d bytes\n",r , sizeof(r));
	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",r_ptr, *r_ptr, sizeof(r_ptr));
	printf("%i is of size %d bytes\n",g , sizeof(g));
	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",g_ptr, *g_ptr, sizeof(g_ptr));
	printf("%i is of size %d bytes\n",b , sizeof(b));
	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",b_ptr, *b_ptr, sizeof(b_ptr));

//	current_ptr = i_ptr;
//	r_ptr = current_ptr;
//	current_ptr++;
//	g_ptr = current_ptr;
//	current_ptr++;
//	b_ptr = current_ptr;

	current_ptr = i_ptr;
	current_ptr++;
	current_ptr++;
	current_ptr++;
	r_ptr = current_ptr--;
	g_ptr = current_ptr--;
	b_ptr = current_ptr;

	printf("\n");

	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",r_ptr, *r_ptr, sizeof(r_ptr));
	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",g_ptr, *g_ptr, sizeof(g_ptr));
	printf("The pointer points to %0x where %c is stored. Pointer size: %d bytes\n",b_ptr, *b_ptr, sizeof(b_ptr));

	return(0);
}
