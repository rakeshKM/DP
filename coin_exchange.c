#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int count( int S[], int m, int n ){
	int table[n+1];
    int i,j,seq[n+1];
	memset(table, 0, sizeof(table));
	table[0] = 1;
	// Pick all coins one by one and update the table[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for(i=0; i<m; i++)
		for(j=S[i]; j<=n; j++){
			table[j] += table[j-S[i]];
			seq[i] = j;
		}
		
	//cout<<"Coins: ";
    j = n;
    while(j)
    {
        printf(" %d ", table[seq[j]] );
        j = j - table[seq[j]];
    }
    
    
	return table[n];
}


// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf("hi");
    int x=count(arr, m, n);
    //printf(" %d ", count(arr, m, n));
    return 0;
}
