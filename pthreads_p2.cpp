/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int input[10];
int total_numbers = 10;
// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed.

//Method to count negatives
void *countNegatives(void*){
    int count = 0;
    for(int i=0;i<total_numbers;i++){
        if(input[i]<0){
            count++;
        }
    }
    
    cout<<"Total negative numbers: "<<count<<endl;
}


//Method to get average
void *average(void*){
    int average;
    average = 0;
    for(int i=0;i<total_numbers;i++){
        average = average + input[i];
        double final_avg = (double)average/total_numbers;
    }
    
    cout<<"Average: "<<(double)average/total_numbers<<endl;
}


//Method to reverse order
void *reverse(void*){
    cout<<"The numbers in reverse:"<<endl;
    for(int i=0;i<total_numbers;i++){
        cout<<input[total_numbers-i]<<endl;
    }
}

int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   // id for all threads
   pthread_t negative_thread;
   pthread_t average_thread;
   pthread_t reverse_thread;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   //Data input
   for(int x; x<total_numbers; x++)
       {
       cout << "Enter Input: " <<endl;
       cin >> input[x];
       }
   // TODO: Add code to perform any needed initialization
   //       or to process user input

   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   //Creates negative thread
   rc = pthread_create(&negative_thread, NULL, countNegatives, NULL);
       if(rc){
           cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
    }
   sleep(1);
   //Creates average thread
   rc = pthread_create(&average_thread, NULL, average, NULL);
       if(rc){
           cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
    }
   sleep(1);
   //Creates reverse thread 
   rc = pthread_create(&reverse_thread, NULL, reverse, NULL);
       if(rc){
           cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
    }
   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
