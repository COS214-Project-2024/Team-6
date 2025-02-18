#include <gtest/gtest.h>

#include "../LowCitizenCreator.h"
#include "../MiddleCitizenCreator.h"
#include "../HighCitizenCreator.h"
#include "../MayorCreator.h"
#include "../LowCitizen.h"
#include "../MiddleCitizen.h"
#include "../HighCitizen.h"
#include "../Mayor.h"

TEST(CreatorTest, BasicLowCitizenCreation)
{
    LowCitizenCreator low;
    Citizen *citizen = low.basicCitizenOperation();

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<LowCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, SpecificLowCitizenCreation)
{
    LowCitizenCreator low;
    Citizen* citizen = low.specificCitizenOperation("employed", 85, nullptr);

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<LowCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, BasicMiddleCitizenCreation)
{
    MiddleCitizenCreator mid;
    Citizen* citizen = mid.basicCitizenOperation();

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<MiddleCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, SpecificMiddleCitizenCreation)
{
    MiddleCitizenCreator mid;
    Citizen *citizen = mid.specificCitizenOperation("self-employed", 75, nullptr);

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<MiddleCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, BasicHighCitizenCreation)
{
    HighCitizenCreator high;
    Citizen *citizen = high.basicCitizenOperation();

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<HighCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, SpecificHighCitizenCreation)
{
    HighCitizenCreator high;
    Citizen *citizen = high.specificCitizenOperation("umemployed", 65, nullptr);

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<HighCitizen*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, BasicMayorCreation)
{
    MayorCreator mc;
    Citizen *citizen = mc.basicCitizenOperation();

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<Mayor*>(citizen) != nullptr);

    delete citizen;
}
TEST(CreatorTest, SpecificMayorCreation)
{
    MayorCreator mc;
    Citizen *citizen = mc.specificCitizenOperation("employed", 50, nullptr, "Test mayor");

    ASSERT_NE(citizen, nullptr);
    ASSERT_TRUE(dynamic_cast<Mayor*>(citizen) != nullptr);

    delete citizen;
}
