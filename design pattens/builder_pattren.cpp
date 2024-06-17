//builder design pattern 
//final proudct
//builder abstatct class
//internal building 
//directory
#include<iostream>
using namespace std;
class Plane 
{
	string _plane;
	string _engine;
	string _body;
	public:
	Plane(string palne):_plane(palne){};
	void setEngine(string engine)
	{
		_engine = engine;
	}
	void setBody(string body)
	{
		_body = body;
	}
	void show()
	{
		cout<<_plane<<"\n"<<_engine<<"\n"<<_body<<"\n";
	}
};

class Builder
{
	public:
	Plane* _plane;
	virtual void callconst()=0;
	virtual void buildEngine()=0;
	virtual void buildBody()=0;
	Plane* getplane()
	{
		return _plane;
	}
};
class JetBuiler :public Builder
{
	void callconst()
	{
		_plane = new Plane("building plane ");
	}
	void buildEngine()
	{
		_plane->setEngine("set the jet engine");
	}
	void buildBody()
	{
		_plane->setBody("set the jet Bosdy");
	}
};
class PropBuiler :public Builder
{
	void callconst()
	{
		_plane = new Plane("building plane ");
	}
	void buildEngine()
	{
		_plane->setEngine("set the prop engine");
	}
	void buildBody()
	{
		_plane->setBody("set the prop Bosdy");
	}
};

//director
class Director
{
	public:
	Plane * getobject(Builder* object )
	{
		object->callconst();
		object->buildEngine();
		object->buildBody();
		return object->_plane;
	}
};
int main (){
	Director dir;
	JetBuiler jb;
	PropBuiler pb;
	Plane* _plane = dir.getobject(&pb);
	_plane->show();
	return 0;
}

