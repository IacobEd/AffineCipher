#include <iostream>
#include <fstream>

using namespace std;

#define MyInt int 

struct  Block {
	char c;
	int nr;
};

char caracter[100] = { 0 };
int N = 0;

void citeste_alfabet() {
	N = 0;
	ifstream in("alphabet.txt");
	if (!in.good())
		perror("Nonexistent file!");
	char c;
	while (in >> noskipws >> c) {
		caracter[N] = c;
		N++;
	}
	if (N == 0)
		cout << "Given alphabet have 0 characters" << endl;
}

int da_cod(char c) {
	for (int i = 0; i < N; i++)
		if (caracter[i] == c) return i;
	return -1;
}

int modulo(MyInt k, MyInt n) {
	if (k < 0)k = n - (-k) % n;
	if (k >= n) return k % n;
	return k;
}

char da_caracter(int cod) {
	return caracter[modulo(cod, N)];
}

int invers(MyInt a, MyInt n) {
	MyInt q, r, x0 = 1, x1 = 0, copy_n = n;
	a = modulo(a, n);
	while (n != 0)
	{
		r = n;
		q = a / n;
		n = a % n;
		a = r;

		r = x1;
		x1 = x0 - q * x1;
		x0 = r;
	}
	if (a == 1)
		return modulo(x0, copy_n);
	return -1;
}

void frequency(ifstream& in, Block bloc[]) {
	for (int i = 0; i < N; i++) {
		bloc[i].c = da_caracter(i);
		bloc[i].nr = 0;
	}
	char c;
	while (in >> noskipws >> c) {
		int cod = da_cod(c);
		if (cod >= 0)
			bloc[cod].nr++;
	}
	int ordonat = 0;
	while (!ordonat) {
		ordonat = 1;
		for (int i = 0; i < N - 1; i++) {
			if (bloc[i].nr < bloc[i + 1].nr) {
				ordonat = 0;
				Block temp = bloc[i];
				bloc[i] = bloc[i + 1];
				bloc[i + 1] = temp;
			}
		}
	}
}