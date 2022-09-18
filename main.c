#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

/*
조건
1. 연결된 순서 기억
2. 현재 채널의 연결이 끊기면 마지막 연결(가장 큰 순서의 연결 번호)로 재연결, 아무 연결이 없으면 1번으로
3. 입력은 8개 출력은 1개
*/

void Init(); //초기설정
void Starting_Logo_Disp(); //시작화면
void Loop_Hdmi_State();
void remove_scrollbar();

char Ver[] = "B.1.1";
char State_Data[9];
char Disp_Nums[9] = {"NNNNNNNN"};

int main(void) {
	Init();
    Starting_Logo_Disp();
   	system("cls");
   	Loop_Hdmi_State();
   	while (1) {
   		int key = _getch();
   		printf("%d", key);
	    if (key == 48) {
		 	exit_fn();
		 	break;
  		} 
	}
    return 0;
}

void Init() {
	remove_scrollbar();
	char State_Data_AF[9] = {"NNNNNNNN"};
	FILE *State_Save;
	if (State_Save = fopen("State_Save.txt", "r")) {
		fgets(Disp_Nums, 9, State_Save);
	}
	else {
		State_Save = fopen("State_Save.txt", "w");
		fprintf(State_Save, Disp_Nums);		
	}
	fclose(State_Save);
}

void exit_fn() {
	FILE *State_Save;
	State_Save = fopen("State_Save.txt", "w");
	fprintf(State_Save, Disp_Nums);
	exit(0);
}

void Loop_Hdmi_State() {
	int i;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                                                                  ■\n");
    printf("■            O          %c          %c          %c          %c          %c          %c          %c          %c         %c    ■\n",Disp_Nums[0],Disp_Nums[1],Disp_Nums[2],Disp_Nums[3],Disp_Nums[4],Disp_Nums[5],Disp_Nums[6],Disp_Nums[7]);
    printf("■                                                                                                                  ■\n");
    printf("■           ○         ○         ○         ○         ○         ○         ○         ○         ○             ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■    Help : 9 | Exit : 0                                                                            Ver : %s    ■\n", Ver);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
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
    printf("■ Press Enter...                                                                                    Ver : %s    ■\n", Ver);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    while (1) {
        int key = _getch();
        if (key == 13) {
            system("cls");
            break;
        }
    }
}

void remove_scrollbar() {
	 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	 CONSOLE_SCREEN_BUFFER_INFO info;
	 GetConsoleScreenBufferInfo(handle, &info);
	 COORD new_size = {info.srWindow.Right - info.srWindow.Left + 1,info.srWindow.Bottom - info.srWindow.Top + 1};
	 SetConsoleScreenBufferSize(handle, new_size);
}
