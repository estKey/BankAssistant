#include "TDParser.h"

TDParser::~TDParser()
{
}

vector<Transaction*> TDParser::ParseCSV()
{
	vector<vector<string>> rawData = LoadCSV();
	//PrintRawData(rawData);
	for (auto iter = rawData.begin(); iter != rawData.end(); iter++)
	{
		std::istringstream iss;
		string samount = (*iter)[2] == "" ? (*iter)[3] : (*iter)[2];
		double amount = -1.0;
		if ((*iter)[2] == "")
			amount = CastString<double>((*iter)[3]);
		else if ((*iter)[3] == "")
			amount = -CastString<double>((*iter)[2]);
		m_gTransactions.push_back(InitTransaction(amount, CastString<double>((*iter)[4]), (*iter)[0], (*iter)[1]));
	}
	return vector<Transaction*>(m_gTransactions);
}
