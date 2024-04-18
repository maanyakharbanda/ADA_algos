#include<bits/stdc++.h>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int LS(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  // Return the index if the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}
void evaluateB(vector<pair<int,int>>&storeB){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        int t=0;
        int avg=0;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            LS(arr.data(),i,arr[0]);
            auto stop=high_resolution_clock::now();
            auto duration=duration_cast<microseconds>(stop-start);
            t+=duration.count();
        }
        avg=t/10;
        storeB.push_back({i,avg});
    }
}
void evaluateW(vector<pair<int,int>>&storeW){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        int t=0;
        int avg=0;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            LS(arr.data(),i,arr[i-1]);
            auto stop=high_resolution_clock::now();
            auto duration=duration_cast<microseconds>(stop-start);
            t+=duration.count();
        }
        avg=t/10;
        storeW.push_back({i,avg});
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    vector<pair<int,int>>storeB;
    cout<<"For the best case"<<endl;
    evaluateB(storeB);
    for(auto i:storeB){
        cout<<i.first<<" "<<i.second<<endl;
    }
    vector<pair<int,int>>storeW;
    cout<<"For the worst case"<<endl;
    evaluateW(storeW);
    for(auto i:storeW){
        cout<<i.first<<" "<<i.second<<endl;
    }
}