#include "stdafx.h"
#include "GenWin_2.h"

//GenWin::GenWin(words, key_c, level)
GenWin::GenWin(
	string InWords,
	string InKey, 
	unsigned short InLevel):words(InWords), key_c(InKey), level(InLevel)
{}

void GenWin::gen()
{
	for (int nk = 0; nk != level; nk++) //iterations of encoding
	{
		int mode = 64; //use to define range of symbols. See ASCII table (32 + X)
////////////////////////
		string buff;
		buff = words.substr(0, 5);
////////////////
		{
			int temp = static_cast<int>(static_cast<unsigned char>(words[i]));
			char prevWord;
			if (i != 0) prevWord = words[i]; 
			
			if (i != 0 && i != (words.length() - 1)) 
				temp = 32 + (words.length() + temp + static_cast<int>(static_cast<unsigned char>(key_c[i%key_c.length()])) + static_cast<int>(static_cast<unsigned char>(prevWord)) + static_cast<int>(static_cast<unsigned char>(words[i+1])) ) % 64;
			else
				if (i != 0 && i == (words.length() - 1)) 
					temp = 32 + (words.length() + temp + static_cast<int>(static_cast<unsigned char>(key_c[i%key_c.length()])) + static_cast<int>(static_cast<unsigned char>(prevWord))) % 64;
				else
					temp = 32 + (words.length() + temp + static_cast<int>(static_cast<unsigned char>(key_c[i%key_c.length()])) + static_cast<int>(static_cast<unsigned char>(words[i+1]))) % 64;
		
			words[i] = static_cast<char>(temp);
		}
	}
}

void GenWin::DeGen()
{
	//Any ideas?
}

string GenWin::getWords() const
{
	return words;
}
