#include <iostream>
#include <queue>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    int n, m;
    int input;
    std::cin >> t;

    while (t--)
    {
        int count{0};
        std::queue<std::pair<int, bool>> q; //같은수가 여러개일수 있으니 bool로 판단
        std::priority_queue<int> pq;

        std::cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            std::cin >> input;  //input받은걸 보통큐랑 우선순위큐에 둘다 넣어줌
            if (i == m)         //m이 타겟인덱스인셈
                q.push( {input, true} );
            else
                q.push( {input, false} );
            pq.push(input);     //우선순위큐가 알아서 정렬해주고
        }

        while (!q.empty())
        {
            if (q.front().first != pq.top()) //우선순위 높은 숫자가 아니면
            {
                q.push(q.front());           //맨뒤로 보내기
                q.pop();
            }

            if (q.front().first == pq.top())  //우선순위높은 숫자가 맞고
            {
                count++;
                if (q.front().second == true) //타겟도 맞으면 출력하고 테스트케이스 끝
                {
                    std::cout << count << '\n';
                    break;
                }
                else                          //숫자만 맞고 타겟이 아니라면
                    q.pop(); pq.pop();        //얌전히 pop하고 진행
            }
        }
    }

    return 0;
}