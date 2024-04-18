#include<bits/stdc++.h>
using namespace std;
const int V=4;
int mindist(int dist[],bool near[]){
    int min_index=-1;
    int min_dist=INT_MAX;
    for(int i=0;i<V;i++){
        if(!near[i] && dist[i]<min_dist){
            min_dist=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void prims(int graph[V][V]){
    int t[V-1][2];
    bool near[V];
    int dist[V];
    int mincost=0;
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        near[V]=false;
    }
    dist[0]=0;
    for(int i=0;i<V;i++){
        int u=mindist(dist,near);
        near[u]=true;
        
        for(int v=0;v<V;v++){
            if(graph[u][v] && !near[v] && graph[u][v] < dist[v]){
                dist[v]=graph[u][v];
                t[v-1][0]=u;
                t[v-1][1]=v;
            }
        }
    }
    for(int i=0;i<V-1;i++){
        cout<<t[i][0]<<" "<<t[i][1]<<endl;
        mincost+=graph[t[i][0]][t[i][1]];
    }
    cout<<"Total cost of MST: "<<mincost<<endl;
}
int main(){
    int graph[V][V]={{0,4,0,0},{4,0,8,0},{0,8,0,7},{0,0,7,0}};
    prims(graph);
    return 0;
}