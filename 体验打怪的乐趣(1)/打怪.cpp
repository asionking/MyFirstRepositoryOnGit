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
			cout<<"���ո����ʼ��Ϸ"<<endl;
			cout<<"��Q���ر���Ϸ"<<endl;
			while(true){
				int okey=_getch();
				if(okey==' '){
					system("cls");
					isBegin=true;
					justBegin=true;
					break;
				}else if(okey=='q'){
					cout<<"�Ƿ�Ҫ�رգ��رպ����ĵȼ���ȫ����գ���Y�� N����"<<endl;
					while(true){
						int key=_getch();
						if(key=='y'){
							return 0;
						}else if(key=='n'){
							system("cls");
							cout<<"���ո����ʼ��Ϸ"<<endl;
							cout<<"��Q���ر���Ϸ"<<endl;
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
				cout<<"����Ѫ��:"<<monsterHP<<endl;
				cout<<"���Ѫ��:"<<playerHP<<endl;
				if(monsterHP<=0){
					cout<<"���ﱻ����ˣ��������1��������F������"<<endl;
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
					cout<<"��ұ�����ˣ���ҽ���1��������F������"<<endl;
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
