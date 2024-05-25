#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

// fuctions
void setup();
int draw();
void input();
int logic();
int logic2();

// data members
int height=20;
int width=20;
int tx[100],ty[100],ntail;
int fruitx,fruity;
int x,y;
int score;
bool gameover;
enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;
// for levels
int level;

void setup()
{
    y=height/2;
    dir=STOP;
    x=width/2;
    fruity=rand() % 20;
    fruitx=rand() % width;
    ntail=0;
    score=0;
    cout<<"WELCOME IN SNAKE GAME !\n\n\n";
    // cout<<"press any key to start game";
    system("pause");
    system("cls");
    cout<<"1. EASY\n";
    cout<<"2. HARD\n";
    cout<<"3. EXIT\n";
    cin>>level;
}

int draw()
{
 system("cls");
 cout << endl;
 for(int i=0; i<width+2; i++){
     cout<<"#";}
  cout<<endl;
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
        if(j==0)
        cout<<"#";
        if(i==y && j==x)
        cout<<"O";
        else if(i==fruitx && j==fruity)
        cout<<"@";
        else
        {
            bool print=false;
            for( int k = 0 ; k < ntail ; k++ )
            {
                if( tx[k] == j &&  ty[k] == i )
                {
                    cout<<"o";
                     print=true;
                }
               
            }
            if(!print)
            cout<<" ";
         }
         if(j==width-1)
         cout<<"#";
      }
    cout<<endl;
  }
     for(int p=0; p<width+2; p++){
       cout<<"#";}
       cout<<"\nScore : "<<score;
}

void input()
{ 
    if(kbhit())
    {
        switch (getch())
        {
        case 'w':
           dir= UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'a':
            dir= LEFT;
            break;
        case 'd':
            dir= RIGHT;
            break;
        case 'x' :
        gameover=true;
        default:
            break;
        }
    }

}

int logic()
{
    int px=tx[0];
    int py=ty[0];
    int p2x,p2y;
    tx[0]=x;
    ty[0]=y;
    for(int i=1; i<ntail;i++)
    {
        p2x=tx[i];
        p2y=ty[i];
        tx[i]=px;
        ty[i]=py;
        px=p2x;
        py=p2y;
    }

    switch(dir)
    {
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        case LEFT:
        x--;  
        break;
        case RIGHT:
        x++;
        break;
        default:
        break;
    }
    if(level==2);
    {
      if(y>height || y<0 || x>width || x<0)
      gameover=true;
    }
    
    
   
    

    for (int i = 0; i < ntail; i++)
        if (tx[i] == x && ty[i] == y)
            gameover = true;

    if(y==fruitx && x==fruity)
    {
        srand(time(0));
        score=+10;
        fruity=rand() % height;
        fruitx=rand() % width;
        ntail++;
        
        
    }

}
int logic2()
{
    int px=tx[0];
    int py=ty[0];
    int p2x,p2y;
    tx[0]=x;
    ty[0]=y;
    for(int i=1; i<ntail;i++)
    {
        p2x=tx[i];
        p2y=ty[i];
        tx[i]=px;
        ty[i]=py;
        px=p2x;
        py=p2y;
    }

    switch(dir)
    {
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        case LEFT:
        x--;  
        break;
        case RIGHT:
        x++;
        break;
        default:
        break;
    }
  // Check if the snake hits the wall
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i = 0; i < ntail; i++)
        if (tx[i] == x && ty[i] == y)
            gameover = true;

    if(y==fruitx && x==fruity)
    {
        srand(time(0));
        score=+10;
        fruity=rand() % height;
        fruitx=rand() % width;
        ntail++;
        
        
    }

}

int main()
{
   
    
   
    setup();
    if(level==2)
    {
     // //Will make cout much faster
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    system("MODE con cols=24 lines=25");
    while(!gameover)
    {
    draw();
    cout<<endl;
    input();
    logic();
    Sleep(50);
    }
    }
    else if(level==1)
    {
     // //Will make cout much faster
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    system("MODE con cols=24 lines=25");
    while(!gameover)
    {
    draw();
    cout<<endl;
    input();
    logic2();
    Sleep(50);
    }

    }
    else{
        system("cls");
    }
    
}

