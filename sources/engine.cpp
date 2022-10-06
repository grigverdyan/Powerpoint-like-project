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

void addSlide(int count = 1){
    setSlideCount(getSlideCount() + count);
}

void Engine::start() const
{
    
	system("clear");
    cout<<"Now we have " << getSlideCount() <<" slides\n";
	gotoxy(5, 5);
    for (size_t i = 0 ; i < 30; ++i){
        gotoxy(5, 5+i);
        cout << "#";
    }

    for (size_t i = 0 ; i < 120 ; ++i){
        gotoxy(5+i,5);
        cout << "#";
    }

    gotoxy(125,5);    
    for(size_t i = 0; i < 30; ++i) {
        gotoxy(125,5 + i);
        cout<<"#";
    }
    
    gotoxy(5,35);
    for (size_t i = 0; i < 125; ++i) {
        gotoxy(35, 5 + i);
        cout<<"#";
        
    } 
    
    gotoxy(5,35);
    for (size_t i = 0; i < 121; ++i) {
        gotoxy(5 + i, 35);
        cout<<"#";
    }
    cout<<"\n";


	//cout << "Powerpoint command prompt:~$ ";
}

//void addSlide(int count = 1);	
//void deleteLastSlide();
//void deleteSlide(int number);	
//void setCurrentSlide(int toSlide);
