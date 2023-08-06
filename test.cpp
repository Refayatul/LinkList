#include <iostream>
using namespace std;

class Ratio{
public:
	Ratio(){cout<<"Obj is born ."<<"\n";}
	~Ratio(){cout<<"Obj dies ."<<"\n";}
private:
	int num,den;

};


int main() {
   
	{	Ratio x;
		cout<<"Now x is alive"<<endl;
	}
	cout<<"code in the mmiddle:"<<"\n";
	{
		Ratio y;
		cout<<"Now y is alive"<<endl;
	}









    return 0;
}
