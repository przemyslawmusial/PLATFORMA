#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;


class Test
{
private:

	/*int wynik_testu;
	int id_testu;*/

public:
	/*Test(int id_testu) {
		this->id_testu = id_testu;
	}*/
	
	int Zobacz_Wynik(int id_studenta, int id_testu);
	int Zobacz_Wyniki_Studentow();
	void dodajTest(int idTestu, string pytanie, string a, string b, string c, string d, string x) { //testy sa tak w pliku [pytanie a b c d x] abcd odpowiedzi, x poprawna odpowiedz
		fstream plikTesty;

		plikTesty.open("testy.txt",ios::app);
		plikTesty << endl <<idTestu<<"	 "<< pytanie <<" "<< a << " " << b << " " << c << " " << d<<" "<<x;

	}
	int Rozwiaz_Test(Student* student1, int id_testu) {
		if (student1->czyZalogowany() == 1) {

		}
	}
};





//co to za gowno 
class Weryfikacja_Danych
{
public:
	bool Weryfikacja_danych(int login, int haslo);
};

class Uwaga
{
private:
	int id_uwagi;
	string tresc_uwagi;
	int id_studenta_dodajacego;

public:
	string Zobacz_Uwage(int id_uwagi);
	string Dodaj_Uwage(int id_studenta);
};

class Student {
	string imie;
	string nazwisko;
	int nrAlbumu;
	int pesel;
	string login;
	string haslo;
	bool czyUdaloSieZalogowac=false;
public:
	Student(string imie, string nazwisko, int nrAlbumu, int pesel, string login, string haslo) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->nrAlbumu = nrAlbumu;
		this->pesel = pesel;
		this->haslo = haslo;
		this->login = login;
	}
	string giveLogin() {
		return login;
	}
	string givePass() {
		return haslo;
	}
	int giveAlbum() {
		return nrAlbumu;
	}
	void pomyslneLogowanie() {
		czyUdaloSieZalogowac = true;
	}
	bool czyZalogowany() {
		if (czyUdaloSieZalogowac) {
			return 1;
		}
	}
};

class Logowanie {
	
public:

	void zaloguj(Student* student1) {
		fstream plikLogowanie;
		int a;	// zczytywanie z wiersza 1 wyrazu     [ wiersz jest taki: nrAlbumu login haslo ]
		string b, c; //zczytywanie 2 i 3 wyrazu 
		bool sukces = false;
		plikLogowanie.open("loginy.txt", ios::in);

		while (!plikLogowanie.eof()) {
			plikLogowanie >> a;
			plikLogowanie >> b;
			plikLogowanie >> c;

			if ( ( (student1->giveAlbum()  == a) && (student1->giveLogin() == b) && (student1->givePass()==c) ) ) {
				student1->pomyslneLogowanie();
				sukces = true;
				cout << "zalogowano pomyslnie" << endl;
				break;
			}
			
		}
		if (!sukces) {
			cout << "nie udalo sie zalogowac" << endl;
		}
		plikLogowanie.close();
	}

	void zarejestruj(Student* student1) {
		int a;	// zczytywanie z wiersza 1 wyrazu     [ wiersz jest taki: nrAlbumu login haslo ]
		string b, c; //zczytywanie 2 i 3 wyrazu     
		bool unikatowyStudent = true;

		fstream plikLogowanie;
		plikLogowanie.open("loginy.txt", ios::in );
		while (!plikLogowanie.eof()) {
			plikLogowanie >> a;
			
			if (a == student1->giveAlbum()) {
				cout << "Student o tym numerze albumu jest juz zarejestrowany";
				unikatowyStudent = false;
				break;
			}
			plikLogowanie >> b;
			plikLogowanie >> c;
		}
		plikLogowanie.close();
		plikLogowanie.open("loginy.txt", ios::app);
		if (unikatowyStudent) {
			cout << "Zarejestrowano pomyslnie!" << endl;
			plikLogowanie <<endl<< student1->giveAlbum() <<" "<< student1->giveLogin() <<" "<< student1->givePass();
		}
		plikLogowanie.close();
	}
};

class Wykladowca {
	string imie;
	string nazwisko;
	string tytul;
};

int main()
{
	Student student1("Maciej","Kowalski",1,123,"xd","maciej1");
	Student student2("Jerzy", "grzyb", 2, 123, "xdd", "al1");
	Student student3("Michal", "Borowik", 3, 123, "xdd", "konr");
	
	Logowanie zaloguj;
	
//	zaloguj.zarejestruj(&student3);
//	zaloguj.zaloguj(&student3);
	Test test1;
	test1.dodajTest(1,"ile to 2+2", "23", "32", "4", "44", "4");

	cout << "xd";
	
}
