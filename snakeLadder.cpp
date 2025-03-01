#include<iostream>
#include<windows.h>
using namespace std;
#include<conio.h>
#include<math.h>
#include <cstdlib>
#include<stdio.h>
void box(int r , int c);
void linebox(int r , int c);
void fulbox(int r , int c);
int dice(char a , char b);
int position(int r , int c , char character , int sum);
void removeposition(int y , int z);
void snakeprint(int sn, int sm);
void ladderprint(int la , int lb);

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {

        }
}
int x=0;
int y=0;
char ch=219;        // use for printing lines between boxes
int row=3;  // use for printing box
int col=2;      // use for printing box
int counter=100;        // counter values written in boxes
char ch1='@' , ch2='#'; //player symbol;
int sum1=0;
int sum2=0;
int p=49;       // use for last row from where character are printing
int q=48;       // use for last column from where character are printing
int main()
{
    box(x , y);
    linebox( x ,y);
    fulbox( x , y);
    int sn=5;       // snake start from 5th row
    int sm=45;       // snake start from 45th column
    snakeprint(sn, sm);
    int ld=40;          // ladder start from 40th row
    int ld2=41;         // ladder start from 41th column
    ladderprint(ld,ld2);
    gotoRowCol(15,55);
    cout<<" player1 symbol :"<< ch1 ;       // it print character for player 1
    gotoRowCol(16, 55);
    cout<<" player2 symbol :"<< ch2 ;       // it print character for player 2
    gotoRowCol(17 ,55);
    cout<<" Snake 91....19 ";
    gotoRowCol(18,55);
    cout<<" ladder 12....42 ";
    x=49;     // this variable start from bottom  printing character
    y=48;       // this variable start from bottom  printing character
    char ch1='@',ch2='#';
    dice(ch1,ch2);
    gotoRowCol(30 ,50);
    if(sum1>=100)
        cout<<"Congratulation Player 1(@) have won";
    else
        cout<<"Congratulation Player 2 (#) have won";
    getch();
}
int t=0;
void box(int r , int c)
{   int i;

    for(i=0;i<=4;i++)
    {
        gotoRowCol(x,y);
        cout<<ch;
        y++;
    }
    for(i=0;i<=4;i++)
    {
        gotoRowCol(x,y);
        cout<<ch;
        x++;
    }
    for(i=0;i<=4;i++)
    {
        gotoRowCol(x,y);
        cout<<ch;
        y--;
    }
    for(i=0;i<=4;i++)
    {
        gotoRowCol(x,y);
        cout<<ch;
        x--;
    }
}
void linebox(int r , int c)
{
    for(int i=0;i<50;i+=5)
    {
         y=i;
        gotoRowCol(x,y);

        box(x,y);
        gotoRowCol(x+2,y+2);
         cout<<counter;
         counter=counter-1;         // counter print value from 1 to 100.
    }
}
void fulbox(int r , int c)
{
    for(int j=5 ; j<50 ; j+=5 )
    {
        row=row+j;
        x=j;
        gotoRowCol(x,y);
        linebox(x,y);            // this function call linbox 10 time
    }
}
int dice(char ch1 , char ch2)
{
    char ch,chr;
    int b, c;

   while(sum1<100 && sum2<100)
   {

        int counter=0;      // it count sixes
        int counter1=0;     // it count sixes of plyer 2
        int six=0;
            do
            {
                do
                {
                gotoRowCol(20,55);
                b =rand()%6+1;
                cout<<"(Roll Dice Player No.1) " << b;
                sleep(100);
                    if(sum1==0 && b!=6)     // restricted sum1 without 6
                    {
                        b=0;
                    }
                }while(!kbhit());
                sleep(10000);
                getch();
                sum1=(sum1+b);
                if(b==6)        // count sixes
                    counter++;
                if(sum1>100)            // condition to restrict number becoming greater than 100
                    sum1=sum1-b;        //if sum1 become greater than 100 it sub last dice value
                if(counter==3)
                {
                    sum1=sum1-18;           // if three sixes come move to previous place
                    break;
                }
            }while(b==6 && counter!=3);         // it continue untill 3 sixes comes
            if(sum1>6 && sum1<18 && counter==1 || counter==2  )     // it sub first six
                sum1=sum1-6;

                if(sum1==91)        // condition for snake
                    sum1=19;
                if(sum1==12)        // condition for ladder
                    sum1=42;

                position(x,y,ch1,sum1);
                gotoRowCol(22,56);
                cout<<"sum of dice"<<sum1;
    do
    {
        do
        {
            gotoRowCol(25,55);
            c=rand()%6+1;
            cout<<"(Roll Dice Player No.2): "<<c;
                sleep(100);
                if(sum2==0 && c!=6)           // restricted sum2 without 6
                {
                    c=0;
                }
        }while(!kbhit());
        sleep(10000);
        getch();
        sum2=sum2+c;
        if(c==6)
            counter1++;         // it count sixes
        if(sum2>100)                 // condition to restrict number becoming greater than 100
            sum2=sum2-c;
        if(counter1==3)
            {
                sum2=sum2-18;
                break;
            }
        }while(c==6 && counter1!=3);
       if(sum2>6 && sum2<18 && counter1==1 || counter1==2 )
                sum2=sum2-6;
                if(sum2==91 )           // condition for snake
                    sum2=19;
                if(sum2==12)
                    sum2=42;           // condition for ladder

        position(x,y,ch2,sum2);
        gotoRowCol(27,55);
        cout<<"Sum of dice \t "<<sum2;
    }
}
int position(int r , int c , char character ,int sum )
{
    gotoRowCol(r,c);
    if(sum>=1 && sum<=10)       // it print in last row
    {   removeposition(p,q);
        gotoRowCol(r,c-((sum*5)-5));
        p=r;
        q=c-((sum*5)-5);
        cout<<character;
        gotoRowCol(30,50);
    }
    else
    {
        int f=sum%10;
        int g=sum/10;
            if(f==0 )       // it print character for which modulus become zero
            {
                removeposition(p,q);
                gotoRowCol(r-(((g-1)*5)), 3);
                p=(r-(((g-1)*5)));
                q=3;
                cout<<character;
            }
            else
            {   removeposition(p,q);
                gotoRowCol(r-((g*5)),c-((f*5)-5));      // it print character without in last rows and first columns
                cout<<character;
                p=r-((g*5));
                q=c-((f*5)-5);
            }
    }
}
void removeposition(int y , int z)
{
    gotoRowCol(y,z);
    cout<<" ";
}
void snakeprint(int sn, int sm)
{
    for(sn=4;sn<=41;sn++)
    {
        gotoRowCol(sn,sm);
        sm--;
            if(sn<=5)
            {
                cout<<" &";     // it print snake mouth
            }
            else if(sn==40 ||sn==41)
                cout<<" *";         // snake tail
            else
                cout<<"/*/";         // snake body.
    }
}
void ladderprint(int la , int lb)
{
    for(la;la>=30 ; la--)
    {
        gotoRowCol(la,lb);      // it print ladder
        cout<<"|~~|";
    }
}








