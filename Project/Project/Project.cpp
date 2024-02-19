#include <iostream>
using namespace std;
#include "Tailer.h"
#include "Customer.h"
#include "Bank.h"
#include <queue>
int main()
{
	/*int numberOfCustomer;
	cout << "Enter Number of Customers\n";
	cin >> numberOfCustomer;*/
	//Customer* clients=new Customer[numberOfCustomer];
	/*string name;
	int age, arriveTime, surviceTime;*/
	/*for (int i = 0; i < numberOfCustomer; i++)
	{
		cout << "Enter name of customer number : " << i + 1 << endl;
		cin >> name;
		clients[i].setName(name);
		cout << "Enter arrive Time for customer number : " << i + 1 << endl;
		cin >> arriveTime;
		clients[i].setArriveTime(arriveTime);
		cout << "Enter survice Time for customer number : " << i + 1 << endl;
		cin >> surviceTime;
		clients[i].setSurviceTime(surviceTime);
	}*/
	priority_queue<Customer> Custemr_Queue;
	Custemr_Queue.push(Customer("Ahmed",1, 5, 25));
	Custemr_Queue.push(Customer("Ali", 1, 4, 35));
	Custemr_Queue.push(Customer("Mostafa", 1, 4, 30));
	Custemr_Queue.push(Customer("hady", 1, 4, 30));
	Custemr_Queue.push(Customer("Rady",10, 4, 40));
	Custemr_Queue.push(Customer("Hossam", 5, 3, 25));
	Custemr_Queue.push(Customer("abdallah", 5, 2, 34));
	Custemr_Queue.push(Customer("Mina", 4, 10, 20));
	Custemr_Queue.push(Customer("Abanoub", 3, 9, 40));
	Custemr_Queue.push(Customer("yasmeen", 2, 8, 50));
	Custemr_Queue.push(Customer("ebtsam", 8, 7, 60));
	Custemr_Queue.push(Customer("fatma", 3, 6, 20));
	Custemr_Queue.push(Customer("doha", 15, 4, 30));
	Custemr_Queue.push(Customer("kamal", 20, 4, 37));
	Custemr_Queue.push(Customer("gamal", 10, 4, 38));
	Custemr_Queue.push(Customer("yusra", 36, 4, 39));

	Bank bank1;
	bank1.Simulation(Custemr_Queue);
	
	
   
}