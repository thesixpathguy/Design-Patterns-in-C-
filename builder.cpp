#include <bits/stdc++.h>

using namespace std;

class Dog {

private:

  string name;
  int age;
  string gender;

public:

  class DogBuilder {

  private:

    string name;
    int age;
    string gender;

  public:

    DogBuilder& setName(string name) {
      this->name=name;
      return *this;
    }

    DogBuilder& setAge(int age) {
      this->age=age;
      return *this;
    }

    DogBuilder& setGender(string gender) {
      this->gender=gender;
      return *this;
    }

    string getName() const {
      return this->name;
    }

    int getAge() const {
      return this->age;
    }

    string getGender() const {
      return this->gender;
    }

    Dog* build() {
      return new Dog(this);
    }
  };

private:

  Dog(Dog::DogBuilder* builder) {
    this->name = builder->getName();
    this->age = builder->getAge();
    this->gender = builder->getGender();
  }

};





int main() {
  
  Dog* d = Dog::DogBuilder().setName("Tom").setAge(5).build();
  return 0;
}