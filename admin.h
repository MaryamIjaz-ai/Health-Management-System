#pragma once
#include<iostream>
#include<fstream>
#include"User.h"
#include"Doctor.h"
#include"patient.h"
#include"Appointment.h"


class Admin :public user{
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