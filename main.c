#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

// HDMI SWITCH B.1.0

/*
����
1. ����� ���� ���
2. ���� ä���� ������ ����� ������ ����(���� ū ������ ���� ��ȣ)�� �翬��, �ƹ� ������ ������ 1������
3. �Է��� 8�� ����� 1��
*/

void Init(); //�ʱ⼳��
void Starting_Logo_Disp(); //����ȭ��

char State_Data;

int main(void) {
	Init();
    Starting_Logo_Disp();
    while (1) {
    }
    return 0;
}

void Init() {
	char State_Data_AF = '0';
	FILE *State_Save;
	if (State_Save = fopen("State_Save", "r")) {
		State_Data = fgetc(State_Save);
	}
	else {
		State_Save = fopen("State_Save", "w");
		fputc(State_Data_AF, State_Save);		
	}
	fclose(State_Save);
}

void Starting_Logo_Disp() {
	
    int Press_Enter = 0;
    printf("������������������������������������������������������������\n");
    printf("��                                                                                                                  ��\n");
    printf("�� ��    �� ����     ��      �� ������        ����   ��  ��  �� ������ ������   ����   ��      �� ��\n");
    printf("�� ��    �� ��    ��   ���  ���     ��          ��      �� ��  ��  ��     ��         ��     ��      �� ��      �� ��\n");
    printf("�� ��    �� ��      �� ��  ��  ��     ��          ��         ��  ��  ��     ��         ��     ��         ��      �� ��\n");
    printf("�� ����� ��      �� ��      ��     ��            ����   ��  ��  ��     ��         ��     ��         ������ ��\n");
    printf("�� ��    �� ��      �� ��      ��     ��                  �� ��  ��  ��     ��         ��     ��         ��      �� ��\n");
    printf("�� ��    �� ��    ��   ��      ��     ��          ��      �� ��  ��  ��     ��         ��     ��      �� ��      �� ��\n");
    printf("�� ��    �� ����     ��      �� ������        ����     ��  ��   ������     ��       ����   ��      �� ��\n");
    printf("��                                                                                                                  ��\n");
    printf("�� Press Enter...                                                                                    Ver : B.1.0    ��\n");
    printf("������������������������������������������������������������\n");
    while (Press_Enter == 0) {
        char c = _getch();
        if (c == 13) {
            system("cls");
            break;
        }
    }
}
