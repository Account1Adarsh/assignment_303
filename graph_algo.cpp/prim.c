#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

int min(int x,int y){
    if(x<=y) return x;
    else return y;
}

int prim(int V,int graph[V][V]){
    int key[V],res=0;
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    bool mset[V];
    for(int i=0;i<V;i++){
        mset[i]=false;
    }

    for(int count=0;count<V;count++){
        int u=-1;

        for(int i=0;i<V;i++){
            if(mset[i]==false && (u==-1||key[i]<key[u])){
                u=i;
            }
        }

        mset[u]=true;
        res=res+key[u];

        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && mset[v]==false){
                key[v]=min(key[v],graph[u][v]);
            }
        }
    }
}


int main(){
    int V;
    scanf("%d ",&V);
    int graph[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d ",&graph[i][j]);
        }
    }
    printf("%d ",prim(V,graph));
    
}