/* Dynamic Programming C/C++ implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>

int ceilindex(int tail[],int l,int r,int key){
    while(r-l>1)
    {
    int m=l+(r-l)/2;
    if(tail[m]>=key)
    r=m;
    else
    l=m;
    }
    return r;
}

int lis(int v[],int n){
    if(n==0)
    return 0;
    
    int tail[n];
    int length=1,i;
    tail[0]=v[0];
    
    for(i=1;i<n;i++){
        if(v[i]<tail[0])
        tail[0]=v[i];
        else if(v[i]>tail[length-1])
        tail[length++]=v[i];
        else
        tail[ceilindex(tail,-1,length-1,v[i])]=v[i];
    }
    return length;
}

int main()
{
int a[]={0,8,4,12,2,10,6,14,1,9,5,13,1,7,15};
int n=sizeof(a)/sizeof(a[0]);
printf("Longest Increasing Sub-sequence is = %d",lis(a,n));
return 0;
}
