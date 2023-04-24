#pragma once

/// @brief Interface wywolywany, w wyniku wybioru opcji ,,czytelnik,, z interface'u menu_1, rozpoczynajacy procedure poszukiwania zarejestrowanego czytelnika
void interface_1();
/// @brief Interface wywolywany, w wyniku wybioru opcji ,,czytelnik,, z interface'u menu_1, rozpoczynajacy procedure rejestracji nowego czytelnika
void interface_2();
/// @brief Interface wywolywany, w wyniku nastepstwa dzialania interface'u _1 oraz _2. Wykonuje operacje na polce bibliotecznej porzycz/oddaj
/// @param obj obiekt przekazywany do interface'u za pomoca ktorego zostana wykonane operacje
void interface_main(karta* obj);


