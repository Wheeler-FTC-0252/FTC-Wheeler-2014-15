void writeDebugStreamSaveMain(char saveText, bool carrageReturn){
	TFileIOResult IoResult;
	TFileHandle FileHandle;
	const char * debugSaveFile="debugSave.txt";
	short stringLength=sizeof(saveText);


	OpenWrite(FileHandle, IoResult, debugSaveFile, stringLength);

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

void writeDebugStreamLineSave(char saveText){
	writeDebugStreamSaveMain(saveText, true);
}

void writeDebugStreamSave(char saveText){
	writeDebugStreamSaveMain(saveText, false);
}
