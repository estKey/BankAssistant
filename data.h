#pragma once

#ifndef DATA_H
#define DATA_H "DATA_H"
#include <string>
#include "Log.h"

using std::string;

class Date
{
public:
private:
	unsigned short day;
	unsigned short month;
	unsigned long long year;
public:
	Date(unsigned short day, unsigned short month, unsigned long long year) :day(day), month(month), year(year) {};
	Date(string date)
	{
		/*WIP*/
	};
	Date(const Date &d) :day(d.day), month(d.month), year(d.year) {};
};

#ifdef _cplusplus
extern "C" {
#endif
	typedef struct _Transaction {
		double amount;
		double balance;
		string date;
		string description;
	} Transaction;

	inline Transaction* InitTransaction(double amount, double balance, string date, string description)
	{
		Transaction* t = new Transaction;
		if (!t)
		{
			Log::error("Failed to Allocate a Transaction Entity!");
			return NULL;
		}
		t->amount = amount;
		t->balance = balance;
		t->date = date;
		t->description = description;
		return t;
	}

	inline void DelTransaction(Transaction* t)
	{
		delete t;
		t = NULL;
	}

	inline string TransactionToString(Transaction* t) { return "Date: " + t->date + "\tAmount: " + std::to_string(t->amount) + "\tBalance: " + std::to_string(t->balance) + "\tDescription: " + t->description + "\n";}
#ifdef _cplusplus
}
#endif

#endif // !DATA_H
