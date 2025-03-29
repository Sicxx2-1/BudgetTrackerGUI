#include "Tracker.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;



Tracker::Tracker()
{

}

Tracker::~Tracker()
{
	cout << "Finished recording savings and spendings!" << endl;
}

string Tracker::getCurrentDate()
{
	time_t now = time(0);
	struct tm localTime;
	localtime_s(&localTime, &now);  // Safe version

	char buf[11];
	strftime(buf, sizeof(buf), "%Y-%m-%d", &localTime);
	return string(buf);
}

void Tracker::addSpending(string spendingName, int amount)
{
	spendings.insert({ spendingName, amount });
	spendingFile.open("Spendings.csv", ios::app);
	spendingFile << spendingName << "," << amount << "," << "RON" << "," << getCurrentDate() << endl;
	spendingFile.close();
}

void Tracker::addSaving(string savingName, int amount)
{
	savings.insert({ savingName, amount });
	spendingFile.open("Savings.csv", ios::app);
	spendingFile << savingName << "," << amount << "," << "RON" << "," << getCurrentDate() << endl;
	spendingFile.close();
}

void Tracker::printSpendings() const
{
	cout << "Spendings: " << endl;
	for (auto i : spendings)
	{
		cout << i.first << " : " << i.second << " RON" << endl;
	}
}

void Tracker::printSavings() const
{
	cout << "Savings: " << endl;
	for (auto i : savings)
	{
		cout << i.first << " : " << i.second << " RON" << endl;
	}
}
