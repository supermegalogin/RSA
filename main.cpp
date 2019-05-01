#include <iostream>

using namespace std;

class RSA{
public:
//    long   p=77777747, q=64284739;
   long   p=9887, q=9901;
    long m=p*q, fi=(p-1)*(q-1), e=seaE(),d= seaD();

    RSA(){
        cout<<endl<<"RSA start";
        //start();
    }

    void start(){
        cout<<endl<<"m="<<m
           <<endl<<"fi="<<fi
          <<endl<<"e="<<e
         <<endl<<"d="<<d;
        char str[10],n[10];
        int a[10];
        long    b[10],c[10];
        cout<<endl<<"word: "; cin>>str;
        cout<<endl<<"a\tb\tc";
        int i=0;
        for (i;i<10;i++) {
            if(str[i]==0) break;
            a[i]=(int) str[i];
            b[i]=fastPower(a[i],e,m);
            c[i]=fastPower(b[i],d,m);
            n[i]=(char) c[i];
            cout<<endl<<a[i]<<"\t"<<b[i]<<"\t"<<c[i];
        }
        n[i]='\0';
        cout<<endl<<"END: "<<n<<endl;





    }

    long   seaE(){
        long   s= random() % 10000+1000;
        cout<<endl<<"e0= "<<s<<endl;
        if(Nod(s)!=1) {
            s=seaE();
            return s;
        }
        cout<<endl<<"e= "<<s<<endl;

        return s;}



    long   Nod(long   a){
        long   b=fi;
        cout<<endl<<"( "<<a<<", "<<b<<" )= ";
        long   q,r=-1;
        for(;;) {
            r=a%b;
            if(r==0) break;
            q=a/b;
            a=b;
            b=r;
        }
        cout<<b<<endl;
        return b;}

    long   seaD(){

        long    b=fi, a=e;
        cout<<endl<<a<<"x+"<<b<<"y=1";
        long   q,r;
        long   e11=1,e12=0,e21=0,e22=1; // ед матрица Е=((1 0) (0 1))
        long   E11,E12,E21,E22; // ячейки для замены при расчете умножения матриц

        for (;;) {
            r=a%b;
            if(r==0) break;
            q=a/b;
            a=b;
            b=r;
            // Е=Е * ((0 1) (1 -q))
            E11=e12;
            E21=e22;
            E12=e11-q*e12;
            E22=e21-q*e22;
            // Вставка замены
            e11=E11;
            e12=E12;
            e21=E21;
            e22=E22;

        }

        cout<<endl<<"x= "<<e12<<endl<<"y= "<<e22<<endl;
        if(e12<0) e12+=fi;
        return e12;

    }

    long fastPower(int num,long pow, long pole){

            int size=0;
            long long ans=num;
            long numb=num;
            int bitNum[1000];

            while (pow!=1) {
                bitNum[size]=pow%2;
                size++;
                pow=pow/2;

            }
            bitNum[size]=1;
            size--;
            for (;size>=0;size--) {
                if(bitNum[size]==0) {ans=ans*ans%pole;
                }else {
                 ans=ans*ans*numb%pole;
                }
            }
           // cout<<endl<<"Результат= "<<ans<<endl;
            return ans;
    }

    long fastPower(long numb,long pow, long pole){

            int size=0;
            long long ans=numb;
            int bitNum[1000];
            unsigned long long A=ans;

            while (pow!=1) {
                bitNum[size]=pow%2;
                size++;
                pow=pow/2;

            }
            bitNum[size]=1;
            size--;
            for (;size>=0;size--) {
                if(bitNum[size]==0) {
                    A=ans*ans;
                    A%=pole;
                    ans=A;
                }else {
                    A=ans*ans;
                    A%=pole;
                    A=A*numb;
                    A%=pole;
                 ans=A;
                }
            }
           // cout<<endl<<"Результат= "<<ans<<endl;
            return ans;
    }

    long   fastPower2(int num, long   pow, long   pole){


        long   ans=num;
        long long numb=num;
        pow=pow/2;
        while (pow!=0) {
            numb=numb*numb%pole;
            if(pow%2==1){
                ans=ans*numb%pole;
                //if(ans<0) ans+=pole;
            }
            pow=pow/2;
        }
        //cout<<endl<<"Результат= "<<ans<<endl;
        return ans;
    }

    long long  fastPower2(long   num, long   pow, long   pole){


        long long  ans=num;
          unsigned long long numb=num/*, pole=pol*/;

        pow=pow/2;
        while (pow!=0) {
            numb=numb*numb%pole;
            if(pow%2==1){
                ans=ans*numb%pole;
               // if(ans<0) ans+=pole;
            }
            pow=pow/2;
        }
        //cout<<endl<<"Результат= "<<ans<<endl;
        return ans;
    }


};

int main()
{
    RSA obj;
    obj.start();

    return 0;
}


