#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
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




//CLASS SAN PHAM
class SANPHAM{
	private:
	   int sp_id;
	   string sp_name;
	   double sp_price;
	   int sp_nums;
	   int sp_date;
	
	public:
		// Constructor san pham
		SANPHAM(){}
		SANPHAM(int sp_id, string sp_name, double sp_price, int sp_nums, int sp_date){
			this->sp_id= sp_id; 
			this->sp_name= sp_name;
			this->sp_price= sp_price;
			this->sp_nums= sp_nums;
			this->sp_date= sp_date;
		}
		
		//Cac ham setter,getter
		void setsp_id(int sp_id){
			this->sp_id= sp_id;
		}
		int getsp_id(){
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
		
		void setsp_date(int sp_date){
			this->sp_date= sp_date;
		}
		int getsp_date(){
			return sp_date;
		}	
};





// CLASS KHO
class KHO{
	private:
		int kho_loai;
		vector<SANPHAM> kho_sp;
	public:
		// Constructor
		KHO(){}
		KHO(int kho_loai, vector<SANPHAM>& kho_sp){
			this->kho_loai= kho_loai;
			this->kho_sp = kho_sp;
		}
		
		// Phuong thuc
		void display(){}
};





//CLASS HOA DON
class HOADON{
	private:
		KHACHHANG _kh;
	    vector<SANPHAM> _sp;
	    static int _seri;
	    int _stt;
	public:
		// Constructors
		HOADON(){}
		HOADON(KHACHHANG _kh, vector<SANPHAM>& _sp, int _seri, int _stt){
			this -> _kh= _kh;
			this -> _sp= _sp;
			this -> _seri= _seri;
			this -> _stt= _stt;
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



int main(){
	SANPHAM sp;
	int sp_id;
	cin >>sp_id;
	sp.setsp_id(sp_id) ;
	cout<< "ID: " <<sp.getsp_id(); 
	return 0; 
}

