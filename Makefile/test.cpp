#include "test.h"
#include <cstdio>

int main(int argc, char *argv[])
{
    float a = 8.7, b = 3.9;
    printf("%f + %f = %f\n",a ,b, add(a,b));
    printf("%f - %f = %f\n",a ,b, sub(a,b));
    printf("%f * %f = %f\n",a ,b, mul(a,b));
    getchar();
    return 0;
}