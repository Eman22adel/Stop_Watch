

#ifndef SEGMENT_CFG_H_
#define SEGMENT_CFG_H_

/*FOR ALL TYPE*/
/*SELECT CC FOR COMMON CATHODE OR CN FOR COMMEN ANODE*/

#define  CC 0
#define  CN 1

#define  SEG_MODE CC

#define TRANSISTROR1 PINA7
#define TRANSISTROR2 PINB4

DIO_Pin_type SEG_PINArray[]={
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
};

#endif /* SEGMENT_CFG_H_ */