#include <iostream>
#include <stdio.h>
#include <string>   
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
//Çì´õ ÆÄÀÏ ¼±¾ð

//À¯Àú °ü¸®ÇÏ´Â Å¬·¡½º
class user {
	int money;
	int user_loc;
	bool revial = false;
	string name;
public:
	user(int money, int user_loc) {
		cout << "ÇÃ·¹ÀÌ¾î ÀÌ¸§ ÁöÁ¤: ";
		cin >> name;
		this->name = name;
		this->money = money;
		this->user_loc = user_loc;
		cout << "À¯Àú »ý¼º " << "µ·: " << this->money << "¿ø" << endl;
		cout << endl;
	}
	int getMoney() { return money; } //ÇØ´ç À¯ÀúÀÇ µ·À» °¡Áö°í ¿Â´Ù.
	string getName() { return this->name; } //ÇØ´ç À¯ÀúÀÇ ÀÌ¸§À» °¡Áö°í ¿Â´Ù.
	void setMoney(int money) { this->money = money; } //ÇØ´ç À¯ÀúÀÇ µ·À» ¼¼ÆÃÇÑ´Ù.
	int getLoc(); //ÇØ´ç À¯ÀúÀÇ À§Ä¡¸¦ °¡Áö°í ¿Â´Ù.
	void setLoc(int dice) { this->user_loc += dice; } //ÇØ´ç À¯ÀúÀÇ À§Ä¡¸¦ ¼³Á¤ÇÑ´Ù.
	void getRevial(bool boo) { this->revial = boo; } // Æ÷Ãá ÄíÅ° 2ÀÇ ¸éÃ¥À» ¼³Á¤ÇÑ´Ù.
	bool isRevial() { return this->revial; } //¸éÃ¥ Ä«µåÀÇ À¯¹«¸¦ È®ÀÎÇÑ´Ù. 
};
int user::getLoc() {
	if (this->user_loc > 25) {
		cout << "¡Ú¡Ú¡Ú¡Ú¡ÚÇÑ ¹ÙÄû µ¹¾Ò½À´Ï´Ù. º¸³Ê½º 30¸¸ ¿ø Áö±Þ¡Ú¡Ú¡Ú" << endl << endl;
		this->money += 300000;
		user_loc %= 26;
	}
	return this->user_loc;
}

// µµ½Ã °ü·Ã Å¬·¡½º
class land {
protected:
	string name;
	//string info;
	string status;
	int num;
	int owner;
	string owner_name;
	int price;
	int building;
public:
	land() {}
	land(int num, string name, int price=0, int owner=5, int building = 1) { //»ý¼ºÀÚ ÀÌ¸§, °¡°Ý, ¼ÒÀ¯ÀÚ, µµ½ÃÀÎÁö Çà¿îÄ«µåÀÎÁö °áÁ¤ÇÑ´Ù.
		this->num = num;
		this->name = name;
		this->price = price;
		this->owner = owner;
		this->building = building;
		this->owner_name = "¹ÌÁ¤";
	}

	int getPrice() { return this->price; } //ÇØ´ç Áö¿ªÀÇ °¡°Ý
	int getNumber() { return this->num;  }
	int getOwner() { return this->owner; } //ÇØ´ç Áö¿ªÀÇ ¼ÒÀ¯ÀÚ
	int getBuilding() { return this->building; } //ÇØ´ç Áö¿ªÀÇ Å¸ÀÔ
	void setOwner(int i) { this->owner = i; } //¼ÒÀ¯ÀÚÀÇ À¯¹« ¼³Á¤
	void setOwner_name(string str) { this->owner_name = str; }//¼ÒÀ¯ÀÚ ÀÌ¸§ ¼³Á¤
	string getOwner_name() { return this->owner_name; } //¼ÒÀ¯ÀÚ ÀÌ¸§ ºÒ·¯¿À±â
	string getInfo() { return this->name; } //Áö¿ª Á¤º¸ ºÒ·¯¿À±â
	string getInfo(user* u1, user* u2) {
		if (u1->getLoc() == this->getNumber() && u2->getLoc() == this->getNumber())
			status = this->name + "¡Ü¡Ü";
		else if (u1->getLoc() == this->getNumber() && u2->getLoc() != this->getNumber())
			status = this->name + "¡Ü¡Û";
		else if (u2->getLoc() == this->getNumber() && u1->getLoc() != this->getNumber())
			status = this->name + "¡Û¡Ü";
		else
			status = this->name + "¡Û¡Û";

		if (this->getOwner_name() == u1->getName())
			status += "¨ç";
		else if (this->getOwner_name() == u2->getName())
			status += "¨è";
		else if (this->building == 0)
			status += "¢Ã";
		else if (this->building == 1)
			status += "¢Ë";
		else
			status += "¢Æ";

		return status;
	}
};

//Æ÷Ãá ÄíÅ° Áö¿ª Å¬·¡½º
class special_city : public land {
	int card = 0; // 3°¡Áö ¾ÆÀÌÅÛÀ» ¼±ÅÃÇÏ±â À§ÇÑ º¯¼ö
public:
	special_city() { cout << "¦®¦¬¦¬¦¬¦¬¦¬Æ÷Ãá Áö¿ª¿¡ µé¾î¿Ô½À´Ï´Ù.¦¬¦¬¦¬¦¬¦¬¦¯" << endl; }
	~special_city() { cout << "¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å" << endl; }
    void special_effect(user *u); // ºÎ¸ð Å¬·¡½º landÀÇ ¸Þ¼Òµå ¿À¹ö ¶óÀÌµù
};

void special_city::special_effect(user *u) { // ¾ÆÀÌÅÛ »Ì´Â ¸Þ¼Òµå
	srand((unsigned)time(NULL));
	card = rand() % 3 + 1;
	switch (card) {
		{
	case 1:
		cout << "Æ÷Ãá Ä«µå 1: ºÒ¿ìÀÌ¿ô µ½±â 30¸¸ ¿ø ±âºÎ " << endl;
		u->setMoney(u->getMoney() - 300000);
		break;
	case 2:
		cout << "Æ÷Ãá Ä«µå 2: ÆÄ»ê ¸éÃ¥" << endl;
		if (u->isRevial()) { cout << "ÀÌ¹Ì ÆÄ»ê ¸éÃ¥ Ä«µå¸¦ °¡Áö°í ÀÖ½À´Ï´Ù."; }
		else u->getRevial(true);
		break;
	default:
		cout << "Æ÷Ãá Ä«µå 3: ²Î " << endl;
		break;
		}
	}
};

//ÄûÁî °ÔÀÓ
class quizGame {
	int timer;
	int qz_num = 0;
	string quiz[3] = { "2018 ¿ùµåÄÅ ¿ì¸®ÀÇ Ã¹ ¹øÂ° »ó´ë´Â?", "ÀÌ ÇÁ·Î±×·¥À» ¸¸µç »ç¶÷ÀÇ ÀÌ¸§Àº?", "c++ ¼ö¾÷À» ¸Ã°í ÀÖ´Â ±³¼ö´ÔÀº?" };
	string answer[3] = { "½º¿þµ§", "¾ÈÁÖ¿µ", "È«¼º¿õ" };
	string user_answer;
public:
	quizGame() { cout << "¦®¦¬¦¬¦¬¦¬¦¬ÄûÁî·£µå¿¡ µµÂøÇÏ¿´½À´Ï´Ù.¦¬¦¬¦¬¦¬¦¬¦¯" << endl;}
	~quizGame() { cout << "¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å¡å" << endl; }
	void startGame(user *u) {
		srand((unsigned)time(NULL));
		this->qz_num = rand() % 3;

		cout << quiz[qz_num] << endl << "Á¤´ä: ";
		cin >> user_answer;

		if (answer[qz_num] != user_answer) {
			cout << "Æ²·È½À´Ï´Ù." << endl;
		}
		else {
			cout << "¸Â¾Ò½À´Ï´Ù. 10¸¸ ¿ø Áö±Þ" << endl;
			u->setMoney(u->getMoney() + 100000);
		}
	}
};

//°ÔÀÓ¿¡ °ü·ÃµÈ Å¬·¡½º
class game {
public:
	int dice = 0;
	int num = 0;
	int num1 = 0;  //turn Ã¼Å©¸¦ À§ÇÑ º¯¼ö
	int turn_count = 0; //ÇöÀç ¸î ÅÏÀÎÁö Ã¼Å© º¯¼ö
	int setMoney = 0; 
	user *u1, *u2; //À¯Àú µÎ ¸íÀÇ ÁÖ¼Ò¸¦ ÁöÁ¤ÇÒ Æ÷ÀÎÅÍ
	user *turn; //¸Å ÅÏ¸¶´Ù À¯Àú µÎ ¸íÀÇ ÁÖ¼Ò¸¦ º¯°æÇÏ¸ç ÁöÁ¤ÇÒ Æ÷ÀÎÅÍ
	land *ld;

	//ÃÊ±âÈ­ ¼³Á¤
	void init() {
		cout << "ÃÊ±â ÀÚ±ÝÀ» ¼³Á¤ÇÏ¼¼¿ä(´ÜÀ§: ¸¸ ¿ø): ";
		cin >> setMoney;
		cout << endl;
		turn_count = 1;
		u1 = new user(setMoney*10000, 0);
		u2 = new user(setMoney*10000, 0);
		ld = new land[26]
		{ land(0, "½ÃÀÛ", 0, 0, 0), land(1, "¼ö¿ø", 200000, 0, 0), land(2, "¾È¾ç", 150000, 0, 0),
			land(3, "ÀÎÃµ", 180000, 0, 0), land(4, "ºÎ»ê", 240000, 0, 0), land(5, "Á¦ÁÖ", 250000, 0, 0),
			land(6, "Æ÷Ãá"), land(7, "Ãµ¾È", 280000, 0, 0), land(8, "°­¸ª", 310000, 0, 0),
			land(9, "¿ï»ê", 420000, 0, 0), land(10, "´ëÀü", 370000, 0, 0), land(11, "´ëÃµ", 290000, 0, 0),
			land(12, "ÄûÁî", 0, 0, 2), land(13, "¿©¼ö", 300000, 0, 0), land(14, "Æ÷Ç×", 500000, 0, 0),
			land(15, "ÀüÁÖ", 370000, 0, 0), land(16, "´ë±¸", 490000, 0, 0), land(17, "¿¬Ãµ", 230000, 0, 0),
			land(18, "±¤ÁÖ", 380000, 0, 0), land(19, "Æ÷Ãá"), land(20, "Ã¶¿ø", 180000, 0, 0), 
			land(21, "°­³²", 380000, 0, 0), land(22, "Ã»ÁÖ", 270000, 0, 0), land(23, "ÆÄÁÖ", 420000, 0, 0),
			land(24, "±¤±³", 480000, 0, 0), land(25, "Æ÷Ãá")
		};
	}

	//°ÔÀÓ ½ÃÀÛ
	void start() {
		cout << "°ÔÀÓÀ» ½ÃÀÛÇÕ´Ï´Ù" << endl;
		cout << endl;
		turn = u1; //ÃÊ±â ÅÏ ÁöÁ¤
		while (true) {
			turnOver();
			cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
			cout << turn->getName() << "´ÔÀÇ ÅÏ" << endl;
			cout << "ÀÚµ¿À¸·Î ÁÖ»çÀ§¸¦ ±¼¸³´Ï´Ù." << endl;
			srand((unsigned)time(NULL));
			dice = rand() % 6 + 1;
			cout << "ÁÖ»çÀ§ °ª: " << dice << endl;
			turn->setLoc(dice);
			cout << endl;
			cout << turn->getName() << "´Ô¢Ñ " << dice << "Ä­ ÀÌµ¿ " << "ÇöÀç À§Ä¡: " << ld[turn->getLoc()].getInfo() << endl;
			cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
			if (turn->getLoc() != 0) { goLand(turn, (turn == u1) ? u2 : u1, &ld[turn->getLoc()]); }
			else startLine(turn);

			if (turn->getMoney() <= 0) {
				cout << turn->getName() << "´ÔÀÌ ÆÄ»êÇÏ¿´½À´Ï´Ù." << endl;

				if (turn->isRevial()) {
					cout << "ÆÄ»ê ¸éÃ¥ Ä«µå¸¦ °¡Áö°í ÀÖ½À´Ï´Ù. ÆÄ»êÀ» ¸éÇÏ¿´½À´Ï´Ù. 50¸¸ ¿ø ÀÚ±Ý Áö±Þ" << endl;
					turn->setMoney(500000);
					turn->getRevial(false);
				}
				else {
					cout << "G A M E O V E R " << endl;
					break;
				}
			}
			cout << endl;
			cout << "´ÙÀ½ ÅÏ: '1'";
			int next;
			cin >> next;
			cout << endl;

			system("cls");

			if (next == 1) {
				if (num1++ % 2 == 0) { turn = u2; }
				else {
					turn = u1;
					turn_count += 1; //ÅÏÀÌ ³¡³¯ ¶§ ÅÏ¼ö Áõ°¡
				}
			}
		}
		cout << "°ÔÀÓ Á¾·á" << endl;
		delete u1, u2, turn;
		delete[]ld;
	}

	//ÁÖ»çÀ§·Î ÀÌµ¿ÀÌ µÇ¾úÀ» ¶§ ½ÇÇàµÇ´Â ¸Þ¼Òµå
	void goLand(user *u, user *u1, land *l) {	
		//¶¥ÀÇ ¼ÒÀ¯ÀÚ°¡ 0 ¾ø´Ù¸é
		if (l->getBuilding() == 0) {
			cout << "ÇöÀç ÀÌ °÷ÀÇ ¼ÒÀ¯ÀÚ´Â " << l->getOwner_name() << "ÀÔ´Ï´Ù." << endl << endl;
			if (l->getOwner() == 0 ) {
				cout << u->getName() << "´ÔÀÇ ÇöÀç °¡Áø ±Ý¾×Àº " << u->getMoney() << "¿ø ÀÔ´Ï´Ù. " << u->getName() << "´Ô °Ç¹°À» ±¸¸ÅÇÏ½Ã°Ú½À´Ï±î? (1: ±¸¸Å, 2: Ãë¼Ò)" << endl;
				cout << "°Ç¹° ¸Å¸Å°¡: " << l->getPrice() << "¿ø" << endl;
				cin >> num;
				if (num == 1) {
					if (u->getMoney() >= l->getPrice()) {
						cout << l->getInfo() << " ±¸¸Å ¿Ï·á" << endl;
						l->setOwner_name(u->getName());
						l->setOwner(1);
						u->setMoney(u->getMoney() - l->getPrice());
					}
					else
						cout << u->getName() << " ±Ý¾× ºÎÁ·" << endl;
				}
				else {
					cout << "Ãë¼Ò" << endl;
				}
			}
			// ¼ÒÀ¯ÀÚ°¡ 1ÀÖ´Ù¸é
			else if (l->getOwner() == 1) {
				// ¼ÒÀ¯ÀÚ°¡ ÀÖ´Âµ¥ ±×°ÍÀÌ ÀÚ½ÅÀÌ ¾Æ´Ï¶ó¸é
				if (l->getOwner_name() != u->getName()) {
					cout << "ÀÌ °÷Àº ´ç½ÅÀÇ ¼ÒÀ¯Áö°¡ ¾Æ´Õ´Ï´Ù. ÅëÇà·á " << l->getPrice() << "¸¦ ÁöºÒÇÕ´Ï´Ù." << endl;
					u->setMoney(u->getMoney() - l->getPrice());
					cout << "ÇöÀç ±Ý¾×: " << u->getMoney() << "¿ø" << endl << endl;

					//ÀÚ½ÅÀÌ ¾Æ´Ñµ¥ ÀÎ¼öÇÒ µ·ÀÌ ÀÖ´Ù¸é
					if (u->getMoney() >= (l->getPrice()*1.1)) {
						cout << "´ç½ÅÀº ÀÎ¼öÇÒ ¼ö ÀÖ½À´Ï´Ù. ÀÎ¼ö ÇÏ½Ã°Ú½À´Ï±î? (1: ÀÎ¼ö, 2: Ãë¼Ò)" << endl;
						cout << "ÀÎ¼ö °¡°Ý: " << l->getPrice()*1.1 << "¿ø" << endl;
						cin >> num;
						if (num == 1) {
							u->setMoney(u->getMoney() - (l->getPrice()*1.1));
							u1->setMoney(u1->getMoney() + (l->getPrice()*1.1));
							l->setOwner_name(u->getName());
							cout << u->getName() << "´ÔÀÌ ÀÎ¼ö¸¦ ¿Ï·áÇß½À´Ï´Ù. " << "ÇöÀç ±Ý¾×: " << u->getMoney() <<"¿ø"<< endl;
							cout << u1->getName() << "´ÔÀÇ ±Ý¾×ÀÌ ÀÎ¼ö ±Ý¾×¸¸Å­ Ãß°¡ µÆ½À´Ï´Ù. " << u1->getMoney() <<"¿ø" << endl;
						}
					}
				}
				//ÀÚ½ÅÀÇ ¼ÒÀ¯Áö¶ó¸é
				else {
					cout << "ÀÌ °÷Àº ´ç½ÅÀÇ ¼ÒÀ¯ÁöÀÔ´Ï´Ù." << endl;
				}
			}
		}
		else if (l->getBuilding() == 1) {
			// ¶¥ÀÌ Æ÷Ãá µµ½ÃÀÇ Å¸ÀÔÀÌ¶ó¸é			
			special_city *sc = new special_city();
			sc->special_effect(u);
			delete sc;
		}

		else if (l->getBuilding() == 2) {
			// ¶¥ÀÌ ÄûÁî ·£µå¶ó¸é
			quizGame *qg = new quizGame();
			qg->startGame(u);
			delete qg;
		}
	}

	//½ÃÀÛ ¶óÀÎ¿¡ µü µé¾î¼±´Ù¸é
	void startLine(user *u) {
		cout << "¿îÀÌ ÁÁ°Ô ½ÃÀÛÁ¡¿¡ ¸ØÃè½À´Ï´Ù. 5¸¸ ¿ø º¸³Ê½º Áö±ÞÇÕ´Ï´Ù." << endl;
		u->setMoney(u->getMoney() + 50000);
		cout << "ÇöÀç ±Ý¾×: " << u->getMoney() << endl << endl;
	}

	//¸Å ÅÏ¸¶´Ù È­¸éÀ» °»½Å
	void turnOver() {
		cout << "Made by Ahn Juyoung" << endl;
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		cout << "¦® " << ld[6].getInfo(u1, u2) << "¦¬ " << ld[7].getInfo(u1, u2) << "¦¬ " << ld[8].getInfo(u1, u2) << "¦¬ " << ld[9].getInfo(u1, u2) << "¦¬ " << ld[10].getInfo(u1, u2) << "¦¬ " << ld[11].getInfo(u1, u2) << "¦¬ " << ld[12].getInfo(u1, u2) << "¦¯ " << endl;
		cout << "¦­ " << ld[5].getInfo(u1, u2) << "                                                              " << ld[13].getInfo(u1, u2) << "¦­ ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ»óÈ²ÆÇ¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð" << endl;
		cout << "¦­ " << ld[4].getInfo(u1, u2) << "                                                              " << ld[14].getInfo(u1, u2) << "¦­ À¯Àú ÀÌ¸§ -       " << u1->getName() << "        " << u2->getName() << endl;
		cout << "¦­ " << ld[3].getInfo(u1, u2) << "                                                              " << ld[15].getInfo(u1, u2) << "¦­ À¯Àú À§Ä¡ -        " << ld[u1->getLoc()].getInfo() << "          " << ld[u2->getLoc()].getInfo() << endl;
		cout << "¦­ " << ld[2].getInfo(u1, u2) << "                                                              " << ld[16].getInfo(u1, u2) << "¦­ ±Ý¾× ÇöÈ² -      " << u1->getMoney() << "¿ø     " << u2->getMoney() << "¿ø" << endl;
		cout << "¦­ " << ld[1].getInfo(u1, u2) << "                                                              " << ld[17].getInfo(u1, u2) << "¦­ ÅÏ Ä«¿îÆ®                   " << turn_count << endl;
		cout << "¦­ " << ld[0].getInfo(u1, u2) << "                                                              " << ld[18].getInfo(u1, u2) << "¦­ ÆÄ»ê ¸éÃ¥ Ä«µå -    " << (u1->isRevial() ? "¡Ü" : "NO") << "            " << (u2->isRevial() ? "¡Ü" : "NO") << endl;
		cout << "¦± " << ld[25].getInfo(u1, u2) << "¦¬ " << ld[24].getInfo(u1, u2) << "¦¬ " << ld[23].getInfo(u1, u2) << "¦¬ " << ld[22].getInfo(u1, u2) << "¦¬ " << ld[21].getInfo(u1, u2) << "¦¬ " << ld[20].getInfo(u1, u2) << "¦¬ " << ld[19].getInfo(u1, u2) << "¦° ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¢Ñ¾ÈÁÖ¿µ1¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð¢Ð" << endl;
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
		cout << u1->getName() << "ÀÇ ¼ÒÀ¯ÇÑ ¶¥Àº ";
		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u1->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << u2->getName() << "ÀÇ ¼ÒÀ¯ÇÑ ¶¥Àº ";

		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u2->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << "¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬" << endl;
	}
};


int main() {
	game g;
	g.init();
	g.start();	

	int k;
	cin >> k;

}