#include "BrowserHistory.h"

//default constructor
BrowserHistory::BrowserHistory()
{
	//list<Webpage>::iterator 
	itN=navHis.begin();//iterator for navHis
	//list<Webpage>::iterator 
	itF=fullHis.begin();//iterator for fullHis
}

//destructor
BrowserHistory::~BrowserHistory()
{
	navHis.clear();
	fullHis.clear();
}

void BrowserHistory::visitSite(Webpage newSite)
{
	itN = navHis.end();
	//itF = fullHis.begin();
	navHis.insert(itN, newSite);
	//fullHis.insert(itF, newSite);
	//navHis.push_back(newSite);
	fullHis.push_back(newSite);
}

//return url
string BrowserHistory::getURL()
{
	*itN
	//list<Webpage> *ptemp;
	//Webpage temp;
	//temp = *itN;
	//Webpage temp;
	//temp = *itN;
	//Webpage pls;
	//pls = *itN;
	//return pls.getURL();
	//return navHis.back().getURL();
	//return *itN.getURL();
	//return temp.getURL();
	//return this->itN.getURL();
	//cout << "here";
	//return (*itF)->getURL();
	return ;
}

//return navsize
size_t BrowserHistory::getNavSize()
{
	//cout << navHis.size();
	return navHis.size();
}

//go to previous webpage
string BrowserHistory::back()
{
	//with the iterators
	if(itN != navHis.begin()){
		itN--;
		return itN->getURL();
		//add to fullHis
	}
	else{
		cout<< "There is no previous page" << endl;
	}
	
}

//go to next webpage
string BrowserHistory::forward()
{
//with the iterators
	if(itN != navHis.end()){
		itN++;
		return itN->getURL();
		//add to full and navHis
	}
	else{
		cout<< "There is no page to move forward to." << endl;
	}
}

//read from file
void BrowserHistory::readHistory(string fileName)
{
	ifstream myfile(fileName);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << fileName << endl;
		char ch;
		string input;
		while (myfile >> ch)
		{
			fileName.push_back(ch);
			myfile >> input;
			if (input == "new")
			{
				time_t time;
				string url;
				myfile >> url >> time;
				Webpage temp(url, time);
				visitSite(temp);
			}
			else if (input == "back")
			{
				back();
			}
			else if (input == "foward")
			{
				forward();
			}
		}
		myfile.close();
	}
	else throw invalid_argument("Could not open file " + fileName);
}

void BrowserHistory::printBackSites()
{
	list<Webpage>::iterator current; 
	current = itN;   
	for(itN = current; itN != navHis.begin(); itN--){
		cout << itN->getURL() << endl;
	}
}

void BrowserHistory::printForwardSites()
{
	list<Webpage>::iterator current;
	current = itN;
	for (itN = current; itN != navHis.end(); itN++) {
		cout << itN->getURL() << endl;
	}
}

void BrowserHistory::printFullHistory()
{
	for (itF = fullHis.begin(); itF != fullHis.end(); itF++) {
		cout << itF->getURL() << endl;
	}
}