#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

class Singleton {
  private:
    static atomic<Singleton*> instance;
    static mutex mtx;
    Singleton() {}
    string name;
    Singleton(string name) {
      cout<<name<<endl;
      this->name=name;
    }
    

  public:
    static Singleton* getInstance(string name) {
      if(instance == NULL)
      {
        lock_guard<mutex> lock(mtx);
        if(instance == NULL)
        {
          instance = new Singleton(name);
        }
      }
      return instance;
    }

};

atomic<Singleton*> Singleton::instance{NULL};
mutex Singleton::mtx;

void gi()
{
  Singleton* s = Singleton::getInstance("pranjal");
  cout<<&s<<endl;
}

void gi1()
{
  Singleton* s = Singleton::getInstance("ishu");
  cout<<&s<<endl;
}

int main() {
  thread t1(gi);
  thread t2(gi1);
  t1.join();
  t2.join();

  return 0;
}