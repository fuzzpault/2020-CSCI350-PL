/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Math Parser HW
   
   https://github.com/google/googletest
*/

#include "gtest/gtest.h"
#include "Parser.h"

TEST(parse, 0){
  Parser s;
  EXPECT_EQ( s.parse(""), false);
}
TEST(nodeCount, 0){
  Parser s;
  EXPECT_EQ( s.nodeCount(), 0);
}




TEST(parse, 1){
  Parser s;
  EXPECT_EQ( s.parse("5"), true);
}
TEST(nodeCount, 1){
  Parser s;
  s.parse("5");
  EXPECT_EQ( s.nodeCount(), 1);
}


TEST(parse, 2){
  Parser s;
  EXPECT_EQ( s.parse("()"), false);
}
TEST(nodeCount, 2){
  Parser s;
  s.parse("()");
  EXPECT_EQ( s.nodeCount(), 0);
}


TEST(parse, 3){
  Parser s;
  EXPECT_EQ( s.parse("(5)"), true);
}
TEST(nodeCount, 3){
  Parser s;
  s.parse("(5)");
  EXPECT_EQ( s.nodeCount(), 1);
}


TEST(parse, 4){
  Parser s;
  EXPECT_EQ( s.parse("(g)"), false);
}
TEST(nodeCount, 4){
  Parser s;
  s.parse("(g)");
  EXPECT_EQ( s.nodeCount(), 0);
}


TEST(parse, 5){
  Parser s;
  EXPECT_EQ( s.parse("5 + 8"), true);
}
TEST(nodeCount, 5){
  Parser s;
  s.parse("5 + 8");
  EXPECT_EQ( s.nodeCount(), 3);
}


TEST(parse, 6){
  Parser s;
  EXPECT_EQ( s.parse("5 + 8 - 2"), true);
}
TEST(nodeCount, 6){
  Parser s;
  s.parse("5 + 8 - 2");
  EXPECT_EQ( s.nodeCount(), 5);
}


TEST(parse, 7){
  Parser s;
  EXPECT_EQ( s.parse("  (5 + 8) - (2 + 1)"), true);
}
TEST(nodeCount, 7){
  Parser s;
  s.parse("  (5 + 8) - (2 + 1)");
  EXPECT_EQ( s.nodeCount(), 7);
}


TEST(parse, 8){
  Parser s;
  EXPECT_EQ( s.parse("5 9 - 3"), false);
}
TEST(nodeCount, 8){
  Parser s;
  s.parse("5 9 - 3");
  EXPECT_EQ( s.nodeCount(), 0);
}


TEST(parse, 9){
  Parser s;
  EXPECT_EQ( s.parse("(3 + )"), false);
}
TEST(nodeCount, 9){
  Parser s;
  s.parse("(3 + )");
  EXPECT_EQ( s.nodeCount(), 0);
}

TEST(parse, 10){
  Parser s;
  EXPECT_EQ( s.parse("(3 + )"), false);
  EXPECT_EQ( s.parse("(3 + 4)"), true);
}
TEST(nodeCount, 10){
  Parser s;
  s.parse("(3 + )");
  EXPECT_EQ( s.nodeCount(), 0);
  s.parse("(3 + 4)");
  EXPECT_EQ( s.nodeCount(), 3);
}

TEST(parse, 11){
  Parser s;
  EXPECT_EQ( s.parse("(3 + 2) - 458 "), true);
}
TEST(nodeCount, 11){
  Parser s;
  s.parse("(3 + 2) - 458 ");
  EXPECT_EQ( s.nodeCount(), 5);
}

TEST(parse, 12){
  Parser s;
  EXPECT_EQ( s.parse("(56.8) "), false);
}
TEST(nodeCount, 12){
  Parser s;
  s.parse("(56.8) ");
  EXPECT_EQ( s.nodeCount(), 0);
}
