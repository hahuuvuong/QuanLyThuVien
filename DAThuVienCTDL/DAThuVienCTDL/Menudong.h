#pragma once
#include"Mylib.h"

class locate {
public:
	int cot,dong;
	locate() {
		cot = 0;
		dong = 0;
	}
	locate(int x, int y) {
		cot = x;
		dong = y;
	}
	~locate(){}
};
void clearPosition(locate x, locate y) {
	SetBGColor(BLACK);
	for (int i = x.cot; i < y.cot; i++) {
		for (int j = x.dong; j < y.dong; j++) {
			gotoxy(i, j);
			cout << " ";
		}
	}
}
void Normal() {
	SetColor(WHITE);
	SetBGColor(0);
}
void HighLight() {
	SetColor(BLUE);
	SetBGColor(WHITE);
}
void outMenu(char td[][50], int so_item, locate point) {
	for (int i = 0; i < so_item; i++)
	{
		gotoxy(point.cot, point.dong + i);
		cout << td[i];
	}
}
int MenuDongUpLevel(char td[][50], int so_item, locate point) {
	Normal();
	int chon = 0;
	outMenu(td, so_item, point);
	HighLight();
	gotoxy(point.cot, point.dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case UP:
			if (chon + 1 > 1)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				chon--;
				HighLight();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong);
				cout << td[0];
				chon = so_item - 1;
				HighLight();
				gotoxy(point.cot, point.dong + so_item - 1);
				cout << td[so_item - 1];
			}
			break;
		case DOWN:
			if (chon + 1 < so_item)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				chon++;
				HighLight();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				gotoxy(point.cot, point.dong);
				HighLight();
				cout << td[chon - so_item + 1];
				chon = chon - so_item + 1;
				gotoxy(point.cot, point.dong - so_item + 1);
			}
			break;
		case ENTER:
			return chon + 1;
		}

	} while (1);
}
int MenuDong(char td[][50], int so_item,locate point) {
	Normal();
	int chon = 0;
	outMenu(td,so_item, point);
	HighLight();
	gotoxy(point.cot, point.dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case UP:
			if (chon + 1 > 1)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				chon--;
				HighLight();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong);
				cout << td[0];
				chon = so_item - 1;
				HighLight();
				gotoxy(point.cot, point.dong + so_item - 1);
				cout << td[so_item - 1];
			}
			break;
		case DOWN:
			if (chon + 1 < so_item)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				chon++;
				HighLight();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong + chon);
				cout << td[chon];
				gotoxy(point.cot, point.dong);
				HighLight();
				cout << td[chon - so_item + 1];
				chon = chon - so_item + 1;
				//gotoxy(point.cot, point.dong - so_item + 1);
				gotoxy(point.cot, point.dong);
			}
			break;
		case ENTER:
			Normal();
			gotoxy(point.cot, point.dong + chon);
			cout << td[chon];
			return chon + 1;
		}
	} while (1);
}
void outInfoByPage(string menu_list[], int so_item_menu_list, int so_item_list_gioi_han, locate point) {
	int dong = 0, index = so_item_menu_list, index_temp = 0; int get_return_value = 0; int start_index_ = 0;
	string temp[MAX_LIST];
	if (MAX_LIST >= so_item_menu_list) {/*
		for (int i = 0; i < so_item_menu_list; i++) {
			temp[i] = "";
		}*/
		for (int i = 0; (i < so_item_list_gioi_han) && (index > 0); i++) {
			temp[index_temp] = menu_list[i];
			index_temp++;
			index--;
		}
	}
	else {
		cout << "So luong phan tu can vuot qua gioi han";
	}
	Normal();
	//////////////////////////////////////////////////////////////////////////
	int chon = 0, count = 0;
	int start_index = 0;
	gotoxy(point.cot, point.dong);
	for (int i = 0; i < so_item_menu_list; i++)
	{
		gotoxy(point.cot, point.dong + i);
		cout << temp[i];
	}

	start_index--;
	HighLight();
	gotoxy(point.cot, point.dong + chon);
	cout << temp[chon];
	char kytu; int high_light = -1;
	bool loop = true;
	do {
		fflush(stdin);
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case KEY_UP:
			if (high_light > 0)
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					chon--;
					high_light = chon;
					HighLight();
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
				}
				else {
					///
					Normal();
					high_light = chon - count * so_item_list_gioi_han + 1;
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					chon--;
					high_light = chon - count * so_item_list_gioi_han + 1;
					HighLight();
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
				}
			}
			else
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					gotoxy(point.cot, point.dong);
					cout << temp[0];
					chon = so_item_list_gioi_han - 1;
					high_light = chon;
					HighLight();
					gotoxy(point.cot, point.dong + so_item_list_gioi_han - 1);
					cout << temp[so_item_list_gioi_han - 1];
				}
				else {
					///
					Normal();
					gotoxy(point.cot, point.dong);
					cout << temp[0];
					chon = start_index_ + so_item_list_gioi_han - 1;
					high_light = chon;
					HighLight();
					gotoxy(point.cot, point.dong + so_item_list_gioi_han - 1);
					cout << temp[so_item_list_gioi_han - 1];
				}
			}
			break;
		case KEY_DOWN:
			if (high_light < so_item_list_gioi_han - 1)
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					chon++;
					high_light = chon;
					HighLight();
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
				}
				else {
					Normal();
					high_light = chon - count * so_item_list_gioi_han + 1;
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					chon++;
					high_light = chon - count * so_item_list_gioi_han + 1;
					HighLight();
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
				}

			}
			else
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					gotoxy(point.cot, point.dong);
					HighLight();
					cout << temp[high_light - so_item_list_gioi_han + 1];
					chon = chon - so_item_list_gioi_han + 1;
					high_light = chon;
					gotoxy(point.cot, point.dong);

				}
				else {
					Normal();
					gotoxy(point.cot, point.dong + high_light);
					cout << temp[high_light];
					gotoxy(point.cot, point.dong);
					HighLight();
					cout << temp[high_light - so_item_list_gioi_han + 1];
					chon = start_index_;
					high_light = chon - count * so_item_list_gioi_han + 1;
				}
			}
			break;
		case KEY_LEFT: {
			if (count > 0) {
				high_light = -1;
				count--;
				Normal();
				system("cls");
				start_index_ = count * so_item_list_gioi_han - 1;
				if (start_index_ == -1) start_index_++;
				start_index = 0;
				index_temp = 0;
				chon = start_index_;
				for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han); i++) {
					temp[index_temp] = menu_list[i];
					index_temp++;
				}
				for (int i = 0; i < so_item_list_gioi_han; i++)
				{
					gotoxy(point.cot, point.dong + i - start_index);
					cout << temp[i];
				}
				HighLight();
				gotoxy(point.cot, point.dong);
				cout << temp[0];
				Normal();
			}
			break;
		}
		case KEY_RIGHT: {
			if (count*so_item_list_gioi_han < so_item_menu_list) {
				high_light = -1;
				count++;
				Normal();
				system("cls");
				start_index_ = count * so_item_list_gioi_han - 1;
				start_index = 0;
				index_temp = 0;
				chon = start_index_;
				for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han); i++) {
					temp[index_temp] = menu_list[i];
					index_temp++;
				}
				for (int i = 0; i < so_item_list_gioi_han; i++)
				{
					gotoxy(point.cot, point.dong + i - start_index);
					cout << temp[i];
				}
				HighLight();
				gotoxy(point.cot, point.dong);
				cout << temp[0];
				Normal();
			}
			break;
		}
		case ESC:
			cout << "\nout"; _getch();
			loop = false;
			break;
		}
	} while (loop);
}
//////////////////////////////////////////////////////////////////
char thuc_don_chinh[11][50] = { 
"          Nhap the doc gia         ",
"        In danh sach doc gia       ",
"      Nhap thong tin dau sach      ",
"       In danh sach dau sach       ",
"Tim thong tin sach dua vao ten sach",
"              Muon sach            ",
"              Tra sach             ",
"Liet ke danh sach doc gia dang muon",
"  In danh sach muon sach qua han   ",
"10 dau sach co luot muon nhieu nhat",
"        Thoat chuong trinh         "};
char thuc_don_chuc_nang_1[4][50] = {
"          Them the doc gia         ",
"          Xoa the doc gia          ",
"          Sua the doc gia          ",
"               Thoat               "};
char thuc_don_chon_gioi_tinh[3][50] = { 
"     Nam    ",
"     Nu     "};
char thuc_don_yes_no[3][50] = {
"     Co     ",
"    Khong   "};
char thuc_don_trang_thai[3][50] = {
"            Cho muon duoc          ",
"         Da co doc gia muon        ",
"          Sach da thanh ly         "};
char menu_chuc_nang_4[11][111] = {
"|aaaaaaaa|_______________________________________.._________________________________________________|aaaaaaaa|",
"|aaaaaaaa|              The Loai                 ||                    Ten Sach                     |aaaaaaaa|",
"|aaaaaaaa|_______________________________________||_________________________________________________|aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
"|aaaaaaaa|                                       ||                                                 |aaaaaaaa|",
};
char thuc_don_doc_gia[3][50] = {
"         In theo ma doc gia        ",
"            In theo Ten            ",
"               Thoat               " };