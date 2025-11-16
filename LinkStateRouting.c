#include <stdio.h>
#define INF 99
#define MAX 10

void dijkstra(int g[MAX][MAX], int src, int n){
    int dist[MAX], vis[MAX]={0};
    for(int i=0;i<n;i++) dist[i]=INF;
    dist[src]=0;

    for(int c=0;c<n-1;c++){
        int u=-1,min=INF;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<min) min=dist[i],u=i;

        vis[u]=1;
        for(int v=0;v<n;v++)
            if(!vis[v] && g[u][v] && dist[u]+g[u][v]<dist[v])
                dist[v]=dist[u]+g[u][v];
    }

    for(int i=0;i<n;i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);
}

int main(){
    int n, g[MAX][MAX], src;
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
            if(i!=j && g[i][j]==0) g[i][j]=INF;
        }

    scanf("%d",&src);
    dijkstra(g, src, n);
    return 0;
}
