# midterm 1 coding practice

## if-else and switch-case

For midterm, there are two many ppl in the class, so we need 3 classrooms for all the students.
- if the last digit of ur bruin id is 0, 4, or 6, go to Moore 100 
- if the last digit of ur bruin id is 1 or 8, go to Humanities A51 
- if the last digit of ur bruin id is 9, go to WGYoung CS50
- Note that there's no one in the class with last digit equals to 2, 3, 5, or 7. So if we get any input ends with the digit not listed above, we let them go to professor's office: Boelter 4532G.

Complete the following program using (1) if-else and (2) switch-case to help the students to find out which classroom to go.


```cpp
int main()
{
  int bruin_id = 123456789;
  string class_room;
  
  // your code
  
  cout << "you should go to " << class_room << endl;
  return 0;
}
```

------------------------

(1) if-else

```cpp
int main()
{
  int bruin_id = 123456789;
  string class_room;
  
  // your code
  int last_digit = bruin_id % 10; // 0~9
  if (last_digit == 0 || last_digit == 4 || last_digit == 6)
  {
    class_room = "Moore 100";
  }
  else if (last_digit == 1 || last_digit == 8)
  {
    class_room = "Humanities A51";
  }
  else if (last_digit == 9)
  {
    class_room = "WGYoung CS50";
  }
  else
  {
    class_room = "Boelter 4532G";
  }
  
  cout << "you should go to " << class_room << endl;
  return 0;
}
```


(2) switch-case

```cpp
int main()
{
  int bruin_id = 123456789;
  string class_room;
  
  // your code
  int last_digit = bruin_id % 10; // 0~9
  switch(last_digit)
  {
    case 0:
    case 4:
    case 6:
      class_room = "Moore 100";
      break;
    case 1:
    case 8:
      class_room = "Humanities A51";
      break;
    case 9:
      class_room = "WGYoung CS50"
      break;
    default:
      class_room = "Boelter 4532G";
      break;
  }
  
  cout << "you should go to " << class_room << endl;
  return 0;
}
```

## for, while, and do-while

write a program to print out the first 10 Fibonacci numbers using (1) for, (2) while, and (3) do-while.

```
Sample output: 
0 1 1 2 3 5 8 13 21 34
```

```cpp
#include <iostream>

using namespace std;

int main()
{
  // your code

  return 0;
}
```

--------------------------------------

(1) for

```cpp
int main()
{
  int prev2_n = 0;
  int prev1_n = 1;
  cout << prev2_n << " ";
  cout << prev1_n << " ";
  for (int i=3; i<=10; i++)
  {
    int this_n = prev1_n + prev2_n;
    cout << this_n << " "; 
    prev2_n = prev1_n;
    prev1_n = this_n;
  }

  return 0;
}
```


(2) while

```cpp
int main()
{
  int prev2_n = 0;
  int prev1_n = 1;
  cout << prev2_n << " ";
  cout << prev1_n << " ";
  int i = 3;
  while (i<=10)
  {
    int this_n = prev1_n + prev2_n;
    cout << this_n << " "; 
    prev2_n = prev1_n;
    prev1_n = this_n;
    i++;
  }

  return 0;
}
```

(3) do-while

```cpp
int main()
{
  int prev2_n = 0;
  int prev1_n = 1;
  cout << prev2_n << " ";
  cout << prev1_n << " ";
  int i = 3;
  do
  {
    // if (!(i<=10)) break;
    int this_n = prev1_n + prev2_n;
    cout << this_n << " "; 
    prev2_n = prev1_n;
    prev1_n = this_n;
    i++;
  } while (i<=10);

  return 0;
}
```