#include <iostream> 
#include <string> 
#include<vector>
#include<cmath>
using namespace std;
class complex{
    private:
    float real;
    float imaginary;
    float magnitude;
    public:
    complex(){
        real=0;
        imaginary=0;
        magnitude=0;
    }
    complex(int x,int y){
        real =x;
        imaginary=y;
    }
    void read(){
        cout<<"Enter the real part: ";
        cin>>real;
        cout<<"Enter the imaginary part: ";
        cin>>imaginary;
    }
    void print(){
        cout<<"The real Part is: "<<real<<endl;
        cout<<"The imaginary part is: "<<imaginary<<endl;
    }
    void set_real(int r){
        real=r;
    }
    void set_imag(int i){
        imaginary=i;
    }
    void set_mag(){
        magnitude=sqrt(pow(real,2)+pow(imaginary,2));
    }
    float get_mag(){
        return magnitude;
    }
    float get_real(){
        return real;
    }
    float get_imag(){
        return imaginary;
    }
    
};
float max_mag( complex arr[]){
    float m=arr[0].get_mag();
    for(int i=1;i<10;i++){
        if(arr[i].get_mag()>=m)m=arr[i].get_mag();
    }
    return m;
}
complex add_two(complex a,complex b);
int main(){
    complex arr[10];//to make things simpler (it should be 100 but I am going to change it at the end of the test)
    for(int i=0;i<5;i++){
        arr[i].read();
        arr[i].set_mag();
    }
  float max=  max_mag(arr);
    cout<<max<<endl;
    complex x1,x2;
    cout<<"Enter 2 complex nums and I will try to calculate them inashallah \n";
    x1.read();
    x2.read();
    complex sum=add_two(x1,x2);
    sum.print();
}complex add_two(complex a,complex b){
    complex sum;
    sum.set_real(a.get_real()+b.get_real());
    sum.set_imag(a.get_imag()+b.get_imag());
    return sum;
}
