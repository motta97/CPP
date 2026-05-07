#include<iostream>
#include<vector>
#include "classes.h"
#include <climits>
using namespace std;

void insert_holes(int* memory, vector<hole>& holes, int num_holes, int mem_size) {
    for (int i = 0; i < num_holes; i++) {
        for (int j = holes[i].start_address; j < holes[i].size + holes[i].start_address; j++) {
            if (j < mem_size) {
                memory[j] = -1;//assuming -1 means it's empty
            }
            else {
                holes[i].size--;
            }
        }
    }
}
void allocate_to_memory(int* memory, int pid, int start_address, int size) {
    for (int i = start_address; i < (start_address + size); i++) {
        memory[i] = pid;
    }
}
void change_hole_value(hole& h, int new_start_address, int new_size) {
    h.start_address = new_start_address;
    h.size = new_size;
}
void remove_a_process(vector<process>& processes, int process_id) {
    int index;
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].process_id == process_id)index = i;
    }
    if (index < processes.size()) {
        processes.erase(processes.begin() + index);
    }
}
void deallocate_from_memory(int* memory, int pid, int mem_size, vector<process>& processes) {

    for (int i = 0; i < mem_size; i++) {
        if (memory[i] == pid) {
            memory[i] = -1;
        }
    }
    remove_a_process(processes,  pid);

}
void fill_up_holes(vector<hole>& holes, int* memory, int mem_size) {
    holes.clear();
    int count = 0;
    int start_address = 0;
    bool first = true;
    for (int i = 0; i < mem_size; i++) {
        if (memory[i] == -1) {
            if (first) {
                count = 1;
                start_address = i;
                first = false;
            }
            else {
                count++;
            }
        }

        else if ((memory[i] != -1 && !first) || i == mem_size - 1)//to accomodate for reaching the end of the memory
        {
            hole h1;
            h1.size = count;
            h1.start_address = start_address;
            holes.push_back(h1);
            first = true;
            count = 0;
        }

    }


}

int best_fit(process p, int* memory, vector<hole>& holes, int mem_size, vector<process>& processes) {
    //find the min of (hole size - segment size)
    bool can_allocate = false;
    int best_fit_hole_index;
    int min = INT_MAX;
    int difference;
    for (int i = 0; i < p.segments.size(); i++) {
        best_fit_hole_index = -1;
        min = INT_MAX;
        fill_up_holes(holes, memory, mem_size);
        for (int j = 0; j < holes.size(); j++) {
            difference = holes[j].size - p.segments[i].size;
            if (difference < min && difference >= 0) {
                best_fit_hole_index = j;
                min = difference;
                can_allocate = true;
            }


        }
        if (can_allocate) {
            allocate_to_memory(memory, p.process_id, holes[best_fit_hole_index].start_address, p.segments[i].size);
            can_allocate = false;
        }
        else {
            //deallocate everything for this process and returns an error
            deallocate_from_memory(memory, p.process_id, mem_size,processes);
            fill_up_holes(holes, memory, mem_size);
            return false;
        }




    }
    return true;

}
bool first_fit(process p, int* memory, vector<hole>& holes, int mem_size,vector<process>&processes) {
    bool can_allocate = false;

    for (int i = 0; i < p.segments.size(); i++) {
        fill_up_holes(holes, memory, mem_size);
        for (int j = 0; j < holes.size(); j++) {
            if (holes[j].size >= p.segments[i].size) {

                allocate_to_memory(memory, p.process_id, holes[j].start_address, p.segments[i].size);
                can_allocate = true;
                break;


            }

        }
        if (can_allocate) {//we've found a place for the segment
            can_allocate = false;
        }
        else {
            //deallocate everything for this process and returns an error
            deallocate_from_memory(memory, p.process_id, mem_size, processes);
            fill_up_holes(holes, memory, mem_size);
            return false;
        }
    }
    return true;

}


bool allocation(process p, int* memory, string allocation_technique, vector<hole>& holes, int mem_size,vector<process>&processes) {
    if (allocation_technique == "FirstFit") {
        //call first fit algorithm
        if (first_fit(p, memory, holes, mem_size,processes)) {
            return true;
        }
        else return false;
    }
    else if (allocation_technique == "BestFit") {
        //call the best fit algorithm
        if (best_fit(p, memory, holes, mem_size,processes))
            return true;
        else return false;
    }
    return false;
}
