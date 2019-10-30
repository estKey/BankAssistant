#include "User.h"

User::User()
{
	m_nId = GetId();
	m_sName = "User";
	m_sPassword = "darkknight2019";
}

User::User(const string& name, const string& password) :m_nId(GetId()), m_sName(name), m_sPassword(password)
{
}

User::User(const string& name, const string& password, const Card& card) : m_nId(GetId()), m_sName(name), m_sPassword(password)
{
	m_gCards.push_back(card);
}

User::User(const User& user) : m_sName(user.m_sName), m_sPassword(user.m_sPassword), m_nId(user.m_nId), m_gCards(vector<Card>(user.m_gCards))
{
}

User::~User()
{
}

void User::BindCard(const string& cardnumber, const string& bank, const string& cardtype, const string& filepath)
{
	vector<Transaction*> transactions;
	if (bank == "bmo")
		transactions = BMOParser(filepath).GetTransactions();
	else if (bank == "td")
		transactions = TDParser(filepath).GetTransactions();
	m_gCards.push_back(Card(cardnumber, m_sName, bank, cardtype, transactions));
}

void User::BindCard(const Card& card)
{
	m_gCards.push_back(card);
}

void User::LoadUserData(const string& filepath)
{
	
}

void User::StoreUserData(const string& filepath)
{

}

string User::ToString()
{
	string out = "Name: " + m_sName + "\nPassword: " + m_sPassword + "\n";

	return string();
}

unsigned long long User::GetId()
{
	return 0;
}
