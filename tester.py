import os
# compile files
gen ="gen"
stupid="stupid"
smart="smart"
checker="checker"
os.system(f"g++ -std=c++20 ./{gen}.cpp -o ./{gen}.exe")
os.system(f"g++ -std=c++20 ./{smart}.cpp -o ./{smart}.exe")
# compare outputs of stupid and smart
def compare(iters):
    os.system(f'g++ -std=c++20 ./{stupid}.cpp -o ./{stupid}.exe')
    for i in range(1, iters + 1):
        print(f'Test {i}:', end='')
        os.system(f"{gen}.exe > test.txt")
        v1 = os.popen(f'{stupid}.exe < test.txt', 'r').read()
        v2 = os.popen(f'{smart}.exe < test.txt', 'r').read()
        if v1 != v2:
            print("WA:")
            print(open("test.txt").read())
            print(f'Output of stupid.exe:')
            print(v1)
            print(f'Output of smart:')
            print(v2)
            break
        else:
            print("OK")
# use special checker to smart outputs
def check(iters):
    os.system(f"g++ -std=c++20 ./{checker}.cpp -o ./{checker}.exe")
    for i in range(1, iters + 1):
        print(f'Test {i}:', end='')
        os.system(f"{gen}.exe > test.txt")
        os.system(f"{smart}.exe < test.txt > ans.txt")
        test = open("test.txt", 'r')
        test_str = test.read()
        ans = open("ans.txt", 'r')
        ans_str = ans.read()
        info_to_checker = open("info.txt", 'w')
        info_to_checker.write(test_str)
        info_to_checker.write(ans_str)
        test.close()
        ans.close()
        info_to_checker.close()
        check = os.popen(f"{checker}.exe < info.txt", 'r').read()
        print(check)
        if (check == "WA\n"):
            print("Test value: ")
            print(test_str)
            print("Smart answer value: ")
            print(ans_str)
# Start the code
iters = int(input())
compare(iters)
# check(iters)
