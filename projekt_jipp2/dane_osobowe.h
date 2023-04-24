#pragma once
#include <iostream>
#include <string>

using namespace std;

/// @brief Klasa przechowujaca dane osobowe czytelnika (imie, nazwisko, nr.id)
class dane_osobowe {
protected:
	string name;
	string surname;
	long id;

public:
	/// @brief Konstruktor bezparametrowy
	dane_osobowe();
	
	/// @brief Konstruktor parametrowy klasy dane_osobowe
	/// @param name : imie czytelnika
	/// @param surname : nazwisko czytelnika
	/// @param id : nr identyfikacyjny czytelnika
	dane_osobowe(string name, string surname, long id);
	
	/// @brief Destruktor klasy
	~dane_osobowe() {};
	
	/// @brief Metoda zwracajaca imie czytelnika 
	/// @return : typ string
	string getName() { return name; }
	
	/// @brief Metoda zwracajaca nazwisko czytelnika 
	/// @return : typ string
	string getSurname() { return surname; }
	
	/// @brief Metoda zwracajaca nr. id czytelnika 
	/// @return : typ long 
	long getID() { return id; }
	
	/// @brief Metoda ustawiajaca imie czytelnika
	/// @param name : imie do ustawiania
	void setName(string name) { this->name = name; }
	
	/// @brief Metoda ustawiajaca nazwisko czytelnika
	/// @param surname : nazwisko do ustawienia
	void setSurname(string surname) { this->surname = surname; }
	
	/// @brief Metoda ustawiajaca nr. id czytelnika
	/// @param id nr. id czytelnika
	void setID(long id) { this->id = id; }
	
	/// @brief Operator obslugujacy operacje ostream, dla obiektu klasy
	/// @param lhs ostream operand
	/// @param rhs obiekt klasy
	/// @return wartosc przekazana
	friend ostream& operator<<(ostream& lhs, const dane_osobowe& rhs);

};