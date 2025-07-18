#pragma once

#include <iostream>
#include <cstdlib>
#include "clsDate.h"


using namespace std;

class clsUtil
{

public:

	enum enCharType
	{
		SmallLetter = 1,
		CapitalLetter = 2,
		Digit = 3,
		MixChars = 4,
		SpecialCharacter = 5
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == enCharType::MixChars)
		{
			CharType = enCharType(RandomNumber(1, 3));
		}
		switch (CharType)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
			break;
		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string word = "";
		for (short i = 1; i <= Length; i++)
		{
			word += GetRandomCharacter(CharType);
		}

		return word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";

		Key += GenerateWord(CharType, 4) +
			'-' + GenerateWord(CharType, 4) +
			'-' + GenerateWord(CharType, 4) +
			'-' + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(enCharType CharType, short NumberOfKeys)
	{
		for (short i = 1; i < NumberOfKeys; i++)
		{
			cout << "Key [" << i << "]: ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	static void Swap(int& Val1, int& Val2)
	{
		int temp;
		temp = Val1;
		Val1 = Val2;
		Val2 = temp;
	}

	static void Swap(double& Val1, double& Val2)
	{
		double temp;
		temp = Val1;
		Val1 = Val2;
		Val2 = temp;
	}

	static void Swap(bool& Num1, bool& Val2)
	{
		bool temp;
		temp = Num1;
		Num1 = Val2;
		Val2 = temp;
	}

	static void Swap(char& Val1, char& Val2)
	{
		char temp;
		temp = Val1;
		Val1 = Val2;
		Val2 = temp;
	}

	static void Swap(string& Val1, string& Val2)
	{
		string temp;
		temp = Val1;
		Val1 = Val2;
		Val2 = temp;
	}

	static void Swap(clsDate& Val1, clsDate& Val2)
	{
		clsDate temp;
		temp = Val1;
		Val1 = Val2;
		Val2 = temp;
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArrayUsingFisherYatesAlgo(string arr[100], int arrLength)
	{
		for (short i = arrLength-1; i >0 ; i--)
		{
			int j = RandomNumber(0, i);
			Swap(arr[i], arr[j]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string tabs = "";
		for (short i = 1; i < NumberOfTabs; i++)
		{
			tabs += "\t";
		}

		return tabs;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (short i = 0; i <= Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (short i = 0; i <= Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) - EncryptionKey);
		}

		return Text;
	}

};



