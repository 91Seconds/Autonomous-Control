

/*SKELETON CODES FOR AVC */
/*  A.Roberts, 5 Apr 2016*/
#include <stdio.h>
#include <cmath>
//#include <pthread.h>
#include <time.h>
#include <string.h>


//using namespace std;

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

  for(int i=0;i<320;i++){
    for(int j=0;j<320;j++){
      prev_image[i][j] =0;
    }
  }

  while(1)  {
    take_picture();
    convert_camera_to_screen();

    threshold = 100; //tot/(320*240);
    err=0;
    for(int i=0;i<320;i++)	{
        for(int j=0;j<240;j++)	{
            if(image[i][j]>threshold){
                //put_pixel(i+320,j+240,255,255,255);
                int vsdb = std::atan((double)(i-160)/(double)(j))*get_pixel(i,j,3);
            }
            //else
                //put_pixel(i+320,j+240,0,0,0);
        }
    }
    err = err/(160*120);
    printf("Err: %f\n",err);


//    for(int i=0;i<320;i++)	{
//        for(int j=0;j<240;j++)	{
            

    update_screen();
    set_motor(1,40+0.12*err);
    set_motor(2,40-0.12*err);
  }

return 0;}
