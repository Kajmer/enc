#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "GenWin_2.h"
// hwGU4QqEUeyy61@bSqJv$LJsY1XL9hAbD8qtY#2bqDfJWAMa9CP6bqTpfb8bBykPnQG8nHeNDytvr1J$wa6@fkDwZPSw8CguMLimWpDJcdkPd5SgeuyVGCcew8AWZrn9WQfVSBcQD2LixaZ#cmtWCX93sHKGZBcW1a8ytAcQCqDuLQjw8ksMEF$eCrBiS#Hefaj1RTrtqCeJQNTg85sg9@AgkJMJHV8MVkPaRxSydM2d4su#uZw8#3j2MpC8p2Xa$kDJsGWDw5vM2G7hwTsdS$A@N89mjvSqWWi8mJhPKZc1DQXMYxebx992CX2TjGXDhik36hegGZAiP8ciJXGv1yntEUx#KL7acduAPhRvWM4UM2Rxj2R#s6GTUQLmVUTEy4P5MWfyj9iR9dBVZp3CwXg73QMwj5m3nj585Vj836yxP@JbsASdByy3@vD9cE2KZnnuK92wRrtipLgZcKR6vknymDPAnBUF3fLH6vu5d@WukHMREg3vvStc2jENtNfq
using namespace std;
///////////////////////////
///      win-full		///
///////////////////////////
int _tmain(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus"); //need for russian text in console. for debbug purposes
	ifstream inp("book.txt"); //input file
	ofstream ou("result.txt"); // output file

	string words; // storage for user text
	// random "secret" key. Can be entered by user 
	string key_c = "U2FsdGVkX18WvMs1mBJvSDrYphweyY0LG0FnmelNRn+xaYnm+JNVPrtlgmQDFVW++dco6TgiQltzQqhc2Tw5UMTt/YRAHKPVYNJ0RG+BHwEhNr2Oz5pm+95HpZ8MGYGuQJo5lPe5nkQEoQ5htpcdYwQPtPbpmjuDu6LZv8Bb3v6FB+MgkI1uJEd5Iq4FoIbcu0DbYf3jay65XJx9SjJ+z2MN4aUH5lNXEbpkVuQByffZ7aJ1DYkZ6bzmpuKvt+cS+BoejhHl/4L+68eDwx8uhz+lemLufMBUjxRNboIHNSIPZu//r2b9l3wqRC4FY4fk2KsXhodm7D+gJsLx14NA+Hplbu/SetomOeViwsk5cHIhWoUYlGIEGz6CFQFT+HcpM4ptvoIIHS4Yhoh8J7+WsD7L2MHkCL97TeQIa/f2xKQvp6JpUxs69M+Ayjpg/fTB22OgBRXIVdNzhfdRBLU3pf/8vTqOxPxxcQDwQVCxujKwIL0copFV39N5";
	string temp_word; //read-helper

	while ( getline(inp, temp_word) ) //read
	{
		if (words.length() == 0)
			words = temp_word;
		else
			words = words + ' ' + temp_word;
	}

	GenWin msg(words, key_c, 5); //define object of class
	msg.gen(); //calling function

	words = msg.getWords()

	//Simply out.

	ou << words;

	//Output with 100 chars in one line.

	//for (int i = 0; i != words.length(); i++)
	//{
	//	ou << static_cast<unsigned char>(words[i]);

	//	if (((i+1) % 100 == 0) && (i != 0))
	//	{
	//		//ou << endl; // Сделать параметром?
	//	}
	//}
	return 0;
}