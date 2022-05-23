#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1202;

/*
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
*/

tuple<string, vector<vector<int>>, string>
testFixture1()
{
  auto pairs = vector<vector<int>>{
      {0, 3}, {1, 2}};
  return make_tuple("dcab", pairs, "bacd");
}

/*
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
*/

tuple<string, vector<vector<int>>, string>
testFixture2()
{
  auto pairs = vector<vector<int>>{
      {0, 3}, {1, 2}, {0, 2}};
  return make_tuple("dcab", pairs, "abcd");
}

/*
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
*/

tuple<string, vector<vector<int>>, string>
testFixture3()
{
  auto pairs = vector<vector<int>>{
      {0, 1}, {1, 2}};
  return make_tuple("cba", pairs, "abc");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.find(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.find(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.find(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}