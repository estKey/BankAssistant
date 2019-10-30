#pragma once
#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H "DATA_MANAGER_H"

#include <map>
#include "common.h"
#include "data.h"
#include "Card.h"

using std::map;

static class DataManager
{
public:
	static map<string, int> ClusterTransactions(const vector<Transaction*>&);

private:

};

#endif // !DATA_MANAGER_H
