#pragma once
#include<iostream>
#include<fstream>
#include"User.h"
#include"Appointment.h"
#include"Payment.h"
class Patient:public user{
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
       
	}}


    
