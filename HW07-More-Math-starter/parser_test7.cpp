/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for HW7
   
   https://github.com/google/googletest
   https://docs.google.com/document/d/11rKKX-2iQ45g9CDKHpUtyyOBxRslrBWICXt2sNnff_U/edit
*/

#include "gtest/gtest.h"
#include "Parser.h"

TEST(PART1_parse, 0){
  Parser s;
  EXPECT_EQ( s.parse(""), false);
}
TEST(PART1_nodeCount, 0){
  Parser s;
  EXPECT_EQ( s.nodeCount(), 0);
}




TEST(PART1_parse, 1){
  Parser s;
  EXPECT_EQ( s.parse(" 5 - 102"), true);
}
TEST(PART1_nodeCount, 1){
  Parser s;
  s.parse(" 5 - 102");
  EXPECT_EQ( s.nodeCount(), 3);
}


TEST(PART1_parse, 2){
  Parser s;
  EXPECT_EQ( s.parse(" 5 - 102 * 6"), true);
}
TEST(PART1_nodeCount, 2){
  Parser s;
  s.parse(" 5 - 102 * 6");
  EXPECT_EQ( s.nodeCount(), 5);
}


TEST(PART1_parse, 3){
  Parser s;
  EXPECT_EQ( s.parse(" 5 - 102 * "), false);
}
TEST(PART1_nodeCount, 3){
  Parser s;
  s.parse(" 5 - 102 * ");
  EXPECT_EQ( s.nodeCount(), 0);
}


TEST(PART1_parse, 4){
  Parser s;
  EXPECT_EQ( s.parse(" (1 *3) + (102 / 3) "), true);
}
TEST(PART1_nodeCount, 4){
  Parser s;
  s.parse(" (1 *3) + (102 / 3) ");
  EXPECT_EQ( s.nodeCount(), 7);
}


TEST(PART1_parse, 5){
  Parser s;
  EXPECT_EQ( s.parse(" (1- *3) + (102 / 3) "), false);
}
TEST(PART1_nodeCount, 5){
  Parser s;
  s.parse(" (1- *3) + (102 / 3) ");
  EXPECT_EQ( s.nodeCount(), 0);
}

TEST(PART1_parse, 6){
  Parser s;
  EXPECT_EQ( s.parse(" (((25 * 1034) / 9) * 2) - 5 "), true);
}
TEST(PART1_nodeCount, 6){
  Parser s;
  s.parse(" (((25 * 1034) / 9) * 2) - 5 ");
  EXPECT_EQ( s.nodeCount(), 9);
}

/* ------------------------------------------------ */
TEST(PART2_eval, 0){
  Parser s;
  s.parse(" 5");
  EXPECT_EQ( s.eval(), 5);
}

TEST(PART2_eval, 1){
  Parser s;
  s.parse(" 5 + 6");
  EXPECT_EQ( s.eval(), 11);
  s.parse(" 5 + 6 - 1");
  EXPECT_EQ( s.eval(), 10);
}

TEST(PART2_eval, 2){
  Parser s;
  s.parse(" 10 * 2 - 1");
  EXPECT_EQ( s.eval(), 19);
}

TEST(PART2_eval, 3){
  Parser s;
  s.parse(" (3 + 5) * 2 / 4");
  EXPECT_EQ( s.eval(), 4);
}

TEST(PART2_eval, 4){
  Parser s;
  s.parse(" 1 + 5 * 7 - 3 * 9 + (34)");
  EXPECT_EQ( s.eval(), 43);
}

TEST(PART2_eval, 5){
  Parser s;
  s.parse(" 9 / 2");
  EXPECT_EQ( s.eval(), 4);
}

TEST(PART2_eval, 6){
  Parser s;
  s.parse("");
  EXPECT_EQ( s.eval(), 0);
}

TEST(PART2_eval, 7){
  Parser s;
  EXPECT_EQ( s.eval(), 0);
}

TEST(PART2_eval, 8){
  Parser s;
  s.parse("(1 + (3 * 2)) * (8-2)");
  EXPECT_EQ( s.eval(), 42);
}




