#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;
//not working

bool compA(const Process &a, Process const &b){
        return a.at<b.at;
}

bool compB(const Process &a, const Process &b){
	return a.bt<b.bt;
}

class Process{
	int pid, bt, ct, tat, wt, rt;
	public:
		int at, st=0;
		Process(int pid, int at, int bt){
			this->pid = pid;
			this->at = at;
			this->bt = bt;
		}
		
		void FCFS(Process p[], int n){
			int st = 0;
			cout<<"FCFS: "<<endl;
			for(int i=0;i<n;i++){
				p[i].tat = p[i].wt = p[i].rt = 0;
				p[i].ct=st+p[i].bt;
				p[i].tat=p[i].ct-p[i].at;
				p[i].wt=p[i].tat-p[i].bt;
				p[i].rt=st-p[i].at;	
				cout<<p[i].pid<<" < "<<p[i].at<<" , "<<p[i].bt<<" , "<<p[i].ct<<" , ";
				cout<<p[i].tat<<" , "<<p[i].wt<<" , "<<p[i].rt<<" >"<<endl;
				st+=p[i].bt;
			}
		}
		
		void SJF_np(Process p[], int n){
			int st = 0;
                        cout<<"SJF non-preemptive: "<<endl;
			for(int i=0;i<n;i++){
				int j;
				for(j=i-1;j<n-1;j++){
					for(int k=j+1;k<n-j-2;k++){
						if(p[k].at<p[k+1].at) break;
						if(p[k].bt>p[k+1].bt)
							swap(p[k], p[k+1]);
					}
				}
				i=j;
			}
                        for(int i=0;i<n;i++){
                                p[i].tat = p[i].wt = p[i].rt = 0;
                                p[i].ct=st+p[i].bt;
                                p[i].tat=p[i].ct-p[i].at;
                                p[i].wt=p[i].tat-p[i].bt;
                                p[i].rt=st-p[i].at;
                                cout<<p[i].pid<<" < "<<p[i].at<<" , "<<p[i].bt<<" , "<<p[i].ct<<" , ";
                                cout<<p[i].tat<<" , "<<p[i].wt<<" , "<<p[i].rt<<" >"<<endl;
                                st+=p[i].bt;
                        }
		}

		void SJF_p(Process p[], int n){
			queue<Process> ready;
                        cout<<"SJF preemptive: "<<endl;
			for(int i=0;i<n;i++){
                                int j;
                                for(j=i-1;j<n-1;j++){
                                        for(int k=j+1;k<n-j-2;k++){
                                                if(p[k].at<p[k+1].at) break;
                                                if(p[k].bt>p[k+1].bt)
                                                        swap(p[k], p[k+1]);
                                        }
                                }
                                i=j;
                        }
			vector<Process> v;
                        int started[n] = {0};
			Process* cpu;
                        started[0]=1;
			cpu=&p[0];
			for(int j=1;j<n;j++){
				cpu->bt--;
				if(p[j].bt<cpu->bt){
					v.push_back(*cpu);
					cpu = &p[j];	
				}
				else{
					v.push_back(p[j]);
					}
					sort(v.begin(), v.end(), compB);
					if(cpu->bt == 0){
						cpu = &(v.begin());
						v.erase(v.begin());
					}
				}
			for(int i=0;i<n;i++){
				p[i].tat = p[i].wt = p[i].rt = 0;
                                p[i].tat=p[i].ct-p[i].at;
                                p[i].wt=p[i].tat-p[i].bt;
                                p[i].rt=st[i]-p[i].at;
				cout<<p[i].pid<<" < "<<p[i].at<<" , "<<p[i].bt<<" , "<<p[i].ct<<" , ";
                                cout<<p[i].tat<<" , "<<p[i].wt<<" , "<<p[i].rt<<" >"<<endl;
                        }

		}	
};

int main(){
	int n = 3;
	Process p[] = { Process(1,0,3), Process(2,2,3), Process(3,4,2) };

	sort(p, p+n, compA);
	//cout<<p[0].at;cout<<p[1].at;cout<<p[2].at;
	p[0].FCFS(p, n);
	p[0].SJF_np(p,n);
	p[0].SJF_p(p, n);
}
