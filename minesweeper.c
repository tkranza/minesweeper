#include <stdio.h>
#include <stdlib.h>

void pros(int a[][20],int u, int v,int m,int n){

int b = 0, i2,j2;

for(i2 = (u-1>0 ? u-1 : 0) ; i2<(u+2<m ? u+2 : m); i2++)
    for(j2 = (v-1>0 ? v-1 : 0); j2<(v+2<n ? v+2 : n); j2++){
            if(a[i2][j2] == -2) b++;
            }

a[u][v] = b;

if(b != 0) return;

if(b == 0){
    for(i2 = (u-1>0 ? u-1 : 0) ; i2<(u+2<m ? u+2 : m); i2++)
        for(j2 = (v-1>0 ? v-1 : 0); j2<(v+2<n ? v+2 : n); j2++){
            if(a[i2][j2] != 0) pros(a,i2,j2,m,n);
            }
}
}


int main(void){

int m, n, a[20][20], k, i, j, kp, u,v, i2, j2, b, b2;
do{
printf(" unesi 1. dimenziju polja : ");
scanf(" %d", &m);
if(m<=0) printf(" neispravan unos\n");
} while(m<=0);
do{
printf(" unesi 2. dimenziju polja : ");
scanf(" %d", &n);
if(n<=0) printf(" neispravan unos\n");
} while(n<=0);
do{
printf(" koliko mina na polju ? : ");
scanf(" %d", &k);
if(k>m*n) printf(" nestane toliko mina u polje\n");
} while(k>m*n);

srand(time(0));

do{
    kp = k;
for(i=0; i<m; i++){
for(j=0; j<n; j++){
        if(kp){
            a[i][j] = -(rand() % 3);
            if(a[i][j] == -2) kp--;
            else a[i][j] = -1;
        } else a[i][j] = -1;
}
}
}while(kp != 0);


for(i=0; i<m; i++)
for(j=0; j<n; j++){
        do{
        printf(" na koje polje zelite stati : ");
        scanf(" %d", &u);
        printf(" i : ");
        scanf(" %d", &v);
        if(u<0 || u>m-1 || v<0 || v >n-1) printf(" pogresan unos, ponovite ga \n");
        if(a[u][v] != -1 && a[u][v] != -2) printf(" tu ste vec bili\n");
        } while(u<0 || u>m-1 || v<0 || v >n-1 || a[u][v] != -1 && a[u][v] != -2);
if(a[u][v] == -2){
for(i=0; i<m; i++){
for(j=0; j<n; j++) {
        if(a[i][j] != -1 && a[i][j] != -2){
                        printf(" %d", a[i][j]);
} else printf(" %c", (a[i][j] == -1 ? '.' : '*'));
}
printf(" \n");
}
printf(" GAME OVER");
return;
}
if(a[u][v] == -1){
        b = 0;
        for(i2 = (u-1>0 ? u-1 : 0) ; i2<(u+2<m ? u+2 : m); i2++)
        for(j2 = (v-1>0 ? v-1 : 0); j2<(v+2<n ? v+2 : n); j2++){
            if(a[i2][j2] == -2) b++;
            }
            a[u][v] = b;

if(b==0) pros(a,u,v,m,n);

b2 = 0;

for(i2 = 0; i2<m; i2++)
        for(j2 = 0; j2<n; j2++){
  if(a[i2][j2] != -1 && a[i2][j2] != -2) b2++;
}

if(b2 != m*n-k){
for(i2 = 0; i2<m; i2++){
        for(j2 = 0; j2<n; j2++){
                if(a[i2][j2] != -1 && a[i2][j2] != -2){
                        printf(" %d", a[i2][j2]);
                }
        else printf(" .");
        }
        printf(" \n");
}
}

if(b2 == m*n-k) {
for(i=0; i<m; i++){
for(j=0; j<n; j++){
    if(a[i][j] != -1 && a[i][j] != -2){
                        printf(" %d", a[i][j]);
    } else printf(" %c", (a[i][j] == -1 ? '.' : '*'));
}
printf(" \n");
}
printf(" VICTORY");
return;


}
}
}

return 0;
}
