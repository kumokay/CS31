#include <string>
#include <iostream>

using namespace std;

int main()
{
  char names[20][100] = {{0}};
  cin >> names[0];
  cin >> names[1];

  // string names[20] = {"NAME1", "NAME2", ....}
  

  // names[][] =
  // { "NAME1"0000000000...
  //   "NAME2"000000000....
  //   0000000000000000000000
  // }
  cout << names[0] << "," << names[1] << endl;
  return 0;

}
