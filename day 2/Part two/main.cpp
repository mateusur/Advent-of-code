#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//vector<int> obliczenia(vector<int>& lista2, int pierwsza_pozycja, int druga_pozycja, int trzecia_pozycja);
void obliczenia(vector<int> lista2, int zerowa_pozycja, int pierwsza_pozycja, int druga_pozycja, int trzecia_pozycja,int noun,int verb);

void wczytanie()
{
	const int output = 19690720;
	char zbedna;
	int pomocnicza;
	vector<int> lista;
	fstream plik;
	string sciezka = "intcode.txt";
	plik.open(sciezka, fstream::in);
	if (plik.good()) {
		while (plik.good()) {
			plik >> pomocnicza >> zbedna;
			lista.push_back(pomocnicza);
		}
	}
	else cout << "Nie udalo sie otworzyc pliku" << endl;
	plik.close();
	for (const int& k : lista) {
		cout << k << " ";
	}
	cout << endl << endl;
	for(int noun=1;noun<100;noun++){
		for(int verb=1;verb<100;verb++){
			obliczenia(lista, 0, 1, 2, 3,noun,verb);
		}
		}
	}
	
void obliczenia(vector<int> lista2, int zerowa_pozycja, int pierwsza_pozycja, int druga_pozycja, int trzecia_pozycja, int noun, int verb)
{
	lista2.at(1) = noun;
	lista2.at(2) = verb;
	const int output = 19690720;
	int poz0, poz1, poz2, poz3;
	poz0 = zerowa_pozycja;
	poz1 = pierwsza_pozycja;
	poz2 = druga_pozycja;
	poz3 = trzecia_pozycja;
	int pozycja1 = lista2.at(poz1);
	int wartosc1 = lista2.at(pozycja1);
	int	pozycja2 = lista2.at(poz2);
	int wartosc2 = lista2.at(pozycja2);
	int pozycja3 = lista2.at(poz3);
	switch (lista2.at(poz0)) {
	case 1:
		lista2.at(pozycja3) = wartosc1 + wartosc2;
		break;
	case 2:
		lista2.at(pozycja3) = wartosc1 * wartosc2;
		break;
	default:
		cout << "Cos poszlo nie tak\n";
		break;
	}
	zerowa_pozycja = poz0 + 4;
	pierwsza_pozycja = poz1 + 4;
	druga_pozycja = poz2 + 4;
	trzecia_pozycja = poz3 + 4;
	if (lista2.at(zerowa_pozycja) == 99) {
		//cout << "po " << i << "zmianach: ";
		/*for (int k = 0; k < lista2.size(); k++) {

			cout << lista2.at(k) << " ";
		}*/
		if (lista2.at(0) == output) cout << "noun: " << noun << " verb: " << verb << "\nAnd the answer is: " << 100 * noun + verb << endl;
	}
	else obliczenia(lista2, zerowa_pozycja, pierwsza_pozycja, druga_pozycja, trzecia_pozycja,noun,verb);

}

//void part_two()
//{
//	int noun = 1;
//	int verb = 1;
//	const int output = 19690720;
//	for(noun;noun<100;noun++){
//		for(verb;verb<100;verb++){
//		
//		}
//	}
//}
int main()
{
	//part_two();
	wczytanie();
	system("pause");
	return 0;
}
