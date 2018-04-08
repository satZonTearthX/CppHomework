#include<string>
#include<cmath>
#include"infint.hpp"

using namespace std;

Infint minusnum(Infint& n)//keep it on the top or the function that uses it will have problem
{
	Infint n2 = n;
	n2.plus = -1*n2.plus;
	if (n2.plus != 0) {
		if (n2.plus > 0) n2.valueshow.erase(0, 1);
		else n2.valueshow.insert(0, 1, '-');
	}
	return n2;
}

bool bigger(Infint&n1, Infint&n2)//n1>=n2 true compare their absolute
{
	if (n1.power > n2.power) return true;
	if (n1.power < n2.power) return false;
	int i=n1.power-1;
	bool flag=true;
	while (n1.value[i]==n2.value[i]) {
		i--;
	}
	flag = n1.value[i] > n2.value[i];//return the relation where the two differs
	return flag;
}
Infint::Infint(){
	this->power=1;
	this->valueshow="0";
	for (int i = 0; i < MAXPOWER; i++) this->value[i] = 0;//Initialize for some g++ version debug for the minus part
	this->value[0]=0;
	this->plus = 0;
};

Infint::Infint(int num){
	int i,numTem,num2=num;
	this->valueshow="";
	if (num2 == 0) {
		this->plus = 0;
		this->valueshow = "0";//init it as "" prevent from no expression
	
	}
	else this->plus = num2 / (abs(num2));
	num2 = abs(num2);
	numTem=num2;
	while (numTem>0){
		numTem=numTem/10;
		this->power++;
	}
	for (i = 0; i < MAXPOWER; i++) this->value[i] = 0;//Initialize for some g++ version debug for the minus part
	numTem=num2;
	//divide
	for (i=0;i<=this->power-1;i++){
		
		this->value[i]=numTem % 10;
		numTem=numTem/10;
		valueshow=(char)(this->value[i]+48)+valueshow;
	}
	if (plus < 0) this->valueshow = '-' + this->valueshow;
	
	
}

Infint::Infint(std::string nums){
	int i,j=0;
	string nums2=nums;
	
	if (nums2.at(0) == '-') {
		this->plus = -1;
		nums2.erase(0, 1);
	}
	else if (nums2.at(0) == '0' && nums2.length() == 1)
	{
		this->plus = 0;
	}
	else
		this->plus = 1;
	
	while (nums2.at(0) == '0' && nums2.length()>1)
		nums2.erase(0, 1);//prevent the situation like 00003233
	
	this->valueshow=nums2;
	if (this->plus == -1) this->valueshow.insert(0, 1, '-');


	for (i = 0; i < MAXPOWER; i++) this->value[i] = 0;//Initialize for some g++ version debug for the minus part
	
	this->power=nums2.length();	
	//divide
	for (i=this->power-1;i>=0;i--){
		
		this->value[j]=(int)(nums2.at(i))-48;//get the specific array of big number
		j++;
	}
};

ostream & operator<<(ostream &out, Infint &obj)
 	{
    	out << obj.valueshow;
     	return out;
 	}
 
void Infint::operator=(const Infint& b)
    {
         int i;
		 this->plus = b.plus;
         this->power = b.power;
         this->valueshow = b.valueshow;
         for (i=0;i<this->power;i++)
         	this->value[i]=b.value[i];
    }

void Infint::operator=(const int num)
{
	Infint b = Infint(num);
	int i;
	this->plus = b.plus;
	this->power = b.power;
	this->valueshow = b.valueshow;
	for (i = 0; i<this->power; i++)
		this->value[i] = b.value[i];
}

void Infint::operator=(const string num)
{
	Infint b = Infint(num);
	int i;
	this->plus = b.plus;
	this->power = b.power;
	this->valueshow = b.valueshow;
	for (i = 0; i<this->power; i++)
		this->value[i] = b.value[i];
}

Infint Infint::operator+(Infint& n)
	{
	Infint inf = Infint();
	Infint tem;
	if (this->plus == 0 || n.plus == 0) 
		{
		if (this->plus == 0) inf=n;
			else inf=*this;//no need to calculate write the number that is not zero
	    }
	else
	{
		inf.valueshow = "";//the Infint() makes it "0"
			if ((this->plus * n.plus > 0)) {
				
				inf.plus = n.plus;

			

				int maxPower, i, add = 0;

				if (this->power > n.power) maxPower = this->power;
				else maxPower = n.power;

				inf.power = maxPower;
				
				add = 0;//init
				
				for (i = 0; i < maxPower; i++) {

					inf.value[i] = (this->value[i] + n.value[i] + add) % 10;
					inf.valueshow = (char)(inf.value[i] + 48) + inf.valueshow;
					add = (this->value[i] + n.value[i] + add) / 10;
				}

				if (add > 0) {
					inf.power = maxPower + 1;
					inf.value[maxPower - 1] = add;
					inf.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow;

				}
				
				if (inf.plus < 0) inf.valueshow.insert(0, 1, '-');
		}
			else
			{
				if (this->plus == -1)
				{
					tem = minusnum(*this);
					inf = n.operator-(tem);
				}
				else
				{
					tem = minusnum(n);
					inf = this->operator-(tem);
				}
			}
		
	}
	return inf;
	}

Infint Infint::operator+(int num)
{
	Infint n = Infint(num);
	Infint inf = Infint();
	Infint tem;
	if (this->plus == 0 || n.plus == 0)
	{
		if (this->plus == 0) inf = n;
		else inf = *this;//no need to calculate write the number that is not zero
	}
	else
	{
		inf.valueshow = "";//the Infint() makes it "0"
		if ((this->plus * n.plus > 0)) {

			inf.plus = n.plus;



			int maxPower, i, add = 0;

			if (this->power > n.power) maxPower = this->power;
			else maxPower = n.power;

			inf.power = maxPower;

			add = 0;//init

			for (i = 0; i < maxPower; i++) {

				inf.value[i] = (this->value[i] + n.value[i] + add) % 10;
				inf.valueshow = (char)(inf.value[i] + 48) + inf.valueshow;
				add = (this->value[i] + n.value[i] + add) / 10;
			}

			if (add > 0) {
				inf.power = maxPower + 1;
				inf.value[maxPower - 1] = add;
				inf.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow;

			}

			if (inf.plus < 0) inf.valueshow.insert(0, 1, '-');
		}
		else
		{
			if (this->plus == -1)
			{
				tem = minusnum(*this);
				inf = n.operator-(tem);
			}
			else
			{
				tem = minusnum(n);
				inf = this->operator-(tem);
			}
		}

	}
	return inf;
}
Infint Infint::operator+(string num)
{
	Infint n = Infint(num);
	Infint inf = Infint();
	Infint tem;
	if (this->plus == 0 || n.plus == 0)
	{
		if (this->plus == 0) inf = n;
		else inf = *this;//no need to calculate write the number that is not zero
	}
	else
	{
		inf.valueshow = "";//the Infint() makes it "0"
		if ((this->plus * n.plus > 0)) {

			inf.plus = n.plus;



			int maxPower, i, add = 0;

			if (this->power > n.power) maxPower = this->power;
			else maxPower = n.power;

			inf.power = maxPower;

			add = 0;//init

			for (i = 0; i < maxPower; i++) {

				inf.value[i] = (this->value[i] + n.value[i] + add) % 10;
				inf.valueshow = (char)(inf.value[i] + 48) + inf.valueshow;
				add = (this->value[i] + n.value[i] + add) / 10;
			}

			if (add > 0) {
				inf.power = maxPower + 1;
				inf.value[maxPower - 1] = add;
				inf.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow;

			}

			if (inf.plus < 0) inf.valueshow.insert(0, 1, '-');
		}
		else
		{
			if (this->plus == -1)
			{
				tem = minusnum(*this);
				inf = n.operator-(tem);
			}
			else
			{
				tem = minusnum(n);
				inf = this->operator-(tem);
			}
		}

	}
	return inf;
}
Infint Infint::operator-(Infint& n) {
	Infint inf1;//save the first number
	Infint inf2,res;
	int i,j;
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		if (n.plus == 0) return *this;
		else {
			res= minusnum(n);
		}
	}
	else if (this->plus*n.plus < 0) {
		inf2 = minusnum(n);
		res = this->operator+(inf2);
	}
	else if (this->plus*n.plus > 0) {
		if (bigger(n, *this)) { //n>=this calculate  if (n==this) delete the sign of(+/-)later
			inf1 = n;
			inf2 = *this;
			res.plus = inf1.plus*-1;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
			res.plus = inf1.plus;
		}
		for (i = 0; i < inf1.power; i++) {
			if (inf1.value[i] < inf2.value[i]) {
				inf1.value[i] += 10;
				j = i + 1;
				while (inf1.value[j] == 0 && j<inf1.power) {
					inf1.value[j] = 9;
					j++;
				}
				inf1.value[j] = inf1.value[j] - 1;//end of the borrow 1 from the upper
				if (j == inf1.power - 1 && inf1.value[j] == 0) inf1.power--;//100-99 then 100 becomes 99 and the number of figure decrease by 1
			}
			res.value[i] = inf1.value[i] - inf2.value[i];
			res.valueshow = (char)(res.value[i] + 48) + res.valueshow;
		}//end of the calculation
		
		//find the number of the digit of the result
		res.power = inf1.power;
		while (res.value[res.power - 1] == 0 && res.power>1) res.power--;//get actually how many digits in the result
		/*if (res.value[inf1.power - 1] == 0) res.power--; not the same way?*/
		
		//cut the string to avoid the 0 at the first pos of the number
		res.valueshow=res.valueshow.substr(res.valueshow.length() - res.power);
		//change the sign if the result is 0
		if (res.value[0] == 0 && res.power == 1) res.plus = 0;

		if (res.plus==-1) res.valueshow.insert(0, 1, '-');
	}
	return res;
}

Infint Infint::operator-(int num) {
	Infint n = Infint(num);
	Infint inf1;//save the first number
	Infint inf2, res;
	int i, j;
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		if (n.plus == 0) return *this;
		else {
			res = minusnum(n);
		}
	}
	else if (this->plus*n.plus < 0) {
		inf2 = minusnum(n);
		res = this->operator+(inf2);
	}
	else if (this->plus*n.plus > 0) {
		if (bigger(n, *this)) { //n>=this calculate  if (n==this) delete the sign of(+/-)later
			inf1 = n;
			inf2 = *this;
			res.plus = inf1.plus*-1;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
			res.plus = inf1.plus;
		}
		for (i = 0; i < inf1.power; i++) {
			if (inf1.value[i] < inf2.value[i]) {
				inf1.value[i] += 10;
				j = i + 1;
				while (inf1.value[j] == 0 && j<inf1.power) {
					inf1.value[j] = 9;
					j++;
				}
				inf1.value[j] = inf1.value[j] - 1;//end of the borrow 1 from the upper
				if (j == inf1.power - 1 && inf1.value[j] == 0) inf1.power--;//100-99 then 100 becomes 99 and the number of figure decrease by 1
			}
			res.value[i] = inf1.value[i] - inf2.value[i];
			res.valueshow = (char)(res.value[i] + 48) + res.valueshow;
		}//end of the calculation

		 //find the number of the digit of the result
		res.power = inf1.power;
		while (res.value[res.power - 1] == 0 && res.power>1) res.power--;//get actually how many digits in the result
																		 /*if (res.value[inf1.power - 1] == 0) res.power--; not the same way?*/

																		 //cut the string to avoid the 0 at the first pos of the number
		res.valueshow = res.valueshow.substr(res.valueshow.length() - res.power);
		//change the sign if the result is 0
		if (res.value[0] == 0 && res.power == 1) res.plus = 0;

		if (res.plus == -1) res.valueshow.insert(0, 1, '-');
	}
	return res;
}

Infint Infint::operator-(string num) {
	Infint n = Infint(num);
	Infint inf1;//save the first number
	Infint inf2, res;
	int i, j;
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		if (n.plus == 0) return *this;
		else {
			res = minusnum(n);
		}
	}
	else if (this->plus*n.plus < 0) {
		inf2 = minusnum(n);
		res = this->operator+(inf2);
	}
	else if (this->plus*n.plus > 0) {
		if (bigger(n, *this)) { //n>=this calculate  if (n==this) delete the sign of(+/-)later
			inf1 = n;
			inf2 = *this;
			res.plus = inf1.plus*-1;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
			res.plus = inf1.plus;
		}
		for (i = 0; i < inf1.power; i++) {
			if (inf1.value[i] < inf2.value[i]) {
				inf1.value[i] += 10;
				j = i + 1;
				while (inf1.value[j] == 0 && j<inf1.power) {
					inf1.value[j] = 9;
					j++;
				}
				inf1.value[j] = inf1.value[j] - 1;//end of the borrow 1 from the upper
				if (j == inf1.power - 1 && inf1.value[j] == 0) inf1.power--;//100-99 then 100 becomes 99 and the number of figure decrease by 1
			}
			res.value[i] = inf1.value[i] - inf2.value[i];
			res.valueshow = (char)(res.value[i] + 48) + res.valueshow;
		}//end of the calculation

		 //find the number of the digit of the result
		res.power = inf1.power;
		while (res.value[res.power - 1] == 0 && res.power>1) res.power--;//get actually how many digits in the result
																		 /*if (res.value[inf1.power - 1] == 0) res.power--; not the same way?*/

																		 //cut the string to avoid the 0 at the first pos of the number
		res.valueshow = res.valueshow.substr(res.valueshow.length() - res.power);
		//change the sign if the result is 0
		if (res.value[0] == 0 && res.power == 1) res.plus = 0;

		if (res.plus == -1) res.valueshow.insert(0, 1, '-');
	}
	return res;
}

Infint Infint::operator*(Infint& n) {
	Infint inf1;//save the first number
	Infint inf2, res,digit;// digit stores the result the number times different postion of digits
	int i, j,add;//add for result over 10
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		res.valueshow="0";
	}
	else {
		res.plus = 1;//treat it as a postive number
		if (bigger(n, *this)) { //bigger as the first element so it runs faster
			inf1 = n;
			inf2 = *this;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
		}
		for (i = 0; i < inf2.power; i++) {
			if (inf2.value[i] == 0)
			{
				digit.plus = 0;//tell the operator+ not to calculate again
			}
			else {
				digit.plus = 1;
				for (int k = 0; k < i; k++) digit.value[k] = 0;
				add = 0;//init
				digit.power = inf1.power + i;//call operator+ need the power (how many digits in the number)
				for (j = 0; j < inf1.power; j++) {
					digit.value[i + j] = (inf1.value[j] * inf2.value[i] + add) % 10;
					add = (inf1.value[j] * inf2.value[i] + add) / 10;
				}
				if (add > 0) {
					digit.power++;
					digit.value[digit.power - 1] = add;
					//digit.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow; unnecessary. we don't need the expression but the value
				}
			}
			res = res.operator+(digit);
		}//end of the calculation

		if (this->plus*n.plus < 0) {
			res.plus = -1;
			res.valueshow.insert(0, 1, '-');
		}
		else res.plus = 1;
	

		
	}
	return res;
}

Infint Infint::operator*(int num) {
	Infint n = Infint(num);
	Infint inf1;//save the first number
	Infint inf2, res, digit;// digit stores the result the number times different postion of digits
	int i, j, add;//add for result over 10
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		res.valueshow = "0";
	}
	else {
		res.plus = 1;//treat it as a postive number
		if (bigger(n, *this)) { //bigger as the first element so it runs faster
			inf1 = n;
			inf2 = *this;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
		}
		for (i = 0; i < inf2.power; i++) {
			if (inf2.value[i] == 0)
			{
				digit.plus = 0;//tell the operator+ not to calculate again
			}
			else {
				digit.plus = 1;
				for (int k = 0; k < i; k++) digit.value[k] = 0;
				add = 0;//init
				digit.power = inf1.power + i;//call operator+ need the power (how many digits in the number)
				for (j = 0; j < inf1.power; j++) {
					digit.value[i + j] = (inf1.value[j] * inf2.value[i] + add) % 10;
					add = (inf1.value[j] * inf2.value[i] + add) / 10;
				}
				if (add > 0) {
					digit.power++;
					digit.value[digit.power - 1] = add;
					//digit.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow; unnecessary. we don't need the expression but the value
				}
			}
			res = res.operator+(digit);
		}//end of the calculation

		if (this->plus*n.plus < 0) {
			res.plus = -1;
			res.valueshow.insert(0, 1, '-');
		}
		else res.plus = 1;



	}
	return res;
}

Infint Infint::operator*(string num) {
	Infint n = Infint(num);
	Infint inf1;//save the first number
	Infint inf2, res, digit;// digit stores the result the number times different postion of digits
	int i, j, add;//add for result over 10
	res.valueshow = "";
	if (this->plus == 0 || n.plus == 0)
	{
		res.valueshow = "0";
	}
	else {
		res.plus = 1;//treat it as a postive number
		if (bigger(n, *this)) { //bigger as the first element so it runs faster
			inf1 = n;
			inf2 = *this;
		}
		else
		{
			inf1 = *this;
			inf2 = n;
		}
		for (i = 0; i < inf2.power; i++) {
			if (inf2.value[i] == 0)
			{
				digit.plus = 0;//tell the operator+ not to calculate again
			}
			else {
				digit.plus = 1;
				for (int k = 0; k < i; k++) digit.value[k] = 0;
				add = 0;//init
				digit.power = inf1.power + i;//call operator+ need the power (how many digits in the number)
				for (j = 0; j < inf1.power; j++) {
					digit.value[i + j] = (inf1.value[j] * inf2.value[i] + add) % 10;
					add = (inf1.value[j] * inf2.value[i] + add) / 10;
				}
				if (add > 0) {
					digit.power++;
					digit.value[digit.power - 1] = add;
					//digit.valueshow = (char)(inf.value[maxPower - 1] + 48) + inf.valueshow; unnecessary. we don't need the expression but the value
				}
			}
			res = res.operator+(digit);
		}//end of the calculation

		if (this->plus*n.plus < 0) {
			res.plus = -1;
			res.valueshow.insert(0, 1, '-');
		}
		else res.plus = 1;



	}
	return res;
}
Infint& Infint::operator++() {
	Infint inf = Infint(1);
	*this=this->operator+(inf);
	return *this;
}

Infint Infint::operator++(int) {
	Infint inf = Infint(1);
	Infint res=*this;//keep the original number
	*this= this->operator+(inf);
	return res;
}

Infint& Infint::operator--() {
	Infint inf = Infint(1);
	*this = this->operator-(inf);
	return *this;
}

Infint Infint::operator--(int) {
	Infint inf = Infint(1);
	Infint res = *this;//keep the original number
	*this = this->operator-(inf);
	return res;
}
	
void Infint:: operator+=(const Infint& n) {
	Infint inf = n;
	*this = this->operator+(inf);
}

void Infint:: operator+=(const int num) {
	Infint inf = Infint(num);
	*this = this->operator+(inf);
}

void Infint:: operator+=(const string num) {
	Infint inf = Infint(num);
	*this = this->operator+(inf);
}
void Infint:: operator-=(const Infint& n) {
	Infint inf = n;
	*this = this->operator-(inf);
}

void Infint:: operator-=(const int num) {
	Infint inf = Infint(num);
	*this = this->operator-(inf);
}

void Infint:: operator-=(const string num) {
	Infint inf = Infint(num);
	*this = this->operator-(inf);
}

void Infint:: operator*=(const Infint& n) {
	Infint inf = n;
	*this = this->operator*(inf);
}

void Infint:: operator*=(const int num) {
	Infint inf =Infint(num);
	*this = this->operator*(inf);
}

void Infint:: operator*=(const string num) {
	Infint inf = Infint(num);
	*this = this->operator*(inf);
}
