#include "ch32v00x.h"
#include "pwm.h"

// PD7 must be set as IO in WCH-Link utility!

void fadein(int num, int delay){
    for (int n = 0; n < 256; n++) {
        setPwm(num, n);
        Delay_Us(delay);
    }
}

void fadeout(int num, int delay){
    for (int n = 255; n >= 0; n--) {
        setPwm(num, n);
        Delay_Us(delay);
    }
}

void fadein_all(int delay) {
    for (int n = 0; n < 256; n++) {
        for (int i = 0; i < 8; i++) {
            setPwm(i, n);
        }
        Delay_Us(delay);
    }
}

void fadeout_all(int delay) {
    for (int n = 255; n >= 0; n--) {
        for (int i = 0; i < 8; i++) {
            setPwm(i, n);
        }
        Delay_Us(delay);
    }
}

int main(void){
      SystemCoreClockUpdate();
      Delay_Init();
      TIM_PWMOut_Init(255, 250 - 1, 0);  // HSI 8MHz / 250 / 256 = 125Hz

    while(1) {
      // PWM chaser left to right
      for (int i = 0; i <= 7; i++){
      fadein(i,800);
      }
      for (int i = 0; i <= 7; i++){
      fadeout(i,1000);
      }

      Delay_Ms(200);

      // PWM chaser right to left
      for (int i = 7; i >= 0; i--){
      fadein(i,800);
      }
      for (int i = 7; i >= 0; i--){
      fadeout(i,1000);
      }

      Delay_Ms(200);

      // PWM faade in/out all
      for (int i = 0; i < 3; i++){
      fadein_all(1000);
      Delay_Ms(500);
      fadeout_all(1000);
      Delay_Ms(500);
      }

      Delay_Ms(200);
   }
}
