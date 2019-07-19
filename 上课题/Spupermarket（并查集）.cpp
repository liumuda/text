/*Sample Input
4  50 2  10 1   20 2   30 1
7  20 1   2 1   10 3  100 2   8 2
   5 20  50 10
Sample Output
80
185*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=10010;
int F[MAXN];
struct Node
{
    int p,d;
}node[MAXN];
bool cmp(Node a,Node b)//按p从大到小排序。d没有关系
{
    return a.p>b.p;
}
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)   //无限输入 
    {
        memset(F,-1,sizeof(F));   //初始化为-1 
        for(int i=0;i<n;i++)
          scanf("%d%d",&node[i].p,&node[i].d);
        sort(node,node+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int t=find(node[i].d); 
            if(t>0)
            {
                ans+=node[i].p;
                F[t]=t-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
