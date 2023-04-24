#pragma once

#include "karta.h"

/// @brief Przepisuje dane z plikow .csv do plikow binarnych
/// @param file_csv_name : nazwa pliku w formacie .csv
/// @param file_bin_name : nazwa pliku w formacie .bin
void csv_to_binary(string file_csv_name, string file_bin_name);

/// @brief Przepisuje dane z plikow binarnych do plikow .csv
/// @param file_bin_name : nazwa pliku w formacie .bin
/// @param file_csv_name : nazwa pliku w formacie .csv
void binary_to_csv(string file_bin_name, string file_csv_name);
