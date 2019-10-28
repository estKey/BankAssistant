#include "Parser.h"

Parser::Parser(const string& filepath) : m_sFilepath(filepath) { m_nSize = 0; }

Parser::Parser(const Parser& p) : m_sFilepath(p.m_sFilepath), m_nSize(p.m_nSize), m_gTransactions(vector<Transaction*>(p.m_gTransactions)) {}

Parser::~Parser()
{
	for (auto iter = m_gTransactions.begin(); iter != m_gTransactions.end(); iter++)
	{
		cout << "Deleting " << TransactionToString(*iter);
		DelTransaction(*iter);
	}
	m_gTransactions.clear();
}

vector<vector<string>> Parser::LoadCSV()
{
	std::ifstream infile;
	vector<vector<string>> rawData;
	cout << "Opening File " << m_sFilepath << "...\n";
	infile.open(m_sFilepath, std::ios::in);
	if (!infile.is_open())
	{
		cout << "Open File Failed.\n";
		return rawData;
	}
	string buffer;
	int lineCounter = 0;
	while (getline(infile, buffer) && infile.good())
	{
		vector<string> row;
		SplitLine(row, buffer, ',');
		if (row.size())
			rawData.push_back(row);
	}
	infile.close();
	cout << "Extraction Complete, Matrix Size: " << rawData.size() << 'x' << rawData[0].size() << endl;
	return rawData;
}

void Parser::PrintRawData(vector<vector<string>> rawData)
{
	for (auto row = rawData.begin(); row != rawData.end(); row++)
	{
		for (auto iter = (*row).begin(); iter != (*row).end(); iter++)
			cout << (*iter) << "\t";
		cout << endl;
	}
}

void Parser::PrintTransactions(vector<Transaction*> data)
{
	for (auto iter = data.begin(); iter != data.end(); iter++)
		cout << TransactionToString(*iter);
}

vector<Transaction*> Parser::GetTransactions()
{
	return vector<Transaction*>(m_gTransactions);
}

inline void SplitLine(vector<string>& dist, const string& line, char delimiter)
{
	//cout << "Spliting Line [" << line << "]...\n";
	string::size_type idx = line.find(delimiter);
	if (idx == line.npos)
		return;  // skip the line that is not delimiter separated
	else {
		string buffer = line;
		int i = 0;
		while (!buffer.empty())
		{
			if (buffer.find(delimiter) == string::npos)
			{
				dist.push_back(buffer);
				buffer.clear();
				break;
			}
			string s_temp = buffer.substr(0, buffer.find(delimiter));
			dist.push_back(s_temp);
			buffer.erase(0, buffer.find(delimiter) + 1);
			i++;
		}
	}
	return;
}
