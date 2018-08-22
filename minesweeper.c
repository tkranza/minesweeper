#include <stdio.h>
#include <stdlib.h>


void gener(int a[][50],int k, int m, int n){

int i, j;

for(i=0; i<m; i++)
    for(j=0; j<n; j++)
       a[i][j] = -1;

while(k != 0){

    i = rand() % m;
    j = rand() % n;

if(a[i][j] != -2){

a[i][j] = -2;
--k;
}
}

}


void pros(int a[][50],int u, int v,int m,int n){

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

int m, n, a[50][50], k, i, j, kp, u,v, i2, j2, b, b2,u2,v2, z=0;
do{
printf(" unesi 1. dimenziju polja od 1 do 50 : ");
scanf(" %d", &m);
if(m<=0 || m>50) printf(" neispravan unos\n");
} while(m<=0 || m>50);
do{
printf(" unesi 2. dimenziju polja od 1 do 50 : ");
scanf(" %d", &n);
if(n<=0 || n>50) printf(" neispravan unos\n");
} while(n<=0 || n>50);
do{
printf(" koliko mina na polju ? : ");
scanf(" %d", &k);
if(k<=0) printf(" mora biti barem jedna mina u polju\n");
if(k>m*n) printf(" ne stane toliko mina u polje\n");
} while(k>m*n || k<=0);

srand(time(0));

gener(a,k,m,n);


for(i=0; i<m; i++)
for(j=0; j<n; j++){
        do{
        printf(" na koje polje zelite stati ? : ");
        scanf(" %d", &u2);
        printf(" i : ");
        scanf(" %d", &v2);
        u = u2 - 1;
        v = v2 - 1;
        if(u<0 || u>m-1 || v<0 || v >n-1) printf(" pogresan unos, ponovite ga \n");
        if(a[u][v] != -1 && a[u][v] != -2 && u>=0 && u<=m-1 && v>=0 && v<=n-1) printf(" tu ste vec bili\n");
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
