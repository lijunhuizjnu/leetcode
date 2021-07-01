class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x=0,y=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                x+=(board[i][j]=='X');
                y+=(board[i][j]=='O');
            }
        }
        printf("%d %d\n",x,y);
        if((x!=y)&&(x!=y+1))return false;
        int k=0,h=0;
        if(board[0][0]==board[0][1]&&board[0][1]==board[0][2]){k+=board[0][0]=='O';h+=board[0][0]=='X';}
        if(board[1][0]==board[1][1]&&board[1][1]==board[1][2]){k+=board[1][0]=='O';h+=board[1][0]=='X';}
        if(board[2][0]==board[2][1]&&board[2][1]==board[2][2]){k+=board[2][0]=='O';h+=board[2][0]=='X';}
        if(board[0][0]==board[1][0]&&board[1][0]==board[2][0]){k+=board[0][0]=='O';h+=board[0][0]=='X';}
        if(board[0][1]==board[1][1]&&board[1][1]==board[2][1]){k+=board[0][1]=='O';h+=board[0][1]=='X';}
        if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]){k+=board[0][2]=='O';h+=board[0][2]=='X';}
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){k+=board[1][1]=='O';h+=board[1][1]=='X';}
        if(board[2][0]==board[0][2]&&board[2][0]==board[1][1]){k+=board[1][1]=='O';h+=board[1][1]=='X';}
        printf("%d %d\n",k,h);
        if(k*h!=0)return false;printf("1\n");
        if(x==y)if(h!=0)return false;printf("1\n");
        if(x==y+1)if(k!=0)return false;printf("1\n");
        return true;
    }
};
