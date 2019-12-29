#include <iostream>
#include <string>
using namespace std;

bool adjacent(const int& examine)
{
	string number = to_string(examine);
	for (int k = 0; k < number.length() - 1; k++)
		if (number[k] == number[k + 1])
			return true;

	return false;
}

bool increase(const int& examine)
{
	string number = to_string(examine);
	stoi(number);
	//string number2 = to_string(examine2);
	for (int k = 0; k < number.length() - 1; k++){
		char first = number.at(k);
		char second = number.at(k + 1);
		int int_first = first - '0';
		int int_second = second - '0';
		if (int_first > int_second) return false;
	}

	return true;
}

bool part_two(const int& examine)
{
	string number = to_string(examine);
	int repeated = 0;
	for (int k = 0; k < number.length() - 1; k++){
		if (number[k] == number[k + 1]) repeated++;
		else{
			if (repeated == 2 || repeated == 4) return false;
			repeated = 0;
		}
	}
	if (repeated == 2 || repeated ==4) return false;
	//return false;
	return true;
}

int main()
{
	const int lowest = 240920;
	const int highest = 789857;
	int counter = 0;
	/*for (int k = lowest; k <= highest; k++)
		if ( part_two(k) && increase(k)) counter++;
	cout << counter << endl;
	*/
	if (part_two(011111)) cout << "OK" << endl;
	else cout << "NOT OK" << endl;

	system("pause");
	return 0;
}
