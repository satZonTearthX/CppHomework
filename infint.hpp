#ifndef _INFINT_HPP_
#define _INFINT_HPP_


#include<string>
#define MAXPOWER 2000 //the lagest number of figure it can contain
using namespace std;
class Infint {
	friend ostream & operator<<(ostream &out, Infint &obj);
public:
	int value[MAXPOWER] = {};
	int power = 0;
	string valueshow;
	int plus;

	Infint();
	Infint(int num);
	Infint(std::string nums);
	Infint operator+(Infint& n);
	Infint operator-(Infint& n);
	Infint& operator++();
	Infint operator++(int);
	Infint& operator--();
	//Infint operator--(int);
	/*Infint operator+=(Infint& n);
	Infint operator-=(Infint& n);*/
	void operator=(const Infint& b);
};
Infint minusnum(Infint& n);
bool bigger(Infint&n1, Infint&n2);
#endif
