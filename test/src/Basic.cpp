#include "rullo/Engine.h"

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "Utils.h"


BOOST_AUTO_TEST_CASE(Instantiate)
{
    CrtCheckMemory memChecker;
    {
        rullo::Engine myRulloEngine;
    }
}

BOOST_AUTO_TEST_CASE(Instantiate2) {
    CrtCheckMemory memChecker; 
    rullo::Engine myRulloEngine;
    BOOST_CHECK(myRulloEngine.id() != 0);
    rullo::Engine myRulloEngine2;
    BOOST_CHECK(myRulloEngine2.id() != 0);
}

BOOST_AUTO_TEST_CASE(AssertFact) {
    CrtCheckMemory memChecker; 
    rullo::Engine myRulloEngine;
    myRulloEngine.addFact();
}
