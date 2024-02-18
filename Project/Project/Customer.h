#pragma once
using namespace std;
#include <string>
class Customer
{
	string name;
	int arriveTime;
	int surviceTime;
	int waitingTime;
	int age;
public:
	Customer() {}
	Customer(string name,int arriveTime,int surviceTime,int age)
	{
		setName(name);
		setAge(age);
		setArriveTime(arriveTime);
		setSurviceTime(surviceTime);
		this->waitingTime = 0;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setArriveTime(int arriveTime)
	{
		this->arriveTime = arriveTime;
	}
	void setSurviceTime(int surviceTime)
	{
		this->surviceTime = surviceTime;
	}
	void setWaitingTime(int waitingtime)
	{
		this->waitingTime = waitingtime;
	}
	string getName()
	{
		return this->name;
	}
	int getArriveTime()
	{
		return this->arriveTime;
	}
	int getSurviceTime()
	{
		return this->surviceTime;
	}
	int getWaitingTime()
	{
		return this->waitingTime;
	}
	int getAge()
	{
		return this->age;
	}

	bool   operator<(const Customer& customer) const {
		if (this->arriveTime == customer.arriveTime)
		{
			return this->age <  customer.age;
		}
		else
		{
			return this->arriveTime > customer.arriveTime;
		}
	}

};

