#pragma once
#include<string>
#include <iomanip> 
using namespace std;
#include "Customer.h"
#include "Tailer.h"
#include <queue>
#include<iostream>
class Bank
{
	
	Tailer* tailers;
public:
	Bank()
	{
		
		tailers = new Tailer[3];
		tailers[0].setName("Ahmed");
		tailers[0].setId(1);
		tailers[0].setFinshTime(0);
		tailers[1].setName("Omar");
		tailers[1].setId(2);
		tailers[1].setFinshTime(0);
		tailers[2].setName("Ola");
		tailers[2].setId(3);
		tailers[2].setFinshTime(0);


	}


	void Simulation(priority_queue<Customer> clients) {
		double avgWaiting = 0;
		int customerNum = clients.size();
		cout << "+-------------------+---------------+-----------------------------------------------------+" << endl;
		cout << "| " << setw(18) << left << "Customer Name" << " | " << setw(13)<< left <<"Arrival Time"<< " | " << setw(13) << left << "Service Time"  << " | " << setw(13) << left <<"Total Time in Bank" << " | " << setw(13) << left << "Waiting Time" << " |" << endl;
		cout << "+-------------------+---------------+-----------------------------------------------------+" << endl;

		while (!clients.empty()) {
			Customer client = clients.top();
			clients.pop();
			int miniTime = tailers[0].getFinshTime();
			int index = 0;
			for (int i = 0; i < 3; i++) {
				if (miniTime > tailers[i].getFinshTime()) {
					miniTime = tailers[i].getFinshTime();
					index = i;
				}
			}
			if (!tailers[index].getStatus()) {
				avgWaiting += client.getWaitingTime();
				tailers[index].setFinshTime(client.getSurviceTime() + client.getArriveTime()+client.getWaitingTime());
				tailers[index].setStatus(true);
				tailers[index].surveCont++;

				// Print customer data with borders
				cout << "| " << setw(18) << left << client.getName() << " | " << setw(14) << left <<client.getArriveTime()<<" | " << setw(13) << left <<  client.getSurviceTime() << " | " << setw(17) << left<< client.getSurviceTime()+ client.getWaitingTime() << " | " << setw(13) << left << client.getWaitingTime() << " |" << endl;
			}
			else {
				if (tailers[index].getFinshTime() <= client.getArriveTime()) {
					client.setWaitingTime(0);
				}
				else {
					client.setWaitingTime(tailers[index].getFinshTime() - client.getArriveTime());
				}
				tailers[index].setStatus(false);
				clients.push(client);
			}
		}

		// Print average waiting time
		cout << "+-------------------+---------------------------------------------------------------------+" << endl;
		cout << "| Average Waiting Time = " << setw(19) << left << avgWaiting / customerNum<<" Minutes" << setw(39) << right << " |" << endl;
		cout << "+-------------------+---------------------------------------------------------------------+" << endl;

		// Print tailer statistics table with borders
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
		cout << "| " << setw(10) << left << "Tailer ID" << " | " << setw(17) << left << "Tailer Name" << " | " << setw(17) << left << "Total Service Time" << " | " << setw(17) << left << "Utilization Rate" << " |" << endl;
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "| " << setw(7) << left << tailers[i].getId() << " | " << setw(24) << left << tailers[i].getName()
				<< " | " << setw(15) << left << tailers[i].getFinshTime() << " | " << setw(15) << left << ((tailers[i].surveCont) / (double)customerNum) * 100 <<"%"
				<< " |" << endl;
		}
		cout << "+-------+-------------------+-------------------+-------------------------+" << endl;
	}


};

