#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer
#define ascii_offset 48




enum FSMstate state;
enum SYSmode lpm_mode;


void main(void){
    char* ori_f = "Ori      ";
    char* nadav_f = "Nadav     ";
    char* ori_l = "Sadek     ";
    char* nadav_l = "Rozenfeld";

  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
  
  while(1){
	switch(state){
	  case state0:
        enterLPM(lpm_mode);
		break;
		 
	  case state1:
	    freqCount();
		break;
		 
	  case state2:
	    countMinute();
	    if(state == state2){
	        if(return_reset_timer()==0){
	            state = state0;
	        }
	    }
		break;
		
	  case state3:
	    tone_gen();
	    break;

	  case state4:
	      print_names(ori_f ,nadav_f ,ori_l , nadav_l);
	    break;
	}
  }
}
  
  
  
  
  
  
