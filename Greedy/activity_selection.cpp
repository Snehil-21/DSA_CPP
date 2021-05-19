#include <bits/stdc++.h>
using namespace std;

class Activity {
    public: 
    int start;
    int finish;
};

int check(Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

void select_activities(Activity a[], int n) {
    cout<<0<<" ";
    int prev_selected = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].start >= a[prev_selected].finish) {
            cout<<i<<" ";
            prev_selected = i;
        }
    }
}

int main() {
    cout<<"Enter number of activities: ";
    int n; cin>>n;
    Activity* a = new Activity[n];
    cout<<"Enter activities with start and finish time separated by space:\n";
    for(int i = 0; i < n; i++) {
        int s,f; cin>>s>>f;
        a[i].start = s;
        a[i].finish = f;
    }

    sort(a, a+n, check);
    cout<<"Selected Activities are:\n";
    select_activities(a, n);
    return 0;
}