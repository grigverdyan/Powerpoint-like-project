#include <iostream>
#include <string>
#include <tuple>
#include <vector>


using Rectangles = std::vector<std::tuple<size_t, size_t, int, int, std::string>>;
using Triangles = std::vector<std::tuple<size_t, size_t, size_t, std::string>>;
using Circles = std::vector<std::tuple<size_t, std::string>>;

//using Objects = std::tuple<Rectangles, Triangles, Circles>;

class Engine {
    public:
        Engine(){
            slideSize = -1;
            currentSlide = -1;
            mySlides = {};

        }

        void setSize(int size){
            if (size < -1){
                std::cout<<"Size can't be less than 0\n";
            } else {
                slideSize = size;
              }
        }

        int getSize(){
            return slideSize;
        }

        void addSlide(){
            ++slideSize;
            myRectangles.push_back(std::make_tuple(0,0,0,0,""));
            myTriangles.push_back(std::make_tuple(0,0,0,""));
            myCircles.push_back(std::make_tuple(0,""));
            mySlides.resize(slideSize + 1);
           
        }


        void deletelastSlide(){
            if (slideSize >= 1){
                setSize(slideSize - 1);
                myRectangles.pop_back();
                myCircles.pop_back();
                myTriangles.pop_back();
                mySlides.pop_back();
                if (getCurrentSlide() == slideSize + 1) {
                    setCurrentSlide(slideSize);
                }
            }
        }


        void deleteAll(){
            setSize(-1);
            myRectangles.clear();
            myTriangles.clear();
            myCircles.clear();
            mySlides.clear();
        }


        void deletePosition(int position){
            if (position <= slideSize && position > 0){
                --slideSize;
                myRectangles.erase(myRectangles.begin() + position - 1);
                myTriangles.erase(myTriangles.begin() + position - 1);
                myCircles.erase(myCircles.begin() + position - 1);
                mySlides.erase(mySlides.begin() + position - 1);
                if (getCurrentSlide() == slideSize + 1){
                    setCurrentSlide(slideSize);
                }
            } else {
                std::cout<<"There is no such slide\n";
            }
        }

        void setCurrentSlide(int activeSlide){
            if (activeSlide <= slideSize){
                currentSlide = activeSlide;
                std::cout<<"You are now in slide "<<currentSlide << "\n";
            } else {
                std::cout<<"There is no slide with number " << activeSlide << "\n";
            }
        }


        int getCurrentSlide(){
            return currentSlide;
        }

        int getSlideSize(){
            return mySlides.size();
        }
    private:
        int slideSize;
        int currentSlide;

    public:
        Rectangles myRectangles;
        Triangles myTriangles;
        Circles myCircles;
        std::vector<std::tuple<Rectangles, Triangles, Circles>> mySlides;

};


class Slide : public Engine {
    public:
        void addRectangle(int slideNumber, Engine *engine, int length, int width, int posX, int posY, std::string color) {
            if (slideNumber <= engine->getSlideSize()){
                mySlides.resize(slideNumber + 1);

                //myRectangles.resize(slideNumber);
                std::get<0>(mySlides.at(slideNumber)).resize(slideNumber);
                std::get<0>(mySlides.at(slideNumber)).push_back(std::make_tuple(length, width, posX, posY, color));
                std::cout<<"you added a rectangle in slide " << slideNumber << "with length " << length << "\n";

            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void addTriangle(int slideNumber, Engine *engine, size_t a, size_t b, size_t c, std::string color) {
            if (slideNumber <= engine->getSize()){
                std::cout<<"you added a triangle in slide " << slideNumber << "\n";
                std::get<1>(mySlides.at(slideNumber)).push_back(std::make_tuple(a, b, c, color));
            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void addCircle(int slideNumber, Engine *engine, size_t radius, std::string color) {
            if (slideNumber <= engine->getSize()){
                std::cout<<"you added a circle in slide " << slideNumber << "\n";
                std::get<2>(mySlides.at(slideNumber)).push_back(std::make_tuple(radius, color));
            } else {
                std::cout<<"There is no slide with number " << slideNumber << "\n";
            }
        }

        void showSlide(int slideNumber, Engine *engine){
            if (slideNumber <= engine -> getSize() && slideNumber != -1){
                std::cout<<"RECTANGLES\n";
                std::cout<<std::get<0>(mySlides.at(slideNumber)).size();
                for (size_t i = 1; i < std::get<0>(mySlides.at(slideNumber)).size(); ++i){
                    std::cout<<std::get<0>(myRectangles.at(slideNumber))<<std::get<1>(myRectangles.at(slideNumber))<<std::get<2>(myRectangles.at(slideNumber))<<std::get<3>(myRectangles.at(slideNumber));
                }

            } else {
                std::cout<<"There is no slide with number " << slideNumber;
            }
        }
};

int main(){
    Engine *engine = new Engine();
    engine -> addSlide();
    engine -> addSlide();
    engine -> addSlide();
    std::cout<<engine->getSlideSize();
    Slide *slide = new Slide();
    //slide -> addRectangle(engine->getSlideSize() - 1 ,engine, 2, 1, 2, 2, "red");
    slide -> addRectangle(0,engine,2,2,2,2,"red");
    slide -> addRectangle(0,engine,3,3,3,3,"red");
    slide -> addRectangle(1,engine,4,5,6,7,"black");
    slide -> showSlide(0,engine);
    //slide -> addTriangle(0,engine,1,2,3,"aa");
    //slide -> addRectangle(1,engine, 1, 1, 1, 1, "blue");
    //slide -> addCircle(0,engine,2,"red");
    //delete engine;
    //delete slide;
    return 0;
}

