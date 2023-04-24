#include "karta.h"
#include "interfejs.h"
#include "funkcje_dodatkowe.h"
#include "polimorfizm.h"

using namespace std;


template <typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

void menu_1() {

	kalendarz* k1 = new zegar();

	cout << "------------" << endl;

	k1->print();

	cout << "------------" << endl;

	delete k1;


	while (1) {
		cout << "Wybierz opcje:" << endl;
		cout << "1 - czytelnik" << endl;
		cout << "2 - dodaj nowego czytelnika" << endl;
		cout << "3 - sprawdz dostepnosc ksiazki" << endl;
		cout << "4 - wyjdz" << endl;

		int choice;
		string input;

		cin >> input;

		try {
			choice = stoi(input);
		}
			catch (const std::invalid_argument& err) {
				cout << err.what() << endl;
				cout << endl << "Podaj poprawny argument!" << endl << endl;
				continue;
			}
			catch (const std::out_of_range& err) {
				cout << err.what() << endl;
				cout << endl << "Podaj poprawny argument!" << endl << endl;
				continue;
			}
	

		switch (choice) {
		case 1: interface_1();
				break;
		
		case 2: interface_2();
				break;
		
		case 3: availability();
				break;

		case 4: break;
		
		default:
			cout << endl << "Niepoprawny argument!" << endl << endl;
			break;
		}
		
		if (choice == 4) break;
	}
}