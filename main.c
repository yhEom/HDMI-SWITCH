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
void Port_Status_Trasfrom_to_Char();
void Control_Status();
void Loop();

char Ver[] = "A.1.0";
char State_Data[9];
char Disp_Nums[9] = {"NNNNNNNN"};
char State_Data_AF[9] = {"NNNNNNNN"};
char Disp_Port[9] = {""};
char Disp_Nums_Sequence[9];

int Highst_Num = 0;
int Highst_Num_Order = 0;
int Slecte_Num = 10;

int main(void) {
	Init();
	Port_Status_Trasfrom_to_Char();
    Starting_Logo_Disp();
   	system("cls");
   	Loop();
    return 0;
}

void Loop() {
	Loop_Hdmi_State();
   	while (1) {
   		int key = _getch();
   		printf("%d", key);
   		if (key == 9) {system("cls");Select_Port();break;}
   		if (key == 49) {system("cls");Control_Status(1);break;} //1
   		if (key == 50) {system("cls");Control_Status(2);break;} //2
   		if (key == 51) {system("cls");Control_Status(3);break;} //3
   		if (key == 52) {system("cls");Control_Status(4);break;} //4
   		if (key == 53) {system("cls");Control_Status(5);break;} //5
   		if (key == 54) {system("cls");Control_Status(6);break;} //6
   		if (key == 55) {system("cls");Control_Status(7);break;} //7
   		if (key == 56) {system("cls");Control_Status(8);break;} //8
   		if (key == 57) {system("cls");Help_page();break;} //9
	    if (key == 48) {exit_fn();break;} //0
	}
}

void Select_Port() {
	Select_Port_Display();
	while (1) {
		int key = _getch();
   		printf("%d", key);
	    if (key == 49) {system("cls");Select_Status(1);break;} //1
   		if (key == 50) {system("cls");Select_Status(2);break;} //2
   		if (key == 51) {system("cls");Select_Status(3);break;} //3
   		if (key == 52) {system("cls");Select_Status(4);break;} //4
   		if (key == 53) {system("cls");Select_Status(5);break;} //5
   		if (key == 54) {system("cls");Select_Status(6);break;} //6
   		if (key == 55) {system("cls");Select_Status(7);break;} //7
   		if (key == 56) {system("cls");Select_Status(8);break;} //8
   		if (key == 56) {system("cls");Loop();break;} //8
	}
}

void Select_Status(int num) {
	num  = num - 1;
	if (Disp_Nums[num] != 'N')
		Slecte_Num = num;
		Port_Status_Trasfrom_to_Char();
	Loop();
}

void Control_Status(int Num) {
	int Pre_Num = 0, i , j;
	Num = Num - 1;
	if (Disp_Nums[Num] == Disp_Nums[Slecte_Num]) {
		Slecte_Num = 10;
	}
	if (Disp_Nums[Num] != 'N') {
		Pre_Num = Disp_Nums[Num] - 48;
	    Disp_Nums[Num] = 'N';
	    for (i = 0; i < 8; i++) {
	    	if (Pre_Num < Disp_Nums[i] - 48 && Disp_Nums[i] != 'N') {
	    	   Disp_Nums[i] = Disp_Nums[i] - 1;
  	   	    }
		}
	}
	else {
		Disp_Nums[Num] = Highst_Num + 1 + 48;
	}
	Port_Status_Trasfrom_to_Char();
	Loop();
}

void Port_Status_Trasfrom_to_Char() { 
	int i;
	Highst_Num = 0;
	for (i = 0; i < 8; i++) {
 		if (Disp_Nums[i] == 'N') {Disp_Port[i] = 'X';}
	    else {Disp_Port[i] = 'O';}
        if (Highst_Num < Disp_Nums[i] - 48 && Disp_Nums[i] != 'N') {
	       Highst_Num = Disp_Nums[i] - 48;
		   Highst_Num_Order = i;
        }
	}
	if (Highst_Num != 0 && Disp_Nums[Highst_Num_Order] != 'N' && Slecte_Num == 10) {
		Disp_Port[Highst_Num_Order] = '@';
	}
	if (Slecte_Num != 10) {
		Disp_Port[Slecte_Num] = '@';
	}
	if (Disp_Nums[0] == 'N' && Disp_Nums[1] == 'N' && Disp_Nums[2] == 'N' && 
	    Disp_Nums[3] == 'N' && Disp_Nums[4] == 'N' && Disp_Nums[5] == 'N' && 
		Disp_Nums[6] == 'N' && Disp_Nums[7] == 'N')  {
		Disp_Port[0] = '@';
	}
}

void Init() {
	remove_scrollbar();
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

void Help_page() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■   1. Select the number of the port you want to connect.                                                          ■\n");
	printf("■   2. Press the selected number to connect.                                                                       ■\n");
	printf("■   3. Among the connected ports, the most recently connected port is automatically selected.                      ■\n");
	printf("■   4. After selecting the tab, select the port you want to output to and fix the output.                          ■\n");
	printf("■   5. The selected port is fixed and does not change until removed.                                               ■\n");
	printf("■   6. If you remove the selected port, it will automatically connect to the most recently connected port.         ■\n");
	printf("■   7. If no connection is made, it is automatically selected as Port No.1.                                        ■\n");
	printf("■   8. Press 0 to save state when exiting.                                                                         ■\n");
	printf("■                                                                                                                  ■\n");
	printf("■    Return : Enter                                                                                 Ver : %s    ■\n", Ver);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	while (1) {
		int key = _getch();
        if (key == 13) {
            system("cls");
            Loop();
            break;
        }
	}
}

void Select_Port_Display() {
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                                                  ■\n");
	printf("■           Out         1          2          3          4          5          6          7          8             ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                       %c          %c          %c          %c          %c          %c          %c          %c             ■\n",
	Disp_Nums[0],Disp_Nums[1],Disp_Nums[2],Disp_Nums[3],Disp_Nums[4],Disp_Nums[5],Disp_Nums[6],Disp_Nums[7]);
    printf("■                                                                                                                  ■\n");
    printf("■            O          %c          %c          %c          %c          %c          %c          %c          %c             ■\n",
	Disp_Port[0],Disp_Port[1],Disp_Port[2],Disp_Port[3],Disp_Port[4],Disp_Port[5],Disp_Port[6],Disp_Port[7]);
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■    Enter the number you want to display... , Return : Enter                                       Ver : %s    ■\n", Ver);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}


void Loop_Hdmi_State() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                                                  ■\n");
	printf("■           Out         1          2          3          4          5          6          7          8             ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                       %c          %c          %c          %c          %c          %c          %c          %c             ■\n",
	Disp_Nums[0],Disp_Nums[1],Disp_Nums[2],Disp_Nums[3],Disp_Nums[4],Disp_Nums[5],Disp_Nums[6],Disp_Nums[7]);
    printf("■                                                                                                                  ■\n");
    printf("■            O          %c          %c          %c          %c          %c          %c          %c          %c             ■\n",
	Disp_Port[0],Disp_Port[1],Disp_Port[2],Disp_Port[3],Disp_Port[4],Disp_Port[5],Disp_Port[6],Disp_Port[7]);
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■                                                                                                                  ■\n");
    printf("■    Selection mode : Tap | Help : 9 | Exit : 0                                                     Ver : %s    ■\n", Ver);
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
    printf("■    Press Enter...                                                                                 Ver : %s    ■\n", Ver);
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
