#include<iostream>
using namespace std;

class country {
  string name;
  int pop;
  float area;
  public:
  country();
  void read();
    string get_name();
    int get_pop();
     float get_area();
};
int main () {
    country max_of_area,max_of_pop,max_of_den;
    country c;
    for(int i=0;i<4;i++){
        c.read();
        if(c.get_area()>max_of_area.get_area())max_of_area=c;
        if(c.get_pop()>max_of_pop.get_pop())max_of_pop=c;
    if((c.get_pop()/c.get_area())>(max_of_den.get_pop()/max_of_den.get_area()))max_of_den=c;
        
        
    }
    cout<<"The country with the largest population is: "<<max_of_pop.get_name()<<endl;
        cout<<"The country with the largest area is: "<<max_of_area.get_name()<<endl;
        cout<<"The country with the largest population density  is: "<<max_of_den.get_name()<<endl;
        
    
    
    
}
country::country(){
      name="";
      pop=1;
      area=1;
      
  }
  void  country::  read(){
      cout<<"Enter the country name: ";
      cin>>name;
         cout<<"Enter the country population: ";
      cin>>pop;
         cout<<"Enter the country area: ";
      cin>>area;
  }
  string country:: get_name(){
     return name;
 }
 int country:: get_pop(){
     return pop;
 }
 float country:: get_area(){
     return area;
    }
