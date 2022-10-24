#pragma once
/*
 * Model a weekly employee who gets paid on an hourly basis. Only two
 * taxes are included so far: Medicare and Social Security. You may be
 * asked to add Federal Income tax that requires Chapter 7: Selection.
 *
 * File name: WeeklyEmployee.h
 */
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <iostream>
#include <cmath>

class Employee {
private:
	// data members
	std::string name;
	double rate;
	double hours;
	std::string status;
	int allowances;

public:

	Employee(std::string initName, double hourlyRate,
		std::string singleOrMarried, int withholdingAllowances);
	// post: A WeeklyEmployee is built with 0.00 hours worked.

	void giveRaise(double raise);
	// pre: raise > 0 and it is provided as percentage: 3.5 means a 3.50% raise
	// post: the hourly rate of pay has changed


	void setHoursWorked(double hoursWorked);
	// pre: hoursWorked >= 0.0
	// post: hours worked for the current week is set. Pay and taxes can be computed


	double getIncomeTax();
	// pre: All required state is set
	// post: return the correct amount of money to withhold for federal income tax


//--getters
	std::string getName();
	double getHoursWorked();
	double getHourlyRate();
	double getSocSecurityTax();
	double getMedicareTax();
	double getGrossPay();
	double getNetPay();


};

Employee::Employee(std::string initName, double hourlyRate, 
	std::string singleOrMarried, int withholdingAllowances) {
	name = initName;
	rate = hourlyRate;
	status = singleOrMarried;
	allowances = withholdingAllowances;

}


void Employee::giveRaise(double raise) {
	rate = rate + raise;
}
	

void Employee::setHoursWorked(double hoursWorked) {
	hours = hours + hoursWorked;
}
	

double Employee::getIncomeTax() {
	return allowances;
}
	

std::string Employee::getName() {
	return name;
}
double Employee::getHoursWorked() {
	return hours;
}
double Employee::getHourlyRate() {
	return rate;
}
double Employee::getSocSecurityTax() {
	return allowances;
}
double Employee::getMedicareTax() {
	return 0.0;
}
double Employee::getGrossPay(){
	double payment = rate * hours;
	return payment;
}
double Employee::getNetPay() {
	return 0;
}



#endif /* EMPLOYEE_H_ */