#include <iostream>

int array[2000000] = { 0, };

class deque
{
    private:
        int size;
        int it_f, it_e;
    public:
        void front_push(int input)
        {
            array[--it_f] = input;
            size++;
        }
        void end_push(int input)
        {
            array[it_e++] = input;
            size++;
        }
        void front_pop()
        {
            if (size == 0)
                std::cout << - 1 << '\n';
            else
            {
                std::cout << array[it_f++] << '\n';
                size--;
            }
        }
        void end_pop()
        {
            if (size == 0)
                std::cout << - 1 << '\n';
            else
            {
                std::cout << array[--it_e] << '\n';
                size--;
            }
        }
        void print_size()
        {
            std::cout << size << '\n';
        }
        void empty()
        {
            if (size == 0)
                std::cout << 1 << '\n';
            else
                std::cout << 0 << '\n';
        }
        void print_f()
        {
            if (size == 0)
                std::cout << - 1 << '\n';
            else
                std::cout << array[it_f] << '\n';
        }
        void print_e()
        {
            if (size == 0)
                std::cout << - 1 << '\n';
            else
                std::cout << array[it_e - 1] << '\n';
        }

        deque()
        : size{ 0 }, it_f{ 1000000 }, it_e{ 1000000 } {}
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    deque dq;
    int n, order, input;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> order;
        switch (order)
        {
            case 1:
            {
                std::cin >> input;
                dq.front_push(input);
                break;
            }
            case 2:
            {
                std::cin >> input;
                dq.end_push(input);
                break;
            }
            case 3:
            {
                dq.front_pop();
                break;
            }
            case 4:
            {
                dq.end_pop();
                break;
            }
            case 5:
            {
                dq.print_size();
                break;
            }
            case 6:
            {
                dq.empty();
                break;
            }
            case 7:
            {
                dq.print_f();
                break;
            }
            case 8:
            {
                dq.print_e();
                break;
            }
        }
    }
    return 0;
}