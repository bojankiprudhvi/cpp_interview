//singleton design pattern 

#include<iostream>
using namespace std;
class Singleton
{
	public:
	static Singleton* getInstance()
	{
		if(!instance)
		{
			instance = new Singleton();
		}
		return  instance;
	}
	void perform()
	{
		cout<<"performing some task with single ton"<<"\n";
	}
	private:
		Singleton(const &Singleton)= delete;
		Singleton& operator= (const &Singleton )= delete;
		Singleton()
		{
			cout<<"constructor of singleton"<<"\n";
		}
		~Singleton()
		{
				cout<<"Destructor of singleton"<<"\n";
		}
	static Singleton *instance;
};
Singleton* Singleton::instance = nullptr;
int main()
{
	Singleton* obj = Singleton::getInstance();
	obj->perform();
//	obj = new Singleton();
	return 0;
} 
