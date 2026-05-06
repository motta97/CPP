#include<iostream>
#include<vector>
#include "classes.h"
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
void deallocate_from_memory(int* memory, int pid, int mem_size) {
    for (int i = 0; i < mem_size; i++) {
        if (memory[i] == pid) {
            memory[i] = -1;
        }
    }
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

        else if (memory[i] != -1 && !first || i == mem_size - 1)//to accomodate for reaching the end of the memory
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

int best_fit(process p, int* memory, vector<hole>& holes, int mem_size) {
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
            deallocate_from_memory(memory, p.process_id, mem_size);
            fill_up_holes(holes, memory, mem_size);
            return -1;
        }




    }

}
int first_fit(process p, int* memory, vector<hole>& holes, int mem_size) {
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
            deallocate_from_memory(memory, p.process_id, mem_size);
            fill_up_holes(holes, memory, mem_size);
            return -1;
        }
    }
    return 1;

}


void allocation(process p, int* memory, string allocation_technique, vector<hole>& holes, int mem_size) {
    if (allocation_technique == "FirstFit") {
        //call first fit algorithm
        if (first_fit(p, memory, holes, mem_size)) {
            cout << "Allocation Succesfull!";
        }
        else cout << "Sorry We can't allocate this process, please try again:(";
    }
    else if (allocation_technique == "BestFit") {
        //call the best fit algorithm
        if (best_fit(p, memory, holes, mem_size))
            cout << "Allocation Successful";
        else cout << "Sorry We can't allocate this process, please try again:(";
    }
}

int main() {
    //variables declaration
    int mem_size;
    int num_holes;
    vector<hole> holes;
    vector<process> processes;
    int start_address, size;
    int num_processes;
    int  num_segments;
    string allocation_technique;


    //getting memory size
    
    do {
        cout << "Enter memory Size: ";
        cin >> mem_size;
        if (mem_size <= 0)cout << "Please enter a positive number" << endl;
    } while (mem_size <= 0);
    
    int* memory = new int[mem_size]();

    //take number of holes
    do {
        cout << "Enter number of holes: ";
        cin >> num_holes;
        if (num_holes <= 0)cout << "Please enter a positive number" << endl;
    } while (num_holes <= 0);
    
    for (int i = 0; i < num_holes; i++) {
        hole h1;

        do {
            cout << "Enter the hole starting address: ";
            cin >> start_address;
            if (start_address < 0)cout << "Please enter a positive number" << endl;
        } while (start_address <0);
        
        do {
            cout << "Enter the size: ";
            cin >> size;
            if (size <= 0)cout << "Please enter a positive number" << endl;
        } while (size <= 0);


        
        h1.start_address = start_address;
        h1.size = size;

        holes.push_back(h1);
    }
    insert_holes(memory, holes, num_holes, mem_size);

    //taking processes
    do {
        cout << "Enter number of processes to add: ";
        cin >> num_processes;
        if (num_processes <= 0)cout << "Please enter a positive number" << endl;
    } while (num_processes <= 0);
  
    
    for (int i = 0; i < num_processes; i++) {
        process p1;
        do {
            cout << "Enter the process ID: ";
            cin >> p1.process_id;
            if (p1.process_id <= 0)cout << "Please enter a positive number" << endl;
        } while (p1.process_id <= 0);

        do {
            cout << "Enter number of the segments for the Process with id " << p1.process_id << ": ";
            cin >> num_segments;
            if (num_segments <= 0)cout << "Please enter a positive number" << endl;
        } while (num_segments <= 0);

        for (int j = 0; j < num_segments; j++) {
            segment s1;
            cout << "Enter the segment name: ";
            cin >> s1.name;

            do {
                cout << "Enter the segment size: ";
                cin >> s1.size;
                if (s1.size <= 0)cout << "Please enter a positive number" << endl;
            } while (s1.size <= 0);


            p1.segments.push_back(s1);
        }
        processes.push_back(p1);
        do {
            cout << "Enter which method to use (FirstFit or BestFit): ";
            cin >> allocation_technique;
            if (allocation_technique == "FirstFit" || allocation_technique == "BestFit")
                break;
            else
                cout << "Please choose either FirstFit or BestFit"<<endl;
        } while (allocation_technique != "FirstFit" || allocation_technique != "BestFit");

        allocation(p1, memory, allocation_technique, holes, mem_size);
    }
    for (int i = 0; i < mem_size; i++) {
        cout << memory[i] << " ";
    }



}