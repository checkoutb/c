#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define qqq 4
int a = 1;
//int imax2(int, int);
void show3(void);           //原型 != 声明 void加或不加。

int main(void)
{
//    _Bool b;

//    int a = 10;
//    int b = 2;
//    printf("%d,%d, %d, %x\n", a, 3, b-(a++), &a);
//    printf("%d,%x,%d,%d\n", a, &a);
//    printf("%x,%d,%d,%d\n", &a);
//    printf("%d",printf("%d",printf("%d",43)));
//    printf("\n\n");


//    a = 1024;
//    printf("%o,%x, %O, %X\n", a, a,a,a);            //%O error
//    printf("%#o, %#O, %#x, %#X\n", a, a, a, a);     //%#O error

//
//    unsigned short int sh = 65535;
//    printf("%x\n", sh);
//    printf("%x\n", (sh+1));         //this is int...
//
//    short sh2 = 32767;
//    printf("%i\n", sh2);
//    printf("%i\n", (short)((sh2+1)));       //...short+int=int
//
//    short sh3 = 32768;
//    printf("%i\n", sh3);

//    short sh4 = 32767;            //未解决，想获得超越上限后进位到前面一个字节的值。.how to get the number that over range.
//    printf("%i, %i, %i\n", sh4, (*(&sh4-2))&&0xff, (*(&sh4+2))&&0xff);  //cache...so i cannot decide it is successful or not

//    short sh5 = 32765;
//    unsigned short sh6 = 50000;
//    printf("%i, %i, %u, %u", sh5, sh6, sh5, sh6);   //%d %i %u 都一样啊。

//    int i1 = 2100000000;
//    unsigned i2 = 3000000000;
//    printf("%i, %u, %d", i1, i2, i2);       //%i%d%u  all int's.

//    int i3 = 0xffffffff;        //0xffffffff == -1   0x7fffffff == 2147483647
//    printf("%d, %d, %d, %d", i3, *((&i3)+2)&&0xff, *((&i3)+4)&0xff, (i3+1));   //also connot get the number over range

//    int i4 = -5;
//    printf("%d, %u\n", i4, i4);
//    printf("%#x, %#x\n", &(i4));

//    int i5 = 3000000000-1000000000;     //3000000000 is long
//    printf("%d\n", i5);

//    && is logical and , & is and by bit.....and if it is int, -1 == -4bit....
//    unsigned int i6 = 0x3fffffff1;      //have unsigned or not  won't change the printf.
//    printf("%u, %d, %x, %d", i6, i6, i6, (*((&i6)-4))&&0xff);     //...the number over range just change one byte,so u need &&0xff to get the last byte.
//                                                    //e...it seem still error,it still printf 1,not 3, don't know how to get the number over range

//    int a[3] = {0,0xffffffff,0};        // int a[3],,not int[3] a....
//    printf("%u, %u, %u\n", a[0], a[2], a[1]);
//    a[1] += 1;
//    printf("%u, %u, %u\n", a[0], a[2], a[1]);       //it seem won't affect other byte...
//    printf("%x, %x, %x\n", &a[0], &a[2], &a[1]);

//    int i8 = 2100000000;
//    printf("%hd, %h, %d\n", i8, i8, i8);      //short and int...
//    long l1 = 3000000000;           //300millions is bigger then the MAX of long...long is 32bits..
//    printf("%ld, %l, %d\n", l1, l1, l1);
//    long l2 = 2100000000;
//    printf("%ld, %l, %d\n", l2, l2, l2);        //%l %h is nonesence
//    printf("%lu, %ul, %u\n", l1, l1, l1);       //%ul is nonesencce
//    printf("%hu, %uh, %u\n", l2, l2, l2);       //%uh is useless
//    printf("%lx, %hx, %lo\n", l2, l2, l2);
//
//    long long ll1 = 3000000000;
//    printf("%lld, %llu\n", ll1, ll1);
//    printf("%I64d, %I64u\n", ll1, ll1);
//
//    unsigned long l3 = 3000000000;
//    printf("%ld, %lu", l3, l3);     //yeah,althrough it over range,but it also can be an unsigned long....just decided by format.

//    long l4 = 0xffffffff;
//    l4 += 1;
//    long long ll2 = (long long)l4;
//    printf("%ld, %lld", l4, ll2);

//    char c1 = '中';
//    int i;
//    printf("%c, %cu, %d, %d\n", c1, c1, c1, i);      //只有正数部分有用的感觉，..%cu..不知道是什么,是无符号char？%uc会变成%u然后后面加个c，但是可以输出一个字，虽然不是我输入的。
//    printf("%d, %d\n", sizeof(c1), sizeof(i));
//    char c2 = 'A';
//    printf("%c, %c, %cu, %cu\n", c1, c2, c1, c2);     //!!!!!!非常奇怪的输出。%cu不知道是什么，如果char是ascii，那么是%c输出最后+u，如果char非ascii，那么就是%cu整体起作用

//    _Bool b1, b2;
//    printf("%d, %d\n", b1, sizeof(b2));
////    b1 = 0;
//    if(b1)
//    {
//        printf("true");
//    }

//    int_fast16_t a = 4;
//    printf("%d\n", a);

//    float f = 1.1f;
//    double d = 1.2;
//    long double ld = 1.3l;
//    printf("%f, %f, %Lf, %lf\n", f, d, ld, ld);       //lf??
//    printf("%e, %e, %Le, %le\n", f, d, ld, ld);
//    printf("%a, %a, %La, %la\n", f, d, ld, ld);
//    printf("%F, %F, %LF, %lF\n", f, d, ld, ld);       //lf??
//    printf("%E, %E, %LE, %lE\n", f, d, ld, ld);
//    printf("%A, %A, %LA, %lA\n", f, d, ld, ld);

//    double d2 = 1e1000;
//    printf("%f\n", d2);     //over the range will print inf/infinity

//    double d3 = 1e-1000;
//    printf("%f\n", d3);       //0.00000

//    printf("%f\n", asin(4));      //nan
//    printf("%f\n", 'a');          //nan
//    printf("%f\n", (int)'a');     //nan
//    printf("%f\n", (float)('a')); //97.00000
//
//    printf("%d\n", 'a');          //97
//    printf("%c\n", 97);           //a

//    double d4 = 2e20;
//    printf("%f\n", d4);
//    d4 += 1;
//    printf("%f\n", d4);
//    d4 -= 1;
//    printf("%f\n", d4);       //3 printf is same....for e20 is too big.

//    double d5 = 2e20 + 1.0;
//    double d6 = d5 - 2e20;
//    printf("%f\n", d6);         //zero,also for e20 is too big

//    double _Imaginary d;      //cannot work
//    printf("%d\n", d);

//    short s = 1;
//    printf("%zd\n", sizeof(s));      //2
//    printf("%zd\n", 111);           //what is zd???

//    char s[10] = {'a'};
//    printf("input your name:");
//    scanf("%s", s);                 //blank will end the input
//    int l = strlen(s);
//    printf("your name is %s. and length is %d and sizeof is %d\n", s, l, sizeof s);
//    char ss[10] = {'s','s','s','s','s','s','s','s','s','D'};
//    printf("%d, %d\n", strlen(ss), sizeof ss);
//    printf("%s\n", ss);                             //cool,need s[10]
//    printf("%d, %d\n", s, ss);

//    int a = 0x04030201;
//    char c = 'a';
//    printf("%d, %d, %d, %d\n", (*(&a))&0xff, (*(&a-1))&0xff, (*(&a-2))&0xff, (*(&a-3))&0xff);
//    printf("%d, %d, %d, %d, %d, %d\n", &a, &a-1, &c);         //..fk -1 == -sizeof int...
//    printf("%d, %d, %d, %d", *(&c+1),*(&c+2),*(&c+3),*(&c+4));      //ok   high bit high address

//    int b = 3;
//    int a = 0xffffffff;
//    a += 1;
//    char c = 'a';
//    printf("%d, %d, %d\n", &b, &a, &c);
//    printf("%d\n", *(&c+5));        //,int 0xffffffff == -1, so it will never over range...fanma is bug..and althrough it can over range,*(&c+5)is b's 3..a didn't affect b.

//    int a = 5;
//    int b = a += 3;
//    printf("%d, %d\n", a, b);   //8,8

//    printf("%d, %d", INT32_MAX, INT_MAX);        //INT_MAX didn't exist,this is defined in stdint.h..just int..don't know where is float.
//                                                //INT_MAX exists in limits.h

//    short int a = 0xffffU - 30000;
//    short int b = 0xffff - 30000;
//    printf("%d, %d\n", a, b);     //cannot distinguish...

//    char c = 'a';
//    printf("%010hhd", c);

//    double d = 0.3;
//    printf("%#f\n", d);     //# how to use #...

//    double d = 1.85;
//    printf("%2.1f\n", d);       //5 is to the odd
//    int a = d;
//    printf("%d\n", a);            //just cut

//    char s[5] = {'a','b','c','d','e','f'};
//    printf("%d, %zd\n", strlen(s), sizeof s);
//    printf("%5.2s", s);         //print '3blanks'ab

//    float f[3] = {1.1, 1.2, 1.3};
//    printf("%f, %f, %f\n", f[0], f[1], f[2]);       //c primer say float will be double before printf,
//    printf("%d, %d, %d\n", &f[0], &f[1], &f[2]);    //in stack float is flaot, i cannot decide if c primer is right.
//    double d[3] = {2.1, 2.2, 2.3};
//    printf("%d, %d, %d\n", &d[0], &d[1], &d[2]);        //8byte.

//    int a = 0x61616161;
//    char c;
//    printf("%c, %c, %c, %c", *(&a), *(&a+1), *(&a+2), *(&a+3));     //fail. +1 == +4.so...althrough %c can let it just take 1 byte,+1==+4 let other fail

//    int a = 4;
//    int b = printf("%d, %d, %d\n", a, a, a);
//    printf("%d\n", b);

//    printf("short ");
//    printf("long\n");
//    printf("short \
//long\n");
//    printf("short "
//           "long\n");

//    double d;
//    scanf("%le", &d);           //must %lf... or it will print a very big number.
//    printf("%F", d);

//    int a;
//    scanf("%o", &a);
//    printf("%o", a);
//    printf("%d", a);

//    int a = 2;
//    scanf("%d\n", a);       //"2 e" will error, and no print...."e 3" print 2
//    printf("%d", a);

//    int a = 1;
//    int b = 1;
//    int c = scanf("%d, %d", &a, &b);
//    printf("%d, %d, %d", a, b, c);         //if input 2 3,,print 2,1,1

//    int a = 1;
//    scanf("%*d %*d %d\n", &a);
//    printf("%d\n",a);           //input 2 3 4 5 6,,  print 4.  * can skip the input.

//    printf("%d %d %d\n", 1, 3, 5);
//    printf("%d %d %d\n", 111, 222, 333);
//    printf("%d %d %d\n", 34343434, 34223423, 1);

//    char s[5];
//    char ss[4];
//    scanf("%s\n", s);          //delete \n  input just need 1 enter,
//    printf("%s\n%s\n", s);
//    printf("%d, %d", strlen(s), sizeof s);

//    int a = pow(2,2);
//    printf("%d\n", a);

//    printf("%f", pow(2, 0.5));

//    printf("%d", -8/3);

//    int c = 1;
//    int a = c++;
//    int b = ++c;
//    printf("%d, %d", a, b);         //1, 3

//    int a = 1;
//    int b = (a = a+2) + 2;
//    printf("%d, %d\n", a, b);

//    int a = 1;
//    int b = (1+a++) + (1+a++);
//    printf("%d, %d", a, b);     //3, 5

//    int a, b;
//    scanf("%d%d", &a, &b);      //keyi, but cannot use "," to split the input, if use ",", the 2nd variable is uncontrollable.
//                                //but use "%d %d" also cannot use ",".......
//    printf("%d, %d", a, b);

//    int a;
//    const static int b = 3;
//    scanf("%d", &a);
//    switch(a)
//    {
//    case 1:             //anyway, it should be sured when compiled
//        printf("aaa");
//        break;
//    case 2:
//        printf("bbb");
//        break;
//    case 3:             //b cannot compile..const int b also cannot
//        printf("ccc");
//        break;
//    default:
//        printf("default");
//        break;          //if no break, it will also print ddd
//    case qqq:           //#define can...yeah, #define will change the code before compile
//        printf("ddd");
//        break;
//    case 'a':           //input 97, will do this case
//        printf("char");
//        break;
//    }

//    int a;
//    scanf("%d", &a);
//    switch(a)
//    {
//    case 0:
//    case 1:
//    case 2:
//    case 3:
//        printf("in [0, 3]");
//        break;
//    default:
//        printf("not [0, 3]");
//        break;
//    }

//    int a = 1;
//    goto a111;
//    a = 2;
//    a111:               //must be a variable, cannot be a number
//        {a = 4;}
//        a = 11;
//        printf("%d\n", a);        //after goto aaa, it executes by order...but there is a tab.
//    bbb:{}
//        {
//        a = 12;                 //woo, it also do this...
//        printf("%d\n", a);
//        }

//    char c;
//    while((c=getchar()) != EOF)
//    {
//        putchar(c);
//    }

//    for(int i = 0; i < 10; i++)
//    {
//        putchar("*");
//    }
//    putchar("\n");      //output ddddddddddf,don't know why
//            //excepted int but argument is char *

//    void showStar(int);     //comment it, will 2 warning, but it still execute as i want,,don't comment,no warning,
//                                //warning: implicit declaration of function 'showStar' [-Wimplicit-function-declaration]|
//                                //warning: conflicting types for 'showStar'|
//    int a = 2;
//    showStar(a);

//    float fun();          //no this, if change fun()'s return type,it will error.
//    int a = fun();
//    printf("%d", a);


//    int fun();
//    float f = fun();
//    printf("%f", f);


//    printf("%d, %d, %d\n", 3, 5, imax(3));
//    printf("%d, %d, %d\n", 3, 5, imax(3.0, 5.0));     //both can run, but the result is error;
            //first it random?,,second is convert 3.0f to int,then return the number after convert?
            //yes, book say: when first imax is running, it will read 2 number from stack, one is 3,another is random..
            //book: second will push 2 double into stack, and read 2 int.. and 2int == 1double, all 64bits.
            //book: 作为参数传递时，float会被转为double。when a float is transmited as a formal parameter, float will be converted to double

//    show(1.2f);
//    show(1.2f);     //both zero,,,无法理解，float转double再转float。手动转，还是可以输出的啊。
//
//    show2(1.2f);
//    show2(1.2f);    //both 1.2..而且这里强制转换成float，还是可以输出的。
//
//    printf("%f\n", (float)(double)1.2f);    //看来 方法调用，里面有门道？？？但是就是一句跳转吧。。

//    printf("%d", imax2( 4));        //no int imax2(int, int),,imax2(4) can run, has int imax2(int, int),,cannot compile
                                    //whether has or not , imax2(3.2, 4) can run.
//    show3(4);       //void show3(void),,prototype tell compiler formal parameter is void,,,if use void show3();,,compiler thinks you didn't use the prototype,so won't check the formal parameter

//    int a = 5;
//    printf("%d, %p", a, &a);

//    float a = 1.0f;
//    int b = (int)&a;
//    float * p = &a;
//    printf("%p,", p);
//    printf("%d,", b);
//    printf("%d,", *(int*)b);
//    printf("%d,", *(int*)p);        //get int use the bits of float

//    float a = 1.0f;
//    int * p = &a;
//    printf("%d", *p);

//    int a[] = {1,2,3};      //...how to get length.  sizeof
//    printf("%d", sizeof a / sizeof a[0]);

//    int a1[3] = {1, 2, 3};
//    int a2[3] = {1,2};      //a[2] is 0;
//    int a3[3] = {1,2,3,4};      //a[2] is 3, a[3] is random?printf is 1.
//    int a4[3];                  //all random,,, just add ={} ,it will be initialized by 0
//    printf("%d, %d, %d, %d, %d, ", a2[0], a2[2], a4[2], a3[2], a3[3]);

//    static const int a[3];
//    printf("%d", a[2]);           //static will set 0
//
//    static int a1[3];
//    printf("%d", a1[1]);      //0 static

//    int a[] = {[4]=4};
//    printf("%d, %d, %d, ", a[1], a[3], a[4]);
//    printf("\n %d", sizeof a/sizeof a[1]);

//    int a[] = {0,1,[3]=3,6,[3]=44,[6]=2};   //a[3]==44,,a[4]=4
//    for(int i = 0; i < sizeof a/sizeof a[0]; i++)
//    {
//        printf("%d ", a[i]);
//    }

//    int a[] = {1,23};
//    int a1[2];
////    a1 = a;

//    int a[] = {1,2};
//    show4(a);
//    printf("%d", a[1]);

////    const
//    int a[] = {1,3};
//    int a1[] = {11,222};
////    a[1]++;
//    a = a1;

//    const int * pd;
//    int a[] = {1,12,23};
//    pd = a;
//    pd++;
//    printf("%d, ", *pd);
//    *pd++;                    //p++ then *p
//    printf("%d", *pd);

//    const int a[] = {1,3};
//    int * p = a;
//    (*p)++;
//    printf("%d", *p);
////    a[0]++;
//    p[0]++;
//    show5(a);

//    int a[4][2] = {{11,22},{33,44},{55,66},{77,88}};
////    printf("%d, %d, %d", a, *a, **a);       //**a is 11
////    a++;
////    a[0]++;
//    int * p = a;
////    p++;
//    printf("%d, %d, ", **(a+1), *(a[0]+1));
//    printf("%d", **a);

//    int a = 5;
//    int * p;
//    const int * p1;
//    int * const p2 = &a;
//    int * p3;
//    printf("%p, %p, %p, %p \n", p, p1, p2, p3);
//    p = p1;
//    (*p2)++;            //p2++ is error,,p2 is a const point..so u cannot change point's address
//    p1 = p;
//    p1++;           //(*p1)++ is error  p1 point to a const int.,so u cannot change the value of int
//    printf("%p, %p, %p, %p \n", p, p1, p2, p3);

//    int const * p;
//    p++;
////    (*p)++;           //error

//    int const * p;
//    int a = 4;
//    p = &a;
//    printf("%d \n", *p);
//    p++;
//    p--;
//    a = 6;
//    printf("%d \n", *p);

//    int a[][3] = {{11,221,34},{1,3,4}};
//    int a1[3][] = {{11,221,34},{1,3,4}};          //error
//    int a2[2][2];

//    int a[][2][2] = {{{1,2},{11,22} }};         //first [] can be empty, others cannot

//    int r = 2;
//    int c = 3;
//    int a[r][c] = {{1,2},{11,22},{5,6}};        //variable-sized object may not be initialized|

//    int a[2][2];
//    a[0][0] = 123;
//    val(2, 2, a);

//    char a[] = "abcdefghj";
//    printf("%s\n", a);
//    a[4] = '\0';                    //\0 is the end of string
//    for(int i = 0; i < 5; i++)
//    {
//        printf("%c", a[i]);
//    }
//    printf("\n%s", a);

//    char a[10] = "aa";
//    char a1[] = "bb";
//    char *a2 = "cc";
//
//    printf("%s, %s, %s", a, a1, a2);            //use pointer。

//    int a;
//    char *ap[5] = {"aaaa", "bbbbbbbbbbb", "ccccccc", "d", "eee"};
//    for(int i = 0; i < 5; i++)
//    {
//        a = puts(ap[i]);            //puts is printf...puts return what? all 0...
//        printf("%d\n", a);
//    }
//    ap[2] = gets(ap[2]);              //error, why?
//    printf("%s\n", ap[2]);

//    char aa[10];                  //right
//    gets(aa);
//    printf("%s\n", aa);

//    char a[50] = "asd""bvcx"  "qwe"             //...auto connect to one string
//      "hjk";
//    printf("%s", a);

//    printf("%s, %p, %c", "Wdd", "R" , *"space");        //p产生一个地址，所以如果"R"是一个地址，那么%p输出字符串中第一个字符的地址，，*"spacr"获得对应地址中的值，即第一个字符。
//                                                    //虽然有解释，但是还是不太明白
//    printf("%p", "R");          //和上的R是一个地址的。就是说"WD"这种实际上是一个地址？。可能，不过要看汇编了啊。c好像没有办法验证这个。怎么获得c的汇编？
                        //md，书上的例子写了，把字符串看做指针。。。

//    char a[2] = {'a','b','c'};      //这个\0在哪里？。这个都已经把c舍弃掉了。
//    printf("%s", a);

//    const char * p = "A";
//    char a[] = "A";
//    printf("%s, %s", p, a);
//    printf("\n%p, %p, %p", p, a, "A");

//    int a = 4;
//    printf("%x, %p", &a, &a);             //x 16进制。

//    int a = 1;
//    printf("%d, %d, %d, %d, %d, %d\n", a, a++, ++a, a++, ++a, a);       //5 4 5 2 5 5
//    a = 1;
//    printf("%d, %d, %d, %d, %d, %d\n", a, a++, a++, a++, a++, a);         //5 4 3 2 1 5
//    a = 1;
//    printf("%d, %d, %d, %d, %d, %d\n", a, ++a, ++a, ++a, ++a, a);     //5 5 5 5 5 5
//    a=1;
//    printf("%d %d %d %d %d %d\n",a++, ++a, a++, ++a, a++, ++a );        //6 7 4 7 2 7
    /*参见某高手解释吧：
      对于a++的结果，是有ebp寻址函数栈空间来记录中间结果的，在最后给printf压栈的时候，再从栈中把中间结果取出来；
      而对于++a的结果，则直接压寄存器变量，寄存器经过了所有的自增操作。 （来源：http://www.zzzj.com/html/20090609/71613.html）*/
    //就是说++a，压的是寄存器的地址，所以最后输出的时候是全部的，，a++压的是中间结果的栈的地址，所以是递增的。

//    a = 1;
//    printf("%d %d %d\n", a++, a++, a++, a++, a++);        //5 4 3, 说明是从右往左全部压入栈，然后取3个，而且这3个是543，不是123，说明是栈，不是队列。
//    a = 1;
//    printf("%d %d %d", ++a, ++a, ++a, ++a, ++a);        //6 6 6,,,刚才没发现，上面是压栈以后++的。所以最大是5,嗯，上面输出a，就是6

//    char *p = "qwer";
//    char a[] = "qwer";
//    printf("%c", p[3]);
//    printf("%c", a[3]);
//    printf("\n");
//    printf("%c", *(p+2));
//    printf("%c", *(a+2));
//    printf("\n");
//
//    while(*p != '\0')
//    {
//        printf("%c", *p);
//        p++;
//    }

//    char *p = "asdf";
//    p[2] = 'e';         //runtime error

//    const char *p = "zxcv";
//    p[2] = 'A';           //cannot compile

//    char * p;
//    printf("%p\n", p);      //
//    scanf("%s", p);
//    printf("%p\n", p);
//    printf("%c\n", *p);

//    char p[20];
//    scanf("%s", p);
//    printf("%s", p);

//    char * p;
//    gets(p);
//    puts(p);

//    char *p1;
//    char *p2;
//    p1 = gets(p2);
//    printf("%s\n%s\n", p1, p2);
//    printf("%p, %p\n", p1, p2);     //same address

//    char *p;
//    p = 0;
//    printf("%d\n", (p==NULL));          //address is 0 == NULL
//    p = 1;
//    printf("%d", (p==NULL));

//    char *p1;
//    char *p2;
//    p1 = fgets(p2, 30, stdin);
//    printf("%s%s", p1, p2);             //保存了换行符，所以自动换行了

//    char *p1;
//    char *p2;
//    scanf("%5s", p1);        //read 5, others will be discarded
//    scanf("%s", p2);
//    printf("%s", p1);
//    printf("\n\n%s", p2);

//    char *p;
//    int a = scanf("%s %d", p, &a);
//    printf("%d, %s", a, p);

//    char *p1, *p2;
//    printf("%p, %p\n", p1, p2);
//    scanf("%4s %4s", p1, p2);
//    printf("%s, %s", p1, p2);       //...p2 print nothing...
////    scanf("%s", p2);
////    printf("%s", p2);           //,,,random...
//    printf("%p, %p", p1, p2);

//    char *p = "abcdefg";
//    int a = puts(p);
//    printf("%d", a);

//    char a[] = {'A', 'B', 'c'};
//    printf("%s\n", a);
//    puts(a);

//    char a[10];
////    while(*gets(a) != 'a')      //"a" is wrong,and input can longer then 10.
////        puts(a);
////    while(*fgets(a, 15, stdin) != 'q')        //can longer then 10..
////        fputs(a, stdout);
//    gets(a);
////    printf("%c", a[11]);        //right..
//    int a1 = puts(a);
//    int b = fputs(a, stdout);
//    printf("\n%d, %d", a1, b);          //0,0..maybe 0 mean successful? or last char(\0)?...EOF is -1..so it is last char?

//    char a[3] = {'a','b','c','d'};
//    putchar(a[6]);
//    printf("%s", a);
//    a[3] = getchar();
//    a[4] = getchar();
//    a[5] = getchar();           //it will auto add \0?
//    putchar(a[3]);
//    printf("\n\n%s", a);

//    char a[3];
//    gets(a);
//    printf("%d", strlen(a));        // not calculate \0,,if input 'a', output 1..tab is 1.

//    char *p1;
//    char *p2;
//    char *p3;
//    gets(p1);
//    gets(p2);
//    printf("%p, %p\n%s, %s\n", p1, p3, p1, p2);     //p1 p2 p3 are far away from each other...
//    strcat(p1, p2);                     //runtime error ,,
//    printf("%p, %p\n%s, %s\n", p1, p2, p1, p2);

//    char *p1;
//    char *p2;
//    char a[10];
//    p1 = a;
//    p2 = &a[5];
//    printf("%p, %p\n", p1, p2);     //p2's address is bigger then p1's
//    gets(p1);
//    gets(p2);
//    printf("\n%p, %p\n%s, %s", p1, p2, p1, p2);     //p1's length connot bigger then 10. y? above code can..because stack and heap?

//    char a[10];             //initialize or not ,both can over 10.
//    printf("%s\n%p\n", a, a);       //if initialize a by string over 10, there print 10 chars.
//    char *p = a;
//    gets(p);            //both a and p can over 10...
//    printf("\n%s", a);      //can over 10...
//    printf("\n%p", a);

//    char *p1 = "ZXC";       //if p1 p2 not initialize , it can work correctly.
//    char *p2 = "ASD";
//    printf("%p, %p\n",p2, p1);
//    gets(p2);
//    gets(p1);       //error. runtime.
//    strcat(p2, p1);         //runtime error ,y ? no enough space?

//    char *p1;
//    char *p2;
//    gets(p1);
//    gets(p2);
//    strncat(p1, p2, 5);
//    printf("%s", p1);       //..p1+messy code...

//    char a1[10];
//    char a2[10];
//    gets(a1);
//    gets(a2);
//    strncat(a1, a2, 3);
//    printf("%s, %s", a1, a2);       //correct.

//    char *p1;
//    char *p2;
////    gets(p1);
////    gets(p2);
////    p2 = p1;
////    printf("%d", strcmp(p1, p2));       //input same, not equal..
//    printf("%d\n", strcmp("asd", "asd")); //this is 0, is equal
//    char a1[10];
//    char a2[10];
//    gets(a1);
//    gets(a2);
//    printf("%d\n", strcmp(a1, a2));     //wawawawa,,input same. equal...mybe String havn't ascii,so string can not compare.or compare by address...
                        //and string is keeped in heap, C cannot get char to compare?

//    char a1[10];
//    char a2[10];
//    char *p1;
//    char *p2;
//    char *p3;
//
//    gets(p1);
//    p3 = strcpy(p2, p1);        //p2 is front
//    printf("%s, %s, %s\n", p1, p2, p3);       //all same
//    printf("%p, %p, %p", p1, p2, p3);       //p3 == p2, p3 != p1

//    a1 = {'z','x','c'};
//    a2 = {'q','w','e'};

//    char a1[10] = "asd";
//    char a2[10] = "zxc";
//    char *p3;
//    int a = sprintf(p3, "%s - %s", a1, a2);     //a==9,== length of "%s - %s" without \0
//    printf("%d, %s", a, p3);

//    char *p1 = "asd";
//    char *p2 = "qwe";
//    char *p3;
//    sprintf(p3, "%s-%s", p1, p2);           //runtime error....

////    char *p = "zxcsdfASD";
//    char p[] = "asdasdED";          // *p is error ,for *p points to leap, data in leap cannot be changed... i think this is the reason..
//    toStringUpper(p);
//    printf("%s", p);

//    char *p = "~!@#$%^&*()_+-=,.;':[]{}\|";        // \\==\...\|==|?..it seem \|==\..
//    printf("%d", countPunctuation(p));

//    auto int a = 5;
//    printf("%d", a);

//    {
//        int a = 1;
//        {
//            int a = a+1;        //random
//            printf("%d", a);
//        }
//    }

//    for(int i = 0; i <10; i++)
//    {
//        printf("%d, ", i);
//        int i = 3;
//        i++;
//    }

//    register int a;
//    printf("%p", &a);     //error

//    {
//        int a = 5;
//        {
//            extern int a;       //文件作用域的a，不是上面那个a。
//            printf("%d", a);
//        }
//    }

//    srand(time(0));
//    printf("%d", rand());       //

//    int const a[2];
//    a[1] = 5;         //read only

//    int const * p;
//    *p = 1;     //read only
//    p++;        //can

//    FILE * fp = fopen("F:/asdf.properties", "r");
//    if(fp == NULL)
//    {
//        printf("null file porint");
//        return -1;
//    }
//    char ch = getc(fp);
//    printf("%c\n", ch);
//    putc(ch, stdout);
//    putchar(ch);
////    char *p = &ch;
////    puts(p);
//    char ch;
//    do
//    {
//        ch = ch
//    }

//    char ch = getc(fp);
//    while(ch != EOF)
//    {
//        putchar(ch);
//        putc(ch, stdout);
//        ch = getc(fp);
//    }

//    char ch;
//    while((ch = getc(fp)) != EOF)
//    {
//        putchar(ch);
//    }

//    FILE * fp = fopen("f:/asdf.properties", "r");
//    if(fp == NULL)
//    {
//        printf("null");
//        return -1;
//    }
//    printf("%p", fp);
//    char ch;
//    int i;
//    char * p;
//    char a[100];
//    while (fscanf(fp, "%s", a) == 1)
//    {
//        fprintf(stdout, "%s\n", a);             //a, not *a.
//        printf("%s\n", a);
//    }

//    FILE * fp;
//    if((fp = fopen("f:/asdf.properties", "r")) == NULL)
//    {
//        printf("null");
//        return -1;
//    }
//    char *p;
//    char a[50];
//    while((fgets(a, 40, fp)) != NULL)       //while((a = fgets(a, 40, fp)) != NULL)..error
//    {
//        fputs(a, stdout);
//    }
//    printf("\n\n");
//
    //reverse print
//    rewind(fp);           //useless
//    FILE * fp;
//    if((fp = fopen("f:/a", "rb") == NULL))          //这里括号错了。==的优先级高于=
//    {
//        printf("null 2");
//        return -2;
//    }
//    int s = fseek(fp, 0L, SEEK_END);
//    perror("aaa");                         //niubi.
//    printf("%s\n",strerror(errno));     //niubi     char *strerror(int errnum)
//    printf("%d", s);                   //-1
//    long last = ftell(fp);
//    printf("%ld\n", last);         //ld or d..for long and int are 32bits....why last is -1?
//    char ch;
//    for(long i = 1L; i <= last; i++)
//    {
//        fseek(fp, -i, SEEK_END);
//        ch = getc(fp);
//        if(ch != 'r')
//            putchar(ch);
//    }
//    fclose(fp);


























    return 0;
}

//计算标点符号的个数
int countPunctuation(char *str)
{
    int ct = 0;
    while(*str)
    {
        if(ispunct(*str))
        {
            ct++;
            printf("%c", *str);
        }
        else
        {
            printf("\n1");
        }

        str++;
    }
    return ct;
}

void toStringUpper(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}


void val(int n, int m, int a[m][n])
{
    printf("%d, ", a[0][0]);
}

void show5(int* p)
{
    (*p)++;
    printf("%d", *p);
}

void show4(const int a[])
{
//    a[1]++;         //compile error
    int a1[] = {11,22};
    a = a1;
    printf("%d,,,", a[1]);
}

void show3()
{
    printf("%d", 5);
}

int imax2(int a, int b)
{
    return 3;
}

void show2(double dou)
{
    printf("%f\n", (float)dou);
}

void show(float f)
{
    printf("%f\n", f);
}


int imax(n, m)
int n, m;       //cooooooooool...alreay forgot it, even i don't know if i have learned it...
{
    int max;
    if(n>m)
        max = n;
    else
        max = m;
    return max;
}


float fun()
{
    return 1.8f;
}


void showStar(int a)
{
    for(int i = 0; i < a; i++)
    {
        printf("*");
    }
}






