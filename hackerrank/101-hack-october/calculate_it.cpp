#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hrank(int k,int x){
    if (x<k && x>=0) return 1;
    if (x>=k && x%k==0) return hrank(k,x-k)+hrank(k,x/k);
    return hrank(k,x-1);
}
int main() {
    int k,x;
    cin>>k>>x;
    cout<<hrank(k,x)<<endl;
    return 0;
}

