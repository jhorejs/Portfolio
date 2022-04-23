#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "video.h"
//constants
const int CAP = 5;
const int GROWTH = 3;
//class data type for the VideoList object
class VideoList
{
private:
	Video *list;
	int size;
	int capacity;
	//function to expand array
	void expandArray();
public:
	//constructor
	VideoList();
	VideoList(char fileName[]);
	//destructor
	~VideoList();
	//other list functions
	bool addVideo(Video &aVideo);
	const void displayList();
	const void findVideo();
	void writeFile();
};

#endif