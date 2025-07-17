# 🛠️ Project_1_Utility_Library – A C++ Utility Class for Randomization, Swapping, Encryption and More

`Project_1_Utility_Library` is a highly versatile utility project in C++ that provides a reusable class `clsUtil` under the `Project_1_Utility_Library` solution and project name. It includes helper functions for generating random data, manipulating arrays, swapping values, formatting output, and encrypting/decrypting text. This library is ideal for accelerating development in competitive programming, testing utilities, or as part of larger C++ projects.

---

## 📦 Features

* 🎲 Random number generation with custom range
* 🔤 Random character and word generation with multiple character types
* 🔐 Simple Caesar-style encryption/decryption system
* 🔁 Swap overloads for various types: `int`, `double`, `bool`, `string`, `char`, `clsDate`
* 🔄 Array operations: filling, shuffling, key generation
* 🔡 Serial key generation in `XXXX-XXXX-XXXX-XXXX` format
* 🧪 Fisher-Yates algorithm-based shuffling for better randomness
* 🧱 Utility for tab spacing in console output

---

## ⚙️ Enum: `enCharType`

```cpp
enum enCharType {
    SmallLetter = 1,
    CapitalLetter = 2,
    Digit = 3,
    MixChars = 4,
    SpecialCharacter = 5
};
```

Specifies the character set to use for random generation.

---

## 🔧 Core Methods

### 🎲 Randomization

| Method                                         | Description                                              |
| ---------------------------------------------- | -------------------------------------------------------- |
| `Srand()`                                      | Seeds the RNG using current system time                  |
| `RandomNumber(int From, int To)`               | Returns a random integer between From and To (inclusive) |
| `GetRandomCharacter(enCharType)`               | Returns a character randomly from the selected category  |
| `GenerateWord(enCharType, short Length)`       | Generates a word composed of random characters           |
| `GenerateKey(enCharType)`                      | Generates a serial key string                            |
| `GenerateKeys(enCharType, short NumberOfKeys)` | Outputs multiple serial keys                             |

### 🧮 Arrays

| Method                                                    | Description                                             |
| --------------------------------------------------------- | ------------------------------------------------------- |
| `FillArrayWithRandomNumbers(arr, length, from, to)`       | Populates an integer array with random values           |
| `FillArrayWithRandomWords(arr, length, type, wordLength)` | Populates string array with random words                |
| `FillArrayWithRandomKeys(arr, length, type)`              | Populates string array with serial keys                 |
| `ShuffleArray(arr, length)`                               | Shuffles elements in integer/string arrays              |
| `ShuffleArrayUsingFisherYatesAlgo(arr, length)`           | Uses Fisher-Yates for optimal shuffling (string arrays) |

### 🔁 Swapping

Swap values of two variables of matching types:

* Supported: `int`, `double`, `bool`, `char`, `string`, `clsDate`

### 🔐 Encryption

| Method                                | Description                        |
| ------------------------------------- | ---------------------------------- |
| `EncryptText(string text, short key)` | Encrypts using Caesar cipher logic |
| `DecryptText(string text, short key)` | Decrypts using Caesar cipher logic |

### 🔠 Formatting

| Method                     | Description                                              |
| -------------------------- | -------------------------------------------------------- |
| `Tabs(short NumberOfTabs)` | Returns a string of tab characters for output formatting |

---

## 🚀 Example Usage

```cpp
#include "clsUtil.h"
#include <iostream>

int main() {
  clsUtil::Srand();

cout << clsUtil::RandomNumber(1, 10) << endl;
cout << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;
cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;
cout << clsUtil::GenerateKey(clsUtil::MixChars) << endl;
clsUtil::GenerateKeys(clsUtil::MixChars, 10);

cout << "\n";

//Swap Int
int x = 10, y = 20;
cout << x << " " << y << endl;
clsUtil::Swap(x, y);
cout << x << " " << y << endl << endl;

//Swap double
double a = 10.5, b = 20.5;
cout << a << " " << b << endl;
clsUtil::Swap(a, b);
cout << a << " " << b << endl << endl;

//Swap String
string s1 = "Ali", s2 = "Ahmed";
cout << s1 << " " << s2 << endl;
clsUtil::Swap(s1, s2);
cout << s1 << " " << s2 << endl << endl;

//Swap Dates
clsDate d1(1, 10, 2022), d2(1, 1, 2022);
cout << d1.DateToString() << " " << d2.DateToString() << endl;
clsUtil::Swap(d1, d2);
cout << d1.DateToString() << " " << d2.DateToString() << endl;

//Shuffl Array

//int array
int Arr1[5] = { 1,2,3,4,5 };
clsUtil::ShuffleArray(Arr1, 5);
cout << "\nArray after shuffle:\n";
for (int i = 0; i < 5; i++)
{
	cout << Arr1[i] << endl;
}

//string array
string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
clsUtil::ShuffleArray(Arr2, 5);
cout << "\nArray after shuffle:\n";
for (int i = 0; i < 5; i++)
{
	cout << Arr2[i] << endl;
}

int Arr3[5];
clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
cout << "\nArray after fill:\n";
for (int i = 0; i < 5; i++)
{
	cout << Arr3[i] << endl;
}


string Arr4[5];
clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixChars, 8);
cout << "\nArray after fill:\n";
for (int i = 0; i < 5; i++)
{
	cout << Arr4[i] << endl;
}


string Arr5[5];
clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixChars);
cout << "\nArray after filling keys:\n";
for (int i = 0; i < 5; i++)
{
	cout << Arr5[i] << endl;
}

cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";

const short EncryptionKey = 2; //this is the key.

string TextAfterEncryption, TextAfterDecryption;
string Text = "Mohammed Abu-Hadhoud";
TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

cout << "\nText Before Encryption : ";
cout << Text << endl;
cout << "Text After Encryption  : ";
cout << TextAfterEncryption << endl;
cout << "Text After Decryption  : ";
cout << TextAfterDecryption << endl;
    return 0;
}
```

---

## 📁 File Structure

```
📁 Project_1_Utility_Library/
├── clsUtil.h         → Header file with the utility class
├── main.cpp          → Demonstration file
├── README.md         → Project documentation
```

---

## ⚠️ Implementation Notes

* Ensure `#include <ctime>` is used for `time()`

---

## 📚 Related Projects

### clsDate
A C++ utility class for handling date operations, including date arithmetic, validation, and formatting. This library is used within Project_1_Utility_Library for the clsDate type in swap operations.

🔗 [clsDate GitHub Repository](https://github.com/doctordev-devcode/clsDate)

---

## 👨‍💻 Author

**Doctor Dev**  
📍 Egypt  
🧠 Software Engineer | C++ Utility Toolkit Developer  
📧 [My Email](mailto:9abdelhamid080@gmail.com)

---

## 🔗 GitHub Repository

```
[Add GitHub repository link here]
```

---

This utility project under the `Project_1_Utility_Library` solution is flexible and extendable. Great for C++ learners, utility library designers, and developers needing reusable helper functions.#
