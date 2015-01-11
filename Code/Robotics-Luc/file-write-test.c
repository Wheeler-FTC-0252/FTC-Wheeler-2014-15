task main()
{
	TFileHandle myFileHandle;          // create a file handle variable 'myFileHandle'
	TFileIOResult IOResult;            // create an IO result variable 'IOResult'
	const char * myFileName = "testLuc.txt";  // create and initialize a string variable 'myFileName'
	short myFileSize;               // create and initialize an integer variable 'myFileSize'

	writeDebugStreamLine("---START---");

//	string writeMe = "123456789012345678901234567890";        // string always appears to be 20 bytes in RobotC - create a string variable 'writeMe' and set it to "ROBOTC"
	char writeMe[] = "123";                     // number of characters plus a /0 at end
//	myFileSize = sizeof(writeMe);							// sizeof is calculated at compile time
	myFileSize = strlen(writeMe);

	writeDebugStreamLine("Writing a stream (%d chars) %s", myFileSize , writeMe );

	Delete(myFileName,IOResult);
	writeDebugStreamLine("Delete(): IOResult = %d", IOResult);

	writeDebugStreamLine("OpenWrite(1): myFileName = %s, myFileSize = %d, IOResult = %d", myFileName, myFileSize , IOResult);
	OpenWrite(myFileHandle, IOResult,myFileName, myFileSize);  // open for write: "myFile.txt"
	writeDebugStreamLine("OpenWrite(2): myFileName = %s, myFileSize = %d, IOResult = %d", myFileName, myFileSize , IOResult);

	WriteString(myFileHandle, IOResult, writeMe);  // writes "ROBOTC" with a NULL terminator to the file handled by 'myFileHandle
	writeDebugStreamLine("WriteString(): IOResult = %d", IOResult);

	Close(myFileHandle, IOResult);
	writeDebugStreamLine("Close(): IOResult = %d", IOResult);

	writeDebugStreamLine("---ENDS---");

	}
