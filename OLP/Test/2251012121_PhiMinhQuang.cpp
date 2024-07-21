// #include<bits/stdc++.h>
// using namespace std;

// #define out std::cout
// #define in std::cin
// #define el std::endl
// #define ll long long
// #define pb push_back
// #define PB pop_back
// #define For(i,a,b) for(int (i) = (a);(i) < (b);(i)++)
// #define rof(i,a,b) for(int (i) = (a);(i) > (b);(i)--)
// #define ite(i,c) for(auto &(i) : c)
// #define iOS ios_base::sync_with_stdio(false)
// #define MOD 1000000007
// #define vt vector
// int M,N;
// int x,y,z,t;
// vt<vt<char>> arr;
// int total = 0;
// int best = INT_MAX;
// vt<vt<int>> check;
// void initData(){
// 	ifstream fi("pacman.inp");
// 	fi >> M >> N;
// 	fi >> x >> y >> z >> t;
// 	arr.resize(M,vt<char>(N));
// 	check.resize(M,vt<int>(N,0));
// 	ite(i,arr){
// 		ite(j,i){
// 			fi >> j;
// 		}
// 	}
// 	fi.close();
// }

// void outData(){
// 	ofstream fout("pacman.out");
// 	fout << best << el;
// 	fout.close();
// }

// vt<int> dx = {1,0,-1,0};
// vt<int> dy = {0,1,0,-1};

// void update(){
// 	if(best > total)
// 	{
// 		best = total;
// 	}
// }

// void solve(vt<vt<char>> arr,int &curX,int &curY){
// 	out << "At (" << curX << "," << curY << ") total is : " << total << el;  
// 	if(total > best || arr[curX][curY] == '*') return;
// 	if(curX == z && curY == t){
// 		out << total - 1 << el;
// 		update();
// 		return;
// 	}
// 	for(int i = 0;i < 4;i++)
// 	{
// 		int xi = curX + dx[i];
// 		int yi = curY + dy[i];
// 		if(xi >= 0 && xi < M && yi >= 0 && yi < N && arr[xi][yi] == '0' && check[xi][yi] == 0){
// 			total++;
// 			check[xi][yi] = 1;
// 			solve(arr,xi,yi);
// 			total--;
// 			check[xi][yi] = 0;
// 		}
// 	}
// }


// int main(){
// 	initData();
// 	check[x][y] = 1;
// 	solve(arr,x,y);
// 	out << best << el;
// 	return 0;
// }


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int startX, startY, endX, endY;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int minSteps = INT_MAX;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Up, Down, Left, Right

void readInput(const string& filename) {
    ifstream inputFile(filename);
    inputFile >> M >> N;
    inputFile >> startX >> startY >> endX >> endY;
    
    grid.resize(M, vector<char>(N));
    visited.resize(M, vector<bool>(N, false));
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> grid[i][j];
        }
    }
    
    inputFile.close();
}

void writeOutput(const string& filename, int steps) {
    ofstream outputFile(filename);
    outputFile << steps << endl;
    outputFile.close();
}

void backtrack(int x, int y, int steps) {
    if (x == endX && y == endY) {
        minSteps = min(minSteps, steps);
        return;
    }

    for (const auto& dir : directions) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] != '*' && !visited[nx][ny]) {
            visited[nx][ny] = true;
            backtrack(nx, ny, steps + 1);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    readInput("pacman.inp");
    
    visited[startX][startY] = true;
    backtrack(startX, startY, 0);
    
    if (minSteps == INT_MAX) {
        minSteps = -1;
    }
    
    writeOutput("pacman.out", minSteps - 1);
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define out std::cout
// #define in std::cin
// #define el std::endl
// #define ll long long
// #define pb push_back
// #define For(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
// #define rof(i,a,b) for(int (i) = (a); (i) > (b); (i)--)
// #define ite(i,c) for(auto &(i) : c)
// #define iOS ios_base::sync_with_stdio(false)
// #define MOD 1000000007
// #define vt vector
// int M, N;
// int x, y, z, t;
// vt<vt<char>> arr;
// int total = 0;
// int best = INT_MAX;
// vt<vt<int>> check;

// void initData(){
//     ifstream fi("pacman.inp");
//     fi >> M >> N;
//     fi >> x >> y >> z >> t;
//     arr.resize(M, vt<char>(N));
//     check.resize(M, vt<int>(N, 0));
//     for(int i = 0; i < M; i++) {
//         for(int j = 0; j < N; j++) {
//             fi >> arr[i][j];
//         }
//     }
//     fi.close();
// }

// void outData(){
//     ofstream fout("pacman.out");
//     fout << best << el;
//     fout.close();
// }

// vt<int> dx = {1, -1, 0, 0};
// vt<int> dy = {0, 0, 1, -1};

// void update(){
//     if(total < best){
//         best = total;
//     }
// }

// void solve(int curX, int curY)
// {
//     out << "At (" << curX << "," << curY << ") total is : " << total << el;
//     if(total > best || arr[curX][curY] == '*') return;
//     if(curX == z && curY == t){
//         out << "Reached target at (" << curX << "," << curY << ") with total: " << total << el;
//         update();
//         return;
//     }
//     for(int i = 0; i < 4; i++){
//         int xi = curX + dx[i];
//         int yi = curY + dy[i];
//         if(xi >= 0 && xi < M && yi >= 0 && yi < N && arr[xi][yi] == '0' && check[xi][yi] == 0){
//             total++;
//             check[xi][yi] = 1;
//             solve(xi, yi);
//             total--;
//             check[xi][yi] = 0;
//         }
//     }
// }

// int main(){
//     initData();
//     out << "Grid size: " << M << "x" << N << el;
//     out << "Start position: (" << x << "," << y << ")" << el;
//     out << "Target position: (" << z << "," << t << ")" << el;
//     out << "Initial grid state:" << el;
//     for(int i = 0; i < M; i++) {
//         for(int j = 0; j < N; j++) {
//             out << arr[i][j] << " ";
//         }
//         out << el;
//     }
//     check[x][y] = 1;
//     solve(x, y);
//     out << "Shortest path length: " << best << el;
//     outData();
//     return 0;
// }

