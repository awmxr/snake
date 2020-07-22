/*
Amir Marvasti Nejad & Mohsen Ardalan Ashuri
Mar
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mar5.h"
int score = 0;
struct node 
{
    int x;
    int y;
    char h;
    struct node * next;
};
struct node * creat_node(int i,int j)//mar
{
    struct node * nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> x = i;
    nn -> y = j;
    nn -> h = 'O';
    nn -> next = NULL;
    return nn;
}
struct node * creat_node2(int i,int j)//manee
{
    struct node * nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> x = i;
    nn -> y = j;
    nn -> h = '#';
    nn -> next = NULL;
    return nn;
}
void add_end(struct node * list,struct node * new_node)
{
    struct node * current;
    for(current = list ; current -> next != NULL;current = current -> next);
    current -> next = new_node;
    new_node -> next = NULL;
}
void add_front(struct node **plist,struct node * new_node)
{
    new_node -> next = *plist;
    *plist = new_node;
}
void delet_end(struct node * list)
{
    struct node * current = list;
    while(current -> next -> next != NULL)
    {
        current = current -> next;
    }
    free(current -> next);
    current -> next = NULL;
}
void print_table(struct node * list,int a,int b,int len,int bscore,int cl,struct node * list2,int c,int d)
{
    system("clear");
    char table[50][50];
    for(int i = 0;i < 50 ; i++)
    {
        for(int j = 0; j < 50 ; j++)
        {
            table[i][j] = ' ';   
        }
    }    
    struct node * current = list;
    while(current != NULL)
    {
        table[current -> y][current -> x] = current -> h;
        current = current -> next;   
    }
    struct node * current5 = list2;
    while(current5 != NULL)
    {
        table[current5 -> y][current5 -> x] = current5 -> h;
        current5 = current5 -> next;   
    }
    for(int i = 0 ; i < 50 ; i++)
    {
        table[i][0] = '|';
        table[i][49] = '|';
        table[0][i] = '=';
        table[49][i] = '=';
    }
    table[a][b] ='$';
    table[c][d] = '+';
    printf("\033[1;33m");
    printf("score : %d",score);
    printf("\033[0m");
    printf("\033[1m");
    printf("              len : %d",len);
    printf("\033[1;32m");
    printf("              best score : %d",bscore);
    printf("\033[0m");
    printf("\033[1m");
    printf("\n press 'p' to pause");
    printf("             press 'm' for menu\n");
    printf("\033[0m");
    for(int i = 0;i < 50 ; i++)
    {
        for(int j = 0; j < 50 ; j++)
        {
            if(table[i][j]=='@')
            {
                printf("\033[1;36m");
                printf("%c",table[i][j]);
                printf(" ");
                printf("\033[0m");
            }
            else
            {
                if(table[i][j] == 'O')
                {
                    printf("\033[1;%dm",cl);
                    printf("%c",table[i][j]);
                    printf(" ");
                    printf("\033[0m");
                }
                else
                {
                    if(table[i][j] == '$')
                    {
                        if(((score) % 8 )== 0)
                        {
                            printf("\033[1;32m");
                            printf("%c",table[i][j]);
                            printf("\033[0m");
                            printf("\033[1;33m");
                            printf("%c",table[i][j]);
                            printf("\033[0m");
                        }
                        else
                        {
                        printf("\033[1;32m");
                        printf("%c",table[i][j]);
                        printf(" ");
                        printf("\033[0m");
                        }
                    }
                    else
                    {
                        if(table[i][j] == '#')
                        {
                            printf("\033[1;31m");
                            printf("%c",table[i][j]);
                            printf(" ");
                            printf("\033[0m");

                        }
                        else//wall space
                        {
                            if(table[i][j] == '+')
                            {
                                printf("\033[1;36m");
                                printf("%c",table[i][j]);
                                printf(" ");
                                printf("\033[0m");

                            }
                            else
                            {
                                printf("\033[1;34m");
                                printf("%c",table[i][j]);
                                printf("%c",table[i][j]);
                                printf("\033[0m");
                            }
                        }
                    }
                }
            }
        
        }
        printf("\n");
    }    
}
struct node * check1(struct node * list)//barkhord be divar
{
    if(list -> x == 0)
    {
        list -> x = 48;
    }
    if(list -> x == 49)
    {
        list -> x = 1;
    }
    if(list -> y == 0)
    {
        list -> y = 48;
    }
    if(list -> y == 49)
    {
        list -> y = 1;
    }
    return list;
}
int check2(struct node * list,int a,int b)// sar mar be qaza reside ya ne?
{
    if((list -> y == a) &&(list -> x == b))
    {
        return 1;
    }
    return 0;
}
int check3(struct node * list)// mar be khodesh barkhord mikone ya na?
{
    struct node * current2 = list -> next -> next -> next;                                     //bashe
    while(current2 != NULL)
    {
        if((list -> x == current2 -> x) && (list -> y == current2 -> y))
        {
            return 0;
        }
        current2 = current2 -> next;
    }
    return 1;
}
int check4(struct node * list,int a,int b)// qaza ru badane va mane hast ya n?
{
    struct node * current = list;
    while(current -> next != NULL)
    {
        current = current -> next;
        if((current -> x == b)&&(current -> y == a))
        {
            return 0;
        }
    }
    return 1;
}
int check5(int bscore)//moqayese score va bscore
{
    if(score > bscore)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int check7(struct node * list,int c,int d)
{
    if((list -> y == c) &&(list -> x == d))
    {
        return 1;
    }
    return 0;
}
int check6(struct node * list,struct node * list2)//barkhord ba manee
{
    struct node * current = list2;
    while(current != NULL)
    {
        if((list -> x == current -> x) && (list -> y == current -> y))
        {
            return 0;
        }
        current = current -> next;
        
    }
    return 1;
}
struct node * up(struct node * list)
{
    struct node * new_node = (struct node *)malloc (sizeof(struct node));
    new_node -> x = list -> x;
    new_node -> y = list -> y - 1;
    new_node -> h = '@';
    list -> h = 'O';
    add_front(&list,new_node);
    delet_end(list);
    return list;
}
struct node * down(struct node * list)
{
    struct node * new_node = (struct node *)malloc (sizeof(struct node));
    new_node -> x = list -> x;
    new_node -> y = list -> y + 1;
    new_node -> h = '@';
    list -> h = 'O';
    add_front(&list,new_node);
    delet_end(list);
    return list;
}
struct node * right(struct node * list)
{
    struct node * new_node = (struct node *)malloc (sizeof(struct node));
    new_node -> next = NULL;
    new_node -> x = list -> x + 1;
    new_node -> y = list -> y;
    new_node -> h = '@';
    list -> h = 'O';
    add_front(&list,new_node);
    delet_end(list);
    return list;
}
struct node * left ( struct node * list)
{
    struct node * new_node = (struct node *)malloc (sizeof(struct node));
    new_node -> x = list -> x - 1;
    new_node -> y = list -> y;
    new_node -> h = '@';
    list -> h = 'O';
    add_front(&list,new_node);
    delet_end(list);
    return list;
}
int play(int speed,int cl)
{
    int bscore;
    int a;
    int b;
    int c;
    int d;
    FILE * fb;
    fb = fopen("amir.txt","r");
    if(fb == NULL)
    {
        printf("\n not");
    }
    fscanf(fb,"%d",&bscore);
    fclose(fb);
    struct node * mar = NULL;
    struct node * manee = NULL;
    mar = creat_node(23,22);
    mar -> h = '@';
    mar -> next = creat_node(23,21);
    mar -> next -> next = creat_node(23,20);
    manee = creat_node2(20,20);
    manee -> next = creat_node2(10,10);
    manee -> next -> next = creat_node2(30,30);
    manee -> next -> next -> next = creat_node2(40,40);
    manee -> next -> next -> next-> next = creat_node2(12,40);
    manee -> next -> next -> next-> next -> next= creat_node2(40,12);
    manee -> next -> next -> next-> next -> next -> next = creat_node2(40,11);                    //chidan mane va badane avalie Mar
    manee -> next -> next -> next-> next -> next -> next  = creat_node2(30,31);
    manee -> next -> next -> next-> next -> next -> next -> next = creat_node2(30,3);
    manee -> next -> next -> next-> next -> next -> next -> next -> next = creat_node2(29,14);
    manee -> next -> next -> next-> next -> next -> next -> next -> next -> next = creat_node2(17,15);
    manee -> next -> next -> next-> next -> next -> next -> next -> next -> next -> next = creat_node2(18,47);
    int g = 1;
    while(1)
    {
    srand(time(NULL)*g);
    a = rand() % 48 + 1;
    b = rand() % 48 + 1;  //makan qaza
    c = rand() % 48 + 1;
    d = rand() % 48 + 1;
        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
            break;
        g++;
    }   
    int len = 3;
    char jahat;
    // jahat = 's';
    print_table(mar,a,b,len,bscore,cl,manee,c,d);
    while(1)
    {
    if (!kbhit())
    {
        
        struct node * new_node = (struct node *)malloc (sizeof(struct node)); //qaza / mokh akhar
        struct node * current2 = mar;
        for(current2;current2 -> next != NULL;current2 = current2 -> next);
        new_node = current2;
        switch(jahat)
        {
            case 'w':
            mar = up(mar);
            mar = check1(mar);
            if((check3(mar) == 0)||(check6(mar,manee) == 0))
            {
                int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;  
            }
            if(check2(mar,a,b)== 1)
            {
                score++;
                if(((score) % 8 )== 1)
                {
                    score++;
                }
                add_end(mar,new_node);
                len++;
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        a = rand() % 48 + 1;
                        b = rand() % 48 + 1;
                        // c = rand() % 48 + 1;
                        // d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }    
            }
            if(check7(mar,c,d) == 1)
            {
                delet_end(mar);
                len--;
                if(len == 2)
                {
                    int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    
                }
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        // a = rand() % 48 + 1;
                        // b = rand() % 48 + 1;
                        c = rand() % 48 + 1;
                        d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }
            }
            print_table(mar,a,b,len,bscore,cl,manee,c,d);
            break;
            case 's':
            mar = down(mar);
            mar = check1(mar);
            if((check3(mar) == 0)||(check6(mar,manee) == 0))
            {
                int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
            }
            if(check2(mar,a,b)== 1)
            {

                score++;
                if(((score) % 8 )== 1)
                {
                    score++;
                }
                srand(time(NULL));
                add_end(mar,new_node);
                len++;
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        a = rand() % 48 + 1;
                        b = rand() % 48 + 1;
                        // c = rand() % 48 + 1;
                        // d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;

                    }   
            }
            if(check7(mar,c,d) == 1)
            {
                delet_end(mar);
                len--;
                if(len == 2)
                {
                    int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
                }
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        // a = rand() % 48 + 1;
                        // b = rand() % 48 + 1;
                        c = rand() % 48 + 1;
                        d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }
            }
            print_table(mar,a,b,len,bscore,cl,manee,c,d);
            break;
            case 'd':
            mar = right(mar);
            mar = check1(mar);
            if((check3(mar) == 0)||(check6(mar,manee)==0))
            {
                int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
            }
            if(check2(mar,a,b)== 1)
            {
                score++;
                if(((score) % 8 )== 1)
                {
                    score++;
                }
                add_end(mar,new_node);
                len++;
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        a = rand() % 48 + 1;
                        b = rand() % 48 + 1;
                        // c = rand() % 48 + 1;
                        // d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }    
            }
            if(check7(mar,c,d) == 1)
            {
                delet_end(mar);
                len--;
                if(len == 2)
                {
                    int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
                }
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        // a = rand() % 48 + 1;
                        // b = rand() % 48 + 1;
                        c = rand() % 48 + 1;
                        d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }
            }
            print_table(mar,a,b,len,bscore,cl,manee,c,d);
            break;
            case 'a':
            mar = left(mar);
            mar = check1(mar);
            if((check3(mar) == 0)||(check6(mar,manee) == 0))
            {
                int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
            }
            if(check2(mar,a,b)== 1)
            {
                score++;
                if(((score) % 8 )== 1)
                {
                    score++;
                }
                srand(time(NULL));
                // struct node * new_node;
                add_end(mar,new_node);
                len++;  
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        a = rand() % 48 + 1;
                        b = rand() % 48 + 1;
                        // c = rand() % 48 + 1;
                        // d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;    
                    }    
            }
            if(check7(mar,c,d) == 1)
            {
                delet_end(mar);
                len--;
                if(len == 2)
                {
                    int q = 0;
    int m[7];
    while(q < 25)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                if(check5(bscore) == 0)
                {
                    FILE * fa;
                    fa = fopen("amir.txt","w+");
                    fprintf(fa,"%d",score);
                    fclose (fa);
                }
                score = 0;
                return -1;
                }
                int g = 1;
                    while(1)
                    {
                        srand(time(NULL)*g);
                        // a = rand() % 48 + 1;
                        // b = rand() % 48 + 1;
                        c = rand() % 48 + 1;
                        d = rand() % 48 + 1;
                        if((check4(mar,a,b) == 1) && (check4(manee,a,b) == 1)&& (check4(mar,c,d) == 1)&&(check4(manee,c,d) == 1))
                            break;
                        g++;
                    }
            }
            print_table(mar,a,b,len,bscore,cl,manee,c,d);
            break;
        }
    }
    else
    {
        char jahat2 = getchar();
        if(jahat2 == 'm')
        {
            score = 0;
            break;
        }
        if(jahat2 == 'p')
        {
            system("clear");
            printf("\033[1m");
            printf("press 'w' or 's' or 'd' or 'a' to continue!");
            printf("\033[0m");
            while(1)
            {
                if(kbhit())
                {
                    break;
                }
            }
        }
        if(((jahat == 'w') && (jahat2 =='s'))||((jahat == 's') && (jahat2 == 'w'))||((jahat == 'a')&&(jahat2=='d'))||(jahat == 'd')&&(jahat2 == 'a'))
        {
            continue;
        }
        else
        {
            jahat = jahat2;
            continue;
        }    
        

    }
        int o = 0;
        while(o < speed)
        {
            o++;
        }   
    }

}
void show()// record show
{
    char a;
    int record;
    FILE * fb;
    fb = fopen("amir.txt","r");
    fscanf(fb,"%d",&record);
    fclose(fb);
    // printf("record : %d\n",record);
    while(1)
    {
        system("clear");
        printf("\033[1;33m");
        printf("\nRecord ");
        printf("\033[0m");
        printf("\033[1m");
        printf(": ");
        printf("\033[1;32m");
        printf("%d",record);
        system("clear");
        printf("\033[0m");
        printf("\033[1m");
        printf("\nenter 'm' for menu : ");
        scanf("%c",&a);
        if(a == 'm')
        {
        printf("\033[0m");
            break;
        }
    }
}
int level()
{
    int ch;
    system("clear");
    printf("\033[1;32m");
    printf("%10s","levels");
    printf("\n%10s","------");
    printf("\033[0m");
    printf("\033[1m");
    printf("\n%9s","1.One");
    printf("\n%9s","2.Two");
    printf("\n%10s","3.Tree");
    printf("\n%10s","4.Four");
    printf("\n%10s","5.Five");
    printf("\033[1;31m");
    printf("\n    choose : ");
    printf("\033[0m");
    printf("\033[1m");
    scanf("%d",&ch);
    printf("\033[0m");
    switch(ch)
    {
        case 1:
        return 200000000;
        break;
        case 2:
        return 100000000;
        break;
        case 3:
        return 75000000;
        break;
        case 4:
        return 50000000;
        break;
        case 5:
        return 25000000;
        break;
    }
}
int color()
{
    int c;
    system("clear");
    printf("\033[1;31m");
    printf("\n1.Red");
    printf("\033[1;34m");
    printf("\n2.Blue");
    printf("\033[1;33m");
    printf("\n3.Yellow");
    printf("\033[1;32m");
    printf("\n4.Green");
    printf("\033[1;36m");
    printf("\n5.Blue2");
    printf("\033[1;35m");
    printf("\n6.purple");
    printf("\033[0m");
    printf("\033[1m");
    printf("\nchoose : ");
    printf("\033[0m");
    printf("\033[1m");
    scanf("%d",&c);
    printf("\033[0m");
    switch(c)
    {
        case 1:
        return 31;
        break;
        case 2:
        return 34;
        break;
        case 3:
        return 33;
        break;
        case 4:
        return 32;
        break;
        case 5:
        return 36;
        case 6:
        return 35;
        break;
    }
}
int main()
{
    int cl = 33;
    int speed = 100000000;
    int o;
    int p = 0;
    int n[7];
    while(p < 5)
    {
        p++;
        system("clear");
        srand(time(NULL)*(p + 2));
        n[0] = rand() % 5 + 31;
        printf("\033[7;%dm",n[0]);
        printf("W");
        srand(time(NULL)*(p + 3));
        n[1] = rand() % 5 + 31;
        printf("\033[1;%dm",n[1]);
        printf("E");
        srand(time(NULL)*(p + 4));
        n[2] = rand() % 5 + 31;
        printf("\033[1;%dm",n[2]);
        printf("L");
        srand(time(NULL)*(p + 5));
        n[3] = rand() % 5 + 31;
        printf("\033[1;%dm",n[3]);
        printf("L");
        srand(time(NULL)*(p + 6));
        n[3] = rand() % 5 + 31;
        printf("\033[1;%dm",n[3]);
        printf("C");
        srand(time(NULL)*(p + 7));
        n[4] = rand() % 5 + 31;
        printf("\033[1;%dm",n[4]);
        printf("O");
        srand(time(NULL)*(p + 8));
        n[5] = rand() % 5 + 31;
        printf("\033[1;%dm",n[5]);
        printf("M");
        srand(time(NULL)*(p + 9));
        n[6] = rand() % 5 + 31;
        printf("\033[1;%dm",n[6]);
        printf("E");
        printf("\033[0m\n");
        int o = 0;
        while(o < 100000000)
        {
            o++;
        }
    }
    system("clear");
    while(1)
    {
        system("clear");
        int choose;
        printf("\033[1;32m");
        printf("\n%8s","MENU");
        // printf("\033[1;31m");
        printf("\n%9s","-----");
        printf("\033[0m");
        printf("\033[1m");
        printf("\n%10s","1.Play");
        printf("\n%17s","2.Speed level");
        printf("\n%18s","3.show records");
        printf("\n%11s","4.color");
        printf("\n%10s","5.Exit");
        printf("\033[1;31m");
        printf("\n    choose : ");
        printf("\033[0m");
        printf("\033[1m");
        scanf("%d",&choose);
        printf("\033[0m");
        switch(choose)
        {
            case 1:
            play(speed,cl);
            break;
            case 2:
            speed = level();
            break;
            case 3:
            show();
            break;
            case 4:
            cl = color();
            break;
            case 5:
            return -1;
            break;
        }
    }    
}