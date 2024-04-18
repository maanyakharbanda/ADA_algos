#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct item{
int weight;
int value;
};

static bool cmp(item a,item b)
{
    return a.weight<b.weight;
}

double profit_knapsack(int W,item arr[],int n)
{
    vector<item>v(arr,arr+n);

    sort(v.begin(),v.end(),cmp);

    double totalvalue = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].weight > W)
        {
            totalvalue += (1.0*W/v[i].weight)*v[i].value;
            break;
        }
        else
        {
            totalvalue += v[i].value;
            W = W - v[i].weight;
        }
    }
    return totalvalue;
}


int main()
{
    item arr[5];
    arr[0].weight=1;
    arr[1].weight=2;
    arr[2].weight=2;
    arr[3].weight=3;
    arr[4].weight=3;
    arr[0].value=15;
    arr[1].value=3;
    arr[2].value=2;
    arr[3].value=6;
    arr[4].value=8;
    double val = profit_knapsack(10,arr,5);
    cout << val << endl;
    return 0;
}