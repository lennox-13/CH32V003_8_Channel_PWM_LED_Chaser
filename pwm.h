#ifndef USER_PWM_H_
#define USER_PWM_H_

void TIM_PWMOut_Init(u16 arr, u16 psc, u16 ccp);
void setPwm(int num, int val);

#endif /* USER_PWM_H_ */
