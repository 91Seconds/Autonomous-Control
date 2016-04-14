/*SKELETON CODES FOR AVC */
/*  A.Roberts, 5 Apr 2016*/
#include <stdio.h>

//#include <pthread.h>
#include <time.h>
#include <string.h>

// sudo gcc -Wall
extern "C" int init_hardware();
extern "C" int init(int d_lev);

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int color);
extern "C" void set_pixel(int col, int row, char red,char green,char blue);

extern "C" int open_screen_stream();
extern "C" int close_screen_stream();
extern "C" int update_screen();
//extern "C" void GetLine(int row,int threshold);
extern "C" int display_picture(int delay_sec,int delay_usec);
extern "C" int save_picture(char filename[5]);

extern "C" int set_motor(int motor,int speed);

extern "C" int read_analog(int ch_adc);
extern "C" int Sleep(int sec, int usec);
extern "C" int select_IO(int chan, int direct);
extern "C" int write_digital(int chan,char level);
extern "C" int read_digital(int chan);
extern "C" int set_PWM(int chan, int value);

extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);

int main()  {
  init(0);

  open_screen_stream();

  int val;
  int val2;

  while(1)  {
    take_picture();
    int image[320][240];
    for(int i=0;i<320;i++)  {
      for(int j=0;j<240;j++)  {
        image[i][j] = get_pixel(i,j,0);
        set_pixel(i,j,200,200,200);
//	printf("loop ran \n");
      }
    }
	set_pixel(1,1,255,0,0);
    for(int i=0;i<160;i++)  {
      for(int j=0;j<120;j++)  {
        val = image[2*i][2*j];
        set_pixel(i,j,val,val,val);
      }
    }
    for(int i=0;i<160;i++){
    	for(int j=0;j<120;j++)	{
//	val2 = val;
	val = ((2*image[2*i][2*j])-image[2*i-2][2*j]-image[2*i+2][2*j]);
//	val2 = val2-val;
//	printf("value to be drawn %d\n",val);
	if(val>255)
	    val = 255;
	if(val<0)
	    val = 0;
	set_pixel(i+160,j,val,val,val);
	}
    }

       update_screen();
  }
return 0;}
