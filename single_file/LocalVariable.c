#include <stdio.h>

int main()
{
//    printf("%d", a);      //�������ġ�����
    for(int i = 3; i <5; i++)
    {
        Local();
    }
    Local();
    return 0;
}

void Local()
{
    static int a = 5;       //�������678
//    int a = 5;            //���666
    a++;
    printf("%d\n", a);
}
