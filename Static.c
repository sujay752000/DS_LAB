#include <stdio.h>

int myfun()
{
    static int i = 0; // only one time can a ststic variable can be declared
    i++;              // and also static variables remembers last stored value even it is goes out of scope
    return i;
}

int main()
{
    printf("Value is %d\n", myfun());
    printf("Value is %d\n", myfun());
    return 0;
}