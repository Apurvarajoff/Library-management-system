#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

class bookshop
{
    private:
            char b_name[20],a_name[20];
            int b_id;
            int no_of_books;
    public:
        int b_ids()
        {
            return b_id;
        }
        void getdata()
        {

             cout<<"\n\n\t\t\tADD BOOKS"<<endl;
             cout<<"\n\t\t\tBOOK ID : ";
             cin>>b_id;

             cin.ignore(numeric_limits<streamsize>::max(),'\n');
             cout<<"\n\t\t\tBOOK NAME : ";
             cin.getline(b_name,20);


             cout<<"\n\t\t\tAUTHOR NAME : ";
             cin.getline(a_name,20);

             cout<<"\n\t\t\tNO. OF BOOKS : ";
             cin>>no_of_books;
             cin.ignore(numeric_limits<streamsize>::max(),'\n');


        }
        void showdata()
        {
            cout<<"\n\n\n\t\tBOOK ID : "<<b_id<<endl;
            cout<<"\n\n\t\tBOOK : "<<b_name<<endl;
            cout<<"\n\n\t\tAUTHOR : "<<a_name<<endl;
            cout<<"\n\n\t\tNO. OF BOOKS : "<<no_of_books<<endl;

            cout<<endl<<endl;
        }
        void add_book();
        void show_book();
        void check_book();
        void update_book();
        void delete_book();
};

void bookshop::add_book()
{
    bookshop b;
    system("cls");
    fstream f;
    f.open("book2.txt",ios::out|ios::app);
    if(!f)
    {
        cout<<"\nError in opening file ! File Not Found!!"<<endl;
        return;
    }
    b.getdata();

    f.write((char*)&b,sizeof(b));
    f.close();

}

void bookshop::show_book()
{

    bookshop b;
    system("cls");
    ifstream f;
    f.open("book2.txt",ios::in);
    if(!f)
    {
        cout<<"\nError in opening file ! File Not Found!!"<<endl;
        return;
    }
    f.read((char*)&b,sizeof(b));

    while(!f.eof())
    {
        b.showdata();
        f.read((char*)&b,sizeof(b));
    }
    system("pause");
    f.close();

}
void bookshop::check_book()
{

    bookshop b;
    fstream f;
    f.open("book2.txt",ios::in);
    int counts=0;
    int b_idd;

    cout<<"\n\n\t\t\tCheck Particular Book";

    if(!f)
    {
        cout<<"\nError in opening file! File Not Found!!"<<endl;
        return;
    }
    else
    {
        cout<<"\n\n\t\tBOOK ID: ";
        cin>>b_idd;
        f.read((char*)&b,sizeof(b));
        while(!f.eof())
        {

            if(b.b_ids()==b_idd)
            {

                b.showdata();
                counts++;
                break;
            }
            f.read((char*)&b,sizeof(b));
        }


        f.close();
        if(counts==0)
        {
            cout<<"\nBOOK ID ("<<b_id<<") : NOT FOUND....";
        }

    }

}

void bookshop::update_book()
{

    system("cls");
    fstream f,tem;
    int no_book,counts=0;
    bookshop b;
    char a_na[20],b_na[20];
    int b_idd;

    cout<<"\n\n\t\tUPDATE BOOK RECORD"<<endl;
    f.open("book2.txt",ios::in|ios::ate);
    tem.open("tem.txt",ios::out|ios::app);

    if(!f)
    {
        cout<<"\nError in opening file! File Not Found!!"<<endl;
        return;
    }
    else
    {

        cout<<"\nEnter BOOK ID : ";
        cin>>b_idd;
        f.read((char*)&b,sizeof(b));
        while(!f.eof())
        {
            if(b.b_ids()==b_idd)
            {
                system("cls");
                cout<<"\n\t\t\t\tUpdate Book Record";

                cout<<"\nNew Book Name : ";
                cin>>b_na;

                cout<<"\nAuthor Name : ";
                cin>>a_na;

                cout<<"\nNo. of books : ";
                cin>>no_book;

                tem.write((char*)&b,sizeof(b));
                cout<<endl<<endl;
                counts++;

            }
            else
            {
                tem.write((char*)&b,sizeof(b));
            }

            f.read((char*)&b,sizeof(b));
        }

        if(counts==0)
        {
            cout<<"\nBOOK ID ("<<b_idd<<") : NOT FOUND....";
        }

    }

    cout<<endl;


    f.close();
    tem.close();
    remove("book2.txt");
    rename("tem.txt","book2.txt");

}

void bookshop::delete_book()
{
    bookshop b;
    system("cls");
    fstream f,tem;
    int no_books,counts=0;
    char b_na[20];
    int b_idd;
    cout<<"\n\t\t\tDelete a Book ";
    f.open("book2.txt",ios::in);
    tem.open("tem.txt",ios::out|ios::app);



    if(!f)
    {
        cout<<"\nError in opening file! File Not Found!!";
        return;
    }
    else
    {
        cout<<"\nBOOK ID : ";
        cin>>b_idd;

        f.read((char*)&b,sizeof(b));
        while(!f.eof())
        {
            if(b.b_ids()==b_idd)
            {
                system("cls");
                cout<<"\n\t\t\tDelete a Book ";
                cout<<"\n\nBook is deleted Successfully....\n"<<endl;
                counts++;
            }
            else
            {

                tem.write((char*)&b,sizeof(b));

            }
            f.read((char*)&b,sizeof(b));
        }
        if(counts==0)
        {
            cout<<"\nBOOK ID ("<<b_idd<<") : NOT FOUND....";
        }
    }
    system("pause");

    f.close();
    tem.close();
    remove("book2.txt");
    rename("tem.txt","book2.txt");


}
void bookshoprecord()
{

    int ch;
    char x;
    bookshop b;

    while(1)
    {
        system("cls");
        cout<<"\n\tCONTROL PANEL"<<endl;
        cout<<"\n\n\t1. ADD BOOK"<<endl;
        cout<<"\n\t2. DISPLAY BOOK"<<endl;
        cout<<"\n\t3. CHECK PARTICULAR BOOK"<<endl;
        cout<<"\n\t4. UPDATE BOOK"<<endl;
        cout<<"\n\t5. DELETE BOOK"<<endl;
        cout<<"\n\t6. EXIT"<<endl;

        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {

            case 1  :   do
                        {
                            b.add_book();
                            cout<<"\n\n\tWant to add another book? (y/n) : ";
                            cin>>x;

                        }while(x=='y');
                        break;

            case 2  :   b.show_book();
                        break;

            case 3  :   b.check_book();
                        break;

            case 4  :   b.update_book();
                        break;

            case 5  :   b.delete_book();
                        break;

            case 6  :   exit(0);
                        break;

            default :   cout<<"\n\tINVALID CHOICE"<<endl;

        }
    }
}
int main()
{

    bookshoprecord();

    return 0;
}
