#pragma SystemFile
void overrideSensorType(tSensors port, TSensorTypes stype)
{
	switch(stype)
	{
		case sensorLightInactive:
		case sensorLightActive:
		{
			setSensorAutoID(port, false);
			sleep(5);
			setSensorConnectionType(port, CONN_NXT_DUMB);
			sleep(5);
			setSensorType(port, stype);
			break;
		}
		case sensorI2CCustom:
		case sensorEV3_GenericI2C:
		{
			setSensorAutoID(port, false);
			sleep(5);
			setSensorConnectionType(port, CONN_NXT_IIC);
			sleep(100);
			break;
		}
		default: return;
	}
}
