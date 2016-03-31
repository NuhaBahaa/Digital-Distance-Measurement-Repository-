#define GetBit(reg,BitNu)  ((reg>>BitNu)&1)
#define ClrBit(reg,BitNu)  (reg &= ~(1<<BitNu))
#define SetBit(reg,BitNu)	(reg |=(1<<BitNu))
#define TogBit(reg,BitNu)	(reg ^=(1<<BitNu))
#define AssignBit(reg,BitNu, BitVal)	((~(1<<BitNu))&reg)|(BitVal<<BitNu)

#define SetReg(reg)			reg =255
#define ClrReg(reg)			reg=0
#define togReg(reg)			reg=~reg
#define AssignReg(reg,value) reg=value

#define GetLowNib(reg)		(reg & 15)
#define SetLowNib(reg)		(reg | 15)
#define ClrLowNib(reg)		reg &= 240
#define TogLowNib(reg)		reg ^= 15
#define AssignLowNib(reg,value) reg=(reg&240)|(value&15)

#define GetHiNib(reg)		(reg & 240)
#define SetHiNib(reg)		(reg | 240)
#define ClrHiNib(reg)		reg &= 15
#define TogHiNib(reg)		reg ^= 240
#define AssignHiNib(reg,value) (reg=(reg&15)|(value<<4)



