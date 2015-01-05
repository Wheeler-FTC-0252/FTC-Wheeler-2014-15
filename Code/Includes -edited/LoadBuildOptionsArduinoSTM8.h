////////////////////////////////////////////////////////////////////////////////////////////////////
//
//												Load Build Options for Arduino STM8
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// STM8
#define	ramtype																												// STM8
#define	neartype	__near																							// STM8
#define	ramfunc																												// STM8
#define	no_init		__no_init																						// STM8
//#undef inline																												// STM8

#define	bFirmwareStoresMotorType																			// STM8
#define	bFirmwareStoresMotorDriveSide																	// STM8
#define	bIncludeMotorTypeInUploadMessage() true		 										// STM8
#define	bMotorMirroring																								// STM8
#undef	bMotorsWithEncoders																						// STM8
#undef	bMotorsWithCurrentLimiting																		// STM8
#define	bSmartMotorsWithEncoders()   0																// STM8
#define	kSizeOfDefaultPidSettingsTable 0															// STM8
#define	bAssociateMotorWithEncoderSensor															// STM8
#undef	bHasEncoderTimeStamp																					// STM8
#undef	bHasEncoderVelocity																						// STM8
#define	bAssociateMotorWithIOPins 																		// STM8
#define	bIncludeMotorEncoderInUploadMessage() true		 								// STM8
#define	bSupportsSoftwareBasedMotorPWM					 											// STM8
#define	bSupportsSoftwareBasedServoPWM					 											// STM8
#undef	bHasHardwareAutoDetectionMotors					 											// STM8
#undef	bHasHardwareAutoDetectionSensors					 										// STM8

#define	kNumbOfBreakpoints 6																					// STM8
#define	 kSystemClockSpeed  16000000L																	// STM8

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// STM8
#define	optionalExceptions 																						// STM8
#define	optionalBreakpoints 																					// STM8
#define	optionalDebugSupport																					// STM8
#define	hasBulkUploadlupport																					// STM8
#define	hasOptionalUploadSupport																			// STM8
#define	hasDeviceUploadSupport																				// STM8
#define	optionalTrinaryOpcodes																				// STM8
#define	bHasOpcodeStateMachine																				// STM8

#undef	useFloats																											// STM8
#undef	useLongs																											// STM8
#define	useStackVariables																							// STM8

#undef	hasJoystickDownloadMessageOpcodes															// STM8
#undef	hasJoystickUploadMessageOpcodes																// STM8
#undef	hasMemMoveSupport																							// STM8
#define	hasMemCmpSupport																							// STM8
#undef	hasStringSupport																							// STM8
#undef	has_sscanf_Support																						// STM8
#undef	hasTranscendentalSupport 																			// STM8

#define	bHasSoundSupport 0																						// STM8
#define	bHasSoundVolume 0																							// STM8
#undef	bHasPlayMusicalNotes																					// STM8
#undef	bHasSoundsInRomChip																						// STM8
#define	bHasSoundDriverOnOff 0																				// STM8
#define	bHasSoundFiles 0																							// STM8
#define	kSoundQueueSize 5																							// STM8

#undef	hasCamera																											// STM8
#undef	hasHarvardArchitecture																				// STM8
#define	kMaxTimeBetweenMessageChars 15																// STM8
#undef	hasDebugStreamSupport																					// STM8
#define	kDebugStreamDefaultBufferSize	0																// STM8
#define	kRamBaseAddr 0																								// STM8
#undef	bHasDatalog																										// STM8
#define	kDatalogDefaultBufferSize 0																		// STM8
#undef	bHasDatalogSave																								// STM8
#undef	bHasMessageStatistics																					// STM8
#undef	TETRIX_CAPABLE																								// STM8

#undef	hasAlphaNumericLCDDisplayViaUART															// STM8
#undef	bHasLCDGraphicsDisplay																				// STM8
#undef	hasLCDMenuFunctions																						// STM8
#define bPixelByteContainsColumnData() true														// STM8
#define bPixelRowsLSBFirst()					 true														// STM8
#undef	hasLCDBacklight																								// STM8
#undef	kScreenWidth																									// STM8
#undef	kScreenHeight																									// STM8
#undef	kFirstVisibleScreenRow																				// STM8
#undef	hasLCDButtons																									// STM8
#undef	hasStatusLEDs																									// STM8
#undef	bHasLCDContrast																								// STM8
#undef	bHasRemoteButtons																							// STM8

#undef	bUseLookupBreakpointTableInRAM																// STM8
#undef	bHasFloatDuringInactivePWM																		// STM8
#define	nnRobotType	rbtTypeSTM8																				// STM8
#undef	bHasServoSpecificSourceTypes																	// STM8
#undef	bHasSourceTypeSensorRawValue																	// STM8
#undef	bHasSourceTypeSensorMode																			// STM8
#define	nUploadSensorValueType sensorUploadSizeShortX									// STM8
#undef	hasWatchDogTimerFunctions																			// STM8
#define	bHasClearFlashOpcodes																					// STM8
#undef	hasSpareOption9																								// STM8

#define	kSizeOfTLargeValue					 2																// STM8

#undef	bHasReadBatteryVoltage																				// STM8
#undef	bHasStandardBatteryMonitoring																	// STM8
#undef	bHasSoftwareControlledPowerOnOff															// STM8
#undef	bHasSoftwareControlledPowerOnOffTiming												// STM8
#undef	UNUSED__23                     																// STM8
#define	bHasShiftOutOpcode																						// STM8
#define	bHasRandomFunctions																						// STM8
#define	bHasBulkClearSensorFunction																		// STM8
#define	bHasBulkClearMotorFunction																		// STM8

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// STM8
#define bSoftwareMustStartADCConversionCycle													// STM8
#define	useSimpleADCArrayLookup																				// STM8
#define	includeSonarSensorSupportTwoPins															// STM8  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// STM8  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// STM8  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// STM8  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 1																						// STM8
#define	bHasSensorBiasSettings																				// STM8
#undef	bHasI2CPort																										// STM8
#undef	bHasDaisyChainedI2C																						// STM8
#undef	nFirstAutoDaisyChainI2CAddress																// STM8
#define bHasGetSensorRawADValue																				// STM8
#define	bHasFastSonarSensor																						// STM8

#define	kNumbAnalogSensors 	 6																				// STM8
#define	kNumbDigitalSensors  7 																				// STM8
#define	kNumbSensorsOnI2CPorts  4 																		// STM8
#define	kMaxNumbofComplicatedSensors  6																// STM8
#define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// STM8

#define	bHasSystemTaskForUserProgramComplete													// STM8
#define	bHasSemaphoreSupport																					// STM8
#define	kMaxBytesPerDataBytesUpload   65															// STM8
#define	kReceivedOpcodeSize           70															// STM8
#define	bGetClearVariablesOnPgmStart()   true													// STM8
#define	bHasPropertyOpcodes																						// STM8
#undef	hasDriveTrainConfiguration																		// STM8
#undef	hasJoystickAxisConfiguration																	// STM8
#undef	hasMotorOpcodes																								// STM8
#undef	platformDriversBufferOutgoingSerialData												// STM8
#undef	platformDriversBufferIncomingSerialData												// STM8
#define	DelayTimeForStartupProgram()   0															// STM8
#undef	spareOption16																									// STM8
#undef	spareOption17																									// STM8
#undef	spareOption18																									// STM8
#undef	spareOption19																									// STM8
#undef	spareOption20																									// STM8
#undef	spareOption21																									// STM8
#undef	spareOption22																									// STM8
#undef	spareOption23																									// STM8
#undef	spareOption24																									// STM8
#define	bUserMessagesAllowed																					// STM8

#undef	bHasMultRobotNetworking																				// STM8
#define	bSystemUARTSupportsZigBee																			// STM8
#undef	bHasZigBeeFeatureSpare0																				// STM8
#undef	bHasZigBeeFeatureSpare1																				// STM8
#undef	bHasZigBeeFeatureSpare2																				// STM8
#define kNumbOfZigBeeMessageBuffers		0																// STM8

#define	kNumbOfTasks									(4)															// STM8
#define	kNumbOfGlobalVariablesInBytes	(256)														// STM8
#define	kSpareA01											(0)															// STM8
#define	kNumbOfRealMotors             (8)															// STM8
#define	kNumbOfRealServos             ((ubyte) 0)											// STM8
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// STM8
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// STM8

#define	bSupportsInvokeBootloaderOpcode																// STM8
#define	bSupportsFlashWriteOpcodes              (1) 									// STM8
#define	bSpareFlagABC	(0)													 										// STM8
#define	bSupportsRAMWriteOpcodes																			// STM8

#define	bHasFlashFileSystem																						// STM8
#undef	bHasFlashFileSystemDelete																			// STM8
#define	bUsesFlashStorage																							// STM8
#define	kFlashSectorSize							128     // 64 words (16-bits)		// STM8
#define	kMaxNumbofFlashFiles					30															// STM8
#define	kVTOCItemSize									4																// STM8
#define	kStoreRobotNameInPersistentData 1   														// STM8
#define	bStoreStartupUARTTypesInPersistentData() (1)									// STM8
#define	kSizeOfFlashMemoryPtr					2																// STM8
#define	kSizeOfRAMMemoryPtrInHW				2																// STM8

#undef	bHasEvents																										// STM8
#define	kTotalCallSubStackSize				32*kNumbOfTasks									// STM8
#define	kTotalVariablesStackSize			64*kNumbOfTasks									// STM8
#undef	kConstantPoolSize									 														// STM8 -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 						0x00006000											// STM8 -- Byte (and not word) address
#define	kStartOfBootloader						0x00007800											// STM8
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// STM8

#undef	SystemUartPortCanBeReconfigured																// STM8
#undef	hasUserSerialPorts																						// STM8
#define	getNumbOfSerialPorts()				 1															// STM8
#define	kSizeOfXmitUartBuffer 				70															// STM8
#define	kSizeOfRcvUartBuffer	 				25															// STM8

#undef	ARMCPU																												// STM8
#undef	AVRCPU																												// STM8
#define	STM8CPU																												// STM8
#undef	Spare1CPU																											// STM8
#undef	Spare2CPU																											// STM8
#undef	Spare3CPU																											// STM8
#define	useParmForCurrOpPtr																						// STM8
