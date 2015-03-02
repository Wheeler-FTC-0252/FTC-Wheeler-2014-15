task main()
{
     //from "http://help.robotc.net/WebHelpMindstorms/index.htm#Topics/Function_Library_-_LEGO_NXT/File_Access_-_NXT.htm%3FTocPath%3DCommand%2520Library%2520-%2520LEGO%2520NXT%7CText-Based%2520ROBOTC%7C_____10"
     //edited by LUC 150110 - found that nFileSize had to be defined as a "short" and sFileName has to be a "const char *"


 TFileHandle  hFileHandle;                                                                                      // will keep track of our file
 TFileIOResult nIOResult;                                                                                           // will store our IO resultsstring
 const char * sFileName = "test.txt";                                                                            // the name of our file
 short nFileSize = 100;                                                                                                    // will store our file size
 byte CR = 0x13;                                                                                                            // define CR (carriage return)byte
 byte LF = 0x10;                                                                                                                           // define LF (line feed) string
 string sMessageToWrite = "ROBOTC IO test!";                                         // we will write this to the filestring
 string sMesageToWrite_2 = "A new line!";                                                   // we will also write this to the file on the next linechar
 char incommingChar;                                                                                                     // this will store each char as we read back in from the filestring
 string incommingString[5];                                                                                      // this will store the final, fully-read strings (with new strings getting put into new indexesint
 int nLineCounter = 0;                                                                                                    // this will let us know which line we are on when reading and writing (used as the index to 'incommingString[]')
 Delete("test.txt",nIOResult);

// intrinsic void OpenWrite(  TFileHandle &hFileHandle, TFileIOResult &nIoResult, const char   *pzFileName, short  &nFileSize) asm(opcdFileIO, ioOpenWriteVariableFN, variableRefWord(nIoResult), variableRefWord(hFileHandle), variableRefCharPtr(pzFileName), variableRefWord(nFileSize));

 OpenWrite(hFileHandle, nIOResult, sFileName, nFileSize);           // open the file for writing (creates the file if it does not exist)

 WriteText(hFileHandle, nIOResult, sMessageToWrite);         // write 'sMessageToWrite' to the file
 WriteByte(hFileHandle, nIOResult, CR);                      // write 'CR' to the file (carriage return)
 WriteByte(hFileHandle, nIOResult, LF);                      // write 'LF' to the file (line feed)
 WriteText(hFileHandle, nIOResult, sMesageToWrite_2);        // write 'sMesageToWrite_2' to the file
 Close(hFileHandle, nIOResult);                              // close the file (DON'T FORGET THIS STEP!)
 wait1Msec(1000);                                                                                                           // just a wait so we can see the variables updating in the ROBOTC debugger in order (this is not strictly necessary)
 OpenRead(hFileHandle, nIOResult, sFileName, nFileSize);     // open our file 'sFileName' for reading
 for(int i = 0; i < nFileSize; i++)                                                            // iterate through the file until we've hit the end:
 {
  ReadByte(hFileHandle, nIOResult, incommingChar);             // read in a single byte
  if(incommingChar == CR || incommingChar == LF)                              // if the incomming byte is a carriage return or a line feed:
  {
   if(incommingChar == LF)                                                                                     // if it's a line feed:
 {
    nLineCounter++;                                                                                                // increment our index (will now store next char on a 'new line' (a new index into our 'incommingString[]')
   }
   else
   {
    incommingString[nLineCounter] += incommingChar;                // append that byte (char) to the end of our final string, at the right index}}
    Close(hFileHandle, nIOResult);                                 // close our file (DON'T FORGET THIS STEP!)
    for(int i = 1; i <= 5; i++)
    {
     nxtDisplayCenteredTextLine(i, incommingString[i-1]);
    }
   }
  }
 }
}
