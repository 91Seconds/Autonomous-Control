/*SKELETON CODES FOR AVC */
/*  A.Roberts, 5 Apr 2016*/
#include <stdio.h>

//#include <pthread.h>
#include <time.h>
#include <string.h>
#include <cmath>

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
    int edgeDetectedImage[320][240];
    int prevEdgeDetected[320][240];
    double correlation[32][32];

    while(1)
    {
        take_picture();
        convert_camera_to_screen();

        for(int i=16;i<320-16;i++)  {
            for(int j=16;j<240-16;j++)  {
                for(int k=-16;k<16;k++) {
                    for(int l=-16;l<16;l++) {
                        correlation[k+16][l+16] = sqrt((double)(get_pixel(i,j,3)*prevEdgeDetected[i+k][j+l]));
                    }
                }
            }
        }
        for(int k=0;k<32;k++)   {
            for(int l=0;l<32;l++)   {
                put_pixel(k+400,l+400,correlation[k][l],0,0);
            }
        }
        update_screen();
        for(int i=0;i<320;i++)  {
            for(int j=0;j<240;j++)  {
                prevEdgeDetected[i][j] = edgeDetectedImage[i][j];
            }
        }
    }
}