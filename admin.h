#include<iostream>
#include<fstream>
using namespace std;
class Admin:public user{
    protected:
    int staffID;
    public:
    Admin(){
    }
       Admin( string cnic,string name,int age,string phone_no,string email,string password,int staffID)
    { staffID=staffID;
    }
    int setstaffid(int staffID)
    { staffID=staffID;
    }
    int staffid();
   {return staffID;
}
}
