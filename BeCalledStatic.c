#include <stdio.h>

static int global = 5;      //加了还是被调用了。

static int show(int a)
{
    printf("this is BeCalledStatic.c and what you want printf is :%d\n", a);
    return 0;
}

//int main()
//{
//    show(11);
//    return 0;
//}
