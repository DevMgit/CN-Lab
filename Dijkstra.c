#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int g[MAX][MAX], int n, int s){
    int cost[MAX][MAX], dist[MAX], vis[MAX]={0}, pred[MAX];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j] = g[i][j]==0 ? INF : g[i][j];

    for(int i=0;i<n;i++) dist[i]=cost[s][i], pred[i]=s;

    dist[s]=0; vis[s]=1;

    for(int c=1;c<n;c++){
        int min=INF, nxt=-1;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<min) min=dist[i],nxt=i;

        vis[nxt]=1;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[nxt]+cost[nxt][i] < dist[i])
                dist[i] = dist[nxt]+cost[nxt][i], pred[i]=nxt;
    }

    for(int i=0;i<n;i++)
        if(i!=s) printf("To %d = %d\n", i+1, dist[i]);
}

int main(){
    int n,g[MAX][MAX],s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
    scanf("%d",&s);
    dijkstra(g,n,s-1);
    return 0;
}
