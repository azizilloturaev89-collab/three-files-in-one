#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int s,n,d;
    FILE *f,*g,*h,*k;
     do
    {   
        cout<<"Enter the number of elements int the files"<<endl;
        cout<<"the number should be greater than zero: ";cin>>n;
    } while (n<=0);
    f=fopen("first.dat","wb+");
    g=fopen("second.dat","wb+");
    h=fopen("third.dat","wb+");
    if(f==NULL)
    {
        cout<<"Mistake was occured while opening first file"<<endl;
        return 1;
    }
    if(g==NULL)
    {
        cout<<"Mistake was occured while opening second file"<<endl;
        return 1;
    }
    if(h==NULL)
    {
        cout<<"Mistake was occured while opening third file"<<endl;
        return 1;
    }
    //writing first file elements and printing they
    for (int i=0;i<n;i++)
    {
        s=rand()%100+1;
        fwrite(&s,sizeof(s),1,f);
        cout<<s<<" ";
    }
    cout<<endl;
    //writing second file elements and printing they
    cout<<"Second file elements"<<endl;
    for (int i=0;i<n;i++)
    {
        s=rand()%100+1;
        fwrite(&s,sizeof(s),1,g);
        cout<<s<<" ";
    }
    cout<<endl;
    //writing third file elements and printing they
    cout<<"Third file elements"<<endl;
    for (int i=0;i<n;i++)
    {
        s=rand()%100+1;
        fwrite(&s,sizeof(s),1,h);
        cout<<s<<" ";
    }
    d=ftell(f);
    rewind(f);
    rewind(g);
    rewind(h);
    k=fopen("fourth.dat","wb+");
    if(k==NULL)
    {
        cout<<"Mistake was occured while opening foutrh file"<<endl;
        return 1;
    }
    cout<<endl;
    while(d>0)
    {
        d=d-sizeof(int);
        fread(&s,sizeof(s),1,f);
        fwrite(&s,sizeof(s),1,k);
        fread(&s,sizeof(s),1,g);
        fwrite(&s,sizeof(s),1,k);
        fread(&s,sizeof(s),1,h);
        fwrite(&s,sizeof(s),1,k);
    }
    rewind(k);
    while(fread(&s,sizeof(s),1,k)==1)
    {
        cout<<s<<" ";
    }
    fclose(f);
    fclose(g);
    fclose(h);
    fclose(k);
    return 0;
}