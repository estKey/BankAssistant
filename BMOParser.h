#pragma once
#include "Parser.h"
class BMOParser : public Parser
{
public:
	BMOParser(const string& filepath) : Parser(filepath) {}
	~BMOParser();
	vector<Transaction*> ParseCSV();
};

