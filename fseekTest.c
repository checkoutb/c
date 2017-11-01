
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    FILE * fp;
    if((fp = fopen("f:/a", "rb")) == NULL)
//    {
//        printf("null\n");
//        return -1;
//    }
//
//    int a = fseek(fp, 0L, SEEK_END);
//    printf("%d\n", a);
//    long b = ftell(fp);
//    printf("%ld\n", b);
//
//    return 0;

//    FILE * fp;
//    if((fp = fopen("f:/a", "rb") == NULL))        //mlgb,==的优先级高于=，括号错了
    {
        printf("null 2");
        return -2;
    }
    int s = fseek(fp, 0L, SEEK_END);
    perror("aaa");                         //niubi.
    printf("%s\n",strerror(errno));     //niubi     char *strerror(int errnum)
    printf("%d", s);                   //-1
    long last = ftell(fp);
    printf("%ld\n", last);         //ld or d..for long and int are 32bits....why last is -1?
    char ch;
    for(long i = 1L; i <= last; i++)
    {
        fseek(fp, -i, SEEK_END);
        ch = getc(fp);
        if(ch != 'r')
            putchar(ch);
    }
    fclose(fp);

    return 0;
}


