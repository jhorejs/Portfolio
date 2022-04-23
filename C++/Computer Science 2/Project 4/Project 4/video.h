//This is a header file for the Video class
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//constants
const int MAXCHAR = 101;

//Class data type for the Video object
class Video
{
private:
	char *title;
	int qty;
	char *genre;
public:
	//constructors
	Video();
	Video(char initTitle[], int initQty, char initGenre[]);
	Video(const Video &aVideo);
	//destructor
	~Video();
	//accessor and mutator functions
	const void getTitle(char returnTitle[]);
	const int getQty();
	const void getGenre(char returnGenre[]);
	void setTitle(char newTitle[]);
	void setQty(int newQty);
	void setGenre(char newGenre[]);
	//print function
	const void printVideo();
	const void printFile(ofstream &outFile);
};
#endif