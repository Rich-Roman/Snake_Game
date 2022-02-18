#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class snake {
public:
	snake() {

	};
	char getdir() {
		return dir;
	}
	pair<int,int> getHead() {
		return head;
	};

	void setHead(int newx, int newy) {
		head.first = newx;
		head.second = newy;
	}

	void setdir(char d) {
		dir = d;
	}
	void setSnake(int width, int height) {
		head.first = width/2;
		head.second = height/2;

		body.push_back(head);
	}
	pair<int, int> getBody(int i) {
		return body[i];
	}

	int getBodySize() {
		return body.size();
	};

	void growBody() {
		bodySize++;
	}

	bool eat(pair<int, int> f) {
		if (f.first == head.first && f.second == head.second) {
			return true;
		}
		return false;
	}

	void movement() {
		if (dir == 'w') {
			setHead(head.first, head.second - move);
		}
		else if (dir == 'a') {
			setHead(head.first - move, head.second);
		}
		else if (dir == 's') {
			setHead(head.first, head.second + move);
		}
		else if (dir == 'd') {
			setHead(head.first + move, head.second);
		}

		body.push_back(head);
		if (body.size() > bodySize) body.erase(body.begin());
	}

	bool collision(int width, int height) {
		if (head.first < 0 || head.first >= width-2 || head.second <= 0 || head.second > height-2) return true;

		for (int i = 0; i < bodySize - 1; i++)
		{
			if (head.first == body[i].first && head.second == body[i].second) return true;
		}
		return false;
		
	}


private:
	char dir = ' ';
	int move = 1;
	int bodySize = 1;

	pair<int,int> head;
	vector<pair<int, int>> body;
};