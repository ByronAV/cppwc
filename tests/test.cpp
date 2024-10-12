#include <gtest/gtest.h>

#include <WordCount.hpp>

TEST(CPPWC_Test, GetBytesTest) {
  auto count = std::make_unique<WordCount>("../tests/test.txt");
  auto result = count->GetBytes();
  EXPECT_EQ(result, 342190);
}

TEST(CPPWC_Test, GetLineTest) {
  auto count = std::make_unique<WordCount>("../tests/test.txt");
  auto result = count->GetLines();
  EXPECT_EQ(result, 7145);
}

TEST(CPPWC_Test, GetWordsTest) {
  auto count = std::make_unique<WordCount>("../tests/test.txt");
  auto result = count->GetWords();
  EXPECT_EQ(result, 58164);
}

TEST(CPPWC_Test, GetCharsTest) {
  auto count = std::make_unique<WordCount>("../tests/test.txt");
  auto result = count->GetChars();
  EXPECT_EQ(result, 339292);
}