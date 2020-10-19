#include "songLibrary.h"
#include <iomanip>

using namespace std;

const int MAX = 100;

Song::Song(char title[], char artist[], char views[],char likes[], char length[]) {
	this->title = new char[strlen(title) + 1]; //Allocating memory to char array
	strcpy(this->title, title); //target, then source
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);
	this->views = new char[strlen(views) + 1];
	strcpy(this->views, views);
    this->likes = new char[strlen(likes) + 1];
	strcpy(this->likes, likes);
	this->length = new char[strlen(length) + 1];
	strcpy(this->length, length);
}
Song::~Song(){
	delete title;
	delete artist;
	delete views;
    delete likes;
	delete length;
}

void Song::printToConsole() const{
	cout << setw(20) << title << setw(20) << artist << setw(20) << length << setw(20) << views << setw(20) << likes << endl;
}

void Song::printToFile(ofstream *file) const{
		*file << title << ';' << artist << ';' << length << ';' << views << ';' << likes << endl;
}

bool Song::matchesArtist(char *artistValue) const{
	return strcmp(artistValue, artist) == 0;
}
/*
bool Song::matchesviews(char *viewsValue) const{
	return strcmp(viewsValue, views) == 0;
}
*/
SongList::SongList(){
	numSongs = 0;
	head = new Node();
	head->next = nullptr;
}

SongList::~SongList(){
	Node * curr = head;
	while(head != nullptr){
		curr = head->next;
		delete head;
		head = curr;
	}
}

void SongList::insertSong(char title[], char artist[], char views[], char likes[], char length[]){
	Node * newNode = new Node();
	newNode->track = new Song(title, artist, views, likes, length);
	newNode->next = head->next;
	head->next = newNode;
	SongList::numSongs++;
}

void SongList::removeSong(int index){
	if(index > numSongs){
		return;
	}
	Node * current = head;
	int counter = 1;
	while(current != nullptr && counter < index){
		current = current->next;
		counter++;
	}
	Node * temp = current->next;
	current = current->next->next;
	delete temp;
}
void SongList::printSongListToConsole(){
	int index = 1;
	cout << setw(10) << "Index" << setw(20) << "Title" << setw(20) << "Artist" << setw(20) << "length" << setw(20) << "views" << setw(20) << "likes" << endl;
	Node * current = head->next;
	while(current != nullptr){
		cout << setw(10) << index;
		current->track->printToConsole();
		current = current->next;
		index++;
	}
}

void SongList::printSongListToFile(ofstream *file){
	Node * current = head->next;
	while(current != nullptr){
		current->track->printToFile(file);
		current = current->next;
	}
}

void SongList::searchByArtist(char artist[]){
	Node * current = head->next;
	while(current != nullptr){
		if(current->track->matchesArtist(artist)){
			current->track->printToConsole();
		}
		current = current->next;
	}
}

void SongList::searchByviews(char views[]){
	Node * current = head->next;
	while(current != nullptr){
		if(current->track->matchesviews(views)){
			current->track->printToConsole();
		}
		current = current->next;
	}
}

void searchArtist(SongList * sl){
	char artistValue[MAX];
	cout << "Please enter the Artist's name: ";
	cin.get(artistValue, MAX, '\n');
	sl->searchByArtist(artistValue);
}

void searchviews(SongList * sl){
	char viewsValue[MAX];
	cout << "Please enter the views's name: ";
	cin.get(viewsValue, MAX, '\n');
	sl->searchByviews(viewsValue);
}
void removeSongByIndex(SongList * sl){
	int index;
	cout << "Enter the index of the Song you want to delete: ";
	cin >> index;
	sl->removeSong(index);
}
void displayMenu(SongList * sl)
{
	cout << endl << "Welcome to your music library!" << endl << endl;
	cout << "Choose from the following options: " << endl;
	cout << "\t1. Add an entry" << endl;
	cout << "\t2. List all entries" << endl;
	cout << "\t3. Search Songs by Artist name" << endl;
	cout << "\t4. Search Songs by views name" << endl;
	cout << "\t5. Remove song by index" << endl;
	cout << "\tq. Exit this program" << endl << endl;
	char cmd;

	cout << endl << "Please enter command(1, 2, 3, 4 or q): ";
	cin >> cmd;
	cin.ignore(100, '\n');
	switch(cmd){
		case '1': 
			addSong(sl);
			break;

		case '2': 
			sl->printSongListToConsole();
			break;

		case '3': 
			searchArtist(sl);
			break;

		case '4':
			searchviews(sl);
			break;
	
		case '5':
			removeSongByIndex(sl);
			break;

		case 'q':
			cout << endl <<  "Thank you" << endl << endl;
			exit(0);

		default: 
			cout << endl << "Wrong Input!" << endl;
			break;
	}
}

void addSong(SongList * sl){
	char title[MAX];
	char artist[MAX];
	char length[MAX];
	char views[MAX];
	cout << "What is the title of the song: ";
	cin.get(title, MAX, '\n');
	cin.ignore(MAX, '\n');
	cout << "What is the Artist's name: ";
	cin.get(artist, MAX, '\n');
	cin.ignore(MAX, '\n');
	cout << "What is the length of the song: ";
	cin.get(length, MAX, '\n');
	cin.ignore(MAX, '\n');
	cout << "What is the views name: ";
	cin.get(views, MAX, '\n');
	cin.ignore(MAX, '\n');
	sl->insertSong(title, artist, views, length);
}

void loadMusicLibrary(const char fileName[], SongList * sl){
	ifstream in;
	char title[MAX];
	char artist[MAX];
	char length[MAX];
	char views[MAX];

	in.open(fileName);
	if(!in)
	{
		in.clear();
		cerr << endl << "Fail to open " << fileName << " for input!" << endl << endl;
		exit(1);
	}
	in.get(title, MAX, ';');
	while(!in.eof())
	{
		in.get();
		in.get(artist, MAX, ';');

		in.get();
		in.get(length, MAX, ';');

		in.get();	
		in.get(views, MAX, '\n');
		in.ignore(MAX, '\n');

		sl->insertSong(title, artist, views, length);

		in.get(title, MAX, ';');
	}
	in.close();
}