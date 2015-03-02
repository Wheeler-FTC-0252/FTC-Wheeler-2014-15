TFileHandle saveFileInit(){//run this at the beginning before using the functions below
	bool fileNameFound=False;
	string fileName;
	string fileBeginning="debug-";
	string fileMiddle=__DATE__;
	fileMiddle += __TIME__;
	fileMiddle += "-"
	string fileEnding=0;
	string fileExtention=".txt"

	TFileHandle searchHandle;
	TFileIOResult searchResult;
	string searchReturnName;
	short searchFileSize;
	string searchName;

	while (!fileNameFound){
		fileEnding++;
		searchName = fileBeginning;
		searchName += fileMiddle;
		searchName += fileEnding;
		searchName += fileExtention;

		FindFirstFile(searchHandle, searchResult, searchName,  searchReturnName, searchFileSize) ;
		if (searchResult==0){
			fileName=searchName;
			fileNameFound=True;
		}
	}


	TFileIOResult IoResult;
	TFileHandle FileHandle;
	short FileSize = 100;

	OpenWrite(FileHandle, IoResult, fileName, FileSize);
	return FileHandle
}

void writeDebugStreamSaveMain(char * saveText, bool carrageReturn){
	TFileIOResult IoResult;
	TFileHandle FileHandle;
	short FileSize = 100;
	//word FileSize;
	const char * debugSaveFile="debugSave.txt";

	//short stringLength = sizeof(saveText);


	OpenWrite(FileHandle, IoResult, debugSaveFile, FileSize);

	if (carrageReturn){//newline
		WriteString(FileHandle, IoResult, "\n");
		writeDebugStreamLine(saveText);
	}
	else{
		writeDebugStream(saveText);
	}

	WriteString(FileHandle, IoResult, saveText);
	Close(FileHandle, IoResult);
}

void writeDebugStreamLineSave(char * saveText){
	writeDebugStreamSaveMain(saveText, true);
}

void writeDebugStreamSave(char * saveText){
	writeDebugStreamSaveMain(saveText, false);
}
