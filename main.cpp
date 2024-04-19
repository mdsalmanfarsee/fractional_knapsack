#include <iostream>
#include<algorithm>
using namespace std;


struct Item{
    int weight;
    int value;
};
bool compare(Item a,Item b)
{
    double ratio1=(double)a.value/a.weight;
    double ratio2=(double)b.value/b.weight;
    return ratio1>ratio2;
}

double fractional_knapsack(Item arr[],int n,int capacity)
{
    //sort the array accoring to value/unit
    sort(arr,arr+n,compare);
    double totalvalue=0.0;
    int currentweight=0;
    
    for(int i=0; i<n; i++)
    {
        if(currentweight+arr[i].weight <= capacity)
        {
            currentweight+=arr[i].weight;
            totalvalue+=arr[i].value;
        }
        else
        {
            int remainingweight=capacity-currentweight;
            totalvalue+=((double)arr[i].value/arr[i].weight)*remainingweight;
            break;
        }
    }
    
    return totalvalue;
}

int main() {
    
    int capacity=50;
    Item arr[]={{10,60},{20,100},{30,120}};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"maximum value can be : "<<fractional_knapsack(arr,n,capacity);
    
    return 0;
}
