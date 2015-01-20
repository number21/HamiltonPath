#include<stdio.h>
#include<stdlib.h>
#define N 20
#define FINISH 16
void DFS(int);
void DFS2(int,int);
void get_path();
int G[N][N],visited[N],prior[N],n;    //n is no of vertices and graph is sorted in array G[10][10]

void main()
{
    int i,j;
    FILE *fp;
    fp=fopen("graph.txt","r");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            fscanf(fp,"%d",&G[i][j]);
    for(i=0;i<N;i++) // ініціалізація нулями
        visited[i]=0;
    DFS2(0,0);
    system("pause");
}
void DFS2(int v, int from)
{
    int i,j;
    int flag=1;
    int tmp;
    if (visited[v] != 0)  // Якщо вже цей вузол відвідували, то нам нема що тут робити
    {
        return;
    }
    visited[v] = 1;   // Помічаємо вузол, як відвіданий
    prior[v]=from;
    if (v == FINISH-1)   // Перевіряємо чи кінець
    {
        for(tmp=0;tmp<N;tmp++)
        {
            flag=visited[tmp]&&flag;
        }
        if(flag==1)
        {
            get_path();
            printf("The path was found!\n");
        }
        visited[v] = 0;
        return;
    }
    for (j = 0; j < N; j++)  // Для кожного ребра
    {
        if( (visited[j]==0) && (G[v][j]==1) )
            DFS2(j,v);  // Запускаємось з сусіда
    }
    visited[v] = 0;
    return;
}
void get_path()
{
    int path[N]={0};
    int tmp=0;
    int v;
    for (v = FINISH-1; v != 0; v = prior[v])  // Проходимо з кінця в початок
    {
        path[tmp]=v;  // Запамятовуємо вершину
        tmp++;
    }
    path[tmp]=0;
    for(tmp=19;tmp>-1;tmp--) // Реверсно виводимо
    {
        printf("%d ",path[tmp]+1);
    }
    return;
}
