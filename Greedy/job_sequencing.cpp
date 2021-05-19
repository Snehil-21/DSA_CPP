#include <iostream>
#include <algorithm>
using namespace std;

class Job {
    public:
    char title;
    int deadline;
    int profit;
};

int job_sequence(Job jobs[], int n) {
    bool free_slot[n];
    
    for(int i=0; i<n; i++)
        free_slot[i] = true;
    
    int final_seq[n];
    int max_profit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if(free_slot[j] == true) {
                free_slot[j] = false;
                final_seq[j] = i;
                break;
            }
        }
    }

    cout<<"Final sequence of jobs selection:\n";
    for(int i = 0; i < n; i++) {
        if(free_slot[i] == false) {
            max_profit += jobs[final_seq[i]].profit;
            cout<<jobs[final_seq[i]].title<<" ";
        }
    }

    return max_profit;
}

int check(Job j1, Job j2) {
    return (j1.profit > j2.profit);
}

int main() {
    cout<<"Enter number of jobs: ";
    int n; cin>>n;
   
    Job* jobs = new Job[n];
   
    cout<<"Enter job title, deadline, and profit separated by space for jobs\n";
    for(int i = 0; i < n; i++) {
        int d,p; char t; cin>>t>>d>>p;
        jobs[i].title = t;
        jobs[i].deadline = d;
        jobs[i].profit = p;
    }

    sort(jobs, jobs+n, check);

    int profit = job_sequence(jobs, n);
    cout<<"\nMaximum profit = "<<profit;
    
    return 0;
}