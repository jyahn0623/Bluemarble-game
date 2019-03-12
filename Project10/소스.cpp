#include <iostream>
#include <stdio.h>
#include <string>   
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
//��� ���� ����

//���� �����ϴ� Ŭ����
class user {
	int money;
	int user_loc;
	bool revial = false;
	string name;
public:
	user(int money, int user_loc) {
		cout << "�÷��̾� �̸� ����: ";
		cin >> name;
		this->name = name;
		this->money = money;
		this->user_loc = user_loc;
		cout << "���� ���� " << "��: " << this->money << "��" << endl;
		cout << endl;
	}
	int getMoney() { return money; } //�ش� ������ ���� ������ �´�.
	string getName() { return this->name; } //�ش� ������ �̸��� ������ �´�.
	void setMoney(int money) { this->money = money; } //�ش� ������ ���� �����Ѵ�.
	int getLoc(); //�ش� ������ ��ġ�� ������ �´�.
	void setLoc(int dice) { this->user_loc += dice; } //�ش� ������ ��ġ�� �����Ѵ�.
	void getRevial(bool boo) { this->revial = boo; } // ���� ��Ű 2�� ��å�� �����Ѵ�.
	bool isRevial() { return this->revial; } //��å ī���� ������ Ȯ���Ѵ�. 
};
int user::getLoc() {
	if (this->user_loc > 25) {
		cout << "�ڡڡڡڡ��� ���� ���ҽ��ϴ�. ���ʽ� 30�� �� ���ޡڡڡ�" << endl << endl;
		this->money += 300000;
		user_loc %= 26;
	}
	return this->user_loc;
}

// ���� ���� Ŭ����
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
	land(int num, string name, int price=0, int owner=5, int building = 1) { //������ �̸�, ����, ������, �������� ���ī������ �����Ѵ�.
		this->num = num;
		this->name = name;
		this->price = price;
		this->owner = owner;
		this->building = building;
		this->owner_name = "����";
	}

	int getPrice() { return this->price; } //�ش� ������ ����
	int getNumber() { return this->num;  }
	int getOwner() { return this->owner; } //�ش� ������ ������
	int getBuilding() { return this->building; } //�ش� ������ Ÿ��
	void setOwner(int i) { this->owner = i; } //�������� ���� ����
	void setOwner_name(string str) { this->owner_name = str; }//������ �̸� ����
	string getOwner_name() { return this->owner_name; } //������ �̸� �ҷ�����
	string getInfo() { return this->name; } //���� ���� �ҷ�����
	string getInfo(user* u1, user* u2) {
		if (u1->getLoc() == this->getNumber() && u2->getLoc() == this->getNumber())
			status = this->name + "�ܡ�";
		else if (u1->getLoc() == this->getNumber() && u2->getLoc() != this->getNumber())
			status = this->name + "�ܡ�";
		else if (u2->getLoc() == this->getNumber() && u1->getLoc() != this->getNumber())
			status = this->name + "�ۡ�";
		else
			status = this->name + "�ۡ�";

		if (this->getOwner_name() == u1->getName())
			status += "��";
		else if (this->getOwner_name() == u2->getName())
			status += "��";
		else if (this->building == 0)
			status += "��";
		else if (this->building == 1)
			status += "��";
		else
			status += "��";

		return status;
	}
};

//���� ��Ű ���� Ŭ����
class special_city : public land {
	int card = 0; // 3���� �������� �����ϱ� ���� ����
public:
	special_city() { cout << "���������������� ������ ���Խ��ϴ�.������������" << endl; }
	~special_city() { cout << "��������������������" << endl; }
    void special_effect(user *u); // �θ� Ŭ���� land�� �޼ҵ� ���� ���̵�
};

void special_city::special_effect(user *u) { // ������ �̴� �޼ҵ�
	srand((unsigned)time(NULL));
	card = rand() % 3 + 1;
	switch (card) {
		{
	case 1:
		cout << "���� ī�� 1: �ҿ��̿� ���� 30�� �� ��� " << endl;
		u->setMoney(u->getMoney() - 300000);
		break;
	case 2:
		cout << "���� ī�� 2: �Ļ� ��å" << endl;
		if (u->isRevial()) { cout << "�̹� �Ļ� ��å ī�带 ������ �ֽ��ϴ�."; }
		else u->getRevial(true);
		break;
	default:
		cout << "���� ī�� 3: �� " << endl;
		break;
		}
	}
};

//���� ����
class quizGame {
	int timer;
	int qz_num = 0;
	string quiz[3] = { "2018 ������ �츮�� ù ��° ����?", "�� ���α׷��� ���� ����� �̸���?", "c++ ������ �ð� �ִ� ��������?" };
	string answer[3] = { "������", "���ֿ�", "ȫ����" };
	string user_answer;
public:
	quizGame() { cout << "����������������忡 �����Ͽ����ϴ�.������������" << endl;}
	~quizGame() { cout << "��������������������" << endl; }
	void startGame(user *u) {
		srand((unsigned)time(NULL));
		this->qz_num = rand() % 3;

		cout << quiz[qz_num] << endl << "����: ";
		cin >> user_answer;

		if (answer[qz_num] != user_answer) {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}
		else {
			cout << "�¾ҽ��ϴ�. 10�� �� ����" << endl;
			u->setMoney(u->getMoney() + 100000);
		}
	}
};

//���ӿ� ���õ� Ŭ����
class game {
public:
	int dice = 0;
	int num = 0;
	int num1 = 0;  //turn üũ�� ���� ����
	int turn_count = 0; //���� �� ������ üũ ����
	int setMoney = 0; 
	user *u1, *u2; //���� �� ���� �ּҸ� ������ ������
	user *turn; //�� �ϸ��� ���� �� ���� �ּҸ� �����ϸ� ������ ������
	land *ld;

	//�ʱ�ȭ ����
	void init() {
		cout << "�ʱ� �ڱ��� �����ϼ���(����: �� ��): ";
		cin >> setMoney;
		cout << endl;
		turn_count = 1;
		u1 = new user(setMoney*10000, 0);
		u2 = new user(setMoney*10000, 0);
		ld = new land[26]
		{ land(0, "����", 0, 0, 0), land(1, "����", 200000, 0, 0), land(2, "�Ⱦ�", 150000, 0, 0),
			land(3, "��õ", 180000, 0, 0), land(4, "�λ�", 240000, 0, 0), land(5, "����", 250000, 0, 0),
			land(6, "����"), land(7, "õ��", 280000, 0, 0), land(8, "����", 310000, 0, 0),
			land(9, "���", 420000, 0, 0), land(10, "����", 370000, 0, 0), land(11, "��õ", 290000, 0, 0),
			land(12, "����", 0, 0, 2), land(13, "����", 300000, 0, 0), land(14, "����", 500000, 0, 0),
			land(15, "����", 370000, 0, 0), land(16, "�뱸", 490000, 0, 0), land(17, "��õ", 230000, 0, 0),
			land(18, "����", 380000, 0, 0), land(19, "����"), land(20, "ö��", 180000, 0, 0), 
			land(21, "����", 380000, 0, 0), land(22, "û��", 270000, 0, 0), land(23, "����", 420000, 0, 0),
			land(24, "����", 480000, 0, 0), land(25, "����")
		};
	}

	//���� ����
	void start() {
		cout << "������ �����մϴ�" << endl;
		cout << endl;
		turn = u1; //�ʱ� �� ����
		while (true) {
			turnOver();
			cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << turn->getName() << "���� ��" << endl;
			cout << "�ڵ����� �ֻ����� �����ϴ�." << endl;
			srand((unsigned)time(NULL));
			dice = rand() % 6 + 1;
			cout << "�ֻ��� ��: " << dice << endl;
			turn->setLoc(dice);
			cout << endl;
			cout << turn->getName() << "�Ԣ� " << dice << "ĭ �̵� " << "���� ��ġ: " << ld[turn->getLoc()].getInfo() << endl;
			cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
			if (turn->getLoc() != 0) { goLand(turn, (turn == u1) ? u2 : u1, &ld[turn->getLoc()]); }
			else startLine(turn);

			if (turn->getMoney() <= 0) {
				cout << turn->getName() << "���� �Ļ��Ͽ����ϴ�." << endl;

				if (turn->isRevial()) {
					cout << "�Ļ� ��å ī�带 ������ �ֽ��ϴ�. �Ļ��� ���Ͽ����ϴ�. 50�� �� �ڱ� ����" << endl;
					turn->setMoney(500000);
					turn->getRevial(false);
				}
				else {
					cout << "G A M E O V E R " << endl;
					break;
				}
			}
			cout << endl;
			cout << "���� ��: '1'";
			int next;
			cin >> next;
			cout << endl;

			system("cls");

			if (next == 1) {
				if (num1++ % 2 == 0) { turn = u2; }
				else {
					turn = u1;
					turn_count += 1; //���� ���� �� �ϼ� ����
				}
			}
		}
		cout << "���� ����" << endl;
		delete u1, u2, turn;
		delete[]ld;
	}

	//�ֻ����� �̵��� �Ǿ��� �� ����Ǵ� �޼ҵ�
	void goLand(user *u, user *u1, land *l) {	
		//���� �����ڰ� 0 ���ٸ�
		if (l->getBuilding() == 0) {
			cout << "���� �� ���� �����ڴ� " << l->getOwner_name() << "�Դϴ�." << endl << endl;
			if (l->getOwner() == 0 ) {
				cout << u->getName() << "���� ���� ���� �ݾ��� " << u->getMoney() << "�� �Դϴ�. " << u->getName() << "�� �ǹ��� �����Ͻðڽ��ϱ�? (1: ����, 2: ���)" << endl;
				cout << "�ǹ� �ŸŰ�: " << l->getPrice() << "��" << endl;
				cin >> num;
				if (num == 1) {
					if (u->getMoney() >= l->getPrice()) {
						cout << l->getInfo() << " ���� �Ϸ�" << endl;
						l->setOwner_name(u->getName());
						l->setOwner(1);
						u->setMoney(u->getMoney() - l->getPrice());
					}
					else
						cout << u->getName() << " �ݾ� ����" << endl;
				}
				else {
					cout << "���" << endl;
				}
			}
			// �����ڰ� 1�ִٸ�
			else if (l->getOwner() == 1) {
				// �����ڰ� �ִµ� �װ��� �ڽ��� �ƴ϶��
				if (l->getOwner_name() != u->getName()) {
					cout << "�� ���� ����� �������� �ƴմϴ�. ����� " << l->getPrice() << "�� �����մϴ�." << endl;
					u->setMoney(u->getMoney() - l->getPrice());
					cout << "���� �ݾ�: " << u->getMoney() << "��" << endl << endl;

					//�ڽ��� �ƴѵ� �μ��� ���� �ִٸ�
					if (u->getMoney() >= (l->getPrice()*1.1)) {
						cout << "����� �μ��� �� �ֽ��ϴ�. �μ� �Ͻðڽ��ϱ�? (1: �μ�, 2: ���)" << endl;
						cout << "�μ� ����: " << l->getPrice()*1.1 << "��" << endl;
						cin >> num;
						if (num == 1) {
							u->setMoney(u->getMoney() - (l->getPrice()*1.1));
							u1->setMoney(u1->getMoney() + (l->getPrice()*1.1));
							l->setOwner_name(u->getName());
							cout << u->getName() << "���� �μ��� �Ϸ��߽��ϴ�. " << "���� �ݾ�: " << u->getMoney() <<"��"<< endl;
							cout << u1->getName() << "���� �ݾ��� �μ� �ݾ׸�ŭ �߰� �ƽ��ϴ�. " << u1->getMoney() <<"��" << endl;
						}
					}
				}
				//�ڽ��� ���������
				else {
					cout << "�� ���� ����� �������Դϴ�." << endl;
				}
			}
		}
		else if (l->getBuilding() == 1) {
			// ���� ���� ������ Ÿ���̶��			
			special_city *sc = new special_city();
			sc->special_effect(u);
			delete sc;
		}

		else if (l->getBuilding() == 2) {
			// ���� ���� ������
			quizGame *qg = new quizGame();
			qg->startGame(u);
			delete qg;
		}
	}

	//���� ���ο� �� ���ٸ�
	void startLine(user *u) {
		cout << "���� ���� �������� ������ϴ�. 5�� �� ���ʽ� �����մϴ�." << endl;
		u->setMoney(u->getMoney() + 50000);
		cout << "���� �ݾ�: " << u->getMoney() << endl << endl;
	}

	//�� �ϸ��� ȭ���� ����
	void turnOver() {
		cout << "Made by Ahn Juyoung" << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "�� " << ld[6].getInfo(u1, u2) << "�� " << ld[7].getInfo(u1, u2) << "�� " << ld[8].getInfo(u1, u2) << "�� " << ld[9].getInfo(u1, u2) << "�� " << ld[10].getInfo(u1, u2) << "�� " << ld[11].getInfo(u1, u2) << "�� " << ld[12].getInfo(u1, u2) << "�� " << endl;
		cout << "�� " << ld[5].getInfo(u1, u2) << "                                                              " << ld[13].getInfo(u1, u2) << "�� �ѢѢѢѢѢѢѢѢѻ�Ȳ�ǢТТТТТТТ�" << endl;
		cout << "�� " << ld[4].getInfo(u1, u2) << "                                                              " << ld[14].getInfo(u1, u2) << "�� ���� �̸� -       " << u1->getName() << "        " << u2->getName() << endl;
		cout << "�� " << ld[3].getInfo(u1, u2) << "                                                              " << ld[15].getInfo(u1, u2) << "�� ���� ��ġ -        " << ld[u1->getLoc()].getInfo() << "          " << ld[u2->getLoc()].getInfo() << endl;
		cout << "�� " << ld[2].getInfo(u1, u2) << "                                                              " << ld[16].getInfo(u1, u2) << "�� �ݾ� ��Ȳ -      " << u1->getMoney() << "��     " << u2->getMoney() << "��" << endl;
		cout << "�� " << ld[1].getInfo(u1, u2) << "                                                              " << ld[17].getInfo(u1, u2) << "�� �� ī��Ʈ                   " << turn_count << endl;
		cout << "�� " << ld[0].getInfo(u1, u2) << "                                                              " << ld[18].getInfo(u1, u2) << "�� �Ļ� ��å ī�� -    " << (u1->isRevial() ? "��" : "NO") << "            " << (u2->isRevial() ? "��" : "NO") << endl;
		cout << "�� " << ld[25].getInfo(u1, u2) << "�� " << ld[24].getInfo(u1, u2) << "�� " << ld[23].getInfo(u1, u2) << "�� " << ld[22].getInfo(u1, u2) << "�� " << ld[21].getInfo(u1, u2) << "�� " << ld[20].getInfo(u1, u2) << "�� " << ld[19].getInfo(u1, u2) << "�� �ѢѢѢѢѢѢѢѢѾ��ֿ�1�ТТТТТТТ�" << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << u1->getName() << "�� ������ ���� ";
		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u1->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << u2->getName() << "�� ������ ���� ";

		for (int i = 0; i < 24; i++) {
			if (ld[i].getOwner_name() == u2->getName()) {
				cout << ld[i].getInfo() << " ";
			}
		}
		cout << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
	}
};


int main() {
	game g;
	g.init();
	g.start();	

	int k;
	cin >> k;

}