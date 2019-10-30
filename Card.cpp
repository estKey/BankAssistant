#include "Card.h"


Card::Card(const string& cardnumber, const string& owner, const string& bank, const string& cardtype) :m_sCardNumber(cardnumber), m_sOwner(owner), m_sBank(bank), m_sType(cardtype)
{
}

Card::Card(const string& cardnumber, const string& owner, const string& bank, const string& cardtype, const vector<Transaction*> transactions) :m_sCardNumber(cardnumber), m_sOwner(owner), m_sBank(bank), m_sType(cardtype), m_gTransactions(vector<Transaction *>(transactions))
{
}

Card::~Card()
{
}

void Card::LoadCardData(const string& filepath)
{
}

void Card::StoreCardData(const string& filepath)
{
}

string Card::ToString()
{
	string out = "Card Number: " + m_sCardNumber + "\tOwner: " + m_sOwner + "\n";
	for (auto iter = m_gTransactions.begin(); iter != m_gTransactions.end(); iter++)
		out += TransactionToString(*iter);
	return out;
}
