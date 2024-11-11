#include <bits/stdc++.h>

using namespace std;


class IElement {
public:
  virtual void createElement() = 0;
};

class Ifactory {
public:
  virtual IElement* getElement(string type) = 0;
};

class MacButton : public IElement {
public:
  void createElement() {
    cout << "creating MacButton" << endl;
  }
};

class MacCheckbox : public IElement {
public:
  void createElement() {
    cout << "creating MacCheckbox" << endl;
  }
};

class MacFactory : public Ifactory {
public:
  IElement* getElement(string type) {
    if (type == "Button") {
      return new MacButton;
    }
    else if(type == "Checkbox") {
      return new MacCheckbox;
    }
    else return NULL;
  }
};

class WinButton : public IElement {
public:
  void createElement() {
    cout << "creating WinButton" << endl;
  }
};

class WinCheckbox : public IElement {
public:
  void createElement() {
    cout << "creating WinCheckbox" << endl;
  }
};

class WinFactory : public Ifactory {
public:
  IElement* getElement(string type) {
    if (type == "Button") {
      return new WinButton;
    }
    else if(type== "Checkbox") {
      return new WinCheckbox;
    }
    else return NULL; 
  }
};

class GUIFactory {
public:
  static Ifactory* getFactory(string type) {
    if (type == "Mac") {
      return new MacFactory;
    }
    else if(type == "Windows") {
      return new WinFactory;
    }
    else return NULL;
  }
};

int main() {  
  Ifactory* factory = GUIFactory::getFactory("Mac");
  IElement* element = factory->getElement("Button");
  element->createElement();
  Ifactory* factory1 = GUIFactory::getFactory("Windows");
  IElement* element1 = factory1->getElement("Checkbox");
  element1->createElement();
}