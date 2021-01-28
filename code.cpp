#include<iostream.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>

void master_menu();
void transaction_menu();
void activity_master();
void coach_master();
void member_master();
void tran_indata();



struct DATE
{
   int dd,mm,yy;
};

class activity
{
 private:
    int activity_num;
    char activity_name[20];
    int fees;
    int time;

 public:
    void input_act(int k)
    {
	activity_num=k;
	cout<<"\nActivity number:"<<activity_num;
	cout<<"\nEnter activity name:";
	gets(activity_name);
	cout<<"\nActivity fees:";
	cin>>fees;
	cout<<"\nActivity time in hours :";
	cin>>time;
    }
    void outdata()
    {
	cout<<"\nActivity Number:"<<activity_num;
	cout<<"\nActivity name:"<<activity_name;
	cout<<"\nActivity fees:"<<fees;
	cout<<"\nActivity time in hours :"<<time;
    }
    friend void activity_list();
    friend void search_activity(char[]);
    friend void modify_activity(char[]);
    friend activity search_activity(int);
    friend void  tran_indata();

};
void activity_list()
{
   fstream f;
   activity a;
   f.open("activity.dat",ios::in | ios::binary);
   int k;
   if(!f)
   k=1;
   else
   {
	long int t=sizeof(activity);
	f.seekg(-t,ios::end);
	f.read((char*)&a,sizeof(a));
	k=a.activity_num +1;
   }
    f.close();
    f.open("activity.dat",ios::app | ios::binary);
    a.input_act(k);
    f.write((char*)&a,sizeof(a));
    f.close();
    getch();

}

  void display_activity()
 {
    fstream f;
    activity a;
    f.open("activity.dat",ios::in|ios::binary);
    f.read((char*)&a,sizeof(a));
    while(!f.eof())
    {
       a.outdata();
       getch();
       f.read((char*)&a,sizeof(a));
    }
    f.close();
 }
  void search_activity(char nm[])
 {
    fstream f;
    int flag=0;
    activity a;
    f.open("activity.dat",ios::in|ios::binary);
    f.read((char*)&a,sizeof(a));
    while(!f.eof())
    {
       if(strcmpi(a.activity_name,nm)==0)
       {  flag=1;
	  a.outdata();
	  break;
       }
       f.read((char*)&a,sizeof(a));
    }
    f.close();
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }
 activity search_activity(int a1)
 {
    fstream f;
    int flag=0;
    activity a;
    f.open("activity.dat",ios::in|ios::binary);
    f.read((char*)&a,sizeof(a));
    while(!f.eof())
    {
       if(a.activity_num == a1)
       {  flag=1;
	  a.outdata();
	  break;
       }
       f.read((char*)&a,sizeof(a));
    }
    f.close();
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
     return a;
 }
 void modify_activity(char nm[])
 {
    fstream f,f1;
    int flag=0;
    char choice;
    activity a;
    f.open("activity.dat",ios::in|ios::binary);
    f1.open("alter.dat", ios::out|ios::binary);
    f.read((char*)&a,sizeof(a));
    while(!f.eof())
    {
       if(strcmpi(a.activity_name,nm)==0)
       {  flag=1;
	  cout<<"\nDo you want to modify activity Name (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter activity Name:";
	      gets(a.activity_name);
	  }

	  cout<<"\nDo you want to modify activuty fees (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'||choice=='y')
	  {
	      cout<<"\nEnter Fees :";
	      cin>>a.fees;
	  }
	  cout<<"\nDo you want to modify activity time (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Enter Time in hours:";
	      cin>>a.time;
	  }

       }
       f1.write((char*)&a,sizeof(a));
       f.read((char*)&a,sizeof(a));
    }
    f.close();
    f1.close();
    remove("activity.dat");
    rename("alter.dat","activity.dat");
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }




class coach
{
    int coachid;
    char coach_name[20];
    long int contact;
    char address[20];
    char email[20];
    char game[20];


  public:
    void coachinfo(int k)
     {
	coachid=k;
	cout<<"\nCoach ID:"<<coachid;
	cout<<"\nEnter coach name:";
	gets(coach_name);
	cout<<"\nEnter contact number:";
	cin>>contact;
	cout<<"\nEnter address:";
	gets(address);
	cout<<"\nEnter email id:";
	gets(email);
	cout<<"\nEnter game:";
	gets(game);

    }
    void putdata()
    {
	cout<<"\nCoach Id:"<<coachid;
	cout<<"\nCoach Name:"<<coach_name;
	cout<<"\nContact Number:"<<contact;
	cout<<"\nAddress :"<<address;
	cout<<"\nEmail id:"<<email;
	cout<<"\nGame:"<<game;

    }
     friend void add_coach_file();
     friend void search_coach(char[]);
     friend void modify_coach(char[]);

};
void add_coach_file()
{
    fstream f;
    coach c;
    f.open("coach.dat",ios::in|ios::binary);
    int k;
    if(!f)
      k=1;
    else
    {
       long int t=sizeof(coach);
       f.seekg(-t,ios::end);
       f.read((char*)&c,sizeof(c));
       k=c.coachid+1;
    }
    f.close();
    f.open("coach.dat",ios::app|ios::binary);
    c.coachinfo(k);
    f.write((char*)&c,sizeof(c));
    f.close();
    getch();
  }

  void display_coach()
 {
    fstream f;
    coach c;
    f.open("coach.dat",ios::in|ios::binary);
    f.read((char*)&c,sizeof(c));
    while(!f.eof())
    {
       c.putdata();
       getch();
       f.read((char*)&c,sizeof(c));
    }
    f.close();
 }
 void search_coach(char nm[])
 {
    fstream f;
    int flag=0;
    coach c;
    f.open("coach.dat",ios::in|ios::binary);
    f.read((char*)&c,sizeof(c));
    while(!f.eof())
    {
       if(strcmpi(c.coach_name,nm)==0)
       {  flag=1;
	  c.putdata();
	  break;
       }
       f.read((char*)&c,sizeof(c));
    }
    f.close();
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }
 void modify_coach(char nm[])
 {
    fstream f,f1;
    int flag=0;
    char choice;
    coach c;
    f.open("coach.dat",ios::in|ios::binary);
    f1.open("secondary.dat", ios::out|ios::binary);
    f.read((char*)&c,sizeof(c));
    while(!f.eof())
    {
       if(strcmpi(c.coach_name,nm)==0)
       {  flag=1;
	  cout<<"\nDo you want to modify Name (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Name:";
	      gets(c.coach_name);
	  }
	  cout<<"\nDo you want to modify game (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y' ||choice=='y')
	  {
	      cout<<"\nEnter Game :";
	      gets(c.game);
	  }
	  cout<<"\nDo you want to modify address (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'||choice=='y')
	  {
	      cout<<"\nEnter Address :";
	      gets(c.address);
	  }
	  cout<<"\nDo you want to modify Contact Number (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Phone Number:";
	      cin>>c.contact;
	  }
	  cout<<"\nDo you want to modify Email Id (Y/N):";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Email ID:";
	      gets(c.email);
	  }



       }
       f1.write((char*)&c,sizeof(c));
       f.read((char*)&c,sizeof(c));
    }
    f.close();
    f1.close();
    remove("coach.dat");
    rename("secondary.dat","coach.dat");
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }



class members
{
    char gender;
    int mem_id;
    char name[20];

    char address[20];
    long int phone;
    char email[30];
    int activity_no;
    DATE do_joining;

  public:
    void indata(int mem)
    {
	mem_id=mem;
	cout<<"Member_id : "<<mem_id;
	cout<<"\nEnter name :";
	gets(name);
	cout<<"\nEnter Gender :";
	cin>>gender;
	cout<<"\nEnter contact number :";
	cin>>phone;
	cout<<"\nEnter address :";
	gets(address);
	cout<<"\nEnter email id :";
	gets(email);
	cout<<"\nEnter activity number :";
	cin>>activity_no;
	cout<<"\nEnter date of joining(d/m/y) :";
	cin>>do_joining.dd>>do_joining.mm>>do_joining.yy;
     }
     void mem_putdata()
     {
	cout<<"\n\nMember_id:"<<mem_id;
	cout<<"\nName:"<<name;
	cout<<"\nGender:"<<gender;
	cout<<"\nContact Number:"<<phone;
	cout<<"\nAddress:"<<address;
	cout<<"\nEmail-id:"<<email;
	cout<<"\nActivity Number :"<<activity_no;
	cout<<"\nDate of Joining:"<<do_joining.dd<<"/"<<do_joining.mm<<"/"<<do_joining.yy;
     }
     friend void add_member_file();
     friend void search_member(char[]);
     friend void modify_member(char[]);
     friend members search_member(int);
     friend void  tran_indata();
};
void add_member_file()
{
    fstream f;
    members m;
    f.open("members.dat",ios::in|ios::binary);
    int k;
    if(!f)
      k=1;
    else
    {
       long int t=sizeof(members);
       f.seekg(-t,ios::end);
       f.read((char*)&m,sizeof(m));
       k=m.mem_id+1;
    }
    f.close();
    f.open("members.dat",ios::app|ios::binary);
    m.indata(k);
    f.write((char*)&m,sizeof(m));
    f.close();
    getch();
  }

  void display_member()
 {
    fstream f;
    members m;
    f.open("members.dat",ios::in|ios::binary);
    f.read((char*)&m,sizeof(m));
    while(!f.eof())
    {
       m.mem_putdata();
       getch();
       f.read((char*)&m,sizeof(m));
    }
    f.close();
 }
 void search_member(char nm[])
 {
    fstream f;
    int flag=0;
    members m;
    f.open("members.dat",ios::in|ios::binary);
    f.read((char*)&m,sizeof(m));
    while(!f.eof())
    {
       if(strcmpi(m.name,nm)==0)
       {  flag=1;
	  m.mem_putdata();
	  break;
       }
       f.read((char*)&m,sizeof(m));
    }
    f.close();
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }
 members search_member(int memid)
 {
    fstream f;
    int flag=0;
    members m;
    f.open("members.dat",ios::in|ios::binary);
    f.read((char*)&m,sizeof(m));
    while(!f.eof())
    {
       if(m.mem_id== memid)
       {  flag=1;
	  m.mem_putdata();
	  break;
       }
       f.read((char*)&m,sizeof(m));
    }
    f.close();
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
     return m;
 }
 void modify_member(char nm[])
 {
    fstream f,f1;
    int flag=0;
    char choice;
    members m;
    f.open("members.dat",ios::in|ios::binary);
    f1.open("Temp.dat", ios::out|ios::binary);
    f.read((char*)&m,sizeof(m));
    while(!f.eof())
    {
       if(strcmpi(m.name,nm)==0)
       {  flag=1;
	  cout<<"\nDo you want to modify Name (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Name:";
	      gets(m.name);
	  }
	  cout<<"\nDo you want to modify gender (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y' ||choice=='y')
	  {
	      cout<<"\nEnter Gender :";
	      cin>>m.gender;
	  }
	  cout<<"\nDo you want to modify address (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'||choice=='y')
	  {
	      cout<<"\nEnter Address :";
	      gets(m.address);
	  }
	  cout<<"\nDo you want to modify Contact Number (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Phone Number:";
	      cin>>m.phone;
	  }
	  cout<<"\nDo you want to modify Email Id (Y/N):";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Email ID:";
	      gets(m.email);
	  }
	  cout<<"\nDo you want to modify Activity Number (Y/N) :";
	  cin>>choice;
	  if(choice == 'Y'|| choice =='y')
	  {
	      cout<<"\nEnter Activity Number:";
	      cin>>m.activity_no;
	  }



       }
       f1.write((char*)&m,sizeof(m));
       f.read((char*)&m,sizeof(m));
    }
    f.close();
    f1.close();
    remove("members.dat");
    rename("temp.dat","members.dat");
    if(flag==0)
	cout<<"NOT FOUND";
     getch();
 }

void main()
{
   clrscr();
   int choice;
   char ch='y';
   while(ch=='y')
   {
       clrscr();
       cout<<"MAIN MENU "<<endl;
       cout<<"\n 1. Master Menu ";
       cout<<"\n 2. Transaction Menu";
       cout<<"\n 3. to exit"<<endl;
       cout<<"Enter your choice:"<<endl;
       cin>>choice;
       switch(choice)
       {
	 case 1: master_menu();
		 break;
	 case 2: transaction_menu();
		  break;
	 case 3: cout<<"BYE";
		 getch();
		 exit(0);
	  default: cout<<"Wrong choice"<<endl;
       }
       cout<<"\n\n\nDo you want to continue(y/n) : ";
       ch=getch();
   }
}

 void master_menu()
 {
    int choice;
     clrscr();
       cout<<" MASTER MENU "<<endl;
       cout<<"\n1. Activity Master Menu";
       cout<<"\n2. Coach Master Menu";
       cout<<"\n3. Member Master Menu";
       cout<<"\n4. Go Back";
       cout<<"\nEnter your choice:"<<endl;
       cin>>choice;
       switch(choice)
       {
	 case 1: activity_master();
		 break;
	 case 2: coach_master();
		  break;
	 case 3: member_master();
		 break;
	 case 4 : break;
	 default: cout<<"\n\nWrong choice"<<endl;
       }


 }
 class transaction
 {
	int mem_id;
	int act_id;
	int fees;
	DATE dt_payment;
	int interval;
	DATE dt_duedate;
     public:
       friend void tran_indata();
       friend void tran_display();
       friend void tran_search_member(int);
       friend void tran_search_activity(int);
 };
 DATE nextdate(DATE d1, int k)
 {
     DATE d2;

     if(k==1)
     {	d2=d1;
	d2.yy++;
     }
     else if(k==2)
     {  d2=d1;
	d2.mm=d1.mm+6;
	if(d2.mm>=13)
	{
	   d2.mm=d2.mm-12;
	   d2.yy++;
	}
     }
     else if(k==3)
     {  d2=d1;
	d2.mm=d1.mm+3;
	if(d2.mm>=13)
	{
	   d2.mm=d2.mm-12;
	   d2.yy++;
	}
    }
   return d2;
 }
 void tran_indata()
 {
      transaction t;
      cout<<"\nEnter Member id :";
      cin>>t.mem_id;
      members M = search_member(t.mem_id);
      t.act_id= M.activity_no;
      cout<<"\nYour Activity is : ";
      activity A=search_activity(t.act_id);
      struct date D;
      getdate(&D);
      t.dt_payment.dd=D.da_day;
      t.dt_payment.mm=D.da_mon;
      t.dt_payment.yy=D.da_year;
      cout<<"\nTotal Yearly Fees  :  "<<A.fees;
      cout<<"\nPayment Interval  (1. Yearly  2. Half Yearly 3. Quarterly ) :";
      cin>>t.interval;
      t.fees=A.fees;
      if(t.interval == 2)
	  t.fees = t.fees/2+100;
      else if(t.interval == 3)
	  t.fees = t.fees/4+150;
      cout<<"\nPayable Amount = "<<t.fees;
      t.dt_duedate=nextdate(t.dt_payment,t.interval);
      cout<<"\nNext Due Date of Fees Payment :";
      cout<<t.dt_duedate.dd<<"/"<<t.dt_duedate.mm<<"/"<<t.dt_duedate.yy;
      fstream ft;
      ft.open("transaction.dat",ios::app|ios::binary);
      ft.write((char*)&t,sizeof(t));
      ft.close();
 }
 void tran_display()
 {
      fstream ft;
      transaction t;
      ft.open("transaction.dat",ios::in|ios::binary);
      ft.read((char*)&t,sizeof(t));
      cout<<"\nMember ID\tActivity ID\tFEES\tPAYMENT DATE\tINTERVAL\tDUE DATE";
      while(!ft.eof())
      {
	 cout<<"\n"<<t.mem_id<<"\t\t"<<t.act_id<<"\t\t"<<t.fees;
	 cout<<"\t"<<t.dt_payment.dd<<"/"<<t.dt_payment.mm<<"/"<<t.dt_payment.yy;
	 cout<<"\t"<<t.interval;
	 cout<<"\t"<<t.dt_duedate.dd<<"/"<<t.dt_duedate.mm<<"/"<<t.dt_duedate.yy;

	  ft.read((char*)&t,sizeof(t));
      }
      getch();
      ft.close();
 }
  void tran_search_member(int memid)
  {
      fstream ft;
      transaction t;
      ft.open("transaction.dat",ios::in|ios::binary);
      ft.read((char*)&t,sizeof(t));
      cout<<"\nMember ID\tActivity ID\tFEES\tPAYMENT DATE\tINTERVAL\tDUE DATE";
      while(!ft.eof())
      {
	 if(t.mem_id==memid)
	 {
	    cout<<"\n"<<t.mem_id<<"\t\t"<<t.act_id<<"\t\t"<<t.fees;
	    cout<<"\t"<<t.dt_payment.dd<<"/"<<t.dt_payment.mm<<"/"<<t.dt_payment.yy;
	    cout<<"\t"<<t.interval;
	    cout<<"\t"<<t.dt_duedate.dd<<"/"<<t.dt_duedate.mm<<"/"<<t.dt_duedate.yy;
	  }
	  ft.read((char*)&t,sizeof(t));
      }
      getch();
      ft.close();

  }
  void tran_search_activity(int actid)
 {
      fstream ft;
      transaction t;
      ft.open("transaction.dat",ios::in|ios::binary);
      ft.read((char*)&t,sizeof(t));
      cout<<"\nMember ID\tActivity ID\tFEES\tPAYMENT DATE\tINTERVAL\tDUE DATE";
      while(!ft.eof())
      {
	 if(t.act_id==actid)
	 {
	    cout<<"\n"<<t.mem_id<<"\t\t"<<t.act_id<<"\t\t"<<t.fees;
	    cout<<"\t"<<t.dt_payment.dd<<"/"<<t.dt_payment.mm<<"/"<<t.dt_payment.yy;
	    cout<<"\t"<<t.interval;
	    cout<<"\t"<<t.dt_duedate.dd<<"/"<<t.dt_duedate.mm<<"/"<<t.dt_duedate.yy;
	  }
	  ft.read((char*)&t,sizeof(t));
      }
      getch();
      ft.close();
 }

 void transaction_menu()
 {
       clrscr();
       int choice;
       cout<<"  MASTER MENU "<<endl;
       cout<<"\n1. Add a Transaction";
       cout<<"\n2. Display all Transactions ";
       cout<<"\n3. Search Transaction by member id";
       cout<<"\n4. Search Transaction by activity id";
       cout<<"\n5. Go Back";
       cout<<"\n\n Enter your choice:"<<endl;
       cin>>choice;
       int id;
       switch(choice)
       {
	 case 1: tran_indata();
		 break;
	 case 2: tran_display();
		  break;
	 case 3: cout<<"enter activity id :";
		 cin>>id;
		 tran_search_member(id);
		 break;
	 case 4: cout<<"enter activity id :";
		 cin>>id;
		 tran_search_activity(id);
		 break;
	 case 5 : break;
	 default: cout<<"\n\n Wrong choice"<<endl;
       }


 }
 void activity_master()
 {
       char nam[20];
       int choice;
       clrscr();
       cout<<" ACTIVITY MASTER MENU "<<endl;
       cout<<"\n1. Add a activity";
       cout<<"\n2. Display all activities";
       cout<<"\n3. Search Activity by name";
       cout<<"\n4. Modify Activity Record";
       cout<<"\n5. Go Back";
       cout<<"\n\n Enter your choice:"<<endl;
       cin>>choice;
       switch(choice)
       {
	 case 1: activity_list();
		 break;
	 case 2: display_activity();
		  break;
	 case 3: cout<<"\n Enter activity to be searched :";
		 gets(nam);
		 search_activity(nam);
		 break;
	 case 4: cout<<"\n Enter activity to be searched :";
		 gets(nam);
		 modify_activity(nam);
		 break;
	 case 5 : break;
	 default: cout<<"\n\n Wrong choice"<<endl;
       }
 }
 void coach_master()
 {
	char nam[20];
       int choice;
       clrscr();
       cout<<" COACH MASTER MENU "<<endl;
       cout<<"\n1. Add Coach Information";
       cout<<"\n2. Display Information of Coaches";
       cout<<"\n3. Search a Coach by name";
       cout<<"\n4. Modify Coach Record";
       cout<<"\n5. Go Back";
       cout<<"\n\n Enter your choice:"<<endl;
       cin>>choice;
       switch(choice)
       {
	 case 1: add_coach_file();
		 break;
	 case 2: display_coach();
		  break;
	 case 3: cout<<"\n Enter name to be searched :";
		 gets(nam);
		 search_coach(nam);
		 break;
	 case 4: cout<<"\n Enter name to be searched :";
		 gets(nam);
		 modify_coach(nam);
		 break;
	 case 5 : break;
	 default: cout<<"\n\n Wrong choice"<<endl;
       }


 }


 void member_master()
 {
       char nam[20];
       int choice;
       clrscr();
       cout<<" MEMBER MASTER MENU "<<endl;
       cout<<"\n1. Add a Member";
       cout<<"\n2. Display all Member";
       cout<<"\n3. Search a Member by name";
       cout<<"\n4. Modify Member Record";
       cout<<"\n5. Go Back";
       cout<<"\n\n Enter your choice:"<<endl;
       cin>>choice;
       switch(choice)
       {
	 case 1: add_member_file();
		 break;
	 case 2: display_member();
		  break;
	 case 3: cout<<"\n Enter name to be searched :";
		 gets(nam);
		 search_member(nam);
		 break;
	 case 4: cout<<"\n Enter name to be searched :";
		 gets(nam);
		 modify_member(nam);
		 break;
	 case 5 : break;
	 default: cout<<"\n\n Wrong choice"<<endl;
       }


 }

