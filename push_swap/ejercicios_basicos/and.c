#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0x7FFFFFFF;
    int b = 0x7FFFFFFE;
    int c = 0x01;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a & b = %d\n", a & c);
    printf("a & b = %d\n", b & c);
    return 0;
}
