#include <stdio.h>

int arr[10][10];
int box_visited[4][4][10];
int width_visited[10][10];
int length_visited[10][10];
char string[11][11];

int f(int x, int y)
{
    //return statement
    if(y==10) return true;

    //already filled?
    if(arr[y][x] != 0) return f(x+1,y);
    
    //need to go next line?
    if(x==10) return f(1,y+1);
    

    for(int num=1;num<=9;num++){
        if(!box_visited[(y+2)/3][(x+2)/3][num] && !width_visited[y][num] && !length_visited[x][num])
        {
            box_visited[(y+2)/3][(x+2)/3][num] = 1;
            width_visited[y][num] = 1;
            length_visited[x][num] = 1;
            arr[y][x] = num;
            //track deeper, and no problem,
            if(f(x+1, y)) return true;

            //if not,
            box_visited[(y+2)/3][(x+2)/3][num] = 0;
            width_visited[y][num] = 0;
            length_visited[x][num] = 0;
            arr[y][x] = 0;
        }
    }

    //if all the cases in current session is impossible,
    return false;
}

int main()
{
    //input
    for(int i=1;i<=9;i++)
        scanf("%s", string[i]);

    //init
    for(int i=1;i<=9;i++){
        for(int j=0;j<9;j++){
            int value = arr[i][j+1] = string[i][j] - '0'; //character to number which isn't ascii code.

            //init visit array
            box_visited[(i+2)/3][(j+3)/3][value] = width_visited[i][value] = length_visited[j+1][value] = 1;
        }
    }

    //backtracking
    f(1,1);
    
    //output answer
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++) printf("%d",arr[i][j]);
        printf("\n");
    }
    return 0;
}