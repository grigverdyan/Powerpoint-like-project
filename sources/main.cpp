#include "error_message.hpp"
#include "engine.hpp"

int main(int argc, char *argv[]) try
{
	(void) argc;
	(void) argv;

	Engine engine; 
    engine.addSlide(); 
    //std::cout<<"Now we have " << engine.getSlideCount() << " slides\n";
	engine.start();

	//cout << "sdfsfsf\n";
	while (1)
	   ;

	return 0;
}
catch (ErrorMessage& error)
{
	error.printError();
	exit(1);
}
