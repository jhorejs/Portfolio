//This is the implementation file for VideoList class
#include "videolist.h"
#include "tools.h"

////class data type for the VideoList object
//class VideoList
//{
//private:
//	struct Node
//	{
//		Video data;
//		Node *next;
//	};
//	Node *head, *tail;
//public:
//	//constructor
//	VideoList();
//	VideoList(char fileName[]);
//	//destructor
//	~VideoList();
//	//other list functions
//	bool addVideo(Video &aVideo);
//	const void displayList();
//	const void findVideo();
//	void writeFile();
//};

//VideoList implementation functions
//default constructor
VideoList::VideoList()
{
	head = NULL;
	tail = NULL;
}
//constructor from file
VideoList::VideoList(char fileName[])
{
	ifstream inFile;
	Video aVideo;
	char tempTitle[MAXCHAR], tempGenre[MAXCHAR];
	int tempQty = 0;
	//set head and tail to NULL
	head = NULL;
	tail = NULL;
	inFile.open(fileName);
	if (!inFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}

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
	Node *curr = head;
	while (head)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
	head = NULL;
	curr = NULL;
}
//adds a video to the list
void VideoList::addVideo(Video &aVideo)
{
	Node *newNode, *curr, *prev;
	char tempTitle1[MAXCHAR], tempTitle2[MAXCHAR];

	//Build the list sorted - add at the right position
	//allocate memory for newNode
	newNode = new Node;
	//populate newNode-assignment operator overloaded
	newNode->data = aVideo;
	newNode->next = NULL;
	//check if new list
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		curr = head;
		prev = NULL;
		curr->data.getTitle(tempTitle1);
		newNode->data.getTitle(tempTitle2);
		//move prev and curr to the right position
		while (curr && strcmp(tempTitle1, tempTitle2) < 0)
		{
			prev = curr;
			curr = curr->next;
			curr->data.getTitle(tempTitle1);
		}
		if (!curr)			//we are at the end of the list, so add to tail
		{
			tail->next = newNode;
			tail = newNode;
		}
		else
		{
			//insert between 2 nodes
			if (prev)
			{
				prev->next = newNode;
				newNode->next = curr;
			}
			else
			{
				newNode->next = head;
				head = newNode;
			}
		}
	}

}


//prints the list
const void VideoList::displayList()
{
	Node *curr;
	for (curr = head; curr; curr = curr->next)
	{
		cout << curr->data;
	}
	cout << endl;
}

//finds a movie in the list
const void VideoList::findVideo()
{
	Node *curr;
	char srchTitle[MAXCHAR], tempTitle[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (curr = head; curr; curr = curr->next)
	{
		curr->data.getTitle(tempTitle);
		convertCase(tempTitle);
		if (strstr(tempTitle, srchTitle))
		{
			cout << curr->data;
		}
	}
	cout << endl;
}

//writes the data back to the file
void VideoList::writeFile()
{
	ofstream outFile;
	Node *curr;
	outFile.open("movies.txt");
	if (!outFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
	for (curr = head; curr; curr = curr->next)
	{
		curr->data.printFile(outFile);
	}
	outFile.close();
}
