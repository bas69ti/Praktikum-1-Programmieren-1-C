#include<algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

#define PI atan(1)*4



void HelloWorld() {
	printf("%s", "Hello World!\n");
}

void Datentypengroessen() {

	const int groesse[] { sizeof(char), sizeof(unsigned char), sizeof(short), sizeof(unsigned short), sizeof(int), sizeof(unsigned int), sizeof(long), sizeof(unsigned long), sizeof(float), sizeof(double), sizeof(long double) };
	const char* namen[]{ "char: ", "unsigned char:", "short: ", "unsigned short: ", "int: ", "unsigned int: ", "long: ", "unsigned long: ", "float: ", "double: ", "long double: " };
	
	printf("%s", "Datentypgroessen\n");

	for (int i = 0; i < sizeof(groesse) / sizeof(*groesse); i++) {
		printf("%-20s\t%i %s\n", namen[i], groesse[i], groesse[i] > 1 ? "bytes" : "byte");
	}

}

float Fahrzeuggeschwindigkeit(const float& r, float&& a,float&& b) {

	float rga {float(2 * PI * r * a) };
	float rgb {float(2 * PI * r * b) };

	return float{ (rga + rgb) / 2 };
}

void Waehrungsumrechnung() {
	//eigentlich rechtsbündig
	const float werte[]{ 1, 2, 5, 10, 20, 50, 100 };

	const double KursEuroInUsd{ 1.16 };
	const double KursUsdInEuro{ 0.86 };

	printf("%-10s%-10s\n", "EUR", "USD");

	for (int i = 0; i < sizeof(werte) / sizeof(*werte); i++) {
		printf("%-10.2f%-10.2f\n", *(werte + i), *(werte + i) * KursEuroInUsd);
	}

	printf("\n%-10s%-10s\n", "USD", "EUR");

	for (int i = 0; i < sizeof(werte) / sizeof(*werte); i++) {
		printf("%-10.2f%-10.2f\n", *(werte + i), *(werte + i) * KursUsdInEuro);
	}
}

vector<int> v;

template<int n, int i>
struct isprim {
	static const int prim{ (n % i) && isprim<(i > 2 ? n : 0), i - 1 >::prim };
};

template<>
struct isprim<0, 1> {
	static const int prim{ 1 };
};

template<int i>
struct printp {
	printp<i - 1> a;
	static const int p{ isprim<i, i - 1>::prim };
	
	printp() {
		if (p) {
			int s{ 0 }, j = i;
			while (j > 0) {
				s += j % 10;
				j /= 10;
			}
			v.push_back(s);
			s = 0;
		}
	};
};

template<>
struct printp<2> {
	printp() {
		v.push_back(2);
	}
};

template<int n>
class prmar {

private:
	int arr[n];
	int c{ 0 }, x;

	int prm(int i, int n) {
		return i > 1 ? n % i ? prm(i - 1, n) : 0 : 1;
	}

public:
	prmar() : x(n) {
		while (x > 2) {
			if (prm(x - 1, x))
				arr[c++] = x;
			--x;
		}
	};

	void ausg() {
		int b = 0;
		while (b < size(arr))
			cout << arr[b] << '\n';
		++b;
	}
};



void prp(int n) {

	
}

int main() {

	prmar<10> p;

	p.ausg();

	//mark(10);

	//Aufgabe 1:
	//HelloWorld();

	//mark(10);

	//Aufgabe 2:
	//Datentypengroessen();

	//mark(10);

	//Aufgabe 3:
	//float f = Fahrzeuggeschwindigkeit(0.7, 10, 8);
	//printf("Durchschnittsgeschwindigkeit:\t%f m/s\t%f km/h\n",f , f * 3.6);

	//mark(10);

	//Aufgabe 4:
	//Waehrungsumrechnung();

}