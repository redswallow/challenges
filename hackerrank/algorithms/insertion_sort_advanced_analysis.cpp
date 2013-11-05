#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000
long long a[MAX_N],temp[MAX_N];

long long merge(long left,long mid,long right){
    long i=left,j=mid+1,k=left;
    long long inversions=0;
    while(i<=mid && j<=right){
        if (a[i]<=a[j])
            temp[k++]=a[i++];
        else{
            temp[k++]=a[j++];
            inversions+=(mid-i+1);
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=right)
        temp[k++]=a[j++];
    for (i=left; i <= right; i++) a[i] = temp[i];
    return inversions;
}
long long merge_inversion(long left,long right){
    long long inversions=0;
    if (left<right){
        long mid=(left+right)>>1;
        inversions+=merge_inversion(left,mid);
        inversions+=merge_inversion(mid+1,right);
        inversions+=merge(left,mid,right);
    }
    return inversions;
}

int main() {
    long t,i,j,n;
    cin>>t;
    for (i=0;i<t;i++){
        cin>>n;
        for (j=0;j<n;j++) cin>>a[j];
        cout<<merge_inversion(0,n-1)<<endl;
    }
    return 0;
}

