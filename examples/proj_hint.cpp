#include <iosream>
#include <string>

using namespace std;

int main()
{
/*Donor Name: Paula Abdul
Gender: Female
Age: 52
Weight: 107
Height: 59
--- No, Paula Abdul you cannot donate blood.  
*/
  cout << "Donor Name: ";
  //cin >> some_string
  string name;
  getline(cin, name);

  cout << "Gender: ";
  string gender;
  getline(cin, gender);
  if (gender != "Male")
  {
    cout << "--- You must enter a valid gender." << endl;
    return 0;
  }

  cout << "Age: ";
  int age;
  cin >> age;

  // valid input! check if the user can donate blood
  if (.......)
  {
    cout << "--- Yes, "<< name <<" you can donate blood.";
  }
  else(...)
  {
  }

  retrun 0;
}
