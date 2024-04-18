#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // Adjusted size of temp array
    int index = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp[index++] = arr[left++];
        }
        else {
            temp[index++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[index++] = arr[left++];
    }
    while (right <= high) {
        temp[index++] = arr[right++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int>& arr, int low, int high) { // Pass arr by reference
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr.data(), low, mid, high); // Pass arr.data() to merge
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
            mergesort(arr, 0, i - 1); // Pass low and high indices
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
