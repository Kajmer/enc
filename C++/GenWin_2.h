#include "stdafx.h"
#include <string>
using namespace std;

#ifndef GEN_H

class GenWin
{
public:
	GenWin(string words,
		string key_c = "yNBLuEPKQhhkpLm@qkLQ5#8c9J8V9whrZ1ZS3d3LJhPe4f2pNuxcW76MpEGcDA#VMHSRShBkZBN@MPswBkYeLVUGbpqjT$dE7VAat6GJRKJhfmTuwvreYFN399VsDB#JnEpC#6jhTsCFU9kMfC4QH1HNnMegg53bskBLhVV6W1MFQ9xheP6urU1R7hWCFZpvdXRQSZhF2Qq94KAYJAjmnUkB3MuZA89XqAD1h@gpasGc73xEKbwi#hPbFwGnGh2ri33EAGp3H85Y#iwp$vC#KkYpGjwmdV96A$XwNJt9A6EExqq1#DAyrw5esQqukeYtLDfHsacKQLM5m9#8JtcRsPmvdDP94AW2eTHkg9pTMTtHh1vxV$7LkWMXUm2sKdM7sCdEKx$#nxmjU3@gLsfefZ1Z3JYcMVvuDEUwjPibZ$1RSKuwAWCeU$DLxskdDiP8iiCwRBatkJycg211f4n3cjZQdHaE9QXqnsRZ75a#RHn27yMq7fwW#GqjiZ4KGeng", 
		unsigned short level = 1);

	void gen();
	void DeGen();

	string getWords() const;


private:
	string words, key_c;
	unsigned short level;


};

#endif