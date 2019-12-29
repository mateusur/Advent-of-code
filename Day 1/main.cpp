#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fuel()
{
	int pomocniczy;
	long long mass = 0;
	fstream plik, plik2;
	string sciezka = "mass.txt";
	plik.open(sciezka, fstream::in);
	{
		while (plik.good()){
			plik >> pomocniczy;
			pomocniczy = (pomocniczy / 3) - 2;
			mass += pomocniczy;
		}
	}
	plik.close();

	return mass;
}

int main()
{
	int masa = fuel();
	cout << masa << endl;
	system("pause");
	return 0;
}
