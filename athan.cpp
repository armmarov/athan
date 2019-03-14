/*
	Developer : Ammar
	Email     : armmarov@gmail.com
	Version   : 1.0
*/

#include <ctime>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "athan.h"

using namespace std;

Athan* Athan::m_pInstance = NULL;

Athan* Athan::GetInstance(void)
{
	if(m_pInstance == NULL) {
		m_pInstance = new Athan;
	}

	return m_pInstance;
}

Athan::Athan(void)
{
	m_offset_time = 0;
	m_latitude = 0;
	m_longitude = 0;
}

Athan::~Athan(void)
{
	
}

/*
	Function: To set offset for athan time
	Argument: float
	Return: -
*/
void Athan::Set_Offset(float offset)
{
	m_offset_time = offset;
}

/*
	Function: To get offset for athan time
	Argument: -
	Return: float
*/
float Athan::Get_Offset()
{
	return m_offset_time;
}

/*
	Function: To set latitude
	Argument: double
	Return: -
*/
void Athan::Set_Latitude(double latitude)
{
	m_latitude = latitude;
}

/*
	Function: To get latitude
	Argument: -
	Return: double
*/
double Athan::Get_Latitude()
{
	return m_latitude;
}

/*
	Function: To set longitude
	Argument: double
	Return: -
*/
void Athan::Set_Longitude(double longitude)
{
	m_longitude = longitude;
}

/*
	Function: To get longitude
	Argument: -
	Return: double
*/
double Athan::Get_Longitude()
{
	return m_longitude;
}

/*
	Function: To get athan time
	Argument: EN_ATHAN_TIME
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Time(EN_ATHAN_TIME athan_time)
{
	switch(athan_time) {
		case EN_ATHAN_TIME_SUBUH:
			return Get_Athan_Subuh();
		case EN_ATHAN_TIME_SUNRISE:
			return Get_Sunrise();
		case EN_ATHAN_TIME_ZUHUR:
			return Get_Athan_Zuhur();
		case EN_ATHAN_TIME_ASAR:
			return Get_Athan_Asar();
		case EN_ATHAN_TIME_MAGHRIB:
			return Get_Athan_Maghrib();
		case EN_ATHAN_TIME_ISYAK:
			return Get_Athan_Isyak();
		default:
			break;
	}
	
	ST_ATHAN_TIME temp;
	return temp;
}

/*
	Function: To get current year
	Argument: -
	Return: int
*/
int Athan::Get_Current_Year() 
{
   time_t now = time(0);
  
   tm *ltm = localtime(&now);
   
   return 1900 + ltm->tm_year;
}

/*
	Function: To get current day in year
	Argument: -
	Return: int
*/
int Athan::Get_Current_Day_In_Year() 
{
   time_t now = time(0);
   int cur_month = 0;
   int cur_day = 0;
   int ttl_day = 0;
   
   tm *ltm = localtime(&now);
   cur_month = 1 + ltm->tm_mon;
   cur_day = ltm->tm_mday;
   
   switch(cur_month) {
		case int(EN_MONTH_JAN):
			ttl_day = cur_day;
			break;
		case int(EN_MONTH_FEB):
			ttl_day = cur_day + TOTAL_DAYS_IN_JAN;
			break;
		case int(EN_MONTH_MAR):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB_LEAP;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB;
			break;
		case int(EN_MONTH_APR):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB_LEAP + TOTAL_DAYS_IN_MAR;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB + TOTAL_DAYS_IN_MAR;
			break;
		case int(EN_MONTH_MAY):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB_LEAP + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR;
			break;
		case int(EN_MONTH_JUN):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB_LEAP + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR + TOTAL_DAYS_IN_MAY;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR + TOTAL_DAYS_IN_MAY;
			break;
		case int(EN_MONTH_JUL):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS;
			break;
		case int(EN_MONTH_AUG):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_JUL;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_JUL;
			break;
		case int(EN_MONTH_SEP):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG;
			break;
		case int(EN_MONTH_OCT):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP;
			break;
		case int(EN_MONTH_NOV):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP + TOTAL_DAYS_IN_OCT;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_OCT;
			break;
		case int(EN_MONTH_DEC):
			if(Get_Current_Year()%4==0) // Case for leap year
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP + TOTAL_DAYS_IN_OCT + TOTAL_DAYS_IN_NOV;
			else
				ttl_day = cur_day + TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP + TOTAL_DAYS_IN_OCT + TOTAL_DAYS_IN_NOV;
			break;
		default:
			break;
   }
   
   return ttl_day;
}

/*
	Function: To calculate time different for case Subuh, Sunrise, Maghrib and Isyak
	Argument: float
	Return: double
*/
double Athan::Calculate_Time_Diff(float alpha)
{
	double d1 = -sin(alpha * DEG_TO_RAD);
	double d2 = sin(m_latitude * DEG_TO_RAD)*sin(Calculate_Declination_of_Sun() * DEG_TO_RAD);
	double d3 = cos(m_latitude * DEG_TO_RAD)*cos(Calculate_Declination_of_Sun() * DEG_TO_RAD);
	return acos((d1-d2)/d3) * RAD_TO_DEG / 15;
}

/*
	Function: To calculate time different for case Asar
	Argument: float
	Return: double
*/
double Athan::Calculate_Time_Diff_Asr(float time)
{	
	double d0 = tan(m_latitude * DEG_TO_RAD - Calculate_Declination_of_Sun() * DEG_TO_RAD);
	double d1 = arccot(time + d0);
	double d2 = sin(m_latitude * DEG_TO_RAD)*sin(Calculate_Declination_of_Sun() * DEG_TO_RAD);
	double d3 = cos(m_latitude * DEG_TO_RAD)*cos(Calculate_Declination_of_Sun() * DEG_TO_RAD);
	return acos((sin(d1)-d2)/d3) * RAD_TO_DEG / 15;
}

double Athan::arccot(double x) 
{
	return atan(1/x);	
}

/*
	Function: To calculate time update
	Argument: ST_ATHAN_TIME, ST_ATHAN_TIME, bool
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Calculate_Time_Update(ST_ATHAN_TIME t1, ST_ATHAN_TIME t2, bool isUpward) {
	
	ST_ATHAN_TIME ret;
	
	if(isUpward) {
		ret.hour = t1.hour + t2.hour;
		ret.min = t1.min + t2.min;
	} else {
		if(t1.min < t2.min) {
			ret.hour = t1.hour - t2.hour - 1;
			ret.min = (60 + t1.min - t2.min);	
		} else {
			
			ret.hour = t1.hour - t2.hour;
			ret.min = (t1.min - t2.min);
		}
	}

	if(ret.min >= 60) {
		ret.min = (ret.min - 60);
		ret.hour = ret.hour + 1;			
	}
	
	return ret;	
}

/*
	Function: To calculate Subuh time
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Subuh() 
{	
	double hour = 0;
	double min = 0;
	double time = Calculate_Time_Diff(SUN_ANGLE_SUBUH);
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60);
	athan_time.sec = 0;
	
	return Calculate_Time_Update(Get_Athan_Zuhur(), athan_time, false);
}

/*
	Function: To calculate Sunrise
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Sunrise() 
{	
	double hour = 0;
	double min = 0;
	double time = Calculate_Time_Diff(SUN_ANGLE_SUNRISE);
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60);
	athan_time.sec = 0;
	
	return Calculate_Time_Update(Get_Athan_Zuhur(), athan_time, false);
}

/*
	Function: To calculate Zuhur
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Zuhur() 
{
	double hour = 0;
	double min = 0;
	double time = 12 + TIMEZONE_MALAYSIA - m_longitude/15;
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60 - Calculate_Equation_of_Time() + m_offset_time);
	athan_time.sec = 0;
	
	return athan_time;
}

/*
	Function: To calculate Asar
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Asar() 
{	
	double hour = 0;
	double min = 0;
	double time = Calculate_Time_Diff_Asr(T_ASAR);
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60);
	athan_time.sec = 0;
	
	return Calculate_Time_Update(Get_Athan_Zuhur(), athan_time, true);
}

/*
	Function: To calculate Maghrib
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Maghrib() 
{	
	double hour = 0;
	double min = 0;
	double time = Calculate_Time_Diff(SUN_ANGLE_MAGHRIB);
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60);
	athan_time.sec = 0;
	
	return Calculate_Time_Update(Get_Athan_Zuhur(), athan_time, true);
}

/*
	Function: To calculate Isyak
	Argument: -
	Return: ST_ATHAN_TIME
*/
ST_ATHAN_TIME Athan::Get_Athan_Isyak() 
{
	double hour = 0;
	double min = 0;
	double time = Calculate_Time_Diff(SUN_ANGLE_ISYAK);
	
	min = modf (time , &hour);
	
	ST_ATHAN_TIME athan_time;
	athan_time.hour = int(hour);
	athan_time.min = int(min*60);
	athan_time.sec = 0;
	
	return Calculate_Time_Update(Get_Athan_Zuhur(), athan_time, true);
}

/*
	Function: To calculate declination of sun
	Argument: -
	Return: double
*/
double Athan::Calculate_Declination_of_Sun()
{
	if(Get_Current_Year()%4==0)
		return SOLAR_DECLINATION * cos((DAYS/TOTAL_DAYS_IN_LEAP_YEARS) * (Get_Current_Day_In_Year()+10) * DEG_TO_RAD);
	else 
		return SOLAR_DECLINATION * cos((DAYS/TOTAL_DAYS_IN_YEARS) * (Get_Current_Day_In_Year()+10) * DEG_TO_RAD);
}

/*
	Function: To calculate equation of time
	Argument: -
	Return: double
*/
double Athan::Calculate_Equation_of_Time()
{
	double d1 = sin(Get_Current_Day_In_Year());
	double d2 = sin(2*Get_Current_Day_In_Year() + 3.588);
	return (-7.655 * d1)  + (9.873 * d2);
}

#ifdef UNIT_TEST
int main() {
	
	float offset = 0;
	double latitude = 1.65;
	double longitude = 103.2;
	
	ST_ATHAN_TIME temp_subuh;
	ST_ATHAN_TIME temp_sunrise;
	ST_ATHAN_TIME temp_zuhur;
	ST_ATHAN_TIME temp_asar;
	ST_ATHAN_TIME temp_maghrib;
	ST_ATHAN_TIME temp_isyak;
	
	Athan::GetInstance()->Set_Offset(offset);
	cout << "Offset is : " << Athan::GetInstance()->Get_Offset() << endl;

	Athan::GetInstance()->Set_Latitude(latitude);
	cout << "Latitude is : " << Athan::GetInstance()->Get_Latitude() << endl;
	
	Athan::GetInstance()->Set_Longitude(longitude);
	cout << "Longitude is : " << Athan::GetInstance()->Get_Longitude() << endl;
	
	temp_subuh = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_SUBUH);
	temp_sunrise = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_SUNRISE);
	temp_zuhur = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_ZUHUR);
	temp_asar = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_ASAR);
	temp_maghrib = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_MAGHRIB);
	temp_isyak = Athan::GetInstance()->Get_Athan_Time(EN_ATHAN_TIME_ISYAK);
	
	cout << endl;
	cout << "########################" << endl;
	cout << "Subuh is at " << temp_subuh.hour << ":" << setfill('0') << setw(2) << temp_subuh.min << endl;
	cout << "Sunrise is at " << temp_sunrise.hour << ":" << setfill('0') << setw(2) << temp_sunrise.min << endl;
	cout << "Zuhur is at " << temp_zuhur.hour << ":" << setfill('0') << setw(2) << temp_zuhur.min << endl;
	cout << "Asar is at " << temp_asar.hour << ":" << setfill('0') << setw(2) << temp_asar.min << endl;
	cout << "Maghrib is at " << temp_maghrib.hour << ":" << setfill('0') << setw(2) << temp_maghrib.min << endl;
	cout << "Isyak is at " << temp_isyak.hour << ":" << setfill('0') << setw(2) << temp_isyak.min << endl;
	cout << "########################" << endl;
	
	return 0;
}
#endif




