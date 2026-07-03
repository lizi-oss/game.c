#include<iostream>
using namespace std;

enum COLOR { WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal {
public:
    Mammal();
    Mammal(int age);
    ~Mammal();
    int GetAge() const;
    void SetAge(int);
    int GetWeight() const;
    void SetWeight(int);

    void Speak() const;
    void Sleep() const;
protected:
    int itsAge;
    int itsWeight;
};

Mammal::Mammal() {
    itsAge = 0;
    itsWeight = 0;
}

Mammal::Mammal(int age) {
    itsAge = age;
    itsWeight = 0;
}

Mammal::~Mammal() {}

int Mammal::GetAge()const {
    return itsAge;
}

void Mammal::SetAge(int x) {
    itsAge = x;
}

int Mammal::GetWeight() const {
    return itsWeight;
}

void Mammal::SetWeight(int x) {
    itsWeight = x;
}

void Mammal::Speak() const {
    cout << "Mammal is speaking..." << endl;
}

void Mammal::Sleep() const {
    cout << "Mammal is sleeping" << endl;
}

class Dog :public Mammal {
public:
    Dog();
    Dog(int age);
    Dog(int age, int weight);
    Dog(int age, COLOR color);
    Dog(int age, int weight, COLOR color);
    ~Dog();

    COLOR GetColor() const;
    void SetColor(COLOR color);

    void WagTail();
    void BegForFood();

private:
    COLOR itsColor;
};

Dog::Dog() {
    itsColor = WHITE;
}

Dog::Dog(int age) :Mammal(age) {
    itsColor = WHITE;
}

Dog::Dog(int age, int weight) :Mammal(age) {
    itsWeight = weight;
    itsColor = WHITE;
}

Dog::Dog(int age, COLOR color) :Mammal(age) {
    itsColor = color;
}

Dog::Dog(int age, int weight, COLOR color) :Mammal(age) {
    itsWeight = weight;
    itsColor = color;
}

Dog::~Dog() {}

COLOR Dog::GetColor() const
{
    return itsColor;
}

void Dog::SetColor(COLOR color)
{
    itsColor = color;
}

void Dog::WagTail() {
    cout << "The dog is wagging its tail..." << endl;
}

void Dog::BegForFood() {
    cout << "The dog is begging for food..." << endl;
}

int main() {
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.Speak();
    Rover.WagTail();
    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;
    return 0;
}
