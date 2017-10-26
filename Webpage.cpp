#include "Webpage.h"

//default constuctor
Webpage::Webpage()
{
	webpageURL = "NULL";
	timeVisited = NULL;
}
//constructor
Webpage::Webpage(const string& webpageURL, const time_t& timeVisited)
{
	this->webpageURL = webpageURL;
	this->timeVisited = timeVisited;
}

//return url
string Webpage::getURL()
{
	return webpageURL;
}

//return time
time_t Webpage::getTime()
{
	return timeVisited;
}
