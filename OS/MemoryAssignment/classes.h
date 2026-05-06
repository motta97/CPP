#pragma once
#include<string>
using namespace std;
class hole {
public:
    int start_address;
    int size;
};
class segment {
public:
    string name;
    int size;


};
class process {
public:
    int process_id;
    int num_segments;
    vector<segment> segments;

};
class memory{
    public:
    int size;
    int memory_array[size];
}