#include <string>
#include <iostream>
#include <cassert>


bool isValidEbayListingString(string auctionstring);

int main()
{
  
  return 0;
}

bool isValidEbayListingString(string auctionstring)
{
  // L100B50WB+10UWB+41W
  // L => 100 => 
  // B => 50 
  // B+ => check if B exist => 10 =>
  // U => check if W exist => n_watch--
  // W => n_watch++
  //

  // 1. get the auctionCode: L,B....
  int i = 0;
  bool is_L_existed = false;
  bool is_B_existed = false;
  do {
    if (i < auctionstring.size()) return false;
    if (auctionstring[i] == 'L' || auctionstring[i] == 'l')
    {
      i++;
      if (is_L_existed) return false;
      else is_L_existed = true;

      // IMPORTANT!! check i < auctionstring.size()
      if (i < auctionstring.size())
          // get the number....
    }
    else if ( 'B')
    else if ( 'W')
    ...
    else return false;
  } while (i < auctionstring.size());
  return true;
}


// switch case
bool isValidEbayListingString(string auctionstring)
{
  enum eCode { eCodeInvalid, eCodeL, eCodeB, eCodeBPlus, ...};
  eCode code = eCodeInvalid;
  for (int i=0; i<auctionstring.size(); )
  {
    // 1. get the auction code: L,B,B+,...
    if (auctionstring[i] == 'B' && (i+1<len && auctionstring[i+1] == '+')
    {
      code = eCodeBPlus;
      i+=2;
    }
    else if ('B')
    else if ('L')...

    switch(code)  // integer => int / unsigned int / enum / char
    {
      eCodeBPlus:
        // check B exist
        if (is_B_existed == false) return false;
        // get numbers
        break;
      eCodeB:
      eCodeL:
        break;
      default:
        return fasle;
    }

  }
}

// string "100" => int 100
// int char_num = auctionstring[i] - '0';


