x = int(input("write x of 10^x numbers u wnt to solve with 3n+1: "))
def collatz_sequence(x):
    num_seq = [x]
    if x < 1:
        return []
    while x > 1:
        if x % 2 == 0:
            x = x / 2
        else:
            x = 3 * x + 1
        # Added line
        num_seq.append(x)
    return num_seq

f = open("collatz_sequence.txt", 'w')

for i in range(1, 10 ** x):
    f.write(str(collatz_sequence(i)) + '\n')

f.close()
