#include "BeCalledStatic.c"         //�Լ����ļ�
#include <stdio.h>                  //ϵͳ���ļ�

//extern int global;      //��֪��extern��ʲô�ã��Ӳ��Ӷ�һ����
//int show();
//���������Ҿ����е㲻�Ծ�����

int main()
{
//    global = 2;
    show(4);
    printf("%d\n", global);
}
