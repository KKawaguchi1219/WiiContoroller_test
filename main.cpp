#include "mbed.h"
#include "WiiClassicController.h"
// wiiリモコン
WiiClassicController wii(D14, D15); // SDA(left side on rev C, GREEN), SCL(D6, YELLOW)
// コントローラー値

#define JYOY_L_CENTER 31
#define JYOY_R_CENTER 16

bool b_A;
bool b_B;
bool b_X;
bool b_Y;
bool b_R;
bool b_L;
bool b_ZL;
bool b_ZR;          //十字キーはまだ
bool b_minus;
bool b_plus;
bool b_home;
bool b_DU;
bool b_DD;
bool b_DR;
bool b_DL;
unsigned char j_LX;
unsigned char j_LY;
unsigned char j_RX;
unsigned char j_RY;

bool pre_b_A;
bool pre_b_R;
bool pre_b_L;
bool R_max;
bool L_max;
bool pre_b_plus;
bool pre_b_minus;
bool pre_b_X;

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        b_A = wii.button_A();
        b_B = wii.button_B();
        b_X = wii.button_X();
        b_Y = wii.button_Y();
        b_R = wii.button_R();
        b_L = wii.button_L();
        b_ZR = wii.button_ZR();
        b_ZL = wii.button_ZL();
        b_DU = wii.button_DU();
        b_DD = wii.button_DD();
        b_DL = wii.button_DL();
        b_DR = wii.button_DR();

        b_plus = wii.button_plus();
        b_minus = wii.button_minus();
        b_home = wii.button_home();
        j_LX = wii.joy_LX();
        j_LY = wii.joy_LY();
        j_RX = wii.joy_RX();
        j_RY = wii.joy_RY();

        printf("b_A: %d, b_B: %d, b_X: %d, b_Y: %d, b_R: %d, b_L: %d, b_ZR: %d, b_ZL: %d, b_DU: %d, b_DD: %d, b_DL: %d, b_DR: %d, b_plus: %d, b_minus: %d, b_home: %d\r\n", b_A, b_B, b_X, b_Y, b_R, b_L, b_ZR, b_ZL, b_DU, b_DD, b_DL, b_DR, b_plus, b_minus, b_home);
        printf("j_LX: %d, j_LY: %d, j_RX: %d, j_RY: %d\r\n\n", j_LX-JYOY_L_CENTER, j_LY-JYOY_L_CENTER, j_RX-JYOY_R_CENTER, j_RY-JYOY_R_CENTER);
        HAL_Delay(1000);
    }
}

