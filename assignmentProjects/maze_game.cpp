#include<iostream>
#include<stack>
#include<conio.h>
#include<string>
#include<queue>
using namespace std;
static int score=0;
static string qmaze[8]= {"   1    ", "1  1   1", "1  111  ", "1       ","1     11","   11   ","   1  1 ","   1  1d"};

static string maze[8]= {"   1    ", "1  1   1", "1  111  ", "1       ","1     11","   11   ","   1  1 ","   1  1d"};
static string matrix[8] = {"   1    ", "1  1   1", "1  111  ", "1       ","1     11","   11   ","   1  1 ","   1  1d"};
stack <int> stacks;
queue <int> queues;
void print()
{
	cout<<endl<<"SCORE:- "<<score<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<maze[i]<<endl;
	}
}

	/*if(matrix[n][m]=='d')
	{
		cout<<"CONGRATS YOU HAVE REACHED YOUR DESTINATION "<<endl;
		return 1;
	}*/
bool checkvalid(int n,int m)
{
	if(m<=7 && matrix[n][m]!='1' && matrix[n][m]!='$' )
	{	
	if(matrix[n][m]=='@')
	{
		score=score-5;
		return 1;
	}
    score=score+5;
	return 1;
	}
	if(matrix[n][m]=='1' || matrix[n][m]=='$')
	{
		score=score-5;
		cout<<"one";
		cout<<"score reduced now SCORE:-"<<score<<endl;
		
	}
	else
	{
	score=score-5;
	cout<<"m is "<<m<<endl;
	//cout<<"value of matrix is "<<matrix[n][m]<<endl;
      return 0;
}
}
void queuefn()
{
	int xx,yy;
	while(queues.empty()==0)
	{
		if(queues.front()<10)
		{
			xx=0;yy=queues.front();
		}
		else
		{
			xx=queues.front()/10;
			yy=queues.front()%10;
		}
		matrix[xx][yy]='x';
		queues.pop();
		
		if(xx!=0 && matrix[xx-1][yy]!='1' && matrix[xx-1][yy]!='x' )//up
		{
			if(matrix[xx-1][yy]=='d')
			return ;
			queues.push((xx-1)*10+yy);
			matrix[xx-1][yy]='$';
		}
		if(yy!=7 && matrix[xx][yy+1]!='1' && matrix[xx][yy+1]!='x')//right
		{
			if(matrix[xx][yy+1]=='d')
			return ;
			queues.push(xx*10+(yy+1));
			matrix[xx][yy+1]='$';
		}
		if(yy!=0 && matrix[xx][yy-1]!='1' && matrix[xx][yy-1]!='x')//left
		{
		if(matrix[xx][yy-1]=='d')
			return ;
			queues.push(xx*10+(yy-1));
			matrix[xx][yy-1]='$';
		}
		
		if(xx!=7 && matrix[xx+1][yy]!='1' && matrix[xx+1][yy]!='x')//down
		{
		if(matrix[xx+1][yy]=='d')
			return ;
			queues.push((xx+1)*10+yy);
			matrix[xx+1][yy]='$';
		}
		
		
		
	}
	
}
void mazefn()
{
	char ch;
	int d=3;
	int m=0,n=0;
	while(matrix[m][n]!='d')
	{
	
	cin>>ch;
	if(ch=='w' || ch=='W')//top
     {
       if(checkvalid(n-1,m))
       {
       	maze[n-1][m]='#';
       	maze[n][m]=' ';
       	matrix[n][m]='@';
       	n=n-1;
       	system("cls");
       	print();
	   }
	   
	 }

	 	if(ch=='d' || ch=='D')//right
     {
     
     	if(checkvalid(n,m+1))
     	{
     		maze[n][m+1]='#';
     		maze[n][m]=' ';
     		matrix[n][m]='@';
     		m=m+1;
     		system("cls");
     	//	cout<<endl<<"n is"<<n<<"m is"<<m<<endl;
     		print();
		 }
	 }

    
	 	if(ch=='S' || ch=='s')//down
     {
     	if(checkvalid(n+1,m))
     	{
     		maze[n+1][m]='#';
     		maze[n][m]=' ';
     		matrix[n][m]='@';
     		n=n+1;
     		system("cls");
		 print();
		 }
	 }
	 	if(ch=='a' || ch=='A')//left
     {
     	
     	
    
     	
     	if(checkvalid(n,m-1))
     	{
     		maze[n][m-1]='#';
     		maze[n][m]=' ';
     		matrix[n][m]='@';
     		m=m-1;
     		system("cls");
     		print();
		 }
	 }
}
}
bool check(){
	int x,y;
	while(stacks.empty()==0){
	if(stacks.top()<10){
	x=0;y=stacks.top();}
	else{
		x=stacks.top()/10;y=stacks.top()%10;
	}
	matrix[x][y]='x';
	stacks.pop();
	if(x!=0 && matrix[x-1][y]!='1' && matrix[x-1][y]!='x'){//up
	if(matrix[x-1][y]=='d')
	return true;
	stacks.push((x-1)*10 + (y));
	matrix[x-1][y]='$';
	}
	if(y!=7 && matrix[x][y+1]!='1' && matrix[x][y+1]!='x'){//right
		if(matrix[x][y+1]=='d')
	return true;
	stacks.push((x)*10 + (y+1));
	matrix[x][y+1]='$';
	}
	if(x!=7 && matrix[x+1][y]!='1' && matrix[x+1][y]!='x'){//down
		if(matrix[x+1][y]=='d')
	return true;
	stacks.push((x+1)*10 + (y));
	matrix[x+1][y]='$';
	}
	if(y!=0 && matrix[x][y-1]!='1' && matrix[x][y-1]!='x'){//left
		if(matrix[x][y-1]=='d')
	return true;
	stacks.push((x)*10 + (y-1));
	matrix[x][y-1]='$';
	}
 }
	return false;
}
int main(){
	stacks.push(0);
	matrix[0][0]='$';
	queues.push(0);
      maze[0][0]='#';
    /*	for(int i=0;i<8;i++){
    	cout<<maze[i]<<endl;
    }*/
    
    cout<<endl<<endl;
    /*if(check())
    cout<<"YES";
    else
    cout<<"NO";
    cout<<endl;*/
    mazefn();
    
     for(int i=0;i<8;i++){
    	
    	cout<<matrix[i]<<endl;
    }
	//queuefn();
   
    
	return 0;
}
