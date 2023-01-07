/*
                *******JAYPPEE INSTITUE OF INFORMATION TECHNOLOGY*******
                                        SEC-62

                            *SOFTWARE DEVELOPMENT FUNDAMENTALS-2*
                
                                  SEMESTER-2 MINOR PROJECT


                INTRODUCTION:
                *THIS WHOLE PROJECT IS A COMPLETE PROGRAM TO MANAGE THE COLLEGE PORTAL.
                *IT CAN BE ACCESSED BY THE ADMIN OR TEACHER SEPERATELY.
                *BOTH GOT THERE OWN USERID AND PASSWORD.
                *BOTH HAVE SEPARATE MENU TO PERFORM DIFFERENT FUCTIONS.

                SUBMITTED TO:-
                1.PARUL AGARWAL
                2.ANKITA VERMA
                

                SUMITTED BY:-
                1.VIVEK SHAURYA (21803013)
                2.HARSHIT VIJAY (21803015)
                3.ANMOL VERMA   (21803014)
                4.ROHIT GUPTA   (21803018)

*/
//WITHOUT COMMENTING 1300.
// HEADER FILES
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>

//CHECKING OS FOR DIFFERENT FUNCTIONS.

#ifdef _WIN32                                       
    #define OS 0
    #include<windows.h>
#endif

#ifdef __APPLE__
    #define OS 1
    #include<unistd.h>
#endif


#ifdef __linux__
    #define OS 2
    #include<unistd.h>
#endif


//global variable

int option; 

using namespace std;
string loggerId;

//TELLING THE COMPILER ABOUT TEACHER CLASS DEFINITION IS BELOW IN THE CODE.

class Teacher;

//pure virtual base class person from which the admin class and the teacher class are derived.
class Person
{

    public:
    // this function match the name with the password to the access to the user
    // and it is derived in the child class teacher and admin.
    void login_access(string login[],string password[],int n)
    {
        
        string name1,password1;
        int c=0;
        label6: cout<<setw(48);
        cout<<"NAME:-";
        cin>>name1;
        loggerId = name1;
        label1: cout<<"\n"<<setw(48)<<"PASSWORD:-";
        cin>>password1;
        for(int i=0;i<n;i++)
        {
            if(login[i]==name1)
            {
                c=i;
            }
        }
        if(password[c]==password1)
        {
            cout<<setw(48)<<"PASSWORD MATCHED."<<endl;
            if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        }
        else
        {
            cout<<setw(48)<<"INCORRECT PASSWORD ENTERED."<<endl;
            goto label1;
        }
    }
    //this function is used to take the data from the login and passsword 
    //file and feed the data in the program.
    void get_login_detail(void)
    {
        int n=10;
        string login[n],password[n];
        fstream objfile;
        fstream objfile1;
        objfile.open("LOGIN.TXT");
        n=0;
        while(!objfile.eof())
        {
            getline(objfile,login[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<login[i]<<endl;
        // }
        objfile.close();
        objfile1.open("PASSWORD.TXT");
        n=0;
        while(!objfile1.eof())
        {
            getline(objfile1,password[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<password[i]<<endl;
        // }
        objfile1.close();
        login_access(login,password,10);

    }
    //pure virtual function......
    virtual void displayHome(void) = 0;

};
// ADMIN CLASS DEFINITION AND ITS INHERITANCE FROM THE PERSON CLASS.
class Admin:protected Person
{
    public:
    // FUNCTION TO DISPLAY OR THE TEACHER INFORMATION ON THE SCREEN TAKING FROM THE FILE.

    void displayTeacherinfo(void)
    {
        //SYNTAX TO CLEAR THE SCREEN IN DIFFERENT OPERATING SYSTEM.
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 


        ifstream teachinfo;
        string teachinfor[20];
        int n=0;
        teachinfo.open("TEACHERINFO.TXT");
        if(!teachinfo.is_open())
        {
            cout<<"ERROR IN OPENING THE TEACHER'S INFORMATION FILE."<<endl;
        }
        while(!teachinfo.eof())
        {
            getline(teachinfo,teachinfor[n]);
            n++;
        }
        teachinfo.close();
        for(int i=0;i<20;i++)
        {
            cout<<teachinfor[i]<<endl;
        }
    }

    // FUNCTION TO DISPLAY THE TEACHERS ATTENDENCE ON THE SCREEN.

    void Teacherattendence(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 
        string attend[20];
        ifstream teachattend;
        teachattend.open("TEACHERATTENDENCE.TXT");
        if(!teachattend.is_open())
        {
            cout<<"ERROR IN OPENING THE TEACHER'S ATTENDENCE FILE."<<endl;
        }
        int n=0;
        while(!teachattend.eof())
        {
            getline(teachattend,attend[n]);
            n++;
        }
        teachattend.close();
        for(int i=0;i<20;i++)
        {
            cout<<attend[i]<<endl;
        }
    }

    // FUNCTION TO PRINT NOTICE ON THE NOTICE FILE FOR THE TEACHERS.

    void writeNotice(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 
        fstream noticefile;
        string dated,notice;
        noticefile.open("NOTICEFILE.TXT",ios::app);
        if(!noticefile.is_open())
        {
            cout<<"ERROR IN OPENING THE TEACHER'S NOTICE FILE."<<endl;
        }
        cout<<"\n\n\n\n";
        cout<<"ENTER THE DATE."<<endl;
        cin>>dated;
        noticefile<<"\n"<<dated<<endl;
        cout<<"ENTER THE NOTICE HERE....."<<endl;
        getline(cin,notice,'|');
        noticefile<<"\n"<<notice<<endl;
        noticefile.close();

    }
    
// FUNCTION TO ADD NEW TEACHER IN THE TEACHER INFORMATION FILE.

    void AddTeacher(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 
        string DE,DEPT,NAME,USERID,SUBJECT,MOBILENO,EMAILID;
        cout<<"FILL THE REQUIRED DATA HERE..."<<endl;
        cout<<"ENTER THE DESIGNATION:"<<endl;
        cin>>DE;
        cout<<"ENTER THE DEPARTMENT:"<<endl;
        cin>>DEPT;
        cout<<"ENTER THE NAME:"<<endl;
        cin>>NAME;
        cout<<"ENTER THE USERID:"<<endl;
        cin>>USERID;
        cout<<"ENTER THE SUBJECT:"<<endl;
        cin>>SUBJECT;
        cout<<"ENTER THE MOBILE NUMBER:"<<endl;
        cin>>MOBILENO;
        cout<<"ENTER THE EMAIL ID:"<<endl;
        cin>>EMAILID;
        ofstream addteach;
        addteach.open("TEACHERINFO.TXT",ios::app);
        if(!addteach.is_open())
        {
            cout<<"ERROR IN OPENING THE TEACHER'S INFORMATION FILE."<<endl;
        }
        addteach<<"\n"<<DE<<"|"<<DEPT<<"\t|"<<NAME<<"\t|"<<USERID<<"\t|"<<SUBJECT<<"\t|"<<MOBILENO<<"\t|"<<EMAILID<<"|";


    }

// FUNCTION TO PRINT THE DEPARTMENT HEAD.

    void DepartmentHead(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 
        ifstream hodfile;
        string hodinp[20];
        hodfile.open("HOD.TXT");
        if(!hodfile.is_open())
        {
            cout<<"ERROR IN OPENING THE HOD FILE."<<endl;
        }
        int n=0;
        while(!hodfile.eof())
        {
            getline(hodfile,hodinp[n]);
            n++;
        }
        for(int i=0;i<20;i++)
        {
            cout<<hodinp[i]<<endl;
        }
    }


    // FUNCTION TO PRINT ALL THE PAY SLIP OF THE TEACHERS.
    void payslip(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
        else
            {
                system("cls");
            } 
        ifstream payslip;
        string pay[20];
        payslip.open("TEACHER PAYSLIP.TXT");
        if(!payslip.is_open())
        {
            cout<<"ERROR IN OPENING THE HOD FILE."<<endl;
        }
        int n=0;
        while(!payslip.eof())
        {
            getline(payslip,pay[n]);
            n++;
        }
        for(int i=0;i<20;i++)
        {
            cout<<pay[i]<<endl;
        }
    }

// FUNCTION TO SET NEW PASSWORD FOR THE DIFFERENT USERS.(AFTER LOGIN ONLY)

    void changePassword(void)
    {
        int n=20;
        string login[n],password[n];
        fstream objfile;
        fstream objfile1;
        objfile.open("LOGINADMIN.TXT");
        n=0;
        while(!objfile.eof())
        {
            getline(objfile,login[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<login[i]<<endl;
        // }
        objfile.close();
        objfile1.open("PASSWORDADMIN.TXT");
        n=0;
        while(!objfile1.eof())
        {
            getline(objfile1,password[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<password[i]<<endl;
        // }
        objfile1.close();
        string name2,password2;
        int c=0;
        cout<<setw(48);
        cout<<"NAME:-";
        cin>>name2;
        label1: cout<<"\n"<<setw(52)<<"NEW PASSWORD:-";
        cin>>password2;
        for(int i=0;i<n;i++)
        {
            if(login[i]==name2)
            {
                c=i;
            }
        }
        password[c] = password2;
        ofstream objfile2;
        objfile2.open("PASSWORDADMIN.TXT");
        for(int i=0;i<n;i++)
        {
            objfile2<<password[i]<<endl;
        }
        objfile2.close();
        cout<<setw(62)<<"PASSWORD CHANGED SUCCESSFULLY."<<endl;
    }
    // LOGIN DISPLAY IS MADE FRIEND FUNCTION TO CALL ITS ATTRIBUTES AND FUNCTIONS.
    friend void logindisplay(Admin a, Teacher t);

    // FUNCTION TO GET THE LOGIN DETAILS FROM THE TEXT FILE AND ENTER ALL THE DATAIN THE ACTIVE PROGRAM.

    void get_login_detail(void)
    {
        int n=10;
        string login[n],password[n];
        fstream objfile;
        fstream objfile1;
        objfile.open("LOGINADMIN.TXT");
        n=0;
        while(!objfile.eof())
        {
            getline(objfile,login[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<login[i]<<endl;
        // }
        objfile.close();
        objfile1.open("PASSWORDADMIN.TXT");
        n=0;
        while(!objfile1.eof())
        {
            getline(objfile1,password[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<password[i]<<endl;
        // }
        objfile1.close();
        login_access(login,password,10);

    }

    // FUNCTION TO DISPLAY THE HOMEPAGE FOR THE ADMIN. WITH THE FULL MENU.

    void displayHome(void)
    {
        label4: if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        cout<<setw(48);
        for(int i=0;i<16;i++)
        {
            cout<<"*";
        }
        cout<<"\n";
        cout<<setw(62)<<"ADMIN HOMEPAGE"<<endl;
        cout<<setw(48);
        for(int i=0;i<16;i++)
        {
            cout<<"*";
        }
        cout<<setw(290)<<__DATE__;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t"<<loggerId;
        cout<<"\n\n\n\n";
        cout<<"\n\t\t\t\t\tCHOOSE FROM THE BELOW OPTIONS."<<endl;
        cout<<"\n\t\t\t\t\t1.TEACHER INFORMATION."<<endl;
        cout<<"\n\t\t\t\t\t2.TEACHER ATTENDENCE."<<endl;
        cout<<"\n\t\t\t\t\t3.WRITE A NOTICE."<<endl;
        cout<<"\n\t\t\t\t\t4.ADD NEW TEACHER."<<endl;
        cout<<"\n\t\t\t\t\t5.DEPARTMENT HEAD."<<endl;
        cout<<"\n\t\t\t\t\t6.TEACHER'S PAYSLIP."<<endl;
        cout<<"\n\t\t\t\t\t7.CHANGE PASSWORD."<<endl;

       
        int opt;
        label2: cout<<"\n"<<setw(40)<<"-";
        cin>>opt;
        char c='A';


        // SWITCH FUNTION TO CHOOSE FROM DIFFERENT OPTIONS FROM THE MENU BAR.


        switch(opt)
        {
            case 1:
                displayTeacherinfo();
                
                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 2:
                Teacherattendence();
    
                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 3:
                writeNotice();
                
                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 4:
                AddTeacher();
                
                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 5:
                DepartmentHead();
                
                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;

                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 6:
                    payslip();

                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label4;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }   
            break;
            case 7:
                    changePassword();
            break;
            default:
            goto label2;

        }
    }
    
};

// TEACHER CLASS INHERITED FROM THE PERSON PURE VIRTUAL CLASS.

class Teacher:protected Person
{
    public:
    
    //LOGIN DISPLAY MADE FRIEND OF TEACHER CLASS TO USE ITS ATTRIBUTES AND FUNCTIONS. 

    friend void logindisplay(Admin a, Teacher t);

    //this function is used to take the data from the login and passsword 
    //file and feed the data in the program.

    void get_login_detail(void)
    {
        int n=10;
        string login[n],password[n];
        fstream objfile;
        fstream objfile1;
        objfile.open("LOGINTEACHER.TXT");
        n=0;
        while(!objfile.eof())
        {
            getline(objfile,login[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<login[i]<<endl;
        // }
        objfile.close();
        objfile1.open("PASSWORDTEACHER.TXT");
        n=0;
        while(!objfile1.eof())
        {
            getline(objfile1,password[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<password[i]<<endl;
        // }
        objfile1.close();
        login_access(login,password,10);

    }

    // FUNCTION TO DISPLAY THE WHOLE STUDENT INFO ON THE SCREEN FROM THE FILE.

    void displayStudentinfo(void)
    {
        
        if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        ifstream studentinfo;
        string studentinp[20];
        studentinfo.open("STUDENTINFO.TXT");
        if(!studentinfo.is_open())
        {
            cout<<"ERROR IN OPENING THE STUDENT INFORMATION FILE."<<endl;
        }
        int n=0;
        while(!studentinfo.eof())
        {
            getline(studentinfo,studentinp[n]);
            n++;
        }
        for(int i=0;i<20;i++)
        {
            cout<<studentinp[i]<<endl;
        }
    }
    
    // FUNCTION TO PRINT ALL THE ATTENDENCE DATA ON THE SCREEN.

    void Studentattendence(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        ifstream studentatten;
        string studatten[20];
        studentatten.open("STUDENTATTENDENCE.TXT");
        if(!studentatten.is_open())
        {
            cout<<"ERROR IN OPENING THE STUDENT ATTENDENCE FILE."<<endl;
        }
        int n=0;
        while(!studentatten.eof())
        {
            getline(studentatten,studatten[n]);
            n++;
        }
        for(int i=0;i<20;i++)
        {
            cout<<studatten[i]<<endl;
        }
    }

    // FUNCTION TO ADD MARKS OF DIFFERENT STUDENT IN THE TEXT FILE 
    // THREE DIFFERENT FILES CAN BE ACCESS DEPENDING ON T1 T2 T3 RESPECTIVELY.

    void Addmarks(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        ofstream studmarks;
        string marks[7];
        int viv=0;
        cout<<"CHOOSE THE EXAM:\n1.T1\t2.T2\t3.T3\n";
        cin>>viv;
        switch(viv)
        {
            case 1:
                studmarks.open("STUDENTMARKS(T1).TXT",ios::app);
                if(!studmarks.is_open())
                {
                    cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
                }
                cout<<"ENTER THE ROLL NO OF THE STUDENT:"<<endl;
                cin>>marks[0];
                cout<<"ENTER THE MARKS OF THE FOLLOWING SUBJECTS:"<<endl;
                cout<<"ENTER THE MARKS IN MATHS:"<<endl;
                cin>>marks[1];
                cout<<"ENTER THE MARKS IN PHYSICS:"<<endl;
                cin>>marks[2];
                cout<<"ENTER THE MARKS IN SOFTWARE DEVELOPMENT FUNDAMENTALS:"<<endl;
                cin>>marks[3];
                cout<<"ENTER THE MARKS IN LIFE SKILLS:"<<endl;
                cin>>marks[4];
                cout<<"ENTER THE MARKS IN ENGLISH:"<<endl;
                cin>>marks[5];
                cout<<"ENTER THE MARKS IN ELECTRICAL SCIENCE:"<<endl;
                cin>>marks[6];
                studmarks<<"\n";
                for(int i=0;i<10;i++)
                {
                    studmarks<<marks[i]<<"\t";
                }
                studmarks.close();
            break;
            case 2:
            studmarks.open("STUDENTMARKS(T2).TXT",ios::app);
                if(!studmarks.is_open())
                {
                    cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
                }
                cout<<"ENTER THE ROLL NO OF THE STUDENT:"<<endl;
                cin>>marks[0];
                cout<<"ENTER THE MARKS OF THE FOLLOWING SUBJECTS:"<<endl;
                cout<<"ENTER THE MARKS IN MATHS:"<<endl;
                cin>>marks[1];
                cout<<"ENTER THE MARKS IN PHYSICS:"<<endl;
                cin>>marks[2];
                cout<<"ENTER THE MARKS IN SOFTWARE DEVELOPMENT FUNDAMENTALS:"<<endl;
                cin>>marks[3];
                cout<<"ENTER THE MARKS IN LIFE SKILLS:"<<endl;
                cin>>marks[4];
                cout<<"ENTER THE MARKS IN ENGLISH:"<<endl;
                cin>>marks[5];
                cout<<"ENTER THE MARKS IN ELECTRICAL SCIENCE:"<<endl;
                cin>>marks[6];
                studmarks<<"\n";
                for(int i=0;i<10;i++)
                {
                    studmarks<<marks[i]<<"\t";
                }
                studmarks.close();
            break;
            case 3:
            studmarks.open("STUDENTMARKS(T3).TXT",ios::app);
                if(!studmarks.is_open())
                {
                    cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
                }
                cout<<"ENTER THE ROLL NO OF THE STUDENT:"<<endl;
                cin>>marks[0];
                cout<<"ENTER THE MARKS OF THE FOLLOWING SUBJECTS:"<<endl;
                cout<<"ENTER THE MARKS IN MATHS:"<<endl;
                cin>>marks[1];
                cout<<"ENTER THE MARKS IN PHYSICS:"<<endl;
                cin>>marks[2];
                cout<<"ENTER THE MARKS IN SOFTWARE DEVELOPMENT FUNDAMENTALS:"<<endl;
                cin>>marks[3];
                cout<<"ENTER THE MARKS IN LIFE SKILLS:"<<endl;
                cin>>marks[4];
                cout<<"ENTER THE MARKS IN ENGLISH:"<<endl;
                cin>>marks[5];
                cout<<"ENTER THE MARKS IN ELECTRICAL SCIENCE:"<<endl;
                cin>>marks[6];
                studmarks<<"\n";
                for(int i=0;i<10;i++)
                {
                    studmarks<<marks[i]<<"\t";
                }
                studmarks.close();
            break;
            default:
            break;

        }
       

    }


    // FUNCTION TO ADD MARKS OF DIFFERENT STUDENT IN THE TEXT FILE 
    // THREE DIFFERENT FILES CAN BE ACCESS DEPENDING ON T1 T2 T3 RESPECTIVELY.

    void PrintStudentMarks(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        cout<<setw(80)<<"ENTER THE EXAM TO PRINT MARKS OBTAINED."<<endl;
        cout<<setw(56)<<"1.T1\t2.T2\t3.T3"<<endl;
        cout<<setw(48)<<"-";
        int g=0;
        cin>>g;
        ifstream marksprint;
        string marksoutput[20];
        int n=0;
        switch(g)
        {
            case 1:
            if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
            cout<<"\n\n\n\n"<<endl;
            marksprint.open("STUDENTMARKS(T1).TXT");
            if(!marksprint.is_open())
            {
                cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
            }
            while(!marksprint.eof())
            {
                getline(marksprint,marksoutput[n]);
                n++;
            }
            marksprint.close();
            for(int i=0;i<20;i++)
            {
                cout<<marksoutput[i]<<endl;
            }

            break;
            case 2:
            if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
            cout<<"\n\n\n\n"<<endl;
            marksprint.open("STUDENTMARKS(T2).TXT");
            if(!marksprint.is_open())
            {
                cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
            }
            while(!marksprint.eof())
            {
                getline(marksprint,marksoutput[n]);
                n++;
            }
            marksprint.close();
            for(int i=0;i<20;i++)
            {
                cout<<marksoutput[i]<<endl;
            }

            break;
            case 3:
            if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
            cout<<"\n\n\n\n"<<endl;
            marksprint.open("STUDENTMARKS(T3).TXT");
            if(!marksprint.is_open())
            {
                cout<<"ERROR IN OPENING THE STUDENT MARKS FILE."<<endl;
            }
            while(!marksprint.eof())
            {
                getline(marksprint,marksoutput[n]);
                n++;
            }
            marksprint.close();
            for(int i=0;i<20;i++)
            {
                cout<<marksoutput[i]<<endl;
            }

            break;
            default:
            break;
        }
    }

    // FUNCTION TO PRINT ALL THE INTERNSHIP DETAILS ON THE OUTPUT SCREEN.

    void IntershipDetails(void)
    {
        if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        ifstream internship;
        string studinter[20];
        internship.open("STUDENTINTERNSHIP.TXT");
        if(!internship.is_open())
        {
            cout<<"ERROR IN OPENING THE STUDENT ATTENDENCE FILE."<<endl;
        }
        int n=0;
        while(!internship.eof())
        {
            getline(internship,studinter[n]);
            n++;
        }
        for(int i=0;i<20;i++)
        {
            cout<<studinter[i]<<endl;
        }
    }

    
    // FUNCTION TO SET NEW PASSWORD FOR THE DIFFERENT USERS.(AFTER LOGIN ONLY)


    void changePassword(void)
    {
        int n=20;
        string login[n],password[n];
        fstream objfile;
        fstream objfile1;
        objfile.open("LOGINTEACHER.TXT");
        n=0;
        while(!objfile.eof())
        {
            getline(objfile,login[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<login[i]<<endl;
        // }
        objfile.close();
        objfile1.open("PASSWORDTEACHER.TXT");
        n=0;
        while(!objfile1.eof())
        {
            getline(objfile1,password[n]);
            n++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<password[i]<<endl;
        // }
        objfile1.close();
        string name2,password2;
        int c=0;
        cout<<setw(48);
        cout<<"NAME:-";
        cin>>name2;
        label1: cout<<"\n"<<setw(52)<<"NEW PASSWORD:-";
        cin>>password2;
        for(int i=0;i<n;i++)
        {
            if(login[i]==name2)
            {
                c=i;
            }
        }
        password[c] = password2;
        ofstream objfile2;
        objfile2.open("PASSWORDTEACHER.TXT");
        for(int i=0;i<n;i++)
        {
            objfile2<<password[i]<<endl;
        }
        objfile2.close();
        cout<<setw(62)<<"PASSWORD CHANGED SUCCESSFULLY."<<endl;
    }

    //FUNCTION TO DISPLAY THE WHOLE TEACHER HOMEPAGE ON THE SCREEN WITH THE MENU BAR TO CHOOSE FROM. 

    void displayHome(void)
    {
        label5: if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
        cout<<setw(48);
        for(int i=0;i<16;i++)
        {
            cout<<"*";
        }
        cout<<"\n";
        cout<<setw(62)<<"TEACHER HOMEPAGE"<<endl;
        cout<<setw(48);
        for(int i=0;i<16;i++)
        {
            cout<<"*";
        }
        cout<<setw(290)<<__DATE__;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t"<<loggerId;
        cout<<"\n\n\n\n";
        cout<<"\n\t\t\t\t\tCHOOSE FROM THE BELOW OPTIONS."<<endl;
        cout<<"\n\t\t\t\t\t1.STUDENT INFORMATION."<<endl;
        cout<<"\n\t\t\t\t\t2.STUDENT ATTENDENCE."<<endl;
        cout<<"\n\t\t\t\t\t3.ADD MARKS FOR STUDENTS."<<endl;
        cout<<"\n\t\t\t\t\t4.PRINT STUDENTS MARKS."<<endl;
        cout<<"\n\t\t\t\t\t5.INTERSHIP DETAILS."<<endl;
        cout<<"\n\t\t\t\t\t6.CHANGE PASSWORD."<<endl;
        int optx;
        char c;
        label3: cout<<"\n"<<setw(40)<<"-";
        cin>>optx;

// SWITCH OPTION TO CALL DIFFERENT FUNCTIONS.

        switch(optx)
        {
            case 1:
                displayStudentinfo();

                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label5;
                }
                
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
                
            break;
            case 2:
                Studentattendence();

                 cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label5;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 3:
                Addmarks();

                 cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label5;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 4:
                PrintStudentMarks();

                cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label5;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 5:
                IntershipDetails();

                 cout<<"PRESS 'Y' OR 'y' TO CONTINUE AGAIN OR 'E' OR 'e' TO EXIT."<<endl;
                cin>>c;
                if(c=='Y' || c=='y')
                {
                    goto label5;
                }
                else
                {
                    if (OS==1||OS==2)
                    {
                        system("clear");
                    }
                    else
                    {
                        system("cls");
                    } 
                    cout<<"\n\n\n";
                    cout<<setw(80)<<"THANK YOU FOR LOGING IN."<<endl;
                    cout<<setw(80)<<"TEAM MEMBERS............"<<endl;
                    cout<<setw(82)<<"1.VIVEK SHAURYA (21803013)"<<endl;
                    cout<<setw(82)<<"2.HARSHIT VIJAY (21803015)"<<endl;
                    cout<<setw(80)<<"3.ANMOL VERMA (21803014)"<<endl;
                    cout<<setw(80)<<"4.ROHIT GUPTA (21803018)"<<endl;
                    cout<<"\n\n\n";
                }
            break;
            case 6:
                    changePassword();
            break;

            default:
            goto label3;

        }
        
    }


};


void logindisplay(Admin a, Teacher t);


// MAIN FUNCTION OF THE PROGRAM.


int main()
{
    Admin objadmin;
    Teacher objteach;
    logindisplay(objadmin,objteach);
    if(option == 0)
    {
        objadmin.displayHome();
    }
    else if(option == 1)
    {
        objteach.displayHome();
    }
    
    

    return 0;
}


// this function diplays the login page and asks user to choose from the admin or teacher option 
// on the basis of that it further calls other funstions.



void logindisplay(Admin a, Teacher t)
{
    if (OS==1||OS==2)
            {
                system("clear");
            }
            else
            {
                system("cls");
            } 
    int x;

    cout<<setw(31);
    for(int i=0;i<45;i++)
    {
        cout<<"*";
    }

    cout<<endl;
    cout<<setw(32);
    cout<<"\t\t\t\tJAYPEE INSTITUTE OF INFORMATION TECHNOLOGY"<<endl;
    cout<<setw(31);

    for(int i=0;i<45;i++)
    {
        cout<<"*";
    }

    cout<<endl<<endl<<endl;
    cout<<setw(32);
    cout<<"\t\t\t\t\tCOLLEGE PORTAL"<<endl;
    cout<<setw(48);

    for(int i=0;i<15;i++)
    {
        cout<<"*";
    }

    cout<<setw(290)<<__DATE__;  
    cout<<endl<<endl;
    cout<<setw(56);
    cout<<"1.ADMIN\t\t2.TEACHER";
    cout<<endl<<endl;
    label: cout<<setw(48)<<"-";
    cin>>x;

    switch(x)
    {
        case 1:
        a.get_login_detail();
        option = 0;
        break;
        case 2:
        t.get_login_detail();
        option = 1;
        break;
        default:
        cout<<setw(48);
        cout<<setw(72)<<"WRONG OPTION CHOOSED, RENTER THE OPTION"<<endl;
        goto label;
        break;
    }

}