#include <bits/stdc++.h>

using namespace std;

// JSON
class AnalyticsTool {
private:
  string jsonData;
public:
  AnalyticsTool() {}
  AnalyticsTool(string jsonData) {
    this->jsonData = jsonData;
  }
  virtual void analyseData() {
    cout << "Analysing JSON data: " << this->jsonData << endl;
  }
  void setJsonData(string jsonData) {
    this->jsonData = jsonData;
  }
};

// XML
class AnalyticsToolXML {
private:
  string xmlData;
public:
  AnalyticsToolXML(string xmlData) {
    this->xmlData = xmlData;
  }
  void analyseData() {
    cout << "Analysing XML data: " << this->xmlData << endl;
  }
  void setJsonData(string xmlData) {
    this->xmlData = xmlData;
  }
};

// Client which natively supports JSON
class Client {
private:
  AnalyticsTool *analyticsTool;
public:
  Client(AnalyticsTool *analyticsTool) {
    this->analyticsTool = analyticsTool;
  }
  void analyse() {
    analyticsTool->analyseData();
  }
};

class AnalyticsToolAdapter : public AnalyticsTool {
private:
  AnalyticsToolXML *analyticsToolXML;
public:
  AnalyticsToolAdapter(AnalyticsToolXML *analyticsToolXML) {
    this->analyticsToolXML = analyticsToolXML;
  }
  void analyseData() override {
    analyticsToolXML->analyseData();
  }
};

int main() {  
  Client *client = new Client(new AnalyticsTool("jsonData"));
  client->analyse();
  Client *client1 = new Client(new AnalyticsToolAdapter(new AnalyticsToolXML("xmlData")));
  client1->analyse();
}