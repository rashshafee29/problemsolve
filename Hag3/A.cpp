#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tt, h, m, time;
    cin>>tt;
    while (tt--)
    {
        scanf("%d:%d",&h,&m);
        time = h*60 + m;
        if (time>720) 
            time-=720;
        time = 720-time;
        h = (time/60);
        m = time%60;
        if (!h) h = 12;
        if (h<10)
            printf("0%d:",h);
        else
            printf("%d:",h);
        if (m<10)
            printf("0%d\n",m);
        else
            printf("%d\n",m);
    }
    return 0;
}