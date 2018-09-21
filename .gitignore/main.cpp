#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
      //строка ввода
      string stk;

      //Вектор числа ввода
      vector<int> Vec;

      //Вектор числа значения факториала
      vector<int> N;
      N.reserve(300);
      N.push_back(1);

      cin>>stk;

      for(int x = stk.length(); x > 0; --x)
      {
          Vec.push_back(stk[x - 1] - 48);
      }

      int n = 1;
      int number_1 = 0;
      int result = 0;
      int ost = 0;
      bool push;
      while(N != Vec && N.size() <= Vec.size())
      {
          n++;
          push = true;
            for(int i = 0; i < N.size(); i++)
            {
                if(push)
                {
                    result = N[i] * n;

                    //считываем единицы из рез-та и остатка
                    number_1 = result % 10 + ost % 10;

                    //обновление остатка
                    ost = result / 10 + ost / 10;

                    //Проверка если единицы больше 9 то инкрементируем десятки_остатка и вычитаем из единиц 10
                    // Не может быть больше 18, т.к максимальное сложение цифр 9 + 9 = 18 т.е number_1 <= 18
                    if(number_1 > 9)
                        {
                            number_1 -= 10;
                            ost++;
                        }
                    N[i] = number_1;
                }
                // Проверка на последнюю цифру числа(нужно ли увеличить вектор числа)
                if(N.size() - 1 == i && ost != 0)
                    {
                        // Если пуш = фолс то не задействуем пропушенный элемент в цикле выше.
                        push = false;
                        N.push_back(ost % 10);
                        ost /= 10;
                        if(ost == 0)
                            break;
                    }
            }
      }
      if(Vec == N)
      {
          cout<<"n: "<<n;
      }else
      {
          cout<<"-1";
      }

// Для проверки
//      cout<<". VECtor_N: ";
//      for(int i = N.size() - 1 ; i >= 0; --i)
//      {
//            cout<<N[i];
//      }
//      cout<<"   VECtor_Vec: ";
//      for(int i = Vec.size() - 1 ; i >= 0; --i)
//      {
//            cout<<Vec[i];
//      }


      //      stk = to_string(i);
      //      i = atoi(stk.c_str());
      //      int ii = stoi(stk);


      return 0;
}
