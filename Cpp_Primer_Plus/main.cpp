#include <iostream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <string>
#include <ctime>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <new>

#include "share.h"              //使用同一个工程(文件夹下?)的其他.cpp文件的方法

#ifndef DFCS
#define DFCS
#define DDD 3
#endif

using namespace std;    //导入空间内所有的方法名
//using std::cout;      //可以单独导入一个方法名
//using std::endl;

//void SizeOfType();
void sizeOfTypeInCpp();         //使用同一个工程(文件夹下?)的其他.cpp文件的方法。

struct person
{
    char name[20];
    int age;
};

struct inflatable
{
    string name;
    float volume;
    double price;
};

typedef struct
{
    string name;
    int age;
} Info;

union un
{
    int intv;
    double douv;
};

struct St
{
    string name;
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
    green,      //3
    blue,
    violet,
    indigo,     //6
    ultraviolet,
};

enum KKK{zero, null=0, one, err=1};

void aaa(int a)
{
    cout<<"int"<<endl;
}

void aaa(float a)
{
    cout<<"float"<<endl;
}

int fun_aa(void)
{
    return 1.8;
}

void fun_show(...);

void fun_show()
{
    cout<<"zero"<<endl;
}

void fun_show(int a)
{
    cout<<"one "<<a<<endl;
}

void fun_length(int a[])
{
    cout<<sizeof(a)<<endl;      //warning，return size of "int *"
}

/**只能接受int a[]*/
void fun_p_aa(int a[], int n)
{
    cout<<"aa"<<endl;
    for(int i = 0; i < n; i++)
    {
        a[i] += 1;
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

/**可以接受const int a[], int a[]*/
void fun_p_aaa(const int a[], int n)
{
    cout<<"aaa"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

/**能接受const int a[2][2], int a[2][2]*/
void fun_p_ppp(const int a[][2], int n)
{
    cout<<"ppp"<<endl;
    int j = 2*n;
    for(int i = 0; i < j; i++)
    {
        cout<<*(*a+i)<<", ";        // *(*a+i) !!!
    }
    cout<<endl;
}

/**只能int aaa[2][2]*/
void fun_p_pp(int a[][2], int n)
{
    cout<<"pp"<<endl;
    int j = 2*n;
    for(int i = 0; i < j; i++)
    {
        cout<<*(*a+i)<<", ";        // *(*a+i) !!!
    }
    cout<<endl;
}

/**返回int个char组成的字符串*/
char *buildStr(char, int);

/**这个方法是错的，不知道为什么，返回a的话，没有任何输出，但是正常结束，返回p的话，有输出，但是最后的那个\0没有，导致输出超过想要的*/
//可能是因为char数组的生命周期被回收了吧，。。不清楚
/*网上的，a是局部数组，系统为其分配的是栈内存，test（）函数一结束，a的生命结束，其所占内存被释放，p也被释放，返回回来的是被释放的内存，输出必然不正确。*/
/*因为p虽然为局部指针，函数结束，p被释放，但是p指向的并不是栈内存，而是常量存储区，即使函数结束，这段内存存储的仍旧是"abc"，所以返回回来的地址是有效的，结果自然是正确的。*/
//看来new的是堆区。对，对象保存在堆区，栈保存一个指向对象的指针，java中好像可能是这样的。
char *buildStr2(char c, int n)
{
    char a[n+1] = {'a'};
    a[n] = '\0';
    cout<<" "<<a<<endl;
    while(n-- > 0)
    {
        a[n] = c;
    }
    cout<<" "<<a<<endl;
    char *p = a;
    return p;
}

//两样的，return a,cmd停止任务，，return p,可以正确。可能是太短了吧，buildStr短一点用p可以，长了就完蛋
char *fun_1(char c)
{
    char a[2];
    a[1] = '\0';
    a[0] = c;
    cout<<a<<endl;
//    char *p = a;
//    return p;
    return a;
}

struct travel_time
{
    int hours;
    int mins;
};

void fun_fun1(int a)
{
    cout<<a<<endl;
}

int fun_fun2()
{
    return 2;
}

int *fun_fun3()
{
    int a = 2;
    int *p = &a;
    cout<<*p<<endl;
    return p;
}

inline int fun_twice(int a)
{
    return a*2;
}

int fun_ref(int &a)
{
    return a*2;
}

//float fun_ref(int &a)     //error ,ambiguating new declaration of 'float fun_ref(int &)'
//{
//    return 1.2f;
//}

int fun_const_ref(int const &a)
{
    return a*2;
}

travel_time &fun_travel_ref(travel_time &a)
{
    cout<<a.hours<<endl;
    cout<<a.mins<<endl;
    cout<<&a<<endl;
    a.hours += 1;
    return a;
}

int &fun_int_ref(int &a)
{
    a++;
    cout<<a<<endl<<&a<<endl;
    return a;
}

int &fun_return_int_ref(int a)
{
    return a;
}

//return string,,,,not * not &
string fun_return_string(string a)      //写错了，形参应该是&的。。
{
    string aa = a + a;
    cout<<aa<<endl;
    return aa;
}

//void fun_array_ref(int &a, int n)
//{
//    for(int i = 0; i < n; i++)
//    {
//        cout<<a[i]<<", ";         //invalid type 'int[int]'
//    }
//}

int fun_default_a(int a, int b = 1111, int c = 111)
{
    return a+b+c;
}

//int fun_default_a(int a, int b = 1111)
//{
//    return 100000;
//}


float fun_default_b(float f1, float f2 = 1111.1f, float f3 = 111.1f);

float fun_default_b(float a, float b, float c)
{
    return a+b+c;
}

float fun_default_C(float a, float b);

float fun_default_C(float f1, float f2 = 3.2f)
{
    return f1+f2;
}

template <typename T>
void swap2(T &a, T &b);

//这个放在printAaAa之后，那个方法无法编译成功，
static int aAaA = 4;        //静态的内链接的文件作用域，
                        //静态和自动对应，是说持续性

void printAaAa()
{
    cout<<"AaAa:"<<aAaA<<endl;
}


int main()
{






    printAaAa();

//    int a = 4;
//    {
//        cout<<a<<endl;      //4
//        int a = 2;
//        cout<<a<<endl;      //2
//    }


//    char a[20];
//    int *p1, *p2;
//    p1 = new int;
//    p2 = new (a) int;
//
//    cout<<*p1<<", "<<*p2;
//    cout<<endl<<p1<<", "<<p2<<endl;
//    cout<<&a<<endl;         //
//    cout<<a<<endl;          //直接a，是字符串。
//    cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
//    delete p1;
//    delete p2;      //书上说，这句会运行时错误，但是没有错误。

//    int a;
//    static int b;
//    cout<<&a<<", "<<a<<endl;    //0x28ff2c, 4203403
//    cout<<&b<<", "<<b<<endl;    //0x40e024, 0


//    long add;
//    for(register int i = 0; i < 1000000; i++)
//    {
//        add = (long)&i;           //i is still keep in memory. not register
//    }
//    cout<<add<<endl;

//    register int a;
//    int b;
//    cout<<&a<<endl;           //ok, but is memory's address, not register
//    cout<<&b<<endl;


//    cout<<DDD<<endl;

//    int a = 3;
//    int b = 11;
//    swap2(a, b);
//    cout<<a<<", "<<b<<endl;


//    cout<<fun_default_C(1.4f)<<endl;
//    cout<<fun_default_C(1.4f, 1.4f)<<endl;

//    cout<<fun_default_b(1.1, 11.1)<<endl;
//    cout<<fun_default_b(1.1)<<endl;

//    int a = fun_default_a(5, 5, 5);
//    cout<<a<<endl;
//    cout<<fun_default_a(5, 4)<<endl;
//    cout<<fun_default_a(5)<<endl;

//    int a[] = {1,4,7,3,4};
//    fun_array_ref(a, 5);          //function is error


//    string aa = fun_return_string("asd");
//    cout<<aa<<endl;


//    int &a = fun_return_int_ref(3);
//    cout<<&a<<endl;     //0,nullpoint

//    int a = 3;
//    int &aa = fun_int_ref(a);
//    cout<<a<<", "<<aa<<endl;
//    cout<<&a<<", "<<&aa<<endl;      //a==aa, &a==&aa...


//    travel_time tt = {3,40};
//    travel_time &t2 = fun_travel_ref(tt);
//    cout<<tt.hours<<endl;
//    cout<<tt.mins<<endl;
//    cout<<t2.hours<<endl<<tt.mins<<endl;
//    cout<<&tt<<endl<<&t2<<endl;         //tt值==t2值，&tt != &t2...
//                    //...md，方法写错了，，fun_travel_ref，那时返回的是travel_time。不是引用。
//                    //，，而且变量t2的声明也错了，，写成travel_time了。不是travel_time &。。。
//                    //最可怕的是，travel_time 能接收 travel_time & 返回的值。
//                    //的确是可以的，毕竟引用就相当于一个变量，你return一个变量，我接收，没有任何问题。

//    int a = 3;
//    cout<<fun_const_ref(a)<<endl;
//    cout<<fun_const_ref(a+1)<<endl;     //const形参 就可以了
//    cout<<fun_const_ref(1.2f)<<endl;        //
////    cout<<fun_ref(1.3f)<<endl;      //error, 用int对非const的int&初始化是非法的


//    int a = 3;
//    cout<<fun_ref(a)<<endl;
//    cout<<fun_ref(a+1)<<endl;       //error

//    void * p;
//    int a = 3;
//    p = &a;
//    cout<<*(int *)p<<endl;          //必须强制类型转换
//    float f = 3.2;
//    p = &f;
//    cout<<*(float *)p<<endl;


//    int a = 111;
//    int *p = &a;
//    int &r = *p;
//    int b = 22;
//    p = &b;
//    cout<<a<<", "<<*p<<", "<<r<<", "<<b<<endl;      //111,22,111,22
//    cout<<&a<<", "<<p<<", "<<&r<<", "<<&b<<endl;    //&a==&r,!=,p==&b

//    int a = 3;
//    int &b = a;
//    int c = 22;
//    b = c;
//    cout<<a<<", "<<b<<", "<<c<<endl;        //都是22
//    cout<<&a<<", "<<&b<<", "<<&c<<endl;     //a，b地址相同，c不同


//    int const * p;
//    int a = 3;
//    p = &a;
//    (*p)++;           //error . p is point to a read only location..but p itself can change

//    const int * p;        //ok
//    int * const p2;     //error,uninitialized const p2

//    int&a;        //error,'a' declared, but not initialized

//    int a = 3;
//    int&aa = a;           //可以缩一起。。。
//    cout<<&a<<endl<<&aa<<endl;


//    int i = 1;
//    for(; i < 1000; i++)
//    {
//        cout<<fun_twice(i)<<", ";
//    }


//    int i = 1;        //5,4,3,2,1....和c一样，和java相反，
//    cout<<i++<<", "<<i++<<", "<<i++<<", "<<i++<<", "<<i++<<", "<<endl;

//    int *(*pf)(void);
//    pf = fun_fun3;
//    cout<<(*pf)()<<endl;
//    cout<<*pf()<<endl;            //this is * (pf())...
//    cout<<pf()<<endl;             //c also can.

//    void (*pf)(int);
//    pf = fun_fun1;
//    (*pf)(3);
////    *pf(3);       //error void value not ignored as it ought to be,,因为这个返回void,void是没有*的，所以报错
//
//    int (*pf2)();
//    pf2 = fun_fun2;
//    (*pf2)();
////    *pf2();     //error,invlid type argument of unary *


//    cout<<1<<" ";          //keyi的啊       运行4s后，cmd停止工作。，是保存递归的那个栈爆炸了吧。
//    main();

//    travel_time t1 = {1,20};
//    travel_time t2 = t1;
//    cout<<&t1<<endl<<&t2<<endl;



//    char *p = buildStr2('R', 5);
//    cout<<p<<endl;

//    char *p = fun_1('E');
//    cout<<p[0]<<endl;


//    char *p2 = "asd";
//    cout<<p2<<endl;
//    cout<<&p2<<endl;
//    p2 = buildStr2('P', 4);
//    cout<<&p2<<endl;
//    cout<<p2<<endl;
//
//    p2 = 0;
//    cout<<p2<<endl;

//    char *p = buildStr('A', 4);
//    cout<<p<<endl;


/**不知道为什么，下面4个调用都可以，特别是第3个,可以改变的，*/
////    int **a = &{{7,8}, {5,6}};        //不行的。。。
//    int aaa[][2] = {{1,2}, {3,4}};
//    int *a = &aaa[0][0];
//    fun_p_aa(a, 4);
//    fun_p_aaa(a, 4);
//
//    const int *aa = &aaa[0][0];
//    cout<<" "<<*aa<<endl;
//    fun_p_aa(a, 4);           //3
//    fun_p_aaa(a, 4);

//    const int aaaa[][2] = {{11,22,}, {33, 44}};       //22,,,这个也可以正确。
//    fun_p_ppp(aaaa, 2);
////    fun_p_pp(aaaa, 2);        // compile error,cannot convert const int (*)[2]  to int (*)[2]
//
//    int aaa[][2] = {{1,2}, {3,4}};
//    fun_p_ppp(aaa, 2);
//    fun_p_pp(aaa, 2);
//
//    int a[] = {1,2,3,4,5};
//    fun_p_aa(a, 5);
//    fun_p_aaa(a, 5);
//
//    const int aa[] = {11,22,33,44,55};
////    fun_p_aa(aa, 5);      //compile error, cannot conversion from const int * to int *
//    fun_p_aaa(aa, 5);

//    int a[] = {1,2,3};
//    cout<<sizeof(a)<<endl;
//    fun_length(a);      //4


//    fun_show();     //error
//    fun_show(4);      //right

//    cout<<fun_aa();     //1

//    cout<<cout.precision()<<endl;
//    cout<<11232.34567865f<<endl;    //超过百万就是科学技术法，应该是超过precision就是科学计数法
//    cout.precision(2);            //设置输出几个数字。包括整数+小数。
//    cout<<1332.3456f<<endl;     //en,改成2以后，这里就是科学计数法了。
//    return -1;


//--------------------------file i/o-----include fstream
//    ofstream outFile;
//    ofstream fout;
//
//    outFile.open("did.txt");        //并不存在，会不会新建？ hui!
//
//    char fileName[30];
//    cin>>fileName;          //输入qwe
//    fout.open(fileName);
//
//    double d = 123.654;
//    outFile<<d;
//    char a[20] = "asdf";
//    fout<<a<<endl;          //这个换行应该也会写到文件吧? hui!
//    //新建的文件是在cpp文件一起的，不是exe文件一起的。
//    //默认是清空然后写进去，不是追加


//    ifstream fin;
//    fin.open("qwe");
//
//    if(!fin.is_open())
//    {
//        exit(EXIT_FAILURE);     //方法和实参都是cstdlib
//    }
//
//    char a[20];
//    fin>>a;
//    cout<<a<<endl;
//    fin.close();
//
////    double d;
//    fin.open("did.txt");
//    fin>>a;
//    cout<<a<<endl;







//--------------------------


//    float f;
//    cin>>f;
//    cout<<f<<endl;
//    cin>>f;
//    cout<<f<<endl;


//    int a;
//    cin>>a;
//    cout<<a<<endl;
////    cin.clear();
////    cin>>a;
////    cout<<a<<endl;
////    cin>>a;
////    cout<<a<<endl;
////    cin.clear();            //!!!......
//    char c = 'm';
//    cin>>c;
//    cout<<c<<endl;
//    cin>>a;
//    cout<<a<<endl;


//    int a;
//    while((cin>>a))
//    {
//        cout<<". "<<a<<", "<<endl;
//    }


//    char c = 'v';
//    int a;
//    cin>>a;           //这里输入一个字母，那么下面的cin也没用
//    cout<<a<<endl;
//    cin.clear();        //加这句就有用了，会把上面那个自动读进去。
//    cin>>c;
//    cout<<c<<endl;



//    int a;
//    cin>>a;
//    switch(a)
//    {
//    case red:
//        cout<<"red"<<endl;
//        break;
//    case orange:
//        cout<<"orange"<<endl;
//        break;
//    }

//    if(true and false)
//    {
//        cout<<"111"<<endl;
//    }
//    if(true or false)
//    {
//        cout<<"222"<<endl;
//    }

//    int a = 3;
//    if(a++ == 2 || a++ == 4)        //如果第一个是a++ == 3，那么输出4，，现在是输出5，，||是一个顺序点
//    {
//        cout<<a<<endl;
//    }


//    int a;
//    cout<<typeid(a).name();


//    aaa(1);
//    aaa(1.2f);
////    aaa(1.2);       //error, double，没有这个方法

//    cout.put(66);

//    char ch;
//    while(cin.get(ch))          //ctrl+z 可以退出。。嗯，eof
//    {
//        cout<<ch;
//    }


////计算空格，tab,回车。。ctrl+z,回车后退出,ctrl+d是一个字符。
//    char ch;
//    int num = 0;
//    cin.get(ch);
//    while(cin.fail() == false)        // !cin.fail()
//    {
//        cout<<ch;
//        num += 1;
//        cin.get(ch);
//    }
//    cout<<endl<<num<<endl;
//
//    cin.clear();        //没这行的话，下面两句不会执行的。。因为eofbit设置为1以后，cin不会再读取了
//    cin>>ch;            //不会读取回车 tab 空格的，所以，
//    cout<<ch<<endl;



//    char name[3];
//    cin.get(name, 3);           //虽然写了3，但是数组的最后一个应该是\0，所以只会读2个，写4就可以输出想要的name[3]
//                        //嗯,是读取n-1个。
//    cout<<name[0]<<", "<<name[1]<<", "<<name[2]<<endl;
//    cin>>name[0];
//    cout<<endl<<name[0];



//cin.get，空格，回车，tab都会计数，特别是回车。
//    int num = 0;
//    char ch ;
//    cin.get(ch);
//    while(ch != '#')
//    {
//        cout<<ch;
//        num += 1;
//        cin.get(ch);
//    }
//    cout<<endl<<num<<endl;

//    int a;
//    cin>>a;       //12 34
//    cout<<a;
//    cin>>a;
//    cout<<a;

//..cin读char会忽略空格，tab，换行符。
//    int count = 0;
//    char ch='A';
//    do
//    {
//        cin>>ch;
//        ++count;
//        cout<<ch;
//    } while(ch != '#');
//    --count;
//    cout<<count<<endl;

//    char c;
//    int count = 0;
//    cin>>c;
//    while(c != '#')
//    {
//        cout<<c;
//        ++count;
//        cin>>c;
//    }
//    cout<<count<<endl;

//    int a;
//    cin>>a;
//    clock_t delay = a * CLOCKS_PER_SEC;
//    cout<<delay<<", "<<CLOCKS_PER_SEC<<endl;
//    clock_t start = clock();
//    while(clock()-start < delay)
//    {
////        cout<<clock()<<", ";      //1ms输出1.3个。
//        continue;
//    }
//    cout<<"end"<<endl;


//    int i = 0;
//    string s = "asdf";
//    while(s[i] != '\0')
//    {
//        cout<<s[i]<<endl;
//        ++i;
//    }


//    char a[] = "asd";
//    cout.setf(ios_base::boolalpha);
//    if(a == "asd")
//    {
//        cout<<true<<endl;
//    }
//    else
//    {
//        cout<<false<<endl;        //1
//    }
//
//    string s = "asd";
//    if(s == "asd")
//    {
//        cout<<true<<endl;         //1
//    }
//    else
//    {
//        cout<<false<<endl;
//    }


//    if(int a = 0)
//    {
//        cout<<a<<endl;
//    }

//    int a = (22, 1);
//    cout<<a<<endl;

//    int a = 17, 21;
//    cout<<a<<endl;

//    for({int i = 0; int j = 3;}; i < 4; i++)
//    {
//        cout<<i*j<<endl;
//    }


//    char *p = "123qwe";
//    string s = "123awde";
//    cout<<s.size()<<endl;
//    cout<<strlen(p)<<endl;            // strlen接受字符串的地址，不接受string
//    cout<<s[5]<<endl;       //数组的用法。。从0开始

//    for(int i = 0; i < 2; i++)
//        ;
//    cout<<i<<endl;


//    cout.setf(ios_base::boolalpha);       // 不加的话，输出0.加了输出false
//    cout<<(1>2)<<endl;

//    char *p = new char[3];
//    cin.get(p,5);             //只会读4个,然后+\0变成5个。设置好了，不会越界。而且就算越界，也可以显示出来，不像cin的那种，大于数组长度就会cmd停止工作。
//    cout<<p<<endl;
//    cin.get(p, 3);        //会继续读上面剩下的字符。
//    cout<<p<<endl;

//    void *p;
//    p = new int(3);
//    cout<<p<<", "<<(int *)p<<", "<<*(int *)p<<endl;        //ok
////    cout<<*p<<endl;        //cout<<*p is error, void * is not a pointer to object type

//    char *p;
//    cout<<p<<" "<<(int *)p<<endl;


//    char a[6] = "fox";
//    char *p = a;
//    cout<<a<<" "<<(int *)a<<endl;
//    cout<<p<<" "<<(double *)p<<endl;
//    int * pp = new int(1);
//    cout<<pp<<" "<<pp<<endl;

//    char *p = "asd";
//    cout<<p<<endl;


//    char a[3];
//    char *p;
//    p = a;
//    cin>>p;
//    cout<<a<<endl;
//    cout<<p<<endl;        //???,当输入的字符=数组长度时-空白,<数组长度时-正确,大于数组长度时,cmd停止工作,就是p输出的时候会判断是否越界？


//    char *p = "asdf";
//    cin>>p;

//    int *p = new int[3]{2112345678,2112345678,2112345678};
//    cout<<strlen((char *)p)<<endl;


//    char flower[10] = "rose";
//    cout<<flower<<"s are red\n";


//    int a[] = {1,2,3};
//    int *p = a;
//    cout<<sizeof(a)<<endl<<sizeof(p)<<endl;     //12, 4


//    int a[] = {1,2,3};
//    cout<<a[2]<<", "<<a[6]<<endl;

//    int a = new int[4]{1,2,3};            //int *,  int

//    int *p = new int[5]{1,2,3};
//    cout<<p[1]<<", "<<p[2]<<", "<<p[4]<<", "<<p[6]<<endl;

//    int *p;
//    p = new int;
//    delete [] p;
//    p = new int[3];
//    delete p;             // all can execute, but effect is undefined.

//    int *p = new int;
//    int *p2 = new int[2];
//    delete []p;
//    delete p2;            // can execute, but effect is undefined.


//    int a;
//    cin>>a;
//    int *p = new int[a];
//    for(int i = 0; i < a; i++)
//    {
//        cout<<*(p+i)<<", "<<(p+i)<<endl;        // 4 bytes.
//    }
//    delete []p;     // it seems useless. maybe this code just tell cpp, the memory can be used by new int
//    cout<<*p<<".."<<p<<endl;

//    int a = 4;
//    int *p = &a;
//    delete p;       // useless
//    cout<<a<<endl<<p<<endl<<*p<<endl;


//    int *p = new int;
//    delete p;
//    delete p;     // no error. no wrong. no exception


//    int *p = new int;
//    cout<<p<<endl<<*p<<endl;
//    p = new int(3);             // new int, 申请空间，并返回指针
//    cout<<p<<endl<<*p<<endl;
//    p = new int(5);
//    cout<<p<<endl<<*p<<endl;    // 为什么 new int之间相差16个字节。

//    int *p;
//    int a = 4;
//    p = &a;
//    cout<<p<<endl<<*p<<endl;

//    int *p;
//    p = (int *)0x28ff28;
//    cout<<p<<endl<<*p;

//    int *p;
//    p = 0x28ff28;             //invalid conversion
//    cout<<p<<endl<<*p<<endl;

//    int *p;
//    *p = 100;                 //boooom
//    cout<<*p<<endl<<p<<endl;

//    KKK kk = KKK(2200000000L);     //书上说可以用long的。。。
//    cout<<kk<<endl;

//    KKK kkk;
//    kkk = null;
//    cout<<kkk<<endl;          //int和枚举是互不干涉的，没办法通过int让cpp返回枚举常量，所以不会有二义性。

//    spectrum band = spectrum(3);
//    cout<<band<<endl;
//    band = spectrum(111);
//    cout<<band<<endl;
//    band = spectrum(2200000000);        //用int保存的，这里超越上限了
//    cout<<band<<endl;



//    float a = 3 + 3.4;
//    float b = 3.4 + green;        //valid, enum to be a float
//    cout<<a<<endl<<b<<endl;

//    int a = 3 + blue;     //valid, enum to be a int.
//    int b = blue + 3;
//    cout<<a<<endl<<b<<endl;

//    spectrum band = violet;
//    band++;
//    band = red + yellow;      //both invalid


//    spectrum band;
//    band = blue;
//    cout<<band<<endl;       //输出还是int数值
//    band = (spectrum)3;
//    cout<<band<<endl;
//    band = 3;             //invalid conversion from int to spectrum

//    St k = {"S", 4.3};            //默认匿名共用体的第一行作为参数的接收类型。
//    cout<<k.name<<endl<<k.intv<<endl<<k.douv<<endl;

//    St k = {"K", 4};
//    cout<<k.name<<endl<<k.intv<<endl;
//    k.douv = 1.2;
//    cout<<k.name<<endl<<k.douv<<endl;

//    union un a;
//    a.intv = 4;
//    cout<<a.douv<<", "<<a.intv<<endl;
//    a.douv = 1.2;
//    cout<<a.douv<<", "<<a.intv<<endl;


//    Info i = {"A", 3};
//    cout<<i.age<<endl<<i.name<<endl;

//    inflatable k;
//    k = {"K", 1.11, 2.22};                    //cpp support, c donot support
//    cout<<k.name<<k.price<<k.volume<<endl;

//    inflatable k = {.price=12.12, .name="Kin S"};             //not supported
//    cout<<k.name<<endl<<k.price<<endl<<k.volume<<endl;


//    inflatable k = {"Kin S", 9.99, 99.99};
//    cout<<k.name<<endl<<k.price<<endl<<k.volume<<endl<<k.name[0]<<endl;
//    inflatable j = k;             //same value, different address
//    cout<<j.name<<endl<<&j<<", "<<&k<<endl;

//    person p =
//    {
//        "aavc",
//        20
//    };
//    cout<<p.age<<", "<<p.name<<endl;

//    s = "asd";
//    s += " xc";
//    cout<<s<<endl;

//    s = "asd";
//    s1 = s;               //same value, different address
//    cout<<&s<<", "<<&s1<<endl;
//    cout<<s<<", "<<s1<<endl;

//    s = "asd";
//    cout<<s<<endl;
//    cin>>s;
//    cout<<s<<endl;
//    cout<<s[1]<<endl;


//    cin>>a;             //这行回车以后就直接结束了，因为回车的换行符不会被cin>>读取，而是留在输入队列中，导致get直接读了一个回车的换行符
//    cin.get(a, 10);
//    cout<<a<<endl;

//    char a[11];
////    cin.getline(a, 10);
//    cin.get(a, 10);               //这行输入 空行 ，那么会阻断输入，下面那个get没用了
//    cin.get(a, 10);
//    cout<<a<<endl;


//    char a[10];
//    cin.get(a, 12);     //输入大于12的不会停止工作。
//    cout<<a<<endl;

//    char a[10];
//    cin.getline(a, 15);       //输入大于14/15个字符的话，会停止工作。不过还可以继续进行。
//    cout<<a<<endl;

//    char a[10];
//    cin>>a;             //输入 空格分隔的两个字符串，第二个cin不会接受键盘输入的
//    cout<<"1."<<a<<endl;
//    cin>>a;
//    cout<<"2."<<a<<endl;

//    char s1[10];
////    cout<<&s1<<endl<<&(s1[0])<<endl;          //为什么输出不了。。。
////    printf("%p, %p, %p\n", s1, &s1[0], &s1[9]);       //cstdio输出可以，0地址小
//
//    char s2[10];
//    char s3[10];
//    cin>>s2;
////    s1 = "qqqqqqqqq";         //..不能这样写的
////    s3 = "aaaaaaaaa";
//    s1[0] = 'w';
//    s1[9] = 'e';
//    s3[0] = 'r';
//    s3[9] = 't';
//    cout<<s1<<endl;
//    cout<<s2<<endl;
//    cout<<s3<<endl;
//    cout<<&s1<<endl;        //地址大
//    cout<<&s2<<endl;
//    cout<<&s3<<endl;        //地址小

//    char a1[] = "hello, world";
//    char a2[10];            //实际输入的可以爆掉10，然后输出的时候是一直找到\0，而不是10个
//    cin>>a2;
//    cout<<a1<<", "<<strlen(a1)<<endl;
//    cout<<a2<<", "<<strlen(a2)<<endl;

//    cout<<"this is ""one line"<<endl;
//    cout<<"this is also"    " one line"<<endl;
//    cout<<"anyway "
//    "this is "
//    "one line"<<endl;

//    char aa[] = "asdf";
//    cout<<sizeof(aa)/sizeof(char);      //5

//    int s1[4] = {'a', 'b', 'c', 'd'};
//    int s2[4] = {'a', 'b', 'c', '\n'};
//    cout<<s1<<endl<<s2<<endl;           //怎么输出字符串

//    int a[3];
//    cout<<sizeof(a)<<endl;      //返回12

//    #define a 4
//    int aa[a];

//    const int a = 4;
//    int aa[a];

//    int a;
////    long (a);           //..cannot
//    (long) a;

//    short s = 55555;
//    short s1 = 54321;
//    int a = s + s1;
//    short a1 = s + s1;
//    cout<<a<<", "<<a1<<endl;

//    int a = 2100000000;
//    double d = a;
//    cout<<a<<", "<<d<<endl;

//    double d = 4.3e22;
//    int a = d;
//    cout<<d<<", "<<a<<endl;           //负的21亿，最小值。

//    double d = 4.312345;
//    float f = d;
//    cout<<d<<", "<<f<<endl;

//    float f = 5.1;
//    int a = f;
//    cout<<a<<", "<<f<<endl;

//    cout.setf(ios_base::fixed, ios_base::floatfield);

//    float f = 12.34567890f;
//    cout<<f<<endl;


//    float f2 = 7.3f;
//    cout<<f2<<endl;            //7.3,,not 7.30000

//    float f3 = 7.77777777777777777e10;
//    cout<<f3<<endl;                  //7.77778e+10

//    const int a;
//    a = 4;

//    cout<<sizeof(char)<<", "<<sizeof(wchar_t)<<endl;    //1, 2

//    char aa[10];
//    cin>>aa;                //也可以中文啊啊啊。不是说1个字节吗。。
//    cout<<aa<<endl;

//    char aa[10];      //声明数组都忘记了。。

//    wchar_t *wa = L"longlong";
//    wcout<<wa<<endl;
//    wchar_t waa[10];
//    wcin>>waa;                  //可以输入中文
//    wcout<<waa<<endl;


//    wchar_t wa = L'D';
//    wcout<<wa<<endl;


//    wchar_t wa;     //宽字符，不知道怎么测。。。中文塞不进去。
//    wcin>>wa;
//    wcout<<"out:"<<wa<<endl;



//    unsigned long a = 100Lu;
//    cout<<a<<endl;

//    short a = 17;
//    cout<<hex<<a<<", ";       //16
//    cout<<dec<<a<<", ";       //10
//    cout<<oct<<a<<", ";       //8
//    cout<<a<<endl;          //设置以后，不改就是以前的。


//    short int a = 11;
//    short int b = 011;
//    short int c = 0x11;
//    short int d = 0X11;
//    cout<<a<<", "<<b<<", "<<c<<", "<<d<<endl;   //11,9,17,17

//    long long a;
//    cout<<sizeof(long long)<<", "<<sizeof a<<endl;        //可以使用long long

//    int a;
//    cout<<a<<endl;        //random

//    int a(5);
//    cout<<a<<endl;      //5


//    sizeOfTypeInCpp();
//    SizeOfType();

//    cout<<INT_MAX<<endl;      //climit,,21亿
//    cout<<CHAR_BIT<<endl;       //8位
//    cout<<SHRT_MAX<<endl;       //32767
//    cout<<LONG_MAX<<endl;       //21亿
//    int a = 4;
//    cout<<sizeof(int)<<", "<<sizeof a<<endl;        //sizeof(int)  sizeof a, sizrof(a)
//                        //c also cannot sizeof int



    return 0;
}

char *buildStr(char c, int n)
{
    char *p = new char[n+1];
    p[n] = '\0';
    while(n-- > 0)
    {
        p[n] = c;
    }
    return p;
}

template <typename T>
void swap2(T &a, T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
}













/*-------------------下面是cpp调用c------------------------*/
/*
extern "C"          //cpp调用c方法必须这样写。c文件不用改。
{
    extern main2();
    extern cFun();
}

int main3()
{
    cout<<"start..."<<endl;
    int a = main2();
    cout<<"the return of main2 is "<<a<<endl;      //没有任何显示。。不知道为什么
                                            //md,cb打开了两个工程，在这个文件按F9，是允许的另一个工程的main，所以没有改变。。
                                            //是的，F9是这个文件的，到另一个工程的main文件，F9允许的是这个。
                                            //额，cb靠工程名的粗体来标识F9会运行的工程
                                            //右键工程名的第一个activte project,用右键里的build也能获得焦点，双击工程名也可以。
    a = cFun();
    cout<<"the return of cFun is "<<a<<endl;
//    cout << "Hello world!" << endl;
//    return 0;             //cpp03中，main方法不加return的话，会默认return 0; 其他函数没有
}
*/
