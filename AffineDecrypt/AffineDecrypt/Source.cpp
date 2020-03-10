#include "resources.h"

void encrypt(char s1, char s2, char d1, char d2, int& a, int& b) {
	int inv = invers(da_cod(s2) - da_cod(s1), N);
	if (inv <= 0)
		return;
	a = modulo(inv * (da_cod(d2) - da_cod(d1)), N);
	b = modulo(da_cod(d1) - da_cod(s1) * a, N);
}

void main() {
	int a, b;
	Block bloc[100];
	citeste_alfabet();
	ifstream in("source.txt");
	ofstream out("destinatiion.txt");
	if (!in.good())
		perror("Nonexistent file");
	char c;

	char c1 = ' ', c2 = 'a', r1 = '.', r2 = 'T';
	encrypt(c1, c2, r1, r2, a, b);
	a = invers(a, N);
	b = modulo((-a) * b, N);

	while (in >> noskipws >> c) {
		out << da_caracter(da_cod(c) * a + b);
	}

	cout << "The key is (" << a << "," << b << ")" << endl;
	cout << "Finish!" << endl;
}
