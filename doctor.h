#pragma once
#include<iostream>
#include "User.h"
#include "Appointment.h"

class Doctor : public User         // inheritance from user class
{
private:
	Appointment* A = new Appointment;   // aggregation with appointment
	string name, cnic, pass, username, email, phoneno, specification, city, hospital;
	int stime, etime, experience;

public:

	string getName()
	{
		return name;
	}
	string getcnic()
	{
		return cnic;
	}
	string getpass()
	{
		return pass;
	}
	string getusername()
	{
		return username;
	}

	Appointment* getA()
	{
		return A;
	}
	void setDoctor()
	{

	}
};