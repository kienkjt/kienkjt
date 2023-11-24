#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>

using namespace std;

struct CuaHang{
	char TenCuaHang[25];
	char TenChu[20];
	double DoanhThu2017;
	int SoLuong_NV;
}; 
struct Node{
	CuaHang infor;
	Node *next;
};
typedef Node *tro;

// Nhap thong tin cho mo6t cua hang

void NhapCuaHang(CuaHang &ch){
	cout << "Nhap ten cua hang :";
	fflush(stdin);
	cin >> ch.TenCuaHang;
	cout << "Nhap ten chu cua hang :";
	fflush(stdin);
	cin >> ch.TenChu;
	cout << "Nhap doanh thu 2017 :";
	fflush(stdin);
	cin >> ch.DoanhThu2017;
	cout << "Nhap so luong Nhan vien :";
	fflush(stdin);
	cin >> ch.SoLuong_NV;
}
// Nhap danh sach Cua hang
void NhapDS(tro &L){
	tro P , Q;
	CuaHang x;
	int d = 0;
	L = NULL;
	do{
		NhapCuaHang(x);
		P = new Node;
		P->infor = x;
		P->next = NULL;	
		if(L == NULL){
			L = P;
		}else
			Q->next = P;
		Q = P;
		d++;	
	}while(d < 5);
}
void HienThi(tro &L){
	cout << setw(5) << "STT"; 
	cout << setw(15) << "Ten Cua Hang";
    cout << setw(25) << "Chu Cua Hang";
    cout << setw(30) << "Doanh Thu 2017";
    cout << setw(35) << "So Luong NV" << endl;
    if(L == NULL){
    	cout << " Danh sach rong";
    	return ;
	}
	tro Q = L;
	int i = 0;
	while(Q != NULL){
		CuaHang x = Q->infor;
		cout << setw(5) << 1 + i; 
		cout << setw(15) << x.TenCuaHang;
    	cout << setw(25) << x.TenChu;
    	cout << setw(30) << x.DoanhThu2017;
    	cout << setw(35) << x.SoLuong_NV << endl;
    	Q = Q->next;
        i++;
	}
}
// Ham de tim va hien thi cac cua hang co doanh thu tren 100 trieu
void DoanhThuTren100(tro &L){
    if(L == NULL){
        cout << "Danh sach rong" << endl;
        return;
    }
    tro Q = L;
    int dem = 0;
    while(Q != NULL){
    
        CuaHang X = Q->infor;
        if(X.DoanhThu2017 > 100){
            dem++;
            if(dem == 1){
                cout << setw(5) << "STT"; 
                cout << setw(15) << "Ten Cua Hang";
                cout << setw(25) << "Chu Cua Hang";
                cout << setw(30) << "Doanh Thu 2017";
                cout << setw(35) << "So Luong NV" << endl;
            }
            cout << setw(5) << dem; 
            cout << setw(15) << X.TenCuaHang;
            cout << setw(25) << X.TenChu;
            cout << setw(30) << X.DoanhThu2017;
            cout << setw(35) << X.SoLuong_NV << endl;
        }
        Q = Q->next;
    }
    if(dem == 0){
        cout << "Khong co cua hang nao co doanh thu tren 100 trieu" << endl;
    }
}

tro timvtk(int &vt , tro L){
	int dem = 0;
	tro Q ;
	Q = L;
	if(vt == 0){
		return L;
	}else{
		while(Q->next != NULL && dem != vt){
			Q = Q->next;
			dem ++;
		}
		return Q;
	}
}
void Chen(tro L , tro Q , CuaHang x){
	tro P;
	P = new Node;
	P->infor = x;
	P->next = Q->next;
	Q->next = P;
} 
void ChenViTri5(tro &L){
	cout << "Nhap cua hang can chen " << endl;
	CuaHang x;
	NhapCuaHang(x);
	tro Q = L;
	int d = 1;
	while(Q != NULL && d < 4){
		Q = Q->next;
		d++;
	}

	if (Q == NULL){
		cout << "Vi tri khong thich hop";
	}
	Chen(L , Q , x);
	cout << "Danh sach vua bo sung " << endl; 
	HienThi(L);
}
int main(){
	tro L;
	CuaHang x;
	NhapDS(L);
	HienThi(L);
	cout << "Cua hang co doanh thu tren 100 trieu " << endl;
	DoanhThuTren100(L);
	ChenViTri5(L);
}
