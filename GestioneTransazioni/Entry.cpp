#include "Entry.h"

using namespace std;

Entry::Entry()
{

}


Entry::~Entry()
{

}

void Entry::setDate(string theDate)
{
    date = theDate;
}

string Entry::getDate() const
{
    return date;
}

void Entry::setDescription(string theDescription)
{
    description = theDescription;
}

string Entry::getDescription() const
{
    return description;
}

void Entry::setAmount(int theAmount)
{
    amount = theAmount;
}

int Entry::getAmount() const
{
    return amount;
}
