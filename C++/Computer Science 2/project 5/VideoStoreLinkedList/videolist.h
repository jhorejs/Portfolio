#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "video.h"

//class data type for the VideoList object
class VideoList
{
private:
	struct Node
	{
		Video data;
		Node *next;
	};
	Node *head, *tail;
public:
	//constructor
	VideoList();
	VideoList(char fileName[]);
	//destructor
	~VideoList();
	//other list functions
	void addVideo(Video &aVideo);
	const void displayList();
	const void findVideo();
	void writeFile();
};

#endif