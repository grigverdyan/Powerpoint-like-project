#include <iostream>
#include <vector>

class Engine {
    public:
        Engine(){
            slideSize = -1;
            currentSlide = -1; 
        }
        
        void setSize(int size){
            if (size < -1){
                std::cout<<"Size can't be less than 0\n";
            } else {
                slideSize = size;
            }
        }
        
        size_t getSize(){
            return slideSize;
        }

        void addSlide(){
            ++slideSize;
            Rectangles.push_back(0);
            Triangles.push_back(0);
            Circles.push_back(0);
        }
        
        void deletelastSlide(){
            if (slideSize >= 1){
                setSize(slideSize - 1);
                Rectangles.pop_back();
                Circles.pop_back();
                Triangles.pop_back();
                if (getCurrentSlide() == slideSize + 1) {
                    setCurrentSlide(slideSize);
                }
            }
        }


        void deleteAll(){
            setSize(-1);
            Rectangles.clear();
            Triangles.clear();
            Circles.clear();
        }
        

        void deletePosition(size_t number){
            if (number <= slideSize && number > 0){
                --slideSize;
                Rectangles.erase(Rectangles.begin() + number - 1);
                Triangles.erase(Triangles.begin() + number - 1);
                Circles.erase(Circles.begin() + number - 1);
                if (getCurrentSlide() == slideSize + 1){
                    setCurrentSlide(slideSize);
                }
            } else {
                std::cout<<"There is no such slide\n";
            }
        }

        void setCurrentSlide(size_t activeSlide){
            if (activeSlide <= slideSize){
                currentSlide = activeSlide;
                std::cout<<"You are now in slide "<<currentSlide << "\n";
            } else {
                std::cout<<"There is no slide with number " << activeSlide << "\n"; 
            }
        }


        size_t getCurrentSlide(){
            return currentSlide;
        }

    private:
        size_t slideSize;
        size_t currentSlide;

    public:
        std::vector<int> Rectangles;
        std::vector<int> Triangles;
        std::vector<int> Circles;
        
};


class Slide : public Engine {
    public:
        void addRectangle(size_t slideNumber, Engine *engine) {
            if (slideNumber <= engine->getSize()){
                std::cout<<"you added a rectangle in slide " << slideNumber << "\n";
                engine->Rectangles.at(slideNumber)++;
            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void addTriangle(size_t slideNumber, Engine *engine) {
            if (slideNumber <= engine->getSize()){
                std::cout<<"you added a triangle in slide " << slideNumber << "\n";
                engine->Triangles.at(slideNumber)++;
            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void addCircle(size_t slideNumber, Engine *engine) {
            if (slideNumber <= engine->getSize()){
                std::cout<<"you added a circle in slide " << slideNumber << "\n";
                engine->Circles.at(slideNumber)++;
            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void showSlide(size_t slideNumber, Engine *engine){
            if (slideNumber <= engine -> getSize() && slideNumber != -1){ 
                std::cout<<"there is " << engine->Rectangles.at(slideNumber) << " rectangles in slide, " << engine->Triangles.at(slideNumber) 
                << "triangles and " << engine->Circles.at(slideNumber) << " circles in slide " << slideNumber << "\n";
            } else {
                std::cout<<"There is no slide with number " << slideNumber;
            }
        }
};

int main(){
	Engine *engine = new Engine();
    return 0;
}


    
