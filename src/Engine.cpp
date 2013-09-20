#include "rullo/Engine.h"

using namespace rullo;

unsigned Engine::CurrentId = 0;

unsigned Engine::GetId() {
    ++Engine::CurrentId;
    return Engine::CurrentId;
}

Engine::Engine(): 
    id_(Engine::GetId()) {
}

Engine::~Engine() {
}

void Engine::importRule(const std::string& iFileName) {
    
}
