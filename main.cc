//Theo Andonyadis
//ECE 2620 Section 001
//Lab 4
#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
using namespace std;
int findmax(int arr[])		//findmax function returns maximum value of a 5 member array
{
	int max=arr[0];
	for(int i=1;i<5;i++)
		if(arr[i]>max)
		max=arr[i];
	return max;	
}
int main()
{
	int n, *p;
	int x1, x2, x3, x4, x5;
	cout<<"Please enter the number of lines n in the input file."<<endl;
	cin>>n;			//gets user input for number of lines
	p = new int[n];			//declare dynamically allocated array p
	ifstream infile;		//creates infile and outfile objects for reading/writing
	ofstream outfile;
	infile.open("lab4_input.txt");		//uses ifstream member function open to open the input text file for reading
	outfile.open("lab4_output.txt");
	if (infile.is_open())			//if condition checks to ensure the infile is really open
	{
		for(int i=0; i<n; i++)		//for loop to iterate through however many lines the user chose
		{
			infile >> x1 >> x2 >> x3 >> x4 >> x5;		//reads 5 items from each line in the infile
			int arr[5]={x1,x2,x3,x4,x5};			//stores each line in an array to find the maximum
			p[i]=findmax(arr);				//fills dynamically allocated array p with max value from each line
		}	
	}
	else
	{
		cout<<"Error";		//outputs error if the text file is not open for reading
	}
	for(int i=0; i<n; i++)		//for loop to iterate through however many lines the user chose
	{
		outfile << p[i] << endl;		//writes each line of array p (maximums) into the output text file
	}		
	delete[] p;			//deletes dynamically allocated array p
	outfile.close();	//closes outfile and infile
	infile.close();
	return 0;
}

