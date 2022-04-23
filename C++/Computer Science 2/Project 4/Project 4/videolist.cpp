//This is the implementation file for VideoList class
#include "videolist.h"
#include "tools.h"

////class data type for the VideoList object
//class VideoList
//{
//private:
//	Video list[CAP];
//	int size;
//public:
//	//constructor
//	VideoList();
//	VideoList(char fileName[]);
//	//destructor
//	~VideoList();
//	//other list functions
//	bool addVideo(const Video &aVideo);
//	const void displayList();
//	const void findVideo();
//	void delVideo();
//	void writeFile();
//};

//VideoList implementation functions
//default constructor
VideoList::VideoList()
{
	capacity = CAP;
	list = new Video[capacity];
	size = 0;
}
//constructor from file
VideoList::VideoList(char fileName[])
{
	ifstream inFile;
	Video aVideo;
	char tempTitle[MAXCHAR], tempGenre[MAXCHAR];
	int tempQty = 0;
	inFile.open(fileName);
	if (!inFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	capacity = CAP;
	list = new Video[capacity];
	size = 0;
	inFile.get(tempTitle, MAXCHAR, ';');
	while (!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> tempQty;
		inFile.ignore(5, ';');
		inFile.get(tempGenre, MAXCHAR, '\n');
		inFile.ignore(5, '\n');
		//populate aVideo with all the information
		aVideo.setTitle(tempTitle);
		aVideo.setQty(tempQty);
		aVideo.setGenre(tempGenre);
		this->addVideo(aVideo);
		inFile.get(tempTitle, MAXCHAR, ';');
	}
	inFile.close();
}

//destructor
VideoList::~VideoList()
{
	if (list)
	{
		delete[]list;
		list = NULL;
	}
}
//adds a video to the list
bool VideoList::addVideo(Video &aVideo)
{
	char tempTitle[MAXCHAR], tempGenre[MAXCHAR];
	//shallow copy!!! Dont do it
	//list[size] = aVideo;
	//do a deep copy
	//get aVideo's information
	//check to see if array is full
	if (size == capacity)
	{
		expandArray();
	}
	aVideo.getTitle(tempTitle);
	list[size].setTitle(tempTitle);
	list[size].setQty(aVideo.getQty());
	aVideo.getGenre(tempGenre);
	list[size].setGenre(tempGenre);
	size++;
	return true;
}

//prints the list
const void VideoList::displayList()
{
	for (int i = 0; i < size; i++)
	{
		list[i].printVideo();
	}
	cout << endl;
}

//finds a movie in the list
const void VideoList::findVideo()
{
	char srchTitle[MAXCHAR], tempTitle[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (int i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle);
		convertCase(tempTitle);
		if (strstr(tempTitle, srchTitle))
		{
			list[i].printVideo();
		}
	}
	cout << endl;
}

//writes the data back to the file
void VideoList::writeFile()
{
	ofstream outFile;
	outFile.open("movies.txt");
	if (!outFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	for (int i = 0; i < size; i++)
	{
		list[i].printFile(outFile);
	}
	outFile.close();
}


//function to expand array
void VideoList::expandArray()
{
	capacity += GROWTH;
	char tempTitle[MAXCHAR];
	char tempGenre[MAXCHAR];
	Video *tempList = new Video[capacity];
	for (int i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle);
		list[i].getGenre(tempGenre);
		tempList[i].setTitle(tempTitle);
		tempList[i].setQty(list[i].getQty());
		tempList[i].setGenre(tempGenre);		
	}
	delete[] list;
	list = tempList;
	tempList = NULL;
}