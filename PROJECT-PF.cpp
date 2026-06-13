#include<iostream>
#include<cstring>
using namespace std;

struct Book
{
    int id;
    char title[50];
    char author[50]; 
    bool isborrowed;
};
Book books[100];
int bookcount=0;

// function to add books 
    void addBooks()
    {
        if(bookcount<100)
        {
            cout<<"Enter book ID:";
            cin>>books[bookcount].id;
            cout<<"Enter title:";
            cin>>books[bookcount].title;
            cout<<"Enter the author name:";
            cin>>books[bookcount].author;
                books [bookcount].isborrowed=false;
                bookcount++;
            cout<<"Book added successfullly\n";
        }
        else
        {
        cout<<"Library  is full\n";
        }
    }

// function displaying the list of books
    void displaybooks()
    {
        if(bookcount==0)
        {
            cout<<"No book available\n";
            return;
        }
        for (int i=0; i<bookcount; i++)
        {
            cout<<"ID : "<<books[i].id<<"\n"<<"Title : "<<books[i].title<<"\n"
            <<"Author : "<<books[i].author<<"\n"
            <<"Status : "<<(books[i].isborrowed?"borrowed ":"Available")<<endl;
        }
    }
//function to borrow a book

    void borrowbooks()
    {
        int id;
        cout<<"Enter the ID to borrow:";
        cin>>id;
        for(int i=0;i<bookcount; i++)
        {
        if(books[i].id==id)
        {
            if(books[i].isborrowed)
            {
                cout<<"Book is already borrowed: \n";
            }
            else
            {
            books[i].isborrowed=true;
                cout<<"You borrowed: "<<books[i].title<<endl;
            }
            return;
        }
    }
    cout<<"Books not found"<<endl;
    }


//function to return a book
    void returnbook()
    {
        int id;
        cout<<"Enter ID to return:";
        cin>>id;
        for(int i=0; i<bookcount; i++)
        {
            if(books[i].id==id)
            {
                if(books[i].isborrowed)
                {
                    books[i].isborrowed=false;
                    cout<<"You returned : "<<books[i].title<<endl;
                }
                else
                {
                    cout<<"Book was not borrowed\n";
                }
                return;
            }
        }
        cout<<"Books not found\n";
    }

    // Displaying the menu to the user
    void menu()
    {
        cout<<"_________LAHORE COLLEGE FOR WOMEN UNIVERSITY (LCWU)______________"<<endl;
        cout<<"_________DEPARTMENT OF SOFTWARE ENGINEERING (SE)______________"<<endl;
        cout<<"_________PROGRAMMING FUNDAMENTALS (PF)______________"<<endl;
        cout<<"\n";
        cout<<"!----------- Welcome to the Library Management System-----------!"<<endl;
        cout<<"------------ Presnted by Aima Ashfaq ----------------------------"<<endl;;
        int choice;
        while(true)
        {
            cout<<"Press any key from 1-5\n";
            cout<<"\nPress 1 : to Add Book";
            cout<<"\nPress 2 : to Display Books";
            cout<<"\nPress 3 : to Borrow Book";
            cout<<"\nPress 4 : to Return Book";
            cout<<"\nPress 5 : to Exit from the program\n";
            cout<<"Enter your choice: "<<endl;
            cin>>choice;
                if(choice==1)
                addBooks();

                else if(choice==2)
                displaybooks();

                else if(choice==3)
                    borrowbooks();

                else if(choice==4)
                returnbook();

                else if (choice==5)
                    return;

                else
                cout<<"Invalid choice! Try again\n";
        }
    }

    //main function of program 
int main()
{
    menu();
    return 0;
}