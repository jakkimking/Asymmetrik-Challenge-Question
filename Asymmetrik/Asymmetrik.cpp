// Asymmetrik.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ContInfo.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string document;
	cout << "Enter document name: ";
	cin >> document;

	ContInfo getContactInfo(document);
}

