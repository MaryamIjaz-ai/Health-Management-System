#pragma once
#include<iostream>
#include<fstream>
#include"User.h"
#include"Appointment.h"
#include"Payment.h"
class Patient:public User{
    string name, cnic;
    public:
    patient(){
        name="";
        cnic="";
    }
    void setpatient(string n,string c){
        name=n;
        cnic=c;
    }
    void checkPatientDetails(){
        string word,patientname,patientcnic,patientUsername,patientPassword;
       
	}
    	void checkPatientDetails()
	{
		string word, patientname, patientcnic, patientUsername, patientPassword;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> patientname;
			w >> patientcnic;
			w >> patientUsername;
			w >> patientPassword;


			cout <<     patientname << "    " <<     patientcnic << "     " <<     patientUsername << endl;


		}
	}
    
    }


