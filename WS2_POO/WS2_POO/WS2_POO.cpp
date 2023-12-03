#include "pch.h"
#include <iostream>
using namespace std;

class gpcs1s1 {
private:
	int m_c2;
public:
	gpcs1s1(int C1, int C2) : m_c1(C1), m_c2(C2){} // Constructeur
	int m_c1;
};

class gpcs1s2 {
private:
public:
	gpcs1s2(int C3) : m_c3(C3){} // Constructeur
	int m_c3;
};

class gpcs2s1 {
private:
	gpcs1s1* p1;
	gpcs1s2* p2;
public:
	int C1 = p1->m_c1;
	int C3 = p2->m_c3;
	gpcs2s1(int C1, int C3){}
};

int main() {
	gpcs1s1 zehaha = new gpcs1s1(2, 4);
	gpcs1s2 rololo = new gpcs1s2(6);
	//gpcs2s1* yihaha = new gpcs2s1();

	cout << zehaha << endl;
	cout << rololo << endl;

	delete zehaha, rololo/*, yihaha*/;
};