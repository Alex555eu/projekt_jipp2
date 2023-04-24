#include "zapis_binarny.h"

using namespace std;

void csv_to_binary(string file_csv_name, string file_bin_name) {

	string tmp_line;
	int tmp_size;


	ifstream file_csv(file_csv_name);
	ofstream file_bin(file_bin_name, ios::binary);


	if (!file_csv.good()) {
		cout << endl << "Blad otwarcia pliku" << endl;
		return;
	}

	if (!file_bin.good()) {
		cout << endl << "Blad otwarcia pliku" << endl;
		return;
	}

	getline(file_csv, tmp_line);

	while (!file_csv.eof()) {

		tmp_size = tmp_line.length();

		file_bin.write((char*) (&tmp_size), sizeof(tmp_size));
		file_bin.write(tmp_line.c_str(), tmp_size); 

		getline(file_csv, tmp_line);

	}

	

	file_bin.close();
	file_csv.close();

}


void binary_to_csv(string file_bin_name, string file_csv_name) {

	string previous_line="";
	string tmp_line="";
	int tmp_size;

	ofstream file_csv(file_csv_name);
	ifstream file_bin(file_bin_name, ios::binary);

	if (!file_csv.good()) {
		cout << endl << "Blad otwarcia pliku" << endl;
		return;
	}

	if (!file_bin.good()) {
		cout << endl << "Blad otwarcia pliku" << endl;
		return;
	}

	

	while (file_bin) { 

		file_bin.read((char*) (&tmp_size), sizeof(tmp_size));

		if (tmp_size < 1) break; 
								
								 

		tmp_line.resize(tmp_size); 
								   
	
		file_bin.read((char*) (&tmp_line[0]), tmp_size); 

		if(previous_line != tmp_line)    
										 
			file_csv << tmp_line << endl;

		previous_line = tmp_line;
	
	
	}

	file_bin.close();
	file_csv.close();

}