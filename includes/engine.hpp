#pragma once

#include "header.hpp"

class Engine
{
public:
	// constructors and destructor
	Engine();
	~Engine();

	// commands
	void addSlide(int count = 1);	
	void deleteLastSlide();
	void deleteSlide(int number);	

	// setters and getters
	const int& getCurrentSlide() const;
	void setCurrentSlide(int number);
	const int& getSlideCount() const;
	void setSlideCount(int count);
	
	//
	void start() const;

private:
	int slideCount = 1;
	int currentSlide = 1;
	string lastCommand = "";
	vector<string> commands;
};
