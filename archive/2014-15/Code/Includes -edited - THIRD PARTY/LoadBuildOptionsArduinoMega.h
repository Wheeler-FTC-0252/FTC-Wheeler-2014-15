////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for Arduino MEGA
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype   __attribute__((progmem))														// ArduinoMega
#define	ramtype																												// ArduinoMega
#define	neartype																											// ArduinoMega
#define	ramfunc																												// ArduinoMega
#define	no_init																												// ArduinoMega
//#undef inline																												// ArduinoMega

#define	bFirmwareStoresMotorType																			// ArduinoMega
#define	bFirmwareStoresMotorDriveSide																	// ArduinoMega
#define	bIncludeMotorTypeInUploadMessage() true		 										// ArduinoMega
#define	bMotorMirroring																								// ArduinoMega
#undef	bMotorsWithEncoders																						// ArduinoMega
#undef	bMotorsWithCurrentLimiting																		// ArduinoMega
#define	bSmartMotorsWithEncoders()   1																// ArduinoMega
#define	kSizeOfDefaultPidSettingsTable 6															// ArduinoMega
#define	bAssociateMotorWithEncoderSensor															// ArduinoMega
#undef	bHasEncoderTimeStamp																					// ArduinoMega
#undef	bHasEncoderVelocity																						// ArduinoMega
#define	bAssociateMotorWithIOPins 																		// ArduinoMega
#define	bIncludeMotorEncoderInUploadMessage true		 									// ArduinoMega
#undef	bSpare199																 											// ArduinoMega
#define	bSupportsSoftwareBasedServoPWM					 											// ArduinoMega
#undef	bHasHardwareAutoDetectionMotors					 											// ArduinoMega
#undef	bHasHardwareAutoDetectionSensors					 										// ArduinoMega

#define	kNumbOfBreakpoints 6																					// ArduinoMega
#define	kSystemClockSpeed  F_CPU																			// ArduinoMega

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// ArduinoMega
#define	optionalExceptions 																						// ArduinoMega
#define	optionalBreakpoints 																					// ArduinoMega
#define	optionalDebugSupport																					// ArduinoMega
#define	hasBulkUploadlupport																					// ArduinoMega
#define	hasOptionalUploadSupport																			// ArduinoMega
#define	hasDeviceUploadSupport																				// ArduinoMega
#define	optionalTrinaryOpcodes																				// ArduinoMega
#undef	bHasOpcodeStateMachine																				// ArduinoMega

#define	useFloats																											// ArduinoMega
#define	useLongs																											// ArduinoMega
#define	useStackVariables																							// ArduinoMega

#define	hasJoystickDownloadMessageOpcodes															// ArduinoMega
#undef	hasJoystickUploadMessageOpcodes																// ArduinoMega
#define	hasMemMoveSupport																							// ArduinoMega
#define	hasMemCmpSupport																							// ArduinoMega
#define	hasStringSupport																							// ArduinoMega
#define	has_sscanf_Support																						// ArduinoMega
#define	hasTranscendentalSupport																			// ArduinoMega

#define	bHasSoundSupport 1																						// ArduinoMega
#define	bHasSoundVolume 0																							// ArduinoMega
#undef	bHasPlayMusicalNotes																					// ArduinoMega
#undef	bHasSoundsInRomChip																						// ArduinoMega
#define	bHasSoundDriverOnOff 0																				// ArduinoMega
#define	bHasSoundFiles 0																							// ArduinoMega
#define	kSoundQueueSize 5																							// ArduinoMega

#undef	hasCamera																											// ArduinoMega
#define	hasHarvardArchitecture																				// ArduinoMega
#define	kMaxTimeBetweenMessageChars 15																// ArduinoMega
#define	hasDebugStreamSupport																					// ArduinoMega
#define	kDebugStreamDefaultBufferSize 300															// ArduinoMega
#define	kRamBaseAddr 0																								// ArduinoMega
#undef	bHasDatalog																										// ArduinoMega
#define	kDatalogDefaultBufferSize 0																		// ArduinoMega
#undef	bHasDatalogSave																								// ArduinoMega
#undef	bHasMessageStatistics																					// ArduinoMega
#undef	TETRIX_CAPABLE																								// ArduinoMega

#undef	hasAlphaNumericLCDDisplayViaUART															// ArduinoMega
#undef	bHasLCDGraphicsDisplay																				// ArduinoMega
#undef	hasLCDMenuFunctions																						// ArduinoMega
#define bPixelByteContainsColumnData() true														// ArduinoMega
#define bPixelRowsLSBFirst()					 true														// ArduinoMega
#undef	hasLCDBacklight																								// ArduinoMega
#undef	kScreenWidth																									// ArduinoMega
#undef	kScreenHeight																									// ArduinoMega
#undef	kFirstVisibleScreenRow   																			// ArduinoMega
#undef	hasLCDButtons																									// ArduinoMega
#undef	hasStatusLEDs																									// ArduinoMega
#undef	bHasLCDContrast																								// ArduinoMega
#undef	bHasRemoteButtons																							// ArduinoMega

#define	bUseLookupBreakpointTableInRAM																// ArduinoMega
#undef	bHasFloatDuringInactivePWM																		// ArduinoMega
#define	nnRobotType	rbtTypeArduinoAtMega1280													// ArduinoMega
#undef	bHasServoSpecificSourceTypes																	// ArduinoMega
#undef	bHasSourceTypeSensorRawValue																	// ArduinoMega
#undef	bHasSourceTypeSensorMode																			// ArduinoMega
#define	nUploadSensorValueType sensorUploadSizeShortX									// ArduinoMega
#undef	hasWatchDogTimerFunctions																			// ArduinoMega
#define	bHasClearFlashOpcodes																					// ArduinoMega
#undef	hasSpareOption9																								// ArduinoMega

#define	kSizeOfTLargeValue         4																	// ArduinoMega

#undef	bHasReadBatteryVoltage																				// ArduinoMega
#undef	bHasStandardBatteryMonitoring																	// ArduinoMega
#undef	bHasSoftwareControlledPowerOnOff															// ArduinoMega
#undef	bHasSoftwareControlledPowerOnOffTiming												// ArduinoMega
#undef	UNUSED__23                     																// ArduinoMega
#define	bHasShiftOutOpcode																						// ArduinoMega
#define	bHasRandomFunctions																						// ArduinoMega
#define	bHasBulkClearSensorFunction																		// ArduinoMega
#define	bHasBulkClearMotorFunction																		// ArduinoMega

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// ArduinoMega
#define bSoftwareMustStartADCConversionCycle													// ArduinoMega
#define	useSimpleADCArrayLookup																				// ArduinoMega
#define	includeSonarSensorSupportTwoPins															// ArduinoMega  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// ArduinoMega  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// ArduinoMega  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// ArduinoMega  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 1																						// ArduinoMega
#define	bHasSensorBiasSettings																				// ArduinoMega
#undef	bHasI2CPort																										// ArduinoMega
#undef	bHasDaisyChainedI2C																						// ArduinoMega
#undef	nFirstAutoDaisyChainI2CAddress																// ArduinoMega
#define	bHasGetSensorRawADValue																				// ArduinoMega
#define	bHasFastSonarSensor																						// ArduinoMega

#define	kNumbAnalogSensors 	 16																				// ArduinoMega
#define	kNumbDigitalSensors  53																				// ArduinoMega
#define	kNumbSensorsOnI2CPorts  0																			// ArduinoMega
#define	kMaxNumbofComplicatedSensors  12															// ArduinoMega
#define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ArduinoMega

#define	bHasSystemTaskForUserProgramComplete													// ArduinoMega
#define	bHasSemaphoreSupport																					// ArduinoMega
#define	kMaxBytesPerDataBytesUpload   65															// ArduinoMega
#define	kReceivedOpcodeSize           70															// ArduinoMega
#define	bGetClearVariablesOnPgmStart()   true													// ArduinoMega
#define	bHasPropertyOpcodes																						// ArduinoMega
#undef	hasDriveTrainConfiguration																		// ArduinoMega
#undef	hasJoystickAxisConfiguration																	// ArduinoMega
#undef	hasMotorOpcodes																								// ArduinoMega
#undef	platformDriversBufferOutgoingSerialData												// ArduinoMega
#undef	platformDriversBufferIncomingSerialData												// ArduinoMega
#define	DelayTimeForStartupProgram()   0															// ArduinoMega
#undef	spareOption16																									// ArduinoMega
#undef	spareOption17																									// ArduinoMega
#undef	spareOption18																									// ArduinoMega
#undef	spareOption19																									// ArduinoMega
#undef	spareOption20																									// ArduinoMega
#undef	spareOption21																									// ArduinoMega
#undef	spareOption22																									// ArduinoMega
#undef	spareOption23																									// ArduinoMega
#undef	spareOption24																									// ArduinoMega
#undef	bUserMessagesAllowed																					// ArduinoMega

#undef	bHasMultRobotNetworking																				// ArduinoMega
#undef	bSystemUARTSupportsZigBee																			// ArduinoMega
#undef	bHasZigBeeFeatureSpare0																				// ArduinoMega
#undef	bHasZigBeeFeatureSpare1																				// ArduinoMega
#undef	bHasZigBeeFeatureSpare2																				// ArduinoMega
#define kNumbOfZigBeeMessageBuffers		0																// ArduinoMega

#define	kNumbOfTasks									(4)															// ArduinoMega
#define	kNumbOfGlobalVariablesInBytes	(1024)													// ArduinoMega
#define	kSpareA01											(0)															// ArduinoMega
#define	kNumbOfRealMotors             (12)														// ArduinoMega
#define	kNumbOfRealServos             ((ubyte) 9)											// ArduinoMega
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoMega
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoMega

#define	bSupportsInvokeBootloaderOpcode																// ArduinoMega
#define	bSupportsFlashWriteOpcodes              (1) 									// ArduinoMega
#define	bSpareFlagABC	(0)													 										// ArduinoMega
#define	bSupportsRAMWriteOpcodes																			// ArduinoMega

#define	bHasFlashFileSystem																						// ArduinoMega
#undef	bHasFlashFileSystemDelete																			// ArduinoMega
#define	bUsesFlashStorage																							// ArduinoMega
#define	kFlashSectorSize							256    // 128 words (16-bits)		// ArduinoMega
#define	kMaxNumbofFlashFiles					16															// ArduinoMega
#define	kVTOCItemSize									4																// ArduinoMega
#define	kStoreRobotNameInPersistentData 1   														// ArduinoMega
#define	bStoreStartupUARTTypesInPersistentData() (1)									// ArduinoMega
#define	kSizeOfFlashMemoryPtr					4																// ArduinoMega
#define	kSizeOfRAMMemoryPtrInHW				2																// ArduinoMega

#undef	bHasEvents																										// ArduinoMega
#define	kTotalCallSubStackSize				32*kNumbOfTasks									// ArduinoMega
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// ArduinoMega
#define	kConstantPoolSize							300															// ArduinoMega -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 						(0x09000UL * 2)									// ArduinoMega -- NOTE: Byte (and not word) address
#define	kStartOfBootloader						(0x1F000UL * 2)									// ArduinoMega
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoMega

#define	SystemUartPortCanBeReconfigured																// ArduinoMega
#define	hasUserSerialPorts																						// ArduinoMega
#define	getNumbOfSerialPorts()			 4																// ArduinoMega
#define	kSizeOfXmitUartBuffer 			70																// ArduinoMega
#define	kSizeOfRcvUartBuffer	 			40																// ArduinoMega

#undef	ARMCPU																												// ArduinoMega
#define	AVRCPU																												// ArduinoMega
#undef	STM8CPU																												// ArduinoMega
#undef	Spare1CPU																											// ArduinoMega
#undef	Spare2CPU																											// ArduinoMega
#undef	Spare3CPU																											// ArduinoMega
#undef	useParmForCurrOpPtr																						// ArduinoMega

#define	ceilf     ceil																								// ArduinoMega
#define	floorf    floor																								// ArduinoMega
