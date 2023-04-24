#include "stan_konta.h"


ostream& operator<<(ostream& lhs, const stan_konta& rhs) {
	
	double tmp=0;

	for (int i = 0; i < rhs.charge.size() ; i++) {
		tmp += rhs.charge.at(i);
	}

	return lhs << tmp;

}

