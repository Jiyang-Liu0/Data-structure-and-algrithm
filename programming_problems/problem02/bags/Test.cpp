#include "Test.hpp"

Person::Person() : name(""),age(0),gender('X'){

}

std::string Person::getName() const{
    return name;
}

void Person::setName(std::string newName){
    name = newName;
}

int Person::getAge() const{
    return age;
}

void Person::setAge(int newAge)
{
    age=newAge;
}

char Person::getGender() const{
    return gender;
}

void Person::setGender(char newGender)
{
    gender=newGender;
}