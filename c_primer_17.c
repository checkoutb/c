
#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int val;
    struct Node *next;
}Node4;

typedef struct Node2
{
    int val2;
    Node4 *next;
//    Node3 *next2;       //unknow type 'Node3'
} Node3;

typedef struct Node5 Node5;     //重名。
typedef struct Node5
{
    int val5;
    Node5 *next;
} Node5;            //可以重名？，如果上面就是重名的，那么这里是struct Node5了吧。。好像不是？直接typedef Node5是错误的。

typedef struct Node11 Node11;
typedef struct Node11
{
    int val11;
    Node11 *next;
} Node12;


struct Node22
{
    int val;
    struct Node22 *next;
};

enum sample {sage, thyme, salt, pepper};

int main()
{


//    sample season;            //cpp应该可以，c不行，unknown type

//    enum sample season;           //0 error 0 warning
//    season = sage;
//    season = 2;
//    season = (enum sample) 3;
//    season++;

//    struct Node22 aa;
////    Node22 aaa;         //error, unknow type Node22

//    const int a = 1;
//    const int b = 2;
//    const int c = a * b;          //书上说c不能用const初始化const，但是这里可以，可能我这个不是标准c99吧？
//    printf("%d\n", c);

//    int x = 'ABCD';
//    char c = 'ABCD';
//    printf("%0x, %c\n", x, c);          //41424344,,应该就是ABCD的ascII码吧，是的，而且这里是16进制的41。  c是 D，是最后一个字符，和小端模式有关吗？毕竟D是低位，放在了低地址。
//    return 0;
}


int main2()
{
    struct Node22 *temp;
    struct Node22 *head = NULL;
    struct Node22 *prev;

    //build a list
    for(int i = 0; i < 5; i++)
    {
        //这里要检查malloc返回的是不是NULL。
        temp = (struct Node22 *)malloc(sizeof(struct Node22));

        temp->val = 3*i;        //没有初始化的话，是随机数。
//        temp->next = NULL;      //没有初始化，指针也是随机数。这会导致hile(prev != NULL)是个死循环

        if(head == NULL)
        {
            head = temp;
            prev = temp;
        }
        else
        {
            prev->next = temp;
            prev = prev->next;
        }
    }

    //loop && show
    prev->next = NULL;      //防止死循环，而且不用每次malloc时都设置指针为null
    prev = head;
    while(prev != NULL)
    {
        printf("%d, ", prev->val);
        prev = prev->next;
    }

    //free memory
    prev = head;
    temp = head;
    while(prev != NULL)
    {
        temp = prev->next;
        free(prev);
        prev = temp;
    }

    return 0;
}








































