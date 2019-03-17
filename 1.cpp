#include <iostream>
#include <string>
using namespace std;

class rejestracja {
public:
	string imie;
	string nazwisko;
	int numerek;
	static int liczba;
	void wczytaj();

	rejestracja(string im = " ", string naz = " ")
	{
		imie = im;
		nazwisko = naz;
		liczba++;
		numerek = liczba;
	}

	~rejestracja()
	{
		cout << "Destruktor" << endl;
		liczba--;
	}

	void liczbapacjentow()
	{
		cout << "Ile pacjentow " << liczba << endl;
	}
	rejestracja operator+(rejestracja r)
	{
		return rejestracja(imie,r.nazwisko);
	}
	rejestracja operator-(rejestracja r)
	{
		return rejestracja(r.imie, nazwisko);
	}
};

ostream& operator<<(ostream& stm, rejestracja r)
{
	return stm << r.numerek << " " << r.imie << " " << r.nazwisko << endl;
}
istream& operator>>(istream& stm, rejestracja r)
{
	return stm >> r.imie >> r.nazwisko;
}

void rejestracja::wczytaj()
{
	cin >> imie >> nazwisko;
}

class leki {
public:
	string nazwa;
	int cena;
	int ile;
	static int liczba;
	leki(string na, int ce, int il)
	{
		nazwa = na;
		cena = ce;
		ile = il;
		liczba++;
	}
	void wypisz()
	{
		cout << nazwa << " Cena:" << cena << " Ilosc:" << ile << endl;
	}
	void wpisz();
	~leki()
	{
		cout << "Destruktor" << endl;
		liczba--;
	}
	void ilelekow()
	{
		cout << "Ile lekow dostepnych " << liczba << endl;
	}
	int operator/(int i)
	{
		return cena*i;
	}
	void operator=(leki& l)
	{
		nazwa = l.nazwa;
		cena = l.cena;
		ile = l.ile;
	}
};

void leki::wpisz()
{
	cin >> nazwa >> cena >> ile;
}

int rejestracja::liczba = 0;
int leki::liczba = 0;


int main()
{
	rejestracja Aga("Aga", "Mala");
	cout << Aga << endl;
	rejestracja Ola("Ola", "Duza");
	cout << Aga + Ola << endl;
	cout << Aga - Ola << endl;
	cin >> Aga;

	leki Apap("Apap", 5, 12);
	cout << Apap / 5 << endl;
	leki Paracetamol("Paracetamol", 7, 2);
	Apap = Paracetamol;
	Apap.wypisz();


	system("pause");
}
