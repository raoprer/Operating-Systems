#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fcfs(int p[10],int at[10],int bt[10],int ct[10],int tat[10],int wt[10],int rt[10],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(at[j]>at[j+1]){
				swap(at[j], at[j+1]); //sort at
				swap(p[j], p[j+1]); //arrange indices accordingly
			}
		}
	}
	for(int i=0;i<n;i++)
		ct[i]=0;
	int i=0;
	int t=at[0]; //start time of a process
	while(i<n){
		ct[p[i]] = t+bt[p[i]];
		tat[p[i]] = ct[p[i]]-at[i];
		wt[p[i]] = tat[p[i]]-bt[p[i]];
		cout<<p[i]<<" "<<at[i]<<" "<<bt[p[i]]<<" "<<tat[p[i]]<<" "<<wt[p[i]]<<" "<<endl;
		t+=bt[p[i]];
		i++;
	}	
}

int main(){
	int n=3;
	int p[n];
	for(int i=0;i<n;i++)
		p[i]=i;
	int at[n]={0,2,1};
	int bt[n]={2,3,1};
	int ct[n],tat[n],wt[n],rt[n];
	cout<<"p at bt tat wt"<<endl;
	fcfs(p,at,bt,ct,tat,wt,rt,n);
}
