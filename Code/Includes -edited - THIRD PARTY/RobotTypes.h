#if !defined(__RobotTypes_H__)
#define __RobotTypes_H__

typedef enum TRobotTypes
{
	rbtTypeBadValue					= 0,
	rbtTypeNXT,
	rbtTypeVEX0_5,
	rbtTypeVEX2_0,
	rbtTypeArduinoAtMega328,
	rbtTypeArduinoAtMega128,
	rbtTypeArduinoAtMega1280, // or AtMeg2560
	rbtTypeArduinoAtMega32u4,
	rbtTypeArduinoDue,
	rbtTypeSTM8,
	rbtTypeSTM32,
	rbtTypeStellaris,
	rbtChipKit,
	rbtTypeAtmelCortex,
	rbtTypeVexIQ,
	rbtTypeLegoEV3,
} TRobotTypes;

#endif
