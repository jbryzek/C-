#include <iostream>
#include <string>
using namespace std;
class leki;
class rejestracja {
    friend class leki;
	string imie;
	string nazwisko;
	int numerek;
	static int liczba;
public:
	void wczytaj();

	rejestracja(string im=" ",string naz=" ")//bezparametrow
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
	void wypisz()
	{
		cout <<numerek<<" "<< imie << " " << nazwisko << " " << endl;
	}

	void liczbapacjentow()
	{
		cout << "Ile pacjentow "<<liczba<<endl;
	}
};

void rejestracja::wczytaj()
{
	cin >> imie >> nazwisko;
}

class leki {
	string nazwa;
	int cena;
	int ile;
	static int liczba;
public:
	leki(string na, int ce, int il)//z parametrami
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
		cout <<"Ile lekow dostepnych "<< liczba << endl;
	}
	void ten_lek(rejestracja p)
	{
	    cout<<p.imie<<" "<<p.nazwisko<<" " << nazwa<<endl;
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
    int a=2;
    rejestracja *tabrej=new rejestracja[a];
    for(int i=0;i<a;i++)
        tabrej[i].wczytaj();

	leki tablek[2]={leki("Aspiryna", 12,10),leki("Apap", 11, 2)};
	tablek[0].wypisz();
	tablek[1].wypisz();
	tablek[1].ten_lek(tabrej[0]);

	delete []tabrej;
	delete []tablek;
	return 0;
}
