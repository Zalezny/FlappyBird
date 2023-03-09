#include "includes.h"
export module Calculator;
import Calculator_Logix;


export void initCalc() {
	system("CLS");
	std::cout << "Wprowadz numer wykonywanej operacji: " << std::endl;
	std::cout << "Dostepne operacje: " << std::endl;
	std::cout << "1. dodawanie\n 2. odejmowanie\n 3. mnozenie\n 4. dzielenie\n";
	int choice;
	do {
		std::cin >> choice;
	} while (choice < 1 || choice > 4);

	system("CLS");

	int a, b;
	
	bool error = true;
	while (error) {
		std::cout << "Podaj liczby na ktorej bedziemy wykonywac operacje: ";
		std::cin >> a;
		std::cout << " ";
		std::cin >> b;

		if (choice == 4 && b == 0) {
			std::cerr << "Bledne rownanie\n";
		}
		else if (choice == 6 && a < 0) {
			std::cerr << "Bledne rownanie\n";
		}
		else error = false;
	}
	system("CLS");
	

	std::cout << "Wyniki: ";
	switch (choice) {
	case 1:
		std::cout << add(a, b);
		break;
	case 2:
		std::cout << remove(a, b);
		break;
	case 3:
		std::cout << multi(a, b);
		break;
	case 4:
		std::cout << diversion(a, b);
		break;
	default:
		std::cout << "Brak przypisanej funkcji.";
		break;
	
	}




}