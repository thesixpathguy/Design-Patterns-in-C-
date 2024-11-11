#include <bits/stdc++.h>

using namespace std;

class Burger {
public:
  virtual void getDesc() = 0;
  virtual int getCost() = 0;
};

class Zinger : public Burger {
public:
  void getDesc() { cout << "Zinger Burger" << endl; }
  int getCost() { return 2; }
};

class BurgerDecorator : public Burger {
public:
  virtual void smell() = 0;
};

class BurgerWithCheese : public BurgerDecorator {
private:
  Burger *burger;
public:
  BurgerWithCheese(Burger *burger) { this->burger = burger; }
  void getDesc() {
    burger->getDesc();
    cout << " with cheese" << endl;
  }
  int getCost() {
    return burger->getCost() + 1;
  }
  void smell() {
    cout << "smelling" << endl;
  }
};


int main() {  
  Burger *burger = new Zinger();
  burger = new BurgerWithCheese(burger);
}