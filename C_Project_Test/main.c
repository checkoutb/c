#include <stdio.h>
#include <stdlib.h>
//#include <typeinfo.h>

//extern externalFun(int);        //这行不加也可以的。。。

void show2()
{
//    printf("show2 %d\n", aa);           //cannot get aa
}


typedef struct ForKing
{
    char name[10];
    int age;
} K;

struct J
{
    char name[10];
    int age;
};

union un
{
    int int_val;
    double dou_val;
};

struct KA
{
    char name[20];
    union
    {
        double douv;
        int intv;
    };
};

enum spectrum
{
    red,        //0
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
    ultraviolet
};

enum
{
    red1,
    orange1
};

enum wh {zero, null=0, one, err=1};

void show3()
{
    printf("qqq\n");
}

//int show3(int a)          //int void ,both conflict for show3.
//{
//    printf("%d\n", a);
//    return 3;
//}

int fun_aa()
{
    return 1.8;
}

void fun_length(int a[])
{
    printf("%d\n", sizeof(a));
}

void fun_fun(int a)
{
    printf("%d\n", a);
}

//void fun_default(int a, int b = 3)            //error
//{
//    ;
//}

int main()
{






//    int a;
//    static int b;
//    printf("%p, %d\n", &a, a);      //0028ff3c, 2131322
//    printf("%p, %d\n", &b, b);      //0040e020, 0

//    void * p;
//    int a = 3;
//    p = &a;
//    printf("%d\n", *(int *)p);      //必须 强制转换


//    const int * p;        //ok
//    int * const p2;     //error,uninitialized const p2..cpp is error ,,but c is right
//    int const * p3;
//    int a = 3;
//    p3 = &a;    //right..it means const int * == int const *   , != int * const
////    (*p3)++;        //error  readonly
////    p2 = &a;            //error,c error ,,,,

//    int a = 1;
//    int &aa = a;      //c没有引用

//    int i = 1;
//    printf("%d, %d, %d, %d, %d\n", i++, i++, i++, i++, i++);        //5,4,3,2,1...从右往左获得，java是1,2,3,4,5，从左往右获得。

//    void (*pf)(int);
//    pf = fun_fun;
//    (*pf)(3);
//    pf(3);            //c also can

//    int a = 1;                //keyi  但是cpp不能main递归自己，不知道cpp能不能间接递归main
//                                //被坑了，书上说cpp不可以，但是gcc可以的。
//                              //大约运行5-6s 以后，cmd停止工作。
//    printf("%d, ", 1);
//    main();

//    int a[3] = {1,2,3,};

//    int aa[] = {1,2,3};
//    printf("%d\n", sizeof(aa));
//    fun_length(aa);     //4

//    fun_show2(133.2f);        //error.没有原型，会取float的32位转换成int。所以一个大数。

//    fun_show();     //不需要原型。

//    int a = 111111111;
//    printf("%f\n", a);          //0000000

//    printf("%d\n", fun_aa());     //1

//    int a = 3;
//    if(a++ == 2 || a++ == 4)        //如果第一个是a++ == 3，那么输出4，，现在是输出5，，||是一个顺序点
//    {
//        printf("%d\n", a);
//    }

//    int a;
//    printf("%s\n", typeid(a));

//    show3();
//    show3(3);


//    char flower[10] = "rose";
//    printf("%ss are red\n", flower);

//    int a[] = {1,2,3};
//    int *p = a;
//    printf("%d, %d\n", sizeof(a), sizeof(p));   //12,4

//    int a[] = {1,2,3};
//    printf("%d, %d, %d\n", a[2], a[1], a[11]);

//    int *p;
//    int a[] = {1,2,3};
//    p = a;
//    printf("%d, %d, %d, %d\n", p[0], p[1], p[2], p[5]);

//    int *p;
//    p = 0x28ff28;           //valid
//    printf("%p, %d", p, *p);


//    enum wh s = (enum wh)2200000000L;         //over limit
//    printf("%ld\n", s);

//    enum wh s;
//    s = 1;            //valid, 枚举和int是两套系统，没办法通过数值来获得枚举常量，所以不会有冲突的。


//    int a = orange1;
//    printf("%d\n", a);

//    enum spectrum band = blue;
//    printf("%d\n", band);
//    band++;                     //valid
//    printf("%d\n", band);
//    band = orange + green;      //valid
//    printf("%d\n", band);

//    enum spectrum band;
//    band = red;
//    printf("%d\n", band);
//    band = (enum spectrum) 3;
//    printf("%d\n", band);
//    band = 5;               //valid
//    printf("%d\n", band);

//    struct KA k = {"rfv", 5332};              //匿名共用体，共用体的第一行作为默认接收输入的变量
//    printf("%s, %d\n", k.name, k.intv);

//    union un a;
//    a.dou_val = 1.2;
//    printf("%d\n", a.int_val);            //cool?
//    a.int_val = 4;
//    printf("%f\n", a.dou_val);

//    K k = {"S", 33};
//    k = {"K", 11};        //not supported

//    K k = {.age=21};                      //disorder
//    printf("%s, %d\n", k.name, k.age);

//    struct J kin = {"Kin S", 24};
//    struct J S = kin;                       //same value, different address
//    printf("%s, %d\n", kin.name, kin.age);
//    printf("%s, %d\n", S.name, S.age);
//    printf("%p, %p\n", &kin, &S);

//    char a[10];
//    scanf("%s", a);               //输入空格分隔的字符串，第二个scanf不会从键盘读入
//    printf("1.%s\n", a);
//    scanf("%s", a);
//    printf("2.%s\n", a);

//    char s1[10];
//    printf("%p, %p, %p\n", s1, &s1[0], &s1[9]);       //也是char了，一个char一个字节。 0的地址小

//    char a[] = "this is ""one line";
//    char a1[] = "this is "      "one line too";
//    char a2[] = "this is "
//    "one line too"
//    " too";
//    printf("%s \n%s \n%s \n", a, a1, a2);

//    char a[] = "asdf";
//    printf("%d\n", sizeof(a)/sizeof(char));         //5

//    #define aa 4
//    int a[aa];

//    const int a = 4;
//    int aa[a];

//    short s = 55555;
//    short s1 = 54321;
//    int a = s + s1;
//    short a1 = s + s1;
//    printf("%d, %d\n", a, a1);

//    double d = 3e33;
//    int a = d;
//    printf("%d\n", a);

//    float f = 5.1;
//    int a = f;
//    printf("%d, %f\n", a, f);

//    float f = 7.777777777777777777e10;
//    printf("%f\n", f);          //77777780736.000000

//    float f = 3.1e-1;         //keyi
//    printf("%f\n", f);

//    show();
//    #define aa 3
//    printf("%d\n", aa);


//    printf("Hello world!\n");

//    externalFun(4);
//
//    int a = 4;
//    printf("%d, %d, %d\n", sizeof(a), sizeof(int), sizeof a);

    return 0;
}

void fun_show()
{
    printf("qwe");
}
void fun_show2(int a)
{
    printf("%d\n", a);
}
void show()
{
//    printf("show %d\n", aa);
}
