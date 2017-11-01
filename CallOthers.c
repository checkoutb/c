#include "BeCalledStatic.c"         //自己的文件
#include <stdio.h>                  //系统的文件

//extern int global;      //不知道extern有什么用，加不加都一样。
//int show();
//。。。。我觉得有点不对劲。。

int main()
{
//    global = 2;
    show(4);
    printf("%d\n", global);
}
