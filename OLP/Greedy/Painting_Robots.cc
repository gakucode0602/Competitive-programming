#include<bits/stdc++.h>
using namespace std;

#define out std::cout
#define in std::cin
#define ln std::endl
#define ll long long
#define pb push_back
#define PB pop_back
#define For(i,a,b) for(int (i) = (a);(i) < (b);(i)++)
#define rof(i,a,b) for(int (i) = (a);(i) > (b);(i)--)
#define ite(i,c) for(auto &(i) : c)
#define iOS ios_base::sync_with_stdio(false)
#define MOD 1000000007
#define vt vector
#define SIZE 8



/*
Có 9 căn phòng (đánh số từ 1 đến 9) đã được quét vôi với màu trắng, xanh hoặc vàng. 
Có 9 robot (đánh số từ 1 đến 9) phụ trách việc quét vôi. Mỗi robot chỉ quét một số phòng nhất định. 
Việc quét vôi được thực hiện nhờ một chương trình cài sẵn theo qui tắc:
 -    Nếu phòng đang có màu trắng thì quét màu xanh
 -    Nếu phòng đang có màu xanh thì quét màu vàng
 -    Nếu phòng đang có màu vàng thì quét màu trắng
 Cần phải gọi lần lượt một số các robot ra quét vôi (mỗi lần một robot, một robot có thể gọi nhiều lần và có thể có robot không được gọi. Robot được gọi sẽ quét vôi tất cả các phòng mà nó phụ trách) để cuối cùng các phòng đều có màu trắng.
 Yêu cầu: Hãy tìm một phương án như vậy sao cho số lần gọi robot là ít nhất. Giả thiết rằng lượng vôi cho mỗi lượt quét đối với các phòng là như nhau. Đầu vào trong tập tin robots.inp có cấu trúc như sau:
 -    9 dòng đầu: dòng thứ i mô tả một danh sách các phòng do robot i phụ trách việc quét vôi. Mỗi dòng là một chuỗi các chữ số từ 1..9 biểu diễn các số hiệu của các phòng, các chữ số viết sát nhau.
 -    Dòng cuối mô tả màu vôi ban đầu của các phòng. Dòng gồm 9 ký tự viết sát nhau gồm toàn các chữ cái T (trắng), X (xanh), V(vàng) biểu diễn màu ban đầu của 9 phòng theo trật tự số hiệu.
 Đâu ra ghi vào tập tin robots.out dãy thứ tự các robot được gọi (số hiệu các robot được viết sát nhau và in ra kết quả có thứ tự từ điển bé nhất), ngược lại nếu không có phương án thì ghi 0.
*/

vt<string> robots = {
	"159",
	"123",
	"357",
	"147",
	"5",
	"369",
	"456",
	"789",
	"258"
};

string start = "XVXVXVTXT";
string target = "TTTTTTTTT";

vt<int> state(start.length(),0);
int num;
/*
Ta có thể suy ra được robot nào cứ sơn ba lần nó sẽ lại quay lại màu đầu tiên
=> Mỗi robots chỉ có thể sơn tối đa 2 màu 
*/

vt<int> best(start.length(),0);
int numBest = INT_MAX;

void fill(string &s,int i){
	// i : con robots thu i
	string rooms = robots[i];
	For(i,0,rooms.length()){
		int r = (rooms[i] - '0') - 1;
		switch(s[r]){
			case 'T':
				{
					s[r] = 'X';break;
				}
			case 'X':
				{
					s[r] = 'V';
					break;
				}
			case 'V':
				{
					s[r] = 'T';
					break;
				}
		}
	}
}

int chooseBest(){
	int max = INT_MIN;
	int selectedIndex = -1;

	For(i,0,9){
		if(state[i] < 2){
			string tmp = start;
			fill(tmp,i);
			int c = (int)count_if(tmp.begin(),tmp.end(),[](char t) {return t == 'T';});
			if(c > max){
				max = c;
				selectedIndex = i;
			}
		}
	}

	return selectedIndex;
}



void update(){
	if(num < numBest){
		numBest = num;
		best = state;
	}
}

void output(){
	For(i,0,best.size()){
		if(best[i] > 0){
			For(j,0,best[i]){
				out << i + 1;
			}
		}
	}
	out << ln;
}

void process(int idx)
{
	int i = chooseBest(); // Chọn thằng nào cho ra màu trắng nhiều nhất

	if(i >= 0){
		fill(start,i);
		state[i]++; // So lan no goi
		num++;

		if(start == target)
		{
			update();
		}
		else
		{
			process(idx + 1);
		}
		state[i]--;
		num--;

	}
}
int main(){
	process(0);
	output();
	return 0;
}