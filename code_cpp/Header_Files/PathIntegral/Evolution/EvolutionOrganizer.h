#pragma once

#include <PathIntegral/Data/Setting.h>
#include <PathIntegral/Data/MemoryWrapper.h>
#include <PathIntegral/Evolution/EvolutionExecuter.h>
#include <PathIntegral/Evolution/ExecuterSetting.h>


class EvolutionOrganizer {
    private:
        MemoryWrapper* memoryWrapper;
        ExecuterSetting* executerSetting;
        Setting* setting;

    public:
        EvolutionOrganizer(MemoryWrapper& p_memoryWrapper, Generation* p_generation0, Setting& p_setting, ExecuterSetting& p_executerSetting);
        // EvolutionOrganizer - constructor
        // @param MemoryWrapper& p_memoryWrapper - memory wrapper to fill up
        // @param Generation* p_generation0 - generation to start all evolutions at 
        // @param Setting& p_setting - general settings
        // @param ExecuterSetting& p_executerSetting - settings for the evoultion executer

        void run_allEvolutions(void);
        // run_allEvolutions - calls the evolution executer for all memories
};