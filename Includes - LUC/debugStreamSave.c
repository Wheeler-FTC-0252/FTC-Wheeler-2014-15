void writeDebugStreamSaveMain(string saveText, bool carrageReturn){
	TFileIOResult IoResult;
	TFileHandle FileHandle;
	const char * debugSaveFile="debugSave.txt";
	short stringLength=sizeof(saveText);

	writeDebugStreamLine(saveText);
	OpenWrite(FileHandle, IoResult, debugSaveFile, stringLength);

	if (carrageReturn){//newline
		WriteString(FileHandle, IoResult, "\n");
	}
	WriteString(FileHandle, IoResult, saveText);
}

void writeDebugStreamLineSave(string saveText){
	writeDebugStreamSaveMain(saveText, true);
}

void writeDebugStreamLineSave(string saveText){
	writeDebugStreamSaveMain(saveText, false);
}
