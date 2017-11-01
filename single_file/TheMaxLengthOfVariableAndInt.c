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
    printf("\n%ld, %d\n", qwe1, qwe2);      //ld,d都可以，输出是32位的。

    float f = 1231.23;
    printf("%*.*f\n", 13, 6, f);     //精度误差,第一个是(整数+小数+.部分)最小宽度，不够就左侧补空格，超过就超过了，不会截取，第二个是小数的位数，超过就截取，不满就右侧补0.


    long long q1;
    long long q2;
    q2 = 2100000000;
    q1 = 2100000000;
    q2 += q1;
    printf("%lld, %lld\n", q1, q2);
    printf("%I64d, %I64d\n", q1, q2);     //网上说vc6.0是这种输出。。。是一定要I64d，大小写不能错。这里也能用。
    printf("%d, %d, %d, %d\n", q1, q2);     //?
    printf("%ld, %ld\n", q1, q2);      //?


    long long int a=0xFFFFFFFFFFFFFFFF;
    printf("%d, %d\n", a);      //压栈压的是64位的，然后%d取出32位，然后再%d取出32位。
}
