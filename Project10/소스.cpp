#include <iostream>
#include <stdio.h>
#include <string>   
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
//④渦 だ橾 摹樹

//嶸盪 婦葬ж朝 贗楚蝶
class user {
	int money;
	int user_loc;
	bool revial = false;
	string name;
public:
	user(int money, int user_loc) {
		cout << "Ы溯檜橫 檜葷 雖薑: ";
		cin >> name;
		this->name = name;
		this->money = money;
		this->user_loc = user_loc;
		cout << "嶸盪 儅撩 " << "絲: " << this->money << "錳" << endl;
		cout << endl;
	}
	int getMoney() { return money; } //п渡 嶸盪曖 絲擊 陛雖堅 螞棻.
	string getName() { return this->name; } //п渡 嶸盪曖 檜葷擊 陛雖堅 螞棻.
	void setMoney(int money) { this->money = money; } //п渡 嶸盪曖 絲擊 撮たи棻.
	int getLoc(); //п渡 嶸盪曖 嬪纂蒂 陛雖堅 螞棻.
	void setLoc(int dice) { this->user_loc += dice; } //п渡 嶸盪曖 嬪纂蒂 撲薑и棻.
	void getRevial(bool boo) { this->revial = boo; } // ん轔 瓔酈 2曖 賊疇擊 撲薑и棻.
	bool isRevial() { return this->revial; } //賊疇 蘋萄曖 嶸鼠蒂 �挫恉挬�. 
};
int user::getLoc() {
	if (this->user_loc > 25) {
		cout << "≠≠≠≠≠и 夥襪 給懊蝗棲棻. 爾傘蝶 30虜 錳 雖晝≠≠≠" << endl << endl;
		this->money += 300000;
		user_loc %= 26;
	}
	return this->user_loc;
}

// 紫衛 婦溼 贗楚蝶
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
	land(int num, string name, int price=0, int owner=5, int building = 1) { //儅撩濠 檜葷, 陛問, 模嶸濠, 紫衛檣雖 ч遴蘋萄檣雖 唸薑и棻.
		this->num = num;
		this->name = name;
		this->price = price;
		this->owner = owner;
		this->building = building;
		this->owner_name = "嘐薑";
	}

	int getPrice() { return this->price; } //п渡 雖羲曖 陛問
	int getNumber() { return this->num;  }
	int getOwner() { return this->owner; } //п渡 雖羲曖 模嶸濠
	int getBuilding() { return this->building; } //п渡 雖羲曖 顫殮
	void setOwner(int i) { this->owner = i; } //模嶸濠曖 嶸鼠 撲薑
	void setOwner_name(string str) { this->owner_name = str; }//模嶸濠 檜葷 撲薑
	string getOwner_name() { return this->owner_name; } //模嶸濠 檜葷 碳楝螃晦
	string getInfo() { return this->name; } //雖羲 薑爾 碳楝螃晦
	string getInfo(user* u1, user* u2) {
		if (u1->getLoc() == this->getNumber() && u2->getLoc() == this->getNumber())
			status = this->name + "≒≒";
		else if (u1->getLoc() == this->getNumber() && u2->getLoc() != this->getNumber())
			status = this->name + "≒∞";
		else if (u2->getLoc() == this->getNumber() && u1->getLoc() != this->getNumber())
			status = this->name + "∞≒";
		else
			status = this->name + "∞∞";

		if (this->getOwner_name() == u1->getName())
			status += "函";
		else if (this->getOwner_name() == u2->getName())
			status += "刻";
		else if (this->building == 0)
			status += "〡";
		else if (this->building == 1)
			status += "〩";
		else
			status += "〤";

		return status;
	}
};

//ん轔 瓔酈 雖羲 贗楚蝶
class special_city : public land {
	int card = 0; // 3陛雖 嬴檜蠱擊 摹鷗ж晦 嬪и 滲熱
public:
	special_city() { cout << "旨收收收收收ん轔 雖羲縑 菟橫諮蝗棲棻.收收收收收旬" << endl; }
	~special_city() { cout << "∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪" << endl; }
    void special_effect(user *u); // 睡賅 贗楚蝶 land曖 詭模萄 螃幗 塭檜註
};

void special_city::special_effect(user *u) { // 嬴檜蠱 鉻朝 詭模萄
	srand((unsigned)time(NULL));
	card = rand() % 3 + 1;
	switch (card) {
		{
	case 1:
		cout << "ん轔 蘋萄 1: 碳辦檜醒 善晦 30虜 錳 晦睡 " << endl;
		u->setMoney(u->getMoney() - 300000);
		break;
	case 2:
		cout << "ん轔 蘋萄 2: だ骯 賊疇" << endl;
		if (u->isRevial()) { cout << "檜嘐 だ骯 賊疇 蘋萄蒂 陛雖堅 氈蝗棲棻."; }
		else u->getRevial(true);
		break;
	default:
		cout << "ん轔 蘋萄 3: 統 " << endl;
		break;
		}
	}
};

//襪鍔 啪歜
class quizGame {
	int timer;
	int qz_num = 0;
	string quiz[3] = { "2018 錯萄霰 辦葬曖 羅 廓簞 鼻渠朝?", "檜 Щ煎斜極擊 虜萇 餌塋曖 檜葷擎?", "c++ 熱機擊 蜆堅 氈朝 掖熱椒擎?" };
	string answer[3] = { "蝶錚筆", "寰輿艙", "�姨瑪�" };
	string user_answer;
public:
	quizGame() { cout << "旨收收收收收襪鍔楠萄縑 紫雜ж艘蝗棲棻.收收收收收旬" << endl;}
	~quizGame() { cout << "∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪∪" << endl; }
	void startGame(user *u) {
		srand((unsigned)time(NULL));
		this->qz_num = rand() % 3;

		cout << quiz[qz_num] << endl << "薑港: ";
		cin >> user_answer;

		if (answer[qz_num] != user_answer) {
			cout << "ぎ溜蝗棲棻." << endl;
		}
		else {
			cout << "蜃懊蝗棲棻. 10虜 錳 雖晝" << endl;
			u->setMoney(u->getMoney() + 100000);
		}
	}
};

//啪歜縑 婦溼脹 贗楚蝶
class game {
public:
	int dice = 0;
	int num = 0;
	int num1 = 0;  //turn 羹觼蒂 嬪и 滲熱
	int turn_count = 0; //⑷營 賃 欐檣雖 羹觼 滲熱
	int setMoney = 0; 
	user *u1, *u2; //嶸盪 舒 貲曖 輿模蒂 雖薑й ん檣攪
	user *turn; //衙 欐葆棻 嶸盪 舒 貲曖 輿模蒂 滲唳ж貊 雖薑й ん檣攪
	land *ld;

	//蟾晦�� 撲薑
	void init() {
		cout << "蟾晦 濠旎擊 撲薑ж撮蹂(欽嬪: 虜 錳): ";
		cin >> setMoney;
		cout << endl;
		turn_count = 1;
		u1 = new user(setMoney*10000, 0);
		u2 = new user(setMoney*10000, 0);
		ld = new land[26]
		{ land(0, "衛濛", 0, 0, 0), land(1, "熱錳", 200000, 0, 0), land(2, "寰曄", 150000, 0, 0),
			land(3, "檣繭", 180000, 0, 0), land(4, "睡骯", 240000, 0, 0), land(5, "薯輿", 250000, 0, 0),
			land(6, "ん轔"), land(7, "繭寰", 280000, 0, 0), land(8, "鬼葵", 310000, 0, 0),
			land(9, "選骯", 420000, 0, 0), land(10, "渠瞪", 370000, 0, 0), land(11, "渠繭", 290000, 0, 0),
			land(12, "襪鍔", 0, 0, 2), land(13, "罹熱", 300000, 0, 0), land(14, "んо", 500000, 0, 0),
			land(15, "瞪輿", 370000, 0, 0), land(16, "渠掘", 490000, 0, 0), land(17, "翱繭", 230000, 0, 0),
			land(18, "惜輿", 380000, 0, 0), land(19, "ん轔"), land(20, "繹錳", 180000, 0, 0), 
			land(21, "鬼陴", 380000, 0, 0), land(22, "羶輿", 270000, 0, 0), land(23, "だ輿", 420000, 0, 0),
			land(24, "惜掖", 480000, 0, 0), land(25, "ん轔")
		};
	}

	//啪歜 衛濛
	void start() {
		cout << "啪歜擊 衛濛м棲棻" << endl;
		cout << endl;
		turn = u1; //蟾晦 欐 雖薑
		while (true) {
			turnOver();
			cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
			cout << turn->getName() << "椒曖 欐" << endl;
			cout << "濠翕戲煎 輿餌嬪蒂 掉董棲棻." << endl;
			srand((unsigned)time(NULL));
			dice = rand() % 6 + 1;
			cout << "輿餌嬪 高: " << dice << endl;
			turn->setLoc(dice);
			cout << endl;
			cout << turn->getName() << "椒Ｃ " << dice << "蘊 檜翕 " << "⑷營 嬪纂: " << ld[turn->getLoc()].getInfo() << endl;
			cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
			if (turn->getLoc() != 0) { goLand(turn, (turn == u1) ? u2 : u1, &ld[turn->getLoc()]); }
			else startLine(turn);

			if (turn->getMoney() <= 0) {
				cout << turn->getName() << "椒檜 だ骯ж艘蝗棲棻." << endl;

				if (turn->isRevial()) {
					cout << "だ骯 賊疇 蘋萄蒂 陛雖堅 氈蝗棲棻. だ骯擊 賊ж艘蝗棲棻. 50虜 錳 濠旎 雖晝" << endl;
					turn->setMoney(500000);
					turn->getRevial(false);
				}
				else {
					cout << "G A M E O V E R " << endl;
					break;
				}
			}
			cout << endl;
			cout << "棻擠 欐: '1'";
			int next;
			cin >> next;
			cout << endl;

			system("cls");

			if (next == 1) {
				if (num1++ % 2 == 0) { turn = u2; }
				else {
					turn = u1;
					turn_count += 1; //欐檜 部陳 陽 欐熱 隸陛
				}
			}
		}
		cout << "啪歜 謙猿" << endl;
		delete u1, u2, turn;
		delete[]ld;
	}

	//輿餌嬪煎 檜翕檜 腎歷擊 陽 褒ч腎朝 詭模萄
	void goLand(user *u, user *u1, land *l) {	
		//階曖 模嶸濠陛 0 橈棻賊
		if (l->getBuilding() == 0) {
			cout << "⑷營 檜 夠曖 模嶸濠朝 " << l->getOwner_name() << "殮棲棻." << endl << endl;
			if (l->getOwner() == 0 ) {
				cout << u->getName() << "椒曖 ⑷營 陛霞 旎擋擎 " << u->getMoney() << "錳 殮棲棻. " << u->getName() << "椒 勒僭擊 掘衙ж衛啊蝗棲梱? (1: 掘衙, 2: 鏃模)" << endl;
				cout << "勒僭 衙衙陛: " << l->getPrice() << "錳" << endl;
				cin >> num;
				if (num == 1) {
					if (u->getMoney() >= l->getPrice()) {
						cout << l->getInfo() << " 掘衙 諫猿" << endl;
						l->setOwner_name(u->getName());
						l->setOwner(1);
						u->setMoney(u->getMoney() - l->getPrice());
					}
					else
						cout << u->getName() << " 旎擋 睡褶" << endl;
				}
				else {
					cout << "鏃模" << endl;
				}
			}
			// 模嶸濠陛 1氈棻賊
			else if (l->getOwner() == 1) {
				// 模嶸濠陛 氈朝等 斜匙檜 濠褐檜 嬴棲塭賊
				if (l->getOwner_name() != u->getName()) {
					cout << "檜 夠擎 渡褐曖 模嶸雖陛 嬴椎棲棻. 鱔ч猿 " << l->getPrice() << "蒂 雖碳м棲棻." << endl;
					u->setMoney(u->getMoney() - l->getPrice());
					cout << "⑷營 旎擋: " << u->getMoney() << "錳" << endl << endl;

					//濠褐檜 嬴棋等 檣熱й 絲檜 氈棻賊
					if (u->getMoney() >= (l->getPrice()*1.1)) {
						cout << "渡褐擎 檣熱й 熱 氈蝗棲棻. 檣熱 ж衛啊蝗棲梱? (1: 檣熱, 2: 鏃模)" << endl;
						cout << "檣熱 陛問: " << l->getPrice()*1.1 << "錳" << endl;
						cin >> num;
						if (num == 1) {
							u->setMoney(u->getMoney() - (l->getPrice()*1.1));
							u1->setMoney(u1->getMoney() + (l->getPrice()*1.1));
							l->setOwner_name(u->getName());
							cout << u->getName() << "椒檜 檣熱蒂 諫猿ц蝗棲棻. " << "⑷營 旎擋: " << u->getMoney() <<"錳"<< endl;
							cout << u1->getName() << "椒曖 旎擋檜 檣熱 旎擋虜躑 蹺陛 腑蝗棲棻. " << u1->getMoney() <<"錳" << endl;
						}
					}
				}
				//濠褐曖 模嶸雖塭賊
				else {
					cout << "檜 夠擎 渡褐曖 模嶸雖殮棲棻." << endl;
				}
			}
		}
		else if (l->getBuilding() == 1) {
			// 階檜 ん轔 紫衛曖 顫殮檜塭賊			
			special_city *sc = new special_city();
			sc->special_effect(u);
			delete sc;
		}

		else if (l->getBuilding() == 2) {
			// 階檜 襪鍔 楠萄塭賊
			quizGame *qg = new quizGame();
			qg->startGame(u);
			delete qg;
		}
	}

	//衛濛 塭檣縑 詞 菟橫摹棻賊
	void startLine(user *u) {
		cout << "遴檜 謠啪 衛濛薄縑 誇鏡蝗棲棻. 5虜 錳 爾傘蝶 雖晝м棲棻." << endl;
		u->setMoney(u->getMoney() + 50000);
		cout << "⑷營 旎擋: " << u->getMoney() << endl << endl;
	}

	//衙 欐葆棻 �飛橉� 偵褐
	void turnOver() {
		cout << "Made by Ahn Juyoung" << endl;
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		cout << "旨 " << ld[6].getInfo(u1, u2) << "收 " << ld[7].getInfo(u1, u2) << "收 " << ld[8].getInfo(u1, u2) << "收 " << ld[9].getInfo(u1, u2) << "收 " << ld[10].getInfo(u1, u2) << "收 " << ld[11].getInfo(u1, u2) << "收 " << ld[12].getInfo(u1, u2) << "旬 " << endl;
		cout << "早 " << ld[5].getInfo(u1, u2) << "                                                              " << ld[13].getInfo(u1, u2) << "早 ＣＣＣＣＣＣＣＣＣ鼻�笙ヨ苠苠苠苠苠苠苠�" << endl;
		cout << "早 " << ld[4].getInfo(u1, u2) << "                                                              " << ld[14].getInfo(u1, u2) << "早 嶸盪 檜葷 -       " << u1->getName() << "        " << u2->getName() << endl;
		cout << "早 " << ld[3].getInfo(u1, u2) << "                                                              " << ld[15].getInfo(u1, u2) << "早 嶸盪 嬪纂 -        " << ld[u1->getLoc()].getInfo() << "          " << ld[u2->getLoc()].getInfo() << endl;
		cout << "早 " << ld[2].getInfo(u1, u2) << "                                                              " << ld[16].getInfo(u1, u2) << "早 旎擋 ⑷�� -      " << u1->getMoney() << "錳     " << u2->getMoney() << "錳" << endl;
		cout << "早 " << ld[1].getInfo(u1, u2) << "                                                              " << ld[17].getInfo(u1, u2) << "早 欐 蘋遴お                   " << turn_count << endl;
		cout << "早 " << ld[0].getInfo(u1, u2) << "                                                              " << ld[18].getInfo(u1, u2) << "早 だ骯 賊疇 蘋萄 -    " << (u1->isRevial() ? "≒" : "NO") << "            " << (u2->isRevial() ? "≒" : "NO") << endl;
		cout << "曲 " << ld[25].getInfo(u1, u2) << "收 " << ld[24].getInfo(u1, u2) << "收 " << ld[23].getInfo(u1, u2) << "收 " << ld[22].getInfo(u1, u2) << "收 " << ld[21].getInfo(u1, u2) << "收 " << ld[20].getInfo(u1, u2) << "收 " << ld[19].getInfo(u1, u2) << "旭 ＣＣＣＣＣＣＣＣＣ寰輿艙1ＢＢＢＢＢＢＢＢ" << endl;
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
		cout << u1->getName() << "曖 模嶸и 階擎 ";
		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u1->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << u2->getName() << "曖 模嶸и 階擎 ";

		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u2->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收" << endl;
	}
};


int main() {
	game g;
	g.init();
	g.start();	

	int k;
	cin >> k;

}