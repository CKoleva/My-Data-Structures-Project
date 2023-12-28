#include "engine.h"

Engine::Engine() : association(Association::getInstance()) {}

Engine& Engine::getInstance() 
{
    static Engine instance;
    
    return instance;
}