#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>

using namespace std;

struct sinhvien
{
    char masv[10];
    char hoten[22];
    float diem;
};

struct Node
{
    sinhvien infor;
    Node *next;
};

typedef Node *tro;

void nhapsv(sinhvien &sv)
{
    cout << "Nhap ma: ";
    fflush(stdin);
    cin >> sv.masv;
    cout << "Nhap ho ten: ";
    fflush(stdin);
    cin >> sv.hoten;
    cout << "Nhap diem: ";
    cin >> sv.diem;
}

void input_List(tro &L)
{
    tro P, Q;
    sinhvien X;
    int d = 0;
    L = NULL;
    do
    {
        nhapsv(X);
        P = new Node;
        P->infor = X;
        P->next = NULL;
        if (L == NULL)
            L = P;
        else
            Q->next = P;
        Q = P;
        d++;
    } while (d < 3);
}

void hienthi(tro &L)
{
    cout << setw(5) << "STT";
    cout << setw(15) << "Ma";
    cout << setw(27) << "Ho ten";
    cout << setw(33) << "Diem" << endl;
    if (L == NULL)
    {
        cout << "DS rong";
        return;
    }
    tro Q = L;
    int i = 0;
    while (Q != NULL)
    {
        sinhvien X = Q->infor;
        cout << setw(5) << 1 + i;
        cout << setw(17) << X.masv;
        cout << setw(25) << X.hoten;
        cout << setw(33) << X.diem << endl;
        Q = Q->next;
        i++;
    }
}

tro timvtk(int &vt, tro L)
{
    int dem = 0;
    tro Q;
    Q = L;
    if (vt == 0)
        return L;
    else
    {
        while (Q->next != NULL && dem != vt)
        {
            Q = Q->next;
            dem++;
        }
        return Q;
    }
}

void Chen(tro &L, tro Q, sinhvien x)
{
    tro P;
    P = new (Node);
    P->infor = x;
    P->next = Q->next;
    Q->next = P;
}

void Bosung(tro &L)
{
    sinhvien x;
    cout << "Nhap sv can bo sung" << endl;
    nhapsv(x);
    tro Q = L;
    int d = 1;
    while (d < 3 - 1)
    {
        d++;
        Q = Q->next;
    }
    Chen(L, Q, x);
    cout << "DS vua bo sung :" << endl;
    hienthi(L);
}

void xoa_sinh_vien_diem_cao_nhat(tro &L)
{
    tro Q = L;
    tro max_node = L;
    float max_score = L->infor.diem;
    while (Q->next != NULL)
    {
        if (Q->next->infor.diem > max_score)
        {
            max_score = Q->next->infor.diem;
            max_node = Q;
        }
        Q = Q->next;
    }
    cout << "Sinh vien co diem cao nhat la: " << max_node->next->infor.hoten << " voi diem: " << max_score << endl;
    tro temp = max_node->next;
    max_node->next = max_node->next->next;
    delete temp;
}

tro timkiem123(tro L) {
    tro Q = L;
    while (Q != NULL && strcmp(Q->infor.masv, "123") != 0) {
        Q = Q->next;
    }
    return Q;
}

void chentruoc123(tro L, sinhvien x) {
	//sinhvien x;
    cout << "Nhap sv can chen truoc 123" << endl;
    nhapsv(x);
    tro Q = timkiem123(L);
    if (Q == NULL) {
        cout << "ko tim thay 123.\n";
        return;
    }

    tro P = new Node;
    P->infor = x;
    P->next = Q->next;
    Q->next = P;

    
    sinhvien tg = Q->infor;
    Q->infor = P->infor;
    P->infor = tg;

    
    hienthi(L); 
}
int main()
{
    tro L;
    
    sinhvien x;
    input_List(L);
    hienthi(L);
    Bosung(L);
    xoa_sinh_vien_diem_cao_nhat(L);
    hienthi(L);
    timkiem123(L);
    chentruoc123(L, x);
    return 0;
}
