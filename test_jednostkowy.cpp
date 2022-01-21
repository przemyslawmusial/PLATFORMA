#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testjednostkowy
{
	TEST_CLASS(Student)
	{
	public:
		string imie;
		string nazwisko;
		string nrAlbumu;
		string login;
		string haslo;
		TEST_METHOD(TestMethod1)
		{
			this->imie = imie;
			this->nazwisko = nazwisko;
			this->nrAlbumu = nrAlbumu;

			this->haslo = haslo;
			this->login = login;
		}
	};
}
