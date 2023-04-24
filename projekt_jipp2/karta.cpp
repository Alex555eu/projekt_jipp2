#include "karta.h"
#include "funkcje_dodatkowe.h"


void karta::push(string val) {
	string tmp;
	stringstream s(val);

	getline(s, tmp, ',');
	
	val.erase(0, tmp.length()+1);

	book.push_back(val);
	date.push_back(__DATE__);

}

void karta::remove(string _date) {
	for (int i = 0; i < date.size(); i++) {
		if (_date == date.at(i)) {
			date.erase(date.begin() + i);
			book.erase(book.begin() + i);
			charge.erase(charge.begin() + i);
		}
	}
}

void karta::remove(int index) {
	date.erase(date.begin() + index);
	book.erase(book.begin() + index);
	charge.erase(charge.begin() + index);
}

ostream& operator<<(ostream& lhs, const karta& rhs) {
	
	string tmp="";
	string tmp_double;
	double sum=0;


	
	for (int i = 0; i < rhs.book.size(); i++) {

		sum += rhs.charge.at(i);

		tmp_double = to_string(rhs.charge.at(i));
		tmp_double.erase(tmp_double.end() - 4, tmp_double.end());

		tmp += rhs.date.at(i) + " " + rhs.book.at(i) + " ||kwota do oplaty: " + tmp_double + " pln ||\n";
	}

	if (sum > 0) {
		tmp_double = to_string(sum);

		tmp_double.erase(tmp_double.end() - 4, tmp_double.end());

		tmp += "\nw sumie: " + tmp_double + " pln\n";
	}

	lhs << rhs.name << " " << rhs.surname << " nr.ID: " << rhs.id
		<< endl << tmp;

	return lhs;
}

int karta::getBookList() {

	int i = 0;
	cout << endl << "INDEX\t" << "AUTOR\t\t" << "TYTUL" << endl;
	for (i = 0; i < book.size(); i++) {
		cout << i << "\t" << text_filter(book.at(i)) << endl;
	}
	
	return i;
}

int month_str_to_num(string month) {

	if (month == "Jan") return 1;
	if (month == "Feb") return 2;
	if (month == "Mar") return 3;
	if (month == "Apr") return 4;
	if (month == "May") return 5;
	if (month == "Jun") return 6;
	if (month == "Jul") return 7;
	if (month == "Aug") return 8;
	if (month == "Sept") return 9;
	if (month == "Oct") return 10;
	if (month == "Nov") return 11;
	if (month == "Dec") return 12;
	else return 0;

}

template <class Int>
constexpr
Int

days_from_civil(Int y, unsigned m, unsigned d) noexcept
{
	static_assert(std::numeric_limits<unsigned>::digits >= 18,
		"This algorithm has not been ported to a 16 bit unsigned integer");
	static_assert(std::numeric_limits<Int>::digits >= 20,
		"This algorithm has not been ported to a 16 bit signed integer");
	y -= m <= 2;
	const Int era = (y >= 0 ? y : y - 399) / 400;
	const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
	const unsigned doy = (153 * (m > 2 ? m - 3 : m + 9) + 2) / 5 + d - 1;  // [0, 365]
	const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;         // [0, 146096]
	return era * 146097 + static_cast<Int>(doe) - 719468;
}

void balans_calculator(karta* obj) {

	string local_date = __DATE__;

	string tmp_month;
	string tmp_day;
	string tmp_year;
	
	int local_month;
	int local_day;
	int local_year;

	int users_month;
	int users_day;
	int users_year;

	int days_gap;

	for (int i = 0; i < obj->date.size(); i++) {

		stringstream s(local_date);

		getline(s, tmp_month, ' ');
		getline(s, tmp_day, ' ');
		getline(s, tmp_year, ' ');

		local_month = month_str_to_num(tmp_month);
		local_day = stoi(tmp_day);
		local_year = stoi(tmp_year);

		stringstream s2(obj->getDate(i));
	
		getline(s2, tmp_month, ' ');
		getline(s2, tmp_day, ' ');
		getline(s2, tmp_year, ' ');
	
		users_month = month_str_to_num(tmp_month);
		users_day = stoi(tmp_day);
		users_year = stoi(tmp_year);
	
		days_gap = days_from_civil(local_year, local_month, local_day) - days_from_civil(users_year, users_month, users_day) - 30;

		if (days_gap > 0) obj->setCharge(days_gap);
		else obj->setCharge(0);

	}
	
}

