def cntitems2(items: str, startIndices: list[int], endIndices: list[int]) -> list[int]:
    print(str)
    ln = len(items)
    # pre-calc left-most pipe location and sum of stars arrays
    stars = [0] * (ln+1)
    lftpipeidx = [-1] * (ln+1)
    for i, ch in enumerate(items,1):
        if ch == "|":
            stars[i] = stars[i-1]
            lftpipeidx[i] = i
        else:  # ch == *
            stars[i] = stars[i-1] + 1
            lftpipeidx[i] = lftpipeidx[i-1]
    print(stars)
    print(lftpipeidx)
    if lftpipeidx[-1] == -1:
        return [0]*len(startIndices)

    # pre-calc right-most pipe location
    rgtpipeidx = [ln+1] * (ln+1)
    for i in range(ln-1,-1,-1):
        if items[i] == '|':
            rgtpipeidx[i+1] = i+1
        else:
            rgtpipeidx[i+1] = rgtpipeidx[i+2] if i < ln-1 else ln+1
    print(rgtpipeidx)
    # calc answer as difference between num. of stars b/w right and left pipes.
    # right pipe is the left-most pipe from the end index, left pipe is the right-most one from the start index
    ans = []
    for i in range(len(startIndices)):
        si, ei = startIndices[i], endIndices[i]
        lftpipe = rgtpipeidx[si]
        rgtpipe = lftpipeidx[ei]
        ans.append(stars[rgtpipe] - stars[lftpipe] if lftpipe < rgtpipe else 0)
    return ans


if __name__ == '__main__':
    #  1-based index, assume start idx <= end idx, and both indices within the range 1..ln
    print(cntitems2("|**|*|*",[1,1,2],[5,7,7]))  # [2, 3, 1]
    print(cntitems2("*|**|*|**|****|*",[4,1,4],[8,16,11]))  # [1, 9, 3]
    print(cntitems2("*****|*****",[1,4,1,7],[5,8,11,9]))  # [0, 0, 0, 0]
