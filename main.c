#include <stdio.h>
#include <stdlib.h>

char box[3][3]={
  {'1','2','3'} ,
  {'4','5','6'} ,
  {'7','8','9'} };

typedef struct PlayerPos{
  char pos;
  }PlPo;

void Draw();
void Start();
char WhoIsWin();

int main()
{
    Start();

    Draw();
    char win = WhoIsWin();

    switch (win) {
      case 'X':
        printf("\n----> X Player is  Win! <----\n"); break;
      case 'O':
        printf("\n----> O Player is Win! <----\n"); break;
      default:
        printf("No Winner!\a\n");

}

  return 0;
}

void Draw(){
  system("clear");
  puts("----- TicTacToe Game -----\n");

  int i , j;

  for (i = 0; i < 3; i++) {
    for (j=0; j<3; j++){
      printf("\t%c | %c | %c\n",box[i][j],box[i][j+1],box[i][j+2]);
      printf("\t--|---|--\n");
      j += 3;
    }
  }
}

void Start(){


  char xo , posi;
  PlPo p1, p2 ;
  int i , j , n=0;

  printf("\n- - - > X or O: ");  scanf(" %c",&xo);

  switch (xo) {
    case 'x':
      p1.pos = 'X'; p2.pos = 'O'; break;
    case 'o':
      p1.pos = 'O'; p2.pos = 'X'; break;
    default:
      system("clear"); printf("------> Error! <------\a\n---> Chose X or O <---\n\n"); exit(1);
    }

  int fp = 1 ,sp = 2 , k;


  for(k=0; k<9; k++){
    Draw();

    n = (k%2==0) ? fp : sp;

    printf("\nPlayer <%d> Enter Your position: ",n);
    scanf(" %c",&posi);

  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
    {
      if(box[i][j] == posi && k%2==0)
        box[i][j] = p1.pos;
      else if(box[i][j] == posi && k%2==1)
        box[i][j] = p2.pos;
    }
  }
  if (WhoIsWin() != '.')
    return ;
}


}

char WhoIsWin(){

  int i , j;
  int xc = 0 , oc = 0;

  //Rows
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      if (box[i][j] == 'X') xc++;
      else if (box[i][j] == 'O') oc++;
      if(xc == 3 || oc == 3)
        return xc > oc ? 'X' : 'O';
    }xc =0, oc =0;
  }

  //Columns
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      if (box[j][i] == 'X') xc++;
      else if (box[j][i] == 'O') oc++;
      if(xc == 3 || oc == 3)
        return xc > oc ? 'X' : 'O';
    }xc =0, oc =0;
  }

  //Shaquli
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      if (i==j){
        if(box[i][j] == 'X') xc++;
        else if(box[i][j] == 'O') oc++;
        if (xc == 3 || oc == 3)
          return xc > oc ? 'X' : 'C';
      }
    }xc = 0 , oc = 0;
  }

  //Shaquli Ters
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      if (j == 2-i){
        if (box[i][j] == 'X') xc++;
        else if (box[i][j] == 'O') oc++;
        if (xc == 3 || oc == 3)
          return xc > oc ? 'X' : 'O';
      }
    }xc = 0 , oc = 0;
  }
  return '.';
}
