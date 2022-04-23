//This is the implememtation file for video.h
#include "video.h"

/*Class data type for the Video object
class Video
{
private:
	char title[MAXCHAR];
	int qty;
	char genre[MAXCHAR];
public:
	//constructors
	Video();
	Video(char initTitle[], int initQty, char initGenre[]);
	//accessor and mutator functions
	const void getTitle(char returnTitle[]);
	const int getQty();
	const void getGenre(char returnGenre[]);
	void setTitle(char newTitle[]);
	void setQty(int newQty);
	void setGenre(char newGenre[]);
	//print function
	const void printVideo();
};*/

//constructors
//default constructor
Video::Video()
{
	//allocate memory
	title = new char[MAXCHAR];
	strcpy_s(title, MAXCHAR, "No Title");
	qty = 0;
	genre = new char[MAXCHAR];
	strcpy_s(genre, MAXCHAR, "No Genre");
}

//constructor with parameters
Video::Video(char newTitle[], int newQty, char newGenre[])
{
	title = new char[strlen(newTitle) + 1];
	strcpy_s(title, strlen(newTitle) + 1, newTitle);
	qty = newQty;
	genre = new char[strlen(newGenre) + 1];
	strcpy_s(genre, strlen(newGenre) + 1, newGenre);
}
//Copy Constructor
Video::Video(const Video &aVideo)
{
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	title = new char[strlen(aVideo.title) + 1];
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
	genre = new char[strlen(aVideo.genre) + 1];
	//use the assignment operator
	*this = aVideo;
}
//destructor
Video::~Video()
{
	//deallocate mem for title and genre
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
}

//accessor and mutator functions
//accessor functions
const void Video::getTitle(char returnTitle[])
{
	strcpy_s(returnTitle, MAXCHAR, title);
}
const int Video::getQty()
{
	return qty;
}
const void Video::getGenre(char returnGenre[])
{
	strcpy_s(returnGenre, MAXCHAR, genre);
}
//mutator functions
void Video::setTitle(char newTitle[])
{
	if (title)
	{
		delete[] title;
		title = NULL;
	}
	title = new char[strlen(newTitle) + 1];
	strcpy_s(title, strlen(newTitle) + 1, newTitle);
}
void Video::setQty(int newQty)
{
	qty = newQty;
}
void Video::setGenre(char newGenre[])
{
	if (genre)
	{
		delete[] genre;
		genre = NULL;
	}
	genre = new char[strlen(newGenre) + 1];
	strcpy_s(genre, strlen(newGenre) + 1, newGenre);
}


//print function to file
const void Video::printFile(ofstream &outFile)
{
	outFile << title << ';' << qty << ';' << genre << endl;
}
//assignment operator overloaded
const Video& Video::operator= (const Video& aVideo)
{
	//if it is a self copy, don't do anything
	if (this == &aVideo)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		strcpy_s(this->title, strlen(aVideo.title) + 1, aVideo.title);
		this->qty = aVideo.qty;
		strcpy_s(this->genre, strlen(aVideo.genre) + 1, aVideo.genre);

		return *this;
	}
}

//extraction operator << overloaded
ostream& operator<< (ostream& out, const Video& aVideo)
{
	out << aVideo.title << ';' << aVideo.qty << ';' << aVideo.genre << endl;
	return out;
}