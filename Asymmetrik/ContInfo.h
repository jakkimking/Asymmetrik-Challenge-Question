#pragma once
#include <string>
#include <iostream>
#include <vector>

class ContInfo
{
	public:
		ContInfo();
		ContInfo(std::string document);
		~ContInfo();

		void displayInformation();	//displays the information to the user

	private:
		std::vector<std::string> data;

		std::string getName();			// returns the full name of the individual(eg.John Smith, Susan Malick)
		std::string getPhoneNumber();	// returns the phone number formatted as a sequence of digits
		std::string getEmailAddress();	// returns the email address
};

