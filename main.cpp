#include<iostream>
#include"mylib.h"
using namespace std;
int sl = 2;
void ve_tuong_tren(int x, int y);
void ve_tuong_duoi(int x, int y);
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void them(int a[], int x);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
int main() {
	//=======
	bool gameover = false;
	int toadox[100], toadoy[100];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	//====== kiem tra tao qua
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	//tao qua
	tao_qua(xqua, yqua, toadox, toadoy);
	//=====
	int x = 50, y = 13;//dinh hinh vi tri con ran di chuyen
	int check = 2;
	while (gameover==false) {
		// xoa vi tri cu backspace
		xoa_du_lieu_cu(toadox, toadoy);
		// 0 di xuong 1 di len 2 qua phai 3 qua trai
		//thuc hien di chuyen
		//====dieu khien
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72&& check!=0) {//di len
					check = 1;
				}
				else if (kitu == 80&& check!=1) {// di xuong
					check = 0;
				}
				else if (kitu == 77&& check!=3) {//qua phai
					check = 2;
				}
				else if (kitu == 75&& check!=2) {// qua trai
					check = 3;
				}
			}
		}
		if (check == 0) {
			//di xuong
			y++;
		}
		else if (check == 1) {
			// di len
			y--;
		}
		else if (check == 2) {
			// di qua phai
			x++;
		}
		else if (check == 3) {
			//qua trai
			x--;
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		//=== kiem tra
		gameover = kt_ran(toadox, toadoy);
		Sleep(200);
	}
	_getch();
	return 0;
}
void ve_tuong_tren(int x, int y)
{
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_duoi(int x, int y)
{
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong() {
	SetColor(11);
	ve_tuong_tren(10, 1);
	ve_tuong_tren(10, 26);
	ve_tuong_duoi(10, 1);
	ve_tuong_duoi(100, 1);
	SetColor(7);
}
void khoi_tao_ran(int toadox[], int toadoy[]) {
	int x = 50, y = 13;
	for (int i = 0;i < sl;i++) {
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[]) {
	for(int i=0; i< sl; i++){
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0) {
			cout << "0";
		}
		else {
			cout << "o";
		}
	}
}
void xoa_du_lieu_cu(int toadox[], int toadoy[]) {
	for (int i = 0;i < sl;i++) {
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void xu_ly_ran(int toadox[],int toadoy[],int x, int y, int &xqua, int &yqua) {

	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == true) {
		sl++;
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	//b3 ve ran
	ve_ran(toadox, toadoy);
}
void them(int a[], int x) {
	                  
	for (int i = sl; i > 0;i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
}

bool kt_ran_cham_tuong(int x0, int y0) {
	//ran cham tuong tren
	if (y0 == 1 && (x0 >= 10 && x0<= 100)) {
		//gameover
		return true;
	}//ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100)) {
		return true; //game over
	}
     //ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100)) {
		return true; //game over
	}
	//ran cham tuong phai
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26)) {
	return true; //game over
	}
	//ran cham tuong trai
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26)) {
	return true; //game over
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[], int toadoy[]) {
	for (int i = 1;i < sl;i++) {
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i])) {
			return true;// gameover
		}
	}
	return false;
}
bool kt_ran(int toadox[], int toadoy[]) {
	bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
	bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]);
	if (kt1 == true || kt2 == true) {
		return true;
	}
	return false;
}
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]) {
	do {
		xqua = rand() % (99 - 11 + 1) + 11;
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "$";
	SetColor(7);

}
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]) {
	for (int i = 0; i < sl;i++) {
		if ((xqua == toadox[i]) && (yqua == toadoy[i])) {
			return true;
		}
	}
	return false;
}
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0) {
	if ((x0 == xqua) && (y0 == yqua)) {
		return true;
	}
	return false;
}
