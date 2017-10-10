/*Tyler Allen
Program 3
CS111
This program will output statistics of food eaten by monkeys including the average amount eaten*/

#include <iostream>
using namespace std;
#include<iomanip>
const int NUM_MONKEYS=3;
const int NUM_DAYS=7;

void fillArray(int ar[][NUM_MONKEYS]); // prompts the user to input the data for each monkey
void showAveragePerDay(const int ar[][NUM_MONKEYS]); // displays the average amount of food eaten per day by the whole family of monkeys. 
void showLeastGreatestAmt(const int ar[][NUM_MONKEYS]); // displays the least and greatest amounts of food eaten during the week by any one monkey

int main(){

  int array[NUM_DAYS][NUM_MONKEYS];
  fillArray(array);
  showAveragePerDay(array);
  showLeastGreatestAmt(array);
 return 0;
}

void fillArray(int ar[][NUM_MONKEYS])
{
  for(int m=0;m<NUM_MONKEYS;m++)
    {
      cout<<"Enter the number of pounds Monkey "<<m+1<<" ate each day"<<endl;
      
      for(int d=0;d<NUM_DAYS;d++)
	{
	  do{
	  cout<<"Day "<<d+1<<": ";
	  cin>>ar[d][m];
	  }while(ar[d][m]<0);
	}
    }
}

void showAveragePerDay(const int ar[][NUM_MONKEYS])
{
  int total=0;
  double avg;
  cout<<setw(3)<<"Day"<<setw(20)<<"Average Pounds"<<endl;

  for(int d=0;d<NUM_DAYS;d++)
    {
      cout<<d+1;
      for(int m=0; m<NUM_MONKEYS;m++)
	{
	  total+=ar[d][m];
	}
      avg=(double)total/NUM_MONKEYS;
      cout<<setw(22)<<fixed<<setprecision(2)<<avg<<endl;
      total=0;
    }
}

void showLeastGreatestAmt(const int ar[][NUM_MONKEYS])
{
  int highest=-1;
  int lowest=999;
  for(int m=0;m<NUM_MONKEYS;m++)
    {
      for(int d=0;d<NUM_DAYS;d++)
        {
	  if(ar[m][d]>highest)
	    highest=ar[d][m];
	  if(ar[m][d]<lowest)
	     lowest=ar[d][m];     
        }
    }
      cout<<"The least amount ate is "<<lowest<<endl;
      cout<<"The largest amount ate is "<<highest<<endl;
    }
