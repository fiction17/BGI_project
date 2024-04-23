#include <bits/stdc++.h>
#include <graphics.h>
int rem;//time remaining for both level1 level2
using namespace std;

int maxx,mayy,point=0;//maximum height, width, point
FILE *input= fopen("input.txt","r");// file of words

char poin[100];
char abc[100];
char s[1005][15];

struct high_scores
{

    char name[100];
    int scor;

};

struct high_scores hs[15];


void print_data()//printing high score in file
{
    FILE *output= fopen("score.txt","w");
    int i;
    for(i=0; i<3; i++)
    {
        fprintf(output,"%s\n",hs[i].name);
        printf("%s\n",hs[i].name);
        fprintf(output,"%d\n",hs[i].scor);
        printf("%d\n",hs[i].scor);
    }
    fclose(output);

}
void high_score_function(int score)
{

    int i,j,pos=0;
    char in[100];
    char fahim;
    setbkcolor(3);
    readimagefile("game.jpg",0,0,maxx,mayy);
    settextstyle(10,0,5);
    setcolor(0);
    outtextxy(500,200,"Write your name");//name of high scorer
    setviewport(200,400,600,450,1);
    clearviewport();
    while(1)
    {
        if(kbhit())//keyboard input
        {
            in[pos]=getch();
            while(kbhit())
            {
                fahim=getch();
            }
            if(in[pos]==8)//backspace handling
            {
                if(pos==0) continue;
                pos--;
                in[pos]='\0';
            }
            else
            {
                if(in[pos]==' '||in[pos]==13)//submitting word by enter or space
                {
                    in[pos]='\0';
                    break;
                }
                else pos++;
                in[pos]='\0';
            }
            setviewport(200,400,600,450,1);
            clearviewport();
            outtextxy(5,5,in);//showing word
        }
    }
    if (score>=hs[0].scor)//sorting
    {
        strcpy(hs[2].name,hs[1].name);
        hs[2].scor=hs[1].scor;
        strcpy(hs[1].name,hs[0].name);
        hs[1].scor=hs[0].scor;
        strcpy(hs[0].name,in);
        hs[0].scor=score;
    }
    else if(score>=hs[1].scor)
    {
        strcpy(hs[2].name,hs[1].name);
        hs[2].scor=hs[1].scor;
        strcpy(hs[1].name,in);
        hs[1].scor=score;
    }
    else if(score>=hs[2].scor)
    {
        strcpy(hs[2].name,in);
        hs[2].scor=score;
    }
    setviewport(0,0,maxx,mayy,1);
    cleardevice();
    return;
}

void upoin()//updating point
{
    char pnt[100];
    int i=0;
    int x=point;
    while(x)//converting integer to string
    {
        pnt[i++]=x%10+'0';
        x/=10;
    }
    if(i==0)
        pnt[0]='0',i++;
    pnt[i]='\0';
    for(int j=0; j<i/2; j++)
    {
        swap(pnt[j],pnt[i-j-1]);
    }
    strcpy(poin,"Your score: ");
    strcat(poin,pnt);
    setviewport(950,0,getmaxx(),50,1);
    setcolor(RED);
    outtextxy(20,5,poin);
    //setviewport(0,0,maxx,mayy,1);
}

void gameover()
{
    setviewport(0,0,maxx,mayy,1);
    cleardevice();
    settextstyle(10,0,7);
    char go[20];
    strcpy(go,"Game Over");
    setcolor(0);
    readimagefile("game.jpg",0,0,maxx,mayy);
    outtextxy(350,200,go);
    outtextxy(250,350,poin);
    delay(2000);
    return;
    //getch();
    //closegraph();
}

bool cmp(char s1[],char s2[],int x,int y)//comparing subsequence
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(y==len2&&x==len1)
        return 1;
    if(x==len1)
        return 0;
    if(s1[x]==s2[y])
        return cmp(s1,s2,x+1,y+1);
    else
        return cmp(s1,s2,x+1,y);
}

void print()//instructions
{
    setviewport(0,0,maxx,mayy,1);
    cleardevice();
    readimagefile("New folder/Screenshot (33).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (34).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (35).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (36).jpg",0,0,maxx,mayy);
    getch();
    readimagefile("New folder/Screenshot (38).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (37).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (39).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (40).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (41).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (42).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (43).jpg",0,0,maxx,mayy);
    getch();
    getch();
    readimagefile("New folder/Screenshot (44).jpg",0,0,maxx,mayy);
    getch();
    getch();
}

int level1()
{
    settextstyle(10,0,5);
    int rem=25;
    maxx=getmaxwidth(),mayy=getmaxheight();
    int window_1;
    window_1=initwindow(maxx,mayy);//maximizing window
    setcurrentwindow(window_1);
    char ck[17][20];//for keeping random words
    char in[15];//input from player
    for(int i=0; i<712; i++)//input from file
    {
        fscanf(input,"%s",s[i]);
    }
    int a[17],x;//status of a word and x for random number
    setbkcolor(0);
    cleardevice();
    srand(time(NULL));//for random, random function
    for(int i=0; ; i++)
    {
        setviewport(0,0,maxx,mayy,1);
        setbkcolor(0);
        readimagefile("k.jpg",0,0,maxx,mayy);//background image
        //setbkcolor(WHITE);
        for(int j=0; j<15; j++)//taking 15 words
        {
            if(j==14)//making combination of color
            {
                a[j]=1;
                setcolor(GREEN);
            }
            else
            {
                a[j]=rand()%3;
                if(a[j]==1)
                    setcolor(GREEN);
                else if(a[j]==2)
                    setcolor(BROWN);
                else
                    setcolor(RED);
            }
            x=rand()%712;
            strcpy(ck[j],s[x]);//keeping random word for compare
            int b=(50*(j/5));
            settextstyle(10,0,5);
            outtextxy(50+(j%5)*250,j+150+b,s[x]);//showing words
        }
        if(point>50)
        {
            outtextxy(100,600,"Level 2 unlocked.");
            outtextxy(100,670,"You may progress to level 2 after level 1");
        }
        char TIME[100];
        int time2,time,time1;
        int pos=0,k=0,j=0,b;
        upoin();
        setbkcolor(6);
        setviewport(100,500,1300,550,1);
        clearviewport();
        setcolor(0);
        if(i==0)
        {
            k=1;
            outtextxy(5,5,"write here");//waiting for start typing
            in[0]=getch();
            clearviewport();
            in[1]=NULL;
            outtextxy(5,5,in);
        }
        time1=clock();
        while(pos<15)
        {
            while(pos<15)
            {
                if(kbhit())//detecting keyboard click
                {
                    in[k]=getch();
                    if(in[k]==' '||in[k]==13)
                    {
                        setviewport(100,500,1300,550,1);
                        clearviewport();
                        setviewport(0,0,maxx,mayy,1);
                        if(point>50)
                        {
                            outtextxy(100,600,"Level 2 unlocked.");
                            outtextxy(100,670,"You may progress to level 2 completing level 1");
                        }
                        in[k]=NULL;
                        while(pos<15)
                        {
                            if(a[pos]==0)//red word comparing
                            {
                                b=50*(j/5);
                                outtextxy(50+(j%5)*250,j+150+b,ck[pos]);//changing color of typed words
                                j++;
                                if(strcmp(in,ck[pos])==0)
                                {
                                    //gameover();
                                    return time;
                                }
                                pos++;
                            }
                            if(a[pos]==2)//yellow word comparing
                            {
                                b=50*(j/5);
                                outtextxy(50+(j%5)*250,j+150+b,ck[pos]);
                                j++;
                                if(strcmp(in,ck[pos])==0)
                                {
                                    point+=strlen(in);
                                    upoin();
                                    pos++;
                                    k=0;
                                    break;
                                }
                                pos++;
                                if(pos==15)
                                {
                                    k=0;
                                    break;
                                }
                            }
                            if(a[pos]==1)//green word comparing
                            {
                                if(strcmp(in,ck[pos])!=0)
                                {
                                    //gameover();
                                    return time;
                                }
                                else
                                {
                                    b=50*(j/5);
                                    outtextxy(50+(j%5)*250,j+150+b,ck[pos]);//changing color of typed words
                                    j++;
                                    point+=strlen(in);
                                    upoin();
                                    pos++;
                                    k=0;
                                    break;
                                }
                            }
                        }
                        upoin();
                        k=0;
                        break;
                    }
                    if(pos>=15)
                    {
                        k=0;
                        break;
                    }
                    if(in[k]==8)//handling backspace
                    {
                        in[k]='\0';
                        k-=2;
                    }
                    in[k+1]='\0';
                    setviewport(100,500,1300,550,1);
                    clearviewport();
                    settextstyle(10,0,5);
                    printf("%s\n",in);
                    setcolor(0);
                    outtextxy(5,5,in);//showing input
                    //upoin();
                    k++;
                }
                setbkcolor(6);
                time2=clock();
                if(time!=((time2-time1)/CLOCKS_PER_SEC))//handling time
                {
                    setviewport(1200, 600, 1500, 675, 1);
                    time =rem- ((time2-time1)/CLOCKS_PER_SEC);
                    if(time<=0)
                    {

                        clearviewport();
                        return 0;
                    }
                    else
                    {
                        setviewport(1200, 600, 1500, 675, 1);
                        sprintf(TIME,"%d:%d", time/60,time%60);
                        if(time==9)
                            clearviewport();
                        setcolor(0);
                        outtextxy(0,0,"TIMER");
                        outtextxy(15,40,TIME);

                    }
                }
            }
        }
        setviewport(0,0,maxx,mayy,1);
        cleardevice();
        rem--;
        upoin();
    }
    //delay(200);
    //return time;
}

void level2()
{
    rem=20;
    settextstyle(10,0,7);
    srand(time(NULL));
    char in[50];
    setviewport(0,0,maxx,mayy,1);
    int a[7],x;
    clearviewport();
    int status[105];
    for(int i=0; ; i++)
    {
        char alu[100],balu[100],khalu[100];
        alu[0]='\0';
        balu[0]='\0';
        khalu[0]='\0';
        for(int j=0; j<5; j++)
        {
            x=rand()%712;
            strcat(alu,s[x]);
            //settextstyle(1,0,2);
            //outtextxy(i+50+j*200,j+50,s[x]);
            strcat(alu," ");
            //fprintf(output,"%d\n",i+j);
        }
        strcat(alu,"\0");
        printf("%s\n",alu);
        int len=strlen(alu);
        for(int i=0; i<len; i++)//handling status
        {
            if(alu[i]==' ') continue;
            status[i]=rand()%3;
            char extra[2];
            extra[0]=alu[i];
            extra[1]='\0';
            if(status[i]==0) strcat(balu,extra);//for comparing green words
            if(status[i]==0||status[i]==2) strcat(khalu,extra);//for comparing both yellow and green words
        }
        printf("%s\n",balu);
        int kk=0;
        setviewport(0,0,getmaxx(),getmaxy(),1);
        readimagefile("k.jpg",0,0,getmaxx(),getmaxy());
        //upoin();
        setbkcolor(0);
        for(int i=0; i<len; i++)//showing words
        {
            if(status[i]==0) setcolor(GREEN);
            if(status[i]==1) setcolor(RED);
            if(status[i]==2) setcolor(YELLOW);
            if(alu[i]==' ')
            {
                kk+=3;
                continue;
            }
            char extra[2];
            extra[0]=alu[i];
            extra[1]='\0';
            settextstyle(10,0,5);
            setviewport(0,0,getmaxx(),getmaxy(),1);
            outtextxy(50+kk*24,100,extra);
            kk++;

        }
        int pos=0;
        char fahim;
        char TIME[100];
        int time2,time,time1;
        upoin();
        setbkcolor(6);
        setviewport(100,500,1300,550,1);
        clearviewport();
        setcolor(0);
        if(i==0)
        {
            pos=1;
            outtextxy(5,5,"write here");
            in[0]=getch();
            clearviewport();
            in[1]=NULL;
            outtextxy(5,5,in);
        }
        time1=clock();

        while(1)
        {
            if(kbhit())
            {
                in[pos]=getch();
                if(in[pos]==8)
                {
                    if(pos==0) continue;
                    pos--;
                    in[pos]='\0';
                }
                else
                {
                    if(in[pos]==' '||in[pos]==13)
                    {
                        in[pos]='\0';
                        break;
                    }
                    else pos++;
                    in[pos]='\0';
                }
                setviewport(100,500,1300,550,1);
                clearviewport();
                //setcolor(0);
                //rectangle(1,1,1199,50);
                //setcolor(BROWN);
                //floodfill(5,5,0);
                setbkcolor(6);
                setcolor(0);
                outtextxy(5,5,in);
            }
            time2=clock();
            if(time!=(int)((time2-time1)/CLOCKS_PER_SEC))
            {
                setviewport(1200, 600, 1500, 670, 1);
                time =rem- (int)((time2-time1)/CLOCKS_PER_SEC);
                if(time<=0)
                {
                    clearviewport();
                    break;
                }
                else
                {
                    setviewport(1200, 600, 1500, 670, 1);
                    sprintf(TIME,"%d:%d", time/60,time%60);
                    if(time==9)
                    {
                        clearviewport();
                    }
                    setcolor(0);
                    outtextxy(0,0,"TIMER");
                    outtextxy(15,40,TIME);

                }
            }
        }
        if(cmp(in,balu,0,0)==0||cmp(khalu,in,0,0)==0)//comparing subsequence
        {
            rem--;
            setviewport(0,0,getmaxx(),getmaxy(),1);
            setbkcolor(RED);
            cleardevice();
            settextstyle(10,0,8);
            setcolor(4);
            if(time>0)
            {
                setcolor(0);
                outtextxy(400,300,"WRONG ANSWER");
                delay(2000);
                //getch();
                return ;
            }
            else
            {
                setcolor(0);
                outtextxy(450,300,"TIME OVER");
                delay(2000);
                return ;
            }
        }
        setviewport(0,0,maxx,mayy,1);
        cleardevice();
        point+=(strlen(in)+time*3);
        rem--;
        upoin();
    }
    setviewport(0,0,maxx,mayy,1);
    return;
}

int main(void)
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    maxx=getmaxwidth(),mayy=getmaxheight();
    int window_1;
    window_1=initwindow(maxx,mayy);
    setcurrentwindow(window_1);
    int ijk;
    FILE *inputt= fopen("score.txt","r");//taking high scores from file
    for(ijk=0; ijk<3; ijk++)
    {
        fscanf(inputt," %[^\n]",hs[ijk].name);
        fscanf(inputt,"%d",&hs[ijk].scor);
    }
    fclose(inputt);
    bool gg=0;
    int x,y;
    readimagefile("best.jpg",0,0,maxx,mayy);
    delay(3000);
    while(1)
    {
        readimagefile("normal11.jpg",0,0,maxx,mayy);
        int tt=0;
        while(1)
        {
            //cleardevice();
            //readimagefile("normal11.jpg",0,0,maxx,mayy);
            if(ismouseclick(WM_MOUSEMOVE))
            {
                getmouseclick(WM_MOUSEMOVE,x,y);
                if(x>=105 && x<=524 && y>=200 && y<=268)
                {
                    readimagefile("new.jpg",0,0,maxx,mayy);
                }
                else if(x>=113 && x<=564 && y>=446 && y<=519)
                {
                    readimagefile("Istructions11.jpg",0,0,maxx,mayy);
                }
                else if(x>=125 && x<=529 && y>=320 && y<=394)
                {
                    readimagefile("high score11.jpg",0,0,maxx,mayy);
                }
                else if(x>267&&x<411&&y>580&&y<648)
                    readimagefile("exit.jpg",0,0,maxx,mayy);
                else
                {
                    readimagefile("normal11.jpg",0,0,maxx,mayy);
                }
            }
            else if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);
                if(x>=105 && x<=524 && y>=200 && y<=268)
                    break;
                else if(x>=113 && x<=564 && y>=446 && y<=519)
                {
                    print();
                    cleardevice();
                    readimagefile("normal11.jpg",0,0,maxx,mayy);
                }
                else if(x>=125 && x<=529 && y>=320 && y<=394)
                {
                    setbkcolor(3);
                    setbkcolor(3);
                    cleardevice();
                    readimagefile("high.jpg",0,0,maxx,mayy);
                    setcolor(0);
                    settextstyle(10,0,6);
                    outtextxy(340,100,"1.");
                    outtextxy(400,100,hs[0].name);
                    sprintf(abc,"%d",hs[0].scor);
                    outtextxy(340,300,"2.");
                    outtextxy(650,100,abc);
                    outtextxy(400,300,hs[1].name);
                    sprintf(abc,"%d",hs[1].scor);
                    outtextxy(340,500,"3.");
                    outtextxy(650,300,abc);
                    outtextxy(400,500,hs[2].name);
                    sprintf(abc,"%d",hs[2].scor);
                    outtextxy(650,500,abc);
                    outtextxy(300,600,"press any key to back main menu");
                    getch();
                    cleardevice();
                    readimagefile("normal11.jpg",0,0,maxx,mayy);
                }
                else if(x>267&&x<411&&y>580&&y<648)
                {
                    gg=1;
                    break;
                }
                else
                {
                    readimagefile("normal11.jpg",0,0,maxx,mayy);
                }
            }
        }
        if(gg)
            break;
        //setviewport(0,0,maxx,mayy,1);
        setbkcolor(3);
        cleardevice();
        setcolor(WHITE);
        settextstyle(10,0,10);
        outtextxy(300,300,"Level 1");
        delay(1500);
        int t=level1();
        settextstyle(10,0,10);
        if(t<=0)
        {
            setviewport(0,0,maxx,mayy,1);
            setbkcolor(RED);
            cleardevice();
            setcolor(0);
            outtextxy(350,300,"TIME OVER");
            delay(2000);
        }
        else
        {
            setbkcolor(RED);
            cleardevice();
            setcolor(BLACK);
            outtextxy(350,300,"WRONG ANSWER");
            delay(2000);
        }
        setviewport(0,0,maxx,mayy,1);
        cleardevice();
        if(point>50)
        {
            setbkcolor(3);
            cleardevice();
            setcolor(WHITE);
            settextstyle(10,0,10);
            outtextxy(300,300,"Level 2");
            delay(1500);
            level2();
        }
        gameover();
        if(point>hs[2].scor)
        {
            delay(2000);
            cleardevice();
            printf("kjddf");
            high_score_function(point);
            print_data();
        }
        point=0;
    }
    return 0;
}
