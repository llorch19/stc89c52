// ���ֲ����� :  ���ų���Ů��  ͬһ�׸�  ��ֻ����
#include <reg52.h>           //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "SoundPlay.h"
#include "music.h"

typedef unsigned int u16;     //���������ͽ�����������
typedef unsigned char u8;


u8 key_id = 0;

sbit k1 = P3 ^ 1;
sbit k2 = P3 ^ 0;
sbit k3 = P3 ^ 2;
sbit k4 = P3 ^ 3;

sbit beep = P1 ^ 5;
u8 x = 200 ;

void Delay1ms(unsigned int count)
{
    unsigned int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 120; j++);
}

void delay(u16 i)
{
    while (i--);
}

// ɨ�� ���� K1-K4
void keypros();

void main()
{
    InitialSound();
    while (1) {
        keypros();

        // K1 �������   ��ֻ����
        if (key_id == 1) {
            Play(Music_Two, 0, 3, 360);
            Delay1ms(500);

            key_id = 0;
        }

        // K2 �������   ���ų���Ů��
        if (key_id == 2) {
            Play(Music_Girl, 0, 3, 360);
            Delay1ms(500);

            key_id = 0;
        }

        // K3 �������   ͬһ�׸�
        if (key_id == 3) {
            Play(Music_Same, 0, 3, 360);
            Delay1ms(500);
            key_id = 0;
        }

        // K4  beep ����
        if (key_id == 4) {
            while (x--) {
                beep = ~beep;
                delay(100);
            }
            key_id = 0;
            x = 200 ;
        }
    }
}

// ɨ�� ���� K1-K4
void keypros()
{
    if (k1 == 0) {       // ���� K1 ;  key_id = 1
        delay(1000);
        if (k1 == 0) {
            key_id = 1;
        }
        while (!k1);
    }

    if (k2 == 0) {      // ���� K2 ;  key_id = 2
        delay(1000);
        if (k2 == 0) {
            key_id = 2;
        }
        while (!k2);
    }

    if (k3 == 0) {
        delay(1000);
        if (k3 == 0) {
            key_id = 3;
        }
        while (!k3);
    }

    if (k4 == 0) {
        delay(1000);
        if (k4 == 0) {
            key_id = 4;
        }
        while (!k4);
    }
}