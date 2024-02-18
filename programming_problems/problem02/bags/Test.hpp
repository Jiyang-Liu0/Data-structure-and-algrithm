#include <string>
class Person
{
private:
    std::string name;
    int age;
    char gender;
public:
    Person();
    ~Person();
    std::string getName() const;
    void setName(std::string newName);
    int getAge()  const;
    void setAge(int newAge);
    char getGender() const;
    void setGender() const;
    virtual std::string toString() const=0;
    
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}
