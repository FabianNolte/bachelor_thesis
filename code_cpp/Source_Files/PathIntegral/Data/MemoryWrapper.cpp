#include<PathIntegral/Data/Memory.h>
#include<PathIntegral/Data/MemoryWrapper.h>
#include<vector>
#include<iostream>
using namespace std;

MemoryWrapper::MemoryWrapper() {}

MemoryWrapper::~MemoryWrapper() {
    int i = 0;
    for(auto it = memories.begin(); it != memories.end(); it++){
        delete *it;
        i++;
    }
    memories.clear();
}

void MemoryWrapper::add_memory(Memory* p_memory){
    memories.push_back(p_memory);
}

Memory* MemoryWrapper::operator[](int p_n){
    return memories[p_n];
}

vector<Memory*>* MemoryWrapper::get_memories(void){
    return &memories;
}

int MemoryWrapper::get_num_of_memories(void){
    return memories.size();
}

void MemoryWrapper::delete_memory(int p_n){
    delete memories[p_n];
    memories.erase(memories.begin() + p_n);
}

void MemoryWrapper::print_num_of_memories(void){
    cout << "number of memories straged is; " << memories.size() << endl;
}

void MemoryWrapper::save_allMemories(string p_path){
    int i = 0;
    for(auto it = memories.begin(); it != memories.end(); it++){
        string mem_path = p_path+"/memory"+to_string(i);
        (*it)->save_allGenerations(mem_path);
        i++;
    }
}