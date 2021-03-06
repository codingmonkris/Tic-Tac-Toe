#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> pos;
map<int, pair<int, int>> m;
int cnt = 0;

bool check(vector<vector<int>> &a, int temp)
{

  //diagonals
  if (a[0][0] == temp)
    if (a[0][0] == a[2][2] && a[0][0] == a[1][1])
      return 1;

  if (a[0][2] == temp)
    if (a[0][2] == a[2][0] && a[0][2] == a[1][1])
      return 1;

  //horizontal
  if (a[0][0] == temp)
    if (a[0][0] == a[0][2] && a[0][0] == a[0][1])
      return 1;

  if (a[1][0] == temp)
    if (a[1][0] == a[1][2] && a[1][0] == a[1][1])
      return 1;

  if (a[2][0] == temp)
    if (a[2][0] == a[2][2] && a[2][0] == a[2][1])
      return 1;

  //vertical
  if (a[0][0] == temp)
    if (a[0][0] == a[2][0] && a[0][0] == a[1][0])
      return 1;

  if (a[0][1] == temp)
    if (a[0][1] == a[2][1] && a[0][1] == a[1][1])
      return 1;

  if (a[0][2] == temp)
    if (a[0][2] == a[2][2] && a[0][2] == a[1][2])
      return 1;

  return 0;
}

int fun(vector<vector<int>> v, int depth = 1, int turn = 1)
{

  int mini = INT_MAX;
  int maxi = INT_MIN;
  pair<int, int> pos_min = {0, 0}, pos_max = {0, 0};

  if (check(v, turn ^ 1))
  {
    return ((turn == 0) ? (10 - depth) : (-10 + depth));
  }

  bool flag = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {

      if (v[i][j] == 2)
      {

        flag = 1;

        vector<vector<int>> a = v;

        a[i][j] = turn;

        int temp = fun(a, depth + 1, turn ^ 1);

        if (temp < mini)
        {
          mini = temp;
          pos_min.first = i, pos_min.second = j;
        }

        if (temp > maxi)
        {
          maxi = temp;
          pos_max.first = i, pos_max.second = j;
        }
      }
    }
  }

  if (!flag)
    return 0;

  if (turn)
  {
    pos = pos_max;
    return maxi;
  }
  else
  {
    pos = pos_min;
    return mini;
  }
}

int32_t main()
{

  srand(time(NULL));
  m[1] = {0, 0}, m[2] = {0, 1}, m[3] = {0, 2}, m[4] = {1, 0}, m[5] = {1, 1}, m[6] = {1, 2}, m[7] = {2, 0}, m[8] = {2, 1}, m[9] = {2, 2};

  vector<vector<int>> v = { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} };

  for (int i = 0; i <= 9 / 2; i++)
  {

    int move;
    cin >> move;

    cout << m[move].first << ' ' << m[move].second << endl << endl;

    v[m[move].first][m[move].second] = 0;

    for (int i = 0; i < 3; i++)
    {

      for (int j = 0; j < 3; j++)
          if(v[i][j]==2)
            cout << "_" << "  ";
          else if(v[i][j]==1)
            cout << "X" << "  ";
          else if(v[i][j]==0)
            cout << "O" << "  ";

      cout << '\n';
    
    }

    cout << endl << ' ' << endl;

    if (i == 9 / 2)
      break;

    int x = fun(v);

    cout << pos.first << ' ' << pos.second << endl << endl;
    v[pos.first][pos.second] = 1;

    for (int i = 0; i < 3; i++)
    {

      for (int j = 0; j < 3; j++){
          
          if(v[i][j]==2)
            cout << "_" << "  ";
          else if(v[i][j]==1)
            cout << "X" << "  ";
          else if(v[i][j]==0)
            cout << "O" << "  ";

      }  

      cout << '\n';

    }

    cout << endl << endl;
  
  }

  return 0;
}
