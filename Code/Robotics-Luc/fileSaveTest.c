bool debugFlag = true;

#include "debugStreamSave.c"

task main()
{
	if(debugFlag){writeDebugStreamLine( "\n\n------------------------\n" );}

	TFileHandle handleName = saveFileInit();

	if(debugFlag){writeDebugStreamLine( "Handle Number: %d" , handleName );}
	if(debugFlag){writeDebugStreamLine( "WRITE STREAM" );}

	writeDebugStreamLineSave("cheese", handleName);
}
