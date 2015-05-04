#if !defined(__XBeeSerialIOD__H_)
#define __XBeeSerialIOD__H_


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                          Low Level Platform Specific ZigBee Char Send/Receive Functions
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C"
{
#endif

extern bool startupXBeeSerialLink(void);
extern void shutdownXBeeSerialLink(void);

extern bool getXBChar(unsigned char *pChar);
extern void sendXBChar(unsigned char currChar);

extern void xmitXBeePacketStart(void);
extern void xmitXBeePacketEnd(void);

extern void xmitXBeePacketRetransmit(void);
extern void xmitXBeePacketTransmitFailed(void);

typedef enum TXBeeSendType
{
	sendTypeNormal,
	sendTypeRetransmit,
	sendTypeFailed
} TXBeeSendType;

extern void xmitXBeePacketEndLowLevel(TXBeeSendType nSendType);

#ifdef __cplusplus
};
#endif

#endif //#if !defined(__XBeeSerialIOD__H_)
