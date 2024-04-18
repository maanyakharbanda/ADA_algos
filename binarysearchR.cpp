#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
bool BS(int arr[], int s, int e, int key) {
    if (s > e) {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) {
        return true;
    }
    else if (arr[mid] < key) {
        return BS(arr, mid + 1, e, key);
    }
    else {
        return BS(arr, s, mid - 1, key);
    }
}
void evaluateB(vector<pair<int, int>>& storeB) {
    for (int i = 10; i <= 10000; i += 1000) {
        vector<int> arr(i);
        generate(arr.begin(), arr.end(), rand);
        sort(arr.begin(), arr.end());
        int t = 0;
        int avg = 0;
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            BS(arr.data(), 0, i - 1, arr[0]);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 10;
        storeB.push_back({ i, avg });
    }
}
void evaluateW(vector<pair<int, int>>& storeW) {
    for (int i = 10; i <= 10000; i += 1000) {
        vector<int> arr(i);
        generate(arr.begin(), arr.end(), rand);
        sort(arr.begin(), arr.end());
        int t = 0;
        int avg = 0;
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            BS(arr.data(), 0, i - 1, arr[i - 1]);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 10;
        storeW.push_back({ i, avg });
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
int main() {
    vector<pair<int, int>> storeB;
    cout << "For the best case" << endl;
    evaluateB(storeB);
    for (auto i : storeB) {
        cout << i.first << " " << i.second << endl;
    }
    vector<pair<int, int>> storeW;
    cout << "For the worst case" << endl;
    evaluateW(storeW);
    for (auto i : storeW) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}

// #include<bits/stdc++.h>
// #include<ctime>
// #include<vector>
// using namespace std;
// bool binary_search(int arr[],int s,int e,int key){
//         if(s>e){
//             return false;
//         }
//         int mid=s+(e-s)/2;
//         if(arr[mid]==key){
//             return true;;
//         }
//         else if(arr[mid]<key){
//             return binary_search(arr,mid+1,e,key);
//         }
//         else{
//             return binary_search(arr,s,mid-1,key);
//         }
// }
// void input_generator(vector<pair<int,int>>&store){
//     for(int i=10;i<1e4;i+=1000){
//         vector<int>arr(i);
//         generate(arr.begin(),arr.end(),rand);
//         sort(arr.begin(),arr.end());
//         clock_t time_req;
//         int t=0;
//         for(int m=0;m<10;m++){
//             time_req=clock();
//             binary_search(arr.data(),0, i - 1, arr[rand() % i]);
//             time_req=clock()-time_req;
//             t+=time_req;
//         }
//         t=t/10;
//         store.push_back({i,t});
//     }
// }
// int main(){
//     vector<pair<int,int>>store;
//     input_generator(store);
//     cout<<"Number of Inputs"<<"  "<<"Time"<<endl;
//     for(auto i:store){
//         cout<<i.first<<"  "<<i.second<<endl;
//     }
// return 0;
// }