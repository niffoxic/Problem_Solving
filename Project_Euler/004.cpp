using ull = unsigned long long;

ull pal(ull n){
    ull res = n * 1000;
    return res + (n / 100) + (((n / 10) % 10) * 10) + ((n % 10) * 100);
}

int main()
{
      ull n;
      cin >> n;
      bool fnd = false;
      for(auto upr = n / 1000; upr >= 100 && !fnd; upr--){
          auto palc = pal(upr);
          if (palc >= n) continue;
          for(ull i = 100; i * i <= palc; i++){
              auto lor = palc / i;
              if (lor < 100 || lor > 999) continue;
              cout << palc << "\n";
              fnd = true;
              break;
          }
      }

    return 0;
}
