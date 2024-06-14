#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;


//CLASS SAN PHAM
class SANPHAM{
	private:
	   string sp_id;
	   string sp_name;
	   double sp_price;
	   int sp_nums;
	   string sp_date;
	   string sp_donvi;
	public:
		// Constructor san pham
		SANPHAM(){}
		SANPHAM(string sp_id, string sp_name, double sp_price, int sp_nums, string sp_date, string sp_donvi){
			this->sp_id= sp_id; 
			this->sp_name= sp_name;
			this->sp_price= sp_price;
			this->sp_nums= sp_nums;
			this->sp_date= sp_date;
			this->sp_donvi= sp_donvi;
		}
		//Cac ham setter,getter
		void setsp_id(string sp_id){
			this->sp_id= sp_id;
		}
		string getsp_id(){
			return sp_id;
		}
		void setsp_name(string sp_name){
			this->sp_name= sp_name;
		}
		string getsp_name(){
			return sp_name;
		}
		
		void setsp_price(double sp_price){
			this->sp_price= sp_price;
		}
		double getsp_price(){
			return sp_price;
		}
		void setsp_nums(int sp_nums){
			this->sp_nums= sp_nums;
		}
		int getsp_nums(){
			return sp_nums;
		}
		void setsp_date(string sp_date){
			this->sp_date= sp_date;
		}
		string getsp_date(){
			return sp_date;
		}	
		void setsp_donvi(string sp_donvi) {
			this->sp_donvi= sp_donvi;
		}
		string getsp_donvi(){
			return sp_donvi;
		}
		void display() {
			cout << "ID: " << sp_id << endl;
			cout << "Name: " << sp_name << endl;
			cout << "Price: " << sp_price << endl;
			cout << "Nums: " << sp_nums << endl;
			cout << "Date: " << sp_date <<endl;
			cout << "Donvi: " << sp_donvi << endl;
		}
};

//CLASS KHACH HANG
class KHACHHANG{
	private:
	   string kh_name;
	   long kh_sdt;
	public: 
	   // Constructor khach hang
	   KHACHHANG(){}
   	   KHACHHANG(string kh_name, long kh_sdt){
		   this->kh_name= kh_name;
		   this->kh_sdt= kh_sdt;
	   }
	   // Cac ham setter,getter
	   void setkh_name(string kh_name){
		   this -> kh_name= kh_name;
	   }
	   string getkh_name(){
		   return kh_name;
	   }
	   void setkh_sdt(long kh_sdt){
		   this -> kh_sdt= kh_sdt;
	   }
	   long getkh_sdt(){
		   return kh_sdt;
	   }
};

//CLASS DATE
class DATE {
public:
    int day;
    int month;
    int year;
    // Constructor
	DATE() {}
	DATE(int day, int month, int year) {
		this->day= day;
		this->month= month;
		this->year = year;
	}
		void setday(int day){
			this->day= day;
		}
		int getday(){
			return day;
		}
		void setmonth(int month){
			this->month= month;
		}
		int getmonth(){
			return month;
		}
		void setyear(int year){
			this->year= year;
		}
		int getyear(){
			return year;
		}
};

//CLASS HOA DON
class HOADON{
	public:
		KHACHHANG _kh;
	    vector<SANPHAM> _sp;
	    int _seri;
	    int _stt;
		int sum;
		// Constructors
		HOADON(){}
		HOADON(KHACHHANG _kh, vector<SANPHAM>& _sp, int _seri, int sum){
			this -> _kh= _kh;
			this -> _sp= _sp;
			this -> _seri= _seri;
			this -> sum=sum;
		}
		// Cac ham getter,setter
		void set_kh(KHACHHANG _kh){
			this -> _kh= _kh;
		}
		KHACHHANG get_kh(){
			return _kh;
		}
		void set_sp(vector<SANPHAM>& _sp){
			this -> _sp= _sp;
		}
		vector<SANPHAM> get_sp(){
			return _sp;
		}
		void set_seri(int _seri){
			this -> _seri= _seri;
		}
		int get_seri(){
			return _seri;
		}
		void set_sum(int sum) {
			this -> sum = sum;
		}
		int get_sum() {
			return sum;
		}
		//Phuong thuc them san pham
		void themsanpham(SANPHAM& product){
			_sp.push_back(product);
		}
		//
		void NhapHoaDon(HOADON &m,int &i, vector<SANPHAM> &kho, KHACHHANG &k, DATE &d) {
            char c = 'N';
            do {
               cout <<"\nXin moi nhap san pham (ID): " << endl;
		       string text;
		       getline(cin, text);
		       SANPHAM product;
		       bool found = false;
		       for (int i = 0; i < 51; i++) {
			       if (text == kho[i].getsp_id()){
				       product = kho[i];
				       found = true;
				       break;
			        }
		    }
		        if (!found) {
			    cout << "San pham khong ton tai!" << endl;
			    continue;
		    }
		    cout << "\nSo luong: ";
		    int a;
		    cin >> a;
		    cin.ignore(1);
		    if (a<=0) {
			    cout << "So luong khong hop le!" << endl;
			    continue;
		    }
                product.setsp_nums(a);
				for (int i = 0; i < 52; i++) {
					if (product.getsp_id() == kho[i].getsp_id()) {
						kho[i].setsp_nums(kho[i].getsp_nums() - a);
						break;
					}
				}
		        double cnt = 0;
		        cnt += product.getsp_nums()*product.getsp_price();
		        m.set_sum(cnt);
		        m.themsanpham(product);
		        i++;
		        cout <<"\nBan co muon tiep tuc khong? Y/N";
                c = getch();
		        cin.ignore(1);
            } while (c == 'y'||c == 'Y');
				cout <<"\nNhap thong tin khach hang";
				cout << "\nTen khach hang: ";
				string text;
				getline(cin, text);
				k.setkh_name(text);
				cout << "\nSo dien thoai: ";
				long long nums;
				cin >> nums;
				k.setkh_sdt(nums);
				cout <<"\nNhap thong tin hoa don: ";
                cout <<"\nNhap thoi gian: ";
				int dd, mm, yy;
				cin >> dd >> mm >> yy;
				d.setday(dd);
				d.setmonth(mm);
				d.setyear(yy);
        }

		    //Ham in hoa don
            void InHoaDon(HOADON m, int i, KHACHHANG k, DATE d) {
                cout << endl << endl << endl << endl;
                cout << "\n                               SUPERMARKET                          ";
                cout << "\nDia chi: So 1 Dai Co Viet, Hai Ba Trung, Ha Noi";
				cout << "\nTen khach hang: " << k.getkh_name();
				cout << "\nSo dien thoai: 0" << k.getkh_sdt();
                cout << "\nThoi gian: " << d.getday() << "/" << d.getmonth() << "/" << d.getyear();
                cout << "\nMa so hoa don: ";
                cout << "\n" << setfill('_') << setw(73) << "_" << setfill(' ');
                cout << "\n" << setw(7) << left << "MSSP" << setw(25) << left << "Ten san pham" << setw(9) << left << "Don vi" << setw(11) << left << "So luong" << setw(11) << left << "Dong gia" << setw(10) << right << "Thanh tien";
                for (int j = 0; j < i; j++) {
                    cout << "\n" << setw(7) << left << m._sp[j].getsp_id();
	                cout << setw(25) << left << m._sp[j].getsp_name();
                    cout << setw(9) << left << m._sp[j].getsp_donvi();
                    cout << setw(11) << left << m._sp[j].getsp_nums();
                    cout << setw(11) << left << m._sp[j].getsp_price();
                    cout << setw(10) << right << m._sp[j].getsp_nums()*m._sp[j].getsp_price();
                }
                cout << "\n" << setfill('_');
                cout << setw(73) << "_";
                cout << setfill(' ');
                cout << "\nTong tien:";
                cout << setw(63) << right << m.sum; 
                cout << "\n                          Hen gap lai quy khach!                     ";
				cout << endl << endl << endl << endl;
				cout << endl << endl << endl << endl;
        }

		//Phuong thuc xoa san pham
		/*void xoasanpham(int sp_id){
			for(auto it = _sp.begin(); it != _sp.end(); ++it){
				if(it->getsp_id() == sp_id){
					_sp.erase(it);
					break;
				}
			}
		}*/
};

//Đọc file csv và truyền các chỉ số tương ứng vào các thuộc tính của đối tượng
void readCSV(const string &filename, vector<SANPHAM> &products) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line;
    // Skip the header line
    getline(file, line);
    
    while (getline(file, line)) {
        stringstream ss(line);
        string name, id, date, unit, price_str, nums_str;

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, price_str, ',');
        getline(ss, nums_str, ',');
        getline(ss, date, ',');
        getline(ss, unit, ',');

        double price = stod(price_str);
        int nums = stoi(nums_str);

        SANPHAM product;
		product.setsp_name(name);
		product.setsp_id(id);
		product.setsp_date(date);
		product.setsp_donvi(unit);
		product.setsp_price(price);
		product.setsp_nums(nums);
        products.push_back(product);
    }
    
    file.close();
}

//Hàm check kho
void checkInventory(vector<SANPHAM> products) {
	string text;
	cout << "Hay nhap ID san pham can tim: ";
	getline(cin, text);
	for (int i = 0; i < 52; i++) {
		if (text == products[i].getsp_id()) {
			cout << "Thong tin san pham " << endl;
			products[i].display();
			break;
		}
	}
}

//Hàm main thực hiện chương trình.
int main(){
	vector<SANPHAM> kho;
    readCSV("mini_supermarket_products_en.csv", kho);
	int seri = 12345678;
	HOADON m;
	KHACHHANG k;
	DATE d;
	int i = 0;
	int choice;
    while (true) {
        cout << "Vui long chon mot tuy chon:" << endl;
        cout << "1. In hoa don" << endl;
        cout << "2. Kiem tra kho hang" << endl;
        cout << "3. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore(1);
        switch (choice) {
            case 1:
			    m.NhapHoaDon(m, i, kho, k, d);
                m.InHoaDon(m, i, k, d);
                break;
            case 2:
                checkInventory(kho);
                break;
            case 3:
                cout << "Thoat chuong trinh. Cam on!" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
        cout << endl;
    }

    return 0;
}


