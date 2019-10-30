#include "stdafx.h"

int main(void)
{
	cout << "Start Test\n";
	User user;
	user.BindCard("123456", "TD", "Debit", "./data_td.csv");
	return 0;
}