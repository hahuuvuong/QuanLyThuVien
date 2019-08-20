#include"Header.h"
#include"Datastructure.h"
#include"Menudong.h"
#include"Myrandom.h"
#include"Checkio.h"
#include"Consolelib.h"
#include"Mylib.h"
int demSoLuongDocGia = 0;
int demSoLuongMaSach = 0;
void chucNang1();
void chucNang1_Them();
void chucNang1_Xoa();
void chucNang1_Sua();
void chucNang2();
void chucNang3(ListDS &list_ds);
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();
void chucNang11();
int main() {
	resizeConsole(923,503);
	hienThiInterface(data_interview);
	DisableMaximizeButton();
	newRand(mang_ma_sach); 
	//newRand(mang_ma_isbn);
	//list_ds.writefDS();
	//mang_ma_sach;
	//list_ds = ListDS();
	initDS(list_ds);
	list_ds = new NodeDS;
	newNodeDS(list_ds);
	//list_ds->newNodeDS();
	list_ds->readfDS();
	Init(tree);
	loadDuLieuDocGia("DocGia.txt", tree);
	list_ds->sortTenSach();
	list_ds->sortTheLoaiSach();
	list_ds->sortChucNang4();
	bool loop = true;
	while (loop) {
		hienThiFile(data_menu_chinh);
		switch (MenuDong(thuc_don_chinh, 11, locate(37, 11)))
		{
		case 1:
		{
			chucNang1();
			break;
		}
		case 2:
		{
			chucNang2();
			break;
		}
		case 3:
		{
			chucNang3(list_ds);
			break;
		}
		case 4:
		{
			chucNang4();
			break;
		}
		case 5:
		{
			chucNang5();
			break;
		}
		case 6:
		{
			chucNang6();
			break;
		}
		case 7:
		{
			chucNang7();
			break;
		}
		case 8:
		{
			chucNang8();
			break;
		}
		case 9:
		{
			chucNang9();
			break;
		}
		case 10:
		{
			chucNang10();
			break;
		}
		case 11:
		{
			chucNang11();
			clearNodeDS(list_ds);
			loop = false;
			break;
		}
		}
		system("cls");
	}
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang1() {
	clearPosition(locate(34, 11), locate((34+3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 1    |_______";
	for (int i = 11; i < 11 + 11;i++) {
		gotoxy(36, i);
		cout << "|";
	}
	bool loop = true;
	while (loop) {
		switch (MenuDong(thuc_don_chuc_nang_1,4,locate(1,11)))
		{
		case 1:
		{
			chucNang1_Them();
			break;
		}
		case 2:
		{
			chucNang1_Xoa();
			break;
		}
		case 3:
		{
			chucNang1_Sua();
			break;
		}
		case 4: {
			loop = false;
			break;
		}
		}
	}
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}

void chucNang1_Them() {
	Insert_tree(tree);
	saveDuLieuDocGia("DocGia.txt", tree);
}
void chucNang1_Xoa() {
	xoaDocGia(tree);
}
void chucNang1_Sua() {
	chinhSuaDocGia(tree);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang2() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 2    |_______";
	for (int i = 11; i < 11 + 12; i++) {
		gotoxy(36, i);
		cout << "|";
	}
	bool loop = true;
	while (loop) {
		switch (MenuDong(thuc_don_doc_gia, 3, locate(1, 11)))
		{
		case 1: {
			hienThiDocGia(tree);
			break;
		}
		case 2: {
			hienThiDocGiaTheoThuTuTen(tree);
			break;
		}
		case 3: {
			loop = false;
			break;
		}
		}
	}
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
//3.Nhap thong tin DAU SACH va danh MA SACH tu dong.
void chucNang3(ListDS &list_ds) {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 3    |_______";
	char c;
	for (int i = 0; i < MAX_LIST; i++) {
		gotoxy(37, 15);
		SetColor(YELLOW);
		cout << "           NHAP THONG TIN          ";
		gotoxy(37, 16);
		cout << "     An phim bat ky de tiep tuc    ";
		gotoxy(37, 16);
		cout << "            ESC de thoat           ";
		SetColor(WHITE);
		if (c = _getch() == ESC)
		{
			break;
		}else
		{
			gotoxy(37, 15);
			cout << "                                   ";
			gotoxy(37, 16);
			cout << "                                   ";
			list_ds->createdNodeDS();
		}
	}
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang4() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 4    |_______";
	list_ds->doChucNang4();
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang5() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 5    |_______";
	list_ds->inKyTu(15, locate(1,11));
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang6() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 6    |_______";
	muonSach(tree);
	clearPosition(locate(1, 11), locate(109, (11 + 11)));
	gotoxy(37, 16);
	cout << "           THOAT CHUC NANG         ";
	_getch();
	clearPosition(locate(10, 10), locate(100, 20));
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang7() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 7    |_______";
	traSach(tree);
	clearPosition(locate(1, 11), locate(109, (11 + 11)));
	gotoxy(37, 16);
	cout << "           THOAT CHUC NANG         ";
	_getch();
	clearPosition(locate(10, 10), locate(100, 20));
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang8() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 8    |_______";
	gotoxy(55, 11); cout << "                       MUON SACH                      ";
	gotoxy(55, 12); cout << "______________________________________________________";
	DSMuonSach(tree); _getch();
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang9() {
	clearPosition(locate(34, 11), locate((34 + 3 + 36), (11 + 11)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 9    |_______";
	docGiaMuonQuaHan(tree);
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang10() {
	clearPosition(locate(1, 11), locate(109, (11 + 12)));
	gotoxy(37, 10);
	SetColor(WHITE);
	cout << "_______|    CHUC NANG 10   |_______";
	list_ds->in10DS();
	system("cls");
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void chucNang11(){
	list_ds->writefDS();
	clearPosition(locate(1, 11), locate(109, (11 + 11)));
	gotoxy(37, 16);
	cout << "         THOAT CHUONG TRINH        ";
	_getch();
	clearPosition(locate(10, 10), locate(100, 20));
	list_ds->writefDS(); gotoxy(0, 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////