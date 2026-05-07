#pragma once
#include <string>
#include <vector>
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
    std::vector<int> memory_array;
};