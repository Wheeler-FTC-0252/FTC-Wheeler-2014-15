////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																Load Build Options for VEX PIC
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LoadBuildOptionsVexPIC__H_
#define	LoadBuildOptionsVexPIC__H_
#include "LoadBuildOptionsClearFields.h"
#define	romtype rom //far																							// VEX_PIC
#define	ramtype  ram																									// VEX_PIC
#define	neartype near																									// VEX_PIC
#define	ramfunc																												// VEX_PIC
#define	no_init																												// VEX_PIC
//#undef inline																												// VEX_PIC

#undef	bFirmwareStoresMotorType																			// VEX_PIC
#define	bFirmwareStoresMotorDriveSide																	// VEX_PIC
#define	 bIncludeMotorTypeInUploadMessage() false		 									// VEX_PIC
#define	bMotorMirroring																								// VEX_PIC
#undef	bMotorsWithEncoders																						// VEX_PIC
#undef	bMotorsWithCurrentLimiting																		// VEX_PIC
#define	bSmartMotorsWithEncoders()   0																// VEX_PIC
#define	kSizeOfDefaultPidSettingsTable 0															// VEX_PIC
#undef	bAssociateMotorWithEncoderSensor															// VEX_PIC
#undef	bHasEncoderTimeStamp																					// VEX_PIC
#undef	bHasEncoderVelocity																						// VEX_PIC
#undef	bAssociateMotorWithIOPins 																		// VEX_PIC
#define	 bIncludeMotorEncoderInUploadMessage() false		 							// VEX_PIC
#undef	 bSupportsSoftwareBasedMotorPWM						 										// VEX_PIC
#undef	 bSupportsSoftwareBasedServoPWM						 										// VEX_PIC
#undef	bHasHardwareAutoDetectionMotors					 											// VEX_PIC
#undef	bHasHardwareAutoDetectionSensors					 										// VEX_PIC

#define	kNumbOfBreakpoints 6																					// VEX_PIC
#undef	kSystemClockSpeed																							// VEX_PIC

// Conditional Compile Flags that have significant impact on features and size of firmware file

#define	hasSupportForMessagingWithRobotcIDE														// VEX_PIC
#define	optionalExceptions 																						// VEX_PIC
#define	optionalBreakpoints 																					// VEX_PIC
#define	optionalDebugSupport																					// VEX_PIC
#define	hasBulkUploadlupport																					// VEX_PIC
#define	hasOptionalUploadSupport																			// VEX_PIC
#define	hasDeviceUploadSupport																				// VEX_PIC
#undef	optionalTrinaryOpcodes 																				// VEX_PIC
#undef	bHasOpcodeStateMachine 																				// VEX_PIC

#undef	useFloats																											// VEX_PIC
#undef	useLongs																											// VEX_PIC
#undef	useStackVariables																							// VEX_PIC

#undef	hasJoystickDownloadMessageOpcodes															// VEX_PIC
#undef	hasJoystickUploadMessageOpcodes																// VEX_PIC
#undef	hasMemMoveSupport																							// VEX_PIC
#undef	hasMemCmpSupport																							// VEX_PIC
#undef	hasStringSupport																							// VEX_PIC
#undef	has_sscanf_Support																						// VEX_PIC
#undef	hasTranscendentalSupport																			// VEX_PIC

#define	bHasSoundSupport 0																						// VEX_PIC
#define	bHasSoundVolume 0																							// VEX_PIC
#undef	bHasPlayMusicalNotes																					// VEX_PIC
#undef	bHasSoundsInRomChip																						// VEX_PIC
#define	bHasSoundDriverOnOff 0																				// VEX_PIC
#define	bHasSoundFiles 0																							// VEX_PIC
#define	kSoundQueueSize 5																							// VEX_PIC

#undef	hasCamera																											// VEX_PIC
#define	hasHarvardArchitecture																				// VEX_PIC
#define	kMaxTimeBetweenMessageChars 75 // 45													// VEX_PIC
#undef	hasDebugStreamSupport																					// VEX_PIC
#define	kDebugStreamDefaultBufferSize	0																// VEX_PIC
#define	kRamBaseAddr 0																								// VEX_PIC
#undef	bHasDatalog																										// VEX_PIC
#define	kDatalogDefaultBufferSize 0																		// VEX_PIC
#undef	bHasDatalogSave																								// VEX_PIC
#undef	bHasMessageStatistics																					// VEX_PIC
#undef	TETRIX_CAPABLE																								// VEX_PIC

#define	hasAlphaNumericLCDDisplayViaUART															// VEX_PIC
#undef	bHasLCDGraphicsDisplay																				// VEX_PIC
#undef	hasLCDMenuFunctions																						// VEX_PIC
#define bPixelByteContainsColumnData() true														// VEX_PIC
#define bPixelRowsLSBFirst()					 true														// VEX_PIC
#define	hasLCDBacklight																								// VEX_PIC
#undef	kScreenWidth																									// VEX_PIC
#undef	kScreenHeight																									// VEX_PIC
#undef	kFirstVisibleScreenRow																				// VEX_PIC
#define	hasLCDButtons																									// VEX_PIC
#undef	hasStatusLEDs																									// VEX_PIC
#undef	bHasLCDContrast																								// VEX_PIC
#define	bHasRemoteButtons																							// VEX_PIC

#undef	bUseLookupBreakpointTableInRAM																// VEX_PIC
#undef	bHasFloatDuringInactivePWM																		// VEX_PIC
#define	nnRobotType	rbtTypeVEX0_5																			// VEX_PIC
#undef	bHasServoSpecificSourceTypes																	// VEX_PIC
#undef	bHasSourceTypeSensorRawValue																	// VEX_PIC
#undef	bHasSourceTypeSensorMode																			// VEX_PIC
#define	nUploadSensorValueType sensorUploadSizeShortX									// VEX_PIC
#undef	hasWatchDogTimerFunctions																			// VEX_PIC
#undef	bHasClearFlashOpcodes																					// VEX_PIC
#undef	hasSpareOption9																								// VEX_PIC

#define	kSizeOfTLargeValue				 2																	// VEX_PIC

#undef	bHasReadBatteryVoltage																				// VEX_PIC
#undef	bHasStandardBatteryMonitoring																	// VEX_PIC
#undef	bHasSoftwareControlledPowerOnOff															// VEX_PIC
#undef	bHasSoftwareControlledPowerOnOffTiming												// VEX_PIC
#undef	UNUSED__23                     																// VEX_PIC
#undef	bHasShiftOutOpcode																						// VEX_PIC
#undef	bHasRandomFunctions																						// VEX_PIC
#undef	bHasBulkClearSensorFunction																		// VEX_PIC
#undef	bHasBulkClearMotorFunction																		// VEX_PIC

// Flags to control level of sensor support

extern void sensorHandlerWorkBetweenOpcodes(void);										// VEX_PIC
#define bSoftwareMustStartADCConversionCycle													// VEX_PIC
#undef	useSimpleADCArrayLookup																				// VEX_PIC
#define	includeSonarSensorSupportTwoPins															// VEX_PIC  -- For MaxBotic SRP-04 ultrasonic and similar
#define	includeSonarSensorSupportOnePin																// VEX_PIC  -- For Parallax Ping ultrasonic and similar
#define	includeEncoderSensorSupport																		// VEX_PIC  -- For minimal f/w size, this can be discarded
#define	includeGyroAndAccelSupport																		// VEX_PIC  -- For minimal f/w size, this can be discarded
#define	nGyroJitterRange 1																						// VEX_PIC  -- For minimal f/w size, this can be discarded
#define	bHasSensorBiasSettings																				// VEX_PIC
#undef	bHasI2CPort																										// VEX_PIC
#undef	bHasDaisyChainedI2C																						// VEX_PIC
#undef	nFirstAutoDaisyChainI2CAddress																// VEX_PIC
#undef	bHasGetSensorRawADValue																				// VEX_PIC
#undef	bHasFastSonarSensor																						// VEX_PIC

#define	kNumbAnalogSensors 	 8																				// VEX_PIC
#define	kNumbDigitalSensors  8																				// VEX_PIC
#define	kNumbSensorsOnI2CPorts  0																			// VEX_PIC
#define	kMaxNumbofComplicatedSensors  8																// VEX_PIC
#define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts) // VEX_PIC

#define	bHasSystemTaskForUserProgramComplete													// VEX_PIC
#undef	bHasSemaphoreSupport																					// VEX_PIC
#define	kMaxBytesPerDataBytesUpload   59															// VEX_PIC
#define	kReceivedOpcodeSize           70															// VEX_PIC
#define	bGetClearVariablesOnPgmStart()   false												// VEX_PIC
#define	bHasPropertyOpcodes																						// VEX_PIC
#undef	hasDriveTrainConfiguration																		// VEX_PIC
#undef	hasJoystickAxisConfiguration																	// VEX_PIC
#undef	hasMotorOpcodes																								// VEX_PIC
#undef	platformDriversBufferOutgoingSerialData												// VEX_PIC
#undef	platformDriversBufferIncomingSerialData												// VEX_PIC
#define	DelayTimeForStartupProgram()   0															// VEX_PIC
#undef	spareOption16																									// VEX_PIC
#undef	spareOption17																									// VEX_PIC
#undef	spareOption18																									// VEX_PIC
#undef	spareOption19																									// VEX_PIC
#undef	spareOption20																									// VEX_PIC
#undef	spareOption21																									// VEX_PIC
#undef	spareOption22																									// VEX_PIC
#undef	spareOption23																									// VEX_PIC
#undef	spareOption24																									// VEX_PIC
#undef	bUserMessagesAllowed																					// VEX_PIC
#undef	bHasMultRobotNetworking																				// VEX_PIC
#undef	bSystemUARTSupportsZigBee																			// VEX_PIC
#undef	bHasZigBeeFeatureSpare0																				// VEX_PIC
#undef	bHasZigBeeFeatureSpare1																				// VEX_PIC
#undef	bHasZigBeeFeatureSpare2																				// VEX_PIC
#define kNumbOfZigBeeMessageBuffers		0																// VEX_PIC

#define	kNumbOfTasks									(5)															// VEX_PIC
#define	kNumbOfGlobalVariablesInBytes	(256)														// VEX_PIC
#define	kNumbOfPrograms								(16)														// VEX_PIC
#define	kSpareA01											(0)															// VEX_PIC
#define	kNumbOfRealMotors             (8)															// VEX_PIC
#define	kNumbOfRealServos             ((ubyte) 8)											// VEX_PIC
#define	kNumbOfVirtualSensors         ((ubyte) 0)											// VEX_PIC
#define	kNumbOfVirtualMotors          ((ubyte) 0)											// VEX_PIC

#undef	bSupportsInvokeBootloaderOpcode																// VEX_PIC
#define	bSupportsFlashWriteOpcodes              (1) 									// VEX_PIC
#define	bSpareFlagABC	(0)													 										// VEX_PIC
#define	bSupportsRAMWriteOpcodes																			// VEX_PIC

#define	bHasFlashFileSystem																						// VEX_PIC
#undef	bHasFlashFileSystemDelete																			// VEX_PIC
#define	bUsesFlashStorage																							// VEX_PIC
#define	kFlashSectorSize							64															// VEX_PIC
#define	kMaxNumbofFlashFiles					12															// VEX_PIC
#define	kVTOCItemSize									2																// VEX_PIC
#define	kStoreRobotNameInPersistentData 0    													// VEX_PIC
#define	bStoreStartupUARTTypesInPersistentData() (0)									// VEX_PIC
#define	kSizeOfFlashMemoryPtr					2																// VEX_PIC
#define	kSizeOfRAMMemoryPtrInHW				2																// VEX_PIC

#undef	bHasEvents																										// VEX_PIC
#define	kTotalCallSubStackSize				15*kNumbOfTasks									// VEX_PIC
#define	kTotalVariablesStackSize			64*kNumbOfTasks									// VEX_PIC
#define	kConstantPoolSize							-1															// VEX_PIC -- Maximum size in bytes of constant pool. None if "#undef".
#define	kStartOfFileSystem 						0x00007000											// VEX_PIC -- Byte (and not word) address
#undef	kStartOfBootloader																						// VEX_PIC
#define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// VEX_PIC

#undef	SystemUartPortCanBeReconfigured																// VEX_PIC
#define	hasUserSerialPorts																						// VEX_PIC
#define	getNumbOfSerialPorts()			 2																// VEX_PIC
//#define	kSizeOfXmitUartBuffer 		10																// VEX_PIC
#define	kSizeOfXmitUartBuffer 			70																// VEX_PIC
#define	kSizeOfRcvUartBuffer	 			20																// VEX_PIC

#undef	ARMCPU																												// VEX_PIC
#undef	AVRCPU																												// VEX_PIC
#undef	STM8CPU																												// VEX_PIC
#undef	Spare1CPU																											// VEX_PIC
#undef	Spare2CPU																											// VEX_PIC
#undef	Spare3CPU																											// VEX_PIC
#undef	useParmForCurrOpPtr																						// VEX_PIC

#endif