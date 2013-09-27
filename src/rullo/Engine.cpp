#include "rullo/Engine.h"
#include "rullo/Fact.h"

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

unsigned Engine::addRule(const std::string& iFileName) {
    return 0;
}

void Engine::addFact(const std::string& iFileName) {
    facts_.insert(boost::shared_ptr<Fact>(new Fact()));    
}