#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
ifstream my_file;
ofstream output;
struct node{
    char from;
    char to;
    int weight;
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
    output.open("output_p.txt");
	if (!my_file.is_open() || !output.is_open()) {
        return 1;
	}
    
    int edges;
    my_file >> edges;
    int matrix[7][7]; // adj matrix
    int dis[7]; // distance for MST each spot
    int parent[7]; // remember its parent
    bool visit[7]; // see if the edges are in the MST
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            matrix[i][j] = 2147483647;
        }
    }
    for(int i = 0 ; i < edges ; i++){
        char a, b;
        int weight;
        my_file >> a >> b >> weight;
        // cout << endl << a -97 << "  " << b -97 << endl;
        matrix[a - 97][b - 97] = weight;
        matrix[b - 97][a - 97] = weight;
    }
    for(int i = 0 ; i < 7 ; i++) visit[i] = false;
    for(int i = 0 ; i < 7 ; i++) dis[i] = 2147483647;
    char start;
    my_file >> start;
    dis[start - 97] = start - 97; 
    parent[start - 97] = start - 97;
    
    for(int i = 0 ; i < 7 ; i++){
        int a = -1, b = -1, min = 2147483647;
        for(int j = 0 ; j < 7 ; j++)
            if(!visit[j] && dis[j] < min){
                a = j;
                min = dis[j];
            }
        if(a == -1) break;
        visit[a] = true;
        for(b = 0; b < 7 ; b++)
            if(!visit[b] && matrix[a][b] < dis[b]){
                dis[b] = matrix[a][b];
                parent[b] = a;
            }
    }

    vector <struct node> ans;
    for(int i = 0 ; i < 7 ; i ++){
        struct node temp;
        if(i == parent[i]) continue;
        if(i < parent[i]){
            temp.from = char(i + 97);
            temp.to = char(parent[i] + 97);
            temp.weight = matrix[i][parent[i]];
            ans.push_back(temp);
        }
        else{
            temp.from = char(parent[i] + 97);
            temp.to = char(i + 97);
            temp.weight = matrix[i][parent[i]];
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end(), compareByLength);
    int length = ans.size();
    for (int i = 0 ; i < length ; i++){
        output << ans[i].from << " " << ans[i].to << " " << ans[i].weight << endl;
        cout  << ans[i].from << " " << ans[i].to << " " << ans[i].weight << endl;
    }
    return 0;
}
