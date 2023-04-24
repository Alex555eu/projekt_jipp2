#include "karta.h"
#include "funkcje_dodatkowe.h"


using namespace std;

void interface_main(karta* obj) {
	while (1) {

		cout << "Wybierz:" << endl;
		cout << "1 - Wypozycz ksiazke" << endl;
		cout << "2 - Oddaj ksiazke" << endl;
		cout << "3 - Anuluj" << endl;

		vector<string> books;
		books.clear();

		int choice;
		int option;
		int size;

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
			cout << endl << "Podaj poprawny argument!"<< endl << endl;
			continue;
		}

		switch (choice) {
		case 1:
			books = availability();

			if (books.size() == 0) break;

			cout << endl << "Wybierz ksiazke: " << endl;

			cin >> input;

			try {
				option = stoi(input);

				if (option < 0 || option > books.size()) throw std::out_of_range("argument niezgodny z indexem na liscie");
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

			obj->push(books.at(option));

			decrement_books_amount(books.at(option)); 

			save_to_lent_list(obj);

			break;

		case 2:
			size = obj->getBookList();

			if (size < 1) {
				cout << endl << "Brak wyporzyczonych ksiazek" << endl << endl;
				break;
			}

			cout << endl << "Wybierz ksiazke: " << endl; 
			
			cin >> input;

			try {
				option = stoi(input);

				if (option < 0 || option >= size) throw std::out_of_range("argument niezgodny z indexem na liscie");
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

			remove_from_lent_list(obj, option);

			increment_books_amount(obj, option);

			obj->remove(option);

			break;
		

		case 3: break;

		default:
			cout << endl << "Niepoprawny argument!" << endl << endl;

		}
		if (choice == 3) break;
	}

}

void interface_1() {

	karta* czytelnik = new karta;

	while (1) {
		cout << "Wyszukaj czytelnika: " << endl;
		cout << "1 - po numerze ID" << endl;
		cout << "2 - po nazwisku" << endl;
		cout << "3 - anuluj" << endl;

		string input;
		int choice;
		
		cin >> input;

		try {
			choice = stoi(input);

			if (choice < 0 || choice > 3) throw std::out_of_range("argument niezgodny z indexem na liscie");
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

		if (choice == 1) {
			if(find_user_id(czytelnik)) break;
		}

		else if (choice == 2) {
			if (find_username(czytelnik)) break;
		}

		else if (choice == 3) return;

	}

	load_users_record(czytelnik);

	balans_calculator(czytelnik);

	cout << *czytelnik << endl;

	interface_main(czytelnik);

	delete czytelnik;

}

void interface_2() {

	string name;
	string surname;
	long id;

	while (1) {

		cout << "Podaj Imie i Nazwisko: " << endl;

		cin >> name;
		cin >> surname;
		cin.clear();

		if (name.size() > 20 || surname.size() > 20) {
			cout << "Imie lub Nazwisko za dlugie, podaj krotsze" << endl;
			continue;
		}
		break;
	}
	
	if ((id = id_generator()) == 0) return;

	name[0] = toupper(name[0]);
	surname[0] = toupper(surname[0]);

	karta* czytelnik = new karta(name, surname, id);

	string input;
	int choice;

	while (1) {

		cout << "Podane Imie i Nazwisko to: " << name << " " << surname << endl << "Czy chcesz kontynuowac ?"
			<< endl
			<< "1 - tak" << endl
			<< "2 - nie" << endl;

		cin >> input;

		try {
			choice = stoi(input);

			if (choice < 0 || choice > 2) throw std::out_of_range("argument niezgodny z indexem na liscie");
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

		break;
	}

	if (choice == 1) {

		add_new_user(czytelnik);

		cout << *czytelnik << endl;

		interface_main(czytelnik);

	}
	delete czytelnik;

}
