#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int n, string s[]){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(s[j]>s[j+1]){
				swap(s[j],s[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<s[i]<<" ";
	cout<<endl;
}

int main(){
	int n;
	cout<<"Enter the number of strings: ";
	cin>>n;
	string s[n];
	cout<<"Enter "<<n<<" strings: "<<endl;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		s[i]=str;
	}
	pid_t id;
	id = fork();
	if(id==0){
		cout<<"Inside 1st child"<<endl;
		cout<<"Bubble sort: ";
		bubbleSort(n, s);
	}
	else if(id>0){
		id = fork();
		if(id==0){
			cout<<"Inside 2nd child"<<endl;
			cout<<"Intro sort: ";
			vector<string> v;
			for(int i=0;i<n;i++)
				v.push_back(s[i]);
			sort(v.begin(), v.end());
			for(auto i: v)
				cout<<i<<" ";
			cout<<endl;
		}
		else if(id>0){
			id = wait(NULL);
			cout<<"Inside parent"<<endl;
			cout<<"Unsorted: ";
			for(int i=1;i<n;i++)
				cout<<s[i]<<" ";
			cout<<endl;
		}
		else
			cout<<"Error"<<endl;
	}
}
