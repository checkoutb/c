/*
#include "Stock.h"


Stock::Stock()
{
    //ctor
}

Stock::~Stock()
{
    //dtor
}
*/


//��õķ���������������ͷ�ļ��У����Ա�����������һ��������Դ�����ļ���
//��codeblocks�½�һ���࣬�Զ����õ�һ��

#include <iostream>
#include <cstring>

class Stock
{
private:            //��ʼʱ��Ĭ����private��
    char company[30];
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}

public:
    void acquire(const char *co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show();
    Stock(const char *co, int n = 0, double pr = 0.0);
    Stock();
    ~Stock();
    void show2()const;

};

void Stock::acquire(const char *co, int n, double pr)
{
    std::strncpy(company, co, 29);
    company[29] = '\0';
    if(n < 0)
    {
        std::cerr<<"Number of shares can't be negative."<<company<<" shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(int num, double price)
{
    if(num < 0)
    {
        std::cerr<<"Number of shares purchased can't be negative."<<"Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if(num < 0)
    {
        cerr<<"Number of shares sold can't be nagitave,"
            <<"Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cerr<<"You can't sell more than you have!"
            <<"Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::endl;
    cout<<"Company: "<<company
        <<" shares: "<<shares<<endl
        <<" share Price $: "<<share_val
        <<" Total Worth $: "<<total_val<<endl;
}

Stock::Stock(const char *co, int n, double pr)
{
    std::strncpy(company, co, 29);
    company[29] = '\0';

    if(n < 0)
    {
        std::cerr<<"Number of shares can't be negative;"
            <<company<<" shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
    std::cout<<"This is constructor: "<<company<<std::endl;
}

Stock::Stock()
{
    using namespace std;
    cout<<"This is Constructor"<<endl;
}

Stock::~Stock()
{
    std::cout<<"Destruction:"<<company<<std::endl;
}

void Stock::show2()const
{
//    show();               //error...
    using std::cout;
    using std::endl;
    cout<<"Company: "<<company
        <<" shares: "<<shares<<endl
        <<" share Price $: "<<share_val
        <<" Total Worth $: "<<total_val<<endl;
}

void testOrderOfConstructionAndDestriction()
{
    Stock s1("1");
    Stock s2("2");
}

int main()
{
    using std::cout;
    using std::ios_base;

//    Stock stock1;               //�����������+�����ˡ�
//                //д��Stock::Stock(const char *co, int n, double pr)��
//                //rror: no matching function for call to 'Stock::Stock()'
//                    //��javaһ�������д���в����Ĺ��췽����Ĭ�ϵĹ��췽����û����
//    stock1.acquire("NanoSmart", 20, 12.50);
//    cout.setf(ios_base::fixed);
//    cout.precision(2);
//    cout.setf(ios_base::showpoint);
//    stock1.show();

//    Stock stock2 = Stock("IBM", -2, 100.0);
//    stock2.show();
//
//    cout<<&stock1<<std::endl<<&stock2<<std::endl;
//    stock2 = stock1;
//    stock2.show();
//    cout<<&stock1<<std::endl<<&stock2<<std::endl;
//
//    Stock stock3 = stock1;
//    stock3.show();
//    cout<<&stock3<<std::endl;

//    cout<<"\n\n\n";
//    testOrderOfConstructionAndDestriction();

//    const Stock s1 = Stock("Kludgehorn");
//    s1.show2();

//    Stock s1 = "Jobilayangse";
//    s1.show();

//    Stock myStuff[2];
//    myStuff[1].show();

//    Stock stocks[2] = {
//        Stock("NanoSmart", 12.5, 20),
//        Stock()
//    };

//    Stock stock[3];

    return 0;
}



















