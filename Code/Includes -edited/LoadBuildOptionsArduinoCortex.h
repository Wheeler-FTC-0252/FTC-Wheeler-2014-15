////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for Arduino Cortex
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// ArduinoCortex
#define	ramtype																												// ArduinoCortex
#define	neartype																											// ArduinoCortex
#define	ramfunc																												// ArduinoCortex
#define	no_init																												// ArduinoCortex
//#undef inline																												// ArduinoCortex

#define	bFirmwareStoresMotorType																			// ArduinoCortex
#define	bFirmwareStoresMotorDriveSide																	// ArduinoCortex
#define	bIncludeMotorTypeInUploadMessage() true		 										// ArduinoCortex
#define	bMotorMirroring																								// ArduinoCortex
#undef	bMotorsWithEncoders																						// ArduinoCortex
#undef	bMotorsWithCurrentLimiting																		// ArduinoCortex
#define	bSmartMotorsWithEncoders()   1																// ArduinoCortex
#define	kSizeOfDefaultPidSettingsTable 6															// ArduinoCortex
#define	bAssociateMotorWithEncoderSensor															// ArduinoCortex
#undef	bHasEncoderTimeStamp																					// ArduinoCortex
#undef	bHasEncoderVelocity																						// ArduinoCortex
#define	bAssociateMotorWithIOPins 																		// ArduinoCortex
#define	bIncludeMotorEncoderInUploadMessage true		 									// ArduinoCortex
#undef	bSpare199																 											// ArduinoCortex
#define	bSupportsSoftwareBasedServoPWM					 											// ArduinoCortex
#undef	bHasHardwareAutoDetectionMotors					 											// ArduinoCortex
#undef	bHasHardwareAutoDetectionSensors					 										// ArduinoCortex

#define	kNumbOfBreakpoints 6																					// ArduinoCortex
#define	kSystemClockSpeed  F_CPU																			// ArduinoCortex

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// ArduinoCortex
#define	optionalExceptions 																						// ArduinoCortex
#define	optionalBreakpoints 																					// ArduinoCortex
#define	optionalDebugSupport																					// ArduinoCortex
#define	hasBulkUploadlupport																					// ArduinoCortex
#define	hasOptionalUploadSupport																			// ArduinoCortex
#define	hasDeviceUploadSupport																				// ArduinoCortex
#define	optionalTrinaryOpcodes																				// ArduinoCortex
#undef	bHasOpcodeStateMachine																				// ArduinoCortex

#define	useFloats																											// ArduinoCortex
#define	useLongs																											// ArduinoCortex
#define	useStackVariables																							// ArduinoCortex

#define	hasJoystickDownloadMessageOpcodes															// ArduinoCortex
#undef	hasJoystickUploadMessageOpcodes																// ArduinoCortex
#define	hasMemMoveSupport																							// ArduinoCortex
#define	hasMemCmpSupport																							// ArduinoCortex
#define	hasStringSupport																							// ArduinoCortex
#define	has_sscanf_Support																						// ArduinoCortex
#define	hasTranscendentalSupport																			// ArduinoCortex

#define	bHasSoundSupport 0																						// ArduinoCortex
#define	bHasSoundVolume 0																							// ArduinoCortex
#undef	bHasPlayMusicalNotes																					// ArduinoCortex
#undef	bHasSoundsInRomChip																						// ArduinoCortex
#define	bHasSoundDriverOnOff 0																				// ArduinoCortex
#define	bHasSoundFiles 0																							// ArduinoCortex
#define	kSoundQueueSize 5																							// ArduinoCortex

#undef	hasCamera																											// ArduinoCortex
#undef	hasHarvardArchitecture																				// ArduinoCortex
#define	kMaxTimeBetweenMessageChars 15																// ArduinoCortex
#define	hasDebugStreamSupport																					// ArduinoCortex
#define	kDebugStreamDefaultBufferSize 4000														// ArduinoCortex
#define	kRamBaseAddr 0																								// ArduinoCortex
#define	bHasDatalog																										// ArduinoCortex
#define	kDatalogDefaultBufferSize 4000																// ArduinoCortex
#undef	bHasDatalogSave																								// ArduinoCortex
#undef	bHasMessageStatistics																					// ArduinoCortex
#undef	TETRIX_CAPABLE																								// ArduinoCortex

#undef	hasAlphaNumericLCDDisplayViaUART															// ArduinoCortex
#undef	bHasLCDGraphicsDisplay																				// ArduinoCortex
#undef	hasLCDMenuFunctions																						// ArduinoCortex
#define bPixelByteContainsColumnData() true														// ArduinoCortex
#define bPixelRowsLSBFirst()					 true														// ArduinoCortex
#undef	hasLCDBacklight																								// ArduinoCortex
#undef	kScreenWidth																									// ArduinoCortex
#undef	kScreenHeight																									// ArduinoCortex
#undef	kFirstVisibleScreenRow   																			// ArduinoCortex
#undef	hasLCDButtons																									// ArduinoCortex
#undef	hasStatusLEDs																									// ArduinoCortex
#undef	bHasLCDContrast																								// ArduinoCortex
#undef	bHasRemoteButtons																							// ArduinoCortex

#undef	bUseLookupBreakpointTableInRAM																// ArduinoCortex
#undef	bHasFloatDuringInactivePWM																		// ArduinoCortex
#define	nnRobotType	rbtTypeArduinoAtMega1280													// ArduinoCortex
#undef	bHasServoSpecificSourceTypes																	// ArduinoCortex
#undef	bHasSourceTypeSensorRawValue																	// ArduinoCortex
#undef	bHasSourceTypeSensorMode																			// ArduinoCortex
#define	nUploadSensorValueType sensorUploadSizeShortX									// ArduinoCortex
#undef	hasWatchDogTimerFunctions																			// ArduinoCortex
#define	bHasClearFlashOpcodes																					// ArduinoCortex
#undef	hasSpareOption9																								// ArduinoCortex

#define	kSizeOfTLargeValue         4																	// ArduinoCortex

#undef	bHasReadBatteryVoltage																				// ArduinoCortex
#undef	bHasStandardBatteryMonitoring																	// ArduinoCortex
#undef	bHasSoftwareControlledPowerOnOff															// ArduinoCortex
#undef	bHasSoftwareControlledPowerOnOffTiming												// ArduinoCortex
#undef	UNUSED__23                     																// ArduinoCortex
#define	bHasShiftOutOpcode																						// ArduinoCortex
#define	bHasRandomFunctions																						// ArduinoCortex
#define	bHasBulkClearSensorFunction																		// ArduinoCortex
#define	bHasBulkClearMotorFunction																		// ArduinoCortex

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// ArduinoCortex
#define bSoftwareMustStartADCConversionCycle													// ArduinoCortex
#define	useSimpleADCArrayLookup																				// ArduinoCortex
#define	includeSonarSensorSupportTwoPins															// ArduinoCortex  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// ArduinoCortex  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// ArduinoCortex  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// ArduinoCortex  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 1																						// ArduinoCortex
#define	bHasSensorBiasSettings																				// ArduinoCortex
#undef	bHasI2CPort																										// ArduinoCortex
#undef	bHasDaisyChainedI2C																						// ArduinoCortex
#undef	nFirstAutoDaisyChainI2CAddress																// ArduinoCortex
#define	bHasGetSensorRawADValue																				// ArduinoCortex
#define	bHasFastSonarSensor																						// ArduinoCortex

#define	kNumbAnalogSensors 	 16																				// ArduinoCortex
#define	kNumbDigitalSensors  53																				// ArduinoCortex
#define	kNumbSensorsOnI2CPorts  0																			// ArduinoCortex
#define	kMaxNumbofComplicatedSensors  12															// ArduinoCortex
#define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ArduinoCortex

#define	bHasSystemTaskForUserProgramComplete													// ArduinoCortex
#define	bHasSemaphoreSupport																					// ArduinoCortex
#define	kMaxBytesPerDataBytesUpload   65															// ArduinoCortex
#define	kReceivedOpcodeSize           70															// ArduinoCortex
#define	bGetClearVariablesOnPgmStart()   true													// ArduinoCortex
#define	bHasPropertyOpcodes																						// ArduinoCortex
#undef	hasDriveTrainConfiguration																		// ArduinoCortex
#undef	hasJoystickAxisConfiguration																	// ArduinoCortex
#undef	hasMotorOpcodes																								// ArduinoCortex
#undef	platformDriversBufferOutgoingSerialData												// ArduinoCortex
#undef	platformDriversBufferIncomingSerialData												// ArduinoCortex
#define	DelayTimeForStartupProgram()   0															// ArduinoCortex
#undef	spareOption16																									// ArduinoCortex
#undef	spareOption17																									// ArduinoCortex
#undef	spareOption18																									// ArduinoCortex
#undef	spareOption19																									// ArduinoCortex
#undef	spareOption20																									// ArduinoCortex
#undef	spareOption21																									// ArduinoCortex
#undef	spareOption22																									// ArduinoCortex
#undef	spareOption23																									// ArduinoCortex
#undef	spareOption24																									// ArduinoCortex
#undef	bUserMessagesAllowed																					// ArduinoCortex

#undef	bHasMultRobotNetworking																				// ArduinoCortex
#undef	bSystemUARTSupportsZigBee																			// ArduinoCortex
#undef	bHasZigBeeFeatureSpare0																				// ArduinoCortex
#undef	bHasZigBeeFeatureSpare1																				// ArduinoCortex
#undef	bHasZigBeeFeatureSpare2																				// ArduinoCortex
#define kNumbOfZigBeeMessageBuffers		0																// ArduinoCortex

#define	kNumbOfTasks									(4)															// ArduinoCortex
#define	kNumbOfGlobalVariablesInBytes	(15000)													// ArduinoCortex
#define	kSpareA01											(0)															// ArduinoCortex
#define	kNumbOfRealMotors             (12)														// ArduinoCortex
#define	kNumbOfRealServos             ((ubyte) 9)											// ArduinoCortex
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoCortex
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoCortex

#undef	bSupportsInvokeBootloaderOpcode																// ArduinoCortex
#define	bSupportsFlashWriteOpcodes              (1) 									// ArduinoCortex
#define	bSpareFlagABC	(0)													 										// ArduinoCortex
#define	bSupportsRAMWriteOpcodes																			// ArduinoCortex

#define	bHasFlashFileSystem																						// ArduinoCortex
#undef	bHasFlashFileSystemDelete																			// ArduinoCortex
#define	bUsesFlashStorage																							// ArduinoCortex
#define	kFlashSectorSize							256    // 128 words (16-bits)		// ArduinoCortex
#define	kMaxNumbofFlashFiles					16															// ArduinoCortex
#define	kVTOCItemSize									4																// ArduinoCortex
#define	kStoreRobotNameInPersistentData 1   														// ArduinoCortex
#define	bStoreStartupUARTTypesInPersistentData() (1)									// ArduinoCortex
#define	kSizeOfFlashMemoryPtr					4																// ArduinoCortex
#define	kSizeOfRAMMemoryPtrInHW				4																// ArduinoCortex

#undef	bHasEvents																										// ArduinoCortex
#define	kTotalCallSubStackSize				32*kNumbOfTasks									// ArduinoCortex
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// ArduinoCortex
#define	kConstantPoolSize							3200														// ArduinoCortex -- Maximum size in bytes of constant pool
#define	kStartOfFileSystem 						0x00E000												// ArduinoCortex -- Byte (and not word) address
#define	kStartOfBootloader						0x0001F800											// ArduinoCortex
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoCortex

#define	SystemUartPortCanBeReconfigured																// ArduinoCortex
#define	hasUserSerialPorts																						// ArduinoCortex
#define	getNumbOfSerialPorts()			 4																// ArduinoCortex
#define	kSizeOfXmitUartBuffer 			70																// ArduinoCortex
#define	kSizeOfRcvUartBuffer	 			40																// ArduinoCortex

#define	ARMCPU																												// ArduinoCortex
#undef	AVRCPU																												// ArduinoCortex
#undef	STM8CPU																												// ArduinoCortex
#undef	Spare1CPU																											// ArduinoCortex
#undef	Spare2CPU																											// ArduinoCortex
#undef	Spare3CPU																											// ArduinoCortex
#define	useParmForCurrOpPtr																						// ArduinoCortex

#define	ceilf     ceilf																								// ArduinoCortex
#define	floorf    floorf																							// ArduinoCortex