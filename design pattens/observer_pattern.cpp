//Problem statement: Suppose you are developing a weather monitoring application, in which multiple weather stations are responsible for collecting weather data,
// and you want to create a system where multiple displays can show real-time weather updates.
// When a weather station collects new data, all registered displays should be updated automatically with the latest information.

#include<iostream>
#include<vector>
using namespace std;
class Observer
{
	public:
 virtual void updateTemp(int temp,int humidity)=0;	
};
class WhetherUpate{
	public:
	int temp;
	int humidity;
	vector<Observer*> object;
	void add_observer(Observer *obj)
	{
		object.push_back(obj);
	}
	void notify()
	{
		for(Observer* ob: object)
		{
			ob->updateTemp(temp,humidity);
		}
	}
	void set_observer(int tem,int hum)
	{
		temp = tem;
		humidity= hum;
		notify();	
	}
};
class Display : public Observer{
	void updateTemp(int temp,int humidity)
	{
		cout<<"Display : "<<"temp  "<<temp<<"  humidity " <<humidity<<"\n";
	}
};
int main()
{
	Display obj1;
	Display obj2;
	
	WhetherUpate whether;
	whether.add_observer(&obj1);
	whether.add_observer(&obj2);
	whether.set_observer(3,7);
	return 0;
}
