import heapq 

str1 = input()
#str1 = "abacabad"

class Char(object):
    def __init__(self, c):
        self.c = c
        self.f = 1

    def __lt__(self, other):
        return self.f < other.f

cList = []

for c in str1:
    for i in range(len(cList)):
        if (cList[i].c == c):
            cList[i].f += 1
            break
    else:
        cList.append(Char(c))

# c = list(map(lambda l: l.c, cList))
# f = list(map(lambda l: l.f, cList))
# print(c)
# print(f)

lenCharList = len(cList)
heapq.heapify(cList) 

# print([heapq.heappop(cList).f for i in range(len(cList))])

class Hoffman(object):
    def __init__(self,l, r):
        self.l = l
        self.r = r
        self.f = l.f + r.f

    def __lt__(self, other):
        return self.f < other.f

while (len(cList) > 1):
    r = heapq.heappop(cList)
    l = heapq.heappop(cList)
    h = Hoffman(l,r)
    heapq.heappush(cList, h)

hList = []
def codeH(h, code):
    if (type(h) == Hoffman):
        codeH(h.l, (code + '1'))
        codeH(h.r, (code + '0'))
    else:
        hList.append([h.c, code])

if (lenCharList == 1):
    hList.append([cList[0].c, "0"])
else:
    codeH(h, '')

strH = ''
for i in str1:
    for j in hList:
        if(i == j[0]):
            strH += j[1]
            break


# вывод на экран
print(lenCharList, len(strH))

for i in hList:
    ch, code = i
    print(ch + ': ' + code)

print(strH)