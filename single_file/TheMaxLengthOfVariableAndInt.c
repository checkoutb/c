#include <stdio.h>

int qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui1;
int qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui2;

int main()
{
    int asdfghj2 = 3;
    int asdfghj1 = 4;

    qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui1 = 1;
    qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui2 = 2;
    printf("%d, %d", asdfghj1, asdfghj2);
    printf("\n%d, %d", qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui1, qwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyuiqwertyui2);

    asdfghj2 = asdfghj1 = 2100000000;
    asdfghj1 += asdfghj1;
    printf("\n%d, %d", asdfghj1, asdfghj2);

    long qwe1 = 1;
    long qwe2 = 1;
    qwe1 = 2100000000l;
    qwe2 = qwe1;
    qwe1 += qwe1;
    printf("\n%ld, %d\n", qwe1, qwe2);      //ld,d�����ԣ������32λ�ġ�

    float f = 1231.23;
    printf("%*.*f\n", 13, 6, f);     //�������,��һ����(����+С��+.����)��С��ȣ���������ಹ�ո񣬳����ͳ����ˣ������ȡ���ڶ�����С����λ���������ͽ�ȡ���������Ҳಹ0.


    long long q1;
    long long q2;
    q2 = 2100000000;
    q1 = 2100000000;
    q2 += q1;
    printf("%lld, %lld\n", q1, q2);
    printf("%I64d, %I64d\n", q1, q2);     //����˵vc6.0�����������������һ��ҪI64d����Сд���ܴ�����Ҳ���á�
    printf("%d, %d, %d, %d\n", q1, q2);     //?
    printf("%ld, %ld\n", q1, q2);      //?


    long long int a=0xFFFFFFFFFFFFFFFF;
    printf("%d, %d\n", a);      //ѹջѹ����64λ�ģ�Ȼ��%dȡ��32λ��Ȼ����%dȡ��32λ��
}
