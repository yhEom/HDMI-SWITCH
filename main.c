#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

// HDMI SWITCH B.1.0

/*
조건
1. 연결된 순서 기억
2. 현재 채널의 연결이 끊기면 마지막 연결(가장 큰 순서의 연결 번호)로 재연결, 아무 연결이 없으면 1번으로
3. 입력은 8개 출력은 1개
*/

void Init(); //초기설정
void Starting_Logo_Disp(); //시작화면

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
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                                  ■\n");
    printf("■ ■    ■ ■■■     ■      ■ ■■■■■        ■■■   ■  ■  ■ ■■■■■ ■■■■■   ■■■   ■      ■ ■\n");
    printf("■ ■    ■ ■    ■   ■■  ■■     ■          ■      ■ ■  ■  ■     ■         ■     ■      ■ ■      ■ ■\n");
    printf("■ ■    ■ ■      ■ ■  ■  ■     ■          ■         ■  ■  ■     ■         ■     ■         ■      ■ ■\n");
    printf("■ ■■■■ ■      ■ ■      ■     ■            ■■■   ■  ■  ■     ■         ■     ■         ■■■■■ ■\n");
    printf("■ ■    ■ ■      ■ ■      ■     ■                  ■ ■  ■  ■     ■         ■     ■         ■      ■ ■\n");
    printf("■ ■    ■ ■    ■   ■      ■     ■          ■      ■ ■  ■  ■     ■         ■     ■      ■ ■      ■ ■\n");
    printf("■ ■    ■ ■■■     ■      ■ ■■■■■        ■■■     ■  ■   ■■■■■     ■       ■■■   ■      ■ ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■ Press Enter...                                                                                    Ver : B.1.0    ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    while (Press_Enter == 0) {
        char c = _getch();
        if (c == 13) {
            system("cls");
            break;
        }
    }
}
