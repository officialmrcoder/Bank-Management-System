#include<iostream> // input output stream library
#include<fstream> // file handling library
#include<windows.h> // gotoxy and control library
#include<conio.h> // output library
#include<cstring> // string library
using namespace std;
const int max1=100; //constant number value is 100.
const char filename[]="accounts.txt"; // This file to store data accounts.txt.
// All Functions decalred.
void gotoxy(int x, int y);  // cursor control
void fileload(int[],char[][100],double[],int &x); 
// load file in funtion.
void savefile(int[],char[][100],double[],int);
// save file in accounts.txt
void createacc(int[],char[][100],double[],int &);
// user display create account
void display(int[],char[][100],double[],int);
void deposit(int[],char[][100],double[],int);
// Deposit money function
void withdraw(int[],char[][100],double[],int);
// withdraw money function
void balanceacc(int[],double[],int);
// check balance in account
void list(int[],char[][100],double[],int);
// check how many accounts exists.
void deleteacc(int[],char[][100],double[],int &);
// delete account
void Rubric();
// show rubric 
// Move cursor on desired coordinates on the output
void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// main function 
int main() 
{
    int accno[max1];
    char name[max1][100];
    double balance[max1];
    int count=0;
    int choice=-1;
    fileload(accno,name,balance,count);
    system("color 0A"); 
    // Green text on black background
    while(choice!=8)
	 {
	     // show Bank Management System on console and list all points.
        system("cls");
        gotoxy(30,2); 
        {
		cout<<"==============================";
		}
        gotoxy(30,3); 
        {
		cout<<"    BANK MANAGEMENT SYSTEM    ";
		}
        gotoxy(30,4); 
        {
		cout<<"==============================";
		}
        gotoxy(30,5);
		{ 
		cout<<"1. Create Account";
		}
        gotoxy(30,6); 
        {
		cout<<"2. Display Account Details";
		}
        gotoxy(30,7); 
        {
		cout<<"3. Deposit Money";
		}
        gotoxy(30,8); 
        {
		cout<<"4. Withdraw Money";
		}
        gotoxy(30,9); 
        {
		cout<<"5. Check Balance";
		}
        gotoxy(30,10);
        {
		 cout<<"6. List All Accounts";
		}
        gotoxy(30,11); 
        {
		cout<<"7. Delete Account";
		}
        gotoxy(30,12); 
        {
		cout<<"8. Exit";
		}
        gotoxy(30,13);
        {
		 cout<<"9. Show Project Rubric";
		}
        gotoxy(30,14); 
        {
		cout<<"Enter your choice: ";
		}
        cin>>choice;
        system("cls");
        // User choose option in 1 to 9 to procesed further details
        if(choice==1)
        {
		 createacc(accno,name,balance,count);
		}
        else if(choice==2) 
        {
          display(accno,name,balance,count);
		}
        else if(choice==3)
		{
		  deposit(accno,name,balance,count);	
		} 
        else if(choice==4)
        {
          withdraw(accno,name,balance,count);	
		}
        else if(choice==5)
        {
          balanceacc(accno,balance,count);	
		}
        else if(choice==6)
        {
          list(accno,name,balance,count);	
		}
        else if(choice==7)
		{
		  deleteacc(accno,name,balance,count);	
		} 
        else if(choice==8)
        {
          gotoxy(30, 7),
		  cout<<"Exiting system...";	
		}
        else if(choice==9)
        {
          Rubric();	
		}
        else
		 gotoxy(30,17),
		 cout<<"Invalid choice! Please try again.";
        if(choice!=8 && choice!=9)
		{
            gotoxy(30,19);
            system("pause");
        }
    }
    return 0;
}
// load data from file
void fileload(int accno[],char name[][100],double balance[],int &count) 
{
    // file handling
    fstream file(filename, ios::in);
    if(!file) 
	return;
    while(file>>accno[count])
	{
        file.ignore();
        file.getline(name[count],100,'|');
        file>>balance[count];
        file.ignore();
        count++;
    }
    file.close();
}
// Save data in file (accounts.txt)
void savefile(int accno[],char name[][100],double balance[],int count) 
{
    // file handling
    fstream file(filename, ios::out);
    for(int i=0; i<count; i++)
	{
        file<<accno[i]<<" "<<name[i]<<"|"<<balance[i]<<endl;
    }
    file.close();
}
// Function to create account.
void createacc(int accno[],char name[][100],double balance[],int &count) 
{
    if(count<max1) 
	{
	    // cout use to display statements
        accno[count]=(count==0)?1:accno[count-1]+1;
        cout<<"\nEnter your name: ";
        cin.ignore();
        cin.getline(name[count],100);
        cout<<"Enter opening balance: ";
        cin>>balance[count];
        cout<<"Account created successfully! Your account number is "<<accno[count]<<"\n";
        count++;
        // save file data into existing file.
        savefile(accno,name,balance,count);
    } 
	else 
	{
        cout<<"Account limit reached!\n";
    }
}
// This function to display account and existing account.
void display(int accno[],char name[][100],double balance[],int count) 
{
    int number;
    cout<<"\nEnter account number to display: ";
    cin>>number;
    bool found=false;
    for(int i=0; i<count; i++) 
	{
        if(accno[i]==number) 
		{
            cout<<"\nAccount Number: "<<accno[i]<<endl;
            cout<<"Name: "<<name[i]<<endl;
            cout<<"Balance: "<<balance[i]<<endl;
            found=true;
            break;
        }
    }
    if(!found)
	{
	  cout<<"Account not found!\n";	
	} 
}
// Deposit function to add money in the array.
void deposit(int accno[],char name[][100],double balance[],int count) 
{
    int number;
    double amount;
    cout<<"\nEnter account number: ";
    cin>>number;
    cout<<"Enter deposit amount: ";
    cin>>amount;
    bool found=false;
    for(int i=0; i<count; i++)
	{
        if(accno[i]==number) 
		{
            balance[i]+=amount;
            cout<<"Deposited "<<amount<<" successfully! New balance: "<<balance[i]<<"\n";
            found=true;
            break;
        }
    }
    if(!found)
    {
      cout<<"Account not found!\n";	
	}
    else 
	savefile(accno,name,balance,count);
}
// Withdraw function to withdraw cash in the memory. when user sve the data.
void withdraw(int accno[],char name[][100],double balance[],int count) {
    int number;
    double amount;
    cout<<"\nEnter account number: ";
    cin>>number;
    cout<<"Enter withdraw amount: ";
    cin>>amount;
    bool found=false;
    for(int i=0; i<count; i++) 
	{
        if(accno[i]==number) 
		{
            if(balance[i]>=amount) 
			{
                balance[i]-=amount;
                cout<<"Withdrawn "<<amount<<" successfully! New balance: "<<balance[i]<< "\n";
            } 
			else 
			{
                cout<<"Insufficient balance!\n";
            }
            found=true;
            break;
        }
    }
    if(!found)
    {
      cout<<"Account not found!\n";	
	}
    else 
	savefile(accno,name,balance,count);
}
// Balance funtion to check the account,ke kitna balance rhta hai.
void balanceacc(int accno[],double balance[],int count) 
{
    int number;
    cout<<"\nEnter account number: ";
    cin>>number;
    for(int i=0; i<count; i++)
	{
        if(accno[i]==number) 
		{
            cout<<"Balance for Account "<<accno[i]<<": "<<balance[i]<<"\n";
            return;
        }
    }
    cout << "Account not found!\n";
}
// List function to list all existing accounts.
void list(int accno[],char name[][100],double balance[],int count)
{
    cout<<"\n--- List of All Accounts ---\n";
    if(count==0)
	{
        cout<<"No accounts found.\n";
        return;
    }
    for(int i=0; i<count; i++)
	{
        cout<<"\nAccount Number: "<<accno[i]<<endl;
        cout<<"Name: "<<name[i]<<endl;
        cout<<"Balance: "<<balance[i]<<endl;
    }
}
// Delete function to permanently delete account in the memory.
void deleteacc(int accno[],char name[][100],double balance[],int &count) 
{
    int number;
    cout<<"\nEnter account number to delete: ";
    cin>>number;
    bool found=false;
    for(int i=0; i<count; i++) 
	{
        if(accno[i]==number)
		{
            for(int j=i; j<count-1; j++)
		    {
                accno[j]=accno[j+1];
                strcpy(name[j],name[j+1]);
                balance[j]=balance[j+1];
            }
            count--;
            cout<<"Account "<<number<<" deleted successfully!\n";
            found=true;
            break;
        }
    }
    if(!found)
    {
      cout<<"Account not found!\n";	
	}
    else
	{
	  savefile(accno,name,balance,count);	
	} 
}
// Show Rubric function to add the content.
void Rubric() 
{
    system("cls");
    gotoxy(25,4);  
    {
      cout<<"=========== Project Rubric ===========";	
	}
    gotoxy(25,5);
	{
	  cout<<"1. File Handling:                    10 Marks";	
	}  
    gotoxy(25,6);  
    {
      cout<<"2. gotoxy / Graphics Menu:           10 Marks";	
	}
    gotoxy(25,7);
	{
	  cout<<"3. Create/Display/Deposit/Withdraw:  40 Marks";	
	}  
    gotoxy(25,8);  
    {
      cout<<"4. Save & Load from File:            10 Marks";	
	}
    gotoxy(25,9);  
    {
      cout<<"5. Use of Functions:                 10 Marks";	
	}
    gotoxy(25,10);  
	{
	  cout<<"6. Presentation Quality:             10 Marks";	
	}
    gotoxy(25,11);  
    {
      cout<<"7. Bonus: Clean, Structured Code:    10 Marks";	
	}
    gotoxy(25,12);  
    {
      cout<<"Total:                              100 Marks";	
	}
    gotoxy(25,13);  
	{
	  system("pause");
	}
}
// End of Program, Thanks for see it.
