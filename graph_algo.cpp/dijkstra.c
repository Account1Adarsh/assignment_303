#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

int min(int x,int y){
    if(x<=y) return x;
    else return y;
}

void dijkstra(int V,int graph[V][V], int src){
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    bool fin[V];
    for(int i=0;i<V;i++){
        fin[i]=false;
    }
    for(int count=0;count<V;count++){
        int u=-1;
        
        //
        for(int i=0;i<V;i++){
            if(fin[i]==false && (u==-1||dist[i]<dist[u])){
                u=i;
            }
        }

        fin[u]=true;//finalising 

        for(int v=0;v<V;v++){
            if( graph[u][v]!=0 && fin[v]==false){
                dist[v]=min(dist[v],dist[u]+graph[u][v]);
            }
        }
    }
    for(int i=0;i<V;i++){
        printf("%d ",dist[i]);
    }

}
/*
input:
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

expected output:
0 4 12 19 21 11 9 8 14
*/

int main(){
    int V;
    scanf("%d ",&V);
    int graph[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d ",&graph[i][j]);
        }
    }

    dijkstra(V,graph,0);

}