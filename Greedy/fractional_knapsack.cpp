#include <bits/stdc++.h>

using namespace std;
    
class fraction {
    public:
    float ratio;
    int weight;
    int value;
};

float check(fraction e1, fraction e2) {
    return (e1.ratio > e2.ratio);
}

float maxProfit(int n, int w, int weight[], int value[]) {
    if(w==0)
        return 0.0;
    fraction* r = new fraction[n];
    for(int i = 0; i < n; i++) {
        r[i].ratio = float(value[i]) / float(weight[i]);
        r[i].value = value[i];
        r[i].weight = weight[i];
    }

    sort(r, r+n, check);

    float profit = 0;
    cout<<"Selected Items: \n";
    cout<<"Value\t"<<"Weight\n";
    for(int i = 0; i < n; i++) {
        if(r[i].weight <= w && w > 0) {
            profit += r[i].value;
            w -= r[i].weight;
            cout<<r[i].value<<"\t"<<r[i].weight<<"\n";
        }
        else {
            profit += (w/(float(r[i].weight))) * float(r[i].value);
            cout<<(w/(float(r[i].weight))) * float(r[i].value)<<"\t"<<(w/(float(r[i].weight)))<<"\n";
            break;
        }
    }

    return profit;
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int* weight = new int[n];
    int* value = new int[n];
    
    cout<<"Enter weights: ";
    for(int i = 0; i < n; i++)
        cin>>weight[i];
    
    cout<<"Enter values: "; 
    for(int i = 0; i < n; i++)
        cin>>value[i];
    
    int w; 
    cout<<"Enter maximum weight of knapsack: ";
    cin>>w;

    float profit = maxProfit(n,w,weight,value);

    cout<<"\nMaximum Profit = "<<profit;
    return 0;
}