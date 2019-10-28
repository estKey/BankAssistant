#include "stdafx.h"

int main(void)
{
	cout << "Start Test\n";
	TDParser td("./data_td.csv");
	vector<Transaction*> Transactions = td.ParseCSV();
	td.PrintTransactions(Transactions);
	BMOParser bmo("./data_bmo.csv");
	Transactions = bmo.ParseCSV();
	bmo.PrintTransactions(Transactions);
	return 0;
}