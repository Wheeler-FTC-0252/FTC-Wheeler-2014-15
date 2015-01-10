#if !defined(__ZigBeeNtwk__H_)
#define __ZigBeeNtwk__H_

#include "../../Headers/Declares/StandardCommPortTypes.h"
#include "../../Headers/Declares/TNodeIndices.h"


#include "MainIncludes.h"
#include "pPgmByteDeclare.h"
#include "XBeeSerialDriver.h"

#include "stddef.h"

#ifdef __cplusplus
extern "C"
{
#endif


#if defined(bHasMultRobotNetworking) || defined(_WINDOWS)

#if !defined(bytesDeclared)
	#define bytesDeclared
	#define byteDeclareRequired
	typedef unsigned char	 ubyte;
	typedef   signed char  sbyte;
	typedef unsigned short uword;
	typedef   signed short sword;
#endif

//
// Functions to control the XBee Driver
//
extern void startXBeeDriver(void);
extern void startXBeeDriverWithChannel(TUSmallValue nUartIndex, TUSmallValue nChannel);
extern void stopXBeeDriver(void);
extern void XBeeOneMillisecondTick(void);

//
typedef ubyte TXBeeSerialNumber[8];
typedef ubyte TZigBeeShortSerialNumber[2];
typedef ubyte TXBeeIPAddress[4];


#define kMaxPasswordLength 32
typedef ubyte TWiFiPassword[kMaxPasswordLength];

typedef unsigned char tChannelNumber;
typedef unsigned short tZigBeeNetworkNumber;


typedef enum TXBeeCommandStatus   // Aligns with different enum in "RobotCIntrinsics.c". Keep these synchronized!!
{
	xbStatusSuccess							= 0,
	xbStatusWaitingForCommand		= 1,
	xbStatusCommandFailed				= 2,
} TXBeeCommandStatus;

typedef enum TXBeeTypes
{
	xbeeTypeUnknown						= 0,

	xbeeTypeS1								= 1,								// 802.15.4 Series 1
	xbeeTypeS2								= 2,								// ZigBee Series 2
	xbeeTypeWiFi							= 4,								// Wi-Fi

	xbeeTypeS1_or_S2					= (xbeeTypeS1 | xbeeTypeS2),
	xbeeTypeAllTypes					= (xbeeTypeS1 | xbeeTypeS2 | xbeeTypeWiFi),
} TXBeeTypes;




extern TXBeeCommandStatus getNtwkingCommandStatus(void);
extern bool getNtwkingStartupFinished(void);
extern bool bXBeeStateMachineIdle(void);

extern bool bZBOutputBufferAvailable(void);
extern void sendNextBufferedXBeeMessage(void);
extern TXBeeCommandStatus sendXBee_BufferedMessage(TUSmallValue nToNodeIndex, const ubyte *pMessage, TUSmallValue nMessageLength);
extern TXBeeCommandStatus sendXB_Message(TUSmallValue nToNodeIndex, const ubyte *pMessage, TUSmallValue nMessageLength);

extern uword GetReceiveMsgSizeFromQueuedMessages(void);
extern TXBeeCommandStatus getMultiRobotMsgFromQueuedMessages(uword *pFromNode, ubyte *pData, TUSmallValue nBufferSize, ubyte *pActualBytes);

extern void addNodeToListInRobot(TUSmallValue nNodeIndex, const TXBeeSerialNumber *pSerialNumber);
extern void addIPAddressToListInRobot(TUSmallValue nNodeIndex, const TXBeeIPAddress *pIPAddress);

extern void configureNetwork(uword nPanID, TUSmallValue nChannel, TUSmallValue nMyNodeIndex, TUSmallValue nNumbOfNodes, TIntFlashPtr pNodeList);
extern void initializeXBeeNodeTable(void);


enum
{
	kZigBeeDefaultBaudRate							= 200000,
	kZigBeeDefaultNetworkID							= 0x3332,				// Default value after f/w download
	kZigBeeBroadcastPanID								= 0xFFFF,

	kBroadcastNodeIndex									= (ubyte) 0xFE, // Special Node index indicating broadcast command is being used

	kDefaultChannelNumberZigBee					= 12,						// Valid channel range 12 - 26.

	kDefaultChannelNumberWiFi						= 11,						// Valid channel range  1 - 11.

	kZigBeeDefaultSearchTimeInSeconds		= 1,
	kZigBeeDelayWhenSwitchingChannels		= 25,

	kZigBeeNoisyThreshold								= 60,						// Upper limit of Signal strength for "noisy" ZigBee "Energy Scan" results
	kZigBeeQuietThreshold								= 80,						// Lower limit of Signal strength for "quiet" ZigBee "Energy Scan" results

	kMaxPacketLength										= 64 + 15,
	kZigBeePacketHeaderByte							= 0x7E,
};


//
// Helper Functions for Send "Commands" ("Packets") via XBee API
//
#if defined(_WINDOWS)

	#undef CLASS_DECLSPEC_XBeeSerialPorts
	#ifdef _EXPORTING_XBeeSerialPorts
		#define CLASS_DECLSPEC_XBeeSerialPorts    __declspec(dllexport)
	#else
		#define CLASS_DECLSPEC_XBeeSerialPorts    __declspec(dllimport)
	#endif

	extern CLASS_DECLSPEC_XBeeSerialPorts TStandardCommPortUsage nCurrSpecialComPort;
	extern CLASS_DECLSPEC_XBeeSerialPorts void setCurrSpecialComPort(TStandardCommPortUsage nIndex);

	#define kNumbOfZigBeePorts 3

	#if !defined(Simulator)
		extern void startFastZigBeeMessaging(void);
		extern void stopZigBeeFastMessaging(void);
	#endif

	#if (0) && defined(Simulator)
		extern TXBeeTypes getCurrentXBeeType(void);
	#else
		extern CLASS_DECLSPEC_XBeeSerialPorts TXBeeTypes getCurrentXBeeType(void);
	#endif

#else

	#define nCurrXBeeComPort 0
	#define setCurrSpecialComPort(nIndex)
	#define kNumbOfZigBeePorts 1
	#define getCurrentXBeeType() ((TXBeeTypes) xbeeTypeS1)

	extern bool bSameSerialNumber(const TXBeeSerialNumber *pSerialNumber1, const TXBeeSerialNumber *pSerialNumber2);
	extern bool bSameIPAddress(const TXBeeIPAddress *pIPAddress1, const TXBeeIPAddress *pIPAddress2);

#endif

typedef enum TXbeeAPIRcvMessageTypes
{
	// Rcv Commands from XBee modules

	xbAPICmds_RcvPacket64Bits									= 0x80,
	xbAPICmds_RcvPacket16BitsZigBee						= 0x81,	// ZigBee only
	xbAPICmds_RcvSensorData64Bits							= 0x82,
	xbAPICmds_RcvSensorData16BitsZigBee				= 0x83,	// ZigBee only
	xbAPICmds_RemoteAtCommandResponseWiFi			= 0x87,	// WiFi only
	xbAPICmds_ATCommandResponse								= 0x88,
	xbAPICmds_XmitRequestResponse							= 0x89,
	xbAPICmds_RcvModemStatus									= 0x8A,
	xbAPICmds_RemoteAtCommandResponseZigBee		= 0x97,	// ZigBee only
	xbAPICmds_ReceivePacketIPv4								= 0xB0,	// WiFi only
} TXbeeAPIRcvMessageTypes;

typedef enum TXbeeAPIXmitMessageTypes
{
	// Xmit Commands to XBee 802.15.4 module

	xbAPICmds_XmitRequest64Bits								= 0x00,
	xbAPICmds_XmitRequest16BitsZigBee					= 0x01,	// ZigBee only

	xbAPICmds_RemoteAtCommandWiFi							= 0x07,	// For WiFi XBee
	xbAPICmds_ATCommand												= 0x08,
	xbAPICmds_QueueParameter									= 0x09,
	xbAPICmds_RemoteAtCommandZigBee						= 0x17,	// For ZigBee/802.15.4 XBee
} TXbeeAPIXmitMessageTypes;

typedef enum TZigBeeXmitStatus
{
	xbXmitStatusSuccess								= 0x00,
	xbXmitStatusNoACK									= 0x01, // All retries attempted and no ACK received.
	xbXmitStatusCCAFailure						= 0x02,
	xbXmitStatusPurged								= 0x03, // WiFi: Transmission was purged because it was attempted before stack was completely up.
	xbXmitStatusPhysicalError					= 0x04, // WiFi: Physical error occurred on the interface with the WiFi transceiver.
	xbXmitStatusTimeout								= 0x21, // WiFi: X64 transmission timed out awaiting an acknowledgement from the remote device.
	xbXmitStatusResourceError					= 0x32, // WiFi: Resource Error; Either buffers or sockets were depleted, preventing a transmission from occurring.
	xbXmitStatusMessageTooLong				= 0x74, // WiFi: Message not sent because it was too long
	xbXmitStatusSocketFailed					= 0x76, // WiFi: Attempt to create a client socket failed
} TZigBeeXmitStatus;

typedef enum TZigBeeModemStatusType
{
	xbModemStatusHWReset										= 0, // Hardware reset or power up
	xbModemStatusWatchdogReset							= 1, // Watchdog timer reset
	xbModemStatusAssociated									= 2, // WiFi: Joined
	xbModemStatusDisassociated							= 3, // WiFi: No longer joined to access point
	xbModemStatusSyncLost										= 4, // ZigBee only
	xbModemStatusIPConfigurationError				= 4, // WiFi: IP configuration error
	xbModemStatusCoordinatorRealignment			= 5, // ZigBee only
	xbModemStatusCoordinatorStarted					= 6, // ZigBee only
} TZigBeeModemStatusType;

typedef enum TXBeeATErrorCodes
{
	xbATStatusSuccess												= 0,
	xbATStatusError													= 1,
	xbATStatusInvalidCommand								= 2,
	xbATStatusInvalidParameter							= 3,
	xbATStatusNoResponse										= 4,   // Applies to remote AT commands
	xbATStatusUndocumented									= 5,   // Applies to remote AT commands
} TXBeeATErrorCodes;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//														 AT COmmands Known/Used by ROBOTC Driver
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#define convertCommandToShort(firstByte, secondByte) ((((uword) (firstByte)) << 8) | ((ubyte) (secondByte)))

typedef enum TATCommands
{
	ATNodeDiscovery						= convertCommandToShort('N', 'D'),
	ATNodeDiscoveryTime				= convertCommandToShort('N', 'T'),
	ATNodeDiscoverOptions     = convertCommandToShort('N', 'O'),
	ATNodeIdentifier					= convertCommandToShort('N', 'I'),

	ATNodeSerialNumberHigh		= convertCommandToShort('S', 'H'),
	ATNodeSerialNumberLow			= convertCommandToShort('S', 'L'),
	ATDestinationLow					= convertCommandToShort('D', 'L'),
	ATDestinationIPAddress		= ATDestinationLow,
	ATDestinationHigh					= convertCommandToShort('D', 'H'),
	ATMacMode									= convertCommandToShort('M', 'M'),

	ATPanID										= convertCommandToShort('I', 'D'),

	AT16BitSourceAddress			= convertCommandToShort('M', 'Y'),//ZigBee
	ATMyIPNetworkAddress			= AT16BitSourceAddress,						//WiFi. 32-bit network address of the module

	ATActiveScan							= convertCommandToShort('A', 'S'),// Scan for access points in the vicinity. This command can only be issued when SSID is NULL, which can be forced by first issuing the NR command.
	ATNetworkReset						= convertCommandToShort('N', 'R'),// Reset network layer. For WiFi, this means to disassociate from the access point and set SSID to NULL
	ATSSID										= ATPanID,												// Set/read the SSID of the access point, which may be up to 31 ASCII characters
	ATNetworkType							= convertCommandToShort('A', 'H'),// Set/read network type. Network types supported are Infrastructure (using an access point) and Adhoc (IBSS).
	ATIPProtocol							= convertCommandToShort('I', 'P'),// Set/Read the protocol (UDP/TCP) used for the serial communication service. This is the port used by the C0 command.
	ATIPAddressMask						= convertCommandToShort('M', 'K'),
	ATGatewayIPAddress				= convertCommandToShort('G', 'W'),
	ATTCPTimeout							= convertCommandToShort('T', 'M'),// Set/Read the timeout for connection on TCP socket. If 0, socket closes immediately after data sent.
	ATTCPMaxPayloadSize				= convertCommandToShort('N', 'P'),// Read maximum number of RF payload bytes that can be sent in a transmission
	ATIPAddressingMode				= convertCommandToShort('M', 'A'),// Set / read the IP addressing mode (DHCP or Static)
	ATAssociationIndicator		= convertCommandToShort('A', 'I'),// Read information regarding last node join request
	ATEncryptionEnable				= convertCommandToShort('E', 'E'),// Set/Read the encryption enable setting.
	ATPasswordPhrase					= convertCommandToShort('P', 'K'),// Set the security key used for WPA and WPA2 security.
	ATSourcePort							= convertCommandToShort('C', 'O'),// Set/Get port number used to provide the serial communication service.
	ATDestinationPort					= convertCommandToShort('D', 'E'),// Set/Get destination UDP/TCP port value.
	ATBitRate									= convertCommandToShort('B', 'R'),// Bit Rate of IBSS Creator.
	ATDeviceType							= convertCommandToShort('D', 'D'),// Stores a device type value. This value can be used to differentiate different XBee-based devices.
	ATTemperature							= convertCommandToShort('T', 'P'),// Temperature. Read temperature of module in degrees Celsius.
	ATSupplyVoltage						= convertCommandToShort('%', 'V'),// Supply Voltage. Read supply voltage in millivolt units.

	ATBaudRate								= convertCommandToShort('B', 'D'),
	ATParity									= convertCommandToShort('N', 'B'),

	ATApiEnabled							= convertCommandToShort('A', 'P'),

	ATAssociateEndDevice			= convertCommandToShort('A', '1'),
	ATCoordinatorEnable				= convertCommandToShort('C', 'E'),
	ATRandomDelay							= convertCommandToShort('R', 'N'),

	ATEnergyScan							= convertCommandToShort('E', 'D'),
	ATScanChannels						= convertCommandToShort('S', 'C'),

	ATErrorACK_Counts					= convertCommandToShort('E', 'A'),
	ATErrorCCA_Counts					= convertCommandToShort('E', 'C'),
	ATCCA_Threshold						= convertCommandToShort('C', 'A'),    // Do not transmit if CCA engergy assessment exceeds this threshold

	ATRSSI_Timer							= convertCommandToShort('R', 'P'),		// Duration in 100-msec that Rcv indicator LED remains on after receiving a packet
	ATPowerLevel							= convertCommandToShort('P', 'L'),// Select/Read the power level at which the RF module transmits conducted power.
	ATXBeeRetries							= convertCommandToShort('R', 'R'),

	ATForceNetworkReset				= convertCommandToShort('N', 'R'),// Reset network layer. For WiFi, this means to disassociate from the access point and set SSID to NULL,
	ATForceSoftwareReset			= convertCommandToShort('F', 'R'),// Reset module. Responds immediately with an OK status, and then performs a software reset about 2 seconds later.
	ATRestoreDefaults					= convertCommandToShort('R', 'E'),// Restore module parameters to factory defaults.
	ATApplyChanges						= convertCommandToShort('A', 'C'),// Applies changes to all command registers causing queued command register values to be applied.
	ATWriteChanges						= convertCommandToShort('W', 'R'),// Write parameter values to non-volatile memory so that parameter modifications persist through subsequent resets. Takes effect on reboot. Use sparingly to prevent EEPROM wearout.
	ATExitCommandMode					= convertCommandToShort('C', 'N'),// Explicity exit command mode. Changes are applied upon exit

	ATForceSample							= convertCommandToShort('I', 'S'),//	Forces a read of all enabled DIO/ADC lines.
	ATIO_OutputEnabled				= convertCommandToShort('I', 'U'),		//	Enables / disables output of I/O sample packets
	ATIO_SamplesCount					= convertCommandToShort('I', 'T'),		//	(R/W) Number of DIO/ADC samples to collect before transmitting data.
	ATIO_DIOChangeDetect			= convertCommandToShort('I', 'C'),		//	(R/W) Bit map of which DIO fields to monitor for changes.
	ATIO_OutputLevels					= convertCommandToShort('I', 'O'),		//	(W/O) Bit map of which DIO output fields are set
	ATIO_SampleRate						= convertCommandToShort('I', 'R'),		//	(R/W) Sample rate for DIO/ADC pins.
	ATIO_PullUpResistor				= convertCommandToShort('P', 'R'),		//	(R/W) Bit map of enabled / disabled pullup resistors on DIO lines.
	ATIO_InputAddress					= convertCommandToShort('I', 'A'),		//	(W/O) Binds module to a special I/O address for accepting "I/O" commands

	ATIO_PWMConfiguration_0		= convertCommandToShort('P', '0'),		//	(R/W) PWM 0 Configuration
	ATIO_PWMConfiguration_1		= convertCommandToShort('P', '1'),		//	(R/W) PWM 1 Configuration
	ATIO_PWMOutputLevel_0			= convertCommandToShort('M', '0'),		//	(R/W) PWM 0 Output Level / Duty Cycle
	ATIO_PWMOutputLevel_1			= convertCommandToShort('M', '1'),		//	(R/W) PWM 1 Output Level / Duty Cycle

	ATChannel									= convertCommandToShort('C', 'H'),
	ATPacketizationTimeout		= convertCommandToShort('R', 'O'),
	ATReceivedSignalStrength	= convertCommandToShort('D', 'B'),
	ATAccessPointRSSI					= ATReceivedSignalStrength,				// Access Point Signal Strength. Not yet documented in PDF file.

	ATHardwareVersion					= convertCommandToShort('H', 'V'),// Read hardware version of the module.
	ATHardwareRevision				= convertCommandToShort('%', 'R'),// Read hardware revision of the module. Not yet documented in PDF file.
	ATSoftwareVersion					= convertCommandToShort('V', 'R'),// Read firmware version of the module.

	ATMessageDummy						= convertCommandToShort('0', '0'),    // Dummy field for non-command messages
} TATCommands;

extern ubyte xbGetNextFrameIndex(void);
extern void sendXBee_ATCmd_BasicMessage(TATCommands nCommand);
extern void sendATCommandWithOneByteParm(TATCommands nCommand, ubyte nParm, bool bQueuedChange);
extern void sendATCommandWithOneWordParm(TATCommands nCommand, uword nParm, bool bQueuedChange);
extern void sendATCommandWithFourByteParm(TATCommands nCommand, unsigned long nParm, bool bQueuedChange);
extern void sendATCommandWithVariableLengthParm(TATCommands nCommand, ubyte *pData, ubyte nLength, bool bQueuedChange);

extern void sendXBee_RemoteATCmd_BasicMessage(ubyte nNodeIndex,			TATCommands nCommand);
extern void sendXBee_RemoteATCmd_WithOneByteParm(ubyte nNodeIndex,  TATCommands nCommand, ubyte nParm, bool bQueuedChange);
extern void sendXBee_RemoteATCmd_WithOneWordParm(ubyte nNodeIndex,	TATCommands nCommand, uword nParm, bool bQueuedChange);
extern void sendXBee_RemoteATCmd_WithFourByteParm(ubyte nNodeIndex,	TATCommands nCommand, unsigned long nParm, bool bQueuedChange);
extern void sendXBee_RemoteATCommandWithVariableLengthParm(ubyte nNodeIndex, TATCommands nCommand, ubyte *pData, ubyte nLength, bool bQueuedChange);

extern void XBeeReceivePacketStateMachineModeAPI(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																			 Receive API Packet Formats
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	xbRcvStateStartOfPacket,
	xbRcvStatePacketLengthHighByte,
	xbRcvStatePacketLengthLowByte,
	xbRcvStatePacketData,
	xbRcvStateWaitForFirstChar,					// StateUsed in PC diagnostics only
} TXBeeRcvState;

typedef struct TResponseHeader
{
	ubyte					nDelimiter;			// 0x7E
	ubyte					nLengthHigh;
	ubyte					nLengthLow;
	ubyte					nReplyType;			// TXbeeAPIRcvMessageTypes butdeclare as 'ubyte' for packing/byte alignment considerations
	ubyte					nFrameID;
} TResponseHeader;

typedef struct
{
	ubyte			nFirstByte;
	ubyte			nSecondByte;
} TATCommand;

typedef ubyte TReplyStatus;
typedef ubyte TShortAddress[2];


typedef struct
{
	TATCommand					nCommand;
	TReplyStatus				nStatus;
	// variable length command reply data follows here
} TATReply;

typedef struct
{
	TResponseHeader			nHeader;
	TATReply						nATReply;
} TATReplyWithHeader;

typedef struct
{
	TResponseHeader						nHeader;
	TXBeeSerialNumber				nSerialNumber;
	TATReply									nATReply;
} TRemoteATReplyWithHeaderWiFi;

typedef struct
{
	TResponseHeader						nHeader;
	TXBeeSerialNumber				nSerialNumber;
	TZigBeeShortSerialNumber	nShortSerialNumber;
	TATReply									nATReply;
} TRemoteATReplyWithHeaderZigBee;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				ZigBee Received API Packet Types
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	ubyte								nFrameID;
	ubyte								nXmitStatus;			// TZigBeeXmitStatus
	//ubyte							nChecksum;
} TTransmitStatusReply;

typedef struct
{
	ubyte								nZigBeeModemStatusType;			// TZigBeeModemStatusType
} TModemStatusMessage;

#define kMaxNodeNameLength 20
typedef struct
{
	TATReply						nATReply;
	TShortAddress				nShortAddress;
	TXBeeSerialNumber nSerialNumber;
	ubyte								nSignalStrength;
	ubyte								cFriendlyName[kMaxNodeNameLength]; // Actually variable length
	//ubyte							nChecksum;
} TNodeDiscoveryReply;


typedef struct
{
	TATReply						nATReply;
	ubyte								nNodeName[kMaxNodeNameLength]; //Actually variable length field
	//ubyte							nChecksum;
} TNodeIdentifierReply;

#define kMaxSSIDNameLength 32
typedef struct
{
	TATReply						nATReply;
	ubyte								nScanType;				// Value 1 indicating scan type of 802.11
	ubyte								nDontCareFF;			// Placeholder or future user
	ubyte								nSecurityType;		// Security type where: 00=open, 01=WPA, 02=WPA2, and 03=WPA
	ubyte								nSignalStrength;
	ubyte								cSSIDName[kMaxSSIDNameLength]; //Actually variable length field
	//ubyte							nChecksum;
} TActiveScanReply;

typedef struct
{
	TATReply						nATReply;
	ubyte								nValue[4];
	//ubyte							nChecksum;
} TSerialNumberReply;

typedef struct
{
	TATReply						nATReply;
	ubyte								nBaudRate[4];   // Actually variable length?
	//ubyte							nChecksum;
} TBaudRateReply;

typedef struct
{
	TATReply						nATReply;
	ubyte								nReplyData[1];   // Actually variable length?
	//ubyte							nChecksum;
} TGenericDataReply;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				ZigBee Node Table
//
// Table of ZigBee nodes discovered by "ND" command.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TXBPegType
{
	pegLocalMessages,
	pegRemoteMessages,
	pegSuccess,
	pegRetransmit,
	pegFailed,
	kNumbOfPegCountRegisters
} TXBPegType;

#if defined(_WINDOWS)
	#define kSizeOfXBeeNodeTable		120
#else
	#define  kSizeOfXBeeNodeTable		9
#endif

typedef char TXBeeFriendlyName[32];

typedef struct TXBeeNode
{
	TXBeeSerialNumber		nSerialNumb;
	TXBeeIPAddress			nIPAddress;
} TXBeeNode;

extern TXBeeNode nodeTable[kSizeOfXBeeNodeTable];

#if defined(_WINDOWS)
	extern 	unsigned int getSingleVariableLengthParmFromATReply(unsigned char *pParm, int nNumbOfBytes);
	extern void storeSerialNumberHigh(unsigned int nValue);
	extern void storeSerialNumberLow(unsigned int nValue);
	extern void storeHardwareVersion(unsigned int nValue);
	extern void storeIPAddress(unsigned int nValue);
#else
	#define storeSerialNumberHigh(nValue)
	#define storeSerialNumberLow(nValue)
	#define storeHardwareVersion(nValue)
	#define storeIPAddress(nValue)
#endif

#if defined(_WINDOWS) && !defined(Simulator)

	// When it's compiled for Windows, these messages need to be processed

	extern void processRcvEnergyScanCommandResponse(TATReply *pReply, ubyte nDataLength);
	extern void processRcvATCommandReply(TNodeIndices nFromNodeIndex, TATReply *pReply, ubyte nDataLength);
	extern void processRcvNodeIdentifierCommandResponse(TNodeIdentifierReply *pReply, ubyte nDataLength);
	extern void processRcvNodeDiscoveryCommandResponse(TNodeDiscoveryReply *pReply, ubyte nDataLength);
	extern void processRcvActiveScanResponse(TActiveScanReply *pReply, ubyte nDataLength);
	extern void processRcvIPAddress(TGenericDataReply *pReply, ubyte nDataLength);

	extern void processRcvRemoteATCommandReply(TXBeeSerialNumber *pSerialNumber, TATReply *pReply, ubyte nDataLength);
	extern void processRcvRemoteNodeIdentifierCommandResponse(TXBeeSerialNumber *pSerialNumber, TNodeIdentifierReply *pReply, ubyte nDataLength);


	typedef struct  TZBPegs
	{
		int pegMessages[kSizeOfXBeeNodeTable];
		int pegSuccess[kSizeOfXBeeNodeTable];
		int pegRetransmit[kSizeOfXBeeNodeTable];
		int pegFailed[kSizeOfXBeeNodeTable];
	} TZBPegs;

	extern TZBPegs xbPegs[kSizeOfXBeeNodeTable];
	extern void incrementXBeeMessagePeg(TXBPegType pegType, TNodeIndices nToNode);

#else

	// If not compiling for Windows then can ignore processing the content of these messages

	#define processRcvEnergyScanCommandResponse(pReply, nDataLength)
	#define processRcvATCommandReply(nFromNodeIndex, pReply, nDataLength)
	#define processRcvNodeIdentifierCommandResponse(pReply, nDataLength)
	#define processRcvNodeDiscoveryCommandResponse(pReply, nDataLength)
	#define processRcvActiveScanResponse(pReply, nDataLength)
	#define processRcvIPAddress(pReply, nDataLength)

	#define processRcvRemoteATCommandReply(pSerialNumber, pReply, nDataLength)
	#define processRcvRemoteNodeIdentifierCommandResponse(pSerialNumber, pReply, nDataLength)

	#define incrementXBeeMessagePeg(pegType, nToNode)

#endif


typedef enum TXBeeStates
{
	//
	// States related to initialization and startup
	//
	xbStateIllegalZeroValue,
	xbStateIllegalOneValue,
	xbStateIllegalTwoValue,

	xbStateNotEquipped,
	xbStateStartUp,
	xbStateStartUp_Delay1,
	xbStateStartUp_Delay2,
	xbStateStartUp_FailedToOpenFile,

	//
	// For every XBee AT startup command there are two states.
	//    1. One for the send command
	//    2. One when the reply is received. This may be a "do nothing" state.
	//
	// Some states are common to any XBee type. Some states are unique to either "ZigBee" or "WiFi" types. For the
	// unique states, if the hardware is not this type, then two states are simply skipped.
	//
	xbStateStartUp_SendGetSerialNumberHigh,					// Get serial number as first item retrieved. So that it's valid!
	xbStateStartUp_ReplyGetSerialNumberHigh,				// Get serial number as first item retrieved. So that it's valid!

	xbStateStartUp_SendGetSerialNumberLow,
	xbStateStartUp_ReplyGetSerialNumberLow,

	xbStateStartUp_SendGetPowerLevel,
	xbStateStartUp_ReplyGetPowerLevel,

	xbStateStartUp_SendSetPacketizationTimeout,
	xbStateStartUp_ReplySetPacketizationTimeout,

	xbStateStartUp_SendGetNodeName,
	xbStateStartUp_ReplyGetNodeName,

	xbStateStartUp_SendGetHardwareType,
	xbStateStartUp_ReplyGetHardwareType,

	xbStateStartUp_SendGetHardwareRevision,
	xbStateStartUp_ReplyGetHardwareRevision,

	xbStateStartUp_Send16BitAddress,
	xbStateStartUp_Reply16BitAddress,

	xbStateStartUp_SendSetChannel,
	xbStateStartUp_ReplySetChannel,
	xbStateStartUp_SendAssociateEndDeviceOff,
	xbStateStartUp_ReplyAssociateEndDeviceOff,

	xbStateStartUp_SendSetPanID,
	xbStateStartUp_ReplySetPanID,

	xbStateStartUp_SendSetCoordinatorDisable,
	xbStateStartUp_ReplySetCoordinatorDisable,

	xbStateStartUp_SendRandomDelay,
	xbStateStartUp_ReplyRandomDelay,

	xbStateStartUp_SendXBeeRetries,
	xbStateStartUp_ReplyXBeeRetries,

	xbStateStartUp_SendNodeDiscoverOptions,
	xbStateStartUp_ReplyNodeDiscoverOptions,

	xbStateStartUp_SendGetSSID,
	xbStateStartUp_ReplyGetSSID,

	xbStateStartUp_SendGetIPProtocol,
	xbStateStartUp_ReplyGetIPProtocol,

	xbStateStartUp_SendGetIPAddressingMode,
	xbStateStartUp_ReplyGetIPAddressingMode,

	xbStateStartUp_SendGetIPNetworkType,
	xbStateStartUp_ReplyGetIPNetworkType,

	xbStateStartUp_SendGetTCPTimeout,
	xbStateStartUp_ReplyGetTCPTimeout,

	xbStateStartUp_SendGetPayloadSize,
	xbStateStartUp_ReplyGetPayloadSize,

	xbStateStartUp_SendGetAssociationIndication,
	xbStateStartUp_ReplyGetAssociationIndication,

	xbStateStartUp_SendGetIPAddress,
	xbStateStartUp_ReplyGetIPAddress,

	xbStateStartUp_SendGetIPGatewayAddress,
	xbStateStartUp_ReplyGetIPGatewayAddress,

	xbStateStartUp_SendGetIPDestinationPort,
	xbStateStartUp_ReplyGetIPDestinationPort,

	xbStateStartUp_SendGetIPGetAccessPointSignalStrength,
	xbStateStartUp_ReplyGetIPGetAccessPointSignalStrength,

	xbStateStartUp_SendGetSupplyVoltage,
	xbStateStartUp_ReplyGetSupplyVoltage,

	xbStateStartUp_SendGetTemperature,
	xbStateStartUp_ReplyGetGetTemperature,

	xbStateStartUp_SendWriteChangesToNVM,
	xbStateStartUp_ReplyWriteChangesToNVM,

	xbStateStartUp_15,
	xbStateStartUp_16,
	xbStateStartUp_17,
	xbStateStartUp_18,
	xbStateStartUp_19,

	// End of States related to initialization and startup
	///////////////////////////////////////////////////////////////////////////////////////

	//
	// These must be the last states for the state machine
	//
	xbStateIdleReadyForCommand,													// Must be first one
	xbStateIdleGuardTimeBetweenCommands,
	xbStateWaitingForCommandReply,
	xbStateWaitingForCommandRetransmitReply,
} TXBeeStates;

typedef struct TXBeeControlParms
{
	bool bPacketReceived;
	TXBeeStates nXBeeState;

	// Parameters

	TXBeeSerialNumber		mySerialNumberABC;
	uword nPanID;
	ubyte	nChannel;
	ubyte	nMyNodeIndex;

	// Internal State Variables

	ubyte nFrameID;
	uword nWaitForReplyTicksRemaining;
	ubyte nInterMsgInterval[3];
	ubyte nNextNodeToPoll;
	bool  bSendXmitReply;
	ubyte nXmitPacketChecksum;

	// Receive Message

	TXBeeRcvState nRcvState;
	ubyte nCurrByteIndexInPacket;

	ubyte partialReceivedPacket[kMaxPacketLength];
	ubyte receivedPacket[kMaxPacketLength];
	ubyte receivedMessage[kMaxPacketLength];
	ubyte nSizeReceivedMessage;
	ubyte nReceivedPacketChecksum;
	ubyte xbInterCharTimeoutCount;
	uword nPacketDataLength;

	TXbeeAPIXmitMessageTypes nLastCommandTypeSent;
	TATCommands nLastATCommandSent;
	TATCommands nLastATReplyRcvd;
	ubyte nMsgToNode;
	ubyte nLastFrameIDSent;
	ubyte nLastFrameIDRcvd;
	bool  bLastCommandFailed;

} TXBeeControlParms;

#if defined(_WINDOWS)

	#undef CLASS_DECLSPEC_XBeeSerialPorts
	#ifdef _EXPORTING_XBeeSerialPorts
		#define CLASS_DECLSPEC_XBeeSerialPorts    __declspec(dllexport)
	#else
		#define CLASS_DECLSPEC_XBeeSerialPorts    __declspec(dllimport)
	#endif

	extern CLASS_DECLSPEC_XBeeSerialPorts TXBeeControlParms xbPortData[kNumbOfSpecialCommPortTypes];
	extern CLASS_DECLSPEC_XBeeSerialPorts TNodeIndices getHostNodeIndexForSpecialComPortType(TStandardCommPortUsage nCommPortType);

#else

	extern TXBeeControlParms xbPortData[1];
	#define getHostNodeIndexForSpecialComPortType(nCommPortType) ((TNodeIndices) 0xFF)

#endif

#if defined(_WINDOWS) || defined(Simulator)

	#undef CLASS_DECLSPEC_XBeePrint
	#ifdef _EXPORTING_XBeePrint
		#define CLASS_DECLSPEC_XBeePrint    __declspec(dllexport)
	#else
		#define CLASS_DECLSPEC_XBeePrint    __declspec(dllimport)
	#endif


	extern CLASS_DECLSPEC_XBeePrint void debugPrintXBeePacketRcvViaNodeIndex(enum TStandardCommPortUsage nRcvComPortIndex, struct TResponseHeader *pReply);
	extern CLASS_DECLSPEC_XBeePrint void debugPrintXBeePacketXmitViaNodeIndex(const TStandardCommPortUsage nFromComPort, TXBeeSendType nSendType, unsigned char *pChar, unsigned char nNumbOfChar);

	extern CLASS_DECLSPEC_XBeePrint void debugPrintXBeePacketXmit(TXBeeSendType nSendType, const TXBeeSerialNumber *pFromSerialNumber, unsigned char *pChar, unsigned char nNumbOfChar);

#else
	#define debugPrintXBeePacketRcvViaNodeIndex(nRcvComPortIndex, pReply)
	#define debugPrintXBeePacketXmit(nFromComPort, nSendType, pChar, nNumbOfChar)
	#define debugPrintXBeePacketRcv(pToSerialNumber, pReply)
#endif


#endif //#if defined(bHasMultRobotNetworking)

#ifdef __cplusplus
};
#endif

#endif
