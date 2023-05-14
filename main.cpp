#include<iostream>

#include "admin.h";
#include "Appointment.h";
#include "Doctor.h";
#include "patient.h";
#include "User.h";
using namespace std;

int main()
{
	Doctor D;// doctor object
	patient P;//patient object
	Hospitals H;// hospital object
	Admin A;// admin object
	Appointment App; //Appointment object
	int choice = 0, choose = 0, choice1;;//some variables for chooice input
	string name, cnic, user_name, pass, confirm_pass, phoneno, email, specification, currHos, currcity;
	string docname, choosedoctor, patname;// other input variables for name cnic and etc

	char ch = ' ', ch1 = ' ', c = ' ', c1 = ' ';
	int age, u_c = 0, l_c = 0, num = 0, special_char = 0;
	int experience = 0;
	string workinghospital, workingcity, workinghours;
	int stime, etime, workingexperience;
	int schoose;
	string star;

	// an array of hospital names
	string hospitalname[15] = { "  Shifa_International_Hospital" ,"    Maroof_Hospital" ,"    Noori_Hospital","    Kulsum_Hospital","    PIMS" ,"    Jinnah_Hospital", "    Lahore_General_Hospital","    Mayo_Hospital", "    Aadil_Hospital" ,"    MidCity_Hospital" ,"    Aga_KHan_Hospital" ,"    Pateil_Hospital", "    Memon_Hospital", "    Ziauddin_Hospital" ,"    A.O_Hospital" };

	Hospitals* Hos = new Hospitals[15];

	for (int i = 0; i < 5; i++)
	{
		Hos[i].setCity("Islamabad");
		Hos[i].setHospitalName(hospitalname[i]);
	}
	for (int i = 5; i < 10; i++)
	{
		Hos[i].setCity("Lahore");
		Hos[i].setHospitalName(hospitalname[i]);
	}
	for (int i = 10; i < 15; i++)
	{
		Hos[i].setCity("Karachi");
		Hos[i].setHospitalName(hospitalname[i]);
	}

}