#include <stdio.h>
#define N 10

int main() {
    int p[N], bs, rate, rem = 0;
    printf("Enter output rate: "); scanf("%d", &rate);
    printf("Enter bucket size: "); scanf("%d", &bs);

    for(int i=0;i<N;i++) p[i]=(rand()%5+1)*10;

    for(int i=0;i<N;i++){
        if(p[i] > bs) { printf("Pkt %d rejected\n", p[i]); continue; }
        if(rem + p[i] > bs) { printf("Overflow! Dropped\n"); continue; }

        rem += p[i];
        printf("Added %d | Rem = %d\n", p[i], rem);

        while(rem > 0){
            int send = rem < rate ? rem : rate;
            rem -= send;
            printf("Sent %d | Rem = %d\n", send, rem);
        }
    }
    return 0;
}
