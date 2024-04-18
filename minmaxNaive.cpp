#include<iostream>
using namespace std;
void minmax(int arr[],int n){
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Min element is: "<<min<<endl;
    cout<<"Max element is: "<<max<<endl;
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    minmax(arr,n);
}