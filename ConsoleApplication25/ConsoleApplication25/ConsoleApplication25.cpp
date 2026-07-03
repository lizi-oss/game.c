#include<iostream>
#include<string>
using namespace std;

enum COLOR{ WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal {
public:
    Mammal() = default;
    Mammal(int age);
    ~Mammal() = default;
    int GetAge() const;
    void SetAge(int);
    int GetWeight() const;
    void SetWeight(int);
    virtual void speak()const;
    virtual void sleep()const;
protected:
    int itsAge = 0;
    int itsWeight = 0;
};
Mammal::Mammal(int age){
    itsAge = age;
}
int Mammal::GetAge() const {
    return itsAge;
}
void Mammal::SetAge(int x) {
    itsAge = x;
}
int Mammal::GetWeight() const {
    return itsWeight;
}
void Mammal::SetWeight(int a) {
    itsWeight = a;
}
void  Mammal::speak()const {
    cout << "ahhhhh" << endl;
}
void Mammal::sleep()const {
    cout << "shuijiao" << endl;
}
class Dog :public Mammal {
public:
    Dog() = default;
    Dog(int age);
    Dog(int age, int weight);
    Dog(int age, COLOR color);
    Dog(int age, int weight, COLOR color);
    ~Dog() = default;

    COLOR GetColor() const;
    void SetColor(COLOR color);

    void WagTail();
    void BegForFood();

     void speak() const override;
private :
    COLOR itsColor = WHITE;
};

Dog::Dog(int age) : Mammal(age) {

}
Dog::Dog(int age, int weight) : Mammal(age) {
    itsWeight = weight;
}
Dog::Dog(int age, COLOR color) : Mammal(age) {
    itsColor = color;
}
Dog::Dog(int age, int weight, COLOR color) : Mammal(age) {
    itsColor = color;
    itsWeight = weight;
}
COLOR Dog:: GetColor() const {
    return itsColor;
}
void Dog::SetColor(COLOR color) {
    itsColor = color;
}

void Dog::WagTail() {
    cout << "The dog is wagging its tail..." << endl;
}
void Dog::BegForFood() {
    cout << "The dog is begging for food..." << endl;
}

void Dog::speak() const {
    cout << "Dog barks" << endl;
}
int main() {
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.speak();
    Rover.WagTail();

    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;

    Mammal* p = new Dog;
    p->speak();
    delete p;

    return 0;
}