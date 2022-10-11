#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}

	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 0)
		{
			_day += GetMonthDay(_year, _month - 1);
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 13;
			}
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date dat(*this);
		_day -= day;
		return dat;
	}

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator==(const Date& d)
	{
		return d._year == _year
			&& d._month == _month
			&& d._day == _day;
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		
		return false;
	}
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}

	

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		_capacity = capacity;
		_top = 0;
	}
	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		memcpy(_a, st._a, sizeof(int)*st._top);//Éî¿½±´
		_capacity = st._capacity;
		_top = st._top;
	}
	void Push(int x)
	{
		_a[_top] = x;
		_top++;
	}
	
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _capacity;
	int _top;
};

class MyQueue
{
public:
	void push(int x)
	{
		_pushST.Push(x);
	}
private:
	Stack _pushST;
	Stack _popSt;
	size_t _size = 0;

};


void test1()
{
	//Date d(2022,10,9);
	//Date d1(d);
	//Stack st;
	//st.Push(1);
	//st.Push(2);
	//Stack st1(st);
	MyQueue q;
	MyQueue q1(q);
}

void test2()
{
	Date d1(2022, 10, 9);
	Date d2(2023, 1, 1);
	Date d3(2022, 10, 9);
	d1 == d2;//operator==(d1,d2)
	cout << (d1 == d3) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
}

void test3()
{
	Date d1(2022, 10, 9);
	Date d2(2022, 11, 11);
	//d2 += 100;
	d2.print();
	d2 -= 10000;
	d2.print();
	Date d3 = d1 + 100;
	d3 = d1 - 100;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}