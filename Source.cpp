#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

class Student {
	string imie;
	string nazwisko;
	string nrAlbumu;
	string login;
	string haslo;
	bool czyUdaloSieZalogowac = false;
public:
	Student() {};
	Student(string imie, string nazwisko, string nrAlbumu, string login, string haslo) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->nrAlbumu = nrAlbumu;

		this->haslo = haslo;
		this->login = login;
	}
	void set(string imie, string nazwisko, string nrAlbumu, string login, string haslo) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->nrAlbumu = nrAlbumu;

		this->haslo = haslo;
		this->login = login;
	}

	Student(const Student& s) {
		imie = s.imie;
		nazwisko = s.nazwisko;
		nrAlbumu = s.nrAlbumu;
		haslo = s.haslo;
		login = s.login;

	}

	string giveID() {
		return nrAlbumu;
	}
	string giveImie() {
		return imie;
	}
	string giveNazwisko() {
		return nazwisko;
	}
	void pomyslneLogowanie() {
		czyUdaloSieZalogowac = true;
	}
	void wylogowanie() {
		czyUdaloSieZalogowac = false;
	}
	int czyZalogowany() {
		if (czyUdaloSieZalogowac) {
			return 1;
		}
		else return 0;
	}
};
class Wykladowca {
	string imie;
	string nazwisko;
	string tytul;
	string ID;
	bool czyUdaloSieZalogowac;
public:
	string giveID() {
		return ID;
	}
	string giveImie() {
		return imie;
	}
	string giveNazwisko() {
		return nazwisko;
	}
	string giveTytul() {
		return tytul;
	}
	void pomyslneLogowanie() {
		czyUdaloSieZalogowac = true;
	}
	int czyZalogowany() {
		if (czyUdaloSieZalogowac) {
			return 1;
		}
		else return 0;
	}
	void wylogowanie() {
		czyUdaloSieZalogowac = false;
	}
	void set(string imie, string nazwisko, string tytul, string id) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->tytul = tytul;
		this->ID = id;
	}

};
class Test
{
private:
	/*int wynik_testu;
	int id_testu;*/

public:
	int dodajTest()
	{
		string line;
		string nazwaPliku;
		fstream plik, plikTesty;
		int i = 1;
		string liczbaPytan;
		cout << "DODAJ TEST:" << endl << "Wpisz nazwe pliku, ktory chcesz dodac." << endl;
		char znak;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && nazwaPliku.length() > 0)
			{
				nazwaPliku.pop_back();
				system("cls");
				cout << "DODAJ TEST:" << endl << "Wpisz nazwe pliku, ktory chcesz dodac." << endl;
				cout << nazwaPliku;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				nazwaPliku = nazwaPliku + znak;
				cout << znak;
			}
		}
		cout << "Wpisz liczbe pytan testu, ktory dodajesz." << endl;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && liczbaPytan.length() > 0)
			{
				liczbaPytan.pop_back();
				system("cls");
				cout << "DODAJ TEST:" << endl << "Wpisz nazwe pliku, ktory chcesz dodac." << endl;
				cout << nazwaPliku << endl;
				cout << "Wpisz liczbe pytan testu, ktory dodajesz." << endl;
				cout << liczbaPytan;
			}
			else if (znak == 13)
			{
				system("cls");
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				liczbaPytan = liczbaPytan + znak;
				cout << znak;
			}
		}

		plik.open(nazwaPliku, ios::in);

		if (plik.good() == false)
		{
			cout << "Plik nie istnieje! Kliknij dowolny klawisz aby kontynuowac." << endl;
			system("pause");
			system("cls");
			return 0;
		}

		//sprawdzanie jakie ID bedzie mial nowy test
		plikTesty.open("testy.txt", ios::in);

		while (getline(plikTesty, line)) {
			if (line.empty()) {
				i++;
			}
		}
		plikTesty.close();
		plikTesty.open("testy.txt", ios::app);



		plikTesty << endl << i << "###" << endl << liczbaPytan << endl;
		while (getline(plik, line)) {
			plikTesty << line << endl;
		}
		plik.close();
		plikTesty.close();
		cout << "Pomyslnie dodano test. Kliknij dowolny klawisz aby kontynuowac." << endl;
		system("pause");
		system("cls");
		return 1;
	}


	int rozwiazTest(string idStudenta) {
		int wynik = 0;


		int numerTestu;
		int liczbaPytan;
		int counter = 1;
		string counter1 = "1";
		string line;
		string odp;
		fstream plikTesty;
		fstream plikWyniki;
		plikTesty.open("testy.txt", ios::in);
		plikWyniki.open("wyniki.txt", ios::app);
		//sa testy, wyswietla dostepne
		if (plikTesty.good()) {


			cout << "Ponizej wyswietlone sa numery ID dostepnych testow: " << endl;
			cout << "Wybierz test na klawiaturze i potwierdz przyciskiem Enter" << endl << endl;
			while (getline(plikTesty, line)) {
				if (line == counter1 + "###") {
					cout << counter << ". " << endl;
					counter++;
					counter1 = to_string(counter);
				}
			}
			if (counter == 1) {//jak zaden sie nie dodal, to zadnego nie ma
				cout << "Nie ma zadnych testow" << endl;
				return 0;
			}

		}
		//nie ma pliku
		else {
			cout << "Nie ma zadnych testow" << endl;
			return 0;
		}

		plikTesty.close();
		plikTesty.open("testy.txt", ios::in);

		cout << endl << "Wybierz test" << endl;
		cin >> numerTestu;
		system("cls");
		string nrString = to_string(numerTestu);
		int numerNastepnegoPytania = numerTestu + 1;
		string nrStringNastepnego = to_string(numerNastepnegoPytania);




		while (getline(plikTesty, line)) {


			if (line == nrStringNastepnego + "###") {
				system("cls");
				cout << "Koniec testu!" << endl;
				cout << "Twoj wynik wynosi: " << wynik << "/" << liczbaPytan << endl;

				//break;
			}


			if (nrString + "###" == line) {
				getline(plikTesty, line);
				liczbaPytan = stoi(line);

				for (int i = 0; i < liczbaPytan; i++) {
					for (int j = 0; j < 5; j++) {
						getline(plikTesty, line);
						if (j == 0)
							cout << line << endl;
						if (j == 1) {
							cout << "a) " << line << endl;
						}
						else if (j == 2) {
							cout << "b) " << line << endl;
						}
						else if (j == 3) {
							cout << "c) " << line << endl;
						}
						else if (j == 4) {
							cout << "d) " << line << endl;
						}
					}
					getline(plikTesty, line);
					cout << "Podaj odpowiedz wpisujac a,b,c lub d " << endl;

					odp = _getch();

					if (odp == line) {
						cout << "Prawidlowa odpowiedz!" << endl << endl;
						wynik++;
					}
					else {
						cout << line << endl;
						cout << "Zla odpowiedz!" << endl << endl;
					}
				}


				if (numerTestu == (counter - 1)) {
					system("cls");
					cout << "Koniec testu!" << endl;
					cout << "Twoj wynik wynosi: " << wynik << "/" << liczbaPytan << endl;


				}
			}

		}
		plikWyniki << idStudenta << " " << numerTestu << " " << wynik << " " << liczbaPytan << endl;


		return 1;

	}
	int zobaczWynikiStudentow() {
		fstream plikWyniki;

		string a, c;
		string b;
		string d;
		string line;
		plikWyniki.open("wyniki.txt", ios::in);
		getline(plikWyniki, line);
		if (line.empty()) {
			cout << endl << "Brak Wynikow" << endl;
			cout << endl << "Nacisnij dowolny klawisz aby powrocic." << endl;
			plikWyniki.close();
			return 1;
		}
		plikWyniki.close();
		plikWyniki.open("wyniki.txt", ios::in);

		cout << "Wyniki studentow: " << endl << endl;
		while (!plikWyniki.eof())
		{
			plikWyniki >> a;
			plikWyniki >> b;
			plikWyniki >> c;
			plikWyniki >> d;

			if (!plikWyniki.good())
			{
				break;
			}

			cout << "Indeks studenta: " << a << "  " << "Numer testu: " << b << "   " << "Wynik z testu: " << c << "/" << d << endl;
		}
		cout << endl << "Nacisnij dowolny klawisz aby powrocic." << endl;
		plikWyniki.close();
		return 1;
	}

	int zobaczWyniki(string ID) {  //jednego studenta
		fstream plikWyniki;

		string a;
		string b, c;  // [indeks nrTestu wynik]
		string d;
		bool czySaTesty = false;
		plikWyniki.open("wyniki.txt", ios::in);
		cout << "Wyniki studenta: " << endl << endl;
		while (!plikWyniki.eof()) {
			plikWyniki >> a;
			plikWyniki >> b;
			plikWyniki >> c;
			plikWyniki >> d;
			if (a == ID) {
				cout << "Numer testu: " << b << "   " << "Wynik z testu: " << c << "/" << d << endl;
				a = -1;
				czySaTesty = true;
			}
		}
		if (czySaTesty == false) {
			cout << "Brak ukonczonych testow" << endl;
		}
		cout << endl << "Nacisnij dowolny klawisz aby powrocic." << endl;
		plikWyniki.close();
		return 1;
	}
};
class Logowanie
{

public:

	int zaloguj(Student* student1)
	{

		fstream plikLogowanie;
		// zczytywanie z wiersza 1 wyrazu     [ wiersz jest taki: album imie nazwisko login haslo ]
		string a, b, c, d, e; //zczytywanie imie nazwisko login haslo 
		bool sukces = false;

		plikLogowanie.open("loginy.txt", ios::in);

		string wprowadzonyAlbum;
		string wprowadzonyLogin;
		string wprowadzoneHaslo;
		cout << "Wybrano opcje logowanie studenta." << endl;
		cout << "Wprowadz nr albumu:" << endl;
		char znak;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzonyAlbum.length() > 0)
			{
				wprowadzonyAlbum.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie studenta" << endl;
				cout << "Wprowadz nr albumu:" << endl;
				cout << wprowadzonyAlbum;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzonyAlbum = wprowadzonyAlbum + znak;
				cout << znak;
			}
		}
		cout << "Wprowadz login:" << endl;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzonyLogin.length() > 0)
			{
				wprowadzonyLogin.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie studenta" << endl;
				cout << "Wprowadz nr albumu:" << endl;
				cout << wprowadzonyAlbum << endl;
				cout << "Wprowadz login:" << endl;
				cout << wprowadzonyLogin;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzonyLogin = wprowadzonyLogin + znak;
				cout << znak;
			}
		}
		cout << "Wprowadz haslo:" << endl;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzoneHaslo.length() > 0)
			{
				wprowadzoneHaslo.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie studenta" << endl;
				cout << "Wprowadz nr albumu:" << endl;
				cout << wprowadzonyAlbum << endl;
				cout << "Wprowadz login:" << endl;
				cout << wprowadzonyLogin << endl;
				cout << "Wprowadz haslo:" << endl;
				cout << wprowadzoneHaslo;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzoneHaslo = wprowadzoneHaslo + znak;
				cout << znak;
			}
		}

		while (!plikLogowanie.eof())
		{
			plikLogowanie >> a;
			plikLogowanie >> b;
			plikLogowanie >> c;
			plikLogowanie >> d;
			plikLogowanie >> e;

			if (((wprowadzonyAlbum == a) && (wprowadzonyLogin == d) && (wprowadzoneHaslo == e))) {

				student1->pomyslneLogowanie();
				student1->set(b, c, a, d, e);
				sukces = true;


				plikLogowanie.close();
				return 1;


			}

		}
		if (!sukces) {
			cout << "Nie udalo sie zalogowac. Wcisnij dowolny klawisz aby kontynuowac." << endl;
			plikLogowanie.close();
			system("pause");
		}
	}
	int zaloguj(Wykladowca* wykladowca1)
	{

		fstream plikLogowanie;
		// zczytywanie z wiersza 1 wyrazu     [ wiersz jest taki: album imie nazwisko login haslo ]
		string a, b, c, d, e; //zczytywanie imie nazwisko login haslo 
		bool sukces = false;

		plikLogowanie.open("loginy.txt", ios::in);

		string wprowadzonyAlbum;
		string wprowadzonyLogin;
		string wprowadzoneHaslo;
		cout << "Wybrano opcje logowanie wykladowcy" << endl;
		cout << "Wprowadz ID wykladowcy:" << endl;
		char znak;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzonyAlbum.length() > 0)
			{
				wprowadzonyAlbum.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie wykladowcy" << endl;
				cout << "Wprowadz ID wykladowcy:" << endl;
				cout << wprowadzonyAlbum;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzonyAlbum = wprowadzonyAlbum + znak;
				cout << znak;
			}
		}
		cout << "Wprowadz login:" << endl;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzonyLogin.length() > 0)
			{
				wprowadzonyLogin.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie wykladowcy" << endl;
				cout << "Wprowadz ID wykladowcy:" << endl;
				cout << wprowadzonyAlbum << endl;
				cout << "Wprowadz login:" << endl;
				cout << wprowadzonyLogin;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzonyLogin = wprowadzonyLogin + znak;
				cout << znak;
			}
		}
		cout << "Wprowadz haslo:" << endl;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return 0;
			}
			else if (znak == 8 && wprowadzoneHaslo.length() > 0)
			{
				wprowadzoneHaslo.pop_back();
				system("cls");
				cout << "Wybrano opcje logowanie wykladowcy" << endl;
				cout << "Wprowadz ID wykladowcy:" << endl;
				cout << wprowadzonyAlbum << endl;
				cout << "Wprowadz login:" << endl;
				cout << wprowadzonyLogin << endl;
				cout << "Wprowadz haslo:" << endl;
				cout << wprowadzoneHaslo;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzoneHaslo = wprowadzoneHaslo + znak;
				cout << znak;
			}
		}

		while (!plikLogowanie.eof())
		{
			plikLogowanie >> a;
			plikLogowanie >> b;
			plikLogowanie >> c;
			plikLogowanie >> d;
			plikLogowanie >> e;

			if (((wprowadzonyAlbum == "-10") && (wprowadzonyLogin == d) && (wprowadzoneHaslo == e))) {

				cout << "Zalogowano jako wykladowca!" << endl;
				wykladowca1->pomyslneLogowanie();
				wykladowca1->set(b, c, "Profesor", a);
				sukces = true;
				//  cout << b << " " << c << " zalogowano pomyslnie" << endl;
				plikLogowanie.close();
				return 1;
			}

		}
		if (!sukces) {
			cout << "Nie udalo sie zalogowac. Wcisnij dowolny klawisz aby kontynuowac." << endl;
			plikLogowanie.close();
			system("pause");
		}

	}
	void zarejestruj(Student* student1)
	{
		system("cls");
		// zczytywanie z wiersza 1 wyrazu     [ wiersz jest taki: album imie nazwisko login haslo ]
		string a, b, c, d, e; //zczytywanie imie nazwisko login haslo
		bool unikatowyStudent = true;
		fstream plikLogowanie;
		string wprowadzonyAlbum;
		string wprowadzoneImie;
		string wprowadzoneNazwisko;
		string wprowadzonyLogin;
		string wprowadzoneHaslo;
		plikLogowanie.open("loginy.txt", ios::in);
		cout << "Wybrano opcje rejestracja" << endl;
		cout << "Wprowadz nr albumu:" << endl;
		char znak;
		for (;;)
		{
			znak = _getch();
			if (znak == 27)
			{
				system("cls");
				return;
			}
			else if (znak == 8 && wprowadzonyAlbum.length() > 0)
			{
				wprowadzonyAlbum.pop_back();
				system("cls");
				cout << "Wybrano opcje rejestracja" << endl;
				cout << "Wprowadz nr albumu:" << endl;
				cout << wprowadzonyAlbum;
			}
			else if (znak == 13)
			{
				cout << endl;
				break;
			}
			else if (znak >= 32 && znak <= 126)
			{
				wprowadzonyAlbum = wprowadzonyAlbum + znak;
				cout << znak;
			}
		}

		while (!plikLogowanie.eof()) {
			plikLogowanie >> a;

			if (a == wprowadzonyAlbum) {
				system("cls");
				unikatowyStudent = false;
				cout << "Student o tym numerze albumu jest juz zarejestrowany." << endl;
				cout << "Kliknij dowolny klawisz aby kontynuowac." << endl;
				system("pause");
				return;
			}

			plikLogowanie >> b;
			plikLogowanie >> c;
			plikLogowanie >> d;
			plikLogowanie >> e;
		}

		if (unikatowyStudent) {
			plikLogowanie.close();
			plikLogowanie.open("loginy.txt", ios::app);

			cout << "Podaj imie:" << endl;
			for (;;)
			{
				znak = _getch();
				if (znak == 27)
				{
					system("cls");
					return;
				}
				else if (znak == 8 && wprowadzoneImie.length() > 0)
				{
					wprowadzoneImie.pop_back();
					system("cls");
					cout << "Wybrano opcje rejestracja" << endl;
					cout << "Wprowadz nr albumu:" << endl;
					cout << wprowadzonyAlbum << endl;
					cout << "Podaj imie:" << endl;
					cout << wprowadzoneImie;
				}
				else if (znak == 13)
				{
					cout << endl;
					break;
				}
				else if (znak >= 32 && znak <= 126)
				{
					wprowadzoneImie = wprowadzoneImie + znak;
					cout << znak;
				}
			}
			cout << "Podaj nazwisko:" << endl;
			for (;;)
			{
				znak = _getch();
				if (znak == 27)
				{
					system("cls");
					return;
				}
				else if (znak == 8 && wprowadzoneNazwisko.length() > 0)
				{
					wprowadzoneNazwisko.pop_back();
					system("cls");
					cout << "Wybrano opcje rejestracja" << endl;
					cout << "Wprowadz nr albumu:" << endl;
					cout << wprowadzonyAlbum << endl;
					cout << "Podaj imie:" << endl;
					cout << wprowadzoneImie << endl;
					cout << "Podaj nazwisko:" << endl;
					cout << wprowadzoneNazwisko;
				}
				else if (znak == 13)
				{
					cout << endl;
					break;
				}
				else if (znak >= 32 && znak <= 126)
				{
					wprowadzoneNazwisko = wprowadzoneNazwisko + znak;
					cout << znak;
				}
			}
			cout << "Podaj login:" << endl;
			for (;;)
			{
				znak = _getch();
				if (znak == 27)
				{
					system("cls");
					return;
				}
				else if (znak == 8 && wprowadzonyLogin.length() > 0)
				{
					wprowadzonyLogin.pop_back();
					system("cls");
					cout << "Wybrano opcje rejestracja" << endl;
					cout << "Wprowadz nr albumu:" << endl;
					cout << wprowadzonyAlbum << endl;
					cout << "Podaj imie:" << endl;
					cout << wprowadzoneImie << endl;
					cout << "Podaj nazwisko:" << endl;
					cout << wprowadzoneNazwisko << endl;
					cout << "Podaj login:" << endl;
					cout << wprowadzonyLogin;
				}
				else if (znak == 13)
				{
					cout << endl;
					break;
				}
				else if (znak >= 32 && znak <= 126)
				{
					wprowadzonyLogin = wprowadzonyLogin + znak;
					cout << znak;
				}
			}
			cout << "Podaj haslo:" << endl;
			for (;;)
			{
				znak = _getch();
				if (znak == 27)
				{
					system("cls");
					return;
				}
				else if (znak == 8 && wprowadzoneHaslo.length() > 0)
				{
					wprowadzoneHaslo.pop_back();
					system("cls");
					cout << "Wybrano opcje rejestracja" << endl;
					cout << "Wprowadz nr albumu:" << endl;
					cout << wprowadzonyAlbum << endl;
					cout << "Podaj imie:" << endl;
					cout << wprowadzoneImie << endl;
					cout << "Podaj nazwisko:" << endl;
					cout << wprowadzoneNazwisko << endl;
					cout << "Podaj login:" << endl;
					cout << wprowadzonyLogin << endl;
					cout << "Podaj haslo:" << endl;
					cout << wprowadzoneHaslo;
				}
				else if (znak == 13)
				{
					cout << endl;
					break;
				}
				else if (znak >= 32 && znak <= 126)
				{
					wprowadzoneHaslo = wprowadzoneHaslo + znak;
					cout << znak;
				}
			}
			cout << "Zarejestrowano pomyslnie! Wcisnij dowolny klawisz aby kontynuowac." << endl;
			system("pause");
			plikLogowanie << endl << wprowadzonyAlbum << " " << wprowadzoneImie << " " << wprowadzoneNazwisko << " " << wprowadzonyLogin << " " << wprowadzoneHaslo;
		}
		plikLogowanie.close();
		return;
	}
};
class Uwaga
{
public:
	void dodajUwage(string idStudenta)
	{

		system("cls");
		string id = idStudenta;
		string tresc;
		cout << "Napisz tutaj swoja uwage i zatwierdz klawiszem ENTER:" << endl;

		for (;;)
		{
			char znak;
			int czyWyjsc = 0;
			for (;;)
			{
				znak = _getch();
				if (znak == 27)
				{
					system("cls");
					return;
				}
				else if (znak == 8 && tresc.length() > 0)
				{
					tresc.pop_back();
					system("cls");
					cout << "Napisz tutaj swoja uwage i zatwierdz klawiszem ENTER:" << endl;
					cout << tresc;
				}
				else if (znak == 13)
				{
					system("cls");
					break;
				}
				else if (znak >= 32 && znak <= 126)
				{
					tresc = tresc + znak;
					cout << znak;
				}
			}

			if (tresc == "")
			{
				system("cls");
				cout << "Nie mozna dodac pustej uwagi. Sprobuj ponownie. Kliknij dowolny klawisz aby kontynuowac." << endl;
				system("pause");
				system("cls");
				cout << "Napisz tutaj swoja uwage i zatwierdz klawiszem ENTER:" << endl;
			}
			else
			{
				ofstream zapis("uwagi.txt", ios_base::app);
				zapis << tresc << endl << idStudenta << endl << "##########################" << endl;
				zapis.close();

				int iloscUwag = 0;
				ifstream odczyt("ileUwag.txt");
				odczyt >> iloscUwag;
				odczyt.close();

				iloscUwag++;

				ofstream zapisIlosci("ileUwag.txt");
				zapisIlosci << iloscUwag;
				zapisIlosci.close();

				system("cls");
				cout << "Twoja uwaga zostala pomyslnie dodana. Dziekujemy! Wcisnij dowolny klawisz aby powrocic do menu" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	void zobaczUwagi()
	{
		system("cls");

		int iloscUwag = 0;
		ifstream odczyt("ileUwag.txt");
		odczyt >> iloscUwag;
		odczyt.close();

		if (iloscUwag == 0)
		{
			cout << "Nie ma zadnych zgloszonych uwag. Nacisnij dowolny klawisz aby powrocic." << endl;
			system("pause");
			system("cls");
			return;
		}

		int ktoraUwaga = 1;
		string linia;

		for (;;)
		{
			cout << "Uwaga " << ktoraUwaga << "/" << iloscUwag << endl << endl;

			ifstream odczyt("uwagi.txt");

			for (int i = 1; i < ktoraUwaga; i++)
			{
				for (int o = 0; o < 3; o++)
				{
					getline(odczyt, linia);
				}
			}

			getline(odczyt, linia);
			cout << "Tresc:" << endl << linia << endl << endl;
			getline(odczyt, linia);
			cout << "ID zglaszajacego: " << linia << endl << endl;
			if (iloscUwag != 1)
			{
				cout << "                                      ";
				if (ktoraUwaga == 1)
				{
					cout << " >";
				}
				else if (ktoraUwaga == iloscUwag)
				{
					cout << "< ";
				}
				else
				{
					cout << "<>";
				}
			}

			odczyt.close();

			char input;

			for (;;)
			{
				input = _getch();
				if (input == 'a' && ktoraUwaga != 1)
				{
					system("cls");
					ktoraUwaga--;
					break;
				}
				if (input == 'd' && ktoraUwaga != iloscUwag)
				{
					system("cls");
					ktoraUwaga++;
					break;
				}
				if (input == 27)
				{
					system("cls");
					return;
				}
				if (input == 'x')
				{
					system("cls");

					int czyChceWyjsc = 0;
					cout << "Czy chcesz usunac te uwage? Kliknij t lub n." << endl;

					char temp;

					for (;;)
					{
						temp = _getch();
						if (temp == 't' || temp == 'n')
						{
							if (temp == 'n')
							{
								czyChceWyjsc = 1;
							}
							break;
						}
					}

					if (czyChceWyjsc == 1)
					{
						system("cls");
						break;
					}

					string liniaTrash;
					string doWpisania;

					ifstream odczyt("uwagi.txt");

					for (int i = 1; i < ktoraUwaga; i++)
					{
						for (int o = 0; o < 3; o++)
						{
							getline(odczyt, liniaTrash);
							doWpisania = doWpisania + liniaTrash;
							doWpisania = doWpisania + "\n";
						}
					}

					for (int i = 0; i < 3; i++)
					{
						getline(odczyt, liniaTrash);
					}

					while (getline(odczyt, liniaTrash))
					{
						doWpisania = doWpisania + liniaTrash;
						doWpisania = doWpisania + "\n";
					}

					odczyt.close();

					ofstream zapis("uwagi.txt");
					zapis << doWpisania;
					zapis.close();

					iloscUwag--;

					ofstream zapisIle("ileUwag.txt");
					zapisIle << iloscUwag;
					zapisIle.close();

					if (iloscUwag == 0)
					{
						system("cls");
						cout << "Nie ma zadnych zgloszonych uwag. Nacisnij dowolny klawisz aby powrocic." << endl;
						system("pause");
						system("cls");
						return;
					}

					if (ktoraUwaga == (iloscUwag + 1))
					{
						ktoraUwaga--;
					}

					system("cls");
					break;
				}
			}
		}
	}
};

int main()
{
	Student* student1 = new Student;
	Wykladowca* wykladowca1 = new Wykladowca;
	Logowanie zaloguj;
	Test test1;
	Uwaga uwaga1;
	char input;
	int wyborOsoby = 1;
	char coWybrano;
	int loginCzyRejestracja = 1;
	int czyZalogowano = 0;
	int x = 0;
	char inputPoczatkowy;
	for (;;)
	{
		for (;;)
		{
			loginCzyRejestracja = 1;
			for (;;)
			{
				system("cls");
				if (loginCzyRejestracja == 1)
				{
					cout << " > ";
				}
				cout << "LOGIN" << endl;
				if (loginCzyRejestracja == 2)
				{
					cout << " > ";
				}
				cout << "REJESTRACJA" << endl;

				inputPoczatkowy = _getch();
				if (inputPoczatkowy == 's')
				{
					if (loginCzyRejestracja == 1)
					{
						loginCzyRejestracja = 2;
					}
					else
					{
						loginCzyRejestracja = 1;
					}
				}
				if (inputPoczatkowy == 'w')
				{
					if (loginCzyRejestracja == 1)
					{
						loginCzyRejestracja = 2;
					}
					else
					{
						loginCzyRejestracja = 1;
					}
				}
				if (inputPoczatkowy == 13)
				{
					break;
				}
			}

			if (loginCzyRejestracja == 1)
			{
				for (;;)
				{
					system("cls");
					cout << "Chcesz sie zalogowac jako Student czy Wykladowca?" << endl;
					cout << "Nacisnij na klawiaturze: s - student, w - wykladowca" << endl;
					coWybrano = _getch();
					system("cls");
					if (coWybrano == 's') {
						x = zaloguj.zaloguj(student1);
						if (x == 1)
						{
							czyZalogowano = 1;
							break;
						}
					}
					if (coWybrano == 'w') {
						x = zaloguj.zaloguj(wykladowca1);
						if (x == 1)
						{
							czyZalogowano = 1;
							break;
						}
					}
					if (coWybrano == 27)
					{
						break;
					}
				}
			}
			else if (loginCzyRejestracja == 2)
			{
				zaloguj.zarejestruj(student1);
			}
			if (czyZalogowano == 1)
			{
				czyZalogowano = 0;
				break;
			}
		}


		system("cls");


		bool czyWylogowac = 0;

		if (student1->czyZalogowany() == 1) //ZALOGOWANO NA STUDENTA
		{
			for (;;)
			{
				cout << "Zalogowano jako: " << student1->giveImie() << " " << student1->giveNazwisko() << endl << "Nr albumu: " << student1->giveID() << endl << endl;

				if (wyborOsoby == 1)
				{
					cout << " > ";
				}
				cout << "ROZWIAZ TEST";
				cout << endl << endl;

				if (wyborOsoby == 2)
				{
					cout << " > ";
				}
				cout << "SPRAWDZ WYNIKI";
				cout << endl << endl;

				if (wyborOsoby == 3)
				{
					cout << " > ";
				}
				cout << "DODAJ UWAGE";
				cout << endl << endl;

				if (wyborOsoby == 4)
				{
					cout << " > ";
				}
				cout << "WYLOGUJ";
				cout << endl << endl;

				for (;;)
				{
					input = _getch();

					if (input == 'w')
					{
						system("cls");
						if (wyborOsoby == 2 || wyborOsoby == 3 || wyborOsoby == 4)
						{
							wyborOsoby--;
						}
						else
						{
							wyborOsoby = 4;
						}
						break;
					}
					if (input == 's')
					{
						system("cls");
						if (wyborOsoby == 1 || wyborOsoby == 2 || wyborOsoby == 3)
						{
							wyborOsoby++;
						}
						else
						{
							wyborOsoby = 1;
						}
						break;
					}
					if (input == 13)
					{
						switch (wyborOsoby)
						{
						case 1:
							system("cls");
							cout << "ROZWIAZ TEST" << endl;
							test1.Rozwiaz_Test(student1->giveID());
							system("pause");
							system("cls");
							break;

						case 2:
							system("cls");
							cout << "SPRAWDZ WYNIKI" << endl;
							test1.zobaczWyniki(student1->giveID());
							system("pause");
							system("cls");
							break;

						case 3:
							uwaga1.dodajUwage(student1->giveID());
							break;

						case 4:
							system("cls");
							czyWylogowac = 1;
							student1->wylogowanie();
							break;
						}
						break;
					}
				}

				if (czyWylogowac == 1)
				{
					x = 0;
					wyborOsoby = 1;
					czyWylogowac = 0;
					break;
				}
			}
		}
		else if (wykladowca1->czyZalogowany() == 1) //Zalogowano na wyk³adowcê
		{
			for (;;)
			{
				cout << "Zalogowano jako: " << wykladowca1->giveTytul() << " " << wykladowca1->giveImie() << " " << wykladowca1->giveNazwisko() << endl << endl;

				if (wyborOsoby == 1)
				{
					cout << " > ";
				}
				cout << "DODAJ TEST";
				cout << endl << endl;

				if (wyborOsoby == 2)
				{
					cout << " > ";
				}
				cout << "SPRAWDZ WYNIKI STUDENTOW";
				cout << endl << endl;

				if (wyborOsoby == 3)
				{
					cout << " > ";
				}
				cout << "ZOBACZ UWAGI";
				cout << endl << endl;

				if (wyborOsoby == 4)
				{
					cout << " > ";
				}
				cout << "WYLOGUJ";
				cout << endl << endl;

				for (;;)
				{
					input = _getch();

					if (input == 'w')
					{
						system("cls");
						if (wyborOsoby == 2 || wyborOsoby == 3 || wyborOsoby == 4)
						{
							wyborOsoby--;
						}
						else
						{
							wyborOsoby = 4;
						}
						break;
					}
					if (input == 's')
					{
						system("cls");
						if (wyborOsoby == 1 || wyborOsoby == 2 || wyborOsoby == 3)
						{
							wyborOsoby++;
						}
						else
						{
							wyborOsoby = 1;
						}
						break;
					}
					if (input == 13)
					{
						switch (wyborOsoby)
						{
						case 1:
							system("cls");
							test1.Dodaj_Test();
							//system("cls");
							break;

						case 2:
							system("cls");
							cout << "SPRAWDZ WYNIKI STUDENTOW" << endl;
							test1.zobaczWynikiStudentow();
							system("pause");
							system("cls");
							break;

						case 3:
							uwaga1.zobaczUwagi();
							break;

						case 4:
							system("cls");
							czyWylogowac = 1;
							wykladowca1->wylogowanie();
							break;
						}
						break;
					}
				}

				if (czyWylogowac == 1)
				{
					wyborOsoby = 1;
					czyWylogowac = 0;
					x = 0;
					break;
				}
			}
		}
	}
}
