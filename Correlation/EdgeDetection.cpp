

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
extern "C" void convert_camera_to_screen();
extern "C" void put_pixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue);

int correlate(int iAddress,int jAddress,int value)   {
    int total=0;
    float avg;
    for(int i=0;i<320;i++)  {
        for(int j=0;j<240;j++)  {
            total+=(get_pixel(iAddress,jAddress,3)*value);
        }
    }
    avg=total/(320*240);
    return avg;
}


int main()  {
  init(0);

  open_screen_stream();
  float err;
  int val;
  int val2;
  int delta = 2;
  int tot;
  double threshold;
  int prev_image[320][240];
  int image[320][240];
//    int arraypointer = *image;

  for(int i=0;i<320;i++){
    for(int j=0;j<320;j++){
      prev_image[i][j] =0;
    }
  }
    while(1)  {
        take_picture();
        convert_camera_to_screen();

        //loads edge detected image into pixel buffer
        for(int i=0;i<320;i++)  {
    	    for(int j=0;j<240;j++)	{
                val = 8*image[i][j] - image[i-delta][j] -image[i+delta][j]     -image[i-delta][j+delta] -image[i][j+delta] -image[i+delta][j+delta]       -image[i-delta][j-delta] -image[i][j-delta] -image[i+delta][j-delta];
                if(val>255)
                    val = 255;
                if(val<0)
	                val = 0;
                set_pixel(i,j,val,val,val);
	        }
        }
        //loads the edge detected image back to the image array
        for(int i=0;i<320;i++)  {
            for(int j=0;j<240;j++)  {
                image[i][j] = get_pixel(i,j,3);
            }
        }
        //performs the correlation on only white pixels
        for(int i=0;i<320;i++)  {
            for(int j=0;j<240;j++)  {
                if (prev_image[i][j]>100) {
                    put_pixel(i,j,correlate(i,j,prev_image[i][j]),0,0);
                }
            }
        }
        //loads the current image into the previous image;
        for(int i=0;i<320;i++)  {
            for(int j=0;j<240;j++)  {
                prev_image[i][j]=image[i][j];
            }
        }



            

    update_screen();
//    set_motor(1,40+0.8*err);
//    set_motor(2,40-0.8*err);
  }

return 0;}
