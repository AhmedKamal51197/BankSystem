#pragma once
#include<string>
#include <iomanip> 
using namespace std;
#include "Customer.h"
#include "Teller.h"
#include <queue>
#include<iostream>
class Bank
{
	
	Teller* tellers;
public:
	Bank()
	{
		
		tellers = new Teller[3];
		tellers[0].setName("Ahmed");
		tellers[0].setId(1);
		tellers[0].setFinshTime(0);
		tellers[1].setName("Omar");
		tellers[1].setId(2);
		tellers[1].setFinshTime(0);
		tellers[2].setName("Ola");
		tellers[2].setId(3);
		tellers[2].setFinshTime(0);


	}


	void Simulation(priority_queue<Customer> clients) {
		double avgWaiting = 0;
		int minimumWaiting = INT_MAX;
		int maximumWaiting = INT_MIN;
		int customerNum = clients.size();
		cout << "+-------------------+---------------+----------------------------------------------------------------------+" << endl;
		cout << "| " << setw(18) << left << "Customer Name" << " | " << setw(13) << left <<"Customer Age"<<" | " << setw(13) << left << "Arrival Time" << " | " << setw(13) << left << "Service Time" << " | " << setw(13) << left << "Total Time in Bank" << " | " << setw(13) << left << "Waiting Time" << "  |" << endl;
		cout << "+-------------------+---------------+----------------------------------------------------------------------+" << endl;

		while (!clients.empty()) {
			Customer client = clients.top();
			clients.pop();
			int miniTime = tellers[0].getFinshTime();
			int index = 0;
			for (int i = 0; i < 3; i++) {
				if (miniTime > tellers[i].getFinshTime()) {
					miniTime = tellers[i].getFinshTime();
					index = i;
				}
			}
			if (!tellers[index].getStatus()) {
				
				avgWaiting += client.getWaitingTime();
				tellers[index].setFinshTime(client.getSurviceTime() + client.getArriveTime()+client.getWaitingTime());
				tellers[index].setStatus(true);
				tellers[index].surveCont++;

				// Print customer data with borders
				cout << "| " << setw(18) << left << client.getName() << " | " << setw(14) << left <<client.getAge() << " | " << setw(14) << left <<client.getArriveTime()<<" | " << setw(13) << left <<  client.getSurviceTime() << " | " << setw(17) << left<< client.getSurviceTime()+ client.getWaitingTime() << " | " << setw(13) << left << client.getWaitingTime() << " |" << endl;
			}
			else {
				if (tellers[index].getFinshTime() <= client.getArriveTime()) {
					client.setWaitingTime(0);
				}
				else {
					client.setWaitingTime(tellers[index].getFinshTime() - client.getArriveTime());
				}
				tellers[index].setStatus(false);
				clients.push(client);
			}
			if (minimumWaiting >  client.getWaitingTime())
				minimumWaiting = client.getWaitingTime();
			if (maximumWaiting < client.getWaitingTime())
				maximumWaiting = client.getWaitingTime();
		}

		// Print average waiting time
		cout << "+-------------------+--------------------------------------------------------------------------------------+" << endl;
		cout << "| Average Waiting Time = " << setw(14) << left << avgWaiting / customerNum << " Maximum waiting Time = " <<maximumWaiting << setw(13) << left << " minimum waiting Time = "<<minimumWaiting<< setw(19) << right<<"|" << endl;
		cout << "+-------------------+--------------------------------------------------------------------------------------+" << endl;

		// Print Teller statistics table with borders
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
		cout << "| " << setw(10) << left << "Teller ID" << " | " << setw(17) << left << "Teller Name" << " | " << setw(17) << left << "Total Service Time" << " | " << setw(17) << left << "Utilization Rate" << " |" << endl;
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "| " << setw(7) << left << tellers[i].getId() << " | " << setw(24) << left << tellers[i].getName()
				<< " | " << setw(15) << left << tellers[i].getFinshTime() << " | " << setw(15) << left << ((tellers[i].surveCont) / (double)customerNum) * 100 <<"%"
				<< " |" << endl;
		}
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
	}


};

