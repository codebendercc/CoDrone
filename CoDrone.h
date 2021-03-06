/*
	CoDrone.h - CoDrone library
	Copyright (C) 2014 RoboLink.  All rights reserved.
	LastUpdate : 2018-04-27
*/

#ifndef CoDrone_h
#define CoDrone_h
#include "Arduino.h"
#include <avr/interrupt.h>

/***********************************************************************/
/*
# define JOY_UP_LIMIT						1023 - 100
# define JOY_UP_RETURN_LIMIT		512 + 100
# define JOY_DOWN_LIMIT					0 + 100
# define JOY_DOWN_RETURN_LIMIT	512 - 100
*/
/***********************************************************************/

//////////////////////////typedef///////////////////////////////////////


typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
typedef uint32_t u32;
typedef uint8_t u8;

////////////////////////Serial Select////////////////////////////////////

#if defined(UBRRH) || defined(UBRR0H)
#define FIND_HWSERIAL0
#endif

#if defined(__AVR_ATmega128__)
#define DEBUG_MODE_ENABLE
#endif

#if defined(UBRR1H)
#define FIND_HWSERIAL1
#endif

#if defined (FIND_HWSERIAL1)		//Serial Other Setting	- two serial
#define DRONE_SERIAL	Serial1		//drone serial
#define DEBUG_SERIAL	Serial		//debug serial1

#else								//Serial Smart Setting	- one serial
#define DRONE_SERIAL		Serial	//drone serial
#define DEBUG_SERIAL		Serial1	//debug serial1

#endif

////////////////////////////HEADER///////////////////////////////////////

//START CODE
#define START1			0x0A
#define START2			0x55

//serial buffer
#if defined (FIND_HWSERIAL1)	// Atmega128
#define MAX_PACKET_LENGTH	200

#else							// Smart Setting
#define MAX_PACKET_LENGTH	40
#endif

//#define SEND_CHECK_TIME	3
#define	SEND_CHECK_TIME		50

//buzz
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
/***********************************************************************/

#define ROLL					CoDrone.roll
#define PITCH					CoDrone.pitch
#define YAW						CoDrone.yaw
#define THROTTLE				CoDrone.throttle

#define STATE					CoDrone.state
#define SEND_INTERVAL			CoDrone.SendInterval
#define ANALOG_OFFSET			CoDrone.analogOffset
#define BATTERY					CoDrone.battery
#define RSSI					CoDrone.rssi

#define AttitudeROLL			CoDrone.attitudeRoll
#define AttitudePITCH			CoDrone.attitudePitch
#define AttitudeYAW				CoDrone.attitudeYaw

/***********************************************************************/

#define DiscoverStop			cType_LinkDiscoverStop
#define DiscoverStart			cType_LinkDiscoverStart

//#define PollingStop			cType_LinkRssiPollingStop
//#define PollingStart			cType_LinkRssiPollingStart

#define	PAIRING					CoDrone.pairing

#define LinkModeMute 			LinkBroadcast_Mute
#define LinkModeActive			LinkBroadcast_Active
#define LinkModePassive 		LinkBroadcast_Passive

#define	NearbyDrone				1
#define	ConnectedDrone			2
#define AddressInputDrone		3
#define	Nearest					1

//eeprom address
#define	EEP_AddressCheck		10
#define	EEP_AddressFirst		11
#define	EEP_AddressEnd			15

/***********************************************************************/
//Team setting
#define FREE_PLAY				0
#define TEAM_RED				1
#define TEAM_BLUE				2
#define TEAM_GREEN				3
#define TEAM_YELLOW				4
#define MAX_ENERGY				8

/**********************	IR DATA ****************************************/

#define FREE_MISSILE			0xaa01
#define RED_MISSILE				0xbb01
#define BLUE_MISSILE			0xcc01
#define GREEN_MISSILE			0xdd01
#define YELLOW_MISSILE			0xee01

/***********************************************************************/

#define Flight 					dMode_Flight
#define FlightNoGuard			dMode_FlightNoGuard
#define FlightFPV				dMode_FlightFPV
#define Drive 					dMode_Drive
#define DriveFPV				dMode_DriveFPV

#define Absolute 				cSet_Absolute
#define Relative				cSet_Relative

#define TakeOff 				fEvent_TakeOff
#define FlipFront				fEvent_FlipFront
#define FlipRear				fEvent_FlipRear
#define FlipLeft				fEvent_flipLeft
#define FlipRight				fEvent_FlipRight
#define Stop					fEvent_Stop
#define Landing					fEvent_Landing
#define TurnOver				fEvent_TurnOver
#define Shot					fEvent_Shot
#define UnderAttack				fEvent_UnderAttack
#define Square					fEvent_Square
#define CircleLeft				fEvent_CircleLeft
#define CircleRight				fEvent_CircleRight
#define Rotate180				fEvent_Rotate180

#define RollIncrease			trim_RollIncrease
#define RollDecrease			trim_RollDecrease
#define PitchIncrease			trim_PitchIncrease
#define PitchDecrease			trim_PitchDecrease
#define YawIncrease				trim_YawIncrease
#define YawDecrease				trim_YawDecrease
#define ThrottleIncrease		trim_ThrottleIncrease
#define ThrottleDecrease		trim_ThrottleDecrease

//-------------------------------------------------------------------------------------//

#define	Address					Req_Address					///< IEEE address
#define	Attitude				Req_Attitude

// 2018, 1, 22 added
#define LEFT 					direction_left
#define FORWARD 				direction_forward
#define RIGHT 					direction_right
#define BACKWARD				direction_backward
#define UP  					direction_up
#define DOWN 					direction_down

// 2018, 3, 12 added
#define ZIGZAG 					Seq_zigzag
#define SWAY 					Seq_sway
#define SQUARE 					Seq_square
#define CIRCLE 					Seq_circle
#define SPIRAL 					Seq_spiral
#define TRIANGLE 				Seq_triangle
#define HOP 					Seq_hop

#define OFF 					LED_NONE
#define SOLID  					LED_SOLID
#define STROBE  				LED_STROBE 
#define BLINK 					LED_BLINK
#define DOUBLE_BLINK 			LED_DOUBLE_BLINK
#define DIMMING 		  		LED_DIMMING
#define PULSE  					LED_PULSE
#define REVERSE_PULSE 			LED_REVERSE_PULSE

typedef struct gyrodata
{
	int roll;
	int pitch;
	int yaw;
}gyrodata;

typedef struct acceldata
{
	int x;
	int y;
	int z;
}acceldata;

typedef struct angledata
{
	int roll;
	int pitch;
	int yaw;
}angledata;

typedef struct optdata
{
	int x;
	int y;
}optdata;


typedef struct trimdata
{
	int roll;
	int pitch;
	int yaw;
	int throttle;
}trimdata;



/***********************************************************************/

#define LED_DISPLAY_START			0
#define LED_DISPLAY_PORTC			1
#define LED_DISPLAY_DDRC			2
#define LED_DISPLAY_STANDARD		3
#define LED_DISPLAY_MOVE_SLIDE		4
#define LED_DISPLAY_CONNECT			5
#define LED_DISPLAY_BLINK			6
#define LED_DISPLAY_MOVE_RADER		7

/***********************************************************************/
/////////////////////////LINK MODULE/////////////////////////////////////
/***********************************************************************/
enum ModeLink
{
	linkMode_None = 0,				
	linkMode_Boot,					
	linkMode_Ready,					
	linkMode_Connecting,			
	linkMode_Connected,				
	linkMode_Disconnecting,			
	linkMode_ReadyToReset,			
	linkMode_EndOfType
};

enum ModeLinkBroadcast
{
	LinkBroadcast_None = 0,			
	LinkBroadcast_Mute,				
	LinkBroadcast_Active,			
	LinkBroadcast_Passive,			
	LinkBroadcast_EndOfType
};

enum EventLink
{
	linkEvent_None = 0,				
	linkEvent_SystemReset,			
	linkEvent_Initialized,			
	linkEvent_Scanning,				
	linkEvent_ScanStop,				
	linkEvent_FoundDroneService,	
	linkEvent_Connecting,			
	linkEvent_Connected,					
	linkEvent_ConnectionFaild,		
	linkEvent_ConnectionFaildNoDevices,		
	linkEvent_ConnectionFaildNotReady,		
	linkEvent_PairingStart,					
	linkEvent_PairingSuccess,				
	linkEvent_PairingFaild,					
	linkEvent_BondingSuccess,				
	linkEvent_LookupAttribute,				
	linkEvent_RssiPollingStart,				
	linkEvent_RssiPollingStop,				
	linkEvent_DiscoverService,				
	linkEvent_DiscoverCharacteristic,		
	linkEvent_DiscoverCharacteristicDroneData,		
	linkEvent_DiscoverCharacteristicDroneConfig,	
	linkEvent_DiscoverCharacteristicUnknown,		
	linkEvent_DiscoverCCCD,							
	linkEvent_ReadyToControl,						
	linkEvent_Disconnecting,						
	linkEvent_Disconnected,							
	linkEvent_GapLinkParamUpdate,					
	linkEvent_RspReadError,							
	linkEvent_RspReadSuccess,						
	linkEvent_RspWriteError,						
	linkEvent_RspWriteSuccess,						
	linkEvent_SetNotify,							
	linkEvent_Write,								
	EndOfType
};


/***********************************************************************/
//////////////////////////////DRONE/////////////////////////////////////
/***********************************************************************/
enum DataType
{
	dType_None = 0,									
	// ???????????? ????????
	dType_Ping,										
	dType_Ack,										
	dType_Error,							
	dType_Request,							
	dType_DeviceName,						
	// ????????, ????????
	dType_Control = 0x10,					
	dType_Command,							
	dType_Command2,							
	DType_Command3,							
	// LED
	dType_LedMode = 0x20,					
	dType_LedMode2,							
	dType_LedModeCommand,					
	dType_LedModeCommandIr,					
	dType_LedModeColor,						
	dType_LedModeColor2,					
	dType_LedEvent,							
	dType_LedEvent2,						
	dType_LedEventCommand,					
	dType_LedEventCommandIr,				
	dType_LedEventColor,					
	dType_LedEventColor2,					
	dType_LedDefaultColor,					
	dType_LedDefaultColor2,					
	// ????????
	dType_Address = 0x30,						///< IEEE address
	dType_State,										///< ???????????? ????????(???????? ????????, ????????????????, ????????????????)
	dType_Attitude,									///< ???????????? ????????(Vector)
	dType_GyroBias,									///< ???????????? ???????????????? ????(Vector)
	dType_TrimAll,									///< ???????? ???????? (????????+????????)??
	dType_TrimFlight,								///< ???????? ????????
	dType_TrimDrive,								///< ???????? ????????
	dType_CountFlight,							///< ???????? ???????? ????????????
	dType_CountDrive,								///< ???????? ???????? ????????????
	// ???????????? ????????????
	dType_IrMessage = 0x40,					///< IR ???????????? ????????????
	// ????????
	dType_ImuRawAndAngle = 0x50,		///< IMU Raw + Angle
	dType_Pressure,									///< ???????? ???????? ????????????
	dType_ImageFlow,								///< ImageFlow
	dType_Button,										///< ???????? ????????
	dType_Battery,									///< ????????????
	dType_Motor,										///< ???????? ???????? ???? ???????? ???????? ???? ????????
	dType_Temperature,							///< ????????
	dType_Range,										///< ???????? ????????
	// ???????? ????????
	dType_LinkState = 0xE0,					///< ???????? ???????????? ????????
	dType_LinkEvent,								///< ???????? ???????????? ????????????
	dType_LinkEventAddress,					///< ???????? ???????????? ???????????? + ????????
	dType_LinkRssi,									///< ???????????? ???????????? ???????????? RSSI????
	dType_LinkDiscoveredDevice,			///< ???????????? ????????
	dType_LinkPasscode,							///< ???????????? ???????? ???????????? ???????? ????????
	dType_StringMessage = 0xD0,			///< ???????????? ????????????
	dType_EndOfType
};

/***********************************************************************/
enum CommandType
{
	cType_None = 0,									///< ???????????? ????????
	// ????????
	cType_ModeDrone = 0x10,					///< ???????? ???????? ???????? ????????
	// ????????
	cType_Coordinate = 0x20,				///< ???????? ???????? ????????
	cType_Trim,											///< ???????? ????????
	cType_FlightEvent,							///< ???????? ???????????? ????????
	cType_DriveEvent,								///< ???????? ???????????? ????????
	cType_Stop,											///< ????????
	cType_ResetHeading = 0x50,			///< ???????????? ????????(???????????????? ???????? ???? ???? ???????? heading???? 0???????? ????????)
	cType_ClearGyroBiasAndTrim,			///< ???????????? ???????????????????? ???????? ???????? ????????????
	cType_ClearTrim,								///< ???????? ????????????
	// ????????
	cType_PairingActivate = 0x80,		///< ???????????? ????????????
	cType_PairingDeactivate,				///< ???????????? ????????????????
	cType_TerminateConnection,			///< ???????? ????????
	// ????????
	cType_Request = 0x90,						///< ???????????? ???????????? ???????????? ????????
	// ???????? ????????
	cType_LinkModeBroadcast = 0xE0,	///< LINK ???????????? ???????? ????????
	cType_LinkSystemReset,					///< ???????????? ????????????
	cType_LinkDiscoverStart,				///< ???????? ???????? ????????
	cType_LinkDiscoverStop,					///< ???????? ???????? ????????
	cType_LinkConnect,							///< ????????
	cType_LinkDisconnect,						///< ???????? ????????
	cType_LinkRssiPollingStart,			///< RSSI ???????? ????????
	cType_LinkRssiPollingStop,			///< RSSI ???????? ????????

	cType_EndOfType
};

/***********************************************************************/
enum ModeDrone
{
	dMode_None = 0,					///< ????????
	dMode_Flight = 0x10,		///< ???????? ????????(???????? ????????)
	dMode_FlightNoGuard,		///< ???????? ????????(???????? ????????)
	dMode_FlightFPV,				///< ???????? ????????(FPV)
	dMode_Drive = 0x20,			///< ???????? ????????
	dMode_DriveFPV,					///< ???????? ????????(FPV)
	dMode_Test = 0x30,			///< ???????????? ????????
	dMode_EndOfType
};

/***********************************************************************/
enum ModeVehicle
{
	vMode_None = 0,
	vMode_Boot,							///< ????????
	vMode_Wait,							///< ???????? ???????? ????????
	vMode_Ready,						///< ???????? ????????
	vMode_Running,					///< ???????? ???????? ????????
	vMode_Update,						///< ???????????? ????????????????
	vMode_UpdateComplete,		///< ???????????? ???????????????? ????????
	vMode_Error,						///< ????????
	vMode_EndOfType
};

/***********************************************************************/
enum ModeFlight
{
	fMode_None = 0,
	fMode_Ready,						///< ???????? ????????
	fMode_TakeOff,					///< ???????? (Flight???? ????????????????)
	fMode_Flight,						///< ????????
	fMode_Flip,							///< ????????
	fMode_Stop,							///< ???????? ????????
	fMode_Landing,					///< ????????
	fMode_Reverse,					///< ????????????
	fMode_Accident,					///< ???????? (Ready???? ????????????????)
	fMode_Error,						///< ????????
	fMode_EndOfType
};

/***********************************************************************/
enum ModeDrive
{
	dvMode_None = 0,
	dvMode_Ready,						///< ????????
	dvMode_Start,						///< ????????
	dvMode_Drive,						///< ????????
	dvMode_Stop,						///< ???????? ????????
	dvMode_Accident,				///< ???????? (Ready???? ????????????????)
	dvMode_Error,						///< ????????
	dvMode_EndOfType
};

/***********************************************************************/
enum SensorOrientation
{
	senOri_None = 0,
	senOri_Normal,					///< ????????
	senOri_ReverseStart,		///< ???????????????? ????????
	senOri_Reverse,					///< ????????????
	senOri_EndOfType
};

/***********************************************************************/
enum Coordinate
{
	cSet_None = 0,					///< ????????
	cSet_Absolute,					///< ???????? ????????????
	cSet_Relative,					///< ???????? ????????????
	cSet_EndOfType
};

/***********************************************************************/

enum Trim
{
	trim_None = 0,					///< ????????
	trim_RollIncrease,			///< Roll ????????
	trim_RollDecrease,			///< Roll ????????
	trim_PitchIncrease,			///< Pitch ????????
	trim_PitchDecrease,			///< Pitch ????????
	trim_YawIncrease,				///< Yaw ????????
	trim_YawDecrease,				///< Yaw ????????
	trim_ThrottleIncrease,	///< Throttle ????????
	trim_ThrottleDecrease,	///< Throttle ????????
	trim_EndOfType
};

/***********************************************************************/

enum FlightEvent
{
	fEvent_None = 0,				///< ????????
	fEvent_TakeOff,					///< ????????
	fEvent_FlipFront,				///< ????????
	fEvent_FlipRear,				///< ????????
	fEvent_flipLeft,				///< ????????
	fEvent_FlipRight,				///< ????????
	fEvent_Stop,						///< ????????
	fEvent_Landing,					///< ????????
	fEvent_TurnOver,				///< ????????????
	fEvent_Shot,						///< ???????????????? ???? ???? ????????????
	fEvent_UnderAttack,			///< ???????????????? ???????? ???? ????????????
	fEvent_Square,					///< ???????????? ????????
	fEvent_CircleLeft,			///< ???????????????? ????????
	fEvent_CircleRight,			///< ???????????????????? ????????
	fEvent_Rotate180,				///< 180???? ????????
	fEvent_EndOfType
};

enum DriveEvent
{
	dEvent_None = 0,
	dEvent_Ready,						///< ????????
	dEvent_Start,						///< ????????
	dEvent_Drive,						///< ????????
	dEvent_Stop,						///< ???????? ????????
	dEvent_Accident,				///< ???????? (Ready???? ????????????????)
	dEvent_Error,						///< ????????
	dEvent_EndOfType
};

/***********************************************************************/
enum Request
{
	// ????????
	Req_Address = 0x30,					///< IEEE address
	Req_State,									///< ???????????? ????????(???????? ????????, ????????????????, ????????????????)
	Req_Attitude,								///< ???????????? ????????(Vector)
	Req_GyroBias,								///< ???????????? ???????????????? ????(Vector)
	Req_TrimAll,								///< ???????? ????????
	Req_TrimFlight,							///< ???????? ????????
	Req_TrimDrive,							///< ???????? ????????
	Req_CountFlight,						///< ???????? ???????? ????????????
	Req_CountDrive,							///< ???????? ???????? ????????????
	// ????????
	Req_ImuRawAndAngle = 0x50,	///< IMU Raw + Angle
	Req_Pressure,								///< ???????? ???????? ????????????
	Req_ImageFlow,							///< ImageFlow
	Req_Button,									///< ???????? ????????
	Req_Battery,								///< ????????????
	Req_Motor,									///< ???????? ???????? ???? ???????? ???????? ???? ????????
	Req_Temperature,						///< ????????
	Req_Range,									///< ???????? ????????
	Req_EndOfType
};

/***********************************************************************/
enum ModeLight
{
	Light_None,
	WaitingForConnect, 		///< ???????? ???????? ????????
	Connected,
	EyeNone = 0x10,
	EyeHold,							///< ???????????? ???????????? ???????? ????
	EyeMix,								///< ???????????????????? LED ???? ????????
	EyeFlicker,						///< ????????????
	EyeFlickerDouble,			///< ????????????(???? ???? ???????????????? ???????????? ???????????????? ????????)
	EyeDimming,						///< ???????? ???????????????? ???????????? ????????????
	ArmNone = 0x40,
	ArmHold,							///< ???????????? ???????????? ???????? ????
	ArmMix,								///< ???????????????????? LED ???? ????????
	ArmFlicker,						///< ????????????
	ArmFlickerDouble,			///< ????????????(???? ???? ???????????????? ???????????? ???????????????? ????????)
	ArmDimming,						///< ???????? ???????????????? ???????????? ????????????
	ArmFlow,							///< ???????????? ???????? ????????
	ArmFlowReverse,				///< ???????????? ???????????? ????????
	EndOfLedMode
};
enum LED
{
  LED_NONE = 0x10,
  LED_SOLID,
  LED_STROBE, 
  LED_BLINK,
  LED_DOUBLE_BLINK,
  LED_DIMMING,
  LED_PULSE, 
  LED_REVERSE_PULSE, 	
  LED_EndOfType
};
/***********************************************************************/
enum Colors
{
	AliceBlue, AntiqueWhite, Aqua,
	Aquamarine, Azure, Beige,
	Bisque, Black, BlanchedAlmond,
	Blue, BlueViolet, Brown,
	BurlyWood, CadetBlue, Chartreuse,
	Chocolate, Coral, CornflowerBlue,
	Cornsilk, Crimson, Cyan,
	DarkBlue, DarkCyan, DarkGoldenRod,
	DarkGray, DarkGreen, DarkKhaki,
	DarkMagenta, DarkOliveGreen, DarkOrange,
	DarkOrchid, DarkRed, DarkSalmon,
	DarkSeaGreen, DarkSlateBlue, DarkSlateGray,
	DarkTurquoise, DarkViolet, DeepPink,
	DeepSkyBlue, DimGray, DodgerBlue,
	FireBrick, FloralWhite, ForestGreen,
	Fuchsia, Gainsboro, GhostWhite,
	Gold, GoldenRod, Gray,
	Green, GreenYellow, HoneyDew,
	HotPink, IndianRed, Indigo,
	Ivory, Khaki, Lavender,
	LavenderBlush, LawnGreen, LemonChiffon,
	LightBlue, LightCoral, LightCyan,
	LightGoldenRodYellow, LightGray, LightGreen,
	LightPink, LightSalmon, LightSeaGreen,
	LightSkyBlue, LightSlateGray, LightSteelBlue,
	LightYellow, Lime, LimeGreen,
	Linen, Magenta, Maroon,
	MediumAquaMarine, MediumBlue, MediumOrchid,
	MediumPurple, MediumSeaGreen, MediumSlateBlue,
	MediumSpringGreen, MediumTurquoise, MediumVioletRed,
	MidnightBlue, MintCream, MistyRose,
	Moccasin, NavajoWhite, Navy,
	OldLace, Olive, OliveDrab,
	Orange, OrangeRed, Orchid,
	PaleGoldenRod, PaleGreen, PaleTurquoise,
	PaleVioletRed, PapayaWhip, PeachPuff,
	Peru, Pink, Plum,
	PowderBlue, Purple, RebeccaPurple,
	Red, RosyBrown, RoyalBlue,
	SaddleBrown, Salmon, SandyBrown,
	SeaGreen, SeaShell, Sienna,
	Silver, SkyBlue, SlateBlue,
	SlateGray, Snow, SpringGreen,
	SteelBlue, Tan, Teal,
	Thistle, Tomato, Turquoise,
	Violet, Wheat, White,
	WhiteSmoke, Yellow, YellowGreen,
	EndOfColor
};

enum Direction
{
	direction_none = 0,
	direction_left,
	direction_forward,
	direction_right,
	direction_backward,
	direction_up,
	direction_down,
	direction_EndOfType
};

enum Sequence
{
	Seq_none = 0,
	Seq_zigzag,
	Seq_sway,
	Seq_square,
	Seq_circle,
	Seq_spiral,
	Seq_triangle,
	Seq_hop,
	Seq_EndOfType,
};
enum Angle
{
	ANGLE_30 = 30,
	ANGLE_45 = 45,
	ANGLE_60 = 60,
	ANGLE_90 = 90,
	ANGLE_120 = 120,
	ANGLE_135 = 135,
	ANGLE_150 = 150,
	ANGLE_180 = 180,
	ANGLE_210 = 210,
	ANGLE_225 = 225,
	ANGLE_240 = 240,
	ANGLE_270 = 270,
	ANGLE_300 = 300,
	ANGLE_315 = 315, 
	ANGLE_330 = 330
};



/***********************************************************************/

class CoDroneClass
{
public:
	
	//------------------------------------------------------------------------------------//
	void begin(long baud);

	void Receive(void);

	void Control();
	void Control(int interval);

	void Send_Command(int sendCommand, int sendOption);
	void Send_Processing(byte _data[], byte _length, byte _crc[]);

	//------------------------------------------------------------------------------------//

	void LinkReset();
	void Send_LinkModeBroadcast(byte mode);
	void Send_LinkState();

	//------------------------------------------------------------------------------------//

	void AutoConnect();
	void AutoConnect(byte mode);
	void AutoConnect(byte mode, byte address[]);	
	void ConnectionProcess(byte	mode,	byte address[]);
	void Send_ConnectDrone(byte mode, byte address[]);
	void disconnect();
	void Send_Discover(byte action);
	void Send_Check(byte _data[], byte _length, byte _crc[]);

//------------------------------------------------------------------------------------//

	void Send_ResetHeading();
	void Send_Coordinate(byte mode);
	void Send_ClearGyroBiasAndTrim();	
	void DroneModeChange(byte event);
	void FlightEvent(byte event);
	void DriveEvent(byte event);

//------------------------------------------------------------------------------------//

	void BattleShooting();
	void BattleReceive();
	void BattleBegin(byte teamSelect);
	void BattleDamageProcess();

//------------------------------------------------------------------------------------//

	void Set_Trim(byte event);
	void Set_TrimReset();
	void Set_TrimFlight(int _roll, int _pitch, int _yaw, int _throttle);

//------------------------------------------------------------------------------------//

	void LedColorProcess(byte _dType, byte sendMode, byte r, byte g, byte b, byte sendInterval);
	void LedColor2Process(byte _dType, byte sendMode1, byte r1, byte g1, byte b1, byte sendInterval1, byte sendMode2, byte r2, byte g2, byte b2, byte sendInterval2);
	void LedColor(byte sendMode, byte sendColor, byte sendInterval);
	void LedColor(byte sendMode, byte r, byte g, byte b, byte sendInterval);
	void LedColor(byte sendMode, byte sendColor[], byte sendInterval);
	void LedColorDefault(byte sendMode, byte r, byte g, byte b, byte sendInterval);
	void LedColorDefault(byte sendMode, byte sendColor[], byte sendInterval);
	void LedColorDefault(byte sendMode, byte sendColor[], byte sendInterval, byte sendMode2, byte sendColor2[], byte sendInterval2);

//------------------------------------------------------------------------------------//

	void LinkStateCheck();
	void ReceiveEventCheck(byte _completeData[]);
	void DisplayRSSI();
	int LowBatteryCheck(byte value);

//------------------------------------------------------------------------------------//

	void LED_Display(byte mode, int value);
	void LED_Connect();
	void LED_Blink(int time, int count);

//------------------------------------------------------------------------------------//

	unsigned short CRC16_Make(unsigned char *buf, int len); //CRC16-CCITT Format
	boolean CRC16_Check(unsigned char data[], int len, unsigned char crc[]);

//------------------------------------------------------------------------------------//

	void PrintDroneAddress();

//------------------------------------------------------------------------------------//

	void ButtonPressHoldWait(int button);
	void ButtonPressHoldWait(int button1, int button2);
	int AnalogScaleChange(int analogValue);
	int scaleChange(int analogValue);

//------------------------------------------------------------------------------------//

	boolean TimeCheck(word interval); 						//milliseconds
	boolean TimeOutSendCheck(word interval); 			//milliseconds
	boolean TimeCheckBuzz(word interval); 				//microseconds

//------------------------------------------------------------------------------------//

	void Buzz(long frequency, int tempo);

//------------------------------------------------------------------------------------//

	void goToHeight(int _range);


//------------------------------------------------------------------------------------//
	void ReceiveGetData(byte _reqType);
	int getBatteryPercentage();
	int getBatteryVoltage();
	int getHeight();
	int getState();
	int getDroneTemp();
	int getPressure();

	optdata getOptFlowPosition();
	acceldata getAccelerometer();
	gyrodata getAngularSpeed();
	angledata getGyroAngles();
	trimdata getTrim();

	boolean isUpsideDown();
	boolean isFlying();
	boolean isReadyToFly();
	boolean lowBatteryCheck();

//------------------------------------------------------------------------------------//

	//getter and setter
	void setRoll(int _roll);
	int getRoll();

	void setPitch(int _pitch);
	int getPitch();

	void setYaw(int _yaw);
	int getYaw();

	void setThrottle(int _throttle);
	int getThrottle();

	void trim(int _roll, int _pitch, int _yaw, int _throttle);
	void resetTrim();

	//flight command
	void go(int direction);
	void go(int direction, float duration);
	void go(int direction, float duration, int power);
	

	void move();
	void move(float duration);
	void move(int _roll, int _pitch, int _yaw, int _throttle);
	void move(float duration, int _roll, int _pitch, int _yaw, int _throttle);

	void turn(int direction);
	void turn(int direction, float duration);
	void turn(int direction, float duration, int power);


	void hover(float duration);
	void turnDegree(int _dir, int _angle);

	//FlightEvnet
	void takeoff();
	void land();
	void emergencyStop();



	void resetDefaultLED();

	void setEyeLED(byte Color,byte Mode);
	void setEyeLED(byte Color, byte Mode, byte Interval);
	void setEyeLED(byte R, byte G, byte B, byte Mode);
	void setEyeLED(byte R, byte G, byte B, byte Mode, byte Interval);
	void setArmLED(byte Color, byte Mode);
	void setArmLED(byte Color, byte Mode, byte Interval);
	void setArmLED(byte R, byte G, byte B, byte Mode);
	void setArmLED(byte R, byte G, byte B, byte Mode, byte Interval);
	void setAllLED(byte Color, byte Mode);
	void setAllLED(byte Color, byte Mode, byte Interval);
	void setAllLED(byte R, byte G, byte B, byte Mode);
	void setAllLED(byte R, byte G, byte B, byte Mode, byte Interval);
	void setEyeDefaultLED(byte R, byte G, byte B, byte Mode);
	void setEyeDefaultLED(byte R, byte G, byte B, byte Mode, byte Interval);
	void setArmDefaultLED(byte R, byte G, byte B, byte Mode);
	void setArmDefaultLED(byte R, byte G, byte B, byte Mode, byte Interval);
	void setAllDefaultLED(byte R, byte G, byte B, byte Mode);
	void setAllDefaultLED(byte R, byte G, byte B, byte Mode, byte Interval);

	// new function
	void eyeColor(byte Color, byte brightness);
	void eyeColor(byte R, byte G, byte B, byte brightness);
	void armColor(byte Color, byte brightness);
	void armColor(byte R, byte G, byte B, byte brightness);
	void eyeDefaultColor(byte R, byte G, byte B, byte Interval);
	void armDefaultColor(byte R, byte G, byte B, byte Interval);
	void eyePattern(byte Color, byte pattern, byte brightness);
	void eyePattern(byte R, byte G, byte B, byte pattern, byte brightness);
	void armPattern(byte Color, byte pattern, byte brightness);
	void armPattern(byte R, byte G, byte B, byte pattern, byte brightness);
	void eyeDefaultPattern(byte R, byte G, byte B, byte Mode, byte Interval);
	void armDefaultPattern(byte R, byte G, byte B, byte Mode, byte Interval);
	void eyeStrobe();
	void armStrobe();
	void eyeOff();
	void armOff();

	


	//sequence
	void flySequence(int shape);
	void sway();
	void zigzag();
	void square();
	void triangle();
	void hop();
	void circle();
	void spiral();

	void pair(byte address[]);
	void pair();
	void pair(int mode);
	void calibrate();

//------------------------------------------------------------------------------------//

	static byte receiveAttitudeSuccess;
	static byte receiveRangeSuccess;
	static byte receiveGyroSuccess;
	static byte receiveAccelSuccess;
	static byte receivePressureSuccess;
	static byte receiveTrimSuccess;
	static byte receiveStateSuccess;
	static byte receiveBatterySuccess;
	static byte receiveOptSuccess;

//------------------------------------------------------------------------------------//

	static int roll;
	static int pitch;
	static int yaw;
	static int throttle;

	static int attitudeRoll;
	static int attitudePitch;
	static int attitudeYaw;

	static int batteryPercent;
	static int batteryVoltage;

	static long fVelocitySumX ;
	static long fVelocitySumY;

	static long temperature;
	static long pressure	;

	static int ImuAccX;
	static int ImuAccY;
	static int ImuAccZ;

	static int ImuGyroRoll	;
	static int ImuGyroPitch;
	static int ImuGyroYaw	;

	static int ImuAngleRoll;
	static int ImuAnglePitch;
	static int ImuAngleYaw	;
	
	static int TrimAll_Roll;
	static int TrimAll_Pitch;
	static int TrimAll_Yaw;
	static int TrimAll_Throttle;
	static int TrimAll_Wheel;

//------------------------------------------------------------------------------------//

	byte cmdBuff[MAX_PACKET_LENGTH];

	byte checkHeader;
	byte cmdIndex;
	byte receiveDtype;
	byte receiveLength;

//------------------------------------------------------------------------------------//
	
	int SendInterval; //millis seconds
	int analogOffset;

	static byte displayMode;	//smar inventor : default 1

	static boolean pairing;
	static boolean	isConnectedBefore;
	
	static byte timeOutRetry;
	static byte sendCheckCount;
	static byte sendCheckFlag;
	static byte energy;
	static byte team;
	
	static unsigned long weapon;

//------------------------------------------------------------------------------------//
	//for CodeLoader
	boolean sendingData;	
	boolean sendDataControl;
	
//------------------------------------------------------------------------------------//
	static byte linkState;
	static int rssi;
	static byte battery;
	unsigned long	irMessageReceive;
	byte droneState[7];
	int sensorRange[6];
	long PreviousMillis;

	static byte armred;
	static byte armgreen;
	static byte armblue;
	static byte eyered;
	static byte eyegreen;
	static byte eyeblue;
	static byte armmode;
	static byte eyemode;

private:
	long PreviousBuzz;
	long timeOutSendPreviousMillis;
	
	static byte discoverFlag;
	static byte connectFlag;

	static byte devCount;
	byte devFind[5];

	int devRSSI[5];

	byte devAddress0[6];
	byte devAddress1[6];
	byte devAddress2[6];
	byte devAddress3[6];
	byte devAddress4[6];

	byte devAddressBuf[6];
	byte devAddressConnected[6];
	//---------------------------------------------//


};

extern CoDroneClass CoDrone;

#endif
