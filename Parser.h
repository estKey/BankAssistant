#pragma once
#ifndef PARSER_H
#define PARSER_H "PARSER_H"
#include "common.h"
#include "data.h"

constexpr auto MAX_BUFFER_SIZE = 512;

using std::cout;
using std::endl;
using std::string;
using std::vector;

inline void SplitLine(vector<string>&, const string&, char);

template <class T>
T CastString(const string& str)
{
	std::istringstream iss(str);
	T num;
	iss >> num;
	return num;
}

class Parser
{
public:
	/*Data*/
private:
	string m_sFilepath;
	long m_nSize;
protected:
	vector<Transaction*> m_gTransactions;
public:
	virtual ~Parser();
	vector<vector<string>> LoadCSV();
	virtual vector<Transaction*> ParseCSV()=0;
	void PrintRawData(vector<vector<string>>);
	void PrintTransactions(vector<Transaction*>);
	vector<Transaction*> GetTransactions();
protected:
	Parser(const string&);
	Parser(const Parser&);
};

#endif // !PARSER_H

