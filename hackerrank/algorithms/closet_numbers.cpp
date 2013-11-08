#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n,m,i,min_distance;
    vector<long long> ar;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        ar.push_back(m);
    }
    sort(ar.begin(),ar.end());
    min_distance=20000000;
    for(i=0;i+1<ar.size();i++)
        if(ar[i+1]-ar[i]<min_distance){
            min_distance=ar[i+1]-ar[i];
        }
    for(i=0;i+1<ar.size();i++) 
        if(ar[i+1]-ar[i]==min_distance){
            cout<<ar[i]<<" "<<ar[i+1];
        }
    cout<<endl;
    return 0;
}
