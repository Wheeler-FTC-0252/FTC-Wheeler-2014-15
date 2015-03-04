task main()
{
	string fileBeginning="debug-";
	string date = __DATE__;
	string time = __TIME__;
	string fileMiddle= date + time;
	fileMiddle += "-";
	string fileEnding="0";
	string fileExtention=".txt"

	string searchName = (string)fileBeginning + (string)fileMiddle;
	searchName += (string)fileEnding + (string)fileExtention;

	TFileHandle searchHandle;
	TFileIOResult searchResult;
	string searchReturnName;
	short searchFileSize;

	FindFirstFile(searchHandle, searchResult, searchName,  searchReturnName, searchFileSize);

/*	nxtDisplayCenteredTextLine(1,"fM: %s",fileMiddle);
	nxtDisplayCenteredTextLine(3,"time: %s",time);
	nxtDisplayCenteredTextLine(5,"date: %s",date);
	nxtDisplayCenteredTextLine(7,"sN: %s",searchName);*/
	nxtDisplayCenteredTextLine(7,"searchResult: %d",searchResult);
	while (true){}
}
