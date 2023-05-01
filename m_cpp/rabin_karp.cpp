#include "bits/stdc++.h"
using namespace std;

#define d 256 //total number of alphabets

void rabin_karp(char text[], char pattern[], int q){
    int n = strlen(text);
    int m = strlen(pattern);
    int p = 0, t = 0; //hash values of pattern and text
    int h = 1; //constant factor
    
    for(int i = 0; i < m-1; i++){
        h = (h*d)%q;
    }
    
    for(int i = 0; i<m; i++){
        p = (d*p + pattern[i])%q;
        t = (d*t + text[i])%q;
    }
    
    for(int i = 0; i<=(n - m); i++){
        if(p == t){
            int j;
            for(j = 0; j < m; j++){
                if(text[i+j] != pattern[j]){
                    break;
                }
            }
            if(j == m){
                cout<<"Pattern found at "<<i<<endl;
            }
        }
        if(i < n-m){
            t = (d*(t-text[i]*h)+text[i+m])%q;
            
            if(t<0){
                t = t + q;
            }
        }
    }
}

int main(){
    char txt[] = "STRINGSAMESTRINGSTR";
    char pat[] = "STR";
    int q = 11;
    rabin_karp(txt, pat, q);
    return 0;
}