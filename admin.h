#include<iostream>
#include<fstream>
#include "admin.h";
#include "Appointment.h";
#include "Doctor.h";
#include "patient.h";
#include "User.h";
#include "Hospital.h";

using namespace std;
class Admin:public User {
    protected:
    int staffID;
    public:
    Admin(){}
       Admin( string cnic,string name,int age,string phone_no,string email,string password,int staffID){}

    int setstaffid(int staffID)
    { 
      staffID=staffID;
    }
    int staffid()
   {
      return staffID;
}
};
