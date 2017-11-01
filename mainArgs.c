#include <stdio.h>

//argc并不是输入的，是系统根据你输入的单词数自动设置的。
int main(int argc, char *argv[])            //只能cmd启动，输出 英文句子。
{
    for(int i = 0; i < argc; i++)       //第一个是cmd的第一个单词，就是 程序的名字。
    {
        printf("%s, ", argv[i]);
    }
//    printf("%d %d", argc, argv);
    return 0;
}
