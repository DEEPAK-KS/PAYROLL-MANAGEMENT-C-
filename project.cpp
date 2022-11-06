#include<iostream>
#include<fstream>
#include <cstdio>
#include<cstring>
using namespace std;
class emp_data
{
public:
    char name[15],level[2],phn[10];
    int empid;
};
class emp_write
{
public:
    emp_data emp,temp;
    int flag=0;
    char file1[15]="Employee.txt",file2[15]="temp.txt";
    void write()
    {
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S ID:-";
        cin>>emp.empid;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S NAME:-";
        cin>>emp.name;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S PHONE NUMBER:-";
        cin>>emp.phn;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE LEVEL(A/B/C/D):-";
        cin>>emp.level;
        fstream add;
        add.open("Employee.txt",ios::app);
        add.write((char*)&emp,sizeof(emp));
        add.close();
    }
    void update()
    {
        fstream edit,newtxt;
        edit.open("Employee.txt",ios::in);
        newtxt.open("temp.txt",ios::out);
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S ID:-";
        cin>>emp.empid;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S NAME:-";
        cin>>emp.name;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE'S PHONE NUMBER:-";
        cin>>emp.phn;
        cout<<"\t\t\t\t\t\t";cout<<"\n\nENTER THE EMPLOYEE LEVEL(A/B/C/D):-";
        cin>>emp.level;
        while(edit.read((char*)&temp,sizeof(temp)))
        {
            if (temp.empid==emp.empid)
                flag=1;
            else
                newtxt.write((char*)&temp,sizeof(temp));
        }
        if (flag==1)
        {
            newtxt.write((char*)&emp,sizeof(emp));
            edit.close();
            newtxt.close();
            remove(file1);
            rename(file2,file1);
        }
        else
        {
            edit.close();
            newtxt.close();
            cout<<"\t\t\t\t\t\t";cout<<"!!!!INVALID EMPLOYEE ID!!!";
            remove(file2);
        }

    }
    void dele()
    {
        fstream edit,newtxt;
        edit.open("Employee.txt",ios::in);
        newtxt.open("temp.txt",ios::app);
        int id;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER THE EMPLOYEE'S ID:-";
        cin>>id;
        while(edit.read((char*)&temp,sizeof(temp)))
        {
            if (temp.empid==id)
                flag=1;
            else
                newtxt.write((char*)&temp,sizeof(temp));
        }
        if (flag==1)
        {
            edit.close();
            newtxt.close();
            remove(file1);
            rename(file2,file1);
        }
        else
        {
            cout<<"\t\t\t\t\t\t";cout<<"!!!!INVALID EMPLOYEE ID!!!\n";
            edit.close();
            newtxt.close();
            remove(file2);
        }
    }
    void display()
    {
        fstream show;
        int num=0;
        show.open("Employee.txt",ios::in);
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t";cout << char(218);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(191) << endl;
        cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout.setf(ios::left);cout << "        " << char(186) ;cout.width(15);cout.setf(ios::left);cout<< "          " << char(186);cout.width(15);cout.setf(ios::left);cout<< "          " << char(186);cout.width(15);cout.setf(ios::left);cout<< "          " << char(186);cout.width(15);cout.setf(ios::left);cout<< "          " << char(186) << endl;
        cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout.setf(ios::left);cout << "S/NO" << char(186) ;cout.width(15);cout.setf(ios::left);cout<< "EMPLOYEE ID" << char(186);cout.width(15);cout.setf(ios::left);cout<< "EMPLOYEE NAME" << char(186);cout.width(15);cout.setf(ios::left);cout<< "PHONE NUMBER" << char(186);cout.width(15);cout.setf(ios::left);cout<< "EMPLOYEE LVL" << char(186) << endl;
        cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(185) << endl;
        while(show.read((char*)&emp,sizeof(emp)))
        {
        num++;
        cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout.setf(ios::left);cout <<num << char(186) ;cout.width(15);cout.setf(ios::left);cout<<emp.empid<< char(186);cout.width(15);cout.setf(ios::left);cout<<emp.name<< char(186);cout.width(15);cout.setf(ios::left);cout<<emp.phn<< char(186);cout.width(15);cout.setf(ios::left);cout<<emp.level<< char(186) << endl;
        cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(185) << endl;
        }
        cout<<"\t\t\t\t\t\t";cout << char(192);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(217) << endl;
    }

};
class pay
{
    public:
    char lvl[2],nam[15];
    int da,hra,gbasic,gda,ghra,incentive,esi=0,advance=0,tds=0,lwf=0,pt=0,tot,gsum,salary,basic=0,tded,tax,pf,temp;
    int p,pl,wo,f,days,pd;
    emp_data obj;
    void get_sal(int id)
    {
        fstream show;
        show.open("Employee.txt",ios::in);
        while(show.read((char*)&obj,sizeof(obj)))
        {
            if (obj.empid==id)
            {
                strcpy(lvl,obj.level);
                strcpy(nam,obj.name);
                break;
            }

        }
    }
    void sal()
    {
        if (strcmp(lvl,"D")==0)
            basic=15000;
        else if (strcmp(lvl,"C")==0)
            basic=20000;
        else if (strcmp(lvl,"B")==0)
            basic=30000;
        else if (strcmp(lvl,"A")==0)
            basic=40000;
    }
    void bas()
    {
        da=(basic*10)/100;
        temp=(da+basic)*3/10;
        hra=temp;
        tot=basic+da+hra;
    }
    void attendance()
    {
        cout<<"\t\t\t\t\t\t";cout<<"TOTAL NO OF DAYS=:-";
        cin>>days;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER PRESENT DAYS:-";
        cin>>p;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER PAID LEAVES:-";
        cin>>pl;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER WEEKY OFF:-";
        cin>>wo;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER FESTIVALS:-";
        cin>>f;
        pd=p+pl+wo+f;
    }
    void gross_sal()
    {
       gbasic=(tot*pd)/days;
       gda=(da*pd)/days;
       ghra=(hra*pd)/days;
       cout<<"\t\t\t\t\t\t";cout<<"INCENTIVES IF ANY=:-";
       cin>>incentive;
       gsum=gbasic+gda+ghra+incentive;
    }
    void dedeuction()
    {
        if(tot>21000)
            esi=(gsum*0.75)/100;
        temp=gbasic+gda;
        temp=temp*.12;
        pf=temp;
        cout<<"\t\t\t\t\t\t";cout<<"ENTER ADVANCE IF ANY:-";
        cin>>advance;
        tds=(basic*3)/100;
        temp=670;
        lwf=temp;
        pt=210;
        tded=advance+tds+lwf+pt+esi+pf;
        tax=pt+tds;
    }
    void final_salary()
    {
        salary=gsum-tded;
    }
};
class payroll
{
    public:
    emp_data tobj;
    int get_emp(pay *obj_s,int eid)
    {
    ifstream file_base;
    file_base.open("Employee.txt",ios::in);
    while(file_base.read((char*)&tobj,sizeof(tobj)))
    {
        if (eid==tobj.empid)
        {
            obj_s->get_sal(tobj.empid);
            obj_s->sal();
            obj_s->bas();
            obj_s->attendance();
            obj_s->gross_sal();
            obj_s->dedeuction();
            obj_s->final_salary();
            file_base.close();
            return 0;
        }
    }
    file_base.close();
    return 1;
    }
};
int main()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t";cout << char(218);  for(int i=0; i<69; i++){cout << char(205);}cout << char(191) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186); cout.width(70);cout<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(70); cout<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(70); cout<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(69);cout.setf(ios::left); cout<<"                    PAYROLL MANAGEMENT SYSTEM"<<char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(69);cout<<"  "<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(69);cout<<"  "<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(186) ; cout.width(69); cout<<"  "<< char(186) << endl;
    cout<<"\t\t\t\t\t\t";cout << char(192);  for(int i=0; i<69; i++){cout << char(205);} cout << char(217) << endl;
    cout<<"\n\n\n\n\n\n\n";
    system("pause");
    int ch,ch2;
    start:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t TEMAKI         \n\n";
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t"<< char(218);for(int i=0; i<65; i++){cout << char(205);}cout << char(191)<<"\n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >>EMPLOYEE DATA                                  |\n";
        cout<<"\t\t\t\t\t\t|             2  >>SALARY SLIP                                    |\n";
        cout<<"\t\t\t\t\t\t|             3  >>GENERATE PAYROLL                               |\n";
        cout<<"\t\t\t\t\t\t|             4  >>EXIT THE PROGRAM                               |\n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t"<< char(192);for(int i=0; i<65; i++){cout << char(205);}cout << char(217)<<"\n";
        cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
    if (ch==1)
    {
        emp_write obj;
        ewrite:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t\t\t\t\t\t"<< char(218);for(int i=0; i<65; i++){cout << char(205);}cout << char(191)<<"\n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t|             1  >>ADD EMPLOYEE                                   |\n";
        cout<<"\t\t\t\t\t\t|             2  >>DELETE EMPLOYEE                                |\n";
        cout<<"\t\t\t\t\t\t|             3  >>UPDATE EMPLOYEE                                |\n";
        cout<<"\t\t\t\t\t\t|             4  >>SHOW EMPLOYEE LIST                             |\n";
        cout<<"\t\t\t\t\t\t|             5  >>RETURN TO MAIN MENU                            |\n";
        cout<<"\t\t\t\t\t\t|                                           	                  |\n";
        cout<<"\t\t\t\t\t\t"<< char(192);for(int i=0; i<65; i++){cout << char(205);}cout << char(217)<<"\n";
        cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch2;
        cout<<"\n\n";
        if (ch2==1)
            obj.write();
        else if (ch2==2)
            obj.dele();
        else if (ch2==3)
            obj.update();
        else if (ch2==4)
            obj.display();
        else if (ch2==5)
            goto start;
        else
            cout<<"\n\t\t\t\t\t\tPLEASE CHK YOUR INPUT\n";
        system("pause");
        goto ewrite;

    }
    else if (ch==2)
    {
        pay sslip;
        int id,flag;
        payroll obj;
        cout<<"\t\t\t\t\t\tENTER THE EMPLOYEE ID";
        cin>>id;
        flag=obj.get_emp(&sslip,id);
        if (flag==0)
            {
                system("cls");
                cout<<"\t\t\t\t\t\t";cout << char(218);  for(int i=0; i<50; i++){cout << char(205);}cout << char(191) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(50);cout.setf(ios::left);cout << "                    TEMAKI                  "<< char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<50; i++){cout << char(205);}cout << char(180) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "EMPLOYEE ID" ;cout<<char(186);cout.width(24);cout << id << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "EMPLOYEE NAME" ;cout<<char(186);cout.width(24);cout << sslip.nam << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "PRESENT DAYS" ;cout<<char(186);cout.width(24);cout << sslip.pd << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "EMPLOYEE LEVEL" ;cout<<char(186);cout.width(24);cout << sslip.lvl << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<50; i++){cout << char(205);}cout << char(180) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "EARNINGS" ;cout<<char(186);cout.width(24);cout << "DEDUCTION" << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<50; i++){cout << char(205);}cout << char(180) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout << "BASIC SALARY:";cout.width(10);cout<<sslip.basic;cout<<char(186);cout.width(15);cout << "ESI:";cout.width(9);cout<<sslip.esi << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout << "GROSS DA:";cout.width(10);cout<<sslip.gda ;cout<<char(186);cout.width(15);cout << "PF:";cout.width(9);cout<<sslip.pf << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout << "GROSS HRA:";cout.width(10);cout<<sslip.ghra ;cout<<char(186);cout.width(15);cout << "ADVANCE:";cout.width(9);cout<<sslip.advance << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(15);cout << "INSENTIVES:";cout.width(10);cout<<sslip.incentive ;cout<<char(186);cout.width(15);cout << "LWF:";cout.width(9);cout<<sslip.lwf << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(19);cout << "TOTAL GROSS SALARY:";cout.width(6);cout<<sslip.gsum ;cout<<char(186);cout.width(15);cout << "TAX:";cout.width(9);cout<<sslip.tax << char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(195);  for(int i=0; i<50; i++){cout << char(205);} cout << char(180) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(186);cout.width(25);cout << "TOTAL SALARY:-";cout.width(25);cout.setf(ios::left);cout<<sslip.salary;cout<< char(186) << endl;
                cout<<"\t\t\t\t\t\t";cout << char(192);  for(int i=0; i<50; i++){cout << char(205);} cout << char(217) << endl;
            }
        else if (flag==1)
            {cout<<"\t\t\t\t\t\tEMPLOYEE NOT FOUND\n";}
            system("pause");
    }
    else if (ch==3)
    {
        fstream bill,payroll1;
        emp_data tobj;
        payroll obj;
        pay sslip;
        int ch=0,su=0,bills;
        bill.open("Employee.txt",ios::in);
        payroll1.open("BILL.txt",ios::out);
        while(bill.read((char*)&tobj,sizeof(tobj)))
        {
            su++;
            cout<<"\t\t\t\t\t\tEMPLOYEE NAME:-"<<tobj.name<<endl;
            cout<<"\t\t\t\t\t\tEMPLOYEE ID:-"<<tobj.empid<<endl;
            obj.get_emp(&sslip,tobj.empid);
            payroll1.write((char*)&sslip,sizeof(sslip));
        }
        payroll1.close();
        payroll1.open("BILL.txt",ios::in);
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t TEMAKI         \n\n";
        cout<<"\t\t";cout << char(218);  for(int i=0; i<4; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);for(int i=0; i<5; i++){cout << char(205);}  cout << char(194);  for(int i=0; i<5; i++){cout << char(205);}cout << char(194);  for(int i=0; i<5; i++){cout << char(205);}cout << char(194);  for(int i=0; i<5; i++){cout << char(205);} cout << char(194);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(191) << endl;
        cout<<"\t\t";cout << char(186);cout.width(4);cout.setf(ios::left);cout <<"S/NO" << char(186) ;cout.width(15);cout.setf(ios::left);cout<< "     NAME" << char(186);cout.width(5);cout.setf(ios::left);cout<< "BASIC" << char(186);cout.width(5);cout.setf(ios::left);cout<< "DA" << char(186);cout.width(5);cout.setf(ios::left);cout<< "HRA"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "TOTAL"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "P"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "PL"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "WO"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "F"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "PD"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "GROSS"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "G-DA"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "G-HRA"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "INCEN"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "TOTAL"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "ESI"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "PF"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "ADV."<< char(186);cout.width(5);cout.setf(ios::left);cout<< "TDS"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "LWF"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "PT"<< char(186);cout.width(5);cout.setf(ios::left);cout<< "T.SAL" << char(186) << endl;
        cout<<"\t\t";cout << char(195);  for(int i=0; i<4; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);} cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(185) << endl;
        while(ch<su)
        {
            ch++;
            payroll1.read((char*)&sslip,sizeof(sslip));
            bills+=sslip.salary;
            cout<<"\t\t";cout << char(186);cout.width(4);cout.setf(ios::left);cout << ch << char(186) ;cout.width(15);cout.setf(ios::left);cout<<sslip.nam<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.basic<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.da<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.hra<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.tot<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.p<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.pl<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.wo<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.f<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.pd<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.gbasic<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.gda<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.hra<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.incentive<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.gsum<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.esi<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.pf<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.advance<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.tds<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.lwf<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.pt<< char(186);cout.width(5);cout.setf(ios::left);cout<<sslip.salary<< char(186) << endl;
            cout<<"\t\t";cout << char(195);  for(int i=0; i<4; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}cout << char(197);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(185) << endl;

        }
         cout<<"\t\t";cout << char(195);  for(int i=0; i<4; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<15; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}cout << char(193);  for(int i=0; i<5; i++){cout << char(205);}  cout << char(180) << endl;
         cout<<"\t\t";cout << char(186);cout.width(100);cout.setf(ios::right);cout << "TOTAL SALARY:-";cout.width(46);cout.setf(ios::left);cout<<bills;cout<< char(186) << endl;
         cout<<"\t\t";cout << char(192);  for(int i=0; i<146; i++){cout << char(205);}  cout<<char(217) << endl;
        payroll1.close();
        system("pause");
    }
    if (ch!=4)
        goto start;

}
