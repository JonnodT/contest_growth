#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <set>
#include <cstring>
#define maxm 65
#define maxn 32010

using namespace std;

struct obj
{
    int v,p,q; //价格 重要度 类型
}a[maxm],rel[maxm][maxm]; //a: 存储原始数据    rel:[主件编号][附件编号]   t[i]:主件i后有多少附件  cnt[i]:第i个主件的分组中有多少个方案
int n,m,t[maxm],V[maxm][10],P[maxm][10],cnt[maxm],f[maxn],ans;
int main()
{
    //读取，存储
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);//正常的读入
        if(a[i].q)//如果这个物品是附件
        {
            t[a[i].q]++;
            rel[a[i].q][t[a[i].q]].v=a[i].v;
            rel[a[i].q][t[a[i].q]].p=a[i].p;
            rel[a[i].q][t[a[i].q]].q=a[i].q;//把它存在相应的主件的分组中
        }
    }


    //对每个主件分组进行01背包处理    参考：洛谷p1164 小a点菜（压到一维的01完全背包）
    for(int i=1;i<=m;i++)// 对于每件物品
    {
        if(t[i])//如果当前物品为有附件的主件
        {
            //a[i]：当前正遍历的有附件的主件  rel[i][j]: 当前正在遍历的附件

            memset(f,-1,sizeof(f));//恰好背包的处理，-1表示不恰好取到此价值
            f[0]=0;//恰好背包的处理 base case

            //这里的算法是：压到一维的01完全背包
            for(int j=1;j<=t[i];j++) //对于这个主件所有的附件
                for(int k=n-a[i].v;k>=rel[i][j].v;k--)
                    if(f[k]<f[k-rel[i][j].v]+rel[i][j].v*rel[i][j].p && f[k-rel[i][j].v]!=-1) //恰好背包的判断
                        f[k]=f[k-rel[i][j].v]+rel[i][j].v*rel[i][j].p; //很平常的01状态转移


            for(int j=0;j<=n-a[i].v;j++)
                if(f[j]!=-1)//恰好背包的判断，这种附件组合满足题意
                {
                    cnt[i]++;
                    V[i][cnt[i]]=j+a[i].v; 
                    P[i][cnt[i]]=f[j]+a[i].v*a[i].p;//把此情况存在主件i的分组中，为分组背包做好处理
                }

        }
        //如果当前物品为主件(不一定非要有附件),注意这个if只要是主件都会进，如果有附件会进上面的if，之后这个if的作用只是
        //再把单独买主件的情况加进来，如果上面if没走，这个主件就没有附件，那么他这个组就只有单独买他自己的这种方案
        if(!a[i].q)
        {
            cnt[i]++;
            V[i][cnt[i]]=a[i].v;
            P[i][cnt[i]]=a[i].v*a[i].p;//存储
        }
    }

    //清空f数组，并在分组背包求解中重新利用
    memset(f,0,sizeof(f));

    //分组背包求解
    for(int i=1;i<=m;i++) //对于每件物品
        for(int j=n;j>=0;j--) //对于所有容量（在本题中为预算）
            for(int k=1;k<=cnt[i];k++) //对于每个主件分组的每个方案（附件cnt[i]为0，不会走）
                if(j>=V[i][k]) //如果目前的预算可以买这个方案
                    f[j]=max(f[j],f[j-V[i][k]]+P[i][k]);//分组背包的计算

    //在dp数组中寻找答案
    for(int i=0;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d",ans);//输出
    return 0;
}