task main()
{
	string fileBeginning="debug-";
	string fileMiddle= (string)__DATE__ + (string)__TIME__ + "-";
	string fileEnding=0;
	string fileExtention=".txt"

	string searchName = (string)fileBeginning + (string)fileMiddle + (string)fileEnding + (string)fileExtention;

	TFileHandle searchHandle;
	TFileIOResult searchResult;
	string searchReturnName;
	short searchFileSize;

	FindFirstFile(searchHandle, searchResult, searchName,  searchReturnName, searchFileSize);

	nxtDisplayCenteredTextLine(3,"%d",searchName);
	while (true){}
}
