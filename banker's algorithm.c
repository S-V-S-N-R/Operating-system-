
#include<stdio.h>
void main()
{ 
    int n, m, i, j, k, alloc[20][20], max[20][20], available[20];
    int f[20],ans[20], ind=0, need[20][20]; //We need the Need matrix.
    
   
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
   
    printf("Enter the number of Resources: ");
    scanf("%d",&m);
   
   
    printf("Enter the Values of Allocation Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&alloc[i][j]);
        }
    }
    
  
        printf("Enter the Values of Max Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
    }
    
   
    printf("Enter the values in available: \n");
    for(j=0;j<m;j++)
    {
        printf("Enter value at position (%d) :",j+1);
        scanf("%d",&available[j]);
    }
    
    
    for(k=0;k<n;k++)
    {
        f[k]=0;
    }
    
   
    for(i=0;i<n;i++)  
    {
        for(j=0;j<m;j++)   
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    //Finding safe sequence
    int y=0;

    for(k=0;k<n;k++)    
    {
        for(i=0;i<n;i++)    
        {
            if(f[i]==0)     
            {
                int flag = 0;   
                for(j=0;j<m;j++)  
                {
                    if(need[i][j] > available[j])    
                    {
                        flag=1; //Setting flag as true or 1.
                        //flag=1 means the Need is greater than what is Available for that particular resource.
                        break; //Breaking out of this loop if need > available
                    }
                }
                
                if(flag==0)
                {
                    ans[ind++] = i;
                    for(y=0;y<m;y++)    //For each Resource
                    {
                        available[y] = available[y] + alloc[i][y];  //Setting availability to current availability + allocation 
                    }
                    f[i]=1; //Declaring the current process as FINISHED.
                }
            }
        }
    }
    
   //Displaying the SAFE SEQUENCE.
    printf("The SAFE SEQUENCE is: \n");
    for(i=0;i<n-1;i++)  //Here loop ends at n-1 because we don't want to printf the arrowmark(->) at the end.printf(" P%d", answer[n-1)
    {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d", ans[n-1]);    //Printing the final state in safe sequence without printing the arrowmark.

}

