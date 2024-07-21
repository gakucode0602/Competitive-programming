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

// bool compare(int a,int b){ // giam dan
// 	return a < b;
// }

// stack<int> change(int n,int radix = 2){
// 	stack<int> s;
// 	while(n != 0){
// 		s.push(n % radix);
// 		n /= radix;
// 	}
// 	return s;
// }

// void cal(stack<int> &a,char op){
// 	int y = a.top();
// 	a.pop();
// 	int x = a.top();
// 	a.pop();

// 	switch(op){
// 		case '+':{
// 			a.push(x + y);
// 			break;
// 		}
// 		case '-':{
// 			a.push(x - y);
// 			break;
// 		}
// 		case '*':{
// 			a.push(x * y);
// 			break;	
// 		}
// 		case '/':{
// 			a.push(x / y);
// 			break;
// 		}
// 	}
// }

// int priority(char c){
// 	if(c == '+' || c == '-'){
// 		return 1;
// 	}
// 	return 2;
// }

// int checkingParentheses(string s,int i){
// 	stack<char> st;
// 	for(int j = i;j < s.length();j++){
// 		if(s[j] == '('){
// 			st.push(s[j]);
// 		}
// 		else{
// 			if(st.size() == 1){
// 				return j;
// 			}
// 			else {
// 				st.pop();
// 			}
// 		}
// 	}
// 	return -1;
// }


// vector<bool> b(3,false);
// // Xuất ra các hoán vị của một tập hợp
// void solve1(vector<int> &v,vector<vector<int>> &res,vector<int> &p,int n){
// 	if(p.size() == n){
// 		res.pb(p);
// 		return;
// 	}
// 	else{
// 		For(i,0,n){
// 			if(b[i]) continue;
// 			b[i] = true;
// 			p.pb(v[i]);
// 			solve1(v,res,p,n);
// 			b[i] = false;
// 			p.PB();
// 		}
// 	}
// }

// void solve2(vector<int> &v,vector<vector<int>> &res,int i){
// 	if(i == v.size() - 1){
// 		res.pb(v);
// 		return;
// 	}
// 	For(j,i,v.size()){
// 		swap(v[i],v[j]);
// 		solve2(v,res,i+1);
// 		swap(v[i],v[j]);
// 	}
// }

// vector<vector<int>> getPermutation(vector<int> &v){
// 	vector<vector<int>> res;
// 	solve2(v,res,0);
// 	return res;
// }

// // Lecture
// int n = 3;
// vector<int> state(n,0);
// vector<bool> d(n + 1,false);

// void output(){
// 	ite(i,state){
// 		out << i << " ";
// 	}
// 	out << end;
// }

// void process(int idx){
// 	For(i,1,n+1){
// 		if(!d[i]){
// 			state[idx] = i;
// 			d[i] = true;
// 			if(idx == n - 1){
// 				output();
// 			}
// 			else{
// 				process(idx + 1);
// 			}
// 			d[i] = false;
// 		}
// 	}
// }


// // Xac dinh chinh hop chap k cua n phan tu (chinh hop lap)
// int n1 = 2;
// int k = 3;

// vector<int> state1(k);

// void output1(){
// 	ite(i,state1){
// 		out << i << " ";
// 	}
// 	out << end;
// }

// void arrangement(int idx){
// 	For(i,1,n1+1){
// 		state1[idx] = i;
// 		if(idx == k-1){
// 			output1();
// 		}
// 		else arrangement(idx + 1);
// 	}
// }

// // to hop chap k cua n phan tu
// int n2 = 5;
// int k1 = 3;
// vector<int> state2(k1);

// void output2(){
// 	ite(i,state2){
// 		out << i << " ";
// 	}
// 	out << end;
// }

// void combination(int idx){
// 	int start = (idx > 0) ? state2[idx - 1] : 0;
// 	For(i,start + 1,n2 + 1){
// 		state2[idx] = i;
// 		if(idx == k1 - 1){
// 			output2();
// 		}
// 		else combination(idx + 1);
// 	}
// }

// // Bai toan 8 quan hau
#define SIZE 8
vector<int> state3(SIZE,0);

bool canPutQueen(int i,int j){
	For(k,0,i){
		if(state3[k] == j || abs(i - k) == abs(j - state3[k])){
			return false;
		}
	}
	return true;
}

void output3(){
	For(i,0,SIZE){
		For(j,0,SIZE){
			if(j == state3[i]) out << "Q ";
			else out << "0 ";
		}
		out << end;
	}
	out << "More : ";
	if(getchar() == 'y'){
		out << "=======================================" << end;
	}
	else exit(1);
	cin.ignore();
}

void process1(int idx){
	For(i,0,SIZE){
		if(canPutQueen(idx,i) == true) // Dieu kien de dat quan hau
		{
			state3[idx] = i;
			if(idx == SIZE - 1)
			{
				output3();
			}
			else process1(idx + 1);
		}
	}
}

// // Quan ma di tuan
// vector<vector<int>> state4(SIZE,vector<int>(SIZE,0));
// int steps[SIZE][2] {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

// void output4(){
// 	For(i,0,SIZE){
// 		For(j,0,SIZE){
// 			out << state4[i][j] << " ";
// 		}
// 		out << end;
// 	}
// 	if(getchar() == 'y'){
// 		cin.ignore();
// 		out << "==============\n";
// 	}
// 	else exit(1);
// }

// void process2(int idx,int d,int c){
// 	For(i,0,SIZE){
// 		int row = d + steps[i][0];
// 		int col = c + steps[i][1];

// 		if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && state4[row][col] == 0){
// 			state4[row][col] = idx;

// 			if(idx == SIZE * SIZE){
// 				output4();
// 			}
// 			else{
// 				process2(idx + 1,row,col);
// 			}
// 			state4[row][col] = 0;
// 		}

// 	}
// }

// Ky thuat nhanh can
// Giong backtracking , nhung no se danh gia giai phap nao la tot nhat
/*
void branchBound(int idx){
	if(<Cac loi giai khong tot hon best>) return;
	for xi in Si{
		if(<xi thoa dk dat vao state>){
			<ghi nhan vao state>
			if(<state thoa dieu kien>){
				update(); // cap nhat ket qua toi uu
			}
			else branchBound(idx + 1);
		}
		<Loai xi khoi state tim ket qua khac>
	}
}
*/

// Bai toan ATM
/*ATM có n (n <= 20) tờ tiền có giá trị t1,t2,...,tn .Lập trình đưa ra
kết quả trả ra số tiền là ít nhất với số tờ tiền sử dụng là ít nhất
Dữ liệu đầu vào là tập tin atm.inp có dạng
- Dòng đầu là 2 số n và s
- Dòng 2 là n số t1,t2,tn
Kết quả xuất ra tập tin atm.out cách trả số tiền , ngược lại ghi -1
*/

// vector<int> a = {200,10,20,20,100,50,50,50,50,100};
// int n3 = 10;
// int s = 500;
// vector<int> state5;
// int num = 0;
// int total = 0;

// vector<int> best;
// int numBest = INT_MAX;

// vector<bool> d1(n3,false);
// vector<int> tMax(n3,0);

// void update(){
// 	if(num < numBest){
// 		numBest = num;
// 		best = state5;
// 	}
// }

// int counter = 0;
// void process3(int idx){
// 	// s - total : so tien con lai
// 	// tmaxIdx : menh gia lon nhat
// 	if(num + (s - total) / tMax[idx] >= numBest) // mau chot nam o day
// 	{
// 		return;
// 	}
// 	counter++;
// 	for(int i = 0;i < n3;i++){
// 		if(d1[i] == false and total + a[i] <= s){
// 			state5.pb(a[i]);
// 			d1[i] = true;
// 			num++;
// 			total += a[i];

// 			if(total == s){
// 				update();
// 			}
// 			else process3(idx + 1);

// 			state5.pop_back();
// 			d1[i] = false;
// 			num--;
// 			total-=a[i];
// 		}
// 	}
// }

// void output5(){
// 	cout << "So to it nhat : " << numBest << end;
// 	ite(x,best){
// 		out << x << "\t";
// 	}
// 	out << end;
// }

// Bai toan nguoi du lich
/*
int n;
vector<vector<int>> a;
vector<int> state;
int total = 0;// tong chi phi
vector<int> best;
int totalBest = INT_MAX;

vector<bool> d;

int start = 0;

void initData(){
	ifstream f;
	f.open("travel.inp");
	f >> n;
	a.resize(n,vector<int>(n));
	For(i,0,n){
		For(j,0,n){
			f >> a[i][j];
		}
	}
	f.close();
	state.resize(n);
	d.resize(n,false);
}

void update()
{
	int x = a[start][state[n - 1]];
	if(x > 0 && total + x < totalBest){
		totalBest = total + x;
		best = state;
	}	
}

int counter = 0;
void process(int idx){
	if(total > totalBest){
		return;
	}
	counter++;
	For(i,0,n){
		if(d[i] == false && a[state[idx - 1]][i] > 0){
			//Neu nhu thanh pho do chua tham va co duong di tu thanh pho hien tai den thanh pho truoc do
			state[idx] = i;
			d[i] = true;
			total += a[state[idx-1]][i];

			if(idx == n - 1){
				update();
			}	
			else process(idx + 1);

			d[i] = false;
			total -= a[state[idx-1]][i];
		}
	}
}

void output(){
	ite(x,best){
		out << x << "\t";
	}
	out << start << end;
	out << endl;
	out << totalBest << end;
	out << counter << end;
}
*/

vector<vector<int>> a;
int n;
vector<int> state;
int total = 0;
vector<bool> d;
int start = 0;

vector<int> best;
int totalBest = INT_MAX;

void initData(){
	ifstream f;
	f.open("travel.inp");
	f >> n;
	a.resize(n,vector<int>(n));
	state.resize(n);
	d.resize(n,false);
	For(i,0,n){
		For(j,0,n){
			f >> a[i][j];
		}
	}
	f.close();
}

void update(){
	int x = a[state[n - 1]][start]; // ???
	if(x > 0 && total + x < totalBest){
		totalBest = total + x;
		best = state;
	}
}

// idx : gia tri xet hang
void process(int idx){
	if(total > totalBest){
		return;
	}
	For(i,0,n){
		if(d[i] == false and a[state[idx - 1]][i] > 0){
			state[idx] = i;
			d[i] = true;
			total +=  a[state[idx - 1]][i];
			if(idx == n - 1){
				update();
			}
			else process(idx + 1);
			d[i] = false;
			total -=  a[state[idx - 1]][i];
		}
	}
}

void output(){
	ite(i,best){
		out << i << "  ";
	}
	out << start;
	out << endl << totalBest << endl;
}

int main(){
	//iOS;
	initData();
	// ===== Algorithm =====

	/*
	vector<int> v = {4,2,4,2,6,7,3,6};
	ite(i,v) cout << i << " ";
	cout << endl;
	sort(v.begin(),v.end(),compare);
	ite(i,v) cout << i << " ";
	cout << endl;

	//sort(v.begin(),v.end(),[](auto a,auto b) { return a > b;});
	//ite(i,v) cout << i << " ";
	//cout << endl;

	auto r1 = count(v.begin(),v.end(),4);
	cout << r1 << endl;

	// dem so chan
	auto r2 = count_if(v.begin(),v.end(),[](auto x) { return (x&1) == 0;});
	cout << r2 << endl;

	// tim so
	auto r3 = find(v.begin(),v.end(),1);
	if(r3 != v.end()){
		cout << "Found\n";
		return 0;
	}
	cout << "Not found\n";


	// dung thuat toan nhi phan
	auto r4 = binary_search(v.begin(),v.end(),4,compare);
	if(r4){
		cout << "Found\n";
	}
	else cout << "Not found\n";
	*/


	// ===== Stack =====

	// vector<char> label = {'A','B','C','D','E','F'};

	// stack<int> a = change(125);
	// while(!a.empty()){
	// 	int x = a.top();
	// 	a.pop();

	// 	if(x >= 10){
	// 		cout << label[x - 10];
	// 	}
	// 	else{
	// 		cout << x;
	// 	}
	// }
	// cout << endl;

	// === Tinh gia tri bieu thuc dung stack
	// string s = "2+5*2";
	// stack<int> a;
	// stack<int> b;
	// for(int i = 0;i < s.length();i++){
	// 	if(s[i] >= '0' && s[i] <= '9'){
	// 		int num = 0;
	// 		while(s[i] >= '0' && s[i] <= '9'){
	// 			num = num * 10 + (s[i] - '0');
	// 			i++;
	// 		}
	// 		i--;
	// 		a.push(num); // "7" -> 7
	// 	}
	// 	else{
	// 		while(!b.empty() && priority(b.top()) >= priority(s[i])){
	// 			char op = b.top();
	// 			b.pop();
	// 			cal(a,op);
	// 		}
	// 		b.push(s[i]);
	// 	}
	// }

	// while(!b.empty()){
	// 	char op = b.top();
	// 	b.pop();
	// 	cal(a,op);
	// }
	// int res = a.top();
	// a.pop();
	// cout << res << endl;

	// Kiem tra tinh hop le cua dau ngoac

	//cout << checkingParentheses("(((((((((()()()(()))))))))))",16) << endl;


	// ============= Backtracking ==============
	// Thu - sai - quay lui


	// vector<int> v = {1,4,3};
	// ite(x,getPermutation(v)){
	// 	ite(y,x){
	// 		out << y << " "; 
	// 	}
	// 	out << end;
	// }

	// lecture
	//process(0);

	// chinh hop
	//arrangement(0);

	// to hop
	//combination(0);

	// ================== 8 quan hau ========================

	//process1(0);

	// Bai toan ATM
	// // state4[0][0] = 1;
	// // process2(2,0,0);
	// tMax[n3 - 1] = a[n3 - 1];
	// //  200,10,20,20,100,50,50,50,50,100
	// //  200 100 100 100 100 100 100 100 100
	// rof(i,n3-2,-1){
	// 	tMax[i] = tMax[i + 1];
	// 	if(a[i] > tMax[i]){
	// 		tMax[i] = a[i];
	// 	}
	// }
	// for(auto x : tMax){
	// 	cout << x << " ";
	// }
	// out << endl;
	// process3(0);
	// output5();
	// out << counter << end;

	// Bai toan nguoi du lich
	state[0] = start;
	d[start] = true;
	process(1);
	output();
	return 0;
}