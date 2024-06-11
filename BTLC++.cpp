#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

//CLASS KHACH HANG
class KHACHHANG{
	private:
	   int kh_id;
	   string kh_name;
	   string kh_sex;
	   string kh_sdt;
	
	public: 
	   // Constructor khach hang
	   KHACHHANG(){}
   	   KHACHHANG(int kh_id, string kh_name, string kh_sex, string kh_sdt){
		   this->kh_id= kh_id;
		   this->kh_name= kh_name;
		   this->kh_sex= kh_sex;
		   this->kh_sdt= kh_sdt;
	   }
	
	   // Cac ham setter,getter
	   void setkh_id(int kh_id){
		   this -> kh_id= kh_id;
	   }
	   int getkh_id(){
		   return kh_id;
	   }
	
	   void setkh_name(string kh_name){
		   this -> kh_name= kh_name;
	   }
	   string getkh_name(){
		   return kh_name;
	   }
	
	   void setkh_sex(string kh_sex){
		   this -> kh_sex= kh_sex;
	   }
	   string getkh_sex(){
		   return kh_sex;
	   }
	
	   void setkh_sdt(string kh_sdt){
		   this -> kh_sdt= kh_sdt;
	   }
	   string getkh_sdt(){
		   return kh_sdt;
	   }
};


//CLASS DATE
class date {
public:
    int day;
    int month;
    int year;

    // Constructor
	date() {}
	date(int day, int month, int year) {
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
		HOADON(KHACHHANG _kh, vector<SANPHAM>& _sp, int _seri, int _stt, int sum){
			this -> _kh= _kh;
			this -> _sp= _sp;
			this -> _seri= _seri;
			this -> _stt= _stt;
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
		
		void set_stt(int _stt){
			this -> _stt= _stt;
		}
		int get_stt(){
			return _stt;
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
		
		//Phuong thuc xoa san pham
		/*void xoasanpham(int sp_id){
			for(auto it = _sp.begin(); it != _sp.end(); ++it){
				if(it->getsp_id() == sp_id){
					_sp.erase(it);
					break;
				}
			}
		}*/
		
		//Phuong thuc tinh tong so tien cho hoa don
		/*double tinhTongTien() {
			double tongTien = 0;
			for (const auto& sp : _sp) {
				tongTien += sp.getsp_price() * sp.getsp_nums();
			}
			return tongTien;
		}*/ 
};

//Ham Nhap hoa don
void NhapHoaDon(HOADON &m,int &i, vector<SANPHAM> kho) {
    char c = 'N';
    do {
        cout <<"\nXin moi nhap san pham: " << endl;
		SANPHAM product;
		string text;
		getline(cin, text);
		for (int i = 0; i < 100; i++) {
			if (text == kho[i].getsp_id()){
				product = kho[i];
			}
		}
		cout << "\nSo luong: ";
		int a;
		cin >> a;
        product.setsp_nums(a);
		int cnt = 0;
		cnt += product.getsp_nums()*product.getsp_price();
		m.set_sum(cnt);
		m.themsanpham(product);
		i++;
		cout <<"\nBan co muon tiep tuc khong? Y/N";
        c = getch();
    } while (c == 'y'||c == 'Y');
}


//Ham in hoa don
void InHoaDon(HOADON m, int i) {
    cout <<"\nNhap thong tin hoa don: ";
    cout <<"\nNhap thoi gian: ";
    cout << endl << endl << endl << endl;
    cout << "\n                          SUPERMARKET                          ";
    cout << "\nDia chi: So 1 Dai Co Viet, Hai Ba Trung, Ha Noi";
    cout << "\nThoi gian: ";
    cout << "\nMa so hoa don: ";
    cout << "\n" << setfill('_') << setw(63) << "_" << setfill(' ');
    cout << "\n" << setw(7) << left << "MSSP" << setw(15) << left << "Ten san pham" << setw(9) << left << "Don vi" << setw(11) << left << "So luong" << setw(11) << left << "Dong gia" << setw(10) << right << "Thanh tien";
    for (int j = 0; j < i; j++) {
    cout << "\n" << setw(7) << left << m._sp[j].getsp_id();
    cout << setw(15) << left << m._sp[j].getsp_name();
    cout << setw(9) << left << m._sp[j].getsp_donvi();
    cout << setw(11) << left << m._sp[j].getsp_nums();
    cout << setw(11) << left << m._sp[j].getsp_price();
    cout << setw(10) << right << m._sp[j].getsp_nums()*m._sp[j].getsp_price();
    }
    cout << "\n" << setfill('_');
    cout << setw(63) << "_";
    cout << setfill(' ');
    cout << "\nTong tien:";
    cout << setw(53) << right << m.sum; 
    cout << "\n                     Hen gap lai quy khach!                     ";
}

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


int main(){
	vector<SANPHAM> kho;
    readCSV("mini_supermarket_products_en.csv", kho);
	HOADON m;
	int i = 0;
	NhapHoaDon(m, i, kho);
	InHoaDon(m, i);
    return 0;
}


