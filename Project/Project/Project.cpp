	#include <iostream>
	using namespace std;
	#include "Tailer.h"
	#include "Customer.h"
	#include "Bank.h"
	#include <queue>
    #include<fstream>
	int main()
	{
		
		priority_queue<Customer> Custemr_Queue;
		
		string name;
		int arriveTime, surviceTime, age;
		ifstream Infile("Customer_Info.txt");
		while (Infile >> name >> arriveTime >> surviceTime >> age)
		{
			Custemr_Queue.push(Customer(name, arriveTime, surviceTime, age));
		}
		Infile.close();

		Bank bank1;
		bank1.Simulation(Custemr_Queue);
	
	
   
	}