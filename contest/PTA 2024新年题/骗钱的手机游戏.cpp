#include<iostream>
using namespace std;
int main(){
    long long int a,b,c,d,e,f,g,h,i;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    while(a/2>1||b/3>1||c/2>1||d/3>1||e/2>1||f/3>1||g/2>1||h/3>1){
        if(a/2>1){
            b+=a/2;
            a=a%2;
        }
        if(b/3>1){
            c+=b/3;
            b=b%3;
        }
        if(c/2>1){
            d+=c/2;
            c=c%2;
        }
        if(d/3>1){
            e+=d/3;
            d=d%3;
        }
        if(e/2>1){
            f+=e/2;
            e=e%2;
        }
        if(f/3>1){
            g+=f/3;
            f=f%3;
        }
        if(g/2>1){
            h+=g/2;
            g=g%2;
        }
        if(h/3>1){
            i+=h/3;
            h=h%3;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i;
}