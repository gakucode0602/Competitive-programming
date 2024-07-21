#include<bits/stdc++.h>
using namespace std;

#define out std::cout
#define in std::cin
#define end std::endl
#define ll long long
#define pb push_back
#define PB pop_back
#define For(i,a,b) for(int (i) = (a);(i) < (b);(i)++)
#define rof(i,a,b) for(int (i) = (a);(i) > (b);(i)--)
#define ite(i,c) for(auto &(i) : c) 
#define iOS ios_base::sync_with_stdio(false)

/*
genaral pseudocode

void backtrack(int pos){

	// trường hợp cơ sở
	if(<pos> là vị trí cuối cùng)
	{
		<out/lưu lại tập hợp đã dựng nếu thỏa mãn>
		return;
	}

	// phần đệ quy
	for(<tất cả giá trị i có thể ở vị trí pos>)
	{
		<thêm giá trị vào tập danh sách>
		backtrack(pos + 1);
		<xóa bỏ giá trị i khỏi tập đang xét>
	}
}

*/


// Sinh dãy nhị phân
// Liệt kê tất cả các dãy nhị phân có độ dài n

//int n;
// string curString;

// void genString(int pos){
// 	if(pos > n){
// 		out << curString << end;
// 		return;
// 	}
// 	for(char i = '0'; i <= '1';i++){
// 		curString.push_back(i);
// 		genString(pos + 1);
// 		curString.pop_back();
// 	}
// }


// Bài toán phân tích số
/**
 * Ở một quốc gia có n
 * loại tiền gồm các mệnh giá a1,a2,…,an (n≤10).
 * Có những cách nào để lấy các tờ tiền sao cho 
 * tổng mệnh giá của chúng là S ? Biết rằng mỗi
 * mệnh giá tiền có thể được lấy nhiều lần và 
 * hai cách lấy là hoán vị của nhau chỉ tính là một.
 * 
**/

// int n,a[15];
// ll S,curMoneySum;
// vector<int> curMoneySet;
// void printMoneySet(){
// 	ite(i,curMoneySet) out << a[i] << " ";
// 	out << end;
// }
// void genMoneySet(int pos){
// 	// Thời điểm bắt đầu nếu set rỗng sẽ lấy idx đầu (tức là 1) không thì sẽ lấy cái cuối 
// 	int lastIdx = (curMoneySet.empty() ? 1 : curMoneySet.back());
// 	if(curMoneySum >= S){
// 		if(curMoneySum == S) 
// 		{
// 			printMoneySet();
// 		}
// 		return;
// 	}
// 	For(i,lastIdx,n + 1){
// 		curMoneySet.pb(i);
// 		curMoneySum+=a[i];
// 		genMoneySet(pos+1);
// 		curMoneySet.PB();
// 		curMoneySum-=a[i];
// 	}
// }


// Bài toán n quân hậu

// Tìm tất cả các cách xếp n (n≤12) 
// quân Hậu lên một bàn cờ n×n
// sao cho không có hai quân Hậu 
// nào có thể ăn được nhau.
// Nếu có hai cách là hoán vị của 
// nhau (về vị trí) thì chỉ tính là một,
// ví dụ hai tập hợp (1,2),(3,4),(5,6)
// và (1,2),(5,6),(3,4) chỉ lấy 1
// . Hai quân Hậu được gọi là có thể ăn
// được nhau nếu chúng nằm cùng hàng, cột
// hoặc đường chéo của bàn cờ.

// Solution
/*
Hai quân hậu chỉ ăn nhau khi chúng cùng 1 hàng hay 1 cột
hoặc cùng nằm trên đường chéo
Tức là
- A và B nằm cùng hàng : xA = xB
- A và B nằm cùng cột : yA = yB
- A và B nằm trên cùng đường chéo
	+, xA + yA = xB + yB (đường chéo phụ or hướng tây bắc - đông nam)
	+, xA - yA = xB - yB (đường chéo  - hướng đông bắc - tây nam)
*/

int n;

/**
 * isInCol[k] : nhận giá trị true nếu đã có một quân hậu nằm ở cột k
 * isInDiag1[k] : nhận giá trị true nếu đã có một quân hậu nằm ở đường chéo phụ
 * isInDiag2[k] : nhận true nếu đã có 1 quân hậu nằm ở đường chéo chính
 * **/

bool isInCol[13],isInDiag1[26],isInDiag2[26];
vector<int> currQueenSetX,currQueenSetY;
void printQueenSet(){
	For(i,0,n){
		out << "(" << currQueenSetX[i] << ", " << currQueenSetY[i] << ")";
		if(i < n-1) out << ", ";
	}
	out << end;
}

void genQueenSet(int curRow){
	For(curCol,1,n + 1){
		int curDiag1 = curRow + curCol;
		int curDiag2 = curRow - curCol + 13;

		if(isInCol[curCol]) continue;
		if(isInDiag1[curDiag1]) continue;
		if(isInDiag2[curDiag2]) continue;

		currQueenSetX.pb(curRow);
		currQueenSetY.pb(curCol);
		isInCol[curCol] = true;
		isInDiag1[curDiag1] = true;
		isInDiag2[curDiag2] = true;

		if(currQueenSetX.size() == n) printQueenSet();
		else genQueenSet(curRow + 1);

		currQueenSetX.PB();
		currQueenSetY.PB();
		isInCol[curCol] = false;
		isInDiag1[curDiag1] = false;
		isInDiag2[curDiag2] = false;
	}
}

int main()
{
	iOS;
	in >> n;
	memset(isInCol,0,sizeof(isInCol));
	memset(isInDiag1,0,sizeof(isInDiag1));
	memset(isInDiag2,0,sizeof(isInDiag2));
	genQueenSet(1);
	return 0;
}