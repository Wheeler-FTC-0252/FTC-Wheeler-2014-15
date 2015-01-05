#pragma once
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  
//									ROBOTC Intrinsic Functions to Access Functions in LEGO's EV3 VM                  
//                                                                                                  
// This file contains ROBOT intrinsic function declarations that allow access to capabilities       
// of the LEGO developedEV3 firmware by the ROBOTC VM.                                              
//                                                                                                  
// Automatically Generated File on: 8/27/2014 at 11:22:10 PM 
//                                                                                                  
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ev3_native_bytecodes.h"



// Get name of program. Note there is no buffer overflow check on 'pProgramName'.
intrinsic void ProgramInfoGetPrgname(const short pgmSlotNumber, char *pProgramName)
                asm(byte(opcdEV3_LEGO), byte(opPROGRAM_INFO), byte(GET_PRGNAME), variable(pgmSlotNumber), variable(pProgramName));


// Get HW version string
intrinsic void GetHWVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_HW_VERS), variable(nMaxLength), variable(pVersionChars));

// Get FW version string
intrinsic void GetFWVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_FW_VERS), variable(nMaxLength), variable(pVersionChars));

// Get FW Build string
intrinsic void GetFWBuild(const char nMaxLength, char *pBuildChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_FW_BUILD), variable(nMaxLength), variable(pBuildChars));

// Get OS Build string
intrinsic void GetOSBuild(const char nMaxLength, char *pBuildChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_OS_BUILD), variable(nMaxLength), variable(pBuildChars));

// Get version string
intrinsic void GetVersion(const char nMaxLength, char *pVersionChars)
                asm(byte(opcdEV3_LEGO), byte(opUI_READ), byte(GET_VERSION), variable(nMaxLength), variable(pVersionChars));


// Wait for keypress
intrinsic void waitForButtonPress()
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(WAIT_FOR_PRESS));

// Flush unprocessed button messages
intrinsic void flushButtonMessages()
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(FLUSH));

// Generate button press
intrinsic void generateButtonPress(const char button)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(PRESS), variable(button));

// Generate button release
intrinsic void generateButtonRelease(const char button)
                asm(byte(opcdEV3_LEGO), byte(opUI_BUTTON), byte(RELEASE), variable(button));


// Update LCD
intrinsic void UIUpdateLCD()
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(UPDATE));

// Fill window
intrinsic void UIFillWindow(const char color, const short startY, const short sizeY)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(FILLWINDOW), variable(color), variable(startY), variable(sizeY));

// Scroll
intrinsic void UIScrollDisplay(const short rowsToScroll)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(SCROLL), variable(rowsToScroll));

// Restore or save LCD parameters
intrinsic void saveRestoreLCD(const char bRestoreSave)
                asm(byte(opcdEV3_LEGO), byte(opUI_DRAW), byte(POPUP), variable(bRestoreSave));


// Write data to sensor via UART
intrinsic void sensorWriteUART(const char sensorPort, const char numbOfBytes, char *pBytes)
                asm(byte(opcdEV3_LEGO), byte(opINPUT_WRITE), variable(sensorPort), variable(numbOfBytes), variable(pBytes));


// Create file or open for append (if name starts with '~','/' or '.' it is not from current folder)
intrinsic void FileOpenAppend(char *pFileName, short &fileHandle)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(OPEN_APPEND), variable(pFileName), variableRefRAM(fileHandle));

// Open file for read (if name starts with '~','/' or '.' it is not from current folder)
intrinsic void FileOpenRead(char *pFileName, short &fileHandle, long &sizeOfFile)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(OPEN_READ), variable(pFileName), variableRefRAM(fileHandle), variableRefRAM(sizeOfFile));

// Create file for write (if name starts with '~','/' or '.' it is not from current folder)
intrinsic void FileOpenWrite(char *pFileName, short &fileHandle)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(OPEN_WRITE), variable(pFileName), variableRefRAM(fileHandle));

// Read float value
intrinsic void FileReadValue(const short fileHandle, const char delimiters, float &value)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(READ_VALUE), variable(fileHandle), variable(delimiters), variableRefRAM(value));

// Write formated float value
intrinsic void FileWriteValue(const short fileHandle, const char delimiters, const float value, const char totalChars, const char numbDecimalChars)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(WRITE_VALUE), variable(fileHandle), variable(delimiters), variable(value), variable(totalChars), variable(numbDecimalChars));

// Read text from file
intrinsic void FileReadText(const short fileHandle, const char delimiters, const short maxChars, char *pText)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(READ_TEXT), variable(fileHandle), variable(delimiters), variable(maxChars), variable(pText));

// Write text to file
intrinsic void FileWriteText(const short fileHandle, const char delimiters, char *pText)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(WRITE_TEXT), variable(fileHandle), variable(delimiters), variable(pText));

// Close file
intrinsic void FileClose(const short fileHandle)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(CLOSE), variable(fileHandle));

// Get handle from filename
intrinsic void FileGetHandle(char *pFileName, short &fileHandle, char &openForWrite)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_HANDLE), variable(pFileName), variableRefRAM(fileHandle), variableRefRAM(openForWrite));

// Make folder if not present
intrinsic void FileMakeFolder(char *pFolderName, char &bSuccess)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(MAKE_FOLDER), variable(pFolderName), variableRefRAM(bSuccess));

// Get number of sub folders
intrinsic void FileGetFolders(char *pFolderName, char &numbOfSubFolders)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_FOLDERS), variable(pFolderName), variableRefRAM(numbOfSubFolders));

// Get sub-folder name
intrinsic void FileGetSubfolderName(char *pFolderName, const char subFolderIndex, const char maxChars, char *pFolderName2)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_SUBFOLDER_NAME), variable(pFolderName), variable(subFolderIndex), variable(maxChars), variable(pFolderName2));

// Get index for item name
intrinsic void FileGetItem(char *pFolderName, char *pFileName, char &subFolderIndex)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_ITEM), variable(pFolderName), variable(pFileName), variableRefRAM(subFolderIndex));

// Get number of files in cache
intrinsic void FileGetCacheFiles(char &numbOfFilesInCache)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_CACHE_FILES), variableRefRAM(numbOfFilesInCache));

// Create cache file
intrinsic void FilePutCacheFile(char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(PUT_CACHE_FILE), variable(pFileName));

// Get name from cache file index
intrinsic void FileGetCacheFile(const char cacheIndex, const char maxChars, char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(GET_CACHE_FILE), variable(cacheIndex), variable(maxChars), variable(pFileName));

// Delete cache file by index
intrinsic void FileDelCacheFile(const char cacheIndex)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(DEL_CACHE_FILE), variable(cacheIndex));

// Delete sub-folder
intrinsic void FileDelSubfolder(char *pFolderName, const char subFolderIndex)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(DEL_SUBFOLDER), variable(pFolderName), variable(subFolderIndex));

// Read bytes from file
intrinsic void FileReadBytes(const short handle, const short numbOfChars, char *pBytes)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(READ_BYTES), variable(handle), variable(numbOfChars), variable(pBytes));

// Write bytes to file
intrinsic void FileWriteBytes(const short handle, const short numbOfChars, char *pBytes)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(WRITE_BYTES), variable(handle), variable(numbOfChars), variable(pBytes));

// Delete file
intrinsic void FileRemove(char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(REMOVE), variable(pFileName));

// Move file SOURCE to DEST (if name starts with '~','/' or '.' it is not from current folder)
intrinsic void FileMove(char *pSource, char *pDest)
                asm(byte(opcdEV3_LEGO), byte(opFILE), byte(MOVE), variable(pSource), variable(pDest));


// Calculate folder/file size
intrinsic void getFilenameTotalSize(char *pFileName, long &numbOfFiles, const long totalSize)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(TOTALSIZE), variable(pFileName), variableRefRAM(numbOfFiles), variable(totalSize));

// Split file name into directory, file name and file extension.
intrinsic void FilenameSplit(char *pFileName, const char maxCharsInStrings, char *pFolder, char *pName, char *pExtension)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(SPLIT), variable(pFileName), variable(maxCharsInStrings), variable(pFolder), variable(pName), variable(pExtension));

// Merge directory+name+extension strings into file name
intrinsic void FilenameMerge(char *pFolder, char *pName, char *pExtension, const char maxCharsInFilename, char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(MERGE), variable(pFolder), variable(pName), variable(pExtension), variable(maxCharsInFilename), variable(pFileName));

// Pack file or folder into "raf" container (Robot Archive File tar ball)
intrinsic void FilenamePack(char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(PACK), variable(pFileName));

// Unpack file or folder from "raf" container(Robot Archive File tar ball)
intrinsic void FilenameUnpack(char *pFileName)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(UNPACK), variable(pFileName));

// Get folder name of currently loaded program file
intrinsic void FilenameGetFoldername(const char maxChars, char *pFolder)
                asm(byte(opcdEV3_LEGO), byte(opFILENAME), byte(GET_FOLDERNAME), variable(maxChars), variable(pFolder));


// Tests if new message is available
intrinsic void testForMailboxMessage(const char mailboxIndex, char &bBusy)
                asm(byte(opcdEV3_LEGO), byte(opMAILBOX_TEST), variable(mailboxIndex), variableRefRAM(bBusy));


// Wait for message to be available
intrinsic void waitForMailboxMessage(const char mailboxIndex)
                asm(byte(opcdEV3_LEGO), byte(opMAILBOX_READY), variable(mailboxIndex));


// Closes mailbox
intrinsic void closeMailbox(const char mailboxIndex)
                asm(byte(opcdEV3_LEGO), byte(opMAILBOX_CLOSE), variable(mailboxIndex));
