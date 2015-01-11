task main()
{
	TFileHandle myFileHandle;          // create a file handle variable 'myFileHandle'
	TFileIOResult IOResult;            // create an IO result variable 'IOResult'
	char myFileName = "testLuc.txt";  // create and initialize a string variable 'myFileName'
	short myFileSize = 6;               // create and initialize an integer variable 'myFileSize'
	//Delete("test.txt",IOResult);
	OpenWrite( &myFileHandle, &IOResult,myFileName, & myFileSize);  // open for write: "myFile.txt"
	string writeMe = "ROBOTC";                     // create a string variable 'writeMe' and set it to "ROBOTC"
	WriteString(myFileHandle, IOResult, writeMe);  // writes "ROBOTC" with a NULL terminator to the file handled by 'myFileHandle
	Close(myFileHandle, IOResult);
}
