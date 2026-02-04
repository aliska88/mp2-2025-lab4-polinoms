#include <gtest.h>
#include "polynomial.h"

TEST(PolynomialTest, CreateEmpty) {
  Polynomial p;
  EXPECT_TRUE(p.isEmpty());
  EXPECT_EQ(p.size(), 0);
}

TEST(PolynomialTest, InsertAndSize) {
  Polynomial p;
  p.insert(5.0, 1, 2, 3);
  EXPECT_FALSE(p.isEmpty());
  EXPECT_EQ(p.size(), 1);
}

TEST(PolynomialTest, AdditionAndSimplification) {
  Polynomial p1, p2;
  p1.insert(2.0, 1, 1, 1);
  p2.insert(3.0, 1, 1, 1);

  Polynomial sum = p1 + p2;
  EXPECT_EQ(sum.size(), 1);

  Polynomial expected;
  expected.insert(5.0, 1, 1, 1);
  EXPECT_TRUE(sum == expected);
}

TEST(PolynomialTest, SubtractionToZero) {
  Polynomial p1, p2;
  p1.insert(10.0, 2, 0, 0);
  p2.insert(10.0, 2, 0, 0);

  Polynomial diff = p1 - p2;
  EXPECT_TRUE(diff.isEmpty());
}

TEST(PolynomialTest, Multiplication) {
  Polynomial p1, p2;
  p1.insert(2.0, 1, 0, 0);
  p2.insert(3.0, 0, 1, 0);

  Polynomial res = p1 * p2;
  Polynomial expected;
  expected.insert(6.0, 1, 1, 0);

  EXPECT_TRUE(res == expected);
}

TEST(PolynomialTest, ScalarMultiplication) {
  Polynomial p;
  p.insert(2.0, 1, 1, 1);

  Polynomial res = p * 4.0;
  Polynomial expected;
  expected.insert(8.0, 1, 1, 1);

  EXPECT_TRUE(res == expected);
}

TEST(PolynomialTest, DegreeOverflowException) {
  Polynomial p1, p2;
  p1.insert(1.0, 6, 0, 0);
  p2.insert(1.0, 5, 0, 0);

  EXPECT_THROW(p1 * p2, std::overflow_error);
}

TEST(PolynomialTest, SortingOrder) {
  Polynomial p;
  p.insert(1.0, 0, 0, 1);
  p.insert(1.0, 1, 0, 0);

  EXPECT_EQ(p.toString().find("x"), 0);
}
