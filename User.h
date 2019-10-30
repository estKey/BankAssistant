#pragma once
#ifndef USER_H

#include "TDParser.h"
#include "BMOParser.h"
#include "DataManager.h"

using std::vector;
using std::string;

class User
{
private:
	unsigned long long m_nId;
	string m_sName;
	string m_sPassword;
	vector<Card> m_gCards;
public:
	User();
	User(const string& name, const string& password);
	User(const string&, const string&, const Card&);
	User(const User&);
	~User();
	void BindCard(const string&, const string&, const string&, const string&);
	void BindCard(const Card&);
	void LoadUserData(const string&);
	void StoreUserData(const string&);
	string ToString();
private:
	unsigned long long GetId();
};

#endif // !USER_H

