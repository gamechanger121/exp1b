#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int *a,int n)
{
    FILE * ptr2 =NULL;
    ptr2 = fopen("insertion.txt","a");
    for(int i = 0 ; i < n ; i++)
    {
        fprintf(ptr2,"%d ",a[i]);
    }
    fprintf(ptr2,"\n");
    fclose(ptr2);
}

void InsertionSort(int *a, int n)
{
    int key,j;
    for(int i = 0; i < n; i++)
    {
        key = a[i];
        j = i-1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j -- ; // j will get reset to 0 or it will run till j become 0
        }
        a[j+1] = key;
    }
}

int main()
{
    srand(time(0));
    FILE * ptr2 = NULL;
    FILE * ptr3 = NULL;
    ptr2 = fopen("insertion.txt","a");
    ptr3 = fopen("insertion.csv","a");
    int n ;
    int *a;
    // printf("Enter the size of array\n"); //THis is dynamic allocation array 
    // scanf("%d",&n);
    a = (int *) malloc(n * sizeof(int));
    for(n=0 ; n <=100000;n = n+100)
    {
        for(int i = 0; i < n ; i++)
        {
            int rando = rand() % n;
            a[i] = rando;
            rando;        
        }
        printf("For %d\n",n);
        int ticks = clock();
        fprintf(ptr3,"%f\n",(float)ticks / CLOCKS_PER_SEC); 
    }
    InsertionSort(a,n);
    printArray(a,n);
    fclose(ptr2);
    fclose(ptr3);
    return 0;
}