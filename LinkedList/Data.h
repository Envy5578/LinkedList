#pragma once
#include <iostream>
class date
{
private:
	int dd;
	int mm;
	int yyyy;
public:
	~date() {};
	date() { dd = 0; mm = 0; yyyy = 0; }
	date(int _dd, int _mm, int _yyyy) :dd(_dd), mm(_mm), yyyy(_yyyy) {};
	const int& operator-(const date& local);
	const date& operator+(const int days);

	/*bool operator<(const date& local);*/

	friend std::ostream& operator<<(std::ostream& cout, date& data);

	/*date operator[](date date) {
		return date;
	}*/

	void print();
};

