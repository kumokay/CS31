#include <iostream>
#include <string>
#include <cassert>

using namespace std;   

int findMinimum( const string array[ ],int n )
{
/*
Return the index of the smallest item found in the array or -1 if n <= 0.  For example, for the array people[ 5 ] shown above, findMinimum( people, 5 ) should return the value 3, corresponding to the index of "daenerys".  If there are multiple duplicate minimum values, you may return the index of either element that has this smallest value.*/
  // string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
  if (n <= 0) return -1;

  int smallest_idx = 0;
  string smallest_str = array[0];
  for (int i=0; i<n; i++)
  {
    if (array[i] < smallest_str)
    {
      smallest_idx = i;
      smallest_str = array[i];
    }
  }
  return smallest_idx;
}

int main()
{
            string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
            string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };

            assert(findMinimum(a, 3 ) == 0);
            assert(findMinimum(b, 3 ) == 2);

            // assert(countAllFloatingPointValues(a, 5 ) == 0);
            // assert(countAllFloatingPointValues(b, -10 ) == -1);	

	    cout << "All tests succeeded" << endl;
            return( 0 );
}


