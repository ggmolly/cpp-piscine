import subprocess
import random
from typing import List

def random_seq(n: int) -> List[int]:
    return [random.randint(0, 2147483647) for _ in range(n)]

def seq_to_args(seq: List[int]) -> List[str]:
    return [str(x) for x in seq]

def try_exec(ns: List[int]) -> bool:
    try:
        subprocess.check_output(["./PmergeMe"] + seq_to_args(ns), stderr=subprocess.DEVNULL)
        return True
    except subprocess.CalledProcessError:
        return False

def exec_var(ns: List[int]) -> str:
    return subprocess.check_output(["./PmergeMe"] + seq_to_args(ns), stderr=subprocess.PIPE).decode("utf-8")

if __name__ == "__main__":
    subprocess.run(["make"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    print("Testing ex02..")
    print("-- VALID SEQUENCES --")
    for _ in range(2, 10000, 10):
        print("✅" if try_exec(random_seq(2)) else "❌", end=" ", flush=True)
    print("\n-- INVALID SEQUENCES --")
    print("Negative numbers: " + ("✅" if not try_exec([-1]) else "❌"))
    print("Non-integer numbers: " + ("✅" if not try_exec([1.5]) else "❌"))
    print("Non-numeric strings: " + ("✅" if not try_exec(["a"]) else "❌"))
    print("Empty list:" + ("✅" if not try_exec([]) else "❌"))

    print("-- CHRONOS --")
    for n in [5, 50, 500, 5000, 10000, 20000]:
        print("{} numbers : ".format(n))
        for line in exec_var(random_seq(n)).split("\n"):
            if "Time to process" in line:
                print(line)
        print("-"*30)