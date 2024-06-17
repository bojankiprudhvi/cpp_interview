//factory design pattern for fruits
/*
#include<iostream>
using namespace std;
class Fruit
{
public:
	static Fruit * giveobject(string type);
	virtual void taste()=0;	
};
class Apple : public Fruit
{
public:
void taste(){
	cout<<"apple is sweet"<<"\n";
}	
};
class Orange : public Fruit
{
public:
void taste(){
	cout<<"Orange is sour"<<"\n";
}	
};
class Grape : public Fruit
{
public:
void taste(){
	cout<<"apple is good"<<"\n";
}	
};
Fruit * Fruit::giveobject(string type)
{
	
		if(type== "apple")
		return new Apple();
		else if(type== "orange")
		return new Orange();
		else if(type== "grape")
		return new Grape();
		else 
		return nullptr;
	
}
int main()
{
	Fruit* obj = Fruit::giveobject("apple");
	obj->taste();
	return 0;	
}*/








#include<iostream>
using namespace std;
class Fruit{
	public:
	static  Fruit * giveobj(string type);
	virtual void taste() =0;
};
class Apple : public Fruit
{
	void taste()
	{
		cout<<"apple is sweet";
	}
};
class Orange : public Fruit
{
	void taste()
	{
		cout<<"Orange is sweet";
	}
};
Fruit * Fruit::giveobj(string type){
	if( type == "apple")
	{
		return new Apple();
	}
	else
	return new Orange();
}
int main()
{
	Fruit* obj = Fruit::giveobj("apple");
	obj->taste();
	return 0;
}
