#include <iostream>
#include "Movie.hpp"
bool set_rating(double rating){
    if(rating >= 0 && rating <=10){
        std::cout<<"Rating must be between 0 and 10."<<endl;
        return false;
    }
    this->rating=rating;
    return true;
}

void Play(){
    std::cout<<"Rating: "<<rating<<endl;
}

void Details(){
    std::cout<<"Title: "<<title<<endl;
    std::cout<<"Description: "<<description<<endl;
    std::cout<<"Rating: "<<rating<<endl;
}
