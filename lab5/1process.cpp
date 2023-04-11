#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main(){
	pid_t id;
	id = fork();
	if(id==0){
		cout<<"In child "<<getpid()<<" "<<getppid()<<endl;
		return 1;
	}
	else if(id>0){
		cout<<"In parent ";
		id = wait(NULL);
		cout<<getpid()<<" " <<getppid()<<endl;
	}
	else
		cout<<"Error";
}
