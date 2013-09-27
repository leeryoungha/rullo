#include <gtest/gtest.h>
#include "rullo/Engine.h"

#include "Utils.h"

class Basic : public ::testing::Test {
protected:
    Basic() {}
    virtual ~Basic() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(Basic, Instantiate) {
    CrtCheckMemory memChecker;
    rullo::Engine myRulloEngine;
}

TEST_F(Basic, Instantiate2) {
    CrtCheckMemory memChecker; 
    rullo::Engine myRulloEngine;
    GTEST_ASSERT_EQ(myRulloEngine.id(), 1);
    rullo::Engine myRulloEngine2;
    GTEST_ASSERT_EQ(myRulloEngine2.id(), 2);
}



