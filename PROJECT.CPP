#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<string.h>
#include<stdlib.h>
class student
{
	public:
		char name[36],branch[36];
		int roll,year,sem;
		float cpi;
		static int cnt;
		void setdata(char a[],int b,int c,int d,float e,char f[])
		{
			strcpy(name,a);
			strcpy(branch,f);
			roll=b;
			year=c;
			sem=d;
			cpi=e;
			cnt++;
		}
		void getdata()
		{
			cout<<"\nenter the name: ";
			cin>>name;
			cout<<"\n enter the enrollment no: ";
			cin>>roll;
			cout<<"\n enter the branch: ";
			cin>>branch;
			cout<<"\n enter the year: ";
			cin>>year;
			cout<<"\n enter the sem: ";
			cin>>sem;
			cout<<"\n enter the CPI: ";
			cin>>cpi;
			cnt++;
		}

		void putdata()
		{
			cout<<"\n"<<roll<<"\t\t"<<name<<"\t\t"<<branch<<"\t\t"<<year<<"\t\t"<<sem<<"\t  "<<cpi;
		}
		void operator =(student a)
		{
			roll=a.roll;
			strcpy(name,a.name);
			strcpy(branch,a.branch);
			year=a.year;
			sem=a.sem;
			cpi=a.cpi;
		}


};
int student::cnt=0;
void view_data(student s1[],student s2)
{
	int i;
	cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
	for(i=0;i<s2.cnt;i++)
	{
	s1[i].putdata();
	}
}

void add(student s2,student s[])
{
	s[s2.cnt].getdata();
}

void update(int enr,student s[],student s2)
{
	int i,temp=99;
	for(i=0;i<s2.cnt;i++)
	{
		if(s[i].roll==enr)
		{
			temp=i;
			break;
		}
	}
	if(temp==99)
	{
		cout<<"\nno match found";
	}
	else
	{
		cout<<"\n 1. enroll no 2.name 3.branch 4.year 5.sem 6.cpi ";
		cout<<"\nwhat do u want to update? ";
		cin>>i;
		if(i==1)
		{
			cout<<"enter the new enrollment no: ";
			cin>>s[temp].roll;
		}
		else if(i==2)
		{
			cout<<"enter the new name: ";
			cin>>s[temp].name;
		}
		else if(i==3)
		{
			cout<<"enter the new branch: ";
			cin>>s[temp].branch;
		}
		else if(i==4)
		{
			cout<<"enter the new year: ";
			cin>>s[temp].year;
		}
		else if(i==5)
		{
			cout<<"enter the new sem: ";
			cin>>s[temp].sem;
		}
		else if(i==6)
		{
			cout<<"enter the new cpi: ";
			cin>>s[temp].cpi;
		}
		else
		{
			cout<<"no such field";
		}
	}
}

void sort(student s[],student s2)
{
	int i,j;
	student temp;
	for(i=0;i<s2.cnt;i++)
	{
		for(j=i+1;j<s2.cnt;j++)
		{
			if(s[i].cpi < s[j].cpi)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}


void search_record(student s[],student s2)
{
	int choice,i,temp=99;
	char x[36];
	cout<<" 1.Enroll no\t 2.Name \n 3.branch\t 4.year \n 5.sem\t 6.cpi";
	cout<<"\n what do u want to search: ";
	cin>>choice;
	if(choice==1)
	{
		cout<<"enter the enrollment no: ";
		cin>>choice;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(s[i].roll==choice)
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else if(choice==2)
	{
		cout<<"enter the name: ";
		cin>>x;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(strcmp(x,s[i].name))
			{
				temp=99;
			}
			else
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else if(choice==3)
	{
		cout<<"enter the branch: ";
		cin>>x;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(strcmp(x,s[i].branch))
			{
			}
			else
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else if(choice==4)
	{
		cout<<"enter the year: ";
		cin>>choice;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(s[i].year==choice)
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else if(choice==5)
	{
		cout<<"enter the sem: ";
		cin>>choice;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(s[i].sem==choice)
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else if(choice==6)
	{       float temp2;
		cout<<"enter the cpi: ";
		cin>>temp2;
		cout<<"Enroll No"<<"\t"<<"Name"<<"\t\t"<<"Branch"<<"\t\t"<<"Year"<<"\t\t"<<"Sem"<<"\t  "<<"CPI";
		for(i=0;i<s2.cnt;i++)
		{
			if(s[i].cpi==temp2)
			{
				s[i].putdata();
				temp=1;
			}
		}
		if(temp==99)
		{
			cout<<"no match found";
		}
	}
	else
		cout<<"no such field";
}

int main()
{
	int n;
	student s[15],s2;
	clrscr();
	s[0].setdata("Darshil",101,1,2,8.71,"CO");
	s[1].setdata("Harshil",102,1,1,7.10,"Civil");
	s[2].setdata("Parth",103,2,3,9.13,"TCP");
	s[3].setdata("Dhruti",104,2,4,6.65,"Elec");
	s[4].setdata("Soham",105,3,5,4.44,"Mech");
	s[5].setdata("Yuti",106,3,6,9.65,"CO");
	s[6].setdata("Krish",107,4,7,8.54,"EC");
	s[7].setdata("Ruchir",108,4,8,8.54,"EC");
	cout<<"********************************SUDENTS DATABASE********************************";
	do
	{
		cout<<"\n 1. View \n 2. Add a record \n 3. Update a record \n 4. Sorting on basis of CPI \n 5. Searching a Record \n 6. exit";
		cout<<"\n Enter ur choice: ";
		cin>>n;
		cout<<endl;
		switch(n)
		{
			case 1: view_data(s,s2);
				break;
			case 2: add(s2,s);
				break;
			case 3: int enr;
				cout<<"enter the enrollment no of student u want to update info: ";
				cin>>enr;
				update(enr,s,s2);
				break;
			case 4: sort(s,s2);
				break;
			case 5: search_record(s,s2);
				break;
			case 6: exit(0);
				break;
			default: cout<<"wrong choice";
		}
	}while(n!=999);
	getch();
	return 0;
}
