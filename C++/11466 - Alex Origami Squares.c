#include<stdio.h>
int main()
{
    double h,w,temp;
    scanf("%1f %1f", &h, &w);
    if(h<w)
    {
        temp =w;
        w=h;
        h=temp;
    }

    if(h>w*3)
        printf("%1f", w);
    else
    {
        double a= h/3.0;
        double b = w/2.0;

        if(a>b)
            printf("%lf", a);
        else
            printf("%lf", b);
    }
}
