#include <stdio.h>

//argc����������ģ���ϵͳ����������ĵ������Զ����õġ�
int main(int argc, char *argv[])            //ֻ��cmd��������� Ӣ�ľ��ӡ�
{
    for(int i = 0; i < argc; i++)       //��һ����cmd�ĵ�һ�����ʣ����� ��������֡�
    {
        printf("%s, ", argv[i]);
    }
//    printf("%d %d", argc, argv);
    return 0;
}
