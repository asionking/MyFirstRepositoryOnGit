#include <iostream>
#include <conio.h>
#include <ctime>
#include <random>
using namespace std;
int main(){
	int playerLV=1,monsterLV=1;
	int playerAttackHp,monsterAttackHP;
	int playerHP,monsterHP;
	int oldPlayerHP=-1,oldMonsterHP=-1;
	int eStart=time(0),qStart=time(0);
	bool isBegin=false;
	bool justBegin=false;
	while(true){
		if(!isBegin){
			cout<<"按空格键开始游戏"<<endl;
			cout<<"按Q键关闭游戏"<<endl;
			while(true){
				int okey=_getch();
				if(okey==' '){
					system("cls");
					isBegin=true;
					justBegin=true;
					break;
				}else if(okey=='q'){
					cout<<"是否要关闭？关闭后您的等级将全部清空！（Y是 N不）"<<endl;
					while(true){
						int key=_getch();
						if(key=='y'){
							return 0;
						}else if(key=='n'){
							system("cls");
							cout<<"按空格键开始游戏"<<endl;
							cout<<"按Q键关闭游戏"<<endl;
							break;
						}
					}
				}
			}
		}
		else{
			if(justBegin){
				justBegin=false;
				srand(time(0));
				playerHP=playerLV*100;
				playerAttackHp=playerLV;
				monsterHP=monsterLV*1000;
				monsterAttackHP=monsterLV;
			}
			if(playerHP!=oldPlayerHP||monsterHP!=oldMonsterHP){
				oldPlayerHP=playerHP;
				oldMonsterHP=monsterHP;				
				system("cls");
				cout<<"怪物血量:"<<monsterHP<<endl;
				cout<<"玩家血量:"<<playerHP<<endl;
				if(monsterHP<=0){
					cout<<"怪物被打败了！玩家提升1级！（按F继续）"<<endl;
					if(playerLV<100)playerLV++;
					if(playerLV%10==0)monsterLV=playerLV;
					isBegin=false;
					while(true){
						if(_getch()=='f'){
							break;
						}
					}
					system("cls");
					continue;
				}
				if(playerHP<=0){
					cout<<"玩家被打败了！玩家降低1级！（按F继续）"<<endl;
					if(playerLV>1)playerLV--;
					if(playerLV%10==0)monsterLV=playerLV;
					isBegin=false;
					while(true){
						if(_getch()=='f'){
							break;
						}
					}
					system("cls");
					continue;
				}
			}
			if(_kbhit()){
				int key=_getch();
				if(key=='a'){
					monsterHP-=playerAttackHp;
				}else if(key=='e'){
					if(time(0)-eStart>=3){
						monsterHP-=playerAttackHp*10;
						eStart=time(0);
					}
				}else if(key=='q'){
					if(time(0)-qStart>=10){
						monsterHP-=playerAttackHp*100;
						playerHP+=playerAttackHp*10;
						qStart=time(0);
					}
				}else if(key=='f'){
					if(playerLV<100)playerLV++;
					if(playerLV%10==0)monsterLV=playerLV;
					isBegin=false;
					system("cls");
					continue;
				}
			}
			if(monsterHP!=oldMonsterHP){
				if(rand()%100+1<=20){
					monsterHP+=(oldMonsterHP-monsterHP)/2;
					playerHP-=monsterAttackHP;
				}
			}
		}
	}
	return 0;
}
