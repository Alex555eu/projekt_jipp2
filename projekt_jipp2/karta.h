#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>


#include "dane_osobowe.h"
#include "stan_konta.h"


/// @brief 
class karta: public dane_osobowe, public stan_konta {

	vector<string> book;
	vector<string> date;


public:

	/// @brief Konstruktor bezparametryczny
	karta(){};

	/// @brief Konstruktor parametryczny klasy
	/// @param name: jest to pole odziedziczone z klasy dane_osobowe, przechowuje imie czytelnika
	/// @param surname : jest to pole odziedziczone z klasy dane_osobowe, przechowuje nazwisko czytelnika
	/// @param id : jest to pole odziedziczone z klasy dane_osobowe, przechowuje numer identyfikacyjny (ID) czytelnika
	karta(string name, string surname, int id) : dane_osobowe(name, surname, id) {};

	/// @brief Destruktor domyslny
	~karta() {};

	
	/// @brief Funkcja ustawiajaca wartosc w rzadanym przez nas miejscu w wektorze book
	/// @param index : index, wskazujacy na pozycje w wektorze, do ktorej wlozymy nasza wartosc
	/// @param val : wartosc do ustawienia
	void setBook(int index, string val) { book.at(index) = val; }

	/// @brief Dodaje wartosc na koniec wektora 
	void setBook(string val) { book.push_back(val); }

	/// @brief Funkcja zwracajaca wartosc kontenera book
	/// @param index : jest to index, pod ktorym zlokalizowana jest nasza szukana wartosc
	/// @return : element wektora book
	string getBook(int index) { return book.at(index); }
	
	/// @brief Funkcja zwracajaca wartosc kontenera book z jego samego konca
	string getBook() { return book.back(); }
	
	/// @brief Funkcja ustawiajaca wartosc w wektorze date
	/// @param index : index, wskazujacy na pozycje w wektorze, z ktorej pobierzemy nasza wartosc
	/// @param val : wartosc do ustawienia
	void setDate(int index, string val) { date.at(index) = val; }

	/// @brief Dodaje wartosc na koniec wektora
	/// @param val : wartosc do dodania
	void setDate(string val) { date.push_back(val); }

	string getDate(int index) { return date.at(index); }
	string getDate() { return date.back(); }

	/// @brief Przekazuje do obiektu wartosci: do wektora ->date dzisiejsza date, a do wektora ->books linie przekazana jako argument funkcji, z pominieciem pierwszego slowa w linii
	/// @param val : linia, do przekazania do wektora ->books
	void push(string val);

	/// @brief Usuwa wartosci na wspolnym indeksie wektorw ->books, ->date, ->charge, zlokalizowanym na podstawie polozenia parametru wywolania
	/// @param _date : parametr wywolania, jest nim data kalendarzowa
	void remove(string _date);

	/// @brief Usuwa wartosci na wspolnym indeksie wektorw ->books, ->date, ->charge
	/// @param index : wspolny indeks, ktory wskazuje na elementy do usuniecia 
	void remove(int index);
	
	/// @brief Wyswietla na ekranie zawartosc wektora ->books
	/// @return : Zwraca ilosc elementow w liscie
	int getBookList();

	/// @brief Obicza kwote do zaplaty, podczas przetrzymania ksiazki ( >30 dni)
	/// @param obj : obiekt, z ktorego pobrane zostana daty z wektora ->date, i w ktorym przechowane zostana wyniki w wektorze ->charge
	friend void balans_calculator(karta* obj);


	friend ostream& operator<<(ostream& lhs, const karta& rhs);

};

/// @brief Konwertuje skrot nazwy miesiaca, (n.p Jan, Feb...), na liczbe mu odpowiadajaca
/// @param month : nazwa miesiaca do przekonwertowania
/// @return wartosc integer odpowiadajaca nazwie miesiaca (1-12)
int month_str_to_num(string month);