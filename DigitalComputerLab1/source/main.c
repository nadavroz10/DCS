#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer
#define ascii_offset 48
#define id_size 9



enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  char id[9] ={1,2,3,4,5,6,7,8,9}; // example id
  char name[9] = "Israel Israeli";
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  
  while(1){
	switch(state){
	  case state0:
        enterLPM(lpm_mode);
		break;
		 
	  case state1:
		disable_interrupts();
		printDigitArr2LEDs(id,id_size,LEDs_SHOW_RATE); // remember to change rate
		enable_interrupts();
		state = state0;
		break;
		 
	  case state2:
		disable_interrupts();
		ShiftNum2LEDs(LEDs_SHOW_RATE);
		enable_interrupts();
		state = state0;
		break;
		
	  case state3:
	        enable_interrupts();
	        generatePwm();
	    break;

	  case state4:
	        disable_interrupts();
	        PrintStr(name,debounceVal);
	        enable_interrupts();
	        state = state0;
	        break;
	}
  }
}
  
  
  
  
  
  
