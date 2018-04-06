// main.cpp

#include <iostream>
#include "infint.hpp"
using namespace std;

int main() {
    Infint num = Infint("194981297390127940");
    Infint num2 = Infint("-194981297390127940");
    Infint num3 = Infint();
//    // or Infint num = Infint(0);
//
//
//    num = num + 1;  // num is equal to "1"
//    num += 1;       // num is equal to "2"
//    num += "8";       // num is equal to "10"
//    num -= "5";     // num is equal to "5"
//    num -= num;     // num is equal to "0"
//
//
//    num = 1;                // num is equal to "1"
//    num++;                  // num is equal to "2"
//    num = num + num + 1;    // num is equal to "5"
//    num--;                  // num is equal to "4"
//
    std::cout << num<< std::endl;
    std::cout << num2<< std::endl;
	//std::cout << num.power << endl;
	//for (int i=num.power;i>=0;i--) std::cout << num.value[i] << " ";
	std::cout << "_______" << std::endl;
	//std::cout << num3 << std::endl;
	num3 = num2+ num;
	num=num3--;
	/*cout << num.plus << endl;*/
	//for (int i = 20; i >= 0; i--) std::cout << num3.value[i] << " ";
	std::cout << num3 << std::endl;
	std::cout << num << std::endl;
	getchar();
	getchar();
	return 0;
	
}

