#include "dane_osobowe.h"

dane_osobowe::dane_osobowe() { 
	name = "";
	surname = "";
	id = 0;

}

dane_osobowe::dane_osobowe(string name, string surname, long id): name(name), surname(surname), id(id) {}


ostream& operator<<(ostream& lhs, const dane_osobowe& rhs) {

	lhs << rhs.name << " " << rhs.surname << " nr.ID: " << rhs.id;

	return lhs;
}

