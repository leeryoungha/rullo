#include "rullo/Engine.h"
#include "rullo/Fact.h"

#include <boost/property_tree/json_parser.hpp>

extern "C" {
#include "clips.h"
}

using namespace rullo;

unsigned Engine::CurrentId = 0;

unsigned Engine::GetId() {
    ++Engine::CurrentId;
    return Engine::CurrentId;
}

Engine::Engine(): 
    id_(Engine::GetId()), 
    clipsEnv_(static_cast<void*>(0)) {
        clipsEnv_ = CreateEnvironment();
}

Engine::~Engine() {
    DestroyEnvironment(clipsEnv_);
    clipsEnv_ = static_cast<void*>(0);
}

unsigned Engine::addRule(const std::string& iFileName) {
    return 0;
}

void Engine::addFact() {
    
    // facts_.insert(boost::shared_ptr<Fact>(new Fact()));    
    void *newFact;
    void *templatePtr;
    void *theMultifield;
    DATA_OBJECT theValue;
    IncrementGCLocks();
    templatePtr = FindDeftemplate("example");
    newFact = CreateFact(templatePtr);
    if (newFact == NULL) return;

    /*==============================*/
    /* Set the value of the x slot. */
    /*==============================*/
    theValue.type = INTEGER;
    theValue.value = AddLong(3);
    PutFactSlot(newFact,"x",&theValue);
    theValue.type = SYMBOL;
    theValue.value = AddSymbol("red");
    PutFactSlot(newFact,"y",&theValue);

    /*==============================*/
    /* Set the value of the z slot. */
    /*==============================*/
    theMultifield = CreateMultifield(2);
    SetMFType(theMultifield,1,FLOAT);
    SetMFValue(theMultifield,1,AddDouble(1.5));
    SetMFType(theMultifield,2,SYMBOL);
    SetMFValue(theMultifield,2,AddSymbol("b"));
    SetDOBegin(theValue,1);
    SetDOEnd(theValue,2);
    theValue.type = MULTIFIELD;
    theValue.value = theMultifield;
    PutFactSlot(newFact,"z",&theValue);
    /*=================================*/
    /* Assign default values since all */
    /* slots were not initialized. */
    /*=================================*/
    AssignFactSlotDefaults(newFact);
    /*==========================================================*/
    /* Enable garbage collection. Each call to IncrementGCLocks */
    /* should have a corresponding call to DecrementGCLocks. */
    /*==========================================================*/
    DecrementGCLocks();
    /*==================*/
    /* Assert the fact. */
    /*==================*/
    Assert(newFact);


}