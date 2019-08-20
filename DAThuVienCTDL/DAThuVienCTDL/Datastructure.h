#pragma once
#include"Header.h"
#include"Menudong.h"
#include"Checkio.h"
#include"ngayThang.h"
#include<regex>
//2.DANH_MUC_SACH
////////////////////////////////////////////////////////////////////////////////////////////
//CODE_BELOW
////KHAI_BAO_CAU_TRUC_DU_LIEU
struct DanhMucSach {
	string ma_sach;
	unsigned int trang_thai;
	string vi_tri;
};
struct NodeDMS {
	DanhMucSach thong_tin;
	NodeDMS *next;
};
typedef struct NodeDMS *NodeDMSPtr;
////END_KHAI_BAO_CAU_TRUC_DU_LIEU
NodeDMSPtr newNodeDMS(void) {
	NodeDMSPtr p;
	p = new NodeDMS;
	p->next = NULL;
	return p;
}

//NodeDMSPtr travetoPtr(NodeDMSPtr first, int ordinal_number) {
//	NodeDMSPtr p;
//	int vitri = 1;
//	p = first;
//	while (p != NULL && vitri < ordinal_number) {
//		p = p;
//		vitri++;
//	}
//	return p;
//}
//int position(NodeDMSPtr first, NodeDMSPtr p) {
//	int vitri = 1;
//	NodeDMSPtr q;
//	q = first;
//	while (q != NULL && q != p) {
//		q = q->next;
//		vitri++;
//	}
//	if (q == NULL) return -1;
//	return vitri;
//}
void initDMS(NodeDMSPtr &first) {
	first = NULL;
}
int isEmptyDMS(NodeDMSPtr first) {
	return(first == NULL ? true : false);
}
void insertFirstDMS(NodeDMSPtr &first, DanhMucSach x) {
	NodeDMSPtr p;
	p = newNodeDMS();
	p->thong_tin = x;
	p->next = first;
	first = p;
}
void insertLastDMS(NodeDMSPtr &first, DanhMucSach x) {
	NodeDMSPtr p, q;
	q = newNodeDMS();
	p = first;
	if (isEmptyDMS(first)) {
		insertFirstDMS(first, x);
	}
	else {
		while (p->next != NULL)
		{
			p = p->next;
		}
		q->thong_tin = x;
		p->next = q;
		q->next = NULL;
	}
}
//void insertAfterDMS(NodeDMSPtr p, DanhMucSach x) {
//	NodeDMSPtr q;
//	if (p == NULL) {
//		printf("khong them duoc");
//	}
//	else {
//		q = newNodeDMS();
//		q->thong_tin = x;
//		q->next = p->next;
//		p->next = q;
//	}
//}
void insertOrderDMS(NodeDMSPtr &first, DanhMucSach x) {
	NodeDMSPtr p, q;
	for (p = first; p != NULL && p->thong_tin.ma_sach < x.ma_sach; p = p->next) q = p;
	if (p == NULL) {
		insertLastDMS(first, x);
	}else {
		q = newNodeDMS();
		q->thong_tin = x;
		q->next = p->next;
		p->next = q;
	}
}
void deleteFirstDMS(NodeDMSPtr &first) {
	NodeDMSPtr p;
	if (isEmptyDMS(first)) printf_s("Khong con SV trong DS");
	else {
		p = first;
		first = p->next;
		free(p);
	}
}
void deleteAfterDMS(NodeDMSPtr &first, DanhMucSach x) {
	NodeDMSPtr q,p;
	if (first == NULL) printf_s("Danh sach rong");
	else if ((first->next == NULL)) deleteFirstDMS(first);
	else {
		for (p = first; p != NULL && p->thong_tin.ma_sach < x.ma_sach; p = p->next) q = p;
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
void deleteAllDMSList(NodeDMSPtr &first) {
	while (first != NULL) {
		deleteFirstDMS(first);
	}
}
//void traverseDMS(NodeDMSPtr first) {
//	NodeDMSPtr p;
//	int stt = 0;
//	p = first;
//	if (p == NULL) printf_s("Khong co sinh vien trong danh sach");
//	while (p != NULL) {
//		printf_s("%5d %8s %-30d %-10s", ++stt, p->thong_tin.ma_sach, p->thong_tin.trang_thai, p->thong_tin.vi_tri);
//		p = p->next;
//	}
//}
NodeDMSPtr searchInfoDMS(NodeDMSPtr first, string x) {
	NodeDMSPtr p;
	p = first;
	while (p != NULL && p->thong_tin.ma_sach != x) {
		p = p->next;
	}
	return p;
}
void selectionDMS(NodeDMSPtr &first) {
	NodeDMSPtr p, q, pmin;
	DanhMucSach min;
	for (p = first; p->next != NULL; p = p->next) {
		min = p->thong_tin;
		pmin = p;
		for (q = p->next; q != NULL; q = q->next) {
			if (min.ma_sach > q->thong_tin.ma_sach) {
				min = q->thong_tin;
				pmin = q;
			}
		}
		pmin->thong_tin = p->thong_tin;
		p->thong_tin = min;
	}
}
//int justInNum() {
//	char temp;
//	int num = 0;
//	do {
//		temp = _getch();
//		fflush(stdin);
//		if (temp >= ZERO && temp <= NINE || temp == ENTER) {
//			num = num * 10 + (int)temp - 48;
//		}
//		else {
//			cout << "Chi nhap so, moi nhap lai!!";
//		}
//	} while (temp != ENTER);
//	return (int)temp - 48;
//}
void createDMS(NodeDMSPtr &first, string maSach) {//Ham nhap lien tiep danh sach sach cua dau sach
	DanhMucSach temp;
	temp.ma_sach = maSach;
	gotoxy(56, 13);
	cout << " Nhap Vi Tri              :";
	gotoxy(56, 14);
	cout << "_____________________________________________________";
	gotoxy(83, 13);
	temp.vi_tri = string(justInString(1,15));
	fflush(stdin);
	gotoxy(56, 15);
	cout << "Chon Trang Thai           :";
	switch (MenuDong(thuc_don_trang_thai, 3,locate(56, 17)))
	{
	case 1: {
		temp.trang_thai = 0;
		break;
	}
	case 2: {
		temp.trang_thai = 1;
		break;
	}
	case 3: {
		temp.trang_thai = 2;
		break;
	}
	}
	Normal();
	fflush(stdin);
	insertLastDMS(first, temp);
}
//void writefDMS(NodeDMSPtr first) {
//	try {
//		fstream file;
//		NodeDMSPtr temp;
//		//char  c[50];
//		temp = first;
//		file.open(data_danh_muc_sach);
//		if (!file) {
//			cout << "Khong doc duoc file";
//		}
//		else {
//			while (temp != NULL) {
//				file << "\n";
//				file << temp->thong_tin.ma_sach;
//				file << "\n";
//				file << temp->thong_tin.vi_tri;
//				file << "\n";
//				file << temp->thong_tin.trang_thai;
//				temp = temp->next;
//			}
//		}
//		file.close();
//	}
//	catch (exception e) {
//		ofstream file(data_danh_muc_sach);
//		NodeDMSPtr temp;
//		temp = first;
//		if (!file) {
//			cout << "Khong doc duoc file";
//		}
//		else {
//			while (!file.eof()) {}
//			while (temp != NULL) {
//				file << "\n";
//				file << temp->thong_tin.ma_sach;
//				file << "\n";
//				file << temp->thong_tin.vi_tri;
//				file << "\n";
//				file << temp->thong_tin.trang_thai;
//				file << "\n";
//				temp = temp->next;
//			}
//		}
//		file.close();
//	}
//}
void readfDMS(NodeDMSPtr &first,int dem_deny,int dem_dms) {
	NodeDMSPtr temp;
	DanhMucSach info;
	try {
		char  c[50];
		fstream file;
		file.open(data_danh_muc_sach);
		if (!file) {
			cout << "Khong doc duoc file";
		}
		else {
			file.getline(c, 50);
			while ((!file.eof())&& (dem_dms > -1)) {
				if (dem_deny != 0) {
					file.getline(c, 50);
					file.getline(c, 50);
					file.getline(c, 50);
					dem_deny--;
					continue;
				}
				else {
					file.getline(c, 50);
					info.ma_sach = string(c);
					file.getline(c, 50);
					info.vi_tri = string(c);
					file >> info.trang_thai;
					file.getline(c, 50);
					insertLastDMS(first, info);
					dem_dms--;
				}
			}
		}
		file.close();
	}
	catch (exception e) {
		char  c[50];
		fstream file;
		file.open(data_danh_muc_sach);
		if (!file) {
			cout << "Khong doc duoc file";
		}
		else {
			file.getline(c, 50);
			while (!file.eof()) {
				if (dem_deny != 0) {
					file.getline(c, 50);
					file.getline(c, 50);
					file.getline(c, 50);
					dem_deny--;
					continue;
				}
				else if (dem_dms > -1) {
					file.getline(c, 50);
					info.ma_sach = string(c);
					file.getline(c, 50);
					info.vi_tri = string(c);
					file >> info.trang_thai;
					file.getline(c, 50);
					insertLastDMS(first, info);
					dem_dms--; break;
				}
			}
		}
		file.close();
	}
}
//END_DANH_MUC_SACH
//
//1.Dau_Sach
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CODE_BELOW
////KHAI_BAO_CAU_TRUC_DU_LIEU
struct DauSach {
	char *isbn_code;
	string ten_sach, tac_gia, nam_xuat_ban, the_loai;
	unsigned int so_trang;
	NodeDMSPtr list_dms;
	int dem_dms,dem_luot_muon_sach;
	DauSach *next_the_loai,*next_ten_sach,*next_cn4;
	int trang_thai_de_sap_xep;
};
typedef struct DauSach * DauSachPrt;

struct NodeDS {
	int index;
	DauSach *arr_ds_ptr[MAX_LIST];
	DauSachPrt sort_the_loai_sach, sort_ten_sach,sort_chuc_nang_4;

	/*NodeDS();
	~NodeDS();*/
	bool isEmptyDS();
	bool isFullDS();
	void insertDS();
	void makeNodeDS();
	void createdNodeDS();
	void delInfoDS(DauSach dauSach);
	void readfDS();
	void writefDS();
	void sortTheLoaiSach();
	void sortTenSach();
	void sortChucNang4();
	void doChucNang4();
	void resetTrangThai();
	void xulyISBN();
	string xulyDMSCode(int index);
	void readDataBase();
	void inKyTu(int leng_chuoi, locate point);
	int kiemtraTrangThai(int ma_sach);
	int searchInfoDSTheoMaSach(string ma_sach,int mode);
	void in10DS();
};
typedef NodeDS *ListDS;
////END_KHAI_BAO_CAU_TRUC_DU_LIEU
//<VARIABLE DAU SACH>
ListDS list_ds;
void initDS(ListDS &l_ds) {
	l_ds = NULL;
}
void newNodeDS(ListDS &l_ds) {
	l_ds->index = -1;
	l_ds->sort_ten_sach = NULL;
	l_ds->sort_the_loai_sach = NULL;
	l_ds->sort_chuc_nang_4 = NULL;
	for (int i = 0; i < MAX_LIST; i++) {
		l_ds->arr_ds_ptr[i] = NULL;
		l_ds->arr_ds_ptr[i] = new DauSach;
		l_ds->arr_ds_ptr[i]->isbn_code = new char[7];
		l_ds->arr_ds_ptr[i]->isbn_code[6] = '\0';
		initDMS(l_ds->arr_ds_ptr[i]->list_dms);
		l_ds->arr_ds_ptr[i]->dem_luot_muon_sach = 0;
		l_ds->arr_ds_ptr[i]->dem_dms = -1;
		l_ds->arr_ds_ptr[i]->next_ten_sach = NULL;
		l_ds->arr_ds_ptr[i]->next_the_loai = NULL;
		l_ds->arr_ds_ptr[i]->next_cn4 = NULL;
		l_ds->arr_ds_ptr[i]->trang_thai_de_sap_xep = 0;
	}
}
void clearNodeDS(ListDS &l_ds) {
	for (int i = 0; i < l_ds->index + 1; i++) {
		deleteAllDMSList(l_ds->arr_ds_ptr[i]->list_dms);
		delete l_ds->arr_ds_ptr[i];
	}
	for (int i = l_ds->index + 1; i < MAX_LIST; i++) {
		deleteAllDMSList(l_ds->arr_ds_ptr[i]->list_dms);
		delete l_ds->arr_ds_ptr[i];
	}
}
//</VARIABLE DAU SACH>

//NodeDS::NodeDS() {
//	this->index = -1;
//	this->sort_ten_sach = NULL;
//	this->sort_the_loai_sach = NULL;
//	this->sort_chuc_nang_4 = NULL;
//	for (int i = 0; i < MAX_LIST; i++) {
//		this->arr_ds_ptr[i] = NULL;
//		this->arr_ds_ptr[i] = new DauSach;
//		this->arr_ds_ptr[i]->isbn_code = new char[7];
//		this->arr_ds_ptr[i]->isbn_code[6] = '\0';
//		initDMS(this->arr_ds_ptr[i]->list_dms);
//		this->arr_ds_ptr[i]->dem_luot_muon_sach = 0;
//		this->arr_ds_ptr[i]->dem_dms = -1;
//		this->arr_ds_ptr[i]->next_ten_sach = NULL;
//		this->arr_ds_ptr[i]->next_the_loai = NULL;
//		this->arr_ds_ptr[i]->next_cn4 = NULL;
//		this->arr_ds_ptr[i]->trang_thai_de_sap_xep = 0;
//	}
//}
//NodeDS::~NodeDS() {
//	for (int i = 0; i < this->index + 1 ; i++) {
//		deleteAllDMSList(this->arr_ds_ptr[i]->list_dms);
//		delete this->arr_ds_ptr[i];
//	}
//	for (int i = this->index + 1; i < MAX_LIST ; i++) {
//		deleteAllDMSList(this->arr_ds_ptr[i]->list_dms);
//		delete this->arr_ds_ptr[i];
//	}
//}
//ListDS initArrPointer(void) {
//	ListDS list_ds;
//	list_ds.index = -1;
//	for (int i = 0; i < MAX_LIST; i++) {
//		list_ds.arr_ds_ptr[i] = new DauSach;
//		list_ds.arr_ds_ptr[i]->list_dms = newNodeDMS();
//	}
//	return list_ds;
//}
////Ham test
bool NodeDS::isEmptyDS() {
	if (this->index == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool NodeDS::isFullDS() {
	if (this->index == MAX_LIST - 1) {
		return true;
	}
	else {
		return false;
	}
}
////Ham tao
void NodeDS::makeNodeDS() {
	clearPosition(locate(37-8, 11), locate((37 + 35+2), (11 + 11)));
	this->index++;
	gotoxy(1, 11);
	cout << "_____________________Nhap Dau Sach____________________";
	gotoxy(1, 13);
	cout << " Nhap Ten Sach             :";
	gotoxy(1, 14);
	cout << "______________________________________________________";
	gotoxy(1, 15);
	cout << " Nhap Ten Tac Gia          :";
	gotoxy(1, 16);
	cout << "______________________________________________________";
	gotoxy(1, 17);
	cout << " Nhap The Loai Sach        :";
	gotoxy(1, 18);
	cout << "______________________________________________________";
	gotoxy(1, 19);
	cout << " Nhap So Trang Sach        :";
	gotoxy(1, 20);
	cout << "______________________________________________________";
	gotoxy(1, 21);
	cout << " Nhap Nam Xuat Ban Sach    :";
	for (int i = 11; i < 11 + 12; i++) {
		gotoxy(55, i);
		cout << "|";
	}
	gotoxy(29, 13); this->arr_ds_ptr[this->index]->ten_sach = insertName(50,locate(29, 13));
	gotoxy(29, 15); this->arr_ds_ptr[this->index]->tac_gia = insertName(50,locate(29, 15));
	gotoxy(29, 17); this->arr_ds_ptr[this->index]->the_loai = insertName(50,locate(29, 17));
	gotoxy(29, 19); this->arr_ds_ptr[this->index]->so_trang = insertNum_i(4, locate(29, 19));//fflush(stdin);
	gotoxy(29, 21); this->arr_ds_ptr[this->index]->nam_xuat_ban = insertNum_s(4,locate(29, 21));
	gotoxy(56, 11);
	cout << "_____________Nhap Danh Muc Sach______________________";
	this->xulyISBN();
	string temp = "";
	while (char c = _getch() != ESC) {
		this->arr_ds_ptr[this->index]->dem_dms++;
		gotoxy(56, 16);
		SetColor(YELLOW);
		cout << "           Enter de tiep tuc/ESC de thoat..          ";
		SetColor(WHITE);
		gotoxy(56, 16);
		cout << "                                                     ";
		//temp = xulyDMSCode(this->index);
		temp.append((this->arr_ds_ptr[this->index]->isbn_code));
		temp.append(convertInt2Char(mang_ma_sach[this->arr_ds_ptr[this->index]->dem_dms]));
		/*strcat_s(temp, convertInt2Char(mang_ma_sach[this->arr_ds_ptr[this->index]->dem_dms]));
		strcat_s(temp, (this->arr_ds_ptr[this->index]->isbn_code));*/
		createDMS(this->arr_ds_ptr[this->index]->list_dms,temp);
		clearPosition(locate(56, 12), locate(109, 22));
	}
	gotoxy(10, 20);
	SetColor(GREEN);
	cout << "|BAM BAT KY NUT DE THOAT CHUC NANG !!      ";
	SetColor(WHITE);
	_getch();
	gotoxy(10, 20);
	cout << "                                           ";
	clearPosition(locate(10, 10), locate(100, 20));
}
void NodeDS::insertDS() {
	if (this->isFullDS()) {
		gotoxy(37, 16);
		SetBGColor(RED);
		//cout << "     An phim bat ky de tiep tuc    ";
		cout << "          Khong Them Duoc          ";
		SetBGColor(BLACK);
		_getch();
		gotoxy(37, 16);
		cout << "                                   ";
	}
	else {
		this->makeNodeDS();
	}
}
//convertInt2String(mang_ma_sach[i])
void NodeDS::createdNodeDS() {
	this->insertDS();
}
////Ham xuat nhap file
void NodeDS::writefDS() {
	try{
		fstream fileDS;
		fstream fileDMS;
		NodeDMSPtr temp;
		fileDS.open("info_dau_sach.txt");
		fileDMS.open(data_danh_muc_sach);
		if (!fileDS&&!fileDMS) {
			cout << "Khong doc duoc file";
		}
		else {
			for (int i = 0; i <= this->index; i++) {
				fileDS << "\n";
				fileDS << i;
				fileDS << "\n";
				for (int j = 0; j <6; j++) {
					fileDS << this->arr_ds_ptr[i]->isbn_code[j];
				}
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->ten_sach;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->tac_gia;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->so_trang;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->the_loai;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->nam_xuat_ban;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->dem_dms;
				//writefDMS(this->arr_ds_ptr[i]->list_dms);
				//char  c[50];
				temp = this->arr_ds_ptr[i]->list_dms;
				while (temp != NULL) {
					fileDMS << "\n";
					fileDMS << temp->thong_tin.ma_sach;
					fileDMS << "\n";
					fileDMS << temp->thong_tin.vi_tri;
					fileDMS << "\n";
					fileDMS << temp->thong_tin.trang_thai;
					temp = temp->next;
				}
				
			}
		}
		fileDS.close();
		fileDMS.close();
	}
	catch (exception e) {
		ofstream fileDS("info_dau_sach.txt");
		ofstream fileDMS(data_danh_muc_sach);
		NodeDMSPtr temp;
		if (!fileDS&&!fileDMS) {
			cout << "Khong doc duoc file";
		}
		else {
			for (int i = 0; i <= this->index; i++) {
				fileDS << "\n";
				fileDS << i;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->isbn_code;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->ten_sach;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->tac_gia;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->so_trang;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->the_loai;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->nam_xuat_ban;
				fileDS << "\n";
				fileDS << this->arr_ds_ptr[i]->dem_dms;
				//writefDMS(this->arr_ds_ptr[i]->list_dms);
				temp = this->arr_ds_ptr[i]->list_dms;
				while (temp != NULL) {
					fileDMS << "\n";
					fileDMS << temp->thong_tin.ma_sach;
					fileDMS << "\n";
					fileDMS << temp->thong_tin.vi_tri;
					fileDMS << "\n";
					fileDMS << temp->thong_tin.trang_thai;
					temp = temp->next;
				}
			}
		}
		fileDS.close();
	}
}
void NodeDS::readfDS() {
	
	try {
		char  c[50];
		ifstream file("info_dau_sach.txt");
		int dem_deny = 0;
		if (!file) {
			cout << "Khong doc duoc file";
		}
		else {
			int i = 0;
			file.getline(c, 50);
			while (!file.eof()) {
				this->index = i;
				file.getline(c, 50);
				file.getline(c, 50);
				for (int i = 0; i < 6; i++) {
					this->arr_ds_ptr[this->index]->isbn_code[i] = c[i];
				}
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->ten_sach = string(c);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->tac_gia = string(c);
				file >> this->arr_ds_ptr[this->index]->so_trang;
				file.getline(c, 50);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->the_loai = string(c);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->nam_xuat_ban = string(c);
				file >> this->arr_ds_ptr[this->index]->dem_dms;
				file.getline(c, 50);
				readfDMS(this->arr_ds_ptr[this->index]->list_dms,dem_deny, this->arr_ds_ptr[this->index]->dem_dms);
				dem_deny = dem_deny + this->arr_ds_ptr[this->index]->dem_dms + 1;
				i++;
			}
		}
		file.close();
	}catch (exception e) {
		char  c [50];
		fstream file;
		int dem_deny = 0;
		file.open(data_dau_sach);
		if (!file) {
			cout << "Khong doc duoc file";
		}
		else {
			int i = 0;
			file.getline(c, 50);
			while (!file.eof()) {
				this->index = i;
				file.getline(c, 50);
				file.getline(c, 50);
				for (int i = 0; i < 6; i++) {
					this->arr_ds_ptr[this->index]->isbn_code[i] = c[i];
				}
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->ten_sach = string(c);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->tac_gia = string(c);
				file >> this->arr_ds_ptr[this->index]->so_trang;
				file.getline(c, 50);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->the_loai = string(c);
				file.getline(c, 50);
				this->arr_ds_ptr[this->index]->nam_xuat_ban = string(c);
				file >> this->arr_ds_ptr[this->index]->dem_dms;
				file.getline(c, 50);
				readfDMS(this->arr_ds_ptr[this->index]->list_dms, dem_deny, this->arr_ds_ptr[this->index]->dem_dms);
				dem_deny = dem_deny + this->arr_ds_ptr[this->index]->dem_dms + 1;
				i++;
			}
		}
		file.close();
	}
}
void NodeDS::readDataBase(){
	this->readfDS();
}
////Ham duyet
void searchNodeDS(ListDS list_dau_sach, DauSach dau_sach) {

}
void travelDS(ListDS list_dau_sach){
	for (int i = 0; i < list_dau_sach->index + 1; i++) {
		cout << "\nISBN:" << list_dau_sach->arr_ds_ptr[i]->isbn_code;
		cout << "\nTen Sach:" << list_dau_sach->arr_ds_ptr[i]->ten_sach;
		cout << "\nSo Trang:" << list_dau_sach->arr_ds_ptr[i]->so_trang;
		cout << "\nTac Gia:" << list_dau_sach->arr_ds_ptr[i]->tac_gia;
		cout << "\nNam xuat ban:" << list_dau_sach->arr_ds_ptr[i]->nam_xuat_ban;
		cout << "\nThe Loai:" << list_dau_sach->arr_ds_ptr[i]->the_loai;
		cout << "\nCac Ma Sach:" << list_dau_sach->arr_ds_ptr[i]->list_dms->thong_tin.ma_sach;
		cout << "\nTrang Thai:" << list_dau_sach->arr_ds_ptr[i]->list_dms->thong_tin.trang_thai;
	}
}
////Ham sap xep
void sortInfoDS() {

}
int NodeDS::kiemtraTrangThai(int ma_sach) {// return -1 neu khong ton tai sach co ma sach da cho.
	string ma_sach_temp = convertInt2String(ma_sach);//VD:list_ds.kiemtraTrangThai(123);
	for (int i = 0; i <= this->index; i++) {
		if (this->arr_ds_ptr[i]->list_dms->thong_tin.ma_sach == ma_sach_temp) {
			return this->arr_ds_ptr[i]->list_dms->thong_tin.trang_thai;
		}
	}
	return -1;
}
//Ham xoa
void NodeDS::delInfoDS(DauSach dauSach) {
}
void NodeDS::resetTrangThai() {
	for (int i = 0; i < this->index + 1; i++) {
		this->arr_ds_ptr[i]->trang_thai_de_sap_xep = 0;
	}
}
void NodeDS::sortTheLoaiSach() {
	int index = 0;
	char * max_str_the_loai_sach/*= convertString2Char(this->arr_ds_ptr[index]->ten_sach)*/, *temp, c = SPACE;
	for (int j = 0; j < this->index + 1; j++) {
		max_str_the_loai_sach = &c;
		for (int i = 0; i < this->index + 1; i++) {
			temp = NULL;
			if (this->arr_ds_ptr[i]->trang_thai_de_sap_xep == 0) {
				temp = convertString2Char(this->arr_ds_ptr[i]->the_loai);
				if (strcmp(max_str_the_loai_sach, temp) == -1) {
					max_str_the_loai_sach = temp; index = i;
				}
			}
		}//thoat loop tim duoc min_str_the_loai;
		this->arr_ds_ptr[index]->next_the_loai = this->sort_the_loai_sach;
		this->sort_the_loai_sach = this->arr_ds_ptr[index];
		this->arr_ds_ptr[index]->trang_thai_de_sap_xep = 1;
	}
	this->resetTrangThai();
}
void NodeDS::sortTenSach() {
	int index = 0;
	char * max_str_ten_sach/*= convertString2Char(this->arr_ds_ptr[index]->ten_sach)*/, *temp,c = SPACE;
	for (int j = 0; j < this->index + 1; j++) {
		max_str_ten_sach = &c;
		for (int i = 0; i < this->index + 1; i++) {
			temp = NULL;
			if (this->arr_ds_ptr[i]->trang_thai_de_sap_xep == 0) {
				temp = convertString2Char(this->arr_ds_ptr[i]->ten_sach);
				if (strcmp(max_str_ten_sach, temp) == -1) {
					max_str_ten_sach = temp; index = i;
				}
			}
		}
		this->arr_ds_ptr[index]->next_ten_sach = this->sort_ten_sach;
		this->sort_ten_sach = this->arr_ds_ptr[index];
		this->arr_ds_ptr[index]->trang_thai_de_sap_xep = 1;
		
	}
	this->resetTrangThai();
}
void outInfoByPage4(DauSachPrt menu_list, int so_item_menu_list, int so_item_list_gioi_han, locate point) {
	int dong = 0, index = so_item_menu_list, index_temp = 0;int start_index_ = 0;
	DauSach *p_menu_list = new DauSach[MAX_LIST];
	if (MAX_LIST >= so_item_menu_list) {
		for (int i = 0; (i < so_item_list_gioi_han) && (index > 0)&&(p_menu_list !=NULL); i++) {
			p_menu_list[index_temp] = menu_list[i];
			/*temp_the_loai[index_temp] = p_menu_list->the_loai;
			temp_ten_sach[index_temp] = p_menu_list->ten_sach;
			p_menu_list = p_menu_list->next_cn4;*/
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
		//cout <<temp_the_loai[i] ;
		cout<< p_menu_list[i].the_loai;
		gotoxy(point.cot+20, point.dong + i);
		cout<< p_menu_list[i].ten_sach;
		//cout <<temp_ten_sach[i] ;
	}

	start_index--;
	HighLight();
	gotoxy(point.cot, point.dong + chon);
	//cout << temp_the_loai[chon] ;
	cout << p_menu_list[chon].the_loai;
	gotoxy(point.cot + 20, point.dong + chon);
	//cout << temp_ten_sach[chon];
	cout << p_menu_list[chon].ten_sach;
	Normal();
	clearPosition(locate(60, 11), locate(109, (11 + 11)));
	gotoxy(50, 11);
	cout << "Trang: " << count;
	for (int i = 11; i < 11 + 12; i++) {
		gotoxy(20, i);
		cout << "|";
		gotoxy(60, i);
		cout << "|";
	}
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
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot +20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					chon--;
					high_light = chon;
					HighLight();
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61,point.dong-2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong+1-2);
					cout << "________________________________________________";
					gotoxy(61, point.dong+2-2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong+3-2);
					cout << "________________________________________________";
					gotoxy(61, point.dong+4-2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong+5-2);
					cout << "________________________________________________";
					gotoxy(61, point.dong+6-2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong+7-2);
					cout << "________________________________________________";
					gotoxy(61, point.dong+8-2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong+9-2);
					cout << "________________________________________________";
					gotoxy(61, point.dong+10-2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong+11-2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
				else {
					////
					Normal();
					high_light = chon - count * so_item_list_gioi_han + 1;
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai ;
					gotoxy(point.cot+20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					chon--;
					high_light = chon - count * so_item_list_gioi_han + 1;
					HighLight();
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai ;
					gotoxy(point.cot+20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
			}
			else
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					//cout << temp[0];
					gotoxy(point.cot, point.dong);
					cout << p_menu_list[0].the_loai;
					gotoxy(point.cot+20, point.dong);
					cout << p_menu_list[0].ten_sach;
					chon = so_item_list_gioi_han - 1;
					high_light = chon;
					HighLight();
					//cout << temp[so_item_list_gioi_han - 1];
					gotoxy(point.cot, point.dong + so_item_list_gioi_han - 1);
					cout << p_menu_list[so_item_list_gioi_han - 1].the_loai ;
					gotoxy(point.cot+20, point.dong + so_item_list_gioi_han - 1);
					cout << p_menu_list[so_item_list_gioi_han - 1].ten_sach;
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
				else {
					////
					Normal();
					//cout << temp[0];
					gotoxy(point.cot, point.dong);
					cout << p_menu_list[0].the_loai;
					gotoxy(point.cot + 20, point.dong);
					cout << p_menu_list[0].ten_sach;
					
					//cout << temp[so_item_list_gioi_han - 1];
					if (so_item_list_gioi_han < so_item_menu_list - count * so_item_list_gioi_han) {
						chon = start_index_ + so_item_list_gioi_han - 1;
						high_light = chon;
						HighLight();
						gotoxy(point.cot, point.dong + so_item_list_gioi_han - 1);
						cout << p_menu_list[so_item_list_gioi_han - 1].the_loai;
						gotoxy(point.cot + 20, point.dong + so_item_list_gioi_han - 1);
						cout << p_menu_list[so_item_list_gioi_han - 1].ten_sach;

					}
					else {
						chon = start_index_ + so_item_menu_list - count * so_item_list_gioi_han;
						high_light = so_item_menu_list - count * so_item_list_gioi_han;
						HighLight();
						gotoxy(point.cot, point.dong + so_item_menu_list - count * so_item_list_gioi_han );
						cout << p_menu_list[high_light].the_loai;
						gotoxy(point.cot + 20, point.dong + so_item_menu_list - count * so_item_list_gioi_han );
						cout << p_menu_list[high_light].ten_sach;
					}
					
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
			}
			break;
		case KEY_DOWN:
			if ((high_light < so_item_list_gioi_han - 1)&&(high_light < so_item_menu_list- (count)* so_item_list_gioi_han))
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai ;
					gotoxy(point.cot +20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					chon++;
					high_light = chon;
					HighLight();
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
				else {
					Normal();
					high_light = chon - count * so_item_list_gioi_han + 1;
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					chon++;
					high_light = chon - count * so_item_list_gioi_han + 1;
					HighLight();
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}

			}
			else
			{
				if (count == 0) {
					Normal();
					high_light = chon;
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					HighLight();
					//cout << temp[high_light - so_item_list_gioi_han + 1];
					gotoxy(point.cot, point.dong);
					cout << p_menu_list[high_light - so_item_list_gioi_han + 1].the_loai;
					gotoxy(point.cot + 20, point.dong);
					cout << p_menu_list[high_light - so_item_list_gioi_han + 1].ten_sach;
					chon = chon - so_item_list_gioi_han + 1;
					high_light = chon;
					gotoxy(point.cot, point.dong);
					Normal();
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}

				}
				else {
					Normal();
					//cout << temp[high_light];
					gotoxy(point.cot, point.dong + high_light);
					cout << p_menu_list[high_light].the_loai;
					gotoxy(point.cot + 20, point.dong + high_light);
					cout << p_menu_list[high_light].ten_sach;
					HighLight();
					//cout << temp[high_light - so_item_list_gioi_han + 1];
					if (so_item_list_gioi_han < (so_item_menu_list - count * so_item_list_gioi_han)) {
						gotoxy(point.cot, point.dong);
						cout << p_menu_list[high_light - so_item_list_gioi_han + 1].the_loai;
						gotoxy(point.cot + 20, point.dong);
						cout << p_menu_list[high_light - so_item_list_gioi_han + 1].ten_sach;
						chon = start_index_;
						high_light = chon - count * so_item_list_gioi_han + 1;
					}
					else {
						gotoxy(point.cot, point.dong);
						cout << p_menu_list[high_light - (so_item_menu_list - count * so_item_list_gioi_han)].the_loai;
						gotoxy(point.cot + 20, point.dong);
						cout << p_menu_list[high_light - (so_item_menu_list - count * so_item_list_gioi_han)].ten_sach;
						chon = start_index_;
						high_light = chon - count * (so_item_menu_list - count * so_item_list_gioi_han);
					}
					//////////
					Normal();
					clearPosition(locate(60, 11), locate(109, (11 + 11)));
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(20, i);
						cout << "|";
						gotoxy(60, i);
						cout << "|";
					}
					/*p_menu_list = menu_list;
					for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
						p_menu_list = p_menu_list->next_cn4;
					}*/
					gotoxy(61, point.dong - 2);
					cout << "Ma ISBN      :" << p_menu_list[high_light].isbn_code;
					gotoxy(61, point.dong + 1 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 2 - 2);
					cout << "Ten sach     :" << p_menu_list[high_light].ten_sach;
					gotoxy(61, point.dong + 3 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 4 - 2);
					cout << "Tac gia      :" << p_menu_list[high_light].tac_gia;
					gotoxy(61, point.dong + 5 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 6 - 2);
					cout << "Nam xuat ban :" << p_menu_list[high_light].nam_xuat_ban;
					gotoxy(61, point.dong + 7 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 8 - 2);
					cout << "The loai     :" << p_menu_list[high_light].the_loai;
					gotoxy(61, point.dong + 9 - 2);
					cout << "________________________________________________";
					gotoxy(61, point.dong + 10 - 2);
					cout << "So luong     : " << p_menu_list[high_light].dem_dms;
					gotoxy(61, point.dong + 11 - 2);
					cout << "________________________________________________";
					for (int i = 11; i < 11 + 12; i++) {
						gotoxy(0, i);
						cout << "|";
						gotoxy(109, i);
						cout << "|";
					}
				}
			}
			break;
		case KEY_LEFT: {
			if (count > 0) {
				high_light = -1;
				count--;
				Normal();
				clearPosition(locate(1, 11), locate(109, (11 + 11)));
				gotoxy(1, 11); cout << "The Loai";
				gotoxy(21, 11); cout << "Ten Sach";
				gotoxy(1, 12); cout << "____________________________________________________________";
				gotoxy(50, 11);cout <<"Trang: "<< count;
				//system("cls");
				start_index_ = count * so_item_list_gioi_han - 1;
				if (start_index_ == -1) start_index_++;
				start_index = 0;
				index_temp = 0;
				chon = start_index_;
				//p_menu_list = menu_list;
				/*for (int i = 0; i < so_item_list_gioi_han; i++) {
					temp_the_loai[index_temp] = "";
					temp_ten_sach[index_temp] = "";
				}
				for (int i = 0; (i < start_index_) && (p_menu_list != NULL); i++) {
					p_menu_list = p_menu_list->next_cn4;
				}
				for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han) && (p_menu_list != NULL); i++) {
					temp_the_loai[index_temp] = p_menu_list->the_loai;
					temp_ten_sach[index_temp] = p_menu_list->ten_sach;
					index_temp++;
					p_menu_list = p_menu_list->next_cn4;
				}*/
				/*for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han); i++) {
					temp_the_loai[index_temp] = menu_list[i].the_loai;
					temp_ten_sach[index_temp] = menu_list[i].ten_sach;
					index_temp++;
				}*/
				for (int i = start_index_; i < count*so_item_list_gioi_han + so_item_list_gioi_han; i++)
				{
					p_menu_list[index_temp] = menu_list[i];
					index_temp++;
				}
				for (int i = 0; i < so_item_list_gioi_han; i++)
				{
					gotoxy(point.cot, point.dong + i - start_index);
					cout << p_menu_list[i].the_loai;
					gotoxy(point.cot + 20, point.dong + i - start_index);
					cout << p_menu_list[i].ten_sach;
				}
				HighLight();
				//cout << temp[0];
				gotoxy(point.cot, point.dong);
				cout << p_menu_list[0].the_loai;
				gotoxy(point.cot + 20, point.dong);
				cout << p_menu_list[0].ten_sach;
				Normal();
				clearPosition(locate(60, 11), locate(109, (11 + 11)));
				for (int i = 11; i < 11 + 12; i++) {
					gotoxy(20, i);
					cout << "|";
					gotoxy(60, i);
					cout << "|";
				}
			}
			break;
		}
		case KEY_RIGHT: {
			if (so_item_menu_list - count* so_item_list_gioi_han> so_item_list_gioi_han) {
				high_light = -1;
				count++;
				Normal();
				clearPosition(locate(1, 11), locate(109, (11 + 11)));
				gotoxy(1, 11); cout << "The Loai";
				gotoxy(21, 11); cout << "Ten Sach";
				gotoxy(1, 12); cout << "____________________________________________________________";
				gotoxy(50, 11);cout << "Trang: " << count;
				//system("cls");
				start_index_ = count * so_item_list_gioi_han - 1;
				start_index = 0;
				index_temp = 0;
				//p_menu_list = menu_list;
				chon = start_index_;
				/*for (int i = 0; i < so_item_list_gioi_han; i++) {
					temp_the_loai[i] = "";
					temp_ten_sach[i] = "";
				}
				for (int i = 0; (i < start_index_)&&(p_menu_list!=NULL); i++) {
					p_menu_list = p_menu_list->next_cn4;
				}
				for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han)&&(p_menu_list!=NULL); i++) {
					temp_the_loai[index_temp] = p_menu_list->the_loai;
					temp_ten_sach[index_temp] = p_menu_list->ten_sach;
					index_temp++;
					p_menu_list = p_menu_list->next_cn4;
				}*/
				/*for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han); i++) {
					temp_the_loai[index_temp] = menu_list[i].the_loai;
					temp_ten_sach[index_temp] = menu_list[i].ten_sach;
					index_temp++;
				}*/
				for (int i = start_index_; (i < count*so_item_list_gioi_han + so_item_list_gioi_han); i++) {
					p_menu_list[index_temp] = menu_list[i];
					index_temp++;
				}
				for (int i = 0; i < so_item_list_gioi_han; i++)
				{
					gotoxy(point.cot, point.dong + i - start_index);
					cout << p_menu_list[i].the_loai;
					gotoxy(point.cot +20, point.dong + i - start_index);
					cout << p_menu_list[i].ten_sach;
				}
				HighLight();
				//cout << temp[0];
				gotoxy(point.cot, point.dong);
				cout << p_menu_list[0].the_loai;
				gotoxy(point.cot +20 , point.dong);
				cout << p_menu_list[0].ten_sach;
				Normal();
				clearPosition(locate(60, 11), locate(109, (11 + 11)));
				for (int i = 11; i < 11 + 12; i++) {
					gotoxy(20, i);
					cout << "|";
					gotoxy(60, i);
					cout << "|";
				}
			}
			break;
		}
		case ESC:
			loop = false;
			break;
		}
		/*case ENTER:
			system("cls");
			Normal();
			get_return_value = chon;
			p_menu_list = menu_list;
			for (int i = 0; (i < get_return_value) && (p_menu_list != NULL); i++) {
				p_menu_list = p_menu_list->next_cn4;
			}
			cout << "\nThong tin cua sach:";
			cout << "\nMa ISBN:" << p_menu_list->isbn_code;
			cout << "\nTen sach:" << p_menu_list->ten_sach;
			cout << "\nTac gia:" << p_menu_list->tac_gia;
			cout << "\nNam xuat ban:" << p_menu_list->nam_xuat_ban;
			cout << "\nThe loai:" << p_menu_list->the_loai;
			cout << "\nSo luong: " << p_menu_list->dem_dms;
			_getch();
			cout << "\nBam phim bat ky de tiep tuc";
			break;
		}*/
	} while (loop);
}
void NodeDS::sortChucNang4() {
	DauSachPrt p_ten_sach, p_the_loai; int index = 0;
	char *a, *b;
	p_the_loai = this->sort_the_loai_sach;
	//p_ten_sach = this->sort_ten_sach;
	while (p_the_loai != NULL) {
		p_ten_sach = this->sort_ten_sach;
		a = convertString2Char(p_the_loai->the_loai);
		while (p_ten_sach != NULL) {
			b = convertString2Char(p_ten_sach->the_loai);
			if (strcmp(a, b) == 0 && p_ten_sach->trang_thai_de_sap_xep == 0) {
				p_ten_sach->next_cn4 = this->sort_chuc_nang_4;
				this->sort_chuc_nang_4 = p_ten_sach;
				p_ten_sach->trang_thai_de_sap_xep = 1;
			}
			p_ten_sach = p_ten_sach->next_ten_sach;
		}
		p_the_loai = p_the_loai->next_the_loai;
	}
	this->resetTrangThai();
}

void NodeDS::doChucNang4() {
	/*this->sortTenSach();
	this->sortTheLoaiSach();*/
	DauSachPrt cn4 = NULL;
	DauSach *menu = new DauSach[MAX_LIST];
	gotoxy(1, 11);cout << "The Loai";
	gotoxy(21, 11);cout << "Ten Sach";
	gotoxy(1, 12); cout << "____________________________________________________________";
	for (int i = 0; i < this->index+ 1; i++) {
		cn4 = this->sort_chuc_nang_4;
		while (cn4->next_cn4 != NULL && cn4->next_cn4->trang_thai_de_sap_xep == 0) {
			cn4 = cn4->next_cn4;
		}
		menu[i] = *cn4;
		cn4->trang_thai_de_sap_xep = 1;
	}
	list_ds->resetTrangThai();
	/*for (int i = 0; i < this->index + 1; i++) {
		gotoxy(1,i); cout << menu[i].ten_sach;
	}*/
	outInfoByPage4(menu, this->index + 1, 9, locate(1,13));
	delete [] menu;
	//outInfoByPage(menu, this->index + 1, 10, locate(0, 0));
}

void NodeDS::xulyISBN() {
	//for (int i = 0; i < this->index + 1; i++) {
		this->arr_ds_ptr[this->index]->isbn_code[0] = this->arr_ds_ptr[this->index]->ten_sach[0];
		this->arr_ds_ptr[this->index]->isbn_code[1] = this->arr_ds_ptr[this->index]->ten_sach[1];
		this->arr_ds_ptr[this->index]->isbn_code[2] = this->arr_ds_ptr[this->index]->tac_gia[0];
		this->arr_ds_ptr[this->index]->isbn_code[3] = this->arr_ds_ptr[this->index]->tac_gia[1];
		this->arr_ds_ptr[this->index]->isbn_code[4] = this->arr_ds_ptr[this->index]->nam_xuat_ban[2];
		this->arr_ds_ptr[this->index]->isbn_code[5] = this->arr_ds_ptr[this->index]->nam_xuat_ban[3];
	//}
}
string NodeDS::xulyDMSCode(int index) {
	string temp,temp_DMS;
	temp_DMS = convertInt2Char(mang_ma_sach[this->arr_ds_ptr[this->index]->dem_dms]);
	for (int i = 0; i < 6; i++) {
		temp[i] = this->arr_ds_ptr[index]->isbn_code[i];
	}
	for (int i = 6; i < 4+6; i++) {
		temp[i] = temp_DMS[i];
	}
	return string(temp);
}
void searchInfo(char * chuoi_nhap, DauSachPrt sort_ten_sach, int so_item_menu_list, locate point) {
	DauSachPrt p = sort_ten_sach;
	point.cot = 1;
	point.dong = 14;
	int dong = 0, index = so_item_menu_list, index_temp = 0; int get_return_value = 0;
	string temp[MAX_LIST];
	if (MAX_LIST >= so_item_menu_list){
		for (int i = 0; i < so_item_menu_list; i++) {
			temp[i] = "";
		}
		for (int i = 0; (i < so_item_menu_list) && (index > 0); i++) {
			if ((p != NULL)&&(strcmp(convertString2Char(p->ten_sach), chuoi_nhap) >= 0)){
				temp[index_temp] = p->ten_sach;
				p = p->next_ten_sach;
				index_temp++;
				index--;
			}
		}
	}
	else {
		cout << "So luong phan tu can vuot qua gioi han";
	}
	Normal();
	//////////////////////////////////////////////////////////////////////////
	int chon = 0;
	for (int i = 0; i < so_item_menu_list; i++)
	{
		gotoxy(point.cot, point.dong + i + 1);
		cout << temp[i];
	}
	HighLight();
	gotoxy(point.cot, point.dong + chon + 1);
	cout << temp[chon];
	char kytu;
	bool loop = true;
	do {
		fflush(stdin);
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case KEY_UP:
			if (chon +1 > 1)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon+1);
				cout << temp[chon];
				chon--;
				HighLight();
				gotoxy(point.cot, point.dong + chon+1);
				cout << temp[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong + 1);
				cout << temp[0];
				chon = so_item_menu_list - 1;
				HighLight();
				gotoxy(point.cot, point.dong + so_item_menu_list);
				cout << temp[so_item_menu_list - 1];
			}
			break;
		case KEY_DOWN:
			if (chon + 1 < so_item_menu_list)
			{
				Normal();
				gotoxy(point.cot, point.dong + chon+1);
				cout << temp[chon];
				chon++;
				HighLight();
				gotoxy(point.cot, point.dong + chon+1);
				cout << temp[chon];
			}
			else
			{
				Normal();
				gotoxy(point.cot, point.dong + chon+1);
				cout << temp[chon];
				HighLight();
				gotoxy(point.cot, point.dong+1);
				cout << temp[0];
				chon = chon - so_item_menu_list + 1;
				gotoxy(point.cot, point.dong + 1);
			}
			break;
		case KEY_LEFT: {
			loop = false;
			get_return_value = 0;
			break;
		}
		case KEY_RIGHT: {
			loop = false;
			get_return_value = 0;
			break;
		}
		case ESC: {
			loop = false;
			get_return_value = -1;
			break;
		}
		case ENTER:
			Normal();
			get_return_value = chon + 1;
			p = sort_ten_sach;
			NodeDMSPtr q;
			while (p != NULL) {
				if (strcmp(convertString2Char(p->ten_sach), convertString2Char(temp[get_return_value-1]))==0) {
					gotoxy(51, 13); cout << "Ma ISBN      :" << p->isbn_code;
					gotoxy(51, 14); cout << "______________________________";
					gotoxy(51, 15); cout << "Tac gia      :" << p->tac_gia;
					gotoxy(51, 16); cout << "______________________________";
					gotoxy(51, 17); cout << "Nam xuat ban :" << p->nam_xuat_ban;
					gotoxy(51, 18); cout << "______________________________";
					gotoxy(51, 19); cout << "The loai     :" << p->the_loai;
					gotoxy(51, 20); cout << "______________________________";
					q = p->list_dms;
					int i = 0;
					while (q != NULL) {
						if (q->thong_tin.trang_thai == 0) {
							SetColor(GREEN);
						}
						else if (q->thong_tin.trang_thai == 1) {
							SetColor(RED);
						}
						else if (q->thong_tin.trang_thai == 2 ) {
							SetColor(YELLOW);
						}
						gotoxy(83,13+i);
						cout << q->thong_tin.ma_sach;
						q = q->next;
						Normal();
						i++;
					}
					break;
				}
				p = p->next_ten_sach;
			}
			cout << "\n" << temp[get_return_value - 1];
			loop = false;
			break;
		}
	} while (loop);
}

void NodeDS::inKyTu(int leng_chuoi, locate point) {////duoc
	this->sortTenSach();
	const int gioi_han_list_in_ra = 7;
	char *chuoi_nhap, ky_tu_nhap;
	chuoi_nhap = new char[leng_chuoi];
	for (int i = 0; i < leng_chuoi; i++) {
		chuoi_nhap[i] = 0;
	}
	int index = 0;
	do {
		Normal();
		gotoxy(1,11);
		cout << "___Tim Kiem Sach_________________________________";
		gotoxy(1,12);
		cout << "_________________________________________________";
		gotoxy(1,13);
		cout << "Nhap Ten Sach:";
		gotoxy(1, 14);
		cout << "_________________________________________________";
		for (int i = 11; i < 11 + 12; i++) {
			gotoxy(50, i);
			cout << "|";
			gotoxy(81, i);
			cout << "|";
		}
		gotoxy(51, 11); cout << "___Thong Tin Dau Sach_________";
		gotoxy(51, 12); cout << "______________________________";
		gotoxy(82, 11); cout << "___Cac Ma Sach_____________";
		gotoxy(82, 12); cout << "___________________________";
		gotoxy(16 + index, 13);
		ky_tu_nhap = _getch();
		if (ky_tu_nhap == ESC) continue;
		chuoi_nhap[index] = ky_tu_nhap;
		cout << chuoi_nhap[index];
		searchInfo(chuoi_nhap,this->sort_ten_sach, gioi_han_list_in_ra,point);
		index++;
	} while (ky_tu_nhap != ESC && index < leng_chuoi);
}
void NodeDS::in10DS() {
	int max = 0, index_max = -1,dem = 0;
	int sl = (this->index + 1) > 10 ? 10 : (this->index + 1);
	clearPosition(locate(1, 23), locate(109, 23 + 6));
	gotoxy(1, 12); cout << "Ten sach";
	gotoxy(1, 13); cout << "____________________________________________________________________________________________________________";
	for (int j = 0; j < sl; j++) {
		max = 0, index_max = -1;
		for (int i = 0; i <= this->index; i++) {
			if ((max <= this->arr_ds_ptr[i]->dem_luot_muon_sach)&&( this->arr_ds_ptr[i]->trang_thai_de_sap_xep == 0)) {
				this->arr_ds_ptr[i]->trang_thai_de_sap_xep = 1;
				max = this->arr_ds_ptr[i]->dem_luot_muon_sach;
				index_max = i;
			}
		}
		if (index_max > -1) {
			gotoxy(1, 14+dem);
			cout << this->arr_ds_ptr[index_max-1]->ten_sach << endl; dem++;
		}
	}
	if (dem == 0) {
		gotoxy(1,14);
		cout << "Chua co sach nao duoc muon";
	}
	_getch();
	this->resetTrangThai();
}
int NodeDS::searchInfoDSTheoMaSach(string ma_sach,int mode) {
	NodeDMSPtr p = NULL;
	for (int i = 0; i < this->index + 1; i++) {
		p = this->arr_ds_ptr[i]->list_dms;
		while (p != NULL) {
			if (strcmp(convertString2Char(ma_sach), convertString2Char(p->thong_tin.ma_sach)) == 0) {
				if (mode == 0) return i;
				if (mode == 1) {//Muon sach
					/*if (p->thong_tin.trang_thai == 1) {
						cout << "Sach da co doc gia muon";
						return i;
					}*/
					if (p->thong_tin.trang_thai == 0) p->thong_tin.trang_thai = 1;
					return i;
				}
				if (mode == 2) {//Tra Sach
					if (p->thong_tin.trang_thai == 1) p->thong_tin.trang_thai = 0;
					return i;
					/*if (p->thong_tin.trang_thai == 0) {
						cout << "Sach da tra";
						return i;
					}*/
				}
				
			}
			p = p->next;
		}
	}
	return -1;
}
//END_DAU_SACH
//
//4.MUON_TRA
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CODE_BELOW
struct MuonSach {
	string maSach;
	Date ngayMuon;
	Date ngayTra;
	unsigned int trangThai;
};
typedef struct MuonSach MS;
struct nodeMS {
	MS info;
	nodeMS *left, *right;
};
typedef struct nodeMS NODE_MS;
struct listMS {
	NODE_MS *pFirst;
	NODE_MS *pLast;
};
typedef struct listMS LIST_MS;

void InitMS(listMS &l);
//END_MUON_TRA
//
//3.THE_DOC_GIA
//////////////////////////////////////////////
//CODE_BELOW
struct DocGia {
	unsigned int maThe;
	char ho[30];
	char ten[15];
	char gioiTinh[4];
	int trangThai;
	LIST_MS ms;
};
typedef struct DocGia DG;

struct nodeDG {
	DG info;
	nodeDG *left;
	nodeDG *right;
};
typedef struct nodeDG *NODE_DG;

NODE_DG tree;
void Init(NODE_DG &root) {// khoi tao
	root = NULL;
}
void InitMS(listMS &l);
void Insert_node(NODE_DG &p, DG a);// them nut vao cay
void Insert_first(listMS &l, MS x);
void clearlist(listMS &l);

struct quaHan {
	unsigned int mathe;
	string masach;
	Date ngayMuon;
	int ngayQuaHan;
};
//-----------------------------------------
void inDocGia(int x, int y, DG Object) {// in mot doc gia
	gotoxy(0, y); cout << "|"; gotoxy(109, y); cout << "|";
	gotoxy(x+1, y); cout << Object.maThe;
	strcat_s(Object.ho, " ");
	strcat_s(Object.ho, Object.ten);
	gotoxy(x + 10, y); cout <<"|"<< Object.ho;
	gotoxy(x + 60, y); cout <<"|"<< Object.gioiTinh;
	gotoxy(x + 70, y); cout << "|";
	if (Object.trangThai == 0) cout << "The bi khoa";
	else cout << "Dang hoat dong";
}
void inDocGia6(int x, int y, DG Object) {// in mot doc gia
	gotoxy(x , y+2); cout << Object.maThe;
	strcat_s(Object.ho, " ");
	strcat_s(Object.ho, Object.ten);
	chuanHoaChuoi(Object.ho);
	gotoxy(x , y+4); cout << Object.ho;
	gotoxy(x , y+6); cout << Object.gioiTinh;
	gotoxy(x , y+8);
	if (Object.trangThai == 0) cout << "The bi khoa";
	else cout << "Dang hoat dong";
}

void demDocGia(NODE_DG tree, int &sl) {
	if (tree != NULL)
	{
		sl++;
		demDocGia(tree->left, sl);
		demDocGia(tree->right, sl);
	}
}

void themMangDocGia(NODE_DG tree, DG* dg, int &sl) {
	if (tree != NULL) {
		dg[sl] = tree->info; sl++;
		themMangDocGia(tree->left, dg, sl);
		themMangDocGia(tree->right, dg, sl);
	}
}

void hienThiDocGiaTheoThuTuTen(NODE_DG tree) {
	int x = wherex() - 40;
	int y = wherey();
	system("cls");
	clearPosition(locate(1, 23), locate(109, 23 + 6));
	gotoxy(1, 24); cout << "Ma the";
	gotoxy(10, 24); cout << "|Ho va ten";
	gotoxy(60, 24); cout << "|Phai";
	gotoxy(70, 24); cout << "|Trang thai";
	gotoxy(1, 25); cout << "____________________________________________________________________________________________________________";
	int dem_sl_doc_gia = 0, j = 0;
	demDocGia(tree, dem_sl_doc_gia);
	DG *dg = NULL;
	dg = new DG[dem_sl_doc_gia];
	dem_sl_doc_gia = 0;
	themMangDocGia(tree, dg, dem_sl_doc_gia);
	gotoxy(0, 26);
	for (int q = 0; q < dem_sl_doc_gia; q++){
		for (int k = dem_sl_doc_gia - 1; k > q; k--) {
			if (strcmp(convertString2Char(string(dg[k - 1].ho) + string(dg[k - 1].ten)),convertString2Char(string(dg[k].ho) + dg[k].ten))>0){
				DG temp;
				temp = dg[k - 1];
				dg[k - 1] = dg[k];
				dg[k] = temp;
			}
		}
	}
	for (int z = 0; z < dem_sl_doc_gia; z++) {
		gotoxy(0, 26);
		inDocGia(0, 26 + j, dg[z]); j++;
	}
	delete [] dg;
}

void hienThiDocGia(NODE_DG tree) {// in danh sach doc gia
	int x = wherex() - 40;
	int y = wherey();
	clearPosition(locate(1, 23), locate(109, 23 + 6));
	gotoxy(1, 24); cout << "Ma the";
	gotoxy(10, 24); cout << "|Ho va ten";
	gotoxy(60, 24); cout << "|Phai";
	gotoxy(70, 24); cout << "|Trang thai";
	gotoxy(1, 25); cout << "____________________________________________________________________________________________________________";
	//gotoxy(x, y); cout << "Ma the";
	//gotoxy(x + 13, y); cout << "Ho va ten";
	//gotoxy(x + 33, y); cout << "Phai";
	//gotoxy(x + 38, y); cout << "Trang Thai";
	int i = 0;
	NODE_DG p = tree;
	NODE_DG Stack[STACKSIZE];
	int sp = -1;
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			/*gotoxy(0, 26 + i); cout << "|"; gotoxy(109, 26 + i); cout << "|";
			gotoxy(1, 26 + i); cout << list_ds.arr_ds_ptr[list_ds.searchInfoDSTheoMaSach(h->info.maSach, 0)]->ten_sach;
			gotoxy(50, 26 + i); cout << "|" << h->info.maSach;
			gotoxy(80, 26 + i); cout << "|"; h->info.ngayMuon.dateOut();*/
			p = Stack[sp--];
			gotoxy(0, 26);
			inDocGia(0, 26 + i, p->info);
			i++;
			p = p->right;
		}
		else break;
	} while (1);
}

void loadPhieuMuon(LIST_MS &l, int maThe) {
	fstream f;
	MS ms;
	const string file = "PhieuMuon/" + to_string(maThe) + ".txt";
	f.open(file, ios::in);
	if (!f) {
		return;
	}
	while (f.peek() != EOF)
	{
		getline(f, ms.maSach);
		f >> ms.ngayMuon.nam;
		f >> ms.ngayMuon.thang;
		f >> ms.ngayMuon.ngay;
		f >> ms.ngayTra.nam;
		f >> ms.ngayTra.thang;
		f >> ms.ngayTra.ngay;
		f >> ms.trangThai;
		string temp;
		getline(f, temp);
		Insert_first(l, ms);
	}
	f.close();
}

void loadDuLieuDocGia(const char* fileName, NODE_DG &tree) {// lay du lieu tu file vao tree
	fstream f;
	MS ms;
	f.open(fileName, ios::in);
	if (!f) {
		return;
	}
	while (f.peek() != EOF)
	{
		DG pt;
		f.read((char*)&(pt), sizeof(DG));
		InitMS(pt.ms);
		loadPhieuMuon(pt.ms, pt.maThe);
		Insert_node(tree, pt);
	}
	f.close();
}

void savePhieuMuon(MS p, int maThe) {
	fstream f;
	const string file = "PhieuMuon/" + to_string(maThe) + ".txt";
	f.open(file, ios::out | ios::app);
	if (!f) {
		return;
	}
	f << p.maSach << endl;
	f << p.ngayMuon.nam << endl;
	f << p.ngayMuon.thang << endl;
	f << p.ngayMuon.ngay << endl;
	f << p.ngayTra.nam << endl;
	f << p.ngayTra.thang << endl;
	f << p.ngayTra.ngay << endl;
	f << p.trangThai << endl;
	f.close();
}

void savePhieuTra(NODE_DG doc_gia) {
	fstream f;
	const string file = "PhieuMuon/" + to_string(doc_gia->info.maThe) + ".txt";
	char *temp = new char(file.size() + 1);
	for (int i = 0; i < file.size() + 1; i++)
		temp[i] = file[i];
	remove(temp);
	f.open(file, ios::out | ios::trunc);
	if (!f) {
		return;
	}
	NODE_MS *h;
	for (h = doc_gia->info.ms.pFirst; h != NULL; h = h->right) {
		f << h->info.maSach << endl;
		f << h->info.ngayMuon.nam << endl;
		f << h->info.ngayMuon.thang << endl;
		f << h->info.ngayMuon.ngay << endl;
		f << h->info.ngayTra.nam << endl;
		f << h->info.ngayTra.thang << endl;
		f << h->info.ngayTra.ngay << endl;
		f << h->info.trangThai << endl;
	}
	f.close();
}

void saveDuLieuDocGia(const char* fileName, NODE_DG tree)// luu tree, du lieu ve file
{
	fstream f;
	f.open(fileName, ios::out | ios::app);
	if (!f)
	{
		cout << "Khong the mo file";
		return;
	}
	NODE_DG p = tree;
	NODE_DG Stack[STACKSIZE];
	int sp = -1;
	while (p != NULL) {
		f.write((char*)&p->info, sizeof(DG));
		if (p->right != NULL)
			Stack[++sp] = p->right;
		if (p->left != NULL) {
			p = p->left;
		}
		else if (sp == -1)
			break;
		else
			p = Stack[sp--];
	}
	f.close();
}

int Check_MADG(NODE_DG t, unsigned int MADG)// ham kiem tra ma doc gia trung
{
	if (t == NULL) {
		return FALSE;
	}
	else if (t->info.maThe == MADG)
	{
		return TRUE;
	}
	else if (MADG < t->info.maThe)
	{
		return Check_MADG(t->left, MADG);
	}
	else
	{
		return Check_MADG(t->right, MADG);
	}
}
unsigned int Random()
{
	srand(time(0));
	unsigned int x;
	x = rand() % 1000 + 1;
	return x;
}

int Random_MADG(NODE_DG t)
{
	int temp;
	do
	{
		temp = Random();
	} while (Check_MADG(t, temp));  // check trung , neu trung thi random lai
	return temp;
}
void Insert_node(NODE_DG &p, DG a) {// them nut vao cay
	if (p == NULL) {
		p = new nodeDG;
		p->info = a;
		p->left = NULL;
		p->right = NULL;
	}
	if (a.maThe < p->info.maThe)
		Insert_node(p->left, a);
	else if (a.maThe > p->info.maThe)
		Insert_node(p->right, a);
}

NODE_DG New_node(void) {
	NODE_DG p;
	p = new nodeDG;
	return(p);
}
NODE_DG SearchDG(NODE_DG root, int x) {// ham tim kiem theo ma the
	NODE_DG p;
	p = root;
	while (p != NULL && p->info.maThe != x) {
		if (x < p->info.maThe)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

void nhapDocGia(DG &dg) {// nhap mot doc gia
	fflush(stdin);
	Normal();
	gotoxy(37, 11);
	cout << "______Them Doc Gia______________________________________________________";
	gotoxy(37, 13);
	cout << "Nhap Ho        :";
	gotoxy(37, 14);
	cout << "________________________________________________________________________";
	gotoxy(37, 15);
	cout << "Nhap Ten       :";
	gotoxy(37, 16);
	cout << "________________________________________________________________________";
	gotoxy(37, 17);
	cout << "Chon Trang Thai:";
	gotoxy(37, 20);
	cout << "________________________________________________________________________";
	char m[4] = "NAM", fm[4] = "NU";
	gotoxy(37+17, 13); gets_s(dg.ho);
	gotoxy(37+17, 15); gets_s(dg.ten);
	switch (MenuDong(thuc_don_chon_gioi_tinh, 2, locate((37), 18)))
	{
	case 1: {
		for (int i = 0; i < 4; i++) {
			dg.gioiTinh[i] = m[i];
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 4; i++) {
			dg.gioiTinh[i] = fm[i];
		}
		break;
	}
	}
	
	Normal();
	gotoxy(37, 21);
	cout << "Da nhap xong 1 doc gia!!"; _getch();
	chuanHoaChuoi(dg.ho);
	chuanHoaChuoi(dg.ten);
	gotoxy(37, 21);
	cout << "                        ";
	clearPosition(locate(37, 11), locate((109), (11 + 11)));
}

void Insert_tree(NODE_DG &root) {// CHUC NANG THEM DOC GIA
	DG dg;
	nhapDocGia(dg);
	dg.maThe = Random_MADG(root);
	dg.trangThai = 1;
	InitMS(dg.ms);
	Insert_node(root, dg);
}
NODE_DG ptr;
void remove_case_3(NODE_DG &root) {
	if (root->left != NULL)
		remove_case_3(root->left);
	else {
		ptr->info.maThe = root->info.maThe;
		ptr->info = root->info; // chep noi dung root sang tree, de free(tree);
		ptr = root;
		root = ptr->right;
	}
}
void remove(int x, NODE_DG &p) {// ham xoa 1 nut khoi cay
	if (p == NULL)
		cout << "khong tim thay";
	else if (x < p->info.maThe)
		remove(x, p->left);
	else if (x > p->info.maThe)
		remove(x, p->right);
	else {//p->info.mathe=x
		ptr = p;
		if (ptr->right == NULL)
			p = ptr->left; // p la nut la hoac la nut co cay con ben trai
		else if (ptr->left == NULL)
			p = ptr->right; // p la nut co cay con ben phai
		else remove_case_3(ptr->right);
		delete ptr;
	}
}
void xoaDocGia(NODE_DG &tree) {// CHUC NANG XOA DOC GIA
	hienThiDocGia(tree);
	int x = wherex();
	int y = wherey();
	int temp;
l:	gotoxy(0, y + 1); cout << "Nhap ma the muon xoa:";
	cin >> temp;
	fflush(stdin);
	NODE_DG p = SearchDG(tree, temp);
	if (p == NULL) {
		gotoxy(0, y + 1); cout << "                             ";
		gotoxy(0, y + 1); cout << "Ma the khong ton tai";
		gotoxy(0, y + 1); cout << "                             ";
		goto l;
	}
	else
	{
		gotoxy(0, y + 1); cout << "                             ";
		char s[5];
		gotoxy(0, y + 1); cout << "Ban co chac muon xoa ? Y/N:";
		cin >> s;
		_strupr_s(s);
		gotoxy(0, y + 1); cout << "                             ";
		if (!strcmp(s, "Y")) {
			const string file = "PhieuMuon/" + to_string(temp) + ".txt";
			char *q = new char(file.size() + 1);
			for (int i = 0; i < file.size() + 1; i++)
				q[i] = file[i];// xoa file masach.txt
			remove(q);

			clearlist(p->info.ms);
			remove(temp, tree);
			saveDuLieuDocGia("temp.txt", tree);
			remove("DocGia.txt");
			rename("temp.txt", "DocGia.txt");
			gotoxy(0, y + 1); cout << "Xoa thanh cong!";
		}
		else {
			gotoxy(0, y + 1); cout << "Huy xoa doc gia!";
			_getch();
			goto l;
		}
	}
}

void chinhSuaDocGia(NODE_DG &tree) {
	hienThiDocGia(tree);
	int x = wherex();
	int y = wherey();
	int temp;
l:	gotoxy(0, y + 1); cout << "Nhap ma the muon chinh sua:";
	cin >> temp;
	cin.ignore();
	NODE_DG p = SearchDG(tree, temp);
	if (p == NULL) {
		gotoxy(0, y + 1); cout << "                             ";
		gotoxy(0, y + 1); cout << "Ma the khong ton tai";
		gotoxy(0, y + 1); cout << "                             ";
		goto l;
	}
	else {
		DG dg;
		nhapDocGia(dg);
		dg.maThe = temp;
		dg.trangThai = p->info.trangThai;
		remove(temp, tree);
		Insert_node(tree, dg);
		saveDuLieuDocGia("temp.txt", tree);
		remove("DocGia.txt");
		rename("temp.txt", "DocGia.txt");
	}
}

//END_THE_DOC_GIA
//END_THE_DOC_GIA
////////////////////////
void InitMS(listMS &l) {
	l.pFirst = l.pLast = NULL;
}

void Insert_first(listMS &l, MS x) {
	NODE_MS *p;
	p = new NODE_MS;
	p->left = NULL; p->right = l.pFirst;
	p->info = x;
	if (l.pFirst == NULL) {// truong hop danh sach rong
		l.pLast = p;
	}
	else { // tao lien ket giua p va First
		l.pFirst->left = p;
	}
	l.pFirst = p;
}

void Delete_first(listMS &l) {
	NODE_MS *p;
	if (l.pFirst == NULL)
		cout << "Danh sach rong!";
	else
	{
		p = l.pFirst;
		if (l.pFirst->right == NULL)
			l.pFirst = NULL;
		else
		{
			l.pFirst = p->right;
			l.pFirst->left = NULL;
		}
		free(p);
	}
}

void Delete_node(listMS &l, NODE_MS *p) {
	NODE_MS *q, *r;
	if (p == NULL)
		cout << "Nut khong ton tai!";
	else
	{
		if (l.pFirst == NULL)
		{
			cout << "Danh sach rong";
		}
		else
		{
			if (p == l.pFirst)
				Delete_first(l);
			else
			{
				q = p->left;
				r = p->right;
				r->left = q;
				q->right = r;
				free(p);
			}
		}
	}
}

void clearlist(listMS &l) { // XÓA NODE MS
	while (l.pFirst != NULL )
		Delete_first(l);
}

int tongSachMuon(listMS &l) {
	int soSachMuon = 0;
	for (NODE_MS *p = l.pFirst; p != NULL; p = p->right) {
		if (p->info.trangThai == 0)
			soSachMuon++;
	}
	return soSachMuon;
}

void inPhieuMuon(listMS l) {
	for (NODE_MS *p = l.pFirst; p != NULL; p = p->right) {
		cout << p->info.maSach << endl;
		cout << p->info.ngayMuon.ngay << "/" << p->info.ngayMuon.thang << "/" << p->info.ngayMuon.nam << endl;
	}
}
int checkQuaHan(listMS ms) {
	Date currentTime;
	getTimeSystem(currentTime);
	for (NODE_MS *h = ms.pFirst; h != NULL; h = h->right) {
		if (tinhNgay(currentTime, h->info.ngayMuon) > 7)
			return 0;
	}
	return 1;
}
NODE_DG DSMuonSach(NODE_DG tree) {
	int maDG;
	gotoxy(1, 11);	cout << "Nhap ma doc gia:";
	gotoxy(1, 12);	cout << "_____________________________________________________";
	for (int i = 11; i < 11 + 12; i++) {
		gotoxy(54, i);
		cout << "|";
	}
	gotoxy(18, 11);	cin >> maDG;
	
	fflush(stdin);
	NODE_DG doc_gia = SearchDG(tree, maDG);// trả về độc giả theo mã thẻ, trả về null nếu không tìm được
	if (doc_gia == NULL) {
		gotoxy(1, 13);
		cout << "Khong tim thay doc gia";
		_getch();
		gotoxy(1, 13);
		cout << "                      ";
	}
	else
	{
		if (!checkQuaHan(doc_gia->info.ms))
		{
			doc_gia->info.trangThai = 0;
		}
		else if (!checkMatSach(doc_gia->info.ms)) {
			doc_gia->info.trangThai = 0;
		}
		clearPosition( locate(1, 11), locate(109, 11));
		for (int i = 11; i < 11 + 12; i++) {
			gotoxy(54, i);
			cout << "|";
		}
		gotoxy(1, 11); cout << "                   THONG TIN THE                     ";
		gotoxy(1, 12); cout << "_____________________________________________________";
		gotoxy(1, 13); cout << "Ma the     :";
		gotoxy(1, 14); cout << "_____________________________________________________";
		gotoxy(1, 15); cout << "Ho va ten  :";
		gotoxy(1, 16); cout << "_____________________________________________________";
		gotoxy(1, 17); cout << "Phai       :";
		gotoxy(1, 18); cout << "_____________________________________________________";
		gotoxy(1, 19); cout << "Trang Thai :";
		gotoxy(1, 20); cout << "_____________________________________________________";
		inDocGia6(1+13, 11, doc_gia->info);
		LIST_MS p = doc_gia->info.ms;// gắn p vơi list Muon sach hiện tại
		MuonSach *menu_list = new MuonSach[MAX_LIST]; int i = 0;
		clearPosition(locate(1, 23), locate(109, 23+6));
		gotoxy(1, 24 ); cout << "Ten Sach";
		gotoxy(50, 24); cout << "|Ma Sach";
		gotoxy(80, 24); cout << "|Date";
		gotoxy(1, 25); cout << "____________________________________________________________________________________________________________";
		for (NODE_MS *h = p.pFirst; h != NULL; h = h->right) {//
			if(h->info.trangThai==0&& list_ds->searchInfoDSTheoMaSach(h->info.maSach, 0) !=-1){
			// GỌI HÀM INPHIEUMUON
			// CHO NAY IN RA TEN SACH, MA SACH, NGAY MUON 
			// Bo ma sach in ra ten sach
				gotoxy(0, 26 + i); cout << "|"; gotoxy(109, 26 + i); cout << "|";
				gotoxy(1, 26 + i); cout << list_ds->arr_ds_ptr[list_ds->searchInfoDSTheoMaSach(h->info.maSach, 0)]->ten_sach;
				gotoxy(50, 26 + i); cout <<"|"<< h->info.maSach;
				gotoxy(80, 26 + i); cout << "|"; h->info.ngayMuon.dateOut();
				i++;
			}
		}
	}
	return doc_gia;
}

int soLuongSachMuon(listMS ms) {
	int i = 0;
	for (NODE_MS *h = ms.pFirst; h != NULL; h = h->right) {
		if (h->info.trangThai == 0)
			i++;
	}
	return i;
}

int checkMatSach(listMS ms) {
	for (NODE_MS *h = ms.pFirst; h != NULL; h = h->right) {
		if (h->info.trangThai == 2)
			return 0;
	}
	return 1;
}

void muonSach(NODE_DG &tree) {
x:	string mSach;
	gotoxy(55, 11); cout << "                       MUON SACH                      ";
	gotoxy(55, 12); cout << "______________________________________________________";
	NODE_DG doc_gia = DSMuonSach(tree);
	if (doc_gia == NULL) {
		gotoxy(1, 11); cout << "                        ";
		goto x;
	}
	if (doc_gia->info.trangThai == 0) {
		gotoxy(1, 21); cout << "The da bi khoa!";
		_getch();
		return;
	}
	if (!checkQuaHan(doc_gia->info.ms)) {
		gotoxy(1, 21); cout << "The bi khoa vi muon qua han!";
		_getch();
		return;
	}
	if (soLuongSachMuon(doc_gia->info.ms) >= 3) {
		gotoxy(1, 21); cout << "Khong the muon them sach!";
		_getch();
		return;
	}
	if (!checkMatSach(doc_gia->info.ms)) {
		gotoxy(1, 21); cout << "The bi khoa vi lam mat sach!";
		_getch();
		return;
	}
	gotoxy(55, 13); cout << "Nhap ma sach:";cin >> mSach;fflush(stdin);
	gotoxy(55, 14); cout << "______________________________________________________";
	// tìm sách có tồn tại hoặc đã có người mượn//nhap ma sach , tim xem co ton tai hay k
	int i = -1;
	if (i = list_ds->searchInfoDSTheoMaSach(mSach, 1) != -1) {
		list_ds->arr_ds_ptr[i]->dem_luot_muon_sach++;
		MS Mas;
		Mas.maSach = mSach;
		getTimeSystem(Mas.ngayMuon);
		Mas.trangThai = 0; // đánh dấu đã có người mượn
		savePhieuMuon(Mas, doc_gia->info.maThe);
		Insert_first(doc_gia->info.ms, Mas);
		clearPosition(locate(55, 11), locate(109, 11 + 11));
		gotoxy(55, 16);
		cout << "                    Da muon xong!                     ";
		_getch();
	}
	else {
		clearPosition(locate(55, 11), locate(109, 11 + 11));
		gotoxy(55, 16);
		cout << "                    Khong ton tai                     ";
		_getch();
	}
	// đánh dấu sách đã được mượn//duyet trang thai va thay doi trang thai tu chua duoc muon thanh duoc muon
	clearPosition(locate(1, 11), locate(109, 11+11));
	gotoxy(52, 16);
	cout << "Thoat";
	_getch();
	gotoxy(52, 16);
	cout << "     ";
	//////////////////////////////////////////////////////////////////
	list_ds->writefDS();
}

void traSach(NODE_DG &tree) {
x1:	NODE_DG doc_gia = DSMuonSach(tree); string mSach; NODE_MS *h;
	if (doc_gia == NULL) {
		gotoxy(1, 11); cout << "                        ";
		goto x1;
	}
x:	gotoxy(55, 11); cout << "                        TRA SACH                      ";
	gotoxy(55, 12); cout << "______________________________________________________";
	gotoxy(55, 13); cout << "Nhap ma sach muon tra:";cin >> mSach;fflush(stdin);
	for (h = doc_gia->info.ms.pFirst; h != NULL; h = h->right) {
		if (h->info.maSach == mSach) {
			goto y;
		}
	}
	clearPosition(locate(55, 11), locate(109, (11 + 11)));
	gotoxy(55, 16); cout << "                Ma sach khong ton tai                 ";
	gotoxy(55, 16); cout << "                                                      ";
	_getch();
	goto x;
	// kiểm tra sách có tồn tại
y:	MS Mas;
	Mas.maSach = mSach;
	getTimeSystem(Mas.ngayTra);
	Mas.trangThai = 1; // đánh dấu đã có người trả
	Mas.ngayMuon = h->info.ngayMuon;
	h->info = Mas;
	clearPosition(locate(1, 11), locate(109, 11 + 11));
	gotoxy(52, 16);
	cout << "Xong";
	_getch();
	gotoxy(52, 16);
	cout << "     ";
	// đánh dấu sách đã được trả
	savePhieuTra(doc_gia);
	Delete_node(doc_gia->info.ms, h);
	if (checkQuaHan(doc_gia->info.ms)&& checkMatSach(doc_gia->info.ms))
	{
		doc_gia->info.trangThai = 1;
	}
}

void demDocGiaQuaHan(NODE_DG tree, int &sl, Date currentTime) {
	if (tree != NULL)
	{
		for (NODE_MS *h = tree->info.ms.pFirst; h != NULL; h = h->right) {
			if (h->info.trangThai == 0) {
				if (tinhNgay(currentTime, h->info.ngayMuon) > 7)
					sl++;
			}
		}
		demDocGiaQuaHan(tree->left, sl, currentTime);
		demDocGiaQuaHan(tree->right, sl, currentTime);
	}
}

void themMangDocGiaQuaHan(NODE_DG tree, int sl, Date currentTime, quaHan *arr) {
	if (tree != NULL)
	{
		for (NODE_MS *h = tree->info.ms.pFirst; h != NULL; h = h->right) {
			if (h->info.trangThai == 0) {
				if (tinhNgay(currentTime, h->info.ngayMuon) > 7)
				{
					arr[sl].masach = h->info.maSach;
					arr[sl].mathe = tree->info.maThe;
					arr[sl].ngayMuon = h->info.ngayMuon;
					arr[sl++].ngayQuaHan = tinhNgay(currentTime, h->info.ngayMuon);
				}
			}
		}
		themMangDocGiaQuaHan(tree->left, sl, currentTime, arr);
		themMangDocGiaQuaHan(tree->right, sl, currentTime, arr);
	}
}

void sapXepQuaHan(quaHan *arr, int q, int r) {
	quaHan temp;
	int i = q;
	int j = r;
	//Lấy phần tử giữa của dãy cần sắp thứ tự làm chốt
	int x = arr[(q + r) / 2].ngayQuaHan;
	do
	{  // Phân đoạn dãy con a[q],..., a[r]
		while (arr[i].ngayQuaHan > x)
			i++; //Tìm phần tử đầu tiên có trị nhỏ hơn hay bằng x
		while (arr[j].ngayQuaHan < x)
			j--;   //Tìm phần tử đầu tiên có trị lớn hơn hay bằng x

		if (i <= j)   // Hoan vi
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (q < j) 	// phần thứ nhất có từ 2 phần tử trở lên
		sapXepQuaHan(arr, q, j);
	if (i < r)   	// phần thứ ba có từ 2 phần tử trở lên
		sapXepQuaHan(arr, i, r);
}

string inTenDocGia(NODE_DG t, int MADG) {

	if (t == NULL) {
		return FALSE;
	}
	else if (t->info.maThe == MADG)
	{
		strcat_s(t->info.ho, " ");
		strcat_s(t->info.ho, t->info.ten);
		return	t->info.ho;
	}
	else if (MADG < t->info.maThe)
	{
		return inTenDocGia(t->left, MADG);
	}
	else
	{
		return inTenDocGia(t->right, MADG);
	}
}

void docGiaMuonQuaHan(NODE_DG tree) {
	Date currentTime;
	getTimeSystem(currentTime);
	int sl = 0;
	demDocGiaQuaHan(tree, sl, currentTime);
	quaHan *arrQuaHan = new quaHan[sl];
	themMangDocGiaQuaHan(tree, 0, currentTime, arrQuaHan);
	clearPosition(locate(1, 22), locate(109, 23 + 6));
	gotoxy(1, 12); cout << "Ma the";
	gotoxy(6, 12); cout << "|Ho va ten";
	gotoxy(36, 12); cout << "|Ma Sach";
	gotoxy(46, 12); cout << "|Ten Sach";
	gotoxy(80, 12); cout << "|Ngay muon";
	gotoxy(93, 12); cout << "|So ngay qua han";
	gotoxy(1, 13); cout << "____________________________________________________________________________________________________________";
	/*for (int i = 0; i < 10; i++) {
		gotoxy(1, 14+i); cout << "AAAAA";
		gotoxy(6, 14 + i); cout << "|"<<"Nguyen Le Hai Son";
		gotoxy(36, 14 + i); cout << "|"<<"MSAS981231";
		gotoxy(46, 14 + i); cout << "|"<<"Nguyen le hai son";
		gotoxy(80, 14 + i); cout << "|"<<"08/03/1998";
		gotoxy(93, 14 + i); cout << "|"<<"12";
	}*/
	sapXepQuaHan(arrQuaHan, 0, sl - 1);
	for (int i = 0; i < sl; i++) {
		gotoxy(1, 14 + i); cout << arrQuaHan[i].mathe;
		gotoxy(6, 14 + i); cout << "|" << inTenDocGia(tree,arrQuaHan[i].mathe);
		gotoxy(36, 14 + i); cout << "|" << arrQuaHan[i].masach;
		gotoxy(46, 14 + i); cout << "|" << list_ds->arr_ds_ptr[list_ds->searchInfoDSTheoMaSach(arrQuaHan[i].masach, 1)];
		gotoxy(80, 14 + i); cout << "|";arrQuaHan[i].ngayMuon.dateOut();
		gotoxy(93, 14 + i); cout << "|" << arrQuaHan[i].ngayQuaHan;
	}
	_getch();
}
//END_THE_DOC_GIA
//END_THE_DOC_GIA
////////////////////////
