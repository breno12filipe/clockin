#include "src/date.h"
#include <memory>
#include <gtest/gtest.h>

TEST(dateTests, GIVEN_CORRECT_ARRAY_OF_NUMBERS_THEN_SHOULD_RETURN_CORRECT_PAIR) {
    std::unique_ptr<Date> date0(new Date());
    std::vector<float> correctVectorNumbers = {9.0, 12.0, 13.0, 18.0};
    
    std::pair result = date0->calculateNumbers(correctVectorNumbers);

    EXPECT_EQ(result.first, 8);
    EXPECT_EQ(result.second, 0);
}

