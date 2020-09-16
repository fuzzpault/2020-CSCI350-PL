/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the List interface
   
   https://github.com/google/googletest
*/

#include "gtest/gtest.h"
#include "dfa.h"


TEST(fn1, 0){
  EXPECT_EQ( fn1("ab"), true);
}

TEST(fn1, 1){
  EXPECT_EQ( fn1("z"), true);
}

TEST(fn1, 2){
  EXPECT_EQ( fn1("aba"), true);
}

TEST(fn1, 3){
  EXPECT_EQ( fn1("abaaaaaaaaa"), true);
}

TEST(fn1, 4){
  EXPECT_EQ( fn1("abaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), true);
}

TEST(fn1, 5){
  EXPECT_EQ( fn1("zaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), true);
}

TEST(fn1, 6){
  EXPECT_EQ( fn1("a"), false);
}

TEST(fn1, 7){
  EXPECT_EQ( fn1("zb"), false);
}

TEST(fn1, 8){
  EXPECT_EQ( fn1("abb"), false);
}

TEST(fn1, 9){
  EXPECT_EQ( fn1("abaaaaaaaaaaaab"), false);
}

TEST(fn1, 10){
  EXPECT_EQ( fn1("zzzzzzzzz"), false);
}

/************************************************************/

TEST(fn2, 0){
  EXPECT_EQ( fn2(""), true);
}

TEST(fn2, 1){
  EXPECT_EQ( fn2("a"), true);
}

TEST(fn2, 2){
  EXPECT_EQ( fn2("b"), true);
}

TEST(fn2, 3){
  EXPECT_EQ( fn2("ab"), true);
}

TEST(fn2, 4){
  EXPECT_EQ( fn2("aaaa"), true);
}

TEST(fn2, 5){
  EXPECT_EQ( fn2("bbbb"), true);
}

TEST(fn2, 6){
  EXPECT_EQ( fn2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbb"), true);
}

TEST(fn2, 7){
  EXPECT_EQ( fn2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbba"), false);
}

TEST(fn2, 8){
  EXPECT_EQ( fn2("ba"), false);
}

TEST(fn2, 9){
  EXPECT_EQ( fn2("bbbbbaaaaa"), false);
}

TEST(fn2, 10){
  EXPECT_EQ( fn2("abc"), false);
}

/************************************************************/

TEST(fn3, 0){
  EXPECT_EQ( fn3("aaa"), true);
}

TEST(fn3, 1){
  EXPECT_EQ( fn3("abc"), true);
}

TEST(fn3, 2){
  EXPECT_EQ( fn3("bca"), true);
}

TEST(fn3, 3){
  EXPECT_EQ( fn3("ccc"), true);
}

TEST(fn3, 4){
  EXPECT_EQ( fn3("ab"), false);
}

TEST(fn3, 5){
  EXPECT_EQ( fn3("abd"), false);
}

TEST(fn3, 6){
  EXPECT_EQ( fn3("aabc"), false);
}

TEST(fn3, 7){
  EXPECT_EQ( fn3(""), false);
}

/************************************************************/

TEST(fn4, 0){
  EXPECT_EQ( fn4(""), true);
}

TEST(fn4, 1){
  EXPECT_EQ( fn4("aa"), true);
}

TEST(fn4, 2){
  EXPECT_EQ( fn4("abcc"), true);
}

TEST(fn4, 3){
  EXPECT_EQ( fn4("aaabbb"), true);
}

TEST(fn4, 4){
  EXPECT_EQ( fn4("aaa"), false);
}

TEST(fn4, 5){
  EXPECT_EQ( fn4("ad"), false);
}

TEST(fn4, 6){
  EXPECT_EQ( fn4("abccb"), false);
}

/************************************************************/

TEST(fn5, 0){
  EXPECT_EQ( fn5("aaaaa"), true);
}

TEST(fn5, 1){
  EXPECT_EQ( fn5("baaab"), true);
}

TEST(fn5, 2){
  EXPECT_EQ( fn5("abcba"), true);
}

TEST(fn5, 3){
  EXPECT_EQ( fn5("aabbcc"), false);
}

TEST(fn5, 4){
  EXPECT_EQ( fn5("abba"), false);
}

TEST(fn5, 5){
  EXPECT_EQ( fn5("aadaa"), false);
}