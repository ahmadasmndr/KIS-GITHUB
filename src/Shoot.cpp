#include "Arduino.h"
#include "Servo.h"
#include "debug.h"
#include "Shoot.h"
debug debshoot;
Servo shhot_motor;
float delay_time_shoot;
int angel=20;
int motor_delay=100;
int end_angel=0;

void Shoot::motorIntil()
{
  shhot_motor.attach(9);
  shhot_motor.write(0);
}
void Shoot::shootManuel(int ango)
{
          shhot_motor.write(ango);
          delay(motor_delay);
          shhot_motor.write(end_angel); 

}

void Shoot::fireBall(uint16_t delta_hoder,float time_resto,uint8_t section, float total_time , uint16_t window,uint16_t target_time)
{

        if (time_resto <= (target_time+ window) && time_resto >= target_time )
        {
          shhot_motor.write(angel);
          delay(motor_delay);
          shhot_motor.write(end_angel);
          debshoot.sPrint("NORMAL_IF  if work time is ", time_resto, "ms");
          debshoot.sPrint("NORMAL_IF  SHOOT SECTION ", section, "");
        //   debshoot.sPrint("NORMAL_IF photo_speed is ", spedo.photoSpeed(time_delta_photo), "rad/s");
        }
        else if (time_resto > target_time)
        {
          delay_time_shoot = time_resto - target_time;
          delay(delay_time_shoot);
          shhot_motor.write(angel);
          delay(motor_delay);
          shhot_motor.write(end_angel);
          // debshoot.sPrint("SECOND_IF 2- if photo_speed is ", spedo.photoSpeed(time_delta_photo), "rad/s");
          debshoot.sPrint("SECOND_IF 2- if work time is ", time_resto, "ms");
          debshoot.sPrint("SECOND_IF 2- total time ", total_time, "ms");
          debshoot.sPrint("target_time", target_time, "ms");
          debshoot.sPrint("SECOND_IF 2- if delay time is ", delay_time_shoot, "ms");
          debshoot.sPrint("SECOND_IF 2- if new work time is ", time_resto - delay_time_shoot, "ms");
          
        }
        else if (time_resto < target_time)
        {
          if (total_time > target_time)
         {
            delay_time_shoot=total_time-(target_time -time_resto);
            delay(delay_time_shoot);
            shhot_motor.write(angel);
            delay(motor_delay);
            shhot_motor.write(end_angel);
             // debshoot.sPrint("THIRD_IF 3 - if speed is ", spedo.photoSpeed(time_delta_photo), "rad/s");
            debshoot.sPrint("THIRD_IF 3 - if work time is ", time_resto, "ms");
            debshoot.sPrint("THIRD_IF 3 - if delay time is ", delay_time_shoot, "ms");
            debshoot.sPrint("THIRD_IF 3 - if new work time is ", time_resto - delay_time_shoot, "ms");
         }
    
        }


}
