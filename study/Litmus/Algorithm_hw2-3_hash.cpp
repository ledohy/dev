//#include <iostream>
//#include <vector>
//
//inline bool isPrime(int val)
//{
//    for (int i = 3; i < val; i += 2) //애초에 홀수만 val값으로 들어오기때문에 홀수만 점검하면 됨
//        if (val % i == 0)
//            return false;
//
//    return true;
//}
//
//int main(void)
//{
//    int n, count = 0;
//    
//    std::cin >> n;
//    int size;
//
//    for (size = 2*n + 1; isPrime(size) == false; size += 2);
//
//
//    std::vector<int> arr(size);
//    std::vector<bool> hasNum(size);
//
//    int x;
//    while (n--) {
//        std::cin >> x;
//
//        for (int i = 0; i < size; i++) {
//            int h_i = (x + i) % size;
//            if (hasNum[h_i] == true)
//                count++;
//            
//            else {
//                arr[h_i] = x;
//                hasNum[h_i] = true;
//                break;
//            }
//        }
//    }
//
//    std::cout << count << '\n';
//
//    return 0;
//}
