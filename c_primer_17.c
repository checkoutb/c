
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

typedef struct Node5 Node5;     //������
typedef struct Node5
{
    int val5;
    Node5 *next;
} Node5;            //���������������������������ģ���ô������struct Node5�˰ɡ��������ǣ�ֱ��typedef Node5�Ǵ���ġ�

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


//    sample season;            //cppӦ�ÿ��ԣ�c���У�unknown type

//    enum sample season;           //0 error 0 warning
//    season = sage;
//    season = 2;
//    season = (enum sample) 3;
//    season++;

//    struct Node22 aa;
////    Node22 aaa;         //error, unknow type Node22

//    const int a = 1;
//    const int b = 2;
//    const int c = a * b;          //����˵c������const��ʼ��const������������ԣ�������������Ǳ�׼c99�ɣ�
//    printf("%d\n", c);

//    int x = 'ABCD';
//    char c = 'ABCD';
//    printf("%0x, %c\n", x, c);          //41424344,,Ӧ�þ���ABCD��ascII��ɣ��ǵģ�����������16���Ƶ�41��  c�� D�������һ���ַ�����С��ģʽ�й��𣿱Ͼ�D�ǵ�λ�������˵͵�ַ��
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
        //����Ҫ���malloc���ص��ǲ���NULL��
        temp = (struct Node22 *)malloc(sizeof(struct Node22));

        temp->val = 3*i;        //û�г�ʼ���Ļ������������
//        temp->next = NULL;      //û�г�ʼ����ָ��Ҳ�����������ᵼ��hile(prev != NULL)�Ǹ���ѭ��

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
    prev->next = NULL;      //��ֹ��ѭ�������Ҳ���ÿ��mallocʱ������ָ��Ϊnull
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








































