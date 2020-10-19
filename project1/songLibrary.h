#ifndef SONGLIBRARY_H
#define SONGLIBRARY_H

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class SongList 
{
    public:
        SongList();
        ~SongList();
        void addSong(char title[], char artist[], char album[], char duration[]);
        void removeSong();
        void numViews();
        void displayAllArtists();
        void displayAllSongs();

    private:
        struct Node 
        {
            char data;
            Node * next;
            Node * prev;
        };
        Node * head;
};