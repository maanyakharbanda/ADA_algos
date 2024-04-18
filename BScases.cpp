#include<bits/stdc++.h>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int BS(int arr[],int s,int e,int key){
    if(s>e){
        return -1;
    }
    else{
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return BS(arr,s,mid-1,key);
    }
    else{
        return BS(arr,mid+1,e,key);
    }
}
}
void evaluateB(vector<pair<int,int>>&storeB){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        sort(arr.begin(),arr.end());
        int t=0;
        int avg=0;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            BS(arr.data(),0, i - 1, arr[0]);
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
        sort(arr.begin(),arr.end());
        int t=0;
        int avg=0;
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            BS(arr.data(),0, i - 1, arr[i-1]);
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
    evaluateB(storeW);
    for(auto i:storeW){
        cout<<i.first<<" "<<i.second<<endl;
    }
}



// int main(){
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     display(arr,n);
//     int key;
//     cout<<"Best Case"<<endl;
//     cout<<"Enter key i.e. the first element"<<endl;
//     cin>>key;
//     int t=0;
//     auto start=high_resolution_clock::now();
//     cout<<BS(arr,0,n,key)<<endl;
//     auto stop=high_resolution_clock::now();
//     auto duration=duration_cast<microseconds>(stop-start);
//     t+=duration.count();
//     cout<<"Time Taken For the Best Case: "<<t<<endl;
// }