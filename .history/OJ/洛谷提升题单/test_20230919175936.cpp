#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int map[5][10]={0};
    map[4][8]=10;
    map[1][7]=9;
    map[1][4]=20;
    sort(map[1][0],map[1][7]);

}