#include "engine.hpp"
#include "utils.hpp"

Engine::Engine() {};

Engine::~Engine() {};

const int& Engine::getCurrentSlide() const
{
	return currentSlide;
}

void Engine::setCurrentSlide(int number)
{
	if (number < 1)
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

	gotoxy(leftUpCornerX, leftUpCornerY + verticalBorderSize + 2);
	cout << GREEN <<  "Powerpoint command prompt" << RESET << ":~$ ";
	string command;
	cin >> command;
}

//void addSlide(int count = 1);	
//void deleteLastSlide();
//void deleteSlide(int number);	
//void setCurrentSlide(int toSlide);
