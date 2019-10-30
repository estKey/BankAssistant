#pragma once

#ifndef CARD_H
#define CARD_H "CARD_H"

#include <string>
#include <vector>
#include "data.h"

using std::string;
using std::vector;

class Card
{
public:
	string m_sCardNumber;
	string m_sOwner;
	string m_sBank;
	string m_sType;
	vector<Transaction*> m_gTransactions;
public:
	Card(const string&, const string&, const string&, const string&);
	Card(const string&, const string&, const string&, const string&, const vector<Transaction*>);
	~Card();
	string ToString();
private:
	void LoadCardData(const string&);
	void StoreCardData(const string&);
};


#endif