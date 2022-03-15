
/************************************************************************************************************************

Name: Normil Luccin                                Z#:Z23635489
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 02/02/22                      Due Time:02/09/22
Total Points: 20
Assignment #: amazon_orders.cpp

Description:
	
	This program takes values from amazon orders through
	a data file and displays them to a user after calculations.

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:
	string cell_number;
	string item_number;
	int quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};


void input(ifstream&, order_record&);
void output(const order_record&);
void process(order_record&);

///*************************************************************************************
//Name: input
//Precondition: Connects to the data file, must have a valid order record.
//
//Postcondition: Reads the order record from data file and retains infromation.
// 
//Description: Gets the input (values of cell_number, item_number, quantity, price, processing_plant) 
//			   from data file order record (p_record).

//*************************************************************************************

void input(ifstream& in, order_record& p_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> p_record.cell_number;
	in >> p_record.item_number;
	in >> p_record.quantity;
	in >> p_record.price;
	in >> p_record.processing_plant;

}

///*************************************************************************************
//Name: output
//Precondition: Requires order record and information remains unchanged (const).
//Postcondition: Takes processed data and displays it to the user.
//Description: Outputs the cell number, item number, quantity, price, processing plant, tax rate
//			   order tax, net cost and total cost for the user.

//*************************************************************************************

void output(const order_record& p_record)
{
	//Helps format the values into a table format (magic formula)
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	/********************************************/
	
	cout << p_record.cell_number << "\t";
	cout << p_record.item_number << "\t";
	cout << p_record.quantity << "\t";
	cout << p_record.price << "\t";
	cout << p_record.processing_plant << "\t";

	cout.precision(2);// Sets the value into 2 decimal places
	cout << p_record.tax_rate << "%" << "\t";

	cout.precision(2);// Sets the value into 2 decimal places
	cout << p_record.order_tax << "\t";

	cout << p_record.net_cost << "\t";
	cout << p_record.total_cost << "\t" << endl;

}

///*************************************************************************************
//Name: process
//Precondition: Takes the order record and returns in the output of a visible record (p_record).
//Postcondition: Newly formed output is created and sent to the output.
//Description: Calculates the tax rate, order tax, net cost and total cost.

//*************************************************************************************


void process(order_record& p_record)
{

	if (p_record.processing_plant >= 0 && p_record.processing_plant <= 50)
		p_record.tax_rate = 6;
	else if (p_record.processing_plant >= 51 && p_record.processing_plant <= 110)
		p_record.tax_rate = 7;
	else if (p_record.processing_plant >= 111 && p_record.processing_plant <= 200)
		p_record.tax_rate = 8;
	else if (p_record.processing_plant >= 201 && p_record.processing_plant <= 500)
		p_record.tax_rate = 9;
	else if (p_record.processing_plant > 500)
		p_record.tax_rate = 11;


	p_record.order_tax = p_record.price * p_record.quantity * (p_record.tax_rate/100);
	p_record.net_cost = p_record.price * p_record.quantity;
	p_record.total_cost = p_record.order_tax + p_record.net_cost;
	
}


int main()
{
	//Setting magic formula
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	//Greeting
	string name;
	cout << "Hello, Enter your first name: \n";
	cin >> name;
	cout << "Alright " << name << ", let's access the amazon database. \n" << endl;

	//Initializing records
	order_record customer_record;

	//declaring an input file stream (displaying data file)
	ifstream in;    
	in.open("Purchase_data_Assignment2.txt");

	if (in.fail())
	{
		cout << "\nInput file did not open correctly" << endl;
	}
	else
	{
		cout << "\nDATA GRANTED! \n" << endl;
		
		while (!in.eof())
		{
			input(in, customer_record);
			process(customer_record);
			output(customer_record);
		}
	}

	in.close();

	return 0;
}


