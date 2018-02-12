class Solution {
public:
struct pointxy
{
	int x;
	int y;
	pointxy(int a, int b) :x(a), y(b){}
};

int numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0)
	{
		return 0;
	}
	vector<vector<bool>> visited, grid2;
	for (int i = 0; i < grid.size() + 2; i++){
		vector<bool> row;
		if (i == 0 ||( i == (grid.size() + 1))){
			for (int j = 0; j < grid[0].size() + 2; j++){
				row.push_back(0);
			}
		}
		else{
			row.push_back(0);
			for (int j = 0; j < grid[0].size(); j++){
				row.push_back(grid[i - 1][j] - '0');
			}

			row.push_back(0);
		}
		grid2.push_back(row);
	}

	for (int i = 0; i < grid2.size(); i++)
	{
		vector<bool> row;
		for (int j = 0; j < grid2[0].size(); j++)
		{
			row.push_back(0);
		}
		visited.push_back(row);
	}
	int rst = 0;
	while (1)
	{
		stack<pointxy> ps;
		bool flag = false;
		for (int i = 0; i < grid2.size();i++)
		{
			
			for (int j = 0; j < grid2[0].size(); j++)
			{
				if (grid2[i][j] == 1 && visited[i][j] == 0){
					ps.push(pointxy(i, j));
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
			//return rst;
		}
		if (!flag)
		{
			return rst;
		}
		int incx[] = { 0, 0, -1, 1 };
		int incy[] = { -1, 1, 0, 0 };
		rst++;
		while (!ps.empty()){
			pointxy now = ps.top();
			ps.pop();
			visited[now.x][now.y] = 1;
			for (int m = 0; m < 4; m++){
				if (grid2[now.x + incx[m]][now.y + incy[m]] == 1 && visited[now.x + incx[m]][now.y + incy[m]] == 0)
				{
					ps.push(pointxy(now.x + incx[m], now.y + incy[m]));
				}
			}

		}
	}



}
};
