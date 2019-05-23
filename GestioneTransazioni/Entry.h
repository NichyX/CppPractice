#include <string>

#pragma once

using namespace std;

class Entry
{
public:
	Entry();
	~Entry();
	void setDate(string theDate);
	string getDate() const;
	void setDescription(string theDescription);
	string getDescription() const;
	void setAmount(int theAmount);
	int getAmount() const;
private:
	string date;
	string description;
	int amount;
};
