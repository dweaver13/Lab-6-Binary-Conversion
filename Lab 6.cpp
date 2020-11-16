// Dale Weaver
// C++ Fall 2020
// Due: November 16th 2020
// The object of this lab is to recieve binary from a file and then output them as readable numbers.
// There should be a binary numer as well as decimal number.
// The code should also reject any invalid inputs

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

using namespace std;
// This allows me to use certain void functions later
void fileReader(ifstream& inFile, char& input);
void binaryInput(ifstream& inFile, char input, unsigned int& decimal, int& binary, bool& valid);
void openFile(ifstream& inFile, ifstream& inFileTwo);
void binaryOutput(int, bool, char, ifstream& inFileTwo);
void outDecimal(unsigned int);

int main()
{
	char input;
	bool valid;
	int binary;
	unsigned int decimal;
	ifstream inFile;
	ifstream inFileTwo;

	openFile(inFileTwo, inFile); // opens users file
	cout << "	Binary Number			Decimal Equivalent" << endl; //prints the header
	fileReader(inFile, input); // calls file reader function
	while (inFile)
	{
		binaryInput(inFile, input, decimal, binary, valid); //calls function binaryInput
		binaryOutput(binary, valid, input, inFileTwo); // calls function binaryOutput

		if (valid) // makes sure validity
			outDecimal(decimal); 
		fileReader(inFile, input);
	}
	return 0; //ends
}

void fileReader(ifstream& inFile, char& input)
{
	inFile >> input;
	while (inFile && input != '1' && input == ' ' || input == '0') // reads users input is in1's and 0's
	{
		inFile.get(input); // gets users file
	}
}
void binaryInput(ifstream& inFile, char input, unsigned int& decimal, int& binary, bool& valid)
{
	decimal = 0; //base value
	binary = 0; //base value
	valid = true;

	while (inFile && input != '\n') //makes the program read one line at a time
	{
		switch (input) //calculates decimal and checks validity
		{
		case '1': decimal = (decimal * 2) + 1;
			break;
		case '0': decimal = (decimal * 2) + 0;
			break;
		default: valid = false;
		}
		binary++; //increases by 1
		inFile.get(input); //reads next line
	}
}
void openFile(ifstream& inFile, ifstream& inFileTwo)
{
	string BinIn = "C:/Users/WEAVER41/Desktop/Coding/Lab 6/BinIn.txt"; //users file
	inFile.open(BinIn); //opens ifstream
	if (!inFile)
	{
		cout << "Please ener a valid file";
		abort(); //closes program if file is not valid
	}
	inFileTwo.open(BinIn); //opens second ifstream
}
void binaryOutput(int binary, bool valid, char input, ifstream& inFileTwo)
{
	int lengthBinary; //sores the binary length

	if (binary % 2 == 0) // Width based on binary size
		lengthBinary = ((binary) / -2) + 18;
	else
		lengthBinary = ((binary) / -2) + 17;
	if (valid)
		cout << setw(lengthBinary); //outputs width
	inFileTwo.ignore(200, '1'); //ignores unless first didgit of binary
	input = '1';

	while (inFileTwo && input != '\n') //utputs on binary num at a time
	{
		if (valid) //stops at end of file
			cout << input;
		inFileTwo.get(input);
	}

	if (valid)
	{
		cout << setw(lengthBinary); //outputs binary
		cout << "\t";
	}
	else
	{
		cout << "		Bad digit in input " << endl; //displays message if invalid
	}
}
void outDecimal(unsigned int decimal)
{
	int width; //amount of char outputted before decimal
	int size; //amount of characters of decimal
	unsigned int decimal2; //copy

	size = 0; //base number set to 0

	decimal2 = decimal; //makes copy

	while (decimal2 >= 1)
	{
		decimal2 /= 10; //size is calculated
		size++;
	}
	if (size % 2 == 0)
	{
		width = ((size) / -2) + 6; //width is calculated based on decimal size
	}
	else
	{
		width = ((size) / -2) + 5; 
	}
	for (width; width > 0; width--) //spaces are outputted
	{
		cout << " ";
	}
	cout << decimal << endl; //displays decimal
}