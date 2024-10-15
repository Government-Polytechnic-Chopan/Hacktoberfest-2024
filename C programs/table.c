//This program is write table of given no by user//
#include<stdio.h>
int main()
{
    printf("Enter that no which table you want to print ");
    
    int n,i,t; /*Here n is numer to given by user, 
                i is ues for calculation and t use for last variable to print the table*/
 
    scanf("%d",& n);
       printf("Table of- %d\n",n);
    for(i=1; i<=10; i++)
    {
        t=n*i;
              
       printf("%d*%d= %d\n",n,i,t);
    }
    
    return 0;
}
