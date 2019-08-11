def LukyS(line):
    if len(line) <= 2: return len(line)
    
    idx_ref = [0]
    for idx in range(len(line)-1):
        if line[idx] != "N":
            idx_ref.append(idx)
    if line[-1] == "N":
        idx_ref.append(len(line))
    if len(idx_ref) <= 4: return len(line)

    maxL = []
    for idx in range(len(idx_ref) - 1):
        maxL.append(idx_ref[idx+1]-idx_ref[idx])

    ret = 0
    for i in range(len(maxL)-3):
        ret = max(ret, (maxL[i]+maxL[i+1]+maxL[i+2]))
    ret += 1

    return ret


def main():
    nums = int(input("num\n"))
    N = nums
    lines = []
    while nums:
        print("input string", N - nums + 1)
        lines.append(input())
        nums -= 1
    print(lines)
    for line in lines:
        print(LukyS(str(line)))
        

if __name__ == '__main__':
    main()
