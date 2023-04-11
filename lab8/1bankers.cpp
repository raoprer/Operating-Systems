#include<iostream>
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int p=5,r=3;
	int alloc[p][r] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int max[p][r] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int tot[r] = {10,5,7};
	int avail[r]={0};
	int rneed[p][r];
	
	for(int i=0;i<r;i++){
		for(int j=0;j<p;j++)
			avail[i]+=alloc[j][i];
	}
	
	for(int i=0;i<r;i++)
		avail[i]=tot[i]-avail[i];
	
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			rneed[i][j]=max[i][j]-alloc[i][j];
		}
	}
	
	int counter = 0;
	
	bool f[p];
	for(int i=0;i<p;i++)
		f[i]=true;
	while(counter!=3){
		for(int i=0;i<p;i++){
			if(counter==0 || !f[i]){
				f[i]=true;
				for(int j=0;j<r;j++){
					if(avail[j]<rneed[i][j]){
						f[i]=false;
						break;
					}
				}
				if(f[i]){ //process[i] completed
					cout<<"P"<<i<<" ";
					for(int j=0;j<r;j++){
						avail[j]+=alloc[i][j];
						alloc[i][j]=0;
						rneed[i][j]=0;
					}
				}
			}
		}
		counter++;
	}
	
	for(int i=0;i<p;i++){
		if(!f[i]){
			cout<<"\nNot safe"<<endl;
			exit(0);
		}
	}
	cout<<"\nSafe"<<endl;
	return 0;
}
