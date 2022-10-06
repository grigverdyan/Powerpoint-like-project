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

void Engine::start() const
{
	//system("clear");
	
	//gotoxy(26, 10);
	cout << "Powerpoint command prompt:~$ ";
}

//void addSlide(int count = 1);	
//void deleteLastSlide();
//void deleteSlide(int number);	
//void setCurrentSlide(int toSlide);
