#include <gmock/gmock.h>
#include <iostream>

// returns the twos compliment of the argument
inline int getTwosCompliment(const int &num) { return (~num) + 1; }

int multiply(int a, int b) {
  int sum = 0;
  int count = 0;
  bool is_positive = true;
  if (b < 0) {
    is_positive = false;
    b = getTwosCompliment(b);
  }

  while (b > 0) {
    if (b & 1) {
      sum += (a << count);
    }
    count++;
    b = (b >> 1);
  }
  return (is_positive? sum : getTwosCompliment(sum));
}


TEST(MultiplyInts, PositiveNumbers) {
  EXPECT_EQ(multiply(8 , 7), 56);
  EXPECT_EQ(multiply(53 , 71), 3763);
  EXPECT_EQ(multiply(1740 , 1234186), 2147483640);
}

TEST(MultiplyInts, NegativeNumbers) {
  EXPECT_EQ(multiply(-3 , 9), -27);
  EXPECT_EQ(multiply(3 , -9), -27);
  EXPECT_EQ(multiply(-3 , -9), 27);
  EXPECT_EQ(multiply(-1740 , -1234186), 2147483640);
  EXPECT_EQ(multiply(1740 , -1234186), -2147483640);
  EXPECT_EQ(multiply(-1740 , 1234186), -2147483640);
}

TEST(MultiplyInts, ZeroNumbers) {
  EXPECT_EQ(multiply(0 , -9), 0);
  EXPECT_EQ(multiply(0 , 9), 0);
  EXPECT_EQ(multiply(9 , 0), 0);
  EXPECT_EQ(multiply(0 , 2147483640), 0);
}
