#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol1202;
using namespace std;

/*takeaways
  - use union-find to group indexes.
  - The indexes that can be connected allow us to sort
    the string represented by those index locations using swaps.
  - so for example input: s = "dcab", pairs = [[0,3],[1,2]]
    - locations 0 and 3 are a group and the string represented is "da"
    - locations 1 and 2 are another group and the string represented is "cb"
    - we then sort each string separately  "da" -> "ad" and "cb" -> "bc"
    - finally, we just assemble the string back to get "bacd"
*/

string Solution::find(string s, vector<vector<int>> &pairs)
{
  int n = s.size();
  auto parent = vector<int>(n);
  iota(begin(parent), end(parent), 0);

  function<int(int)> findParent = [&](int i)
  {
    return parent[i] == i ? i : findParent(parent[i]);
  };

  /* Union - group indexes that are connected into
     their own group
   */
  for (auto &p : pairs)
    parent[findParent(p[0])] = findParent(p[1]);

  /* record indexes and string for each group */
  auto indexes = vector<vector<int>>(n);
  auto ss = vector<string>(n);

  for (auto i = 0; i < n; i++)
  {
    auto p = findParent(i);
    indexes[p].push_back(i);
    ss[p].push_back(s[i]);
  }

  for (auto i = 0; i < n; i++)
  {
    auto indxs = indexes[i];
    if (indxs.empty())
      continue;
    auto str = ss[i];
    /* simulating swapping */
    sort(begin(str), end(str));

    /* copy back the sorted string
       - char by char back to its location in the original string
    */
    for (auto j = 0; j < indxs.size(); j++)
      s[indxs[j]] = str[j];
  }

  return s;
}