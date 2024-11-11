#include <bits/stdc++.h>

using namespace std;

class IPay {
public:
  virtual void pay() = 0;
};

class IAuth {
public:
  virtual void auth() = 0;
};

class CardPay : public IPay {
public:
  void pay() { cout << "CardPay" << endl; }
};

class CashPay : public IPay {
public:
  void pay() { cout << "CashPay" << endl; }
};

class CardAuth : public IAuth {
public:
  void auth() { cout << "CardAuth" << endl; }
};

class PaymentMethod {
private:
  IPay* payMethod;
  IAuth* authMethod;
public:
  void setPayMethod(IPay* payMethod) {
    this->payMethod = payMethod;
  }
  void setAuthMethod(IAuth* authMethod) {
    this->authMethod = authMethod;
  }
  void getAuthMethod() {
    authMethod->auth();
  }
  void getPayMethod() {
    payMethod->pay();
  }
};

class DebitCard : private PaymentMethod {
public:
  DebitCard() {
    setPayMethod(new CardPay());
    setAuthMethod(new CardAuth());
  }

  void pay() {
    getPayMethod();
  }

  void auth() {
    getAuthMethod();
  }

};

class Cash : private PaymentMethod {
public:
  Cash() {
    setPayMethod(new CashPay());
  }

  void pay() {
    getPayMethod();
  }
};


int main() {  
  Cash* payment = new Cash();
  payment->pay();
  
}