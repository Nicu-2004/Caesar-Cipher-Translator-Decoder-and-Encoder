#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;
string Decode(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
        str[i]--;
        if(str[i]<'a')
            str[i]='z';
    }
    if(str[i]>='0' && str[i]<='9')
    {
        str[i]--;
        if(str[i]<'0')
            str[i]='9';
    }
    if(str[i]>='A' && str[i]<='Z')
        {
        str[i]--;
        if(str[i]<'A')
            str[i]='Z';
    }

    }

    return str;
}
string Encode(string str)
{
     for(int i=0;i<str.length();i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
        str[i]++;
        if(str[i]>'z')
            str[i]='a';
    }
    if(str[i]>='0' && str[i]<='9')
    {
        str[i]++;
        if(str[i]>'9')
            str[i]='0';
    }
    if(str[i]>='A' && str[i]<='Z')
        {
        str[i]++;
        if(str[i]>'Z')
            str[i]='A';
    }

    }

    return str;
}
int main()
{
    string mesaj;
    cout<<"mesajul = ";
    getline(cin,mesaj);
    int alegere;
    cout<<"ce vrei sa faci? 1 pt Encode 2 pt Decode ";
    cin>>alegere;
    while(alegere!=1 && alegere!=2)
    {
        cout<<"raspundeti doar cu 1 doriti Encode sau cu 2 daca doriti Decode ";
        cin>>alegere;
    }
    if(alegere==1)
    {
        int r;
        cout<<"de cate ori doriti sa dati Encode? ";
        cin>>r;
        int r2=r%25;
        while(r2!=0)
        {
            mesaj=Encode(mesaj);
            r2--;
        }
        cout<<"mesajul Encoded de "<<r<<" ori este "<<mesaj;
         ofstream fisier("note.txt");
        if(fisier.is_open())
        {
            fisier<<"mesajul Encoded e: "<<mesaj;
        }

        return 0;
    }
    if(alegere==2)
    {
    int descifrat;
    cout<<"e descifrat mesajul "<<mesaj<<" 1/0 ";
    cin>>descifrat;
    while(descifrat!=1 && descifrat!=0)
    {
        cout<<"raspundeti doar cu 1 daca e descifrat sau cu 0 daca nu e ";
        cin>>descifrat;
    }
    while(descifrat==0)
    {
    cout<<Decode(mesaj);
    cout<<" E descifrat? 1/0 ";
    cin>>descifrat;
    while(descifrat!=1 && descifrat!=0)
    {
        cout<<" raspundeti doar cu 1 daca e descifrat sau cu 0 daca nu e ";
        cin>>descifrat;
    }
    if(descifrat==1){
        ofstream fisier2("note2.txt");
        cout<<" mesajul crackat= "<<Decode(mesaj);
        if(fisier2.is_open())
        {
            fisier2<<"mesajul Decoded e: "<<Decode(mesaj);
        }
        return 0;
    }
    mesaj=Decode(mesaj);
    }
    }
}
