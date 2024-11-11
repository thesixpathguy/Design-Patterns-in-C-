#include <bits/stdc++.h>

using namespace std;

class Observer {
  public:
    virtual void update() = 0;
};

class Subject {
  public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherStation : public Subject {
  private:
    int temperature;
    int humidity;
    vector<Observer*> observers;

  public:
    WeatherStation() {
      temperature = 0;
      humidity = 0;
      observers = vector<Observer*>();
    }

    void setTemperature(int temperature) {
      this->temperature = temperature;
      notifyObservers();
    }

    void setHumidity(int humidity) {
      this->humidity = humidity;
      notifyObservers();
    }

    int gethumidity() {
      return humidity;
    } 

    int getTemperature() {
      return temperature;
    }

    void addObserver(Observer *observer) {
      if (find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
      }
    }

    void removeObserver(Observer *observer) {
      if (find(observers.begin(), observers.end(), observer) != observers.end()) {
        observers.erase(find(observers.begin(), observers.end(), observer));
      }
    }

    /*
      For pushing method, the Subject class should be able to push the data to all the 
      observers. But can lead to redundancy due to unwanted variables.
    */
    /*
      Below is polling method, the obeserver will poll the required data from the weather 
      station. But manual getting need to be done at Observer class.
    */
    void notifyObservers() {
      for (Observer *observer : observers) {
        observer->update();
      }
    }
};

class CurrentWeatherDisplay : public Observer {
  private:
    WeatherStation *weatherStation;
    int temperature;
    int humidity;

  public:
    CurrentWeatherDisplay(WeatherStation *weatherStation) {
      this->weatherStation = weatherStation;
      this->weatherStation->addObserver(this);
      temperature = 0;
      humidity = 0;
    }

    // Polling method
    void update() {
      temperature = weatherStation->getTemperature();
      humidity = weatherStation->gethumidity();
      cout << temperature << " " << humidity << endl;
    }

    void removeObserver() {
      weatherStation->removeObserver(this);
    }
};


int main() {
  WeatherStation *weatherStation = new WeatherStation();
  CurrentWeatherDisplay *currentWeatherDisplay = new CurrentWeatherDisplay(weatherStation);
  weatherStation->setTemperature(45);
  weatherStation->setHumidity(21);
  currentWeatherDisplay->removeObserver();
  weatherStation->setTemperature(15);
    return 0;
}