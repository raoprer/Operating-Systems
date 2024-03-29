//  parall reduciton (can be sum, max, min or any associate operation) pattern using Pthreads
#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//used for synchronization
pthread_mutex_t lock;

//global variable visible to all threads
int sum = 0;

// Define the max threads as X per the cores in your system
#define MAX_THREADS  4

// Array
#define ARRAY_SIZE 1000
int arr[ARRAY_SIZE];

//Define a large array of random numbers as per the input from user


// Function to find the sum of large array with the a thread, pass the min and maximum index so that the thread can handle only that data.  Find the local sum and then use pthread_mutex_lock to add it to the global sum variable
void *threadSum(void* arg)
{
	int tid, start, end, local_sum =0;
	tid = *(int *)arg;
	start = (tid*(ARRAY_SIZE/MAX_THREADS));
	end = ((tid+1)*(ARRAY_SIZE/MAX_THREADS));
	for(int i=start;i<=end;i++){
		local_sum+=arr[i];
	}
	pthread_mutex_lock(&lock);
	sum+=local_sum;
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
    int i, tid[MAX_THREADS];
    
    // Read N (number of elements and create an array of N random numbers. Write a loop to find the sum of N elements sequenetially and display the sum and time taken
    sum=0;
    // Now divide the N as per maxThread and create threads with corresponding indcies for sum
    pthread_t threads[maxThread];

    // creating  maxThread threads
    for (i = 0; i < maxThread; i++)
        //Create threads

    // i.e. waiting for threads to complete
    for (i = 0; i < maxThread; i++)
        // join threads
        
    //  Display final sum and time taken
    
    cout<<sum;

    return 0;
}
