#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits.h>
using namespace std;

struct missile{
    int m_time;
    int m_freq;
    void show(){
        cout<<m_time<<"  "<<m_freq<<endl;
    }
};

bool sort_by_freq (const missile& x,const missile& y){
    return x.m_freq<y.m_freq;
}

bool check_eq(const missile& x,const missile& y){
    return (x.m_freq==y.m_freq)&&(x.m_time==y.m_time);
}

struct hackerX{
    int freq;
    int free_time;              //time till it can set off another missile
    hackerX(int h,int d){
        freq=h;
        free_time=d;
    }
};


bool cmp_hmissil(const hackerX* x,const hackerX* y){
    return x->freq<y->freq;
}

int main(){
    int n,i,fa;
    cin>>n;
    vector<missile> missiles(n);
    for(i=0;i<n;i++){
        cin>>missiles[i].m_time>>missiles[i].m_freq;
    }

    unique(missiles.begin(),missiles.end(),check_eq);               //remove missiles with same time and frequency.

    int hackerX_count=0;
    vector<hackerX*> h_missiles;   //set of all hacker_X missiles


    for(i=0;i<missiles.size();){
        //find missiles with this same time
        int j,count=1;
        while(((i+count)<missiles.size())&&(missiles[i].m_time==missiles[i+count].m_time))
            count++;                           //missiles with same end_time
        sort(missiles.begin()+i,missiles.begin()+i+count,sort_by_freq);            //sort those missiles by frequency.


        int cur_time=missiles[i].m_time;

        for(j=0;j<count;j++){
            //considering each missile of that time i.e missiles[i+j] having lowest frequency
            int z,best_choice=0,diff=INT_MAX;;
            int fb=missiles[i+j].m_freq;              //missile frequency
            bool no_missile=true;           //to see if you have to create new missile

            sort(h_missiles.begin(),h_missiles.end(),cmp_hmissil);
            //cout<<"sorted hacker missiles"<<endl;
            for(z=0;z<h_missiles.size();z++)
                //cout<<"freq:"<<h_missiles[z]->freq<<"  free-time:"<<h_missiles[z]->free_time<<endl;
            for(z=0;z<h_missiles.size();z++) //consider all missiles and find one which can just finish this missile
            {
                fa=h_missiles[z]->freq;
                int trans_time=abs(fb-fa);

                if(cur_time-h_missiles[z]->free_time>=trans_time-1)     //that hacker_x missile is free now
                {     
                    if(trans_time<diff)
                    {
                        diff=trans_time;
                        best_choice=z;
                    }
                    no_missile=false;
                }      
            }        

            vector<int> best_index_comp;
            for(z=0;z<h_missiles.size();z++) //consider all missiles and find one which can just finish this missile
            {
                int trans_time=abs(fb-fa);

                if(trans_time==diff)     //tie-braker two values with same difference.
                {     
                    best_index_comp.push_back(z);
                }      
            }        

            if(best_index_comp.size()==2) //settle tie breaker.
            {

            }


            if(no_missile)            //create new hacker_x
            {
                hackerX* y=new hackerX(fb,cur_time+1);
                h_missiles.push_back(y);
                hackerX_count++;
                //cout<<"new hacker missile launched at "<<cur_time<<" for frequency:"<<fb<<endl;
            }    
            else if(!no_missile)       //assign hacker_x[z] for the mission
            {
                //cout<<"missile converted"<<fb<<" from "<<h_missiles[best_choice]->freq<<endl;
                h_missiles[best_choice]->freq=fb;
                h_missiles[best_choice]->free_time=cur_time+1;      

            }   
        }         
        i+=count;
    }
    cout<<hackerX_count<<endl;

    return 0;
}
