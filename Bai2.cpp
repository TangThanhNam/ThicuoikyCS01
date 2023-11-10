#include <iostream>
#include <string> 
using namespace std;


// Class cua Ve may bay
class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    float giave;


public:
    Vemaybay() {}
    ~Vemaybay() {}

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
        cin.ignore(); // Dung de xoa bo dem sau khi nhap gia ve
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << ", Ngay bay: " << ngaybay << ", Gia ve: " << giave << endl;
    }

    float getgiave() {
        return giave;
    }
};

// Class cua Nguoi
class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() {}
    ~Nguoi() {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore(); //Dung de xoa bo dem sau khi nhap tuoi
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << ", Gioi tinh: " << gioitinh << ", Tuoi: " << tuoi << endl;
    }
};


// Class Hanh Khach
class Hanhkhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;

public:
    Hanhkhach() : ve(NULL), soluong(0) {}
    ~Hanhkhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        cin.ignore();
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhap thong tin ve thu " << i + 1 << ":\n";
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; ++i) {
            ve[i].Xuat();
        }
    }

    float tongtien() {
        float tong = 0;
        for (int i = 0; i < soluong; ++i) {
            tong += ve[i].getgiave();
        }
        return tong;
    }
};


// Main
int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();

    Hanhkhach* danhSach = new Hanhkhach[n];
    
    // input thong tin hanh khach
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":\n";
        danhSach[i].Nhap();
    }

    // cout thong tin hanh khach va tong tien
    for (int i = 0; i < n; ++i) {
        danhSach[i].Xuat();
        cout << "Tong tien: " << danhSach[i].tongtien() << endl;

    }
}
