#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

struct Employee{
    int ID;
    string name;
    int salaryLPA;
};


int main(){

    int n;
    
    printf("Enter number of Employee : ");
    scanf("%d",&n);
    
    Employee *Emp = new Employee[n];

    for(int i = 0; i<n; i++){
        printf("\n Enter %d Employee details : \n",i+1);
        printf("Enter %d Employee ID : ",i+1);
        scanf("%d",&Emp[i].ID);
        printf("Enter %d Employee Name : ",i+1);
        scanf("%s",&Emp[i].name);
        printf("Enter %d Employee salary in LPA : ",i+1);
        scanf("%d",&Emp[i].salaryLPA);
    }

    ofstream file("employee.txt");
    
    if(file.is_open()){
        file << "===== EMPLOYEE DETAILS =====\n";
        file << "Total Employees: " << n << "\n\n";
        
        for(int i = 0; i<n; i++){
            file << "Employee " << (i+1) << " Details: "<< endl;
            file << "ID: " << Emp[i].ID << endl;
            file << "Name: " << Emp[i].name << endl;
            file << "Salary (LPA): " << Emp[i].salaryLPA << endl;
            file << "----------------------------" << endl;
        }
        
        file.close();
    }
    else{
        printf("Error opening file!\n");
    }

    printf("\n===== Given Employee Data are =====\n");
    for(int i = 0; i<n; i++){
        printf("Employee %d Data : \n",i+1);
        printf("Employee ID: %d\n",Emp[i].ID);
        printf("Employee Name: %s\n",Emp[i].name);
        printf("Employee salary in LPA: %d\n",Emp[i].salaryLPA);
        printf("----------------------------\n");
    }
    
    delete[] Emp;

    return 0;
}