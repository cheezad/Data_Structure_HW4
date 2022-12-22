#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
ifstream my_file;
ofstream output;

struct node{
    int weight;
    char name;
};
bool compareByLength(const node &a, const node &b) // used for sorting the vector
{
    return a.weight < b.weight;
}


int main(){
    // input of file
    string filename;
    cout << "Input file name: ";
    cin >> filename;
	my_file.open(filename.c_str());
    output.open("output_d.txt");
	if (!my_file.is_open() || !output.is_open()) {
        return 1;
	}

    int matrix[7][7]; // adjacency matrix
    int dis[7];	// distance of the path
    int parent[7]; // record the parent of the vertex
    bool visit[7];	// check if visited
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            matrix[i][j] = 2147483647;
        }
    }
    int edges;
    my_file >> edges;
    for(int i = 0 ; i < edges ; i++){
        char a, b;
        int weight;
        my_file >> a >> b >> weight;
        matrix[a - 97][b - 97] = weight;
    }
    for(int i = 0 ; i < 7 ; i++) visit[i] = false;
    for(int i = 0 ; i < 7 ; i++) dis[i] = 2147483647;
    char start;
    my_file >> start;
    dis[start - 97] = 0;
    parent[start - 97] = start - 97;

    for(int i = 0 ; i < 7 ; i++){
        int a = -1, b = -1, min = 2147483647;
        for(int j = 0 ; j < 7 ; j++)
            if(!visit[j] && dis[j] < min){
                a = j;
                min = dis[j];
            }
        if(a == -1) break;
        if(min == 2147483647) break;
        visit[a] = true;
        for(b = 0; b < 7 ; b++)
            if(!visit[b] && dis[a] + matrix[a][b] < dis[b] && matrix[a][b] != 2147483647){
                dis[b] = dis[a] + matrix[a][b];
                parent[b] = a;
            }
    }

    vector <struct node> ans;
    for(int i = 0 ; i < 7 ; i++){
        if(dis[i] == 2147483647) continue;
        struct node temp;
        temp.name = char(97 + i);
        temp.weight = dis[i];
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end(), compareByLength);
    int length = ans.size();
    for (int i = 0 ; i < length ; i++){
        output << ans[i].name << " " << ans[i].weight << endl;
        cout << ans[i].name << " " << ans[i].weight << endl;
    }
    return 0;
}