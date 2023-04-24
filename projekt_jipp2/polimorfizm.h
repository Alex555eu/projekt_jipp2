#pragma once
#include <iostream>

using namespace std;

/// @brief Klasa przechowujaca obecna date
class kalendarz {

protected:
	string data;

public:
	
	/// @brief Konstruktor bezparametryczny, przypisujacy swojemu polu data, dzisiajsza date
	kalendarz() { data = __DATE__; }
	
	/// @brief Destruktor klasy
	~kalendarz() {};
	
	/// @brief Metoda zwraca wartosc data
	/// @return : typ string
	string getData() { return data; }
	
	/// @brief Metoda ustawia wartosc data
	/// @param data pobieraana wartoc do ustawienia typu string
	void setData(string data) { this->data = data; }
	
	/// @brief Zwraca zawartosc klasy na ekran
	virtual void print() {
		cout << data << endl;
	}

};

/// @brief Klasa przechowujaca obecny czas
class zegar : public kalendarz {

	string godzina;

public:
	
	/// @brief Konstruktor bezparametryczny, przypisujacy swojemu polu godzina, obecna godzine
	zegar() { godzina = __TIME__; }
	
	/// @brief Destruktor klasy
	~zegar() {};
	
	/// @brief Metoda zwraca wartosc godzina
	/// @return : typ string
	string getGodzina() { return godzina; }
	
	/// @brief Metoda ustawia wartosc godzina
	/// @param godzina pobierana warosc do ustawienia typu string
	void setGodzina(string godzina) { this->godzina = godzina; }
	
	/// @brief Zwraca zawartosc klas bazowej i dziedziczonej, na ekran
	void print() override {
		cout << data << endl << godzina << endl;
	}

};
