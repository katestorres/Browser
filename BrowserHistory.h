#pragma once


#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
	BrowserHistory(); //default constructor
	~BrowserHistory(); //destructor

	void visitSite(Webpage newSite); //reads/stores new site
	string back(); //previous webpage
	string forward(); //next webpage

	void readHistory(string fileName);

	string getURL(); //get url
	size_t getNavSize(); //get size

	void printBackSites(); //print sites from p to head
	void printForwardSites(); // print sites from p to tail
	void printFullHistory(); // print sites from head to tail

private:
	list<Webpage> fullHis;
	Webpage* cursorN;
	//list<Webpage>* cursorF;
	Webpage *head;
	Webpage *tail;
	int countern;
	//list<Webpage>::iterator itN;//iterator for navHis
	list<Webpage>::iterator itF;//iterator for fullHis
};