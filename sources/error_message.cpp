#include "error_message.hpp"

ErrorMessage::ErrorMessage()
{
	errorMessage = "Undefined error message.";
}

ErrorMessage::ErrorMessage(string errorMessage)
{
	this->errorMessage = errorMessage;
}

void ErrorMessage::printError() 
{
	auto pos = errorMessage.find(':');
	
	if (pos != string::npos)
	{	
		string errorType = errorMessage.substr(0, pos + 1);
		errorMessage.erase(0, pos + 1);
		cerr << RED << errorType << RESET;
	}

	cerr << errorMessage << endl; 
}
