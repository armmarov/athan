/*
	Developer : Ammar
	Email     : armmarov@gmail.com
	Version   : 1.0
*/

#ifndef __ATHAN_H__
#define __ATHAN_H__

#define SOLAR_DECLINATION     -23.44
#define OFFSET_DAY_PASS           10
#define DAYS                     360
#define TIMEZONE_MALAYSIA          8
#define TOTAL_DAYS_IN_JAN         31
#define TOTAL_DAYS_IN_FEB         28
#define TOTAL_DAYS_IN_FEB_LEAP    29
#define TOTAL_DAYS_IN_MAR         31
#define TOTAL_DAYS_IN_APR         30
#define TOTAL_DAYS_IN_MAY         31
#define TOTAL_DAYS_IN_JUN         30
#define TOTAL_DAYS_IN_JUL         31
#define TOTAL_DAYS_IN_AUG         31
#define TOTAL_DAYS_IN_SEP         30
#define TOTAL_DAYS_IN_OCT         31
#define TOTAL_DAYS_IN_NOV         30
#define TOTAL_DAYS_IN_DEC         31

#define SUN_ANGLE_SUBUH			  20
#define SUN_ANGLE_SUNRISE		  0.8333
#define SUN_ANGLE_ZUHUR			  0
#define SUN_ANGLE_ASAR			  0
#define SUN_ANGLE_MAGHRIB		  0.8333
#define SUN_ANGLE_ISYAK 		  18
#define T_ASAR                    1.5

#define PI						  3.14159
#define DEG_TO_RAD				  PI / 180
#define RAD_TO_DEG				  180 / PI

#define TOTAL_DAYS_IN_1ST_HALF_YEARS      TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR + TOTAL_DAYS_IN_MAY + TOTAL_DAYS_IN_JUN
#define TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP TOTAL_DAYS_IN_JAN + TOTAL_DAYS_IN_FEB_LEAP + TOTAL_DAYS_IN_MAR + TOTAL_DAYS_IN_APR + TOTAL_DAYS_IN_MAY + TOTAL_DAYS_IN_JUN
#define TOTAL_DAYS_IN_2ND_HALF_YEARS      TOTAL_DAYS_IN_JUL + TOTAL_DAYS_IN_AUG + TOTAL_DAYS_IN_SEP + TOTAL_DAYS_IN_OCT + TOTAL_DAYS_IN_NOV + TOTAL_DAYS_IN_DEC
#define TOTAL_DAYS_IN_YEARS               TOTAL_DAYS_IN_1ST_HALF_YEARS + TOTAL_DAYS_IN_2ND_HALF_YEARS
#define TOTAL_DAYS_IN_LEAP_YEARS          TOTAL_DAYS_IN_1ST_HALF_YEARS_LEAP + TOTAL_DAYS_IN_2ND_HALF_YEARS

enum EN_ATHAN_TIME
{
	EN_ATHAN_TIME_INIT = 0,
	EN_ATHAN_TIME_SUBUH,
	EN_ATHAN_TIME_SUNRISE,
	EN_ATHAN_TIME_ZUHUR,
	EN_ATHAN_TIME_ASAR,
	EN_ATHAN_TIME_MAGHRIB,
	EN_ATHAN_TIME_ISYAK
};

enum EN_MONTH
{
	EN_MONTH_INIT = 0,
	EN_MONTH_JAN,
	EN_MONTH_FEB,
	EN_MONTH_MAR,
	EN_MONTH_APR,
	EN_MONTH_MAY,
	EN_MONTH_JUN,
	EN_MONTH_JUL,
	EN_MONTH_AUG,
	EN_MONTH_SEP,
	EN_MONTH_OCT,
	EN_MONTH_NOV,
	EN_MONTH_DEC
};

struct ST_ATHAN_TIME {
	int hour;
	int min;
	int sec;
};
	
class Athan
{
public:

	static Athan* GetInstance(void);
	
	void Set_Offset(float offset);
	float Get_Offset(void);
	
	void Set_Latitude(double latitude);
	double Get_Latitude();
	
	void Set_Longitude(double longitude);
	double Get_Longitude();
	
	ST_ATHAN_TIME Get_Athan_Time(EN_ATHAN_TIME athan_time);

private:

	Athan(void);
	~Athan(void);

	static Athan* m_pInstance;
	
	float m_offset_time;
	double m_latitude;
	double m_longitude;
	
	double arccot(double x);
	
	int Get_Current_Year();
	int Get_Current_Day_In_Year();
	double Calculate_Declination_of_Sun();
	double Calculate_Equation_of_Time();
	
	double Calculate_Time_Diff(float alpha);
	double Calculate_Time_Diff_Asr(float time);
	
	ST_ATHAN_TIME Get_Athan_Subuh();
	ST_ATHAN_TIME Get_Sunrise();
	ST_ATHAN_TIME Get_Athan_Zuhur();
	ST_ATHAN_TIME Get_Athan_Asar();
	ST_ATHAN_TIME Get_Athan_Maghrib();
	ST_ATHAN_TIME Get_Athan_Isyak();	
	ST_ATHAN_TIME Calculate_Time_Update(ST_ATHAN_TIME t1, ST_ATHAN_TIME t2, bool isUpward);
	
};
#endif