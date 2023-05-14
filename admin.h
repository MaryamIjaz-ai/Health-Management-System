#pragma once
#include<iostream>
<<<<<<< Updated upstream
#include"user.h"
#include"patient.h"
=======
#include<fstream>
#include"User.h"
>>>>>>> Stashed changes
using namespace std;

class Admin:public user{
    protected:
    int staffID;
    public:
    Admin()
	{

	}
	Admin(string cnic_n, string name, int age, string phone_no, string email, string password, int staffID)
	{
		staffID = staffID;
	}
	int setstaffid(int staffID)
	{
		staffID = staffID;
	}
	int getstaffid()
	{
		return staffID;
	}
};