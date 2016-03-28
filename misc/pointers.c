#include <stdio.h>
#include <stdlib.h>

void
f(void)
{
    int a[4];
    int *b = malloc(16);
    int *c;
    int i;

    // print address of a, b, c
    printf("1: a = %p, b = %p, c = %p\n", a, b, c);

    // assign address of array a to pointer c
    c = a;
    for (i = 0; i < 4; i++)
	a[i] = 100 + i;
    // a[0] = 200
    c[0] = 200;
    printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // this will result: 200 101 102 103

    // a[1] = 300
    c[1] = 300;
    // a[2] = 301
    *(c + 2) = 301;
    // c[3] = a[3] = 302
    3[c] = 302;
    printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    // result: 200 300 301 302

    // c point to a[1]'s address
    c = c + 1;
    // a[1] = 400
    *c = 400;
    printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    printf("%p\n", (void*)a);
    printf("%p\n", (void*)(a+1));
    printf("%p\n", (void*)(a+2));
    printf("%p\n", (void*)(a+3));
    printf("%p\n", (void*)(c));
    // result: 200 400 301 302

    // char: 1 bytes
    // int: 4 bytes
    // c  + 1: a[2]
    // (char *) c + 1 -> cast to 1 byte
    // 
    // a = C8 00 00 00 | 90 01 00 00 | 2D 01 00 00 | 2E 01 00 00
    // c point to a[1] + 1 byte
    c = (int *) ((char *) c + 1);
    printf("%p\n", (void*)(c));
    printf("%p\n", (void*)(c + 1));
    // 500 = F4 01 00 00
    // a = C8 00 00 00 | 90 F4 01 00 | 00 01 00 00 | 2E 01 00 00
    *c = 500;
    printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    // b = address of a[1] = a[0] + 4 byte
    b = (int *) a + 1;
    // c = address of a[0] + 1 byte
    c = (int *) ((char *) a + 1);
    printf("6: a = %p, b = %p, c = %p\n", a, b, c);
}

int
main(int ac, char **av)
{
    f();
    // printf("%d", sizeof(char));
    return 0;
}

