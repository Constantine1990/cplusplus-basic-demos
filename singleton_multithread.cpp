#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;  


class Singleton{
public:
	static Singleton* getinstance(){
		if (instance==NULL){
			instance = new Singleton();
		}
		return instance;
	};
	void changevalue(){
		lock_guard<mutex> lock(mMutex);
		for(int i = 0 ;i<1000000;i++)
			value++;
	}
	long showvalue(){
		return value;
	}
	
private:
	Singleton(){
		value=0;
	};
	~Singleton(){
		if (NULL!=instance)
			delete instance;
	};
	static Singleton* instance;
	long value;
	mutex mMutex;
};
Singleton* Singleton::instance = NULL;

void invoke(){
	auto p = Singleton::getinstance();	
	p->changevalue();
}


int main()
{	
	vector<thread> vec;
	for(int i = 0 ;i<10;i++){
		//thread t(&f1);
		vec.push_back(thread(invoke));
	}
	for(int i = 0 ;i<10;i++){
		vec[i].join();
	}
	auto p = Singleton::getinstance();	
	cout<<p->showvalue()<<endl;
	return 0 ;
}
