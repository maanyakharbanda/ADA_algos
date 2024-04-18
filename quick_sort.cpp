#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
    while(arr[i]<=pivot && i<=high-1){
        i++;
    }
    while(arr[j]>pivot && j>=low+1){
        j--;
    }
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(vector<int>&arr,int low,int high){
    if(low>=high){
        return;
    }
    else{
    int p_index=partition(arr,low,high);
    quicksort(arr,low,p_index-1);
    quicksort(arr,p_index+1,high);
    }
}
void random_generator(vector<int>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}

void evaluate(vector<pair<int, int>>& store) {
    for (int i = 10; i < 1e4; i += 1000) {
        vector<int> arr(i);
        int t = 0;
        for (int m = 0; m < 10; m++) {
            random_generator(arr, i);
            auto start = high_resolution_clock::now();
            quicksort(arr, 0, i - 1); // Pass low and high indices
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        int avg = t / 10;
        store.push_back({i, avg});
    }
}

int main() {
    vector<pair<int, int>> store;
    evaluate(store);
    cout << "Number of Inputs" << " " << "Time" << endl;
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
