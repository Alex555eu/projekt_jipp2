#include "karta.h"
#include "menu.h"
#include "interfejs.h"
#include "zapis_binarny.h"
#include "polimorfizm.h"


using namespace std;


int main(int argc, char* argv[])
{
  
    cout << "Witaj ";

    for (int i = 1; i < argc; i++) {
        cout << argv[i] << " ";
    }
    
    cout << endl;


    binary_to_csv("inwentarz.bin", "inwentarz.csv");
    binary_to_csv("uzytkownicy.bin", "uzytkownicy.csv");
    binary_to_csv("wypozyczone.bin", "wypozyczone.csv");
 
    menu_1();
   
    csv_to_binary("inwentarz.csv", "inwentarz.bin");
    csv_to_binary("uzytkownicy.csv", "uzytkownicy.bin");
    csv_to_binary("wypozyczone.csv", "wypozyczone.bin");
    
    
    return 0;
}

