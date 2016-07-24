//
//  main.cpp
//  HW3 text list
//
//  Created by Allison Kane on 3/16/16.
//  Copyright Â© 2016 Allison Kane. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <cstring>

using namespace std;

int main (int args, char *argv[])
{
    stack <int> myStack;    //creates stack
    queue <int> myQueue;    //creates queue
    
    int i = 0;
    char c = ',';
    string inputFile;
    ofstream out;
    out.open("my_results.txt"); // will write out the results of the program to text file
    out << "input ";
    ifstream myfile;
    string store;
    int temp;
    
    while(i ==0){                   // reads in file and checks to see if it has been opened
        cout << "Please input the file you would like to read ";
        getline(cin, inputFile);
        myfile.open(inputFile.c_str());
        if(myfile.is_open())
        {
            i++;
            cout<<"File has been located"<<endl;
        }
        else{
            cout<<"Cannot locate the file "<<endl; //ensures user that he/she must enter the file correctly
        }
        
    }
    
    
    if(myfile.is_open()) // reads file and places each element into the stack
    {
        while (myfile.peek() != EOF)
        {
            myfile>>temp;
            if(myfile.peek()!=EOF)
            {
                myfile >> c;
            }
            out <<temp<< ",";
            myStack.push(temp);
        }
        out << endl;
        out<< "Full Stack: ";
        
        while(!myStack.empty()) //places the top element of the stack into the queue
        {
            temp = myStack.top();
            out << temp << ",";
            myQueue.push(temp);
            myStack.pop();
        }
        out<<" - Top" << endl;
        out<<"Full Queue - Front: ";
        queue <int> tempqueue; //create a temp queue to place the popped elements of the first queue, in order to write them            out in reverse order
        while(!myQueue.empty())
        {
            temp = myQueue.front();
            out<< temp << ",";
            tempqueue.push(temp);
            myQueue.pop(); //removes elements from queue
        }
        out<< " - Rear " << endl;
        
        out << "elements as removed from queue;  ";
        while (!tempqueue.empty())
        {
            temp = tempqueue.front();
            out << temp << ",";
            tempqueue.pop();
        }
    }
    
    myfile.close();
    out.close();
    return 0;
    
    
}







