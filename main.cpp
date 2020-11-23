#include <iostream>
#include<cstring>
using namespace std;
class dnode
{
        char number[50];
        char email[40];
        char name[30];
        public:
        dnode *prev,*next;
        dnode(char n[],char r[],char g[])
{
               strcpy(name,n);
                strcpy(number,r);
               strcpy(email,g);
                next=NULL;
                prev=NULL;
}
    friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr,*x,*y,*z;
    
    dnode *ptr1, *ptr2, *dup;
    public:
    dnode *prevn;
        
    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void update(char ch[10]);
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbyemail(char g[20]);
        // friend class apply;
        void accept();
        void display();
        dlist()
                {
                        head=NULL;
                        temp=NULL;
                        ptr=NULL;
                        ptr1=NULL;
                        ptr2=NULL;
                        dup=NULL;
                }
};
void dlist::accept()
{
        char number[50];
        char email[40];
        char name[30];
    char ans;
      do
        {
    cout<<"ENTER NAME   : ";
    cin>>name;
    cout<<"ENTER NUMBER : ";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"ENTER VALID NUMBER : ";
    cin>>number;
    }
    cout<<"ENTER E-MAIL : ";
    cin>>email;
    temp=new dnode(name,number,email);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
        cout<<"DO YOU WANT TO CONTINUE INSERTING?? (y/n)";
    cin>>ans;
}while(ans=='y' || ans=='Y');

}
void dlist::display()
{     if(head==NULL){
    cout<<"Phone Contact List is empty"<<endl;
}else{
    ptr=head;//start the node
    while(ptr!=NULL)//traverse till last
    {
            cout<<"\n\nNAME  ::\t"<<ptr->name;
            cout<<"\nNUMBER::\t+91-"<<ptr->number;
            cout<<"\nE-MAIL::\t"<<ptr->email;
            ptr=ptr->next;
    }
}
}

    void dlist::insert()
    {
        accept();
    }
void dlist::sort()
    {
        dnode *i,*j;
        int temp;
        char n[30];
        char g[40];
        char p[50];
        if(head!=NULL){
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                   strcpy(p,i->number);
                   strcpy(i->number,j->number);
                   strcpy(j->number,p);
                   strcpy(g,i->email);
                   strcpy(i->email,j->email);
                   strcpy(j->email,g);
                }
            }
        }
        }
    }
    void dlist::deletecontact(char s[20])
    {
        int c=0,flag=0;
        char ph[10];
        ptr=head;
        if(ptr==NULL){
            cout<<"PHONE CONTACT LIST IS EMPTY.DELETION NOT POSSIBLE"<<endl;
            return;
        }
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL){
        cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...\n";
                return;
        }
        x=ptr;
        while(x->next!=NULL && strcmp(x->next->name,s)==0){
            flag=1;
            x=x->next;
        }
        if(flag==1){
            z=ptr;
            while(z!=x){
                cout<<"NAME:"<<z->name<<" "<<"PHONE NUMBER:"<<z->number<<" "<<"E-MAIL:"<<z->email<<endl;
                z=z->next;
            }
            cout<<"NAME:"<<x->name<<" "<<"PHONE NUMBER:"<<x->number<<" "<<"E-MAIL:"<<z->email<<endl;
            cout<<"Same name has different phone numbers saved!!!Enter phone number for deletion"<<endl;
            cin>>ph;
            y=ptr;
            while(strcmp(y->number,ph)!=0){
                y=y->next;
            }
            ptr=y;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr==NULL){
            cout<<"PHONE CONTACT LIST IS EMPTY.DELETION NOT POSSIBLE"<<endl;
        }
        if(ptr!=NULL && ptr==head)
        {
            if(ptr->next==NULL){
                head=NULL;
                ptr=NULL;
                cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
            }
            else{
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
            }
        }
        if(ptr!=NULL && ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
    }
    void dlist::deletesamenumber()
    {
     ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2!= NULL)
        {
            if (strcmp(ptr1->number,ptr2->number)==0)
            {
                dup = ptr2;
                ptr2->prev->next=ptr2->next;
                ptr2=ptr2->next;
                dup->next=NULL;
                dup->prev=NULL;
                delete(dup);
            }
            else
            {
                ptr2 = ptr2->next;
        }
        }
        ptr1 = ptr1->next;
    }
    }
    void dlist::searchbyname(char na[10])
    {
        ptr=head;
        int flag=0;
        if(ptr==NULL){
            cout<<"PHONEBOOK IS EMPTY"<<endl;
            return;
        }
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                flag=1;
                cout<<"NAME FOUND"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
            cout<<"\n\nNAME  ::\t"<<ptr->name;
            cout<<"\nNUMBER::\t+91-"<<ptr->number;
            cout<<"\nE-MAIL::\t"<<ptr->email<<endl;
            }
            ptr=ptr->next;
            if(ptr==NULL && flag==0){
                cout<<"NAME NOT FOUND IN PHONEBOOK\n";
                return;
            }
        }
    }
    void dlist::searchbynumber(char num[20])
    {
     ptr=head;
     int flag=0;
     if(ptr==NULL){
            cout<<"PHONEBOOK IS EMPTY"<<endl;
            return;
        }
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                flag=1;
                cout<<"NUMBER FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
            cout<<"\n\nNAME  ::\t"<<ptr->name;
            cout<<"\nNUMBER::\t+91-"<<ptr->number;
            cout<<"\nE-MAIL::\t"<<ptr->email<<endl;
                
            }
            ptr=ptr->next;
        }
        if(ptr==NULL && flag==0){
                cout<<"PHONE NUMBER NOT FOUND IN PHONEBOOK\n";
                return;
            }
    }
    void dlist::searchbyemail(char gm[20])
    {
        ptr=head;
        int flag=0;
        if(ptr==NULL){
            cout<<"PHONEBOOK IS EMPTY"<<endl;
            return;
        }
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->email)==0)
            { flag=1;
                cout<<"E-MAIL FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
            cout<<"\n\nNAME  ::\t"<<ptr->name;
            cout<<"\nNUMBER::\t+91-"<<ptr->number;
            cout<<"\nE-MAIL::\t"<<ptr->email<<endl;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL && flag==0){
                cout<<"E-MAIL NOT FOUND IN PHONEBOOK\n";
                return;
            }
    }
    void dlist::update(char n[20])
    {
        char ans;
        int c,flag=0;
        char ph[10];
        ptr=head;
        if(ptr==NULL){
            cout<<"PHONEBOOK IS EMPTY"<<endl;
            return;
        }
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                c=1;
                break;
            }
            ptr=ptr->next;
        }
         if(ptr==NULL){
        cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...\n";
                return;
        }
        x=ptr;
        while(x->next!=NULL && strcmp(x->next->name,n)==0){
            flag=1;
            x=x->next;
        }
        if(flag==1){
            z=ptr;
            while(z!=x){
                cout<<z->name<<" "<<z->number<<" "<<z->email<<endl;
                z=z->next;
            }
            cout<<x->name<<" "<<x->number<<" "<<z->email<<endl;
            cout<<"Same name has different phone numbers saved!!!Enter phone number for updating"<<endl;
            cin>>ph;
            y=ptr;
            while(strcmp(y->number,ph)!=0){
                y=y->next;
            }
            ptr=y;
        }
                do
                {
                    cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.E-MAIL\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"ENTER NEW-NAME=";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"ENTER NEW PHONE-NUMBER?";
                    cin>>ptr->number;
                    while(strlen(ptr->number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>ptr->number;
    }
                    break;
                    case 3:
                    cout<<"ENTER NEW E-MAIL";
                    cin>>ptr->email;
                    break;
                    default:cout<<"\nNO PROPER INPUT GIVEN..\n";
                }
                cout<<"DO YOU WANT TO CONTINUE UPDATING?PRESS(y/n)";
                cin>>ans;
                }while(ans=='y');
    }
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char email[20];
    dlist d1;
    char ans;
    int ch,a;
    cout<<"\t\t**                              PHONE BOOK                          **";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,20);
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";
    d1.accept();
    d1.sort();
    do
    {
    cout<<"\n\n\n\n1)DISPLAY YOUR PHONE BOOK\n2)INSERT NEW CONTACT\n3)DELETE CONTACT\n4)DELETE SAME NUMBERS IN PHONEBOOK\n5)UPDATE DETAILS OF EXISTING CONTACT\n6)SEARCH\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
    d1.display();
    break;
    case 2:
    d1.insert();
    d1.sort();
    break;
    case 3:
    cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
    cin>>name;
    d1.deletecontact(name);
    break;
    case 4:
    d1.deletesamenumber();
    d1.display();
    break;
    case 5:
    cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
    cin>>n;
    d1.update(n);
    d1.sort();
    break;
    case 6:
    do
    {
    cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY EMAIL\n";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"ENTER THE NAME TO BE SEARCHED\n";
        cin>>name;
        d1.searchbyname(name);
        break;
        case 2:
        cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
        cin>>number;
        d1.searchbynumber(number);
        break;
        case 3:
        cout<<"ENTER THE E-MAIL TO BE SEARCHED\n";
        cin>>email;
        d1.searchbyemail(email);
        break;
        default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
    }
    cout<<"DO YOU WANT TO CONTINUE SEARCHING?????????PRESS(y/n)";
    cin>>ans;
}while(ans=='y');

    break;
    default:cout<<"\nNO PROPER INPUT GIVEN..\n";
    }
    cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????PRESS(y/n)";
    cin>>ans;
}while(ans=='y');
}
