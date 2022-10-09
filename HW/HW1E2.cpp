//Include c standard library
#include <cstdlib>
#include <iostream>
//Use this for ease of programming
using namespace std;

//Set integer private memer variables
private:
	int day;
	int month;
	int year;

//Make your public member functions, I'm probably missing something
public:
	//Member function takes no arguments, advanceDate() is a member function of class Date
	void Date::advanceDate(day, month, year){
		setDay(day);
		setMonth(month);
		setYear(year);
		
		//If all the tests are pass in checkMonthsDaysYear, increment the date by 1
		if(checkMonthDaysYear == true){
			day++;
		}
		
		//Display the final incremented date if valid
		cout << "The date is " << day << "/" << month << "/" << year;
	}

	//Accessor method for the day
	int Date::getDay() const{
		return day;
	}

	//Accessor method for the month
	int Date::getMonth() const{
		return month;
	}

	//Accessor method for the year
	int Date::setYear() const{
		return year;
	}
	
	//Mutator method for the day
	void Date::setDay(int d){
		day = d;
	}

	//Mutator method for the month
	void Date::setMonth(int m) {
		month = m;
	}

	//Mutator method for the year
	void Date::setYear(int y) {
		year = y;
	}
	
	//Make sure the days in the given month, the given month and the given year is valid
	bool Date::checkMonthDaysYear(){
		//Create an array to hold the days in each month
		int daysMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		
		//If the month is less than 1 or greater then 12 it is not valid
		if(month < 1 || month > 12){
			cout << "Not a valid month.";
			exit(EXIT_FAILURE);
		}
		
		//If the day given is greater then the days in that given month
		//or if the day is less than zero it is not valid
		else if(day > daysMonth[month-1] || day < 0){
			cout << "Not a valid day of the month;"
			exit(EXIT_FAILURE);
		}
		
		//If the year is less than zero it is not valid
		//We ain't sum BC lozers
		else if(year < 0){
			cout << "We're not accounting for that here, sorry."
			exit(EXIT_FAILURE);
		}
		
		//If the month is Feburary and it is a leap year, change the days in Feburary
		else if(month == 2 && leapYear() == true){
				daysMonth[2] = 29;
		}
		
		//If the day given is equal to the max days in the given month, advance the month
		//and set day equal to one
		else if(day == daysMonth[month-1]){
			month++;
			day = 1;
		}
		
		//If there are any cases I forgot exit
		else{
			exit(EXIT_FAILURE);
		}
		
		//If the cases all pass, return true;
		return true;
	}
	
	//Write a member function to take into account the leap year
	bool leapYear(){
		//Set a max, can be adjusted
		int max = 10000;
		int first_century = 0;
		
		//If year is not divisible by 4 than it is not a leap year
		if((year % 4) != 0){
			return false;
		} 
		
		//Else while it is divisible by 4 but an even century it is a leap year, zero is even
		//But if it is an odd century, it is not a leap year
		else{
			for(int i = first_century; i < max; i += 200){
				return true;
			} 
			return false;
		}
	}
