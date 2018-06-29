#include "stdafx.h"
#include "ContInfo.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

ContInfo::ContInfo(){
	std::cout << "Error, please include a document title." << std::endl;
}

ContInfo::ContInfo(std::string document) {
	std::ifstream in;
	std::string line;
	
	in.open(document);
	while(!in){
		std::cout << "Invalid file. Please re-enter document name: ";
		std::cin >> document;
		in.open(document);
	};
	int i = 0;
	while (!in.eof()) {
		getline(in, line);
		data.push_back(line);
	}

	in.close();

	displayInformation();
}

ContInfo::~ContInfo()
{
}

void ContInfo::displayInformation() {
	std::cout << getName() << std::endl;
	std::cout << getPhoneNumber() << std::endl;
	std::cout << getEmailAddress() << std::endl;
}

std::string ContInfo::getName() {
	std::regex rgx("[A-Z][a-z]+ [A-Z][a-z]+");							//create a regular expression to match for names
	std::size_t found;
	std::size_t found2;

	
	for (size_t i = 0; i < data.size(); i++) {
		if (regex_match(data[i], rgx)) {								//matches regex with data from vector
			found = data[i].find("Technologies");						//check for Technologies and Developer. Could not find a way to imeplement
			found2 = data[i].find("Developer");							//this in C++ without hardcoding. Was hoping to test against a dictionary
			if (found > 100 && found2 > 100) {							//but C++ does not offer a possible dictionary library to compare strings with
				return "Name: " + data[i];
			}
		}
	}

	return "Name not found.";
}

std::string ContInfo::getPhoneNumber() {
	std::size_t found;
	std::size_t found2;
	std::size_t found3;
	int phoneFound = 0;
	std::string line, number;
	for (size_t i = 0; i < data.size(); ++i) {
		found = data[i].find("Phone");									//checks to see if "Phone" is included	
		found2 = data[i].find("Tel");									//checks to see if "Tel" is included
		found3 = data[i].find("(");										//checks to see if "(" is included, as the start of a phone number
		if(phoneFound == 0){
			if (found < 100 || found2 < 100 || found3 < 100) {			//verifies to see if one of the instances was found
				line = data[i];
				phoneFound = 1;											//boolean for phone, that way we don't accidentally grab a fax number
			}
		}
	}

	if (phoneFound == 0)
		return "No phone number found.";
	else {
		for (int i = 0; i < line.size(); i++) {
			if (isdigit(line[i]))
				number = number + line[i];								//parse the integers out of the string line
		}

		return "Phone Number: " + number;
	}
}

std::string ContInfo::getEmailAddress() {
	std::size_t found;
	for (size_t i = 0; i < data.size(); ++i) {
		found = data[i].find("@");										//checks for an email utilizing the "@" character
		if (found < 100) {
			return "Email: " + data[i];
		}
	}

	return "No email found.";
}