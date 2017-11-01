// 第14章开始

#include <stdio.h>
#include <string.h>
#include <stdarg.h>


#define NDEBUG          //放在#include <assert.h>之前，不会运行assert
#include <assert.h>

#define MAXTITLE 41
#define MAXAUTL 31

#pragma c9x on

struct book
{
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};                  //;;;;;;;;;;;;;;号

struct library
{
    char name[31];
    struct book book1;
};

struct pointer
{
    char * p1;
    char * p2;
};

struct flex
{
    int count;
    double ave;
    double scores[];        //伸缩型数组
};

void show1(struct library a)
{
    printf("%s, %s, %s, %.2f\n", a.name, a.book1.title, a.book1.author, a.book1.value);
}

void show2(struct library * p)
{
    printf("%s, %s, %s, %.2f\n", p->name, p->book1.title, p->book1.author, p->book1.value);
}

union hold
{
    int digit;
    double bigfl;
    char letter;
};

enum spectrum {red, orange, yellow, green, blue, violet};

typedef struct
{
    int a;
    int b;
} SELF;

char toUp(char ch)
{
    return toupper(ch);
}

typedef struct
{
    unsigned int a: 1;
    int b: 1;
    int c: 1;
    int d: 1;
    int e: 1;
} BIT;

typedef struct
{
    int a: 8;
    int b: 8;
    int c: 8;
    int e: 8;
    int f: 8;
} BIT2;

typedef struct
{
    int a: 1;
    int  : 2;
    int b: 1;
    int  : 0;
    int c: 1;
} BIT3;

#define PT(X) printf("the square of "#X" is %d\n", ((X)*(X)));
//不是 printf("the square of #X is %d\n", ((X)*(X)));

#define PR(...) printf(__VA_ARGS__)

#define PA(n) x ## n

#define MMM 3

//#if __STDC_VERSION__ != 199901L
//    #error is C99         //没用
//#endif


void close()
{
    printf("end...");
}

int sum(int, ...);



int main(void)
{












//    printf("%d\n", sum(5, 5, 4, 6, 5, 5));        //可变长参数。

//    struct book2 b2 = {"asd", "zxc", 10};          //storage size of 'b2' isn't known;    只有声明没有{}
                                    //struct book2;   这种声明没用。。
//                                //has initilizer bug incomplete type   加上{}

//    int a1[] = {11,22,33,1,2,3};
//    int a2[5] = {9,9,9,9,9};
//    memmove(a2, a1, 10);            //是字节数，不是元素个数。。10个字节就ok的话，说明低字节放在低位，是小端模式。
//                                    //用 4*sizeof(int)
//    for(int i = 0; i < 5; i++)
//    {
//        printf("%d, ", a2[i]);
//    }



//    int a = 1;
//    scanf("%d", &a);
//    assert(a);

//    exit(close);              //没有。。。
//    atexit(close);
//    exit(-1);



//    #if __STDC_VERSION__ != 199901L
//        printf("111");
//        #error is C99               //没用。。
//    #endif

//    printf("%s\n", __DATE__);           //Sep 22 2017
//    printf("%s, %ld\n", __FILE__, __LINE__);
//    printf("%d, %d, %ld, %s\n", __STDC__, __STDC_HOSTED__, __STDC_VERSION__, __TIME__);
//    printf("%s\n", __func__);

//    for(int i = 0; i < 5; i++)
//    {
//        #if i==MMM              //?为什么进不去？。。好像这东西不是用来执行的，是用来#include的？
//        printf("aaaaa");
//        #endif // MMM
//    }


//    for(int i = 0; i < 4; i++)
//    {
//        #ifdef MMM
//        printf("a");
//        #endif // MMM
//
//        #ifdef AAA
//        #else
//        printf("bbb");
//        #endif // AAA
//    }

//    for(int i = 0; i < 4; i++)
//    {
//        #ifndef AAA
//        printf("asd");
//        #endif // AAA
//        printf("_");
//    }

//    for(int i = 1; i < 4; i++)
//    {
//        #ifdef MMM
//        printf("asd");
//        #endif // MMM
//    }


//    int PA(1) = 4;                // int x1 = 4;
//    printf("%d\n", x1);

//    int a = 5;
//    float f = 1.2345;
//    PR("ABCD\n");
//    PR("a = %d, f = %5.2f\n", a, f);          //66666

//    PT(5)       //#define中有;了

//    const int a = 4;
//    const int b = 2 * a;            //可以，和书上不一样。460/449_
////    static int arr[a];            //不行
//    printf("%d, %d\n", a, b);

//    int/*听说会变成一个空格*/a = 5;        //可以运行的
//    printf("%d\n", a);

//    printf("%d\n", sizeof(BIT3));       //8，因为那个int  : 0; 使下一个属性和int对齐。

//    BIT2 b;
//    b.a = -257;
//    printf("%d\n", b.a);        //-1
//    printf("%d\n", sizeof(BIT2));           //8,是int的长度的整数倍。

//    printf("%d\n", sizeof(BIT));        //有5个属性，依然是4.

//    BIT b;
////    int i;
//    b.a = 3;
//    b.b = -3;
//    printf("%d, %d\n", b.a, b.b);       //1,-1,,如果+-2的话是0
//    printf("%d, %d, %d\n", sizeof(b), sizeof(BIT), sizeof(int));        //4,4,4  sizeof(b.a) 会报错，说sizeof用于bit字段不可以的

//    unsigned int a = 2500000000;
//    printf("%d", a>>1);           //unsigned用0填充

//    int a = -3;
//    printf("%d\n", a>>1);       //用符号位填充的。


//    int a = 2100000000;
//    for(int i = 1; i < 10; i++)
//    {
//        printf("%d\n", a);            //可以变负数，还可以变正数。
//        a <<= 1;
//    }

//    int a = -1;     //1 1111
//    int b = -3;     //1 1101   &之后 反码为 1 1101，是-3的反码
//    int c = a & b;
//    printf("%d\n", c);

//    int a = 0;
//    int b = ~a;
//    printf("%d, %d\n", a, b);

//    char (*pf)(char) = toUp;
//    char c = 'a';
//    pf(c);
//    printf("%c\n", pf(c));

//    SELF a;
//    a.a = 4;
//    a.b = 1;
//    printf("%d, %d\n", a.a, a.b);


//    enum spectrum color;
//    color = blue;
//    color = 3;
//    color++;
//    printf("%d\n", color);
////    printf("%s\n", color);      //error

//    union hold a;
//    union hold b;
//    union hold * p = &a;
//    p->letter = 'e';
//    union hold * p2 = &b;
//    printf("%p\n", p2);
//    p2->bigfl = 1.2;
//    printf("%p\n", p2);
//    printf("%p\n", &p->letter);
//    p->digit = 100;           //加上这两行就可以了
//    printf("%p\n", &p->letter);
//    p->letter = 'e';
//    printf("%p\n", &p->letter);
//    printf("%p\n", p2);
//    printf("%c, %d, %f", p->letter, p->digit, p->bigfl);            //和下面的不一样，这里输出e, 4200805, 0.00


//    union hold a;
//    a.letter = 'a';
//    union hold b = a;       //联合初始化联合
//    union hold c = {11};        //初始化第一个
//    union hold d = {.bigfl = 11.11};    //c99指定初始化项目
//    union hold e = {'e'};
//    printf("%c, %d, %f\n", e.letter, e.digit, e.bigfl);     //...e, 101, 0.00..保存了'e'，然后用int读就是101。就是不知道是保存e还是保存101

//    struct book b1 = {
//        "ninsen",
//        "world",
//        1.3
//    };
//    FILE * fp;

    /*
    "r" 读取
    "w" 清空，写入
    "a" 追加写入
    b   二进制
    */
//    if((fp=fopen("F:/a", "w+b")) == 0)        //前面要有个()，fopen返回的是指针，失败是空指针是个0....a++++++
//    {
//        printf("error");
//        return -1;
//    }
//    fwrite(&b1, sizeof(struct book), 1, fp);
//    struct book * b2;
//    rewind(fp);             //...
//    fread(b2, sizeof(struct book), 1, fp);
//    printf("%s, %s, %.2f", b2->title, b2->author, b2->value);       //吊！
//    close(fp);

//    struct book b1 = {
//        "shiwange",
//        "shijie",
//        100
//    };
//    FILE * fp = fopen("f:/a", "a");
//    fprintf(fp, "名字：%s, 作者：%s, 价值：%.2f\n", b1.title, b1.author, b1.value);
//    close(fp);


//    struct flex f = {
//        3,
//        1.3,
//        {1.1, 1.3, 1.5}             //compile error
//    };

//    struct flex * p;
//    p = malloc(sizeof(struct flex) + 3*sizeof(double));
//    p->scores[0] = 1.3;
//    p->scores[1] = 1.4;
//    p->scores[2] = 1.6;
//    double sum = p->scores[0] + p->scores[1] + p->scores[2];
//    p->count = 3;
//    p->ave = sum/3;
//    printf("%d, %.3f, %.3f, %.3f, %.3f", p->count, p->ave, p->scores[0], p->scores[1], p->scores[2]);

//    struct book b1;
//    b1 = (struct book){"title", "name", 123.5};
//    printf("%s, %s, %f", b1.title, b1.author, b1.value);


//    char temp[33];
//    gets(temp);
//    struct pointer * p1;
//    p1->p1 = (char *)malloc(strlen(temp) + 1);
//    strcpy(p1->p1, temp);
//    gets(temp);
//    p1->p2 = (char *)malloc(strlen(temp) + 1);
//    strcpy(p1->p2, temp);
//    printf("%s, %s\n", p1->p1, p1->p2);


//    char * p;
//    scanf("%s", p);
//    printf("%s\n", *p);


//    struct library library = {
//        "chuandi",
//        {
//            "xingxingzhihuo", "wuminshi", 10
//        }
//    };
////    show1(library);
////    show2(&library);
//    struct library library2 = library;
//    show1(library2);
//    printf("%p, %p\n", &library, &library2);        //different

//    struct library library[2] = {
//        {
//            "coooooool",
//            {
//                "barongbachi", "hujingtao", 100
//            }
//        },
//        {
//            "zhongyang",
//            {
//                "zhongyaojianghua", "xijinping", 100
//            }
//        }
//    };
//
//    struct library * p;
//    p = &library[0];
//    printf("%s, %s, %s, %f\n", p->name, p->book1.title, p->book1.author, p->book1.value);
//    p++;
//    printf("%s, %s, %s, %f\n", p->name, p->book1.title, p->book1.author, p->book1.value);



//    struct library library = {
//        "niubitushuguan",
//        {"sangedaibiao", "jiangzheming", 100.0}
//    };
//
//    printf("%s, %s, %s, %2f", library.name, library.book1.title, library.book1.author, library.book1.value);
//    struct library * p;
//    p = &library;
//    printf("\n");
//    printf("%s, %s, %s, %2f\n", p->name, p->book1.title, p->book1.author, p->book1.value);





//    struct book book1;
//    gets(book1.title);
//    gets(book1.author);
//    scanf("%f", &book1.value);

//    float f = 100.00f;
//    struct book book1 = {           //这里必须声明时初始化。。
//        "maozhedongsixiang",
//        "maozhedong",
//        f
//    };                      //;;;;;;;;;;;;;

//    struct book book1 = {
////        .title = "dengxiapinglulun",
//        .author = "dengxiaping"
//    };
//
//    printf("%s, %s, %.2f", book1.title, book1.author, book1.value);






























    return 0;
}


int sum(int parmN, ...)
{
    va_list va;
    int total = 0;

    va_start(va, parmN);

    for(int i = 0; i < parmN; i++)
    {
        total += va_arg(va, int);
    }
    va_end(va);
    return total;
}


struct book2           //必须写前面，或者还不知道怎么声明。。
{
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};
