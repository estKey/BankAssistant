#pragma once
#include "Parser.h"

class TDParser : public Parser
{
public:
	const char* m_sBankName[3] = { "TD" };
public:
	TDParser(const string& filepath) :Parser(filepath) {}
	TDParser(const TDParser& p) :Parser(p) {}
	~TDParser();
	vector<Transaction*> ParseCSV();
};

