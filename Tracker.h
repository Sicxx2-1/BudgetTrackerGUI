#ifndef TRACKER_H
#define TRACKER_H
#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


class Tracker
{
public:
	Tracker();
	~Tracker();
	string getCurrentDate();
	void addSpending(string spendingName, int amount);
	void addSaving(string savingName, int amount);
	void printSpendings() const;
	void printSavings() const;

private:
	string spendingName;
	int amount;
	ofstream spendingFile;
	ofstream savingFile;
	map<string, int> spendings; 
	map<string, int> savings;
};





#endif

