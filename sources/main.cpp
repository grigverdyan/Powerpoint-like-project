#include "error_message.hpp"
#include "engine.hpp"

int main(int argc, char *argv[]) try
{
	(void) argc;
	(void) argv;

	Engine engine;
    engine.setCommands(); 
    engine.addSlide(); 
	engine.start();

	//cout << "sdfsfsf\n";

	return 0;
}
catch (ErrorMessage& error)
{
	error.printError();
	exit(1);
}
