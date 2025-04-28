#include <stdio.h>

void recurse()
{
    return recurse();
}

int main()
{
    recurse();
    return 0;
}