#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int src,dst,wt;

};
int v,e;
void bellmanford(vector<edge>&edges)
{
    int parent[v];
    int cost_parent[v];
    vector<int>value(v,INT_MAX);
    parent[0]=-1;
    value[0]=0;
    bool updated;
    for(int i=0;i<v-1;i++)
    {
        updated=false;
        for(int j=0;j<e;j++)
        {
            int u=edges[j].src;
            int v=edges[j].dst;
            int wt=edges[j].wt;
            if(value[u]!=INT_MAX && value[u]+wt <value[v])
            {
                value[v]=value[u]+wt;
                parent[v]=u;
                cost_parent[v]=value[v];
                updated=true;
            }


        }
        if(updated==false)
            break;
    }
    for(int j=0;j<e && updated==true;j++)
    {
        int u=edges[j].src;
        int v=edges[j].dst;
            int wt=edges[j].wt;
            if(value[u]!=INT_MAX && value[u]+wt <value[v])
            {
             cout<<"graph has -ve edge cycle";
             return;
            }

    }
    for(int i=1;i<v;i++)
    {
        cout<<"u->v"<<parent[i]<<"->"<<value[i]<<" ";
    }
}
int main()
{
    cin>>v>>e;
    vector<edge>edges(e);
    int src,dst,wt;
    for(int i=0;i<e;i++)
    {
        cin>>src>>dst>>wt;
        edges[i].src=src;
        edges[i].dst=dst;
        edges[i].wt=wt;


    }
    bellmanford(edges);
}
/*
5 10
0 1 6
0 2 7
1 2 8
1 3 -4
1 4 5
2 3 9
2 4 -3
3 4 7
3 0 2
4 1 -2
*/
