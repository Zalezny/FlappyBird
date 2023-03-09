#include <iostream>
import Is_Prime;
import Rectangle;
using namespace std;

int main() {
	int n;
	cout << "Podaj liczbe: ";
	cin >> n;
	cout << endl;
	if (is_prime(n)) 
		cout << "To nie jest liczba pierwsza!" << endl;
	else
		cout << "To jest liczba pierwsza!";

	Rectangle obj;
	cout << "Obwod wynosi dla prostokata 5x10: " << obj.circuit(5, 10) << endl;
	cout << "Pole wynosi dla prostokata 5x10: " << obj.field(5, 10) << endl;

}