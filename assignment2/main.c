//for now, compile with:
//mpicc main.c -o prime 
//in terminal

//prime takes an integer in the command line
#include <stdio.h>
#include <malloc.h>
#include <mpi.h>

void sieve(int *, int);
 
int main(int argc, char *argv[])
{
    int *array, *results, n;

    n=atoi(argv[1]);	//taking command line argument

    array =(int *)malloc(sizeof(int));	//allocating space for flag array
    sieve(array,n);
    return 0;
}
 
void sieve(int *a, int n)
{
    int i=0, j=0;
 	int *results, count;

 	results = (int *)malloc(sizeof(int));	//allocating space for results array

	// intially set all flags from 2 to N as 1

    for(i=2; i<=n; i++) {
        a[i] = 1;	
    }
 
    for(i=2; i<=n; i++) {	//start from 2
        if(a[i] == 1) {		//if our flag at i is 1
            for(j=i; (i*j)<=n; j++) {
                a[(i*j)] = 0;	//set multiples of i to be 0
            }
        }
    }
 	
 	count=0;

    printf("\nPrimes numbers from 1 to %d are :\n ", n);
    for(i=2; i<=n; i++) {
    	//collecting the results 
        if(a[i] == 1){
            // printf("%d, ", i);
            results[count] = i;
            printf("element %d in array results contains prime number %d. \n ",count, results[count]);	//checking to see if it worked
            count++;
    	}
    }
    printf("\n\n");


}