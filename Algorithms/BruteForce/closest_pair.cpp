#include<iostream>
using namespace  std;
void closest_pair(float points[][2],int SIZE,int indices[] ){
int min = find_distance(points[0],points[1]);
int distance;
for(int i=0;i<SIZE;i++){
    for(int j=i+1;j<SIZE;j++){
        distance=find_distance(points[i],points[j]);
        if(distance<min){
            min=distance;
           indices[0] =i;
            indices[1]=j;
        }
    }
}



}
float find_distance(float point1[],float point2[]){
    return sqrt(square(point1[0]-point2[0])+square(point1[1]-point2[1]));
}
float square(int x){
    return x*x;
}


int main() {
    float arr[3][2]= {{1,1},{2,1},{-1,1}};
    int indices[2]={-1,-1};
    closest_pair(arr,3,indices);
    cout<<"Indices are: "<<indices[0]<<endl<<indices[1]<<endl;

}