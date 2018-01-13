# final coding practice

## classes

You are writing codes for a soda vending machine that takes cach and sell coke and water.

( https://en.wikipedia.org/wiki/Soda_fountain )

Complete the following building blocks for the soda fountain.
You are not allow to add any public or private members to the classes.

```cpp
#include <iostream>
#include <string>

using namespace std;

class SodaFountain {
  public:
    void initSodaFountain(int price, int max_size);
    int addSoda(int n_oz);
    bool takeOneOzSoda();
    double getUnitPrice() const;
  private:
    double m_price_per_oz;
    int m_size;  
        // the amount of soda inside the fountain
    int m_max_size;  
        // the max amount of soda can be stored this fountain
};

void SodaFountain::initSodaFountain(int price, int max_size)
{
  // initialize private members

}

int SodaFountain::addSoda(int n_oz)
{
  // Add n_oz soda into the soda fountain.
  // If adding n_oz will make m_size exceed m_max_size
  //   then only add up to max_size.
  // Return the amount of soda increased.

}

bool SodaFountain::takeOneOzSoda()
{
  // Take 1 oz soda from the soda fountain.
  // If the amount of soda we have is less than 1 oz,
  //   then do not take any soda and return false.
  // Otherwise, take the soda, decrease m_size, and return true.

}

double SodaFountain::getUnitPrice() const
{
  // Return m_price_per_oz

}

class VendingMachine{
  public:
    VendingMachine();
    enum eSodaFountain {WATER=0, COKE, N_FOUNTAIN};
    int addSoda(eSodaFountain soda_name, int n_oz);
    double sellSoda(eSodaFountain soda_name, int n_oz, double money);
  private:
    SodaFountain* getSodaFountain(eSodaFountain soda_name);
    SodaFountain m_fountain[N_FOUNTAIN];
    double m_total_money_gained; 
};


VendingMachine::VendingMachine()
{
  // Initialize the private members in the vending machine class.
  // For coke fountain, the max size is 200 oz, the unit price is 0.1 dollar
  // For water fountain, the max size is 100 oz, the unit price is 1 dollar

}

SodaFountain* VendingMachine::getSodaFountain(eSodaFountain soda_name)
{
  // Return the pointer of the corresponding soda fountain.
  // Note that the value of soda_name must be defined in eSodaFountain (i.e. must be WATER or COKE)
  // If the input soda_name is not defined in eSodaFountain, return NULL.

}

int VendingMachine::addSoda(eSodaFountain soda_name, int n_oz)
{
  // Add soda into the soda fountains, and return the amount of soda increased.
  // If the input soda_name is not defined in eSodaFountain, return 0.

}

double VendingMachine::sellSoda(eSodaFountain soda_name, int n_oz, double money)
{
  // Sell soda to the customers; note that tax is 8 percent.
  // Take soda from the fountains, take money, return changes.
  // If the input soda_name is not defined in eSodaFountain, 
  //   don't sell anything and return the money to the customer.
  // If there's not enough soda in the fountain, 
  //   sell all of them and return changes based on the amount sold.
  // The money gained will be stored in m_total_money_gained.

}

int main()
{
  VendingMachine* vp;
  VendingMachine::eSodaFountain undefined_soda = (VendingMachine::eSodaFountain)10;
  double money =  20;
  
  // Create a new vending machine.
  // Add 50 oz to both coke, water, and undefined_soda fountains.
  // Use a 20-dollar bill to buy 10 oz water, and update the amount of money you have.
  // Use the money to buy 2 oz undefined_soda, and update the amount of money you have.
  // delete the vending machine.

  return 0;
}

```


---------------------------------------------

```cpp
#include <iostream>
#include <string>

using namespace std;

class SodaFountain {
  public:
    void initSodaFountain(int price, int max_size);
    int addSoda(int n_oz);
    bool takeOneOzSoda();
    double getUnitPrice() const;
  private:
    double m_price_per_oz;
    int m_size;  
        // the amount of soda inside the fountain
    int m_max_size;  
        // the max amount of soda can be stored this fountain
};

void SodaFountain::initSodaFountain(int price, int max_size)
{
  // initialize private members
  m_price_per_oz = price;
  m_size = 0;
  m_max_size = max_size;
}

int SodaFountain::addSoda(int n_oz)
{
  // Add n_oz soda into the soda fountain.
  // If adding n_oz will make m_size exceed m_max_size
  //   then only add up to max_size.
  // Return the amount of soda increased.
  int increased = 0;
  if (m_size + n_oz > m_max_size)
    increased = m_max_size - m_size;
  else 
    increased = n_oz;
  m_size = m_size + increased;
  return increased;
}

bool SodaFountain::takeOneOzSoda()
{
  // Take 1 oz soda from the soda fountain.
  // If the amount of soda we have is less than 1 oz,
  //   then do not take any soda and return false.
  // Otherwise, take the soda, decrease m_size, and return true.
  if (m_size < 1)
  {
    return false;
  }
  m_size--;
  return true;
}

double SodaFountain::getUnitPrice() const
{
  // Return m_price_per_oz
  return m_price_per_oz;
}

class VendingMachine{
  public:
    VendingMachine();
    enum eSodaFountain {WATER=0, COKE, N_FOUNTAIN};
    int addSoda(eSodaFountain soda_name, int n_oz);
    double sellSoda(eSodaFountain soda_name, int n_oz, double money);
  private:
    SodaFountain* getSodaFountain(eSodaFountain soda_name);
    SodaFountain m_fountain[N_FOUNTAIN];
    double m_total_money_gained; 
};


VendingMachine::VendingMachine()
{
  // Initialize the private members in the vending machine class.
  // For coke fountain, the max size is 200 oz, the unit price is 0.1 dollar
  // For water fountain, the max size is 100 oz, the unit price is 1 dollar
  m_fountain[WATER].initSodaFountain(0.1, 200);
  m_fountain[WATER].initSodaFountain(1.0, 100);
  m_total_money_gained = 0;
}

SodaFountain* VendingMachine::getSodaFountain(eSodaFountain soda_name)
{
  // Return the pointer of the corresponding soda fountain.
  // Note that the value of soda_name must be defined in eSodaFountain (i.e. must be WATER or COKE)
  // If the input soda_name is not defined in eSodaFountain, return NULL.
  if (soda_name < 0 || soda_name >= N_FOUNTAIN)
    return NULL;
  return &m_fountain[soda_name];
}

int VendingMachine::addSoda(eSodaFountain soda_name, int n_oz)
{
  // Add soda into the soda fountains, and return the amount of soda increased.
  // If the input soda_name is not defined in eSodaFountain, return 0.
  SodaFountain* ptr = getSodaFountain(soda_name);
  if (ptr == NULL)
    return 0;
  return ptr->addSoda(n_oz);
}

double VendingMachine::sellSoda(eSodaFountain soda_name, int n_oz, double money)
{
  // Sell soda to the customers; note that tax is 8 percent.
  // Take soda from the fountains, take money, return changes.
  // If the input soda_name is not defined in eSodaFountain, 
  //   don't sell anything and return the money to the customer.
  // If there's not enough soda in the fountain, 
  //   sell all of them and return changes based on the amount sold.
  // The money gained will be stored in m_total_money_gained.
  SodaFountain* ptr = getSodaFountain(soda_name);
  if (ptr == NULL)
    return money;

  double taxed_unit_price = ptr->getUnitPrice() * 1.08;
  double money_increased = 0;
  while (money >= taxed_unit_price && n_oz > 0)
  {
    if (true == ptr->takeOneOzSoda())
    {
      money -= taxed_unit_price;
      money_increased += taxed_unit_price;
      n_oz -= 1;
    } 
    else
      break;
  }
  m_total_money_gained += money_increased;
  return money;
}

int main()
{
  VendingMachine* vp;
  VendingMachine::eSodaFountain undefined_soda = (VendingMachine::eSodaFountain)10;
  double money =  20;
  
  // Create a new vending machine.
  // Add 50 oz to both coke, water, and undefined_soda fountains.
  // Use a 20-dollar bill to buy 10 oz water, and update the amount of money you have.
  // Use the money to buy 2 oz undefined_soda, and update the amount of money you have.
  // delete the vending machine.
  
  vp = new VendingMachine();
  cout << "add coke: " << vp->addSoda(VendingMachine::COKE, 50) << endl;
  cout << "add water: " << vp->addSoda(VendingMachine::WATER, 50) << endl;
  cout << "add undefined soda: " << vp->addSoda(undefined_soda, 50) << endl;
  
  
  money = vp->sellSoda(VendingMachine::WATER, 10, money);
  cout << "Buy water; I have " << money << " left" << endl;
  
  money = vp->sellSoda(undefined_soda, 2, money);
  cout << "Buy undefined_soda; I have " << money << " left" << endl;
  
  delete vp;
  

  return 0;
}

```



