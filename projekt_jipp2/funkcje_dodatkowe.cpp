
#include "funkcje_dodatkowe.h"



vector<string> availability() {

	int choice;
	string input;

	while (1) {

		cout << "Szukaj:" << endl;
		cout << "1 - Autora" << endl;
		cout << "2 - Tytulu" << endl;

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
		break;
	}

	string author;
	string title;
	string currline;
	string word;
	int books_amount = 0;
	vector<string> books;

	ifstream file("inwentarz.csv");

	if (!file.good()) {
		cout << endl << "B³¹d otwarcia pliku!" << endl << endl;
	}
	else {

		switch (choice) {

		case 1:
			cout << "Podaj nazwisko autora:" << endl;

			cin.ignore();
			getline(cin, author); 

			author[0] = toupper(author[0]);

			getline(file, currline);

			while (!file.eof()) {


				stringstream s(currline);

				getline(s, word, ',');

				try {
					books_amount = stoi(word);
				}
				catch (const std::invalid_argument& err) {
					cout << err.what() << endl;
					continue;
				}
				catch (const std::out_of_range& err) {
					cout << err.what() << endl;
					continue;
				}

				getline(s, word, ',');
				getline(s, word, ',');

				if (word == author && books_amount > 0) books.push_back(currline);

				getline(file, currline);
			}

			if (books.size() < 1) cout << endl << "Brak ksiazek!" << endl << endl;

			else {
				cout << endl;
				cout << "INDEX\t" << "ILOSC\t" << "AUTOR\t\t" << "TYTUL" << endl;

				for (int i = 0; i < books.size(); i++) {

					cout << i << "\t" << text_filter(books[i]) << endl;

				}
				cout << endl;
			}

			file.close();
			break;

		case 2:
			cout << "Podaj tytul ksiazki:" << endl;

			cin.ignore();
			getline(cin, title); 

			getline(file, currline);

			while (!file.eof()) {

				stringstream s(currline);

				getline(s, word, ',');

				try {
					books_amount = stoi(word);
				}
				catch (const std::invalid_argument& err) {
					cout << err.what() << endl;
					continue;
				}
				catch (const std::out_of_range& err) {
					cout << err.what() << endl;
					continue;
				}

				getline(s, word, ',');
				getline(s, word, ',');
				getline(s, word, ',');


				if ((word.find(title) != string::npos) && books_amount > 0) books.push_back(currline);

				getline(file, currline);
			}
			if (books.size() < 1) cout << endl << "Brak ksiazek!" << endl << endl;

			else {
				cout << endl;
				cout << "INDEX\t" << "ILOSC\t" << "AUTOR\t\t" << "TYTUL" << endl;
				for (int i = 0; i < books.size(); i++) {
					cout << i << "\t" << text_filter(books[i]) << endl;
				}
				cout << endl;
			}

			file.close();
			break;

		default:
			cout << endl << "Niepoprawny argument!" << endl << endl;
			break;
		}

	}
	return books;
}

string text_filter(string line) {
	string word = "";
	string tmp = "";

	stringstream s(line);

	while (getline(s, word, ',')) {
		tmp += word + "\t";

	}
	return tmp;
}

void decrement_books_amount(string line) {
	vector<string> tmp_vec;
	string tmp_line;
	string tmp_word;
	int books_amount; 

	ifstream file("inwentarz.csv");

	if (!file.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {

		getline(file, tmp_line);

		while (!file.eof()) {
			if (tmp_line != line) tmp_vec.push_back(tmp_line);

			getline(file, tmp_line);
		}

		stringstream s(line);

		getline(s, tmp_word, ',');

		line.erase(0, tmp_word.length());

		try {
			books_amount = stoi(tmp_word);
		}
		catch (const std::invalid_argument& err) {
			cout << err.what() << endl;
			return;
		}
		catch (const std::out_of_range& err) {
			cout << err.what() << endl;
			return;
		}

		books_amount--;

		tmp_word = to_string(books_amount); 

		line.insert(0, tmp_word);

		tmp_vec.push_back(line);

		file.close();
	}

	ofstream file2("inwentarz.csv");

	if (!file2.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {
		for (int i = 0; i < tmp_vec.size(); i++) {
			file2 << tmp_vec.at(i) << endl;
		}
	}

	file2.close();

}

void save_to_lent_list(karta* obj) {

	string tmp;

	ofstream file("wypozyczone.csv", ios::app);

	if (!file.good())
		cout << endl << "Blad otwarcie pliku!" << endl << endl;
	else {
		tmp = to_string(obj->getID()) + "," + obj->getDate() + "," + obj->getBook(); 
		file << tmp << endl;
	}
	file.close();
}

void add_new_user(karta* obj) {
	string tmp;

	ofstream file("uzytkownicy.csv", ios::app);

	if (!file.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;
	else {
		tmp = to_string(obj->getID()) + "," + obj->getName() + "," + obj->getSurname(); 

		file << tmp << endl;

		file.close();
	}
}

bool find_user_id(karta* obj) {

	string tmp_line;
	string tmp_word;
	string tmp_id;
	long id;


	cout << "Podaj szukany numer ID: " << endl; 
	
	cin.ignore();
	getline(cin, tmp_id);

	ifstream file("uzytkownicy.csv");

	if (!file.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {

		getline(file, tmp_line);

		while (!file.eof()) {

			stringstream s(tmp_line);

			getline(s, tmp_word, ',');

			if (tmp_word == tmp_id) {
				
				try {
					id = stol(tmp_id);
				}
				catch (const std::invalid_argument& err) {
					cout << err.what() << endl;
					return false;
				}
				catch (const std::out_of_range& err) {
					cout << err.what() << endl;
					return false;
				}

				obj->setID(id);

				getline(s, tmp_word, ',');
				obj->setName(tmp_word);

				getline(s, tmp_word, ',');
				obj->setSurname(tmp_word);

				cout << endl << "Odnaleziono: " << endl;

				file.close();

				return true;
			}

			getline(file, tmp_line);
		}
		cout << endl << "ID nie odnaleziono" << endl << endl;

		file.close();

	}
	return false;
}

bool find_username(karta* obj) {

	vector<string> tmp_vec;
	string tmp_line;
	string tmp_word;
	int i = 0;

	string input;
	int choice;

	string tmp_surname;

	cout << endl << "Podaj szukane nazwisko:" << endl; 
	
	cin.ignore();
	getline(cin, tmp_surname);

	tmp_surname[0] = toupper(tmp_surname[0]);

	ifstream file("uzytkownicy.csv");

	if (!file.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {

		cout << endl << "INDEX\t" << "ID\t" << "IMIE/NAZWISKO" << endl;

		getline(file, tmp_line);

		while (!file.eof()) {

			stringstream s(tmp_line);

			getline(s, tmp_word, ',');
			getline(s, tmp_word, ',');
			getline(s, tmp_word, ',');

			if (tmp_word == tmp_surname) {

				cout << i << '\t' << text_filter(tmp_line) << endl;
				tmp_vec.push_back(tmp_line);
				i++;
			}

			getline(file, tmp_line);

		}
		if (i > 0) {	
			
			cout << endl << "Wybierz:" << endl;

			cin >> input;

			try {
				choice = stoi(input);
				
				if (choice < 0 || choice > (i-1)) throw std::out_of_range("argument niezgodny z indexem na liscie");

			}
			catch (const std::invalid_argument& err) {
				cout << err.what() << endl;
				return false;
			}
			catch (const std::out_of_range& err) {
				cout << err.what() << endl;
				return false;
			}

			stringstream s(tmp_vec.at(choice));

			getline(s, tmp_word, ',');
			obj->setID(stol(tmp_word)); // !!! stol 

			getline(s, tmp_word, ',');
			obj->setName(tmp_word);

			getline(s, tmp_word, ',');
			obj->setSurname(tmp_word);

			file.close();

			return true;

		}
		else cout << endl << "Nie odnaleziono" << endl << endl;
		file.close();

	}
	return false;
}

void load_users_record(karta* obj) {

	string tmp_line;
	string tmp_line2;
	string tmp_word;
	long tmp_id;
	bool flag = true;

	ifstream file("wypozyczone.csv");

	if (!file.good()) {
		cout << endl << "Blad otwarica pliku" << endl << endl;

	}
	else {
		getline(file, tmp_line);

		while (!file.eof()) {
			stringstream s(tmp_line);

			getline(s, tmp_word, ',');

			try {
				tmp_id = stol(tmp_word);
			}
			catch (const std::invalid_argument& err) {
				cout << err.what() << endl;
				cout << endl << "invalid ID" << endl;
				return;
			}
			catch (const std::out_of_range& err) {
				cout << err.what() << endl;
				cout << endl << "invalid ID" << endl;
				return;
			}

			if (tmp_id == (obj->getID())) {

				getline(s, tmp_word, ',');
				obj->setDate(tmp_word);

				getline(s, tmp_word, ',');
				tmp_line2 = tmp_word;

				while (getline(s, tmp_word, ',')) tmp_line2 += ',' + tmp_word;

				obj->setBook(tmp_line2);

				flag = false;

			}

			getline(file, tmp_line);

		}
		file.close();

		if (flag) cout << endl << "Brak wypozyczonych ksiazek" << endl << endl;

		return;

	}
	file.close();

}

void remove_from_lent_list(karta* obj, int index) {

	string tmp_line;
	string tmp_line2;
	vector<string> tmp_vec;


	ifstream file("wypozyczone.csv");

	if (!file.good())
		cout << endl << "Blad otwarcia pliku" << endl << endl;

	else {

		tmp_line2 = to_string(obj->getID()) + "," + obj->getDate(index) + "," + obj->getBook(index); 

		getline(file, tmp_line);

		while (!file.eof()) {

			if (tmp_line != tmp_line2) tmp_vec.push_back(tmp_line);

			getline(file, tmp_line);
		}

		file.close();
	}

	ofstream file2("wypozyczone.csv");

	if (!file2.good())
		cout << endl << "Blad otwarcia pliku" << endl << endl;

	else {

		for (int i = 0; i < tmp_vec.size(); i++) {
			file2 << tmp_vec.at(i) << endl;
		}

		file2.close();
	}
}

void increment_books_amount(karta* obj, int index) {

	vector<string> tmp_vec;

	string tmp_line;
	string tmp_word;

	int val;

	ifstream file("inwentarz.csv");

	if (!file.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {

		getline(file, tmp_line);

		while (!file.eof()) {

			if (tmp_line.find(obj->getBook(index)) != string::npos) {

				stringstream s(tmp_line);

				getline(s, tmp_word, ',');

				tmp_line.erase(0, tmp_word.length());

				try {
					val = stoi(tmp_word);
				}
				catch (const std::invalid_argument& err) {
					cout << err.what() << endl;
					return;
				}
				catch (const std::out_of_range& err) {
					cout << err.what() << endl;
					return;
				}

				val++;

				tmp_word = to_string(val);

				tmp_line.insert(0, tmp_word);


			}

			tmp_vec.push_back(tmp_line);

			getline(file, tmp_line);
		}

		file.close();
	}

	ofstream file2("inwentarz.csv");

	if (!file2.good())
		cout << endl << "Blad otwarcia pliku!" << endl << endl;

	else {
		for (int i = 0; i < tmp_vec.size(); i++) {
			file2 << tmp_vec.at(i) << endl;
		}
	}

	file2.close();

}

long id_generator() {

	string tmp_line;
	string tmp_id;
	string tmp_id2="";
	long id=0;
	bool flag = true;

	srand(time(NULL));


	ifstream file("uzytkownicy.csv");

	if (!file.good()) {
		cout << endl << "Blad otwarcia pliku" << endl;
	}

	else {

		while (flag) {
			
			flag = false;

			for (int i = 0; i < 6; i++) {
				tmp_id2 += to_string(rand() % 10);
			}

			getline(file, tmp_line);

			while (!file.eof()) {

				stringstream s(tmp_line);

				getline(s, tmp_id, ',');

				if (tmp_id == tmp_id2) {
					flag = true;
					break;
				}

				getline(file, tmp_line);
				
			}
		}

		file.close();

		try {
			id = stol(tmp_id2);
		}
		catch (const std::invalid_argument& err) {
			cout << err.what() << endl;
			return 0;
		}
		catch (const std::out_of_range& err) {
			cout << err.what() << endl;
			return 0;
		}
	}

	return id;

}