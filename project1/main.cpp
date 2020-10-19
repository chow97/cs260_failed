// Name : Chow

#include "songLibrary.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	char cmd;
	char fileName[] = "songs.txt";
	SongList * sl = new SongList();
	loadMusicLibrary(fileName, sl);
	while(true){
		displayMenu(sl);
	}
	ofstream out;
	out.open(fileName);
	sl->printSongListToFile(&out);
	out.close();
	delete sl;

	return 0;
}
