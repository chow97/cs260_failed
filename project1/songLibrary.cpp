#include "songLibrary.h"

SongList::SongList()
{
    head = nullptr;
    tail = nullptr;
}

SongList::~SongList()
{
    Node * curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
}

void SongList::addSong()
{
    Node * curr = head;
    Node * newNode = new Node();
    newNode->data = 
}