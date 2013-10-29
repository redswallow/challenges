#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long int n,k,m,i,theta,min_unfairness=0,temp_unfairness,s=0;
    vector<long int> ar,sar;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>m;
        ar.push_back(m);
    }
    //sort
    sort(ar.begin(),ar.end());
    //count sum array
    for(i=0;i<n;i++){
        sar.push_back(s+=ar[i]);
    }
    //calcuate the first unfairness
    theta=-k+1;
    for(i=0;i<k;i++){
        min_unfairness+=ar[i]*theta;
        theta+=2;
    }
    temp_unfairness=min_unfairness;
    cout<<temp_unfairness<<endl;
    //find min_unfairness   
    for(i=1;i+k-1<ar.size();i++){ 
        temp_unfairness+=+(k-1)*(ar[i+k-1]+ar[i-1])-2*(sar[i+k-2]-sar[i-1]);
        cout<<temp_unfairness<<endl;
        if(temp_unfairness<min_unfairness){
            min_unfairness=temp_unfairness;
        }
    }
    cout<<min_unfairness<<endl;
    return 0;
}

