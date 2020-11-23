#ifndef BITOPERATIONS__H_
#define BITOPERATIONS__H_

	#define set_bit_(var,bit)			var|= (1<<bit)
	#define clear_bit_(var,bit)			var&=~(1<<bit)
	#define toggle_bit_(var,bit)		var^=(1<<bit)
	#define get_bit_(var,bit)			((var>>bit)&1)

#endif 
