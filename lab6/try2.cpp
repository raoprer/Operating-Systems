#include <iostream>
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/wait.h>   
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
//not working

bool compA(const Process &a, Process const &b){
        return a.at<b.at;
}

class Process{
	public:
	int pid, at, bt, rt, pri;
	void Process(int pid, int at, int bt, int pri){
		this->pid = pid;
		this->at = at;
		this->bt = bt;
		this->pri = pri;
		this->rt =  bt;
	}
};

void SJF(process p[], int n){
	queue<Process> rq;
	int cpu;
	int t = 0, ts = 0;
	cpu = 0;
	int i = 0;
	while(true){
		i++;
		if(p[i].at == t){
			if(p[cpu].bt > p[i].at){
				if(p[cpu].rt!=0){
					q.push(p[cpu]);
					cout<<"P"<<p[cpu].pid<<" < "<<ts<<" , "<<t<<" > "<<endl;
				}
				cpu = i;
				ts = t;
			}
		}
		p[cpu].rt--;
		t++;
		if(i==n && q.empty())
			break;
	}
}

int main(){
	int n = 3;
	Process p[] = { Process(1,0,3,1), Process(2,2,3,2), Process(3,4,2,3) };
	sort(p, p+n, compA);
	SJF(p, n)
}
