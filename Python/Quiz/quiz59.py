numbers = [1,2,3,2,4,5,3,3,6]

def find_duplicates(nlist):
    flist = []
    for i in range(min(nlist), max(nlist)):
        if nlist.count(i) > 1:
            flist.append(i)
    return flist

def find_duplicates_fix(nlist):
    flist = []
    for i in nlist:
        if nlist.count(i) > 1 and i not in flist:
            flist.append(i)
    return flist

print(find_duplicates(numbers))
print(find_duplicates_fix(numbers))
