#include "DataManager.h"

map<string, int> DataManager::ClusterTransactions(const vector<Transaction*>& transactions)
{
	map<string, int> cluster;
	for (auto iter = transactions.begin(); iter != transactions.end(); iter++)
	{
		string buffer = (*iter)->description;
		if (cluster.find(buffer) == cluster.end())
			cluster[buffer] = 1;
		else
			cluster[buffer]++;
	}
	return cluster;
}
