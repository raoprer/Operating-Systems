//Program to implement Schdeduling Algorithms
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/wait.h>   
#include <unistd.h>     
using namespace std;

typedef struct{
    int pid;
    int arrival_time;
    int burst_time;
    int rem_time;
    int priority;
}Process;


Process* Entry(){
    cout<<"Enter the number of processes:";
    int n;
    cin>>n;
    Process* p = new Process[n+1];
    cout<<"Enter PID, arrival, burst, Priority\n";
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<": ";
        cin>>p[i].pid>>p[i].arrival_time>>p[i].burst_time>>p[i].priority;
        p[i].rem_time=p[i].burst_time;
    }
    p[n].pid=-1;
    return p;
}


int min(Process *p, int n, int timer){
    int min_time=9999;
    int min=-1;
    for(int i=0;i<n;i++){
        if(p[i].arrival_time<=timer && p[i].rem_time>0 && p[i].burst_time<min_time){
            min_time=p[i].burst_time;
            min=i;
        }
    }
    return min;
}

void SJF(){
    Process* p =Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int timer=0;
    float TAT=0;
    float WAT=0;
    int done=0;
    while(done!=n){
        int i = min(p,n,timer);
        int start=timer;
        int j=i;
        int ran = p[i].rem_time;
        while(j==i){
            timer++;
            p[i].rem_time--;
            j=min(p,n,timer);
        }
        cout<<p[i].pid<<" < "<<start<<" "<< timer<<" >"<<endl;
        if(p[i].rem_time==0){
            TAT+=(timer-p[i].arrival_time);
            WAT+=(timer-p[i].arrival_time-p[i].burst_time);       
            done++;
        }
    }
    TAT=TAT/n;
    WAT=WAT/n;
    cout<<"Turnaround Time = "<<TAT<<" ms \n";
    cout<<"Waiting Time = "<<WAT<<" ms\n\n\n";
}

void RR(){
    Process* p = Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    int q;
    cout<<"Enter time slice:";
    cin>>q;
    int timer=0;
    int done=0;
    float TAT=0;
    float WAT=0;
    while(done!=n){
        for(int i=0;i<n;i++){
            int count=q;
            int start=timer;
            while(p[i].rem_time>0 && p[i].arrival_time<=timer && count>0){
                timer++;
                p[i].rem_time--;
                count--;
            }
            if(start!=timer){
                cout<<p[i].pid<<" < "<<start<<" "<<timer<<" >\n";
                if(p[i].rem_time==0){
                    TAT+=(timer-p[i].arrival_time);
                    WAT+=(timer-p[i].arrival_time-p[i].burst_time);
                    done++;
                }
            }
        }
    }
    TAT=TAT/n;
    WAT=WAT/n;
    cout<<"Turnaround Time = "<<TAT<<" ms \n";
    cout<<"Waiting Time = "<<WAT<<" ms\n\n\n";
}

int comparator(const void* p, const void* q) { 
    return ((Process*)p)->arrival_time > ((Process*)q)->arrival_time && ((Process*)p)->priority > ((Process*)q)->priority;
}

void Prior(){
    Process* p =Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    qsort(p, n, sizeof(Process), comparator);
    int timer=0;
    float TAT=0;
    float WAT=0;
    for(int i=0;i<n;i++){
        WAT+=(timer-p[i].arrival_time);
        cout<<p[i].pid<<" < "<<timer<<" "<<timer+p[i].burst_time<<" >\n";
        timer+=p[i].burst_time;
        TAT+=(timer-p[i].arrival_time);
    }
    TAT=TAT/n;
    WAT=WAT/n;
    cout<<"Turnaround Time = "<<TAT<<" ms \n";
    cout<<"Waiting Time = "<<WAT<<" ms\n\n\n";
}

int main(){
    int ch;
    while(1){
        cout<<"1. Preemptive SJF\n";
        cout<<"2. Round Robin Scheduling\n";
        cout<<"3. Priority Scheduling\n";
        cout<<"-1 to Exit\n";
        cin>>ch;
        switch(ch){
            case 1:
                SJF();
                break;
            case 2:
                RR();
                break;
            case 3:
                Prior();
                break;
            case -1:
                exit(1);
            default:
                cout<<"Invalid Entry\n";
        }
    }
}

