#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Process{
	public:
	int at,bt,p;
	int ct=0,tat=0,wt=0,rt=0,st=0;
	Process(int p, int at, int bt){
		this->at=at;
		this->bt=bt;
		this->p=p;
	}
};

bool compA(const Process &a, const Process &b){ //sort based on at
        return a.at<b.at;
}

bool compB(const Process &a, const Process &b){ //sort based on bt
        return a.bt<b.bt;
}


void sjf(Process p[], int n){
	sort(p,p+n,compB);
	sort(p,p+n,compA);
	int i=0;
	int t=p[i].at;
	while(i<n){
		t+=p[i].bt;
		p[i].ct=t;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		i++;
	}
	for(int i=0;i<n;i++){
		cout<<"p"<<i<<" "<<p[i].tat<<" "<<p[i].wt<<endl;
	}
}

int main(){
	int n=3;
	Process p[]={Process(0,0,1), Process(2,5,2), Process(1,0,3)};
	sjf(p,n);
}
