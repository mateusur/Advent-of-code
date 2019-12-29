#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int masa_pomocnicza=0;

int masa(int liczba)
{
	masa_pomocnicza += liczba;
	if (liczba < 6) return  0;
	return masa((liczba / 3) - 2);
}

void fuel()
{
	int i = 0;
	int pomocniczy;
	long long mass = 0;
	fstream plik, plik2;
	string sciezka = "mass.txt";
	plik.open(sciezka, fstream::in);
	{
		while (plik.good()) {
			plik >> pomocniczy;
			pomocniczy = (pomocniczy / 3) - 2;
			masa(pomocniczy);
		}
	}
	plik.close();
}

int main()
{
	fuel();
	cout << "masa: " << masa_pomocnicza << endl;
	system("pause");
	return 0;
}
