#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* r, *down;
};

Node* con(int ar[][4], int x, int y,
int i, int j, vector<vector<Node*>> &visit)
{
  if (x > i - 1 || y > j - 1)
  return NULL;

  if(visit[x][y]){
  return visit[x][y];
}

Node* tmp = new Node();
visit[x][y] = tmp;
tmp->data = ar[x][y];
tmp->r = con(ar, x, y + 1, i, j, visit);
tmp->down = con(ar, x + 1, y, i, j, visit);
return tmp;
}

  void disp(Node* head)
  {
    Node* pointRight;
    Node* pointDown = head;

    while (pointDown) {
    pointRight = pointDown;

    while (pointRight) {
      cout << pointRight->data << " ";
    pointRight = pointRight->r;
}
    cout << "\n";
    pointDown = pointDown->down;
  }
}

int main()
{
  int a[][4] = {
  { 2, 3, 4, 5},
  { 5, 6, 7, 2},
  { 7, 8, 9, 3},
  { 8, 9, 0, 4}
};
  int c = 4, d = 4;
  vector<vector<Node*>> visit(c, vector<Node*>(d));
  Node* head = con(a, 0, 0, c, d, visit);
  disp(head);
  return 0;
}
