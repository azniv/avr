
#ifndef	_STRUCT_H
#define _STRUCT_H 1


struct Time 
{
	uint8_t seconds;  //секунды
	uint8_t minutes;  //минуты
	uint8_t hours;    //часы
	uint8_t day;      //день недели
	uint8_t date;     //число
	uint8_t month;    //мес€ц
	uint8_t year;     //год
};
/*
struct Alarm_time 
{
	uint8_t seconds;  //секунды
	uint8_t minutes;  //минуты
	uint8_t hours;    //часы
	uint8_t day;      //день недели
	uint8_t date;     //число
};	

*/
void ds_GetTime(struct Time* ds);
void ds_SetTime(struct Time* ds);
////////////////////////////////////////////////////
//функци€ читает все регистры будильника
////////////////////////////////////////////////////
//void ds_GetTime_alarm(struct Alarm_time* ds);
////////////////////////////////////////////////////
//функци€ записывает все регистры дл€ будильника(времени и даты)
////////////////////////////////////////////////////
//void ds_SetTime_alarm(struct Alarm_time* ds);

void time2str(struct Time* ds, uint8_t* s);


#endif	/* struct.h */