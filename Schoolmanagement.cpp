#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int cho;
struct stud
{
	char st[10],sname[20],sr[10],sadd[20],sFname[20],sMname[20],sc[10];
	float mm,msc,mss,me,m2,mph,mch,mcs,mb,ma,mec,mpo,mh,mg,tm;
	int cl;
}s;
struct teac
{
	char tname[20],tsub[20],tqua[15],tc[10];
	int tny,tnl;
	float tsal;
}t;
void screen();
void password();
void menu();
class student
{
	char f,uname[20],pass[20],crn[10];
	int i,ch,c;
	public:
	void sinit()
	{
		s.cl=0;
		strcpy(s.st," ");
		strcpy(s.sname,"**********");
		strcpy(s.sFname,"**********");
		strcpy(s.sMname,"**********");
		strcpy(s.sFname,"**********");
		strcpy(s.sadd,"**********");
		strcpy(s.sc,"**********");
		strcpy(s.sr,"**********");
	}
	void screen();
	void password();
	void smenu();
	void newfile();
	void readfile();
	void writefile();
	void sentertable();
	void sentervalue();
	void sselectdisplay();
	void sdisplay();
	void findtext(char crn[]);
	void entermarks();
}os;
class teacher
{
	int c;
	char ch;
	public:
	void tinit()
	{
		t.tsal=0.0;
		t.tny=t.tnl=0;
		strcpy(t.tname,"**********");
		strcpy(t.tc,"**********");
		strcpy(t.tqua,"**********");
		strcpy(t.tsub,"**********");
	}
	void tmenu();
	void tenter();
	void tentervalue();
	void tdisplay();
	void treadfile();
	void tnewfile();
	void twritefile();
}ot;
int main()
{
	student ob;
	password();
	ob.newfile();
	teacher ob1;
	ob1.tnewfile();
	return 0;
}
/*########################################################################################################

						For Displaying Main menu

  ########################################################################################################*/
void menu()
{
	system("CLS");
	cout<<"\n\n\t<><><><><><><><><><><><><><><><>MAIN MENU<><><><><><><><><><><><><><>";
	cout<<"\n\n\t\t\t\t1.STUDENT\n\t\t\t\t2.TEACHER\n\t\t\t\t3.EXIT";
	cout<<"\n\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n\t\t\tEnter Your Choice: ";
	cin>>cho;
	switch(cho)
	{
		case 1:os.smenu();
				 break;
		case 2:ot.tmenu();
				break;
		case 3:exit(0);
				 break;
		default:cout<<"\n\t\t\t\tWRONG CHOICE";
					getch();
					menu();
	}
}
/*########################################################################################################

						For Displaying Teacher's Menu

  ######################################################################################################## */
void teacher::tmenu()
{
	system("CLS");
	cout<<"\n\n\t****************************SELECT*****************************";
	cout<<"\n\n\t\t\t1.Enter Teacher's Details\n\t\t\t2.Display Teacher's Details\n\t\t\t3.Main Menu";
	cout<<"\n\t_________________________________________________________________\n\t\t\tEnter your choice: ";
	cin>>c;
	switch(c)
	{
		case 1:
						 system("CLS");
						 tinit();
						 tenter();
						 tentervalue();
					system("CLS");
					tmenu();
					break;
		case 2:tdisplay();
				 break;
		case 3:menu();
				 break;
		default:cout<<"\n\t\t\tWrong Choice";
					getch();
					tmenu();
	}
}
void teacher::tnewfile()
{
	fstream fout;
	fout.open("teach",ios::out);
	fout.write((char*)&s,sizeof(s));
	fout.close();
}
void teacher::twritefile()
{
	fstream fout;
	fout.open("teach",ios::app|ios::out);
	fout.write((char*)&t,sizeof(t));
	fout.close();
}
void teacher::tenter()     //Teacher's Entry Form
{
	cout<<"\n\t***********************TEACHER DETAILS**************************";
	cout<<"\n\n\t\t\tName:                   "<<setw(10)<<t.tname;
	cout<<"\n\n\t\t\tContact Number:         "<<setw(10)<<t.tc;
	cout<<"\n\n\t\t\tQualification:          "<<setw(10)<<t.tqua;
	cout<<"\n\n\t\t\tSubject:                "<<setw(10)<<t.tsub;
	cout<<"\n\n\t\t\tNumber of Years:        "<<setw(10)<<t.tny;
	cout<<"\n\n\t\t\tNumber of lectures:     "<<setw(10)<<t.tnl;
	cout<<"\n\n\t\t\tSalary:                 "<<setw(10)<<t.tsal;
	cout<<"\n\n*//////////////////////////////////////////////////////////////////////////////*";

}
void teacher::tentervalue()    //For Entering Student's Details
{
	cout<<"\n\n\t\t\tPlease Enter Teacher's Name: ";
	gets(t.tname);
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Contact Number: ";
	gets(t.tc);
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Qualification: ";
	cin>>t.tqua;
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Subject: ";
	gets(t.tsub);
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Number Of Year's Of Service: ";
	cin>>t.tny;
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Number Of Lectures per week: ";
	cin>>t.tnl;
	system("CLS");
	tenter();
	cout<<"\n\n\t\t\tPlease Enter Salary:";
	cin>>t.tsal;
	system("CLS");
	tenter();
	getch();
	twritefile();
	tmenu();
}
void teacher::tdisplay()     //For Reading From The File "teac" And Displaying Teacher's Details
{
	cout<<"\n********";
	system("CLS");
	fstream fin;
	fin.open("teach",ios::in);
	cout<<"\n\t\t                                DISPLAYING";
	cout<<"\n\============================TEACHER'S DATABASE===============================";
	cout<<"\n_____________________________________________________________________________";
	cout<<"\n|Name       |Contact no.|Qualification|Subject   |no.Years|no.lectures|Salary|";
	while(fin.read((char*)&t,sizeof(t)))
	{
		cout<<"\n_____________________________________________________________________________";
		cout<<"\n|"<<setw(11)<<t.tname<<"|"<<setw(11)<<t.tc<<"|"<<setw(13)<<t.tqua<<"|"<<setw(10)<<t.tsub<<"|"<<setw(8)<<t.tny<<"|"<<setw(11)<<t.tnl<<"|"<<setw(6)<<t.tsal<<"|";
		c++;
		if(c%4==0)
		{
			cout<<"\n\t\tDo You Want to Display More(y/n):";
			cin>>ch;
			if(ch=='N'||ch=='n')
			break;
		}
	}
	fin.close();
	tmenu();
}
/*########################################################################################################

					For Displaying Student's Menu

  ######################################################################################################## */
void student::smenu()
{
	system("CLS");
	cout<<"\n\n\t\t\t\tSELECT\n\t_______________________________________________________________";
	cout<<"\n\n\t\t1.Enter Student details\n\t\t2.Display Student details\n\t\t3.Enter Student marks and allocate stream\n\t\t4.Main Menu";
	cout<<"\n\t___________________________________________________________________\n\n\t\t\tEnter Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:	while(1)
					{
						 system("CLS");
						 sinit();
						 sentertable();
						 sentervalue();
						cout<<"Do you want to enter more(y/n): ";
						cin>>f;
						if(f=='n'||f=='N')
						break;
					}
					system("CLS");
					smenu();
					 break;
		case 2:	system("CLS");
					sselectdisplay();
					break;
		case 3:entermarks();
				system("CLS");
				 break;
		case 4:menu();
				 break;
		default:cout<<"\n\t\t\tWrong Choice";
				  getch();
				  smenu();
	}
}
void student::newfile()
{
	fstream fout;
	fout.open("studen",ios::out);
	fout.write((char*)&s,sizeof(s));
	fout.close();
}
void student::readfile()
{
	fstream fin;
	fin.open("studen" ,ios::in);
	fin.read((char*)& s,sizeof(s));
	fin.close();
}
void student::writefile()
{
	fstream fout;
	fout.open("studen",ios::app|ios::out);
	fout.write((char*)& s,sizeof(s));
	fout.close();
}
void student::findtext(char crn[])     //For Finding A Particular Student's Details From File
{
		fstream fin;
	fin.open("studen",ios::in);
	while(fin.read((char*)& s,sizeof(s)))
	{
		if(strcmp(s.sr,crn)==0)
		sentertable();
	}
	fin.close();
}
void student::sentertable()   //Student's Entry Form
{
	cout<<"\n\t***********************STUDENT DETAILS**************************";
	cout<<"\n\n\t\t\tName:                   "<<setw(10)<<s.sname;
	cout<<"\n\n\t\t\tRegistration number:    "<<setw(10)<<s.sr;
	cout<<"\n\n\t\t\tClass:                  "<<setw(10)<<s.cl<<"("<<s.st<<")";
	cout<<"\n\n\t\t\tFather's Name:          "<<setw(10)<<s.sFname;
	cout<<"\n\n\t\t\tMother's Name:          "<<setw(10)<<s.sMname;
	cout<<"\n\n\t\t\tAddress:                "<<setw(10)<<s.sadd;
	cout<<"\n\n\t\t\tContact Number:         "<<setw(10)<<s.sc;
	cout<<"\n\n*//////////////////////////////////////////////////////////////////////////////*";

}
void student::sentervalue()    //For Entering Student's Details
{
	cout<<"\n\n\t\t\tPlease Enter Student's Name: ";
	gets(s.sname);
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Registration Number: ";
	gets(s.sr);
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Class: ";
	cin>>s.cl;
	if(s.cl==11||s.cl==12)
	{
		cout<<"Enter Stream: ";
		cin>>s.st;
	}
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Father's Name: ";
	gets(s.sFname);
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Mother's Name: ";
	gets(s.sMname);
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Address: ";
	gets(s.sadd);
	system("CLS");
	sentertable();
	cout<<"\n\n\t\t\tPlease Enter Contact Number:";
	gets(s.sc);
	system("CLS");
	sentertable();
	writefile();
}
void student::sselectdisplay()      //For Displaying Student's Details
{
	system("CLS");
	cout<<"\n\n\t*******************************SELECT*****************************";
	cout<<"\n\n\n\t\t\t1.Display Details of a Specific Student\n\t\t\t2.Display Students Database\n\t\t\t3.Student's Menu";
	cout<<"\n\n\t******************************************************************\n\n\t\t\tEnter choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1: system("CLS");
				  cout<<"\n\t__________________________________________________________________";
				  do
					{
						cout<<"\n\t\t\tEnter Registration Number of the Student: ";
						cin>>crn;
						cout<<"\n\t__________________________________________________________________";
						cout<<"\n\t\t\t\t DISPLAYING";
						findtext(crn);
						cout<<"\n\t\t\tDo you want to display any other record:(y/n)";
						cin>>f;
					}while(f=='y');
					sselectdisplay();
				  break;
		case 2: system("CLS");
				  cout<<"\t\t\t1.Back\n\t\t\t2.Student's menu";
				  cout<<"\n*******************************STUDENT DATABASE*********************************";
				  cout<<"\n_______________________________________________________________________________";
				  cout<<"\n|Rno|Name         |Father's Name|Mother's Name|Address        |Contact no|Class|";
					sdisplay();
				  cout<<"\t\t\tEnter Choice: ";
				  cin>>c;
				  switch(c)
				  {
						case 1:sselectdisplay();
								break;
					  case 2:smenu();
								break;
					  default:cout<<"\n\t\t\tWrong Choice";
					  getch();
					  sselectdisplay();
				  }
				  break;
		case 3: smenu();
				  break;
		default:cout<<"\n\n\t\t\tWrong Choice";
					getch();
					sselectdisplay();
	}
}
void student::sdisplay()     //For Displaying Student's Database
{
	c=0;
	fstream fin;
	fin.open("studen",ios::in);
	while(fin.read((char*)& s,sizeof(s)))
	{
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n|"<<setw(3)<<s.sr<<"|"<<setw(15)<<s.sname<<"|"<<setw(13)<<s.sFname<<"|"<<setw(13)<<s.sMname<<"|"<<setw(13)<<s.sadd<<"|"<<setw(10)<<s.sc<<"|"<<setw(2)<<s.cl<<"|";
		c++;
		if(c%4==0)
		{
			cout<<"\nDo you want to display more(y/n): ";
			cin>>f;
			if(f=='n'||f=='N')
			break;
		}
	}
	fin.close();
}
void student::entermarks()    //For Entering Marks And Allocating Stream
{
	system("CLS");
	cout<<"\n\t\t\tEnter student's registration number:";
	cin>>crn;
		fstream fin;
	fin.open("studen",ios::in);
	while(fin.read((char*)& s,sizeof(s)))
	{
		if(strcmp(s.sr,crn)==0)
		{
			break;
		}
	}
	cout<<"\n\n\t***************************ENTER MARKS*****************************";
	if(s.cl>=1&&s.cl<=10)
	{
		cout<<"\n\n\t\t\tMathematics:    ";
		cin>>s.mm;
		cout<<"\t\t\tScience:        ";
		cin>>s.msc;
		cout<<"\t\t\tEnglish:        ";
		cin>>s.me;
		cout<<"\t\t\t2nd Language:   ";
		cin>>s.m2;
		cout<<"\t\t\tSocial Science: ";
		cin>>s.mss;
	}
	else if(s.cl==11||s.cl==12)
	{
		if(strcmp(s.st,"Science")==0)
		{
			cout<<"\n\n\t\t\tPhysics:          ";
			cin>>s.mph;
			cout<<"\t\t\tChemistry:        ";
			cin>>s.mch;
			cout<<"\t\t\tEnglish           ";
			cin>>s.me;
			cout<<"\t\t\tMathematics:      ";
			cin>>s.mm;
			cout<<"\t\t\tComputer Science: ";
			cin>>s.mcs;
		}
		else if(strcmp(s.st,"Commerce")==0)
		{
			cout<<"\n\n\t\t\tBusiness Studies: ";
			cin>>s.mb;
			cout<<"\t\t\tEconomics:        ";
			cin>>s.mec;
			cout<<"\t\t\tEnglish:          ";
			cin>>s.me;
			cout<<"\t\t\tMathematics:      ";
			cin>>s.mm;
			cout<<"\t\t\tAccountancy       ";
			cin>>s.ma;
		}
		else
		{
			cout<<"\n\n\t\t\tGeography:         ";
			cin>>s.mg;
			cout<<"\t\t\tPolitical Science: ";
			cin>>s.mpo;
			cout<<"\t\t\tHistory:           ";
			cin>>s.mh;
			cout<<"\t\t\tEnglish:           ";
			cin>>s.me;
			cout<<"\t\t\t2nd Language:      ";
			cin>>s.m2;
		}
	}
	cout<<"\n\n\t\t\tTotal Percentage: ";      //Calculating Total Percentage
	if(s.cl>=1&&s.cl<=10)
	{
		s.tm=(s.mm+s.msc+s.mss+s.me+s.m2)/5;
	}
	else if(s.cl==11||s.cl==12)
	{
		if(strcmp(s.st,"Science")==0)
		{
			s.tm=(s.mph+s.mch+s.me+s.mm+s.mcs)/5;
		}
		else if(strcmp(s.st,"Commerce")==0)
		{
			s.tm=(s.mb+s.mec+s.ma+s.me+s.mm)/5;
		}
		else
		{
			s.tm=(s.mg+s.mpo+s.me+s.mh+s.m2)/5;
		}
	}
	cout<<s.tm<<"%";
	getch();
			if(s.cl==11||s.cl==12)
			{
				cout<<"\n\t\t\tStream is already selected: "<<s.st;
				getch();
				smenu();
			}
			else
{
	if(s.tm>=80)
	{
		strcpy(s.st,"Science");
	}
	else if(s.tm>=60&&s.tm<80)
	{
		strcpy(s.st,"Commerce");
	}
	else
	{
		strcpy(s.st,"Arts");
	}
	cout<<"\n\t\t\tStream Allocated: "<<s.st;
	getch();
	smenu();
}
}
void password()      //For Checking Access
{
	int c,i;
	char uname[20],pass[10];
	screen();
	c=0;
	cout<<"\n\n\t\t\tEnter Username:  ";
	cin>>uname;
	if(strcmp(uname,"neha")!=0)
	{
		cout<<"\n\n\t\t\tACCESS NOT ALLOWED";
		getch();
		system("CLS");
		password();
	}
	else
	{
		do
		{
			if(c++==3)
			exit(0);
			system("CLS");
			screen();
			cout<<"\n\n\t\t\tEnter Password:  ";
			for(i=0;i<10;i++)
			{
				pass[i]=getch();
				if(int(pass[i])==13)
				{
				pass[i]='\0';
				break;
				}
				putch('*');
			}
			if(strcmp(pass,"neha")==0)
			{
				system("CLS");
				menu();
			}
			else
			{
					cout<<"\n\n\t\t\tIncorrect Password";
					getch();
			}
		}while(strcmp(pass,"neha")!=0);
	}
}
void screen()      //Main Screen
{
	cout<<"\n\n\n\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * *";
	cout<<"\n\t\t*\t                                     \t*";
	cout<<"\n\t\t*\t###################################\t*";
	cout<<"\n\t\t*\t###################################\t*";
	cout<<"\n\t\t*\t##                               ##\t*";
	cout<<"\n\t\t*\t##\t    WELCOME TO           ##\t*";
	cout<<"\n\t\t*\t##\tSCHOOL MANAGEMENT\t ##\t*";
	cout<<"\n\t\t*\t##                               ##\t*";
	cout<<"\n\t\t*\t###################################\t*";
	cout<<"\n\t\t*\t###################################\t*";
	cout<<"\n\t\t*\t                                     \t*";
	cout<<"\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * *";
}
