#include<bits/stdc++.h>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    else{
        return a*power(a,b-1);
    }
}
void evaluate(vector<pair<int,int>>&store){
    int t=0;
    int avg=0;
    for(int i=1000;i<=10000 ;i=i+1000)
    {
    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        int p = power(2,i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start));
    t+=duration.count();
    avg=t/10;
    store.push_back({i,avg});
    }
}
int main(){
    // int a;
    // int b;
    // cout<<"Enter a and b"<<endl;
    // cin>>a>>b;
    // cout<<"Answer is: "<<power(a,b)<<endl;
    vector<pair<int,int>>store;
    evaluate(store);
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}