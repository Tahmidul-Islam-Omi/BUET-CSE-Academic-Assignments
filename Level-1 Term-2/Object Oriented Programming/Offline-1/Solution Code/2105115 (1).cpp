#include<iostream>
#include<cstring>
using namespace std;

class Student
{
private:
    int roll;
    char* name;
    float cgpa;

public:
    Student(int Roll, char* Name, float CGPA) {

        roll = Roll;
        name = (char*)malloc( (strlen(Name)+1) * sizeof(char) );
        strcpy(name , Name);
        cgpa = CGPA;
    }

    Student(char* Name) {
        name = (char*)malloc( (strlen(Name)+1) * sizeof(char) );
        strcpy(name , Name);
    }

    Student(int Roll) {
        roll = Roll;
    }

    Student() {

    }

    void setname(char* Name) {
        free(name);
        name = (char*)malloc( (strlen(Name)+1) * sizeof(char) );
        strcpy(name , Name);
    }

    char* getname() {
        return name;
    }

    void setroll(int Roll) {
        roll = Roll;
    }

    int getroll() {
        return roll;
    }

    void setcg(float CGPA) {
        cgpa = CGPA;
    }

    float getcg() {
        return cgpa;
    }


    ~Student() {
        free(name);
        roll = 0;
    }
};


int main()
{
    Student s1;
    Student s2("Karim");
    Student s3(3);
    Student s4(4, "Rahim", 3.52);
    Student s5(5, "Sakib", 3.92);
    s1.setname("Papon");
    s1.setroll(1);
    s1.setcg(4.00);
    s2.setroll(2);
    s2.setcg(3.8);
    s3.setname("Abdul");
    s3.setcg(3.96);
    float avg=(s1.getcg()+s2.getcg()+s3.getcg()+s4.getcg()+s5.getcg())/5;
    cout<<"Student #1"<<endl;
    cout<<"Roll : "<<s1.getroll()<<endl;
    cout<<"Name : "<<s1.getname()<<endl;
    cout<<"CGPA : "<<s1.getcg()<<endl<<endl;

    cout<<"Student #2"<<endl;
    cout<<"Roll : "<<s2.getroll()<<endl;
    cout<<"Name : "<<s2.getname()<<endl;
    cout<<"CGPA : "<<s2.getcg()<<endl<<endl;

    cout<<"Student #3"<<endl;
    cout<<"Roll : "<<s3.getroll()<<endl;
    cout<<"Name : "<<s3.getname()<<endl;
    cout<<"CGPA : "<<s3.getcg()<<endl<<endl;

    cout<<"Student #4"<<endl;
    cout<<"Roll : "<<s4.getroll()<<endl;
    cout<<"Name : "<<s4.getname()<<endl;
    cout<<"CGPA : "<<s4.getcg()<<endl<<endl;

    cout<<"Student #5"<<endl;
    cout<<"Roll : "<<s5.getroll()<<endl;
    cout<<"Name : "<<s5.getname()<<endl;
    cout<<"CGPA : "<<s5.getcg()<<endl<<endl;


    cout<<"Average of CGPA : "<<avg<<endl;

}
