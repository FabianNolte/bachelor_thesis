#pragma once

#include<PathIntegral/Data/Memory.h>
#include<string>
#include<vector>
using namespace std;

class MemoryWrapper{
    private:
        vector<Memory*> memories;

    public:
        MemoryWrapper();
        // MemoryWrapper - constructor;

        ~MemoryWrapper();
        // ~MemoryWrapper - destructor
        // deletes all memories straged

        void add_memory(Memory* p_memory);
        // add_memory - adds a new memory to memories
        // @param Memory* p_memory - memory to add

        Memory* operator [] (int p_n);
        // operator [] - getter function for memory with index p_n
        // @param int p_n - index of the memory to get
        // @return Memory* - pointer on desired memory

        vector<Memory*>* get_memories(void);
        // get_memories - getter funtion for memories
        // @return vector<Memory*>* - pointer on the vector of all memories

        int get_num_of_memories(void);
        // get_num_of_memories - returns number of memories storaged
        // @return int - value

        void delete_memory(int p_n);
        // delete_memory - deletes memory with index p_n
        // @param int p_n - index to delete

        void print_num_of_memories(void);
        // print_num_of_memories - prints the amount of starged memories

        void save_allMemories(string p_path);
        // save_allMemories - saves all generations
};