/* Dynamic Programming C/C++ implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>

int ceilindex(int input[], int T[], int end, int s){
        int start = 0;
        int middle;
        int len = end;
        while(start <= end){
            middle = (start + end)/2;
            if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
                return middle+1;
            }else if(input[T[middle]] < s){
                start = middle+1;
            }else{
                end = middle-1;
            }
        }
        return -1;
    }
int lis(int v[],int n){
    int T[n];
    int R[n];
    for(int i=0; i < n ; i++) {
        R[i] = -1;
    }
    T[0] = 0;
    int len = 0;
    for(int i=1; i < n; i++){
        if(v[T[0]] > v[i]){ //if input[i] is less than 0th value of T then replace it there.
            T[0] = i;
        }else if(v[T[len]] < v[i]){ //if input[i] is greater than last value of T then append it in T
            len++;
            T[len] = i;
            R[T[len]] = T[len-1];
        }else{ //do a binary search to find ceiling of input[i] and put it there.
            int index = ceilindex(v, T, len,v[i]);
            T[index] = i;
            R[T[index]] = T[index-1];
        }
    }
    int final[len+1],j=len;
    int index = T[len];
        while(index != -1) {
            //printf("%d ",v[index] );
            final[j]=v[index];
            j--;
            index = R[index];
        }
        

    for(int i=0; i < len+1; i++){
        printf("%d ",final[i]);
    }
    printf("\n");
    return len+1;
}

int main()
{
int a[]={0,8,4,12,2,10,6,14,1,9,5,13,1,7,15};
int n=sizeof(a)/sizeof(a[0]);
printf("Longest Increasing Sub-sequence is = %d",lis(a,n));
return 0;
}
