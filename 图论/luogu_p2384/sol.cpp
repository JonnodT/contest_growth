#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define mod 9987
using namespace std;

//struct for edge, e stores all the edges
struct edge{
    int to,next,w;
}e[1000005];
queue<int> q;

//e stores all the edges
//each element in first is the head of a linked list of index of edges in e from that node
//the last edge in the linked list has next value of 0
int first[1005];
//is po used to reconstruct the edges?
int po[1005][2],
int vis[1005], tot=0; //visted array and total n
double dis[1005];
void addedge(int u,int v,int val)
{
    e[++tot].w=val;
    e[tot].to=v;
    e[tot].next=first[u];
    first[u]=tot;
}
int main()
{
    //readin data
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }


    //set to infinity
    memset(dis,255,sizeof(dis));

    // initialize starting point
    dis[1]=0;vis[1]=1;
    q.push(1);


    while(q.size())
    {   
        //get the front of the q
        int now=q.front();q.pop();
        // ? ? ? 
        vis[now]=0;
        //for all the edges from this node
        for(int i=first[now];i;i=e[i].next)
        {
            //get an edge's 
            int v=e[i].to;
            if(dis[v]>dis[now]+log(e[i].w))
            {
                dis[v]=dis[now]+log(e[i].w);
                po[v][0]=now;po[v][1]=e[i].w;
                if(!vis[v]) {vis[v]=1;q.push(v);}
            }
        }
    }
    //reconstruct the path and get the answer
    int ans=1,pos=n;
    while(pos!=1)
    {
        ans*=po[pos][1];
        ans%=mod;
        pos=po[pos][0];
    }
    printf("%d\n",ans);
    return 0;
}