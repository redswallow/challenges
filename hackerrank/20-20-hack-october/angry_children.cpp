#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k,m,i,min_unfairness;
    vector<int> ar;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>m;
        ar.push_back(m);
    }
    sort(ar.begin(),ar.end());
    min_unfairness=*max_element(ar.begin(),ar.end());
    for(i=0;i+k-1<ar.size();i++){ 
        if(ar[i+k-1]-ar[i]<min_unfairness){
            min_unfairness=ar[i+k-1]-ar[i];
        }
    }
    cout<<min_unfairness<<endl;
    return 0;
}
