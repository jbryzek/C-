#include <iostream>
#include <string>
using namespace std;
//gabinet lekarski

namespace n {
	class lekarze {
	public:
		string imie;
		string nazwisko;
		string specjalnosc;
		static int liczba;
		int numerek;
		void wypisz_dane() {
			cout << numerek<<" "<< imie << " " << nazwisko << " " << specjalnosc << endl;
		};
		lekarze(string im=" ",string naz=" ",string spec=" "){
			imie = im;
			nazwisko = naz;
			specjalnosc = spec;
			liczba++;
			numerek = liczba;
	};
		void ilelekarzy() {
			cout <<"W przychodzi pracuje: "<<liczba<<" lekarzy" << endl;
		}
	};
	int lekarze::liczba = 0;
}

class rejestracja {
	class dane {
	public:
		string imie;
		string nazwisko;
		void wpisz_dane();
	};
	static int liczba;
	int numerek;
	
public:
	dane d;
	rejestracja(string im = " ", string naz = " ")
	{
		d.imie = im;
		d.nazwisko = naz;
		liczba++;
		numerek = liczba;
	}
	void wypisz()
	{
		cout << numerek << " " << d.imie << " " << d.nazwisko << " " << endl;
	}


};
int rejestracja::liczba = 0;

void rejestracja::dane::wpisz_dane() {
	cin >> imie >> nazwisko;
}

int main() {
	rejestracja jan("Jan", "Kowalski");
	jan.wypisz();
	rejestracja ola;
	ola.wypisz();
	ola.d.wpisz_dane();
	n::lekarze p("Jan", "Bytnar", "okulista");
	n::lekarze d("Ewa", "Hojnac", "chirurg");
	p.wypisz_dane();
	d.ilelekarzy();
	system("pause");
}