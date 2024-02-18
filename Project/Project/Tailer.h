#pragma once
using namespace std;
#include <string>
class Tailer
{
	int finshTime;
	bool status;
	string  name;
	int id;
public:
	double surveCont;
	Tailer(){
		surveCont = 0;
		setStatus(false);
	}
	Tailer(int id, string name)
	{
		surveCont = 0;
		setStatus(false);
		setName(name);
		setId(id);
	}
	void setName(string name)	
	{
		this->name = name;
	} 
	void setId(int id)
	{
		this->id = id;
	}
	void setFinshTime(int finshTime)
	{
		this->finshTime = finshTime;
	}
	void setStatus(bool status)
	{
		this->status = status;
	}
	string getName()
	{
		return this->name;
	}
	int getId()
	{
		return this->id;
	}
	int getFinshTime()
	{
		return this->finshTime;
	}
	bool getStatus()
	{
		return this->status;
	}
};

