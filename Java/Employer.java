import java.io.*;
import java.util.*;
import java.util.Scanner;

public class Employer{

	static int workHours = 40;
	static int salary = 40000;
	static int vacationDays = 14;
	
    public static void main(String[] args){
		Secretary emp1 = new Secretary();
		legalSecretary emp2 = new legalSecretary();
		Lawyer emp3 = new Lawyer();
		Marketer emp4 = new Marketer();
		
		System.out.println("Work Hours: " + emp1.getWorkHours());
		String str1 = String.format("%.02f", emp1.getSalary());
		System.out.println("Salary: $"+ str1);
		System.out.println("Vacation Days: " + emp1.getVacationDays());
		System.out.println("Vacation Form: " + emp1.getVacationForm() + "\n");
		
		System.out.println("Work Hours: " + emp2.getWorkHours());
		String str2 = String.format("%.02f", emp2.getSalary());
		System.out.println("Salary: $" + str2);
		System.out.println("Vacation Days: " + emp2.getVacationDays());
		System.out.println("Vacation Form: " + emp2.getVacationForm() + "\n");
		
		System.out.println("Work Hours: " + emp3.getWorkHours());
		String str3 = String.format("%.02f", emp3.getSalary());
		System.out.println("Salary: $" + str3);
		System.out.println("Vacation Days: " + emp3.getVacationDays());
		System.out.println("Vacation Form: " + emp3.getVacationForm() + "\n");
		
		System.out.println("Work Hours: " + emp4.getWorkHours());
		String str4 = String.format("%.02f", emp4.getSalary());
		System.out.println("Salary: $" + str4);
		System.out.println("Vacation Days: " + emp4.getVacationDays());
		System.out.println("Vacation Form: " + emp4.getVacationForm() + "\n");
        

    }

   public int getWorkHours(){
       return workHours;
   }

   public double getSalary(){
       return salary;
   }

   public int getVacationDays(){
       return vacationDays;
   }

   public String getVacationForm(){
       return "Yellow Form";
   }

}

class Secretary extends Employer
{
    public void workDictate(){
       System.out.println("Dictate");
    }
}

class legalSecretary extends Secretary
{
    public void workLegalDocuments(){
       System.out.println("Prepare legal documents");
    }

    @Override
    public double getSalary(){
       return (super.getSalary() + 5000);
    }
}

class Lawyer extends Employer
{
    public void workSue(){
       System.out.println("Sue");
    }

    @Override
    public int getVacationDays(){
       return (super.getVacationDays() + 7); // super is like virtual in c++
    }

    @Override
    public String getVacationForm(){
       return "Pink Form";
    }
}

class Marketer extends Employer
{
    public void workAdvertise(){
       System.out.println("Advertise");
    }

    @Override
    public double getSalary(){
       return (super.getSalary() + 10000);
    }
}