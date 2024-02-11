#include <iostream>
# include<cstdlib>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

float check () ;

int search(char card_search[10]);
char search_number[100][11];
char card_number3[100],card_number4[100];
int count =0;

int find1,find2,find3,find4,find5;

class ATM
{ private:
        char account_name [200];
        char card_number[100];
        float amount ;
        public:
        ATM (){amount =0;}
        void create_new_acc(int j);
        void deposit(float);
        void withdrawal(float);
        void transfer(float amount_transferred);
        void print_acc_data();


};
ATM p[100];
void ATM::create_new_acc(int j)/*in this function  we enter name and card number of clients and see error if the user enter larger than 100 character
or enter number in name and another error if the user enter larger than or fewer than 10 number in card number
*/
{   int length2=0; int length1=0; int k;

  repeat1:
    cout<<"please enter the the account name : " ;


    cin.getline(account_name,200);

    length1=strlen(account_name);

   while(length1>100) {cout<<"invalid name! please try again: "; goto repeat1; }





char check[30]="1234567890!@#$%^&*,.~;/?<>-=`";
for(int i= 0;i<strlen(account_name);i++)
{
    for(int j=0;j<strlen(check);j++)
    {
        if(account_name[i]==check[j]||account_name[0]==' ')
        {
            cout<<"do not enter numbers in name or space in first of name or special characters!!"<<endl;
            goto repeat1;
        }
    }
}




cout<<"please enter the card number(10 numbers): ";
repeat2:
    cin.getline(card_number,50);
     k = 0;
    while (card_number[k]) {if ( ! (card_number[k] >= '0' && card_number[k] <= '9') ){ cout<<"please enter the card number using numbers only: "; goto repeat2;} k++; }



   length2=strlen(card_number);
 while(length2<10){cout<<" you have entered less than ten numbers please try again:"; goto repeat2; }
 while(length2>10){cout<<" you have entered more than ten numbers please try again: "; goto repeat2;}

find5=search(card_number);
for(int i=0;i<100;i++)
    if(find5==i)
{

 cout<<"this card number is already used!  try again :";
 goto repeat2;}
 char check3[11]="1234567890";

 for (int i=1 ; i < 10 ;i++) // makes sure that all the input numbers are not the same and prints error massage
	{
		if (card_number[0] != card_number[i]) break;

	{cout << "Invalid card number! numbers must be different! please try again: "; goto repeat2;}}

     for( k=0 ; k<10 ; k++)
     search_number[j][k]=card_number[k];

}



void ATM::deposit(float amount_deposited)
{
   p[find4].amount += amount_deposited + 0.01*amount_deposited;
}

void ATM::withdrawal(float amount_withdrawn )/* in this function we see error if user wants money much than he have in his account +taken money
*/

{
while(amount_withdrawn>amount-0.03*amount_withdrawn)
    {
        cout<<"your account does not have all of this money !!  Please enter fewer money:";
       amount_withdrawn = check ( ) ;}


    p[find3].amount -= (amount_withdrawn + 0.03*amount_withdrawn);

}

void ATM::transfer(float amount_transferred)/*in this function we transfer money from one account to another
*/
{while(amount_transferred>p[find1].amount-0.015*amount_transferred)
{
    cout<<"sending account does not have this money!!  Please enter fewer money:";
    amount_transferred = check ( ) ;
}

        p[find1].amount =p[find1].amount - amount_transferred-0.015*amount_transferred; //sending account x=
        p[find2].amount =p[find2].amount + amount_transferred-0.015*amount_transferred;//receiving account
}


void ATM::print_acc_data()/*in this function we print data account of user
*/
{
   int length=strlen(account_name);

    cout<<"name : ";

    for(int i=0;i<length;i++)
   cout<<account_name[i];
        cout<<endl;


    cout<<"card number :";
    for(int i=0;i<10;i++)
    cout<<card_number[i];
        cout<<endl;
   cout<<"amount:"<<amount<<endl;
}




int main()
{

    char number_of_operation[10]; int length=0;

    for (int i=0;number_of_operation[0]!='5'&&i<100;i++)
   {

       lllabel :
    cout<<"1-----create new account "<<endl;
    cout<<"2-----Deposit"<<endl;
    cout<<"3-----transfer to another account "<<endl;
    cout<<"4-----withdrawal"<<endl;
    cout<<"5-----exit"<<endl;
    cout<<"please enter the number of operation :";
repeat3:
    cin.getline(number_of_operation,10);
   length=strlen(number_of_operation);
   while(length<1){cout<<"please enter an operation! : "; goto repeat3;}
     while(length>1){cout<<"please enter one entry of a valid operation! : "; goto repeat3;}



   if(number_of_operation[0]<'1'||number_of_operation[0]>'5')
   {
do{cout<<"please enter a number of valid operation: "; goto repeat3;} while(number_of_operation[0]<'1'||number_of_operation[0]>'5');}

    switch(number_of_operation[0])
{case '1'://create account
    {
       p[i].create_new_acc(i);
       p[i].print_acc_data();
       break ;

    }
case '2'://deposit
    {
        if ( i == 0 )
        {
           cout << " Please make at least an account first !! " << endl ;
           goto lllabel ;
        }

    jump:
    float amount_deposited;

    cout<<"please enter the account number(10 numbers): ";

    cin.getline(card_number3,50);
     int k = 0;
    while (card_number3[k]) {if ( ! (card_number3[k] >= '0' && card_number3[k] <= '9') ){ cout<<"please enter the card number using numbers only! "; goto jump;} k++; }



   int length2=strlen(card_number3);
 while(length2<10){cout<<" you have entered less than ten numbers please try again!"; goto jump; }
 while(length2>10){cout<<" you have entered more than ten numbers please try again! "; goto jump;}




        find4=search(card_number3);
        if(find4==-1)
           {cout<<"account is not found!please enter another card number "<<endl;
          goto jump ;

}
        else
{

 cout<<"please enter the amount to be deposited :";
  amount_deposited = check ( ) ;



        p[find4].deposit(amount_deposited);
        p[find4].print_acc_data();
        i--;
       }
       break ;

    }
case '3':
    {
        if ( i == 0 || i == 1 )
        {
           cout << " Error!! , 2 accounts at least are needed first " << endl ;
           goto lllabel ;
        }
        label2:
        float amount_transferred;
    char card_number1[100],card_number2[100];
     cout<<"please enter the sending account number(10 numbers): ";

    cin.getline(card_number1,50);
     int k = 0;
    while (card_number1[k]) {if ( ! (card_number1[k] >= '0' && card_number1[k] <= '9') ){ cout<<"please enter the card number using numbers only! "; goto label2;} k++; }



   int length2=strlen(card_number1);
 while(length2<10){cout<<" you have entered less than ten numbers please try again!"; goto label2; }
 while(length2>10){cout<<" you have entered more than ten numbers please try again! "; goto label2;}




         find1 =search(card_number1);
         if(find1==-1)
           {cout<<"account is not found!!  Please try again"<<endl;
        goto label2 ;}
         else
   {
label3:
        cout<<"please enter the number of the receiving account(10 numbers):  ";
        cin.getline(card_number2,50);
     int k = 0;
    while (card_number2[k]) {if ( ! (card_number2[k] >= '0' && card_number2[k] <= '9') ){ cout<<"please enter the card number using numbers only! "; goto label3;} k++; }



   int length2=strlen(card_number2);
 while(length2<10){cout<<" you have entered less than ten numbers please try again!"; goto label3; }
 while(length2>10){cout<<" you have entered more than ten numbers please try again! "; goto label3;}





       find2=search(card_number2);
       if(find2==-1||find1==find2)
       {cout<<"account is not found or its the same account!!  Please try again "<<endl;
      goto label3;}
       else
    {

        cout<<"please enter the amount to be transferred:";

        amount_transferred = check ( ) ;


       p[i].transfer(amount_transferred);
       i--;
       cout<<"sending account:"<<endl;
       p[find1].print_acc_data();
       cout<<"receiving account:"<<endl;
       p[find2].print_acc_data();}}


       break;
    }

case '4':
    {

        if ( i == 0 )
        {
           cout << " Please make at least an account first !! " << endl ;
           goto lllabel ;
        }

label4:
    float amount_withdrawn;
     cout<<"please enter the account number (10 numbers):";
     cin.getline(card_number4,50);
     int k = 0;
    while (card_number4[k]) {if ( ! (card_number4[k] >= '0' && card_number4[k] <= '9') ){ cout<<"please enter the card number using numbers only! "; goto label4;} k++; }



   int length2=strlen(card_number4);
 while(length2<10){cout<<" you have entered less than ten numbers please try again!"; goto label4; }
 while(length2>10){cout<<" you have entered more than ten numbers please try again! "; goto label4;}





 find3=search(card_number4);
if (find3==-1)
   {cout<<"account is not found!!please try again"<<endl;
  goto label4;}
else
     {cout<<"please enter the amount to be withdrawn :";

     amount_withdrawn = check ( ) ;




        p[find3].withdrawal(amount_withdrawn);
        p[find3].print_acc_data();}

        break;
    }

}}
   cout<<"we hope you are satisfied with our services! Have a nice day!"<<endl;

   return 0;
}
int search (char card_search[])/*in this function we make search if account card number is already used or not found
*/
{
    for(int i=0;i<100;i++)

         if(search_number[i][0]==card_search[0]
          &&search_number[i][1]==card_search[1]
          &&search_number[i][2]==card_search[2]
          &&search_number[i][3]==card_search[3]
          &&search_number[i][4]==card_search[4]
          &&search_number[i][5]==card_search[5]
          &&search_number[i][6]==card_search[6]
          &&search_number[i][7]==card_search[7]
          &&search_number[i][8]==card_search[8]
          &&search_number[i][9]==card_search[9])

{
    return i;}
    return -1;


}



float check ()
{
    float amount ;
    error :
    cin>>amount;

        while ( cin.fail() )  //to get numbers only & if characters are entered after the numbers it will be ignored
    {
        cin.clear();
        cin.ignore(1000,'\n') ;
        cout<< " Error!! ,Please enter a valid amount :" ;
        cin>> amount ;
    }

    while (amount <=0)   // in this function we see error if user enter 0 or negative value
    {
        cout<<" Error!! ,Please enter a positive value :";
        goto error ;
    }

    return amount ;

}
