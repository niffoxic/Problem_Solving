using ll = long long;

int main(){
  ll n;
  cin >> n;

  while (n > 1)
  {
      cout << n << " ";
      if (n & 1)n = 3 * n + 1;
      else n /= 2;
  }
  
  cout << 1;
  return 0;
}
