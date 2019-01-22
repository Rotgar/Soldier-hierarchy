#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int *T, *T1;
int leader, n;
unordered_map<int,vector<int>> map;
vector<int> list;


//````````rekurencja - opcjonalnie, standardowo wykorzystuje unordered_map
int nr(int x)
{
  if(T[x] == x)
    return 0;
  else
    return nr(T[x]) + 1;
}

void recursion()
{
  for(int i=0; i<n; ++i)
  {
    cout<<nr(i)<<" ";
  }
  cout<<endl;
}
//```````````rekurencja


void calcMap()
{
  leader = -1;
  for(int i=0; i<n; ++i)
  {
    if(i == T[i])
      leader = i;

    if(i!=leader)
    {
      if(map.find(T[i])==map.end())
      {
        map[T[i]] = vector<int>();
        map[T[i]].push_back(i);
      }
      else
        map[T[i]].push_back(i);
    }
  }

  int x = 0, next;
  T[leader] = 0;
  list.push_back(leader);

  while(x != list.size())
  {
    next = list[x]; x++;
    for(int i : map[next] )
    {
      T[i] = T[next] + 1;
      if(map.find(i)!=map.end())
      {
        list.push_back(i);
      }
    }
  }
  map.clear(); // czyszczenie dla przyszłych
  list.clear();

  for(int i=0; i<n; ++i)
  {
    cout<<T[i]<<" ";
  }
  cout<<endl;
}


int main(int argc, char ** argv)
{
  T = new int[100000];  //jednorazowa alokacja dla maksymalnej ilości danych

  int m;
  if(argc == 2)
    m = stoi(argv[1]); // liczba inna niż 0 - wykona sie rekurencyjnie
  else
    m = 0;

  cin>>n;
  do{

    for(int i=0; i<n; ++i) { cin>>T[i]; } // ładowanie danych do tablicy

    if(m == 0)  // standardowo przy użyciu unordered_map
    {
      calcMap();
    }
    else  // rekurencja
    {
      recursion();
    }
    cin>>n;

  }while(n!=0);

  delete[] T;

  return 0;
}
