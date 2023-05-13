
#pragma once
#include <iostream>
#include <string>
using namespace std;
class User{
private:
string cnic;
string name;
string phone_no;
string password;
int age;

User(){
    cnic = "NULL";
    name= "NULL";
    age =0;
    phone_no= "NULL";
    password="NULL";
}
string getCnic(){
    return cnic;
}
string getName(){
    return name;
}
string getPhoneno(){
    return phone_no;
}
string getPass(){
    return password;
}
int getAge(){
    return age;
}
void setName( string n){
    name= n;
}
void getCnic( string c){
    cnic = c;
}
void setPhoneno( string p){
    phone_no=p;
}
void setPass(string pass){
    pass= password;
}
void setAge( int a){
    age =a;
}
};


