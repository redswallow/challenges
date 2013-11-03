#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int i,t;
    long long k;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>k;
        if(k%2==0){
            cout<<(k/2)*(k/2)<<endl;
        }else{
            cout<<(k/2)*(k/2+1)<<endl;
        }
    }
    return 0;
}

