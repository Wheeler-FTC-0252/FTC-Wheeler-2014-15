#pragma systemFile
#define maxSize 19

/*
Developed by T.Friez
Last Updated: 11/11/2011 5:00pm EST
Version #: 1.02
For use with Digi Xbee Radios (Tested with Series 1)
NXT Hardware: http://www.dexterindustries.com/NXTBee.html
VEX Hardware: http://www.sparkfun.com/products/9132
*/

/////////////////////////
// Initalization Routines
/////////////////////////
#if defined(NXT)
void InitRS485(long nBaudRate = 9600)
{
  nxtEnableHSPort();            //Enable High Speed Port #4
  nxtSetHSBaudRate(nBaudRate);  //Xbee Default Speed
  nxtHS_Mode = hsRawMode;       //Set to Raw Mode (vs. Master/Slave Mode)
}
#elif defined(VEX2)
void InitRS232(TUARTs tSelectedUART = UART1, TBaudRate tSelectBaud = baudRate9600)
{
  configureSerialPort(tSelectedUART, uartUserControl);
  setBaudRate(tSelectedUART, tSelectBaud);
}
#endif

/////////////////////////
// Sending a String
/////////////////////////
#if defined(NXT)
void SendString(const char* sOutgoing)
{
	for(int i = 0; i < strlen(sOutgoing); i++)
	{
		nxtWriteCharRawHS(sOutgoing[i]);
		wait1Msec(2);
	}
}
#elif defined(VEX2)
void SendString(const char* sOutgoing, TUARTs tSelectedUART = UART1)
{
	for(int i = 0; i < strlen(sOutgoing); i++)
	{
		sendChar(tSelectedUART, sOutgoing[i]);
		while(!bXmitComplete(tSelectedUART)) wait1Msec(1);
	}
}
#endif

/////////////////////////
// Receiving a String
/////////////////////////
#if defined(NXT)
void ReceiveString(const char* cProcessing, bool bClearBuffer = true, short nTimeoutInMS = -1)
{
	ubyte cIncomingChar;
	int nCounter = 0;

	memset(cProcessing, 0, sizeof(cProcessing));

	if(bClearBuffer)
	{
		while(nxtGetAvailHSBytes())
		{
			nxtReadRawHS(&cIncomingChar, 1);
			noOp();
		}
	}

	clearTimer(T4);

	while(!nxtGetAvailHSBytes())
	{
		if((time1[T4] > nTimeoutInMS) && (nTimeoutInMS != -1))
			return;
		noOp();
	}

	wait1Msec(1);

	while(nxtGetAvailHSBytes() && nCounter < (maxSize))
	{
		nxtReadRawHS(&cIncomingChar, 1);
		cProcessing[nCounter] = cIncomingChar;
		nCounter++;
		wait1Msec(1);
	}
}

#elif defined(VEX2)
void ReceiveString(const char* cProcessing,TUARTs tSelectedUART = UART1, bool bClearBuffer = true, short nTimeoutInMS = -1)
{
	short incomingChar = -1;
	int nCounter = 0;

	memset(cProcessing, 0, sizeof(cProcessing));

	if(bClearBuffer)
	{
		while(incomingChar != -1)
		{
			incomingChar = getChar(tSelectedUART);
			wait1Msec(1);
		}
	}

	ClearTimer(T4);
	while(incomingChar == -1)
	{
		if((time1[T4] > nTimeoutInMS) && (nTimeoutInMS != -1))
			return;

		incomingChar = getChar(tSelectedUART);
		wait1Msec(1);
	}

	cProcessing[nCounter] = incomingChar;
	wait1Msec(1);

	while(incomingChar != -1 && nCounter < maxSize)
	{
		incomingChar = getChar(tSelectedUART);
		nCounter++;
		if(incomingChar != -1)
		{
			cProcessing[nCounter] = incomingChar;
			wait1Msec(1);
		}
	}
}
#endif
