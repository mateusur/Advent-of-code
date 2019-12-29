#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct point;
int odleglosc(const vector<point>& manhattan);
struct point
{
	int x;
	int y;

};
vector <point> wczytanie(string nazwa_pliku)
{
	char kierunek,przecinek;
	int nowy_x=0;
	int nowy_y=0;
	int poprzedni_x = 0;
	int poprzedni_y = 0;
	vector<point> trasa;
	point punkt;
	
	fstream plik;
	string sciezka = nazwa_pliku+".txt";
	plik.open(sciezka, fstream::in);
	if (plik.good()) {
		while (plik.good()) {
			plik >> kierunek;
			/*poprzedni_x = nowy_x;
			poprzedni_y = nowy_y;*/
			switch(kierunek){
			case 'R':
				plik >> nowy_x;
				for(int i=0;i<nowy_x;i++){
					poprzedni_x++;
					punkt.x = poprzedni_x;
					punkt.y = poprzedni_y;
					trasa.push_back(punkt);
					//punkt.wyswietl();
				}
				break;
			case 'L':
				plik >> nowy_x;
				for (int i = 0; i < nowy_x; i++) {
					poprzedni_x--;
					punkt.x = poprzedni_x;
					punkt.y = poprzedni_y;
					trasa.push_back(punkt);
				}
				break;
			case 'U':
				plik >> nowy_y;
				for (int i = 0; i < nowy_y; i++) {
					poprzedni_y++;
					punkt.x = poprzedni_x;
					punkt.y = poprzedni_y;
					trasa.push_back(punkt);
				}
				break;
			case 'D':
				plik >> nowy_y;
				for (int i = 0; i < nowy_y; i++) {
					poprzedni_y--;
					punkt.x = poprzedni_x;
					punkt.y = poprzedni_y;
					trasa.push_back(punkt);
				}
				break;
			}
			plik >> przecinek;
			
		}
	}
	
	for(const auto& punkcik :trasa){
		cout << punkcik.x << "," << punkcik.y << endl;
	}
	//cout << odleglosc(trasa);
	return trasa;
}
int odleglosc(const vector<point>& manhattan)
{
	int odl= INT_MAX;
	for (const auto& punkcik : manhattan) {
		if((abs(punkcik.x) + abs(punkcik.y))<odl) odl=abs(punkcik.x)+abs(punkcik.y);
	}
	return odl;
}
vector<point> przeciecie(const vector<point>& manhattan1, const vector<point>& manhattan2)
{
	point punkt1, punkt2;
	vector<point> przeciecia;
	//cout << "Rozmiar 1: " << manhattan1.size() << endl;
	//cout << "Rozmiar 2: " << manhattan2.size() << endl;

	for(const auto& liczba :manhattan1){
		punkt1.x = liczba.x;
		punkt1.y = liczba.y;
		for(const auto& liczba2 : manhattan2){
			punkt2.x = liczba2.x;
			punkt2.y = liczba2.y;
			if (punkt1.x == punkt2.x && punkt1.y == punkt2.y){
				przeciecia.push_back(punkt1);
				//cout << punkt2.x << "," << punkt2.y << endl;
			} 
		}
	}
	return przeciecia;
}
int main()
{
	vector<point> kopia1 = wczytanie("path1");
	//vector<point> kopia2 = wczytanie("path2");
	//vector<point> przeciecia = przeciecie(kopia1, kopia2);
	
	//cout << odleglosc(przeciecia) << endl;


	
	/*cout << "Teraz kopia\n";
	for (const auto& punkcik : kopia) {
		cout << punkcik.x << "," << punkcik.y << endl;
	}*/
	system("pause");
	return 0;
}