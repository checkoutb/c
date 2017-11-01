#include <stdio.h>

int main()
{
//    printf("%d", a);      //调不到的。！！
    for(int i = 3; i <5; i++)
    {
        Local();
    }
    Local();
    return 0;
}

void Local()
{
    static int a = 5;       //可以输出678
//    int a = 5;            //输出666
    a++;
    printf("%d\n", a);
}
