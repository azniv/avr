
#ifndef	_STRUCT_H
#define _STRUCT_H 1


struct Time 
{
	uint8_t seconds;  //�������
	uint8_t minutes;  //������
	uint8_t hours;    //����
	uint8_t day;      //���� ������
	uint8_t date;     //�����
	uint8_t month;    //�����
	uint8_t year;     //���
};
/*
struct Alarm_time 
{
	uint8_t seconds;  //�������
	uint8_t minutes;  //������
	uint8_t hours;    //����
	uint8_t day;      //���� ������
	uint8_t date;     //�����
};	

*/
void ds_GetTime(struct Time* ds);
void ds_SetTime(struct Time* ds);
////////////////////////////////////////////////////
//������� ������ ��� �������� ����������
////////////////////////////////////////////////////
//void ds_GetTime_alarm(struct Alarm_time* ds);
////////////////////////////////////////////////////
//������� ���������� ��� �������� ��� ����������(������� � ����)
////////////////////////////////////////////////////
//void ds_SetTime_alarm(struct Alarm_time* ds);

void time2str(struct Time* ds, uint8_t* s);


#endif	/* struct.h */