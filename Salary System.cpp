#include<iostream>
#include<string>

using namespace std;

class Employee                 // base or parent class
{
protected:
	string name;
	int id;
	int age;
	string gender;
	public:
	void Egetdata()
	{
		cout<<" Enter your name:";
		cin>>name;
		cout<<" Enter your id number:";
		cin>>id;
		cout<<" Enter your age:";
		cin>>age;
		cout<<" Enter your gender:";
		cin>>gender;
		}	
	void Eshowdata()
	{
		cout<<" Name: "<<name<<endl;
		cout<<" id: "<<id<<endl;
		cout<<" age: "<<age<<endl;
		cout<<" gender: "<<gender<<endl;
	}
};

class manager:public Employee                 // Manager class inherit from employee class
{
protected:
	
	string employeeas;
	double msalary;
	public:
		manager()
		{
			employeeas=" manager";
			msalary=50000;
			
		}
		 Mshowdata()
		
		{
			Egetdata();
			
		cout<<"^^^^^^^^^^^^ Manager PayCode ^^^^^^^^^^^^^^"<<endl;
		cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
		Eshowdata();	 
		cout<<"Worked as "<<employeeas<<endl;
		cout<<"fixed salary is "<<msalary<<endl;
			
		}
		
};
class hourly_worked:public Employee            //hourly worked class inherit from employee class
{
	protected:
		int hrRate;
		int hours;
		float salary;
		
		
		public:
			void CalculateHourlySalary()
          {
            if ( hours <= 40 ){
            	salary = hours *  hrRate;
			}
            else{
                salary = 40.0 * hrRate + ( hours - 40 ) * hrRate * 1.5;
            }
      }
      
      void hwgetdata()
      { 
       
             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             Egetdata();
             cout<<"Enter Hour Rate:Rs ";
             cin>>hrRate;
             cout<<"Enter hours worked: ";
             cin>>hours;
             
             cout<<endl;
	  }
	
	void hwshowdata()
	{
		cout<<"^^^^^^^^   Hourly Worker PayCode   ^^^^^^^^"<<endl;
		cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
		Eshowdata();
		cout<<"Hour rate:Rs="<<hrRate<<endl;
		cout<<"Hour worked="<<hours<<endl;
		cout<<"Hourly worker's salary is:Rs "<<salary<<endl;
		cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	}
};

class commission_worker:public Employee   // comission class inherit from employee class
{
protected:
	float sales;
	double sale;
	public:	
	
	void getCommissionHourlySalary(){
              sales =(sale* 0.057 )+ 250;
              
			}

	void cwgetdata(){
           
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            Egetdata();
            cout<<"Enter  weekly sale: ";
            cin>>sale;
			cout<<endl;
		}

	void cwshowdata(){
			cout<<"^^^^^^^  Commission Workers PayCode  ^^^^^^"<<endl;
		 	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
		 	Eshowdata();
			cout<<"Weekly sales="<<sale<<endl;
			cout<<"Commission worker's hourly is:Rs"<<sales<<endl;
		 	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;	
		}
};


class piece_worker:public Employee               // piece worker class inherit from employee class
{
	protected:
		int product;
		int rate;
		float pro;
		
		
		public:
			
		void getPieceWorkerHourlySalary()
          {
             pro = product * rate;
              
          }	
	
		void pwgetdata()
		{
			cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl; 
			Egetdata();   
	        cout<<"Enter Number of product: ";
            cin>>product;
            cout<<"Enter rate per each pieces sold:Rs ";
            cin>>rate;
             
		}
	
		void pwshowdata()
		{
			cout<<"^^^^^^^^^^  Piece Worker PayCode  ^^^^^^^^^"<<endl;
             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             Eshowdata();
             cout<<"Number of product ="<<product<<endl;
             cout<<"rate per each pieces sold:Rs="<<rate<<endl;
		     cout<<"Piece worker's salary: "<<pro<<endl;
		}
};

int main()
{
	
manager mag;
hourly_worked hw;
commission_worker cw;
piece_worker pw;


cout<<" ***********************************"<<endl;
cout<<" * Press 1 for Manager             *"<<endl;
cout<<" * Press 2 for Hourly worker       *"<<endl;
cout<<" * Press 3 for Commission worker:  *"<<endl;
cout<<" * press 4 for Piece worker:       *"<<endl;
cout<<" ***********************************"<<endl;


int paycode;
while(paycode!=-1){
cout<<endl;
cout<<"\tEnter PayCode:" ;  
cin>>paycode;
cout<<"**************************************"<<endl;
cout<<endl;



    switch(paycode){
    case 1:
    {
              /*Manager Fixed salary */

              cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
              cout<<"^^^^ Manager PayCode Has been selected ^^^^"<<endl;
              cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    
             mag.Mshowdata();
              system("pause");
              break;
    }



     case 2:
     {

             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             cout<<"^^^^^^^^   Hourly Worker PayCode   ^^^^^^^^"<<endl;
             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             
             hw.hwgetdata();
             hw.hwshowdata();
             break;
             
    }

    case 3:
    {

            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"^^^^^^^  Commission Workers PayCode  ^^^^^^"<<endl;
            cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cw.cwgetdata();
            cw.cwshowdata();
            break;
            
    }

    case 4:
    {
             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             cout<<"^^^^^^^^^^  Piece Worker PayCode  ^^^^^^^^^"<<endl;
             cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
             pw.pwgetdata();
             pw.pwshowdata();
             break;
             }
    default:
    	{
   		 cout<<"Input Error"<<endl;
   		 break;
	}



    return 0;
}	
}
}
