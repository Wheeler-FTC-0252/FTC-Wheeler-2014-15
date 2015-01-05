////////////////////////////////////////////////////////////////////////////////////////////////////
//
//												Load Build Options for Arduino Microchip ChipKit Max
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LoadBuildOptionsClearFields.h"
#define	romtype																												// ChipkitMax
#define	ramtype																												// ChipkitMax
#define	neartype																											// ChipkitMax
#define	ramfunc																												// ChipkitMax
#define	no_init																												// ChipkitMax
//#undef inline																												// ChipkitMax

#define	bFirmwareStoresMotorType																			// ChipkitMax
#define	bFirmwareStoresMotorDriveSide																	// ChipkitMax
#define	bIncludeMotorTypeInUploadMessage() true		 										// ChipkitMax
#define	bMotorMirroring																								// ChipkitMax
#undef	bMotorsWithEncoders																						// ChipkitMax
#undef	bMotorsWithCurrentLimiting																		// ChipkitMax
#define	bSmartMotorsWithEncoders()   0																// ChipkitMax
#define	kSizeOfDefaultPidSettingsTable 6															// ChipkitMax
#define	bAssociateMotorWithEncoderSensor															// ChipkitMax
#undef	bHasEncoderTimeStamp																					// ChipkitMax
#undef	bHasEncoderVelocity																						// ChipkitMax
#define	bAssociateMotorWithIOPins 																		// ChipkitMax
#define	bIncludeMotorEncoderInUploadMessage() true		 								// ChipkitMax
#undef	bSpare199																 											// ChipkitMax
#define	bSupportsSoftwareBasedServoPWM					 											// ChipkitMax
#undef	bHasHardwareAutoDetectionMotors					 											// ChipkitMax
#undef	bHasHardwareAutoDetectionSensors					 										// ChipkitMax

#define	kNumbOfBreakpoints 6																					// ChipkitMax
#define	kSystemClockSpeed  (80000000L)																// ChipkitMax

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// ChipkitMax
#define	optionalExceptions 																						// ChipkitMax
#define	optionalBreakpoints 																					// ChipkitMax
#define	optionalDebugSupport																					// ChipkitMax
#define	hasBulkUploadlupport																					// ChipkitMax
#define	hasOptionalUploadSupport																			// ChipkitMax
#define	hasDeviceUploadSupport																				// ChipkitMax
#define	optionalTrinaryOpcodes																				// ChipkitMax
#define	bHasOpcodeStateMachine																				// ChipkitMax

#define	useFloats																											// ChipkitMax
#define	useLongs																											// ChipkitMax
#define	useStackVariables																							// ChipkitMax

#define	hasJoystickDownloadMessageOpcodes															// ChipkitMax
#undef	hasJoystickUploadMessageOpcodes																// ChipkitMax
#define	hasMemMoveSupport																							// ChipkitMax
#define	hasMemCmpSupport																							// ChipkitMax
#define	hasStringSupport																							// ChipkitMax
#define	has_sscanf_Support																						// ChipkitMax
#define	hasTranscendentalSupport																			// ChipkitMax

#define	bHasSoundSupport 0																						// ChipkitMax
#define	bHasSoundVolume 0																							// ChipkitMax
#undef	bHasPlayMusicalNotes																					// ChipkitMax
#undef	bHasSoundsInRomChip																						// ChipkitMax
#define	bHasSoundDriverOnOff 0																				// ChipkitMax
#define	bHasSoundFiles 0																							// ChipkitMax
#undef	kSoundQueueSize  																							// ChipkitMax

#undef	hasCamera																											// ChipkitMax
#undef	hasHarvardArchitecture																				// ChipkitMax
#define	kMaxTimeBetweenMessageChars 15																// ChipkitMax
#define	hasDebugStreamSupport																					// ChipkitMax
#define	kDebugStreamDefaultBufferSize 4000														// ChipkitMax
#define	kRamBaseAddr 0																								// ChipkitMax
#define	bHasDatalog																										// ChipkitMax
#define	kDatalogDefaultBufferSize 4000																// ChipkitMax
#undef	bHasDatalogSave																								// ChipkitMax
#undef	bHasMessageStatistics																					// ChipkitMax
#undef	TETRIX_CAPABLE																								// ChipkitMax

#undef	hasAlphaNumericLCDDisplayViaUART															// ChipkitMax
#undef	bHasLCDGraphicsDisplay																				// ChipkitMax
#undef	hasLCDMenuFunctions																						// ChipkitMax
#define bPixelByteContainsColumnData() true														// ChipkitMax
#define bPixelRowsLSBFirst()					 true														// ChipkitMax
#undef	hasLCDBacklight																								// ChipkitMax
#define	kScreenWidth							84																	// ChipkitMax
#define	kScreenHeight							48																	// ChipkitMax
#define	kFirstVisibleScreenRow()   0																	// ChipkitMax
#undef	hasLCDButtons																									// ChipkitMax
#undef	hasStatusLEDs																									// ChipkitMax
#undef	bHasLCDContrast																								// ChipkitMax
#undef	bHasRemoteButtons																							// ChipkitMax

#undef	bUseLookupBreakpointTableInRAM																// ChipkitMax
#undef	bHasFloatDuringInactivePWM																		// ChipkitMax
#define	nnRobotType	rbtChipKit																				// ChipkitMax
#undef	bHasServoSpecificSourceTypes																	// ChipkitMax
#undef	bHasSourceTypeSensorRawValue																	// ChipkitMax
#undef	bHasSourceTypeSensorMode																			// ChipkitMax
#define	nUploadSensorValueType sensorUploadSizeShortX									// ChipkitMax
#undef	hasWatchDogTimerFunctions																			// ChipkitMax
#define	bHasClearFlashOpcodes																					// ChipkitMax
#undef	hasSpareOption9																								// ChipkitMax

#define	kSizeOfTLargeValue         4																	// ChipkitMax

#undef	bHasReadBatteryVoltage																				// ChipkitMax
#undef	bHasStandardBatteryMonitoring																	// ChipkitMax
#undef	bHasSoftwareControlledPowerOnOff															// ChipkitMax
#undef	bHasSoftwareControlledPowerOnOffTiming												// ChipkitMax
#undef	UNUSED__23                     																// ChipkitMax
#define	bHasShiftOutOpcode																						// ChipkitMax
#define	bHasRandomFunctions																						// ChipkitMax
#define	bHasBulkClearSensorFunction																		// ChipkitMax
#define	bHasBulkClearMotorFunction																		// ChipkitMax

// Flags to control level of sensor support

#define	sensorHandlerWorkBetweenOpcodes()															// ChipkitMax
#define bSoftwareMustStartADCConversionCycle													// ChipkitMax
#define	useSimpleADCArrayLookup																				// ChipkitMax
#define	includeSonarSensorSupportTwoPins															// ChipkitMax  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// ChipkitMax  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// ChipkitMax  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// ChipkitMax  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 4																						// ChipkitMax
#define	bHasSensorBiasSettings																				// ChipkitMax
#define	bHasI2CPort																										// ChipkitMax
#define	bHasDaisyChainedI2C																						// ChipkitMax
#undef	nFirstAutoDaisyChainI2CAddress																// ChipkitMax
#define	bHasGetSensorRawADValue																				// ChipkitMax
#define	bHasFastSonarSensor																						// ChipkitMax

#define	kNumbAnalogSensors 	 16																				// ChipkitMax
#define	kNumbDigitalSensors  53																				// ChipkitMax
#define	kNumbSensorsOnI2CPorts  0																			// ChipkitMax
#define	kMaxNumbofComplicatedSensors  12															// ChipkitMax
#define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ChipkitMax

#define	bHasSystemTaskForUserProgramComplete													// ChipkitMax
#define	bHasSemaphoreSupport																					// ChipkitMax
#define	kMaxBytesPerDataBytesUpload   65															// ChipkitMax
#define	kReceivedOpcodeSize           70															// ChipkitMax
#define	bGetClearVariablesOnPgmStart()   true													// ChipkitMax
#define	bHasPropertyOpcodes																						// ChipkitMax
#undef	hasDriveTrainConfiguration																		// ChipkitMax
#undef	hasJoystickAxisConfiguration																	// ChipkitMax
#undef	hasMotorOpcodes																								// ChipkitMax
#undef	platformDriversBufferOutgoingSerialData												// ChipkitMax
#undef	platformDriversBufferIncomingSerialData												// ChipkitMax
#define	DelayTimeForStartupProgram()   0															// ChipkitMax
#undef	spareOption16																									// ChipkitMax
#undef	spareOption17																									// ChipkitMax
#undef	spareOption18																									// ChipkitMax
#undef	spareOption19																									// ChipkitMax
#undef	spareOption20																									// ChipkitMax
#undef	spareOption21																									// ChipkitMax
#undef	spareOption22																									// ChipkitMax
#undef	spareOption23																									// ChipkitMax
#undef	spareOption24																									// ChipkitMax
#define	bUserMessagesAllowed																					// ChipkitMax

#define	bHasMultRobotNetworking																				// ChipkitMax
#define	bSystemUARTSupportsZigBee																			// ChipkitMax
#undef	bHasZigBeeFeatureSpare0																				// ChipkitMax
#undef	bHasZigBeeFeatureSpare1																				// ChipkitMax
#undef	bHasZigBeeFeatureSpare2																				// ChipkitMax
#define kNumbOfZigBeeMessageBuffers		0																// ChipkitMax

#define	kNumbOfTasks									(4)															// ChipkitMax
#define	kNumbOfGlobalVariablesInBytes	(15000)													// ChipkitMax
#define	kSpareA01											(0)															// ChipkitMax
#define	kNumbOfRealMotors             (12)														// ChipkitMax
#define	kNumbOfRealServos             ((ubyte) 9)											// ChipkitMax
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// ChipkitMax
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// ChipkitMax

#undef	bSupportsInvokeBootloaderOpcode																// ChipkitMax
#define	bSupportsFlashWriteOpcodes              (1) 									// ChipkitMax
#define	bSpareFlagABC	(0)													 										// ChipkitMax
#define	bSupportsRAMWriteOpcodes																			// ChipkitMax

#define	bHasFlashFileSystem																						// ChipkitMax
#undef	bHasFlashFileSystemDelete																			// ChipkitMax
#define	bUsesFlashStorage																							// ChipkitMax
#define	kFlashSectorSize							4096														// ChipkitMax
#define	kMaxNumbofFlashFiles					64															// ChipkitMax
#define	kVTOCItemSize									4																// ChipkitMax
#define	kStoreRobotNameInPersistentData 1   														// ChipkitMax
#define	bStoreStartupUARTTypesInPersistentData() (1)									// ChipkitMax
#define	kSizeOfFlashMemoryPtr					4																// ChipkitMax
#define	kSizeOfRAMMemoryPtrInHW				4																// ChipkitMax

#undef	bHasEvents																										// ChipkitMax
#define	kTotalCallSubStackSize				32*kNumbOfTasks									// ChipkitMax
#define	kTotalVariablesStackSize			256*kNumbOfTasks								// ChipkitMax
#define	kConstantPoolSize							3200														// ChipkitMax -- Maximum size in bytes of constant pool
#define	kStartOfFileSystem 						0x9D030000											// ChipkitMax
#define	kStartOfBootloader						0x9D07F000											// ChipkitMax
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ChipkitMax

#undef	SystemUartPortCanBeReconfigured																// ChipkitMax
#undef	hasUserSerialPorts																						// ChipkitMax
#define	getNumbOfSerialPorts()			 1																// ChipkitMax
#define	kSizeOfXmitUartBuffer 			70																// ChipkitMax
#define	kSizeOfRcvUartBuffer	 			40																// ChipkitMax

#undef	ARMCPU																												// ChipkitMax
#undef	AVRCPU																												// ChipkitMax
#undef	STM8CPU																												// ChipkitMax
#define	PIC32																													// ChipkitMax
#undef	Spare1CPU																											// ChipkitMax
#undef	Spare2CPU																											// ChipkitMax
#undef	Spare3CPU																											// ChipkitMax
#define	useParmForCurrOpPtr																						// ChipkitMax

//#define	ceilf     ceil																								// ChipkitMax
//#define	floorf    floor																								// ChipkitMax