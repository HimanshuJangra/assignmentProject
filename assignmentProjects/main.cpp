#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<cwchar>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std; 
int myscore=-1,distance_travelled=0;
char direction='d',control='@';//d means right//awsd
int c_x=24,c_y=19;
int r1,r2;
int freqx[80]={0},freqy[20]={0};
struct snake{
	int x,y;
	snake *next;
};
snake *head=NULL,*ptr;
void gotoxy(int x,int y) 
{
	  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
 void changecolor(int color)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
SetConsoleTextAttribute(hStdOut,color);
	
}	
void font()
{
				CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 30;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void Lines()
{
    font();
	system("cls");
	int i,j=0;
	gotoxy(16,1);
	for(i=2;i<=20;i++)
{
		changecolor(8);
		gotoxy(17,i);
		cout<<"*";
		gotoxy(79,i);
		cout<<"*";
}
    for(i=17;i<=79;i++)
{
	
		changecolor(8);
		gotoxy(i,2);
		cout<<"*";	
		gotoxy(i,20);
		cout<<"*";
}

	}
int random(int lower,int upper){
	    srand(time(0));
	return((rand() %(upper - lower + 1)) + lower);
}
bool trev(int x,int y){
	snake *t=head;
	while(t){
	   if(t->x==x && t->y==y)
	   return true;
		t=t->next;
	}
	return false;
}
void food(){
while(1){
	r1=random(18,78);//range
	r2=random(3,19);//range
	if(!trev(r1,r2))
	break;
}
gotoxy(r1,r2);
changecolor(12);
cout<<"@";	
}

bool check_forfood(){
	if(c_x==r1 && c_y==r2)
	return true;
	else
	return false;
}
void delay()
{
	for(int i=0;i<10000000;i++){}
	for(int i=0;i<10000000;i++){
	}
}

void small_delay(){
		for(int i=0;i<100000;i++){}
}

void append(int x1,int y1){
	snake *n=new snake;
	n->next=NULL;
	n->x = x1;
	n->y = y1;
	if(head==NULL){
		head=n;
	    ptr=n;
	}
		else{
			ptr->next=n;
			ptr=n;
		}
}
void del(){
	snake *temp=head;
	head=head->next;
	delete temp;
}

void score(){
	myscore++;
	gotoxy(47,1);
	changecolor(13);
	cout<<myscore;
}
void makesnake(){
changecolor(10);
append(18,19);
gotoxy(18,19);
cout<<"+";	
append(19,19);
gotoxy(19,19);
cout<<"+";
append(20,19);
gotoxy(20,19);
cout<<"+";	
append(21,19);
gotoxy(21,19);
cout<<"+";
append(22,19);
gotoxy(22,19);
cout<<"+";	
append(23,19);
gotoxy(23,19);
cout<<"+";
changecolor(15);
append(24,19);
gotoxy(24,19);
cout<<">";
//add snake in heap

food();//FOOD-*+-+*
//initialize score with 0
score();
}
void show_finalscore(){
	changecolor(11);
	gotoxy(81,1);
	char ch=getch();
system ("cls"); 
cout<<"YOUR SCORE "<<myscore<<endl;
cout<<"DISTANCE TRAVELLED "<<distance_travelled;
delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();
ch =getch();
exit(1);	
}

void check_for_snakebody(){
	if(trev(c_x,c_y))
    show_finalscore();
}

void check_for_boundary(){
	if(c_x==17 || c_x==79 || c_y==2 || c_y==20)
	show_finalscore();
}
void movement(){

	check_for_boundary();
	check_for_snakebody();
	//code 
	if(direction==control){
	if(control=='a' || control=='d' || control=='@'){
	small_delay();}
	else if(control=='s' || control=='w'){
	small_delay();}
	else{
		if(direction=='a' || direction=='d')
		small_delay();
		else{
		small_delay();small_delay();}
	}
     }
	else{
		if(control=='a' || control=='d' || control=='@'){
	delay();}
	else if(control=='s' || control=='w'){
		delay();delay();
	}
	else{
		if(direction=='a' || direction=='d'){
		delay();}
		else{
		delay();delay();}
	}
	
	}
	if(!check_forfood()){
		gotoxy(head->x,head->y);//tail of snake
		changecolor(0);
		cout<<" ";
		del();
	}
	else{// if snake eats foood
			score();//Increasng my score
		food();//FOOD
	}
	gotoxy(ptr->x,ptr->y);//snake head
	changecolor(10);
	cout<<"+";
	append(c_x,c_y);
	gotoxy(ptr->x,ptr->y);//head of snake
	changecolor(15);
	if(control=='w')
	cout<<"^";
	else if(control=='d' || control=='@')// initial case for snake
	cout<<">";
	else if(control=='s')
	cout<<"v";
	else if(control=='a')
	cout<<"<";
	else{
	if(direction=='w')
	cout<<"^";
	else if(direction=='d')
	cout<<">";
	else if(direction=='s')
	cout<<"v";
	else if(direction=='a')
	cout<<"<";	
	}
	if(control !='w' && control !='a' && control !='s' && control !='d')
	{
	}
	else{
	if(direction!=control)
	direction=control;
	control='$';
        }
}
void left(){
if(direction=='d'){
control='$';
return;
}
	c_x=c_x-1;
	movement();
}
void down(){
if(direction=='w'){
control='$';
return;
}
	c_y=c_y+1; 
		
	movement();
}
void right(){
	if(direction=='a'){
	control='$';
	return;
   }
	//if(direction=='r')
	c_x=c_x+1;
	//if(direction=='d')
	//c_y=c_y+1;
	//if(direction=='u')
	//c_y=c_y-1; 
		
	movement();
}
void up(){	
if(direction=='s'){
control='$';
return; 
}
	c_y=c_y-1;
		
	movement();
}
void startgame(){
while(1){//infinite loop
changecolor(14);
    distance_travelled++;//total distance travelles yet
	gotoxy(1,1);
	cout<<distance_travelled;
	if(kbhit()){
		control=getch();
	    switch(control){
	    case 'a' : left(); break;
		case 's' : down(); break;
		case 'd' : right();break;
		case 'w' : up();   break;	
	    default  : break;   	
	    }	
	}	
	if(direction=='a')
	left();
	if(direction=='d')
	right();
	if(direction=='w')
	up();
	if(direction=='s')
	down();
}		
}
int main(){
	Lines();
	makesnake();//******>
	score();
	startgame();
	getchar();
	getchar();
		return 0;
}
