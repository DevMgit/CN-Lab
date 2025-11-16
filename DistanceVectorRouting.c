#include <stdio.h>
#define MAX 10
#define INF 999

typedef struct {
    int dist[MAX], hop[MAX];
} Router;

void init(Router r[], int g[MAX][MAX], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j) r[i].dist[j]=0, r[i].hop[j]=j;
            else if(g[i][j]!=0) r[i].dist[j]=g[i][j], r[i].hop[j]=j;
            else r[i].dist[j]=INF, r[i].hop[j]=-1;
        }
}

void dv(Router r[], int n){
    int upd;
    do{
        upd=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(r[i].dist[j] > r[i].dist[k] + r[k].dist[j]){
                        r[i].dist[j] = r[i].dist[k] + r[k].dist[j];
                        r[i].hop[j] = k;
                        upd=1;
                    }
    }while(upd);
}

int main(){
    int n, g[MAX][MAX];
    Router r[MAX];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
            if(i!=j && g[i][j]==0) g[i][j]=INF;
        }

    init(r,g,n);
    dv(r,n);

    for(int i=0;i<n;i++){
        printf("\nRouter %d\n",i);
        for(int j=0;j<n;j++)
            printf("To %d: Dist=%d Hop=%d\n", j, r[i].dist[j], r[i].hop[j]);
    }
}
