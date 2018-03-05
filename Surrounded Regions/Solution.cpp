class Solution {
public:
    struct pointxy
{
	int x;
	int y;
	pointxy(int a, int b) :x(a), y(b){}
};
void solve(vector<vector<char>>& board){
	int s = board.size();
    if(s == 0)
        return;
    int s1 = board[0].size();
    if(s1 == 0)
        return;
	vector<vector<bool>> visited;

	int decx[] = { 0, -1, 0, 1 };
	int decy[] = { -1, 0, 1, 0 };
	for (int i = 0; i < s;i++)
	{
		vector<bool> row;
		for (int j = 0; j < s1; j++)
		{
			if (board[i][j] == 'X' || i == 0 || i == s-1 || j == 0 || j == s1-1)
			{
				row.push_back(true);
			}
			else
				row.push_back(false);
		}
		visited.push_back(row);
	}
	stack<pointxy> regionstart;
	int flag1 = false;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s1; j++)
		{
			if (board[i][j] == 'O' && i!= 0 && i!= s-1 && j != 0 && j!= s1-1)
			{
				regionstart.push(pointxy(i, j));
				flag1 = true;
				break;
			}
		}
		if (flag1)
		{
			break;
		}
	}
	while (!regionstart.empty())
	{
		pointxy start = regionstart.top();
		regionstart.pop();
		//cout << start.x << " " << start.y << endl;

		stack<pointxy> region;
		vector<pointxy> region2;
		region.push(start);
		region2.push_back(start);
		
		while (!region.empty())
		{
			pointxy start = region.top();
			region.pop();
			//cout << start.x << " " << start.y << endl;
			visited[start.x][start.y] = 1;
			for (int m = 0; m < 4;m++)
			{
				if (board[start.x + decx[m]][start.y + decy[m]] == 'O' && visited[start.x + decx[m]][start.y + decy[m]] == 0){
					pointxy tmp(start.x + decx[m], start.y + decy[m]);
					region.push(tmp);
					region2.push_back(tmp);
				}
			}


		}
		bool flag = false;
		for (auto it = region2.begin(); it != region2.end();it++)
		{
			for (int i = 0; i < 4;i++)
			{
				int tmpi = (*it).x + decx[i];
				int tmpj = (*it).y + decy[i];
				if (board[tmpi][tmpj] == 'O' && (tmpi == 0 || tmpi == s-1 || tmpj ==0|| tmpj == s1-1))
				{
					//边缘O
					flag = true; 
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (!flag){
			for (auto it = region2.begin(); it != region2.end(); it++)
			{
				board[(*it).x][(*it).y] = 'X';
			}
		}
		flag = false;
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s1; j++)
			{
				if (board[i][j] == 'O' && visited[i][j] == false && i != 0 && i != s - 1 && j != 0 && j != s1 - 1)
				{
					regionstart.push(pointxy(i, j));
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	return;
	

}

};

