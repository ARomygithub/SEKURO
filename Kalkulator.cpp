#include<bits/stdc++.h>
using namespace std;

#define ll long long

int k;

ll fastexpo(ll x, ll y) { //nilai double dioper dan disimpan dalam long long
  ll ret = 1; 
  while(y) { //expo dengan kompleksitas O(log y)
    if(y & 1) { ret = ret * x; }
    x = x * x;
    y >>= 1;
  }
  return ret;
}

int main() {
    cout <<"Kode        mode\n";
    cout <<"0       Aritmetika\n";
    cout <<"1       integral Riemann\n";
    cout <<"Masukkan kode: ";
    cin >>k;
    if(k==0) {// mode khusus +,-,*,/,pangkat
        double a,b; char c; //program menyimpan double untuk mengoperasikan bilangan real
        cout <<"Masukkan bilangan pertama: "; cin >>a;
        cout <<"Masukkan operasi (+, -, /, *, ^ (pangkat)): "; cin >>c;
        cout <<"Masukkan bilangan kedua: "; cin >>b;
        if(c=='+') {
            cout <<"Hasil: " <<a+b;
        } else if(c=='-') {
            cout <<"Hasil: " <<a-b;
        } else if(c=='*') {
            cout <<"Hasil: " <<a*b;
        } else if(c=='/') {
            cout <<"Hasil: " <<a/b;
        } else if(c=='^') {
            cout <<"Hasil: " <<fastexpo(a,b); //khusus untuk perpangkatan hanya untuk bilangan bulat
        }
    } else if(k==1) { // mode khusus integral tentu metode trapesium
        int n;
        cout <<"Masukkan pangkat tertinggi fungsi: "; cin >>n; //asumsi fungsi polinomial dan berkoefisien bilangan bulat
        int arr[n+1];
        for(int i=n;i>=0;i--) {
            cout <<"Masukkan koefisien x pangkat " <<i <<": "; cin >>arr[i];
        }
        double a,b,c; int c1;
        cout <<"Masukkan batas bawah: "; cin >>a;
        cout <<"Masukkan batas atas: "; cin >>b;
        cout <<"Masukkan banyak trapesium: "; cin >>c1;
        vector<double> f;
        bool kebalik =false;
        if(a>b) { //bila batas bawah > batas atas, hasil akhir dikali negatif
            swap(a,b);
            kebalik = true;
        }
        if(b==a) { // khusus b==a
            cout <<"Hasil: 0";
            return 0;
        }
        c = (b-a)/c1; //c adalah panjang subselang
        for(double i=a;i<=b;i+=c) {
            double f1=arr[n]; int x=n;
            while(x>0) { // penghitungan polinom
                f1 *= i;
                f1 += arr[x-1];
                x--;
            }
            f.push_back(f1); //simpan nilai f(a),..,f(b)
        }
        int sz= f.size();
        double res=0;
        for(int i=0;i<sz-1;i++) {
            res += (f[i]+f[i+1])/2; //totalkan alas2 trapesium
        }
        res *=c; // kali dengan tinggi trapesium
        if(kebalik) {
            res *= -1;
        }
        cout <<"Hasil: " <<res;
    }
    return 0;
}