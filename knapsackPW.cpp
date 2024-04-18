#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct item{
int weight;
int value;
};
static bool cmp(pair<double,item>a,pair<double,item>b)
{
    return a.first>b.first;
}

double fractional_knapsack(int W,item arr[],int n)
{
    vector<pair<double,item>>v;
    for(int i=0;i<n;i++)
    {
        double perunitvalue= (1.0*arr[i].value)/arr[i].weight;
        pair<double,item>p = make_pair(perunitvalue,arr[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    double totalvalue = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second.weight > W)
        {
            totalvalue += W*v[i].first;
            W = 0;
        }
        else
        {
            totalvalue += v[i].second.value;
            W = W - v[i].second.weight;
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
    double val = fractional_knapsack(50,arr,5);
    cout << val << endl;
    return 0;
}