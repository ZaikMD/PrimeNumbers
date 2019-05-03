/*
Made by Zach Dubuc
May 03, 2019

The purpose of this program is to find a set amount of prime numbers dictated by the user.
Will always start at 2
*/

#include "pch.h"
#include <iostream>
#include "Lab7.h"
using namespace std;
//Main
int main()
{
	Lab7 lab;
	lab.getNumberFromUser();
	lab.generatePrimes();
	lab.printPrimes();
}
//Constuctor
Lab7::Lab7()
{
	cout << "Program developed by Zach Dubuc";
	m_NumberOfPrimes = -1;
}
//Deconstructor
Lab7::~Lab7()
{
	cout << "Object being destroyed" << endl;
}
//Will ask the user for input and will no accept invalid input or negative numbers/0
void Lab7::getNumberFromUser()
{
	
	while (m_NumberOfPrimes <= 0)
	{
		cout << "How many Prime numbers would you like? ";
		cin >> m_NumberOfPrimes;
		cout << endl;

		if (m_NumberOfPrimes <= 0)
		{
			cout << "Number must be greate than 0" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}
//Will loop until the set amount of prime numbers are found
void Lab7::generatePrimes()
{
	//Will always start at 2
	m_Primes.push_back(2);
	int primeNumbers = 1;
	int current = 3;
	bool isPrime;
	//While we still have prime numbers to find
	while (primeNumbers < m_NumberOfPrimes)
	{
		isPrime = true;
		int previousPrime = 0;
		//While there are still prime numbers
		while (previousPrime < primeNumbers)
		{
			if (current % m_Primes[previousPrime] == 0)
			{
				isPrime = false;
				//Break point to stop the loop, if we ever hit false then we have no need to keep going
				break;
			}
			previousPrime += 1;
		}
		//If we did find a prime, add it to the vector
		if (isPrime)
		{
			m_Primes.push_back(current);
			primeNumbers += 1;
		}
		current += 2;
	}
}
//Loop through and print all the prime numbers
void Lab7::printPrimes()
{
	
	cout << "The first " << m_NumberOfPrimes << " prime numbers are:" << endl;
	for (int i = 0; i < m_NumberOfPrimes; i++)
	{
		cout << i+1 << "\t" << m_Primes[i] << endl;
	}
}
