# midterm 2 coding practice

## string, pass by value, pass by reference, and return value

You are writing codes for the game "Super Laser: The Alien Fighter"

( https://www.epicforce.com/index.php/games-en/superlaser )

However your game is not that fancy, and the fighter can only move to either left or right.

Complete the following function "move_the_fighter(...)":
- The player can input a sequence of keystrokes compose of "L" and "R" to move the fighter to the left or right.
- The input parameter x is the fighter's current position.
- The input parameter leftmost, rightmost is the leftmost and rightmost point the fighter has ever reached in the game.

- The map width is 0 to 20 pixels, and the fighter cannot go beyond the border
  * The fighter's x position must be in the range [0 ~ 20].
  * If the fighter touched the border (x < 0 or x > 20), the function should return false immediately.
  * In this case, 0 or 20 would be the final position for the fighter 
  * In this case, the value of leftmost and rightmost could be 0 or 20, depends on the situation
- If the sequence contains characters other then "L" and "R", return false immediately
  * In this case, do not update the fighter's position x, leftmost, and rightmost
- If nothing wrong, update the fighter's position, the value of leftmost and rightmost, and and return true.

```cpp
#include <iostream>
#include <string>

using namespace std;

bool move_the_fighter(string keystrokes, int& x, int& leftmost, int& rightmost)
{

}

int main()
{
  int x = 10;
  int leftmost = x;
  int rightmost = x;

  cout << "move_the_fighter() success=" << move_the_fighter("LLLRRRRRLL", x, leftmost, rightmost) << endl;
  cout << "x=" << x << ", moving_range=("<< leftmost << "," << rightmost << ")" << endl;

  cout << "move_the_fighter() success=" << move_the_fighter("LLLRRRLLLRRRLLLLLLLLLLLX", x, leftmost, rightmost) << endl;
  cout << "x=" << x << ", moving_range=("<< leftmost << "," << rightmost << ")" << endl;
  
  cout << "move_the_fighter() success=" << move_the_fighter("LLLLRRRRRRRRRRRRRRRRLLLLLLLLL", x, leftmost, rightmost) << endl;
  cout << "x=" << x << ", moving_range=("<< leftmost << "," << rightmost << ")" << endl;

  return 0;
}
```

sample output:
```
move_the_fighter() success=1
x=10, moving_range=(7,12)
move_the_fighter() success=0
x=10, moving_range=(7,12)
move_the_fighter() success=1
x=20, moving_range=(6,20)
```

------------------------

```cpp
bool move_the_fighter(string keystrokes, int& x, int& leftmost, int& rightmost)
{
  int cur_x = x;
  int cur_leftmost = leftmost;
  int cur_rightmost = rightmost;

  // check invalid key first
  for (int i=0; i<keystrokes.size(); i++)
  {
    if ( keystrokes[i] != 'R' && keystrokes[i] != 'L')
      return false;
  } 

  // move the fighter
  for (int i=0; i<keystrokes.size(); i++)
  {
    if ( keystrokes[i] == 'R')
    {
      cur_x++;
      if (cur_x > cur_rightmost) 
        cur_rightmost = cur_x;
    } 
    else if ( keystrokes[i] == 'L')
    {
      cur_x--;
      if (cur_x < cur_leftmost) 
        cur_leftmost = cur_x;
    }
    if (cur_x == 0 || cur_x == 20)
      break;
  }
  
  // update values
  x = cur_x;
  leftmost = cur_leftmost;
  rightmost = cur_rightmost;
  return true;
}
```

## pointer, array, c-string, and ascii code

Write a function "transform(char* text)" to do the following using (1) pointers and (2) char array
1. change any UPPERCASE in the text to lowercase
2. calculate the sum of all numbers in the text
3. reverse the text in place

```
sample intput: 
There are 1 APPLE, 12 ORANGES, and 3 PENCILS

output:
sum=7
text=slicnep 3 dna ,segnaro 21 ,elppa 1 era ereht
```

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int transform(char* text)
{

}

int main()
{
  char text[] = "There are 1 APPLE, 12 ORANGES, and 3 PENCILS\0";
  
  int sum = transform(text);
  cout << "sum=" << sum << endl;
  cout << "text=" << text << endl;

  return 0;
}
```

------------------------

(1) pointers only

```cpp
int transform(char* text)
{
  char* p = text;
  int sum = 0;
  while (*p != 0)
  {
    if (*p >= 'A' && *p <= 'Z') 
      *p = *p - 'A' + 'a';
    else if (*p >= '0' && *p <= '9')
    {
      sum += *p - '0';
    }
    p++;
  }
  
  p = text;
  char* q = text + strlen(text) - 1;
  while (p < q)
  {
    char tmp = *p;
    *p = *q;
    *q = tmp;
    p++;
    q--;
  }
  return sum;
}
```


(2) array only

```cpp
int transform(char* text)
{
  int i = 0;
  int sum = 0;
  while (text[i] != 0)
  {
    if (text[i] >= 'A' && text[i] <= 'Z') 
      text[i] = text[i] - 'A' + 'a';
    else if (text[i] >= '0' && text[i] <= '9')
    {
      sum += text[i] - '0';
    }
    i++;
  }
  
  i = 0;
  int j = strlen(text) - 1;
  while (i < j)
  {
    char tmp = text[i];
    text[i] = text[j];
    text[j] = tmp;
    i++;
    j--;
  }
  return sum;
}
```
