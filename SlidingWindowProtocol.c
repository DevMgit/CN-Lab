#include<stdio.h>

void main()
{
    int n,frame[100],ack,ch,i;
    printf("Enter The Frame size : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        frame[i]=i+1;
        printf("Frame %d sent data : %d\n",i,frame[i]);
    }
    printf("\nEnter the frame whose acknowledgemet is not recieved : ");
    scanf("%d",&ack);
    printf("\nEnter 1 for GO Back N\nEnter 2 for Selective Repeat\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nGO Back N\n");
        printf("Frames sent again : \n");
        for(int i=ack;i<n;i++)
        {
            printf("Frame %d sent data : %d\n",i,frame[i]);
        }
    }
    if(ch==2)
    {
        printf("\nSelective Repeat Protocol\n");
        printf("Frame sent again : \n");
        printf("Frame %d sent data : %d\n",ack,frame[ack]);
    }
}
