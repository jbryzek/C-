#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class pracownik {
public:
	static int licznik;
	int id = licznik - 1;
	unsigned int zmienne[3];
	pracownik() {
		cout << "Stworzono pracownika.\n";
	}
	~pracownik() {
		cout << "Usuniêto pracownika.\n";
	}

};
int pracownik::licznik = 1;
class biurowy : public pracownik {
public:
	string cecha;

	biurowy() {
		srand(time(NULL));

		zmienne[0] = rand() % 700 + 1800; 
		zmienne[1] = rand() % 25;
		zmienne[2] = rand() % 12;
	}
};

class informatyk : public pracownik {
public:
	string cecha;

	informatyk() {
		srand(time(NULL));

		zmienne[0] = rand() % 5500 + 2500;
		zmienne[1] = rand() % 50;
		zmienne[2] = rand() % 28;
	}

};

class kierownik : public pracownik {
public:
	string cecha;

	kierownik() {
		srand(time(NULL));

		zmienne[0] = rand() % 5500 + 2500; 
		zmienne[1] = rand() % 50;
		zmienne[2] = rand() % 28;
	}
	void wypisz()
	{
			cout << id << " " <<zmienne[0] << " " << zmienne[1] << " " << zmienne[2] << endl;
	}
};

template <int i, class Typ> class zespol {
public:
	int id, licznik;
	Typ *tab;
	int ilosc = i;
	zespol(Typ p)
	{
		tab = new Typ[ilosc];
		for (int k = 0; k < ilosc; k++)
			tab[k] = p[k];
	}
	~zespol() {delete tab; }
	void wypisz()
	{
		for (int l; l < ilosc; l++)
			cout << tab[l].id << " " << tab[l].zmienne[0] << " " << tab[l].zmienne[1]<<" " << tab[l].zmienne[2] << endl;
	}
};

int main() 
{
	zespol<4, biurowy>ksiegowosc(biurowy(),biurowy(),biurowy(),biurowy());
	zespol<5, informatyk>softwarehouse(informatyk(), informatyk(), informatyk(), informatyk(), informatyk());
	zespol<3, kierownik>zarzad(kierownik(), kierownik(), kierownik());

	kierownik ela;
	ela.wypisz();

	typedef zespol<4, informatyk>dreamTeam;
	typedef zespol<2, biurowy>likwidacja;

	system("pause");
}