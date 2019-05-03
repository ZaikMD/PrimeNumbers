#pragma once
/*
Made by Zach Dubuc
May 03, 2019

The purpose of this program is to find a set amount of prime numbers dictated by the user.
Will always start at 2. This is the header file
*/
#include<vector>
class Lab7
{
public:
	Lab7();
	~Lab7();

	void getNumberFromUser();
	void generatePrimes();
	void printPrimes();

private:
	int m_NumberOfPrimes;
	//Using a vector because arrays were being a bit tricky in terms of initializing it without a set size as we get size from the user later on.
	std::vector<int> m_Primes;
};