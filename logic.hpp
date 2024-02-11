#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
std::string dec(std::string data)
{
	int key = data[0] - 'A' + 1;
	int n = data.size();
	for (int i = 1; i < n; i++)
	{
		data[i] = data[i] - key;
	}
	return data;
}
std::string enc(std::string data)
{
	int key = data[0] - 'A' + 1;
	int n = data.size();
	for (int i = 1; i < n; i++)
	{
		data[i] = data[i] + key;
	}
	return data;
}
void writer(std::string file, std::string s)
{
	std::ofstream outputFile(file, std::ios::app | std::ios::out);

	if (outputFile.is_open())
	{
		outputFile << s << "\n";
		outputFile.close();
	}
	else
	{
		std::cout << "\n\033[31m\tSome Error occured while opening file! \n\tMake sure the filename is correct and have .txt extension.\033[0m\n";
	}
	outputFile.close();
	std::cout << "\033[0m";
}
short reader(std::string file, short op)
{
	std::fstream new_file;
	new_file.open(file, std::ios::in);
	if (new_file.is_open())
	{
		if (op == 1)
		{
			std::string s;
			while (getline(new_file, s))
			{
				s = enc(s);
				writer("encrypt.txt", s);
			}
		}
		else if (op == 2)
		{
			std::string s;
			while (getline(new_file, s))
			{
				s = dec(s);
				writer("decrypt.txt", s);
			}
		}
	}
	else
	{
		std::cout << "\n\t\033[31mSome Error occured while opening file! \n\tMake sure the filename is correct and have .txt extension.\033[0m\n";
		return 0;
	}
	new_file.close();
	std::cout << "\033[0m";
	return 1;
}
void runner()
{
	short choice = 1;
	std::cout << "\033[1m";
	std::cout << "\n\t\033[4mWelcome to File Encryption and Decryption.\n\tYou can encrypt and decrypt text files easily.\n\tMake sure to use correct names for files.\033[0m\n";
	do
	{
		std::cout << "\n\tChoose your operation:\n";
		std::cout << "\t1) Encrypt a text file\n";
		std::cout << "\t2) Decrypt a text file\n";
		std::cout << "\t3) Close\n\n\t>\033[34m";
		std::cin >> choice;
		std::string file;
		if (choice == 1)
		{
			std::cout << "\n\t\033[0mEnter file-name : \n\t>\033[34m";
			std::cin >> file;
			if (reader(file + ".txt", choice))
			{
				std::cout << "\n\t\033[3;104;30mFile Encrypted Successfully with name 'encrypt.txt'\033[0m\n";
			}
		}
		else if (choice == 2)
		{
			std::cout << "\n\t\033[0mEnter file-name : \n\t>\033[34m";
			std::cin >> file;
			if (reader(file + ".txt", choice))
			{
				std::cout << "\n\t\033[3;104;30mFile Decrypted Successfully with name 'decrypt.txt'\033[0m\n";
			}
		}
		else if (choice == 3)
		{
			std::cout << "\n\033[35mKeep your files safe from others :)\n\033[0m";
			break;
		}
		else
		{
			std::cout << "\n\t\033[33mChoose a valid operation!\033[0m\n";
		}
	} while (choice != INT_MIN);
	getch();
}
