#include "gtest/gtest.h"

extern "C" {
    #include "app/metainformation.h"
}

/**
 * @brief Application test fixture
 */
class Application : public testing::Test {
protected:
    /**
     * @brief Resets the application
     */
    void SetUp() override {
        
    }
};

TEST_F(Application, CallSetup) {

}

TEST_F(Application, CallLoop) {

}
