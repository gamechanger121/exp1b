#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b) //Swapping of element is happpening 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *a,int n) //for traversing the array 
{    
    FILE * ptr = NULL;
    ptr = fopen("selection.txt","a");
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr,"%d ",a[i]);
    }
    fprintf(ptr,"\n");
    fclose(ptr);
    
}

void SelectionSort(int *a,int n)  // This is for selection sort 
{
    int indexOfmin;
    for(int i = 0 ; i < n - 1; i++) //This is for treaversing element from index 0 
    // Here i am doing n-1 because at worst it will get sorted in n-1  passes;
    // where n is no of the array 
    {
        indexOfmin = i; //index of min will start from index 0 

        for(int j = i + 1; j < n; j++)  //And now it will check from 0+1 = 1; and also after one index is done it will increament by one 
        {
            if (a[indexOfmin] > a[j])
            {
                indexOfmin = j;
            }
        }
        swap(&a[i],&a[indexOfmin]);
    }
}

int main()
{
    srand(time(0));
    FILE * ptr = NULL;
    FILE * ptr1 = NULL;
    ptr = fopen("selection.txt","a");
    ptr1 = fopen("selection.csv","a");

    int n;
    int *a;
    // printf("Enter the size of array\n"); //THis is dynamic allocation array 
    // scanf("%d",&n);
    a = (int *) malloc(n * sizeof(int));

    for(n = 0 ; n <= 100000; n = n+100)
    {
        for(int i = 0; i < n ; i++)
        {
            int rando = rand() % n;
            a[i] = rando;
            rando;

        } 
        printf("For %d\n",n);
        int ticks = clock();
        fprintf(ptr1,"%f\n",(float)ticks / CLOCKS_PER_SEC);
    }

    SelectionSort(a,n);
    printArray(a,n);
    fclose(ptr);
    fclose(ptr1);
}