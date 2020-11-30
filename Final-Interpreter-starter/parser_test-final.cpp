/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for HW7
   
   https://github.com/google/googletest
   https://docs.google.com/document/d/11rKKX-2iQ45g9CDKHpUtyyOBxRslrBWICXt2sNnff_U/edit
*/

#include "gtest/gtest.h"
#include "Parser.h"


/* ------------------------------------------------ */

TEST(semi_parse, 0){
  Parser s;
  EXPECT_EQ( s.parse("5;3"), true);
}

TEST(semi_parse, 1){
  Parser s;
  EXPECT_EQ( s.parse("5;3;"), false);
}

TEST(semi_parse, 2){
  Parser s;
  EXPECT_EQ( s.parse("5;3;2"), true);
}

TEST(semi_parse, 3){
  Parser s;
  EXPECT_EQ( s.parse("5;3;2;8+3"), true);
}




/* ------------------------------------------------ */
TEST(semi, 0){
  Parser s;
  EXPECT_EQ( s.eval("2; 5"), 5);
}

TEST(semi, 1){
  Parser s;
  EXPECT_EQ( s.eval("a = 2; 5"), 5);
}

TEST(semi, 2){
  Parser s;
  EXPECT_EQ( s.eval("a = 2; a = 3; a"), 3);
}

TEST(semi, 3){
  Parser s;
  EXPECT_EQ( s.eval("8; a = 2; b = 3; a"), 2);
}

TEST(semi, 4){
  Parser s;
  EXPECT_EQ( s.eval("8; a = 2; b = 3; a + b"), 5);
}

/* ------------------------------------------------ */
TEST(print, 0){
  Parser s;
  EXPECT_EQ( s.eval("print 5"), 5);
}

TEST(print, 1){
  Parser s;
  EXPECT_EQ( s.eval("1 ; print 7"), 7);
}

TEST(print, 2){
  Parser s;
  EXPECT_EQ( s.eval("print 2; 10"), 10);
}

TEST(print, 3){
  Parser s;
  EXPECT_EQ( s.eval("a = print 2; a + 3; a"), 2);
}

// Old Tests
/* ------------------------------------------------ */
TEST(eval, 0){
  Parser s;
  EXPECT_EQ( s.eval(" 5"), 5);
}

TEST(eval, 1){
  Parser s;
  EXPECT_EQ( s.eval(" 5 + 6"), 11);
  EXPECT_EQ( s.eval(" 5 + 6 - 1"), 10);
}

TEST(eval, 2){
  Parser s;
  EXPECT_EQ( s.eval(" 10 * 2 - 1"), 19);
}

TEST(eval, 3){
  Parser s;
  EXPECT_EQ( s.eval(" (3 + 5) * 2 / 4"), 4);
}

TEST(eval, 4){
  Parser s;
  EXPECT_EQ( s.eval(" 1 + 5 * 7 - 3 * 9 + (34)"), 43);
}

TEST(eval, 5){
  Parser s;
  EXPECT_EQ( s.eval(" 9 / 2"), 4);
}

TEST(eval, 6){
  Parser s;
  EXPECT_EQ( s.eval(""), 0);
}

TEST(eval, 7){
  Parser s;
  EXPECT_EQ( s.eval("(6"), 0);
}

TEST(eval, 8){
  Parser s;
  EXPECT_EQ( s.eval("(1 + (3 * 2)) * (8-2)"), 42);
}

TEST(eval, 9){
  Parser s;
  EXPECT_EQ( s.eval("(1 + (3 * 2)) * (8-2)"), 42);
}



TEST(assignment, 1){
  Parser s;
  EXPECT_EQ( s.eval("a = 5"), 5);
}

TEST(assignment, 2){
  Parser s;
  s.parse("a=6");
  EXPECT_EQ( s.eval(), 6);
}

TEST(assignment, 3){
  Parser s;
  EXPECT_EQ( s.eval("a = 5"), 5);
  EXPECT_EQ( s.eval("a + 1"), 6);
}

TEST(assignment, 4){
  Parser s;
  EXPECT_EQ( s.eval("a = 5"), 5);
  EXPECT_EQ( s.eval("b = 50"), 50);
  EXPECT_EQ( s.eval("a + b + 1"), 56);
}

TEST(assignment, 5){
  Parser s;
  EXPECT_EQ( s.eval("a = 4 + 1"), 5);
  EXPECT_EQ( s.eval("a + 1"), 6);
  EXPECT_EQ( s.eval("a = 6"), 6);
  EXPECT_EQ( s.eval("a + 1"), 7);
}

TEST(assignment, 6){
  Parser s;
  EXPECT_EQ( s.eval("a = 4 + 1"), 5);
  EXPECT_EQ( s.eval("a * a"), 25);
  EXPECT_EQ( s.eval("a = 6"), 6);
  EXPECT_EQ( s.eval("a + 1"), 7);
}

TEST(assignment, 7){
  Parser s;
  EXPECT_EQ( s.eval("a = 4 + 1"), 5);
  EXPECT_EQ( s.eval("b + 1"), 1);
}

TEST(assignment, 8){
  Parser s;
  EXPECT_EQ( s.eval("3 + (cab = 2) * 2"), 7);
  EXPECT_EQ( s.eval("cab * 3"), 6);
}

TEST(varClear, 1){
  Parser s;
  EXPECT_EQ( s.eval("a = 6"), 6);
  s.varClear();
  EXPECT_EQ( s.eval("a"), 0);
}

TEST(varDump, 1){
  Parser s;
  EXPECT_EQ( s.eval("a = 1"), 1);
  EXPECT_EQ( s.eval("b = 2"), 2);
  EXPECT_EQ( s.eval("c = 3"), 3);
  s.varDump();
}

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

