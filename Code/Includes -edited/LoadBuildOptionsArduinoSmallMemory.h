////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for Arduino Small Memory
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype   __attribute__((progmem))														// ArduinoSmallMemory
#if !defined(__AVR_ATmega328P__) && !defined(__AVR_ATmega32U4__)
	//#error "Wrong or missing AVR type specified for 'ArduinoSmallMemory' project compile"
#endif																																// ArduinoSmallMemory
#define	ramtype																												// ArduinoSmallMemory
#define	neartype																											// ArduinoSmallMemory
#define	ramfunc																												// ArduinoSmallMemory
#define	no_init																												// ArduinoSmallMemory
//#undef inline																												// ArduinoSmallMemory

#define	bFirmwareStoresMotorType																			// ArduinoSmallMemory
#define	bFirmwareStoresMotorDriveSide																	// ArduinoSmallMemory
#define	bIncludeMotorTypeInUploadMessage() true		 										// ArduinoSmallMemory
#define	bMotorMirroring																								// ArduinoSmallMemory
#undef	bMotorsWithEncoders																						// ArduinoSmallMemory
#undef	bMotorsWithCurrentLimiting																		// ArduinoSmallMemory
#define	bSmartMotorsWithEncoders()   0																// ArduinoSmallMemory
#define	kSizeOfDefaultPidSettingsTable 0															// ArduinoSmallMemory
#undef	bAssociateMotorWithEncoderSensor															// ArduinoSmallMemory
#undef	bHasEncoderTimeStamp																					// ArduinoSmallMemory
#undef	bHasEncoderVelocity																						// ArduinoSmallMemory
#define	bAssociateMotorWithIOPins 																		// ArduinoSmallMemory
#undef	bIncludeMotorEncoderInUploadMessage//() true		 							// ArduinoSmallMemory
#undef	bSpare199																	 										// ArduinoSmallMemory
#define	bSupportsSoftwareBasedServoPWM						 										// ArduinoSmallMemory
#undef	bHasHardwareAutoDetectionMotors					 											// ArduinoSmallMemory
#undef	bHasHardwareAutoDetectionSensors					 										// ArduinoSmallMemory

#define	kNumbOfBreakpoints 6																					// ArduinoSmallMemory
#define	kSystemClockSpeed  F_CPU																			// ArduinoSmallMemory

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// ArduinoSmallMemory
#define	optionalExceptions 																						// ArduinoSmallMemory
#define	optionalBreakpoints 																					// ArduinoSmallMemory
#define	optionalDebugSupport																					// ArduinoSmallMemory
#define	hasBulkUploadlupport																					// ArduinoSmallMemory
#define	hasOptionalUploadSupport																			// ArduinoSmallMemory
#define	hasDeviceUploadSupport																				// ArduinoSmallMemory
#define	optionalTrinaryOpcodes																				// ArduinoSmallMemory
#undef	bHasOpcodeStateMachine																				// ArduinoSmallMemory

#undef	useFloats																											// ArduinoSmallMemory
#undef	useLongs																											// ArduinoSmallMemory
#define	useStackVariables																							// ArduinoSmallMemory

#define	hasJoystickDownloadMessageOpcodes															// ArduinoSmallMemory
#undef	hasJoystickUploadMessageOpcodes																// ArduinoSmallMemory
#undef	hasMemMoveSupport																							// ArduinoSmallMemory
#define	hasMemCmpSupport																							// ArduinoSmallMemory
#undef	hasStringSupport																							// ArduinoSmallMemory
#undef	has_sscanf_Support																						// ArduinoSmallMemory
#undef	hasTranscendentalSupport 																			// ArduinoSmallMemory

#define	bHasSoundSupport 1																						// ArduinoSmallMemory
#define	bHasSoundVolume 0																							// ArduinoSmallMemory
#undef	bHasPlayMusicalNotes																					// ArduinoSmallMemory
#undef	bHasSoundsInRomChip																						// ArduinoSmallMemory
#define	bHasSoundDriverOnOff 0																				// ArduinoSmallMemory
#define	bHasSoundFiles 0																							// ArduinoSmallMemory
#define	kSoundQueueSize 5																							// ArduinoSmallMemory

#undef	hasCamera																											// ArduinoSmallMemory
#define	hasHarvardArchitecture																				// ArduinoSmallMemory
#define	kMaxTimeBetweenMessageChars 15																// ArduinoSmallMemory
#undef	hasDebugStreamSupport																					// ArduinoSmallMemory
#define	kDebugStreamDefaultBufferSize 0																// ArduinoSmallMemory
#define	kRamBaseAddr 0																								// ArduinoSmallMemory
#undef	bHasDatalog																										// ArduinoSmallMemory
#define	kDatalogDefaultBufferSize 0																		// ArduinoSmallMemory
#undef	bHasDatalogSave																								// ArduinoSmallMemory
#undef	bHasMessageStatistics																					// ArduinoSmallMemory
#undef	TETRIX_CAPABLE																								// ArduinoSmallMemory

#undef	hasAlphaNumericLCDDisplayViaUART															// ArduinoSmallMemory
#undef	bHasLCDGraphicsDisplay																				// ArduinoSmallMemory
#undef	hasLCDMenuFunctions																						// ArduinoSmallMemory
#define bPixelByteContainsColumnData() true														// ArduinoSmallMemory
#define bPixelRowsLSBFirst()					 true														// ArduinoSmallMemory
#undef	hasLCDBacklight																								// ArduinoSmallMemory
#undef	kScreenWidth																									// ArduinoSmallMemory
#undef	kScreenHeight																									// ArduinoSmallMemory
#undef	kFirstVisibleScreenRow																				// ArduinoSmallMemory
#undef	hasLCDButtons																									// ArduinoSmallMemory
#undef	hasStatusLEDs																									// ArduinoSmallMemory
#undef	bHasLCDContrast																								// ArduinoSmallMemory
#undef	bHasRemoteButtons																							// ArduinoSmallMemory

#define	bUseLookupBreakpointTableInRAM																// ArduinoSmallMemory
#undef	bHasFloatDuringInactivePWM																		// ArduinoSmallMemory
#define	nnRobotType	rbtTypeArduinoAtMega328														// ArduinoSmallMemory
#undef	bHasServoSpecificSourceTypes																	// ArduinoSmallMemory
#undef	bHasSourceTypeSensorRawValue																	// ArduinoSmallMemory
#undef	bHasSourceTypeSensorMode																			// ArduinoSmallMemory
#define	nUploadSensorValueType sensorUploadSizeShortX									// ArduinoSmallMemory
#undef	hasWatchDogTimerFunctions																			// ArduinoSmallMemory
#undef	bHasClearFlashOpcodes																					// ArduinoSmallMemory
#undef	hasSpareOption9																								// ArduinoSmallMemory

#define	kSizeOfTLargeValue				 2																	// ArduinoSmallMemory

#undef	bHasReadBatteryVoltage																				// ArduinoSmallMemory
#undef	bHasStandardBatteryMonitoring																	// ArduinoSmallMemory
#undef	bHasSoftwareControlledPowerOnOff															// ArduinoSmallMemory
#undef	bHasSoftwareControlledPowerOnOffTiming												// ArduinoSmallMemory
#undef	UNUSED__23                     																// ArduinoSmallMemory
#define	bHasShiftOutOpcode																						// ArduinoSmallMemory
#define	bHasRandomFunctions																						// ArduinoSmallMemory
#define	bHasBulkClearSensorFunction																		// ArduinoSmallMemory
#define	bHasBulkClearMotorFunction																		// ArduinoSmallMemory

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// ArduinoSmallMemory
#define bSoftwareMustStartADCConversionCycle													// ArduinoSmallMemory
#define	useSimpleADCArrayLookup																				// ArduinoSmallMemory
#define	includeSonarSensorSupportTwoPins															// ArduinoSmallMemory  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// ArduinoSmallMemory  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// ArduinoSmallMemory  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// ArduinoSmallMemory  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 1																						// ArduinoSmallMemory
#define	bHasSensorBiasSettings																				// ArduinoSmallMemory
#undef	bHasI2CPort																										// ArduinoSmallMemory
#undef	bHasDaisyChainedI2C																						// ArduinoSmallMemory
#undef	nFirstAutoDaisyChainI2CAddress																// ArduinoSmallMemory
#define	bHasGetSensorRawADValue																				// ArduinoSmallMemory
#define	bHasFastSonarSensor																						// ArduinoSmallMemory

#define	kNumbAnalogSensors 	 6																				// ArduinoSmallMemory
#define	kNumbDigitalSensors  14																				// ArduinoSmallMemory
#define	kNumbSensorsOnI2CPorts  0																			// ArduinoSmallMemory
#define	kMaxNumbofComplicatedSensors  6																// ArduinoSmallMemory
#define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ArduinoSmallMemory

#define	bHasSystemTaskForUserProgramComplete													// ArduinoSmallMemory
#undef	bHasSemaphoreSupport																					// ArduinoSmallMemory
#define	kMaxBytesPerDataBytesUpload   65															// ArduinoSmallMemory
#define	kReceivedOpcodeSize           70															// ArduinoSmallMemory
#define	bGetClearVariablesOnPgmStart()   true													// ArduinoSmallMemory
#define	bHasPropertyOpcodes																						// ArduinoSmallMemory
#undef	hasDriveTrainConfiguration																		// ArduinoSmallMemory
#undef	hasJoystickAxisConfiguration																	// ArduinoSmallMemory
#undef	hasMotorOpcodes																								// ArduinoSmallMemory
#undef	platformDriversBufferOutgoingSerialData												// ArduinoSmallMemory
#undef	platformDriversBufferIncomingSerialData												// ArduinoSmallMemory
#define	DelayTimeForStartupProgram()   0															// ArduinoSmallMemory
#undef	spareOption16																									// ArduinoSmallMemory
#undef	spareOption17																									// ArduinoSmallMemory
#undef	spareOption18																									// ArduinoSmallMemory
#undef	spareOption19																									// ArduinoSmallMemory
#undef	spareOption20																									// ArduinoSmallMemory
#undef	spareOption21																									// ArduinoSmallMemory
#undef	spareOption22																									// ArduinoSmallMemory
#undef	spareOption23																									// ArduinoSmallMemory
#undef	spareOption24																									// ArduinoSmallMemory
#undef	bUserMessagesAllowed																					// ArduinoSmallMemory

#undef	bHasMultRobotNetworking																				// ArduinoSmallMemory
#undef	bSystemUARTSupportsZigBee																			// ArduinoSmallMemory
#undef	bHasZigBeeFeatureSpare0																				// ArduinoSmallMemory
#undef	bHasZigBeeFeatureSpare1																				// ArduinoSmallMemory
#undef	bHasZigBeeFeatureSpare2																				// ArduinoSmallMemory
#define kNumbOfZigBeeMessageBuffers		0																// ArduinoSmallMemory

#define	kNumbOfTasks									(4)															// ArduinoSmallMemory
#define	kNumbOfGlobalVariablesInBytes	(256)														// ArduinoSmallMemory
#define	kSpareA01											(0)															// ArduinoSmallMemory
#define	kNumbOfRealMotors             (8)															// ArduinoSmallMemory
#define	kNumbOfRealServos             ((ubyte) 0)											// ArduinoSmallMemory
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoSmallMemory
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoSmallMemory

#define	bSupportsInvokeBootloaderOpcode																// ArduinoSmallMemory
#define	bSupportsFlashWriteOpcodes              (1) 									// ArduinoSmallMemory
#define	bSpareFlagABC	(0)													 										// ArduinoSmallMemory
#define	bSupportsRAMWriteOpcodes																			// ArduinoSmallMemory

#define	bHasFlashFileSystem																						// ArduinoSmallMemory
#undef	bHasFlashFileSystemDelete																			// ArduinoSmallMemory
#define	bUsesFlashStorage																							// ArduinoSmallMemory
#define	kFlashSectorSize							128     // 64 words (16-bits)		// ArduinoSmallMemory
#define	kMaxNumbofFlashFiles					12															// ArduinoSmallMemory
#define	kVTOCItemSize									4																// ArduinoSmallMemory
#define	kStoreRobotNameInPersistentData 1   														// ArduinoSmallMemory
#define	bStoreStartupUARTTypesInPersistentData() (1)									// ArduinoSmallMemory
#define	kSizeOfFlashMemoryPtr					2																// ArduinoSmallMemory
#define	kSizeOfRAMMemoryPtrInHW				2																// ArduinoSmallMemory

#undef	bHasEvents																										// ArduinoSmallMemory
#define	kTotalCallSubStackSize				32*kNumbOfTasks									// ArduinoSmallMemory
#define	kTotalVariablesStackSize			64*kNumbOfTasks									// ArduinoSmallMemory
#undef kConstantPoolSize																							// ArduinoSmallMemory -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 						(0x3400UL * 2)									// ArduinoSmallMemory -- Byte (and not word) address
#if defined(__AVR_ATmega328P__)
	#define	kStartOfBootloader					(0x3C00UL * 2)									// ArduinoSmallMemory	-- atMega328P
#else
	#define	kStartOfBootloader					(0x3800UL * 2)									// ArduinoSmallMemory	-- AtMega32U4
#endif
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoSmallMemory

#define	SystemUartPortCanBeReconfigured																// ArduinoSmallMemory
#define	hasUserSerialPorts																						// ArduinoSmallMemory
#if defined(__AVR_ATmega328P__)
	#define	getNumbOfSerialPorts()     1																// ArduinoSmallMemory	-- atMega328P
#else
	#define	getNumbOfSerialPorts()     2																// ArduinoSmallMemory	-- AtMega32U4
#endif
#define	kSizeOfXmitUartBuffer 			70																// ArduinoSmallMemory
#define	kSizeOfRcvUartBuffer	 			25																// ArduinoSmallMemory

#undef	ARMCPU																												// ArduinoSmallMemory
#define	AVRCPU																												// ArduinoSmallMemory
#undef	STM8CPU																												// ArduinoSmallMemory
#undef	Spare1CPU																											// ArduinoSmallMemory
#undef	Spare2CPU																											// ArduinoSmallMemory
#undef	Spare3CPU																											// ArduinoSmallMemory
#undef	useParmForCurrOpPtr																						// ArduinoSmallMemory

#define	ceilf     ceil																								// ArduinoSmallMemory
#define	floorf    floor																								// ArduinoSmallMemory
