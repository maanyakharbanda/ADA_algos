#include<iostream>
using namespace std;

void minmax(int arr[], int n, int i, int j, int &min, int &max){
    if(i == j){
        min = arr[i];
        max = arr[i];
        return;
    }
    if(i == j - 1){
        if(arr[i] < arr[j]){
            min = arr[i];
            max = arr[j];
        }
        else{
            min = arr[j];
            max = arr[i];
        }
        return;
    }
    int mid = (i + j) / 2;
    int min1, max1;
    minmax(arr, n, i, mid, min, max);
    minmax(arr, n, mid + 1, j, min1, max1);

    if(max < max1){
        max = max1;
    }
    if(min1 < min){
        min = min1;
    }
}

int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = n - 1;
    int min, max;
    minmax(arr, n, i, j, min, max);
    cout << "Min Element is: " << min << endl;
    cout << "Max Element is: " << max << endl;
    return 0;
}
