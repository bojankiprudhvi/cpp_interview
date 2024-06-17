//thread creation for printing even and odd
#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
using namespace std;
int num =0;
condition_variable cv;
mutex m;
class Even{
	public:
	static void even()
	{
		for(int i=0;i<20;i++)
		{
		//	unique_lock<mutex> lk(m);
			cv.wait([]{ return (num%2)==0 ? true: false;});
		cout<<"the current number is even "<<num<<"\n";
		num++;
		cv.notify_all();
	}
	}
};
class Odd{
	public:
	void odd()
	{
		for(int i=0;i<20;i++)
		{
		//unique_lock<mutex> lk(m);
		cv.wait([]{ return (num%2)==1? true: false;});
		cout<<"the current number is odd "<<num<<"\n";
		num++;
		cv.notify_all();
	}
};

int main()
{
	Odd obj;
	thread t1(&Even::even);
	thread t2(&Odd::odd,&obj);
	t1.join();
	t2.join();
	return 0;
}
