#ifndef SONGLIBRARY_H
#define SONGLIBRARY_H

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;
                                            
class Song {
    public:
        Song(char title[], char artist[], char views[], char likes[], char length[]);
        ~Song();
        void printToConsole() const;
        void printToFile(ofstream *file) const;
        bool matchesArtist(char *artistValue) const;
        bool matchesviews(char *viewsValue) const;
    private:
        char *title;
        char *artist;
        char *views;
        char *likes;
        char *length;
		
};

class SongList {
    public:
        SongList();
        ~SongList();
        void insertSong(char title[], char artist[], char views[], char likes[], char length[]);
        void removeSong(int index);
        void printSongListToConsole();
        void printSongListToFile(ofstream *file);
        void searchByArtist(char artist[]);
        void searchByviews(char views[]);
    private:
//        Song *songs[100];
        int numSongs;
		struct Node {
			Song *track;
			Node *next;
		};
		Node *head;
};

void searchviews(SongList * sl);
void searchArtist(SongList * sl);
void displayMenu(SongList * sl);
void loadMusicLibrary(const char fileName[], SongList * sl);
void removeSongByIndex(SongList * sl);
void addSong(SongList * sl);
#endif