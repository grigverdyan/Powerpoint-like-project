#pragma once

#include "header.hpp"
#include "colors.hpp"

class ErrorMessage {
public:
	ErrorMessage();
	ErrorMessage(string errorMessage);
	void printError();
	
private:
	string errorMessage;
};
