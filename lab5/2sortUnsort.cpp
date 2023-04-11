#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
	pid_t id;
	if(fork()==0){
		vector<string> v;
		for(int i=1;i<argc;i++)
			v.push_back(argv[i]);
		sort(v.begin(), v.end());
		cout<<"Child: ";
		for(auto i: v)
			cout<<i<<" ";
		cout<<endl;
	}
	else if(fork()>0){
		id = wait(NULL);
		cout<<"Parent: ";
		for(int i=1;i<argc;i++)
			cout<<argv[i]<<" ";
		cout<<endl;
	}
}
