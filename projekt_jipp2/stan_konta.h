#pragma once
#include <iostream>
#include <vector>


using namespace std;

/// @brief Klasa przechowujaca dane o oplatach czytelnika
class stan_konta {

protected:

	vector<double> charge;

	/// @brief Konstruktor bezparametrowy
	stan_konta() {};
	
	/// @brief Destruktor klasy
	~stan_konta() {};

public:
	

	
	/// @brief Zwraca ostatnia wartosc wektora charge
	/// @return : typ double
	double getCharge() { return charge.back(); }
	
	/// @brief Zwraca wartosc wektora charge, z okreslonego indeksem miejsca
	/// @param index : okresla pozycje wektora charge, z ktorego pobrana zostanie wartosc
	/// @return : typ double
	double getCharge(int index) { return charge.at(index); }
	
	/// @brief Dodaje nowa wartosc do wektora charge na jego koniec
	/// @param val : wartosc do dodania
	void setCharge(double val) { charge.push_back(val); }
	
	/// @brief Dodaje nowa wartosc w wektorze charge, okreslonego indeksem
	/// @param val : wartosc do dodania
	/// @param index : indeks okreslajacy polozenie
	void setCharge(double val, int index) { charge.at(index) = val; }
	
	/// @brief Operator obslugujacy operacje ostream, dla obiektu klasy
	/// @param lhs ostream operand
	/// @param rhs obiekt klasy
	/// @return wartosc przekazana
	friend ostream& operator<<(ostream& lhs, const stan_konta& rhs);

};