//#include "time.h"

task main()
{
	string fileBeginning="debug-";
	string date = __DATE__;
	string time = __TIME__;
	//string fileMiddle= date + "-"
	string fileMiddle = time + "-";
	string fileEnding="0";
	string fileExtention=".txt"

	string searchName = (string)fileBeginning + (string)fileMiddle;
	searchName += (string)fileEnding + (string)fileExtention;

	TFileHandle searchHandle;
	TFileIOResult searchResult;
	string searchReturnName;
	short searchFileSize;

	FindFirstFile(searchHandle, searchResult, searchName,  searchReturnName, searchFileSize);

	if (true){
		nxtDisplayCenteredTextLine(1,"%s",fileMiddle);
		nxtDisplayCenteredTextLine(3,"time: %s",time);
		nxtDisplayCenteredTextLine(5,"date: %s",date);
		nxtDisplayCenteredTextLine(7,"sN: %s",searchName);
	}
	else{
		nxtDisplayCenteredTextLine(7,"searchResult: %d",searchResult);
	}
	while (true){}
}
