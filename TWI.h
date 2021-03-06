
#ifndef	_TWI_H
#define _TWI_H 1

#define DDR_DS  DDRC
#define PORT_DS PORTC



/////////////////////////////////////////////////////
// �������� ������� �����
/////////////////////////////////////////////////////
static inline void TWI_Start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));//�������� ��������� ���� TWIN
}
/////////////////////////////////////////////////////
// �������� ������� ����
/////////////////////////////////////////////////////
static inline void TWI_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

/*
__attribute__((always_inline)) void init_DS(void){
	TWBR    = 0xFF; 
	DDR_DS  &= ~((1<<4)|(1<<5));
	PORT_DS |=(1<<4)|(1<<5);
	
	//��� ������� 1 ��� 
	//TWSR = (0 << TWPS1)|(0 << TWPS0); //���� �������� �� 64
	//TWCR |= (1 << TWEN); //��������� ������ TWI
}*/
/////////////////////////////////////////////////////
// �������� �����
/////////////////////////////////////////////////////
static inline void TWI_SendByte(uint8_t c){
	TWDR = c;//�������� �������� � ������� ������
	TWCR = (1<<TWINT)|(1<<TWEN);//������ �������� ����� ������
	while (!(TWCR & (1<<TWINT)));//�������� ��������� ���� TWIN
}

/////////////////////////////////////////////////////
// ������ ����� 
/////////////////////////////////////////////////////
static inline void TWI_ReadByte(void){
	TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    TWI_Stop();
}

//�������� SLA_W + ���� ������
void TWI_SendPocket (uint8_t  value, uint8_t adres_rw)
{
	TWI_Start(); // ���������� ������� �����
	TWI_SendByte(adres_rw); //��������� ����� ����������+��� ������
	TWI_SendByte(value);//���������� ���� ������
	TWI_Stop();//���������� ������� ����
}

//��������� ������� ������ �� I2C
//������ �����
uint8_t TWI_RecieveByte(void)
{
	uint8_t dat;//���������� �������� ��������
	TWCR |= (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));//�������� ��������� ���� TWIN
	dat = TWDR;//������ ������� ������
	return dat;
}
	
/////////////////////////////////////////////////////
// ������������� ����������
/////////////////////////////////////////////////////

#endif	/* TWI.h */