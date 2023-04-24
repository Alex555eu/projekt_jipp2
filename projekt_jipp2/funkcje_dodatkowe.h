#pragma once

#include <time.h>
#include "karta.h"

/// @brief sprawdza dostepne ksiazki z polki bibliotecznej ( te ktorych ilosc jest wiekszza od 0)
/// @return wektor, zawierajacy ksiazki dostepne do wyporzyczeia
vector<string> availability();

/// @brief Zamienia przecinki miedzy slowami na tabulatory
/// @param line : ciag slow do modyfikacji
/// @return zmodyfikowany ciag slow
string text_filter(string line);

/// @brief Dekrementuje ilosc konkretnej ksiazki na polce bibliotecznej o 1
/// @param line : linia zawierajaca ksiazke w formacie: [ilosc],[imie_autora],[nazwisko_autora],[tytul_ksiazki]
void decrement_books_amount(string line);

/// @brief Inkrementuje ilosc konkretnej ksiazki na polce bibliotecznej o 1
/// @param obj : obiekt, z ktorego pobrana zostanie linia zawierajaca dane o ksiazce do oddania ( ->books)
/// @param index : indeks wskazujacy na pozycje, na ktorej znajduje sie ksiazka w wektorze klasy przekazanwgo obiektu
void increment_books_amount(karta* obj, int index);

/// @brief Zapisuje dane o wyporzyczonych ksiazkach do pliku .csv, w formacie: [id],[data],[imie_autora],[nazwisko_autora],[tytul_ksiazki]
/// @param obj : obiekt, z ktorego pobrane zostana wartosci do zapisu
void save_to_lent_list(karta* obj);

/// @brief Usuwa dane o  wyporzyczonej ksiazce z danej pozycji
/// @param obj : obiekt, posiadajacy w wektorze ksiazke do usuniecia
/// @param index : indeks wskazujacy na pozycje w wektorze obiektu, posiadajacej dane o zwroconej ksiazce 
void remove_from_lent_list(karta* obj, int index);

/// @brief Funckja dodaje nowego czytelnika z jego danymi i zapisuje je do pliku w formacie: [id],[name],[surname]
/// @param obj obiekt przechowujacy dane nowego czytelnika
void add_new_user(karta* obj);

/// @brief Pobiera dane czytelnika, oraz jego wyporzyczone ksiaki z pliku
/// @param obj obiekt, w ktorym przechowywane beda pobrane dane
void load_users_record(karta* obj);

/// @brief Funkcja szuka danych czytelnika na podstawie jego id
/// @param obj : obiekt, do przechowania znalezionych danych
/// @return true, w przypadku znalezienia id, false w przypadku nie powodzenia
bool find_user_id(karta* obj);

/// @brief Funkcja szuka danych czytelnika na podstawie jego nazwiska
/// @param obj obiekt, do przechowania znalezionych danych
/// @return true, w przypadku znalezienia id, false w przypadku nie powodzenia
bool find_username(karta* obj);

/// @brief Generuje 6-cio cyfrowy numer identyfikacyjny
/// @return numer identyfikacyjny
long id_generator();


