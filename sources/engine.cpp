#include "engine.hpp"
#include "utils.hpp"

Engine::Engine() {};

Engine::~Engine() {};



void Engine::setCommands()
{
    commands.push_back("add slide");
    commands.push_back("remove slide");
}

const int& Engine::getCurrentSlide() const
{
	return currentSlide;
}

void Engine::setCurrentSlide(int number)
{
	if (number < 1 || number > getSlideCount())
		return;
	currentSlide = number;
}

const int& Engine::getSlideCount() const
{
	return slideCount;
}

void Engine::setSlideCount(int count)
{
	if (count < 0)
		return;
	slideCount = count;
}

void Engine::addSlide(int count)
{
    setSlideCount(getSlideCount() + count);

}

void Engine::deleteLastSlide()
{   
    if (getSlideCount() == 0)
        return;
    setSlideCount(getSlideCount() - 1);
}

void Engine::start() const
{
   
	system("clear");
    cout << "Slides count: " << getSlideCount() << endl;
	
	gotoxy(leftUpCornerY, leftUpCornerX);
    for (size_t i = 0 ; i < verticalBorderSize; ++i)
	{
        gotoxy(leftUpCornerX, leftUpCornerY + i);
        cout << "#";
    }

    for (size_t i = 0 ; i < horizontalBorderSize ; ++i)
	{
        gotoxy(leftUpCornerX + i, leftUpCornerY);
        cout << "#";
    }
	
    gotoxy(horizontalBorderSize, leftUpCornerY);
    for(size_t i = 0; i < verticalBorderSize; ++i)
	{
        gotoxy(horizontalBorderSize + leftUpCornerX, leftUpCornerY + i);
        cout << "#";
    }
    
    gotoxy(leftUpCornerY, leftUpCornerY + commandsWindowY);
    for (size_t i = 0; i < verticalBorderSize; ++i)
	{
        gotoxy(leftUpCornerY + commandsWindowY, leftUpCornerY + i);
        cout << "#";
    } 
    
    gotoxy(leftUpCornerX, verticalBorderSize + leftUpCornerY);
    for (size_t i = 0; i < horizontalBorderSize + 1; ++i)
	{
        gotoxy(leftUpCornerX + i, verticalBorderSize + leftUpCornerY);
        cout << "#";
    }
    cout << endl;
    
	string command = "";
    while (command != "exit"){
         
	    gotoxy(leftUpCornerX, leftUpCornerY + verticalBorderSize + 2);        
	    cout << GREEN <<  "Powerpoint command prompt" << RESET << ":~$ ";
	    cin >> command;
        if (command == "help")
        {
            cout<<endl;
            gotoxy(leftUpCornerX, leftUpCornerY + verticalBorderSize + 2);
            cout<<"You can type one of this commands:\n";
            for (size_t i = 0; i < commands.size(); ++i)
            {
                
	            gotoxy(leftUpCornerX, leftUpCornerY + verticalBorderSize + 3);
                std::cout<<commands.at(i) << endl;
            }
        } 
    }
}

