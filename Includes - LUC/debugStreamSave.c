bool debugFlag = false;

TFileHandle saveFileInit(){//run this at the beginning before using the functions below

	bool fileNameFound=false;

	string fileName;
	string fileBeginning="d";
	string time ;
	sprintf( time , "%03d" , nClockMinutes);
	string date = "150307";
	string fileMiddle = date + "-";
	fileMiddle += time;
	int fileEnding= rand() % 1000  ;
	string fileEndingString;
	string fileExtention=".txt";

	TFileHandle searchHandle;
	TFileIOResult searchResult;
	string searchReturnName;
	short searchFileSize;
	string searchName;

	while (!fileNameFound){
		string searchName = (string)fileBeginning + (string)fileMiddle;
		sprintf(fileEndingString , "%03d",fileEnding);
		searchName += fileEndingString;
		searchName += (string)fileExtention;

		FindFirstFile(searchHandle, searchResult, searchName,  searchReturnName, searchFileSize);
		if (searchResult!=0){
			fileName=searchName;
			fileNameFound=True;
		}
		else
				fileEnding++;
	}

//	fileName = "bollox.txt";


	TFileIOResult IoResult;
	TFileHandle FileHandle;
	short FileSize = 1000000;

	if(debugFlag){writeDebugStreamLine( "Write to Filename: %s" , fileName );}
	OpenWrite(FileHandle, IoResult, fileName, FileSize);
	// nIoResult is non-zero when an error occurs.
	if(debugFlag){writeDebugStreamLine( "OpenWrite IoResult: %d" , IoResult );}
	if(debugFlag){writeDebugStreamLine( "OpenWrite FileHandle: %d" , FileHandle );}
	//nxtDisplayBigTextLine(3, "%d", IoResult);
	//while(true){}
	return FileHandle;
}

void writeDebugStreamSaveMain(char * saveText, TFileHandle FileHandle, bool carrageReturn){
	TFileIOResult IoResult;
	//TFileHandle FileHandle;
	short FileSize = 100;
	//word FileSize;
	//const char * debugSaveFile="debugSave.txt";

	//short stringLength = sizeof(saveText);


	//OpenWrite(FileHandle, IoResult, debugSaveFile, FileSize);

	if(debugFlag){writeDebugStreamLine( "SAVE MAIN" );}

	WriteText(FileHandle, IoResult, saveText);
	if (carrageReturn){//newline
		WriteText(FileHandle, IoResult, "\n");

		//writeDebugStreamLine(saveText);
		if(debugFlag){
			writeDebugStreamLine("made a new line");
		}
	}
	else{
		//writeDebugStream(saveText);
	}

	if(debugFlag){
		writeDebugStreamLine("writing: %s", saveText);
	}
	//Close(FileHandle, IoResult);
}

void writeDebugStreamLineSave(char * saveText, TFileHandle FileHandle){
	writeDebugStreamSaveMain(saveText, FileHandle, true);
}

void writeDebugStreamSave(char * saveText, TFileHandle FileHandle){
	writeDebugStreamSaveMain(saveText, FileHandle, false);
}
