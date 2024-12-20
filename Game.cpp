#include<iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'x';
int row,column;
bool draw = false;

void display_board()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t\t TICK CROSS GAME"<<endl;
	cout<<"\tplayer1[x]\n";
	cout<<"\tplayer2[0]\n\n\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t\t\t\t\t_||\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t\t\t\t\t_||\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
}
void player_turn(){
	int choice;
	if(turn=='x')
	cout<<"\n\t\tplayer1[x]turn:";
	if(turn=='0')
	cout<<"\n\t\tplayer2[0]turn:";
	cin>>choice;
	switch(choice){
		case 1: row =0; column =0; break;
		case 2: row =0; column =1; break;
		case 3: row =0; column =2; break;
		case 4: row =1; column =0; break;
		case 5: row =1; column =1; break;
		case 6: row =1; column =2; break;
		case 7: row =2; column =0; break;
		case 8: row =2; column =1; break;
		case 9: row =2; column =2; break;
		default:
			cout<<"invalid choice\n";
			break;	
	}
	if(turn=='x'&& board[row][column]!='x'&&board[row][column]!='0')
	{
		board[row][column]= 'x';
		turn= '0';
	}
	else if(turn=='0'&& board[row][column]!='x'&&board[row][column]!='0')
	{
		board[row][column]= '0';
		turn= 'x';
	}
	else
	{
		cout<<"BOX already filled!\n please try again!!\n\n";
		player_turn();
	}
	display_board();
}
bool gameover(){
	//check win
	for(int i=0;i<3;i++)
	if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] || board[0][i]==board[1][i]&&board[0][i]==board[2][i] )
	return false;
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][0]==board[2][0])
	return false;
	//if there is any box not filled
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(board[i][j]!= 'x' && board[i][j]!= '0')
	return true;
	//draw game
	draw=true;
	return false;
}
int main()
{	
    while(gameover()){
    display_board();
	player_turn();
	gameover();
}
if(turn=='x' && draw==false)
cout<<"player2[0] wins !! congratulations\n";
if(turn=='0' && draw==false)
cout<<"player1[x] wins !! congratulations\n";
else
{
	cout<<"GAME�DRAW�!!\n";
}
}
