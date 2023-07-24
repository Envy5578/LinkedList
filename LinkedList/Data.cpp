#include "Data.h"

void date::print()
{
	std::cout << "День - " << dd << std::endl;
	std::cout << "Месяц - " << mm << std::endl;
	std::cout << "Год - " << yyyy << std::endl;
}

const int& date::operator-(const date& local)
{
	int day;
	if (this->yyyy > local.yyyy) {
		day = (((this->yyyy - local.yyyy) * 365) + (this->mm * 30) + (this->dd)) - ((local.mm * 30) + (local.dd));
	}
	else if (this->yyyy == local.yyyy) {
		day = (this->mm * 30) + (this->dd) - ((local.mm * 30) + (local.dd));
	}
	else {
		exit(0);
	}
	return day;
}

const date& date::operator+(const int days)
{
	date help;
	int temp, day, month, year;
	if (days > 365) {
		temp = days % 365;
		year = days / 365;
		month = temp / 30;
		day = temp % 30;
		yyyy += year; mm += month; dd += day;
		if (dd > 30) {
			mm++; dd -= 30;
		}if (mm > 12) {
			yyyy++; mm -= 12;
		}
		help.dd = dd; help.mm = mm; help.yyyy = yyyy;
	}
	else {
		month = days / 30;
		day = days % 30;
		mm += month; dd += day;
		if (dd > 30) {
			mm++; dd -= 30;
		}if (mm > 12) {
			yyyy++; mm -= 12;
		}
		help.dd = dd; help.mm = mm; help.yyyy = yyyy;
	}
	return help;
}

std::ostream& operator<<(std::ostream& cout, date& data)
{

	cout << data.dd << "." << data.mm << "." << data.yyyy;
	return cout;
}

