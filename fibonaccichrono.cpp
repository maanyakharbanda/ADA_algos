#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
int fibonacci(int n){
    if(n==0||n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=1;i<30;i+=2){
        int t=0;
        int avg=0;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            fibonacci(i);
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
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}