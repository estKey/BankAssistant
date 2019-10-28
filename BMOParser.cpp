#include "BMOParser.h"

BMOParser::~BMOParser()
{
}

vector<Transaction*> BMOParser::ParseCSV()
{
	vector<vector<string>> rawData = LoadCSV();
	rawData.erase(rawData.begin());
	//PrintRawData(rawData);
	for (auto iter = rawData.begin(); iter != rawData.end(); iter++)
		m_gTransactions.push_back(InitTransaction(CastString<double>((*iter)[3]), CastString<double>((*iter)[3]), (*iter)[2], (*iter)[4].substr(0, (*iter)[4].find("\n"))));
	return vector<Transaction*>(m_gTransactions);
}