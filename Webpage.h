#pragma once
#include <string>
using namespace std;

class Webpage {
public:
	Webpage(); //default constructor
	Webpage(const string& webpageURL, const time_t& timeVisited);
	string getURL(); //returns url
	time_t getTime(); //returns time

private:
	string webpageURL;
	time_t timeVisited;
	Webpage *prev;
	Webpage *next;
	friend class BrowserHistory;
};
