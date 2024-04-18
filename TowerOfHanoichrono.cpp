#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
void TOH(int n,int A,int B,int C){
    if(n>0){
    TOH(n-1,A,C,B);
    // cout<<"("<<A<<","<<C<<")"<<endl;
    TOH(n-1,B,A,C);
    }
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=1;i<=10;i++){
        int t=0;
        int avg=0;
        int A=1;
        int B=2;
        int C=3;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            TOH(i,A,B,C);
            auto stop=high_resolution_clock::now();
            auto duration=duration_cast<microseconds>(stop-start);
            t+=duration.count();
        }
        avg=t/10;
        store.push_back({i,avg});
    }
}
int main(){
    vector<pair<int,int>>store;
    evaluate(store);
    cout<<"Number of inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}