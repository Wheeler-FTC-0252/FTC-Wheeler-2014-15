#include "debugStreamSave.c"

task main()
{
	TFileHandle handleName = saveFileInit();
	writeDebugStreamLineSave("cheese", handleName);
}
