#include<stdio.h>
int main()
{
    int i,j,k,n,fault=0;
    printf("Enter no of pages:");
    scanf("%d",&n);
    int p[n],frame[3],flag=0,count=0;
    printf("Enter page reference sequence:");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(i=0;i<3;i++)
        frame[i]=-1;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<3;j++)
        {
            if(frame[j]==p[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[count]=p[i];
            count++;
            fault++;
            if(count==3)
                count=0;
        }
    }
    printf("Number of page faults:%d",fault);
}
