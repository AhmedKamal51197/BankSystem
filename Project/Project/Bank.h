#pragma once
#include<string>
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
		int customerNum= clients.size();
		
		while (!clients.empty())
		{
			Customer client = clients.top();
			clients.pop();
			int miniTime = tailers[0].getFinshTime();
			int index = 0;
			for (int i = 0; i < 3; i++)
			{
				if (miniTime > tailers[i].getFinshTime())
				{
					miniTime = tailers[i].getFinshTime();
					index = i;
				}
			}
			if (!tailers[index].getStatus())
			{
				avgWaiting += client.getWaitingTime();
				tailers[index].setFinshTime(client.getSurviceTime()+client.getArriveTime());
				tailers[index].setStatus(true);
				tailers[index].surveCont++;
				cout << "Customer : " << client.getName() << " survice Time = " << client.getSurviceTime() << " waiting time = " << client.getWaitingTime() << endl;
			}
			else
			{
				//if (tailers[index].getFinshTime() <= client.getArriveTime())
				//{
				//	//client.setWaitingTime(0);
				//	//tailers[index].setStatus(false);

				//}
				//else
				//{
				 client.setWaitingTime(tailers[index].getFinshTime() - client.getArriveTime());
				//}
				 tailers[index].setStatus(false);
				clients.push(client);
			}

		}
		cout << "Average Waiting Time = " << avgWaiting/customerNum  << " Minutes total numbers of customers surved = " << customerNum << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Tailer : " << tailers[i].getId() << " Name : " << tailers[i].getName()
				<< " Total Survice Time = " << tailers[i].getFinshTime() << " Minutes utilization surve = " << ((tailers[i].surveCont)/customerNum)*100 << "%" 
				<< endl;

		}
	}
};

